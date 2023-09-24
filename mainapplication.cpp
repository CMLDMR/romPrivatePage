#include "mainapplication.h"
#include <Wt/WPushButton.h>

#include "World/citymap.h"
#include <City/controlpanel.h>

#include <GlobalVariable.h>

#include <CSSRule/GlobalRule.h>

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


#ifdef DevelopmentMode
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
    mCityMap = root()->addNew<City::CityMap>();

    m_controlPanel = root()->addNew<City::ControlPanel>();
}
