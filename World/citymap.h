#ifndef CITYMAP_H
#define CITYMAP_H

#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>

#include <building/building.h>




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

};

}




#endif // CITYMAP_H
