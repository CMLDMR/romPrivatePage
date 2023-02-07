#ifndef WEBWIDGET_BUILDING_CASTLEBUILDING_H
#define WEBWIDGET_BUILDING_CASTLEBUILDING_H

#include <City/assets/castlebuilding.h>
#include "utility/utility.h"

#include "Widget/web/city/building/basewidget.h"

namespace WebWidget {
namespace Building {

class CastleBuilding : public Assets::CastleBuilding , public BaseWidget, public Utility::Utility
{
public:
    CastleBuilding(const bool buildMenu = false);

    Wt::Signal<::Building::Type,bool> &SelectedBuild();

private:

    Wt::Signal<::Building::Type,bool> _selectedBuild;
};

} // namespace Building
} // namespace WebWidget

#endif // WEBWIDGET_BUILDING_CASTLEBUILDING_H
