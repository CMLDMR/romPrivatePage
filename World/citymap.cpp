#include "citymap.h"
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WText.h>
#include <Wt/WString.h>
#include <vector>
#include <random>
#include <utility/style.h>


#include "City/controlpanel.h"
#include "City/citymanager.h"
#include "City/assetsmanager.h"
#include "City/taskmanager.h"
#include "Widget/web/city/building/castlebuilding.h"
#include "Widget/web/city/building/mainbuilding.h"

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
//    this->setId("citymap");

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


    mMap = cityContainer->addNew<WContainerWidget>();
    mMap->setWidth(3000);
    mMap->setHeight(2000);
    mMap->setPositionScheme(PositionScheme::Relative);
    mMap->setMaximumSize(3000,2000);
    mMap->addStyleClass("cityMap");

    mMap->setAttributeValue(Style::style,Style::background::url("cityground.jpg")
                            +Style::background::size::cover
                            +Style::background::repeat::norepeat
                            +Style::background::position::center_center);

    auto coorText = addNew<WText>();
    coorText->setPositionScheme(PositionScheme::Absolute);
    coorText->setOffsets(0,Side::Left|Side::Bottom);
    coorText->setAttributeValue(Style::style,Style::background::color::color(Style::color::Green::DarkCyan)+Style::color::color(Style::color::White::AliceBlue));

    this->doJavaScript("handDrag();");


    mMap->mouseMoved().connect([=]( const Wt::WMouseEvent &event ){
        coorText->setText(WString("{1} {2}").arg(event.widget().x).arg(event.widget().y));
        mDragged = true;
    });



//    return;
    mMap->mouseWentDown().connect([=]( const Wt::WMouseEvent &event){
        std::cout << event.widget().x << " " << event.widget().y << "\n";
//        this->addBuild(event.widget().x,event.widget().y,WebWidget::Building::CastleBuilding());
        mDragged = false;
    });

    mMap->mouseWentUp().connect([=]( const Wt::WMouseEvent &event){
        std::cout << event.widget().x << " " << event.widget().y << "\n";

        if( !mDragged ){
            this->addBuild(event.widget().x,event.widget().y,WebWidget::Building::CastleBuilding());
        }
    });




}

void City::CityMap::addBuild(const int x, const int y, const std::string &assetPath, const int width, const int height)
{
    auto building = mMap->addNew<WContainerWidget>();
    building->setPositionScheme(PositionScheme::Absolute);
    building->setOffsets(y,Side::Top);
    building->setOffsets(x,Side::Left);
    building->setAttributeValue("style","background:url("+assetPath+");;background-repeat:no-repeat;");
    building->setWidth(width);
    building->setHeight(height);
    building->addStyleClass("buildItem");

    building->clicked().connect([=](){
       std::cout << assetPath << "\n";
    });
}

void City::CityMap::addBuild(const int &x, const int &y, const Building::Building &_building)
{
    auto building = mMap->addNew<WebWidget::Building::MainBuilding>();
    building->setPositionScheme(PositionScheme::Absolute);
    building->setOffsets(y-building->assetHeight()/2,Side::Top);
    building->setOffsets(x-building->assetWidth()/2,Side::Left);
//    building->addStyleClass("buildItem");

    building->clicked().connect([=](){
       std::cout << building->itemName() << "\n";
    });
}
