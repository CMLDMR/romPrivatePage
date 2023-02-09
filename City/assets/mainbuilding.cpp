#include "mainbuilding.h"

namespace Assets {

MainBuilding::MainBuilding()
{

}

int MainBuilding::assetWidth() const
{
    return mAssetWidth;
}

int MainBuilding::assetHeight() const
{
    return mAssetHeight;
}

std::string MainBuilding::assetPath() const
{
    return mAssetPath;
}

std::string MainBuilding::acceptedPlaceAreaAssetPath() const
{
    return mAcceptedPlaceAreaAssetPath;
}

std::string MainBuilding::deniedPlaceAreaAssetPath() const
{
    return mDeniedPlaceAreaAssetPath;
}

} // namespace Assets
