#ifndef WEBWIDGET_MAINBUILDING_H
#define WEBWIDGET_MAINBUILDING_H

#include <City/assets/mainbuilding.h>
#include "utility/utility.h"

#include <Wt/WContainerWidget.h>


namespace WebWidget {
namespace Building {
class MainBuilding : public Assets::MainBuilding , public Wt::WContainerWidget, public Utility::Utility
{
public:
    MainBuilding(const bool buildMenu = false);




};

}
} // namespace WebWidget

#endif // WEBWIDGET_MAINBUILDING_H
