#ifndef WEBWIDGET_BUILDING_HOUSEBUILDING_H
#define WEBWIDGET_BUILDING_HOUSEBUILDING_H

#include <City/assets/house.h>

#include <Wt/WContainerWidget.h>


namespace WebWidget {
namespace Building {

class HouseBuilding : public Assets::House, public Wt::WContainerWidget
{
public:
    HouseBuilding();
};

} // namespace Building
} // namespace WebWidget

#endif // WEBWIDGET_BUILDING_HOUSEBUILDING_H
