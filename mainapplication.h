#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>

using namespace Wt;

class World;
namespace City{
class CityMap;
}
class ControlPanelWidget;

class MainApplication : public WApplication
{
public:
    MainApplication(const WEnvironment &env);


private:
    World* mWorld;
    City::CityMap* mCityMap;
    ControlPanelWidget* mControlPanel;
};

#endif // MAINAPPLICATION_H
