#ifndef CITY_ASSETSMANAGER_H
#define CITY_ASSETSMANAGER_H

#include <Wt/WContainerWidget.h>
#include <Wt/WSignal.h>
#include "building/building.h"
#include "Widget/web/city/building/basewidget.h"

#include <tuple>
#include <list>
#include <type_traits>

namespace WebWidget {
namespace Building {
class MainBuilding;
class CastleBuilding;
class HouseBuilding;
class Farmer;

}
}

namespace Wt{
class WGridLayout;
}


namespace City {


class AssetsManager : public Wt::WContainerWidget
{
public:
    AssetsManager();


    template<typename T>
    void addBuildMenu(const int &x, const int &y);


    Wt::WGridLayout* mGLayout;


//    template<typename T>
//    using selectedType =
//    typename std::conditional< std::is_same<T,WebWidget::Building::MainBuilding>::value , WebWidget::Building::MainBuilding,
//    typename std::conditional< std::is_same<T,WebWidget::Building::HouseBuilding>::value , WebWidget::Building::HouseBuilding,
//    typename std::conditional< std::is_same<T,WebWidget::Building::CastleBuilding>::value , WebWidget::Building::CastleBuilding,
//    WebWidget::Building::Farmer >::type >::type >::type;



    std::tuple<bool,Building::Type> selected() const;

    void unSelectAll();






private:

    bool mSelected;
    Building::Type mSelectedType;

    std::list<WebWidget::Building::BaseWidget*> mBuildList;


};

} // namespace City

#endif // CITY_ASSETSMANAGER_H
