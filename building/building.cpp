#include "building.h"


Building::Building::Building( const Type &_buildType )
    :mBuildType(_buildType)
{

    switch (mBuildType) {
    case Type::castle:
        this->initBuilding("Kale","castlebuilding");
        setGeometry(170,108);
        break;
    case Type::farmer:
        this->initBuilding("Çiftlik","farmer");
        setGeometry(230,137);
        break;
    case Type::house:
        this->initBuilding("Ev","house1building");
        setGeometry(224,127);
        break;
    case Type::main:
        this->initBuilding("Ana Bina","mainbuilding");
        setGeometry(169,109);
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

void Building::initBuilding(const std::string &_buildName, const std::string &_assetName)
{

    mBuildingName = _buildName;
    mAssetName = _assetName;
    mAssetPath = "assets/building/"+mAssetName+".png";
    mAcceptedPlaceAreaAssetPath = "assets/building/"+mAssetName+"-"+"accept"+".png";
    mDeniedPlaceAreaAssetPath = "assets/building/"+mAssetName+"-"+"deny"+".png";

}

}
