#include "building.h"


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

int Building::Building::buildingheight() const
{
    return this->mAssetHeight;
}


namespace Building {
void Building::setBuildType(Type newBuildType)
{
    mBuildType = newBuildType;
}

}
