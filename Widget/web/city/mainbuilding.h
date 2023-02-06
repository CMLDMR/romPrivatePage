#ifndef WEBWIDGET_MAINBUILDING_H
#define WEBWIDGET_MAINBUILDING_H

#include <City/assets/mainbuilding.h>
#include "utility/utility.h"

#include <Wt/WContainerWidget.h>

namespace WebWidget {

class MainBuilding : public Assets::MainBuilding , public Wt::WContainerWidget, public Utility::Utility
{
public:
    MainBuilding();
};

} // namespace WebWidget

#endif // WEBWIDGET_MAINBUILDING_H
