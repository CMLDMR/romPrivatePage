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

class CityManager;
class AssetsManager;
class TaskManager;

class CityMap : public Wt::WContainerWidget
{
public:
    CityMap();


    template<typename T>
    void addBuild(const int &x , const int &y )
    {
        auto building = mMap->addNew<T>();
        building->setPositionScheme(Wt::PositionScheme::Absolute);
        building->setPosition(x,y);

        mBuildList.push_back(building);

        building->clicked().connect([=](){
            std::cout << building->buildingName() << "\n";
        });
    }


    Wt::WContainerWidget* mMap;

    CityManager* mCityManager;

    AssetsManager* mAssetsManager;
    TaskManager *mTaskManager;

    bool m_dragged = false;

    Wt::WImage* mCityImage;


    WebWidget::Building::BaseWidget* mNewBuildingPlaceAreaWidget;
    // template<typename T>
    // inline void addToCursor(const int &x, const int &y)
    // {
    //     bool mCollisioned = false;

    //     auto _mNewObject = std::make_unique<T>();

    //     auto nPoints = _mNewObject->getPolyShapeToGlobal(x,y);

    //     for( auto &point : nPoints ){
    //         for( const auto pObj : mBuildList ){
    //             auto _pLis = pObj->getPolyShapeToGlobal(pObj->xPos(),pObj->yPos());
    //             if( PointInPolygon(point,_pLis ) && !mCollisioned ){
    //                 mCollisioned = true;
    //                 break;
    //             }
    //         }
    //         if( mCollisioned ) break;
    //     }

    //     if( !mNewBuildingPlaceAreaWidget ){
    //         mNewBuildingPlaceAreaWidget = mMap->addWidget(WebWidget::Building::BaseWidget::isRightPlaceToBuild<T>(mCollisioned));
    //     }

    //     mBuildingPlaceAble = !mCollisioned;
    //     mNewBuildingPlaceAreaWidget->placeAbleShape()->setWrong(mCollisioned);

    //     mNewBuildingPlaceAreaWidget->setPosition(x,y);


    // }


    std::list<WebWidget::Building::BaseWidget*> mBuildList;



    bool mBuildingPlaceAble{true};
private:
    bool PointInPolygon( ::Building::Point point, const std::vector<::Building::Point> &points);

    void mouseMove( const Wt::WMouseEvent &event );
    void mouseDown( const Wt::WMouseEvent &event );
    void mouseUp( const Wt::WMouseEvent &event );

#ifdef DEVELOPMENTMODE
    Wt::WText* m_coordinateText { nullptr };
#endif
};

}




#endif // CITYMAP_H
