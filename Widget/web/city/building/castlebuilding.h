#ifndef WEBWIDGET_BUILDING_CASTLEBUILDING_H
#define WEBWIDGET_BUILDING_CASTLEBUILDING_H

#include <City/assets/castlebuilding.h>
#include "utility/utility.h"

#include <Wt/WContainerWidget.h>

namespace WebWidget {
namespace Building {

class CastleBuilding : public Assets::CastleBuilding , public Wt::WContainerWidget, public Utility::Utility
{
public:
    CastleBuilding(const bool buildMenu = false);
};

} // namespace Building
} // namespace WebWidget

#endif // WEBWIDGET_BUILDING_CASTLEBUILDING_H
