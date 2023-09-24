#ifndef CITY_CONTROLPANEL_H
#define CITY_CONTROLPANEL_H

#include <Wt/WContainerWidget.h>
#include <GlobalVariable.h>


namespace Wt {
class WText;
}

namespace City {

class ControlPanel : public Wt::WContainerWidget
{
public:
    ControlPanel();


    Wt::Signal<Map> &selectedMap();

private: //Functions Declaration
    void initializePanel();


private: //Variable Declaration

    Wt::Signal<Map> m_selectMap;
    Map m_currentMap{Map::City};
    Wt::WText* m_mapTitleText;

};

} // namespace City

#endif // CITY_CONTROLPANEL_H
