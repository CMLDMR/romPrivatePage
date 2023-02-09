#ifndef BUILDING_H
#define BUILDING_H

#include "item.h"



namespace Building{

enum Type{
    main = 0,
    castle,
    house,
    farmer
};

class Building : public GameCore::Item
{
public:
    Building(const std::string &_buildingName):GameCore::Item(_buildingName){}

    Type buildType() const;

    void setGeometry( const int &width , const int &height );

    int buildingWidth() const;
    int buildingheight() const;

    void setBuildType(Type newBuildType);

private:
    Type mBuildType;

    int mAssetWidth;
    int mAssetHeight;
};


}








#endif // BUILDING_H
