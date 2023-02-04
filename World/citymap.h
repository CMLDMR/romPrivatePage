#ifndef CITYMAP_H
#define CITYMAP_H

#include <Wt/WContainerWidget.h>
#include <mutex>


class CityMap : public Wt::WContainerWidget
{
public:
    CityMap();




    void addBuild( const int x, const int y,
                   const std::string &assetPath,
                   const int width,const int height);


    Wt::WContainerWidget* mMap;

};

#endif // CITYMAP_H
