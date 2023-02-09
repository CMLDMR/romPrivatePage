#include "castlebuilding.h"

namespace Assets {

CastleBuilding::CastleBuilding()
{

}

int CastleBuilding::assetWidth() const
{
    return mAssetWidth;
}

int CastleBuilding::assetHeight() const
{
    return mAssetHeight;
}

std::string CastleBuilding::assetPath() const
{
    return mAssetPath;
}

std::string CastleBuilding::acceptedPlaceAreaAssetPath() const
{
    return mAcceptedPlaceAreaAssetPath;
}

std::string CastleBuilding::deniedPlaceAreaAssetPath() const
{
    return mDeniedPlaceAreaAssetPath;
}

} // namespace Assets
