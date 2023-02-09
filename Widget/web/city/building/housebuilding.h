#ifndef WEBWIDGET_BUILDING_HOUSEBUILDING_H
#define WEBWIDGET_BUILDING_HOUSEBUILDING_H


#include "Widget/web/city/building/basewidget.h"


namespace WebWidget {
namespace Building {

class HouseBuilding : public BaseWidget
{
public:
    HouseBuilding(const bool buildMenu = false);

    Wt::Signal<::Building::Type,bool> &SelectedBuild();

private:

    Wt::Signal<::Building::Type,bool> _selectedBuild;
};

} // namespace Building
} // namespace WebWidget

#endif // WEBWIDGET_BUILDING_HOUSEBUILDING_H
