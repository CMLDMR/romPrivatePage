#include "citymap.h"
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WText.h>
#include <Wt/WString.h>
#include <Wt/WPoint.h>
#include <Wt/WPolygonArea.h>

#include <vector>
#include <random>
#include <utility/style.h>


#include "City/controlpanel.h"
#include "City/citymanager.h"
#include "City/assetsmanager.h"
#include "City/taskmanager.h"
#include "Widget/web/city/building/castlebuilding.h"
#include "Widget/web/city/building/housebuilding.h"
#include "Widget/web/city/building/mainbuilding.h"
#include "Widget/web/city/building/farmer.h"



using namespace Wt;

City::CityMap::CityMap()
{

    this->setPositionScheme(PositionScheme::Fixed);
    this->setWidth(WLength("100%"));
    this->setHeight(WLength("100%"));
    this->setOffsets(0,Side::Left|Side::Top);
    this->setContentAlignment(AlignmentFlag::Center);
    this->setScrollVisibilityEnabled(false);
    this->setOverflow(Overflow::Hidden);

    mControlPanel = this->addNew<ControlPanel>();
    mCityManager = this->addNew<CityManager>();
    mAssetsManager = this->addNew<AssetsManager>();
    mTaskManager = this->addNew<TaskManager>();


    auto cityContainer = this->addNew<WContainerWidget>();
    cityContainer->setPositionScheme(PositionScheme::Absolute);
    cityContainer->setWidth(WLength("100%"));
    cityContainer->setHeight(WLength("100%"));
    cityContainer->setOffsets(0,Side::Left|Side::Top);
    cityContainer->setScrollVisibilityEnabled(false);
    cityContainer->setOverflow(Overflow::Hidden);
    cityContainer->setId("citymap");


    mCityImage = cityContainer->addNew<WImage>(WLink("cityground1.jpg"));
    mCityImage->setWidth(2000);
    mCityImage->setHeight(2000);
    mCityImage->setPositionScheme(PositionScheme::Absolute);
    mCityImage->setOffsets(0,Side::Left|Side::Top);



    mMap = cityContainer->addNew<WContainerWidget>();
    mMap->setWidth(2000);
    mMap->setHeight(2000);
    mMap->setOffsets(0,Side::Left|Side::Top);
    mMap->setPositionScheme(PositionScheme::Absolute);
    mMap->setMaximumSize(2000,2000);


    auto coorText = addNew<WText>();
    coorText->setPositionScheme(PositionScheme::Absolute);
    coorText->setOffsets(0,Side::Left|Side::Bottom);
    coorText->setAttributeValue(Style::style,Style::background::color::color(Style::color::Green::DarkCyan)+Style::color::color(Style::color::White::AliceBlue));
    coorText->setZIndex(2201);
    this->doJavaScript("handDrag();");


    mNewBuildingPlaceAreaWidget = nullptr;

    //TODO: bas??l??yken Drag Yapt??ktan sonra B??rak??yor
    mMap->mouseMoved().connect([=]( const Wt::WMouseEvent &event ){
        const auto &[selected,selectedType] = mAssetsManager->selected();

        if( selected ){
            //TODO: function return a typename?

                switch (selectedType) {

                case Building::Type::main:
                    this->addToCursor<WebWidget::Building::MainBuilding>(event.widget().x,event.widget().y);
                    break;

                case Building::Type::castle:
                    this->addToCursor<WebWidget::Building::CastleBuilding>(event.widget().x,event.widget().y);
                    break;
                case Building::Type::house:
                    this->addToCursor<WebWidget::Building::HouseBuilding>(event.widget().x,event.widget().y);
                    break;

                case Building::Type::farmer:
                    this->addToCursor<WebWidget::Building::Farmer>(event.widget().x,event.widget().y);
                    break;
                default:
                    break;
                }
        }

        coorText->setText(WString("{1} {2}").arg(event.widget().x).arg(event.widget().y));
        mDragged = true;
    });



    //    return;
    mMap->mouseWentDown().connect([=]( const Wt::WMouseEvent &event){
        mDragged = false;
    });

    mMap->mouseWentUp().connect([=]( const Wt::WMouseEvent &event){

        if( event.button() == Wt::WMouseEvent::Button::Left ){

            if( mBuildingPlaceAble ){
                auto [selected,selectedType] = mAssetsManager->selected();

                if( selected ){
                    switch (selectedType) {

                    case Building::Type::main:
                        this->addBuild<WebWidget::Building::MainBuilding>(event.widget().x,event.widget().y);
                        break;

                    case Building::Type::castle:
                        this->addBuild<WebWidget::Building::CastleBuilding>(event.widget().x,event.widget().y);

                        break;
                    case Building::Type::house:
                        this->addBuild<WebWidget::Building::HouseBuilding>(event.widget().x,event.widget().y);

                        break;

                    case Building::Type::farmer:
                        this->addBuild<WebWidget::Building::Farmer>(event.widget().x,event.widget().y);

                        break;
                    default:
                        break;
                    }
                }

                mAssetsManager->unSelectAll();

                if( mNewBuildingPlaceAreaWidget ){
                    mMap->removeWidget(mNewBuildingPlaceAreaWidget);
                    mNewBuildingPlaceAreaWidget = nullptr;
                }
            }


        }



    });


}

bool City::CityMap::PointInPolygon(Building::Point point, const std::vector<Building::Point> &points)
{
    int i, j, nvert = points.size();
    bool c = false;

    for(i = 0, j = nvert - 1; i < nvert; j = i++) {
      if( ( (points[i].y >= point.y ) != (points[j].y >= point.y) ) &&
          (point.x <= (points[j].x - points[i].x) * (point.y - points[i].y) / (points[j].y - points[i].y) + points[i].x)
        )
        c = !c;
    }
    return c;
}



template<typename T>
void City::CityMap::addBuild(const int &x, const int &y)
{
    auto building = mMap->addNew<T>();
    building->setPositionScheme(PositionScheme::Absolute);
    building->setPosition(x,y);

    mBuildList.push_back(building);

    building->clicked().connect([=](){
        std::cout << building->buildingName() << "\n";
    });
}

template<typename T>
void City::CityMap::addToCursor(const int &x, const int &y)
{
    bool mCollisioned = false;
    auto _mNewObject = std::make_unique<T>();


    auto nPoints = _mNewObject->getPolyShapeToGlobal(x,y);


    for( auto &point : nPoints ){
        for( const auto pObj : mBuildList ){
            auto _pLis = pObj->getPolyShapeToGlobal(pObj->xPos(),pObj->yPos());
            if( PointInPolygon(point,_pLis ) && !mCollisioned ){
                mCollisioned = true;
                break;
            }
        }
        if( mCollisioned ) break;


    }


    if( !mNewBuildingPlaceAreaWidget ){
        mNewBuildingPlaceAreaWidget = mMap->addWidget(WebWidget::Building::BaseWidget::isRightPlaceToBuild<T>(mCollisioned));
    }

    mBuildingPlaceAble = !mCollisioned;
    mNewBuildingPlaceAreaWidget->placeAbleShape()->setWrong(mCollisioned);

    mNewBuildingPlaceAreaWidget->setPosition(x,y);


}
