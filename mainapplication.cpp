#include "mainapplication.h"
#include <Wt/WPushButton.h>

#include "World/citymap.h"

MainApplication::MainApplication(const WEnvironment &env)
    :Wt::WApplication(env)
{

    WApplication::useStyleSheet(WLink("css/main.css"));
    Wt::WApplication::require("script/script.js");


    mCityMap = root()->addNew<City::CityMap>();

}
