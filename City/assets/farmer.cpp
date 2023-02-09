#include "farmer.h"

namespace Assets {

Farmer::Farmer()
{

}

int Farmer::assetWidth() const
{
    return mAssetWidth;
}

int Farmer::assetHeight() const
{
    return mAssetHeight;
}

std::string Farmer::assetPath() const
{
    return mAssetPath;
}

std::string Farmer::acceptedPlaceAreaAssetPath() const
{
    return mAcceptedPlaceAreaAssetPath;
}

std::string Farmer::deniedPlaceAreaAssetPath() const
{
    return mDeniedPlaceAreaAssetPath;
}

} // namespace Assets
