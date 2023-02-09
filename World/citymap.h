#ifndef CITYMAP_H
#define CITYMAP_H

#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>

#include <building/building.h>


#include <ostream>

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


    Wt::WContainerWidget* mNewBuildingPlaceAreaWidget;
    template<typename T>
    void addToCursor(const int &x, const int &y);

    std::list<Building::Building*> mBuildList;



private:

    struct Point {
       int x, y;
       friend std::ostream& operator<<( std::ostream &out , const Point &p ){
           out << " ["<<p.x << " " << p.y << "] ";
           return out;
       }

    };



    struct line {
       Point p1, p2;
    };

    bool onLine(line l1, Point p) {        //check whether p is on the line or not
       if(p.x <= std::max(l1.p1.x, l1.p2.x) && p.x <= std::min(l1.p1.x, l1.p2.x) &&
          (p.y <= std::max(l1.p1.y, l1.p2.y) && p.y <= std::min(l1.p1.y, l1.p2.y)))
             return true;

       return false;
    }

    int direction(Point a, Point b, Point c) {
       int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
       if (val == 0){
           return 0;           //colinear
       }else if(val < 0){
           return 2;          //anti-clockwise direction
       }
          return 1;          //clockwise direction
    }

    bool isIntersect(line l1, line l2) {
       //four direction for two lines and points of other line
       int dir1 = direction(l1.p1, l1.p2, l2.p1);
       int dir2 = direction(l1.p1, l1.p2, l2.p2);
       int dir3 = direction(l2.p1, l2.p2, l1.p1);
       int dir4 = direction(l2.p1, l2.p2, l1.p2);

       if(dir1 != dir2 && dir3 != dir4)
          return true;           //they are intersecting
       if(dir1==0 && onLine(l1, l2.p1))        //when p2 of line2 are on the line1
          return true;
       if(dir2==0 && onLine(l1, l2.p2))         //when p1 of line2 are on the line1
          return true;
       if(dir3==0 && onLine(l2, l1.p1))       //when p2 of line1 are on the line2
          return true;
       if(dir4==0 && onLine(l2, l1.p2)) //when p1 of line1 are on the line2
          return true;
       return false;
    }

    bool checkInside(std::vector<Point> poly, Point p) {
       if(poly.size() < 3)
          return false;                  //when polygon has less than 3 edge, it is not polygon
       line exline = {p, {9999, p.y}};   //create a point at infinity, y is same as point p
       int count = 0;
       int i = 0;
       do {
          line side = {poly[i], poly[(i+1)%poly.size()]};     //forming a line from two consecutive points of poly
          if(isIntersect(side, exline)) {          //if side is intersects exline
             if(direction(side.p1, p, side.p2) == 0)
                return onLine(side, p);
             count++;
          }
          i = (i+1)%poly.size();
       } while(i != 0);
          return count&1;             //when count is odd
    }
};

}




#endif // CITYMAP_H
