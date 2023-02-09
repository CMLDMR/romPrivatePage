#include "building.h"


Building::Building::Building( const Type &_buildType )
    :mBuildType(_buildType)
{

    switch (mBuildType) {
    case Type::castle:
        this->initBuilding("Kale","castlebuilding",170,108,{{2,67},{76,30},{167,70},{81,106}});
        break;
    case Type::farmer:
        this->initBuilding("Çiftlik","farmer",230,137,{{0,76},{109,20},{228,77},{112,135}});
        break;
    case Type::house:
        this->initBuilding("Ev","house1building",224,127,{{2,72},{102,23},{214,72},{110,125}});
        break;
    case Type::main:
        this->initBuilding("Ana Bina","mainbuilding",169,109,{{2,65},{84,24},{166,65},{85,107}});
        break;

    default:
        break;
    }



}

Building::Type Building::Building::buildType() const
{
    return mBuildType;
}

void Building::Building::setGeometry(const int &width, const int &height)
{
    this->mAssetWidth = width;
    this->mAssetHeight = height;
}

int Building::Building::buildingWidth() const
{
    return this->mAssetWidth;
}

int Building::Building::buildingHeight() const
{
    return this->mAssetHeight;
}


namespace Building {
void Building::setBuildType(Type newBuildType)
{
    mBuildType = newBuildType;
}

std::string Building::buildingName() const
{
    return mBuildingName;
}

std::string Building::assetPath() const
{
    return mAssetPath;
}

std::string Building::acceptedPlaceAreaAssetPath() const
{
    return mAcceptedPlaceAreaAssetPath;
}

std::string Building::deniedPlaceAreaAssetPath() const
{
    return mDeniedPlaceAreaAssetPath;
}

std::vector<Point> Building::getPolyShape() const
{
    return mMaskPolygon;
}

void Building::initBuilding(const std::string &_buildName, const std::string &_assetName,
                            const int &_width, const int &_height,
                            std::vector<Point> _polygon)
{

    mBuildingName = _buildName;
    mAssetName = _assetName;
    mAssetPath = "assets/building/"+mAssetName+".png";
    mAcceptedPlaceAreaAssetPath = "assets/building/"+mAssetName+"-"+"accept"+".png";
    mDeniedPlaceAreaAssetPath = "assets/building/"+mAssetName+"-"+"deny"+".png";
    setGeometry(_width,_height);

    for( const auto &point : _polygon ){
        mMaskPolygon.push_back(point);
    }
}

}
