#include "mainapplication.h"
#include <Wt/WPushButton.h>

#include "World/world.h"
#include "World/citymap.h"
#include "Widget/controlpanelwidget.h"

MainApplication::MainApplication(const WEnvironment &env)
    :Wt::WApplication(env)
{

    WApplication::useStyleSheet(WLink("css/main.css"));
    Wt::WApplication::require("script/script.js");

//    mWorld = root()->addNew<World>();
    mCityMap = root()->addNew<CityMap>();

    mControlPanel = root()->addNew<ControlPanelWidget>();
}
