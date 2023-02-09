#ifndef WEBWIDGET_BUILDING_FARMER_H
#define WEBWIDGET_BUILDING_FARMER_H


#include "Widget/web/city/building/basewidget.h"


namespace WebWidget {
namespace Building {

class Farmer : public BaseWidget
{
public:
    Farmer(const bool buildMenu = false);


    Wt::Signal<::Building::Type,bool> &SelectedBuild();

private:

    Wt::Signal<::Building::Type,bool> _selectedBuild;
};

} // namespace Building
} // namespace WebWidget

#endif // WEBWIDGET_BUILDING_FARMER_H
