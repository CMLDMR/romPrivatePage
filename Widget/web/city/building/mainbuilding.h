#ifndef WEBWIDGET_MAINBUILDING_H
#define WEBWIDGET_MAINBUILDING_H

#include <City/assets/mainbuilding.h>
#include "utility/utility.h"

#include <Wt/WContainerWidget.h>
#include "Widget/web/city/building/basewidget.h"

#include <list>


namespace WebWidget {
namespace Building {

class MainBuilding : public Assets::MainBuilding , public BaseWidget, public Utility::Utility
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
