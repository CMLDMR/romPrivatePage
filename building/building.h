#ifndef BUILDING_H
#define BUILDING_H

#include "item.h"
#include <vector>


namespace Building{

enum Type{
    main = 0,
    castle,
    house,
    farmer
};


struct Point
{
    int x;
    int y;
};

class Building : public GameCore::Item
{
public:
    Building( const Type &_buildType );

    Type buildType() const;

    void setGeometry( const int &width , const int &height );

    int buildingWidth() const;
    int buildingHeight() const;

    void setBuildType(Type newBuildType);

    std::string buildingName() const;

    std::string assetPath() const;

    std::string acceptedPlaceAreaAssetPath() const;

    std::string deniedPlaceAreaAssetPath() const;

    std::vector<Point> getPolyShape() const;
private:
    Type mBuildType;

    int mAssetWidth;
    int mAssetHeight;

    std::string mAssetName{"mainbuilding"};
    std::string mAssetPath{"assets/building/"+mAssetName+".png"};
    std::string mAcceptedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"accept"+".png"};
    std::string mDeniedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"deny"+".png"};

    std::string mBuildingName;

    std::vector<Point> mMaskPolygon;

    void initBuilding(const std::string &_buildName, const std::string &_assetName , const int &_width, const int &_height, std::vector<Point> _polygon);
};







}








#endif // BUILDING_H
