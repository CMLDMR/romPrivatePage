#include "CityMap.h"
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WText.h>
#include <Wt/WString.h>
#include <Wt/WPoint.h>
#include <Wt/WPolygonArea.h>

#include <vector>
#include <random>
#include <utility/style.h>


#include "City/citymanager.h"
#include "City/assetsmanager.h"
#include "City/taskmanager.h"
#include "Widget/city/building/mainbuilding.h"

#include "GlobalVariable.h"

#include "City/CityGround.h"



using namespace Wt;


City::CityMap::CityMap()
{

#ifdef DEVELOPMENTMODE
    m_coordinateText = addNew<WText>();
    m_coordinateText->setPositionScheme(PositionScheme::Absolute);
    m_coordinateText->setOffsets(0,Side::Right);
    m_coordinateText->setOffsets(20,Side::Top);
    m_coordinateText->setAttributeValue(Style::style,Style::background::color::color(Style::color::Green::DarkCyan)+Style::color::color(Style::color::White::AliceBlue));
    m_coordinateText->setZIndex(2201);
#endif


    this->setPositionScheme(PositionScheme::Fixed);
    this->setWidth(WLength("100%"));
    this->setHeight(WLength("100%"));
    this->setOffsets(0,Side::Left|Side::Top);
    this->setContentAlignment(AlignmentFlag::Center);
    this->setScrollVisibilityEnabled(false);
    this->setOverflow(Overflow::Hidden);


    // mCityManager = this->addNew<CityManager>();
    mAssetsManager = this->addNew<AssetsManager>();
    // mTaskManager = this->addNew<TaskManager>();

    auto cityContainer = this->addNew<WContainerWidget>();
    cityContainer->setPositionScheme(PositionScheme::Absolute);
    cityContainer->setWidth(WLength("100%"));
    cityContainer->setHeight(WLength("100%"));
    cityContainer->setOffsets(0,Side::Left|Side::Top);
    cityContainer->setScrollVisibilityEnabled(false);
    cityContainer->setOverflow(Overflow::Hidden);
    cityContainer->setId("citymap");
    cityContainer->doJavaScript("handDrag();");


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

    mNewBuildingPlaceAreaWidget = nullptr;

    //BUG: basılıyken Drag Yaptıktan sonra Bırakıyor
    mMap->mouseMoved().connect( this , &CityMap::mouseMove );
    mMap->mouseWentDown().connect( this , &CityMap::mouseDown );
    mMap->mouseWentUp().connect (  this , &CityMap::mouseUp );






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

void City::CityMap::mouseMove(const Wt::WMouseEvent &event )
{

    const auto &[selected,selectedType] = mAssetsManager->selected();

    if( selected ){
        //TODO: function return a typename?

        switch (selectedType) {

        case Building::Type::main:
            // this->addToCursor<WebWidget::Building::MainBuilding>(event.widget().x,event.widget().y);
            break;

        // case Building::Type::castle:
        //     this->addToCursor<WebWidget::Building::CastleBuilding>(event.widget().x,event.widget().y);
        //     break;
        // case Building::Type::house:
        //     this->addToCursor<WebWidget::Building::HouseBuilding>(event.widget().x,event.widget().y);
        //     break;

        // case Building::Type::farmer:
        //     this->addToCursor<WebWidget::Building::Farmer>(event.widget().x,event.widget().y);
        //     break;
        default:
            break;
        }
    }

#ifdef DEVELOPMENTMODE
    m_coordinateText->setText(WString("{1} {2}").arg(event.widget().x).arg(event.widget().y));
#endif

    m_dragged = true;

}

void City::CityMap::mouseDown(const Wt::WMouseEvent &event)
{
    m_dragged = false;

}

void City::CityMap::mouseUp(const Wt::WMouseEvent &event)
{
    if( event.button() == Wt::WMouseEvent::Button::Left ){

        if( mBuildingPlaceAble ){
            auto [selected,selectedType] = mAssetsManager->selected();

            if( selected ){
                switch (selectedType) {

                case Building::Type::main:
                    this->addBuild<WebWidget::Building::MainBuilding>(event.widget().x,event.widget().y);
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
}

