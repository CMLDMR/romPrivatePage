#include "house.h"

namespace Assets {

House::House()
{


}

int House::assetWidth() const
{
    return mAssetWidth;
}

int House::assetHeight() const
{
    return mAssetHeight;
}

std::string House::assetPath() const
{
    return mAssetPath;
}

std::string House::acceptedPlaceAreaAssetPath() const
{
    return mAcceptedPlaceAreaAssetPath;
}

std::string House::deniedPlaceAreaAssetPath() const
{
    return mDeniedPlaceAreaAssetPath;
}

} // namespace Assets
