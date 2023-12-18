#include "mainapplication.h"
#include <Wt/WPushButton.h>

#include "World/citymap.h"
#include <City/controlpanel.h>

#include <GlobalVariable.h>

#include <World/WorldMap.h>

MainApplication::MainApplication(const WEnvironment &env)
    :Wt::WApplication(env)
{

    initializeApp();

}

void MainApplication::initializeApp()
{
    initializeScriptAndCSS();

    initializeComponent();
}

void MainApplication::initializeScriptAndCSS()
{
    WApplication::useStyleSheet(WLink("css/main.css"));
    Wt::WApplication::require("script/script.js");


#ifdef DEVELOPMENTMODE
    auto developmentModeEnabledInfoText = root()->addNew<WText>("Development Mode");
    developmentModeEnabledInfoText->setPositionScheme(PositionScheme::Fixed);
    developmentModeEnabledInfoText->setOffsets(0,Side::Top|Side::Right);
    developmentModeEnabledInfoText->setZIndex(10);
    developmentModeEnabledInfoText->decorationStyle().setForegroundColor(WColor(StandardColor::White));
    developmentModeEnabledInfoText->decorationStyle().setBackgroundColor(WColor(Wt::StandardColor::DarkRed));
#endif
}

void MainApplication::initializeComponent()
{
    m_map = root()->addNew<WContainerWidget>();
    m_map->setPositionScheme(PositionScheme::Fixed);
    m_map->setOffsets(0,Side::Top|Side::Left);

    m_controlPanel = root()->addNew<City::ControlPanel>();

    m_controlPanel->selectedMap().connect( [=](Map map){

        if( map == Map::City ){
            m_map->clear();
            m_map->addNew<City::CityMap>();
        }
        else if( map == Map::World ) {
            m_map->clear();
            m_map->addNew<WorldMap>();
        }

    });


    m_map->addNew<City::CityMap>();


}
