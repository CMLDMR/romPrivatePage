#ifndef WEBWIDGET_MAINBUILDING_H
#define WEBWIDGET_MAINBUILDING_H


#include "Widget/city/building/basewidget.h"

namespace WebWidget {
namespace Building {

class MainBuilding : public BaseWidget
{
public:
    MainBuilding(const bool buildMenu = false);

    Wt::Signal<::Building::Type,bool> &SelectedBuild();

private:

    Wt::Signal<::Building::Type,bool> _selectedBuild;
};

}
} // namespace WebWidget

#endif // WEBWIDGET_MAINBUILDING_H
