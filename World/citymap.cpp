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

    this->doJavaScript("handDrag();");


//    mMap->mouseMoved().connect([=]( const Wt::WMouseEvent &event ){
//        coorText->setText(WString("{1} {2}").arg(event.widget().x).arg(event.widget().y));
//    });



//    return;
    mMap->mouseWentDown().connect([=]( const Wt::WMouseEvent &event){
        std::cout << event.widget().x << " " << event.widget().y << "\n";
    });


    this->addBuild(200,480,"b001.png",72,57);
    this->addBuild(640,480,"b002.png",123,121);
    this->addBuild(1280,250,"b003.png",62,49);
    this->addBuild(100,780,"b004.png",58,74);


    struct BuildItem{
        std::string path;
        int width;
        int height;
    };


    std::vector<BuildItem> list;

    BuildItem item1{"b001.png",72,57};
    BuildItem item2{"b002.png",123,121};
    BuildItem item3{"b003.png",62,49};
    BuildItem item4{"b004.png",58,74};
    BuildItem item5{"b005.png",49,58};
    BuildItem item6{"b006.png",67,48};
    BuildItem item7{"b007.png",137,109};
    BuildItem item8{"b008.png",67,60};
    BuildItem item9{"b009.png",67,73};
    BuildItem item10{"b010.png",63,53};
    BuildItem item11{"b011.png",74,56};
    BuildItem item12{"b012.png",49,45};
    BuildItem item13{"b013.png",71,62};

    list.emplace_back(item1);
    list.emplace_back(item2);
    list.emplace_back(item3);
    list.emplace_back(item4);
    list.emplace_back(item5);
    list.emplace_back(item6);
    list.emplace_back(item7);
    list.emplace_back(item8);
    list.emplace_back(item9);
    list.emplace_back(item10);
    list.emplace_back(item11);
    list.emplace_back(item12);
    list.emplace_back(item13);


    for( int i = 0 ; i < 500 ; i++ ){

        std::random_device r;

        std::default_random_engine e1(r());
        std::uniform_int_distribution<int> uniform_dist(150, 1000);
        int x = uniform_dist(e1);
        int y = uniform_dist(e1);

        this->addBuild((x*i)%2800+100,(y*i)%1800+100,list[i%list.size()].path,list[i%list.size()].width,list[i%list.size()].height);
    }


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
