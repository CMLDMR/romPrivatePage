#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>

using namespace Wt;

class World;
namespace City{
class CityMap;
class ControlPanel;
}

class MainApplication : public WApplication
{
public:
    MainApplication(const WEnvironment &env);

private:
    void initializeApp();
    void initializeScriptAndCSS();
    void initializeComponent();

private:
    World* mWorld;
    City::CityMap* mCityMap;

    City::ControlPanel *m_controlPanel;
};

#endif // MAINAPPLICATION_H
