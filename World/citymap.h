#ifndef CITYMAP_H
#define CITYMAP_H

#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>

#include <building/building.h>



#include <ostream>

namespace WebWidget {
namespace Building{
class BaseWidget;
}
}


namespace City{

class ControlPanel;
class CityManager;
class AssetsManager;
class TaskManager;

class CityMap : public Wt::WContainerWidget
{
public:
    CityMap();


    template<typename T>
    void addBuild(const int &x , const int &y );

    Wt::WContainerWidget* mMap;

    ControlPanel* mControlPanel;
    CityManager* mCityManager;

    AssetsManager* mAssetsManager;
    TaskManager *mTaskManager;

    bool mDragged = false;

    Wt::WImage* mCityImage;


    WebWidget::Building::BaseWidget* mNewBuildingPlaceAreaWidget;
    template<typename T>
    void addToCursor(const int &x, const int &y);

    std::list<WebWidget::Building::BaseWidget*> mBuildList;



    bool mBuildingPlaceAble{true};
private:



    bool PointInPolygon( ::Building::Point point, const std::vector<::Building::Point> &points);
};

}




#endif // CITYMAP_H
