#ifndef CITY_ASSETSMANAGER_H
#define CITY_ASSETSMANAGER_H

#include <Wt/WContainerWidget.h>
#include <Wt/WSignal.h>
#include "building/building.h"
#include "Widget/web/city/building/basewidget.h"

#include <tuple>
#include <list>

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


    std::tuple<bool,Building::Type> selected() const;

private:

    bool mSelected;
    Building::Type mSelectedType;

    std::list<WebWidget::Building::BaseWidget*> mBuildList;


};

} // namespace City

#endif // CITY_ASSETSMANAGER_H
