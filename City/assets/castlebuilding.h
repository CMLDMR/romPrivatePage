#ifndef ASSETS_CASTLEBUILDING_H
#define ASSETS_CASTLEBUILDING_H

#include <building/building.h>

namespace Assets {

class CastleBuilding
{
public:
    CastleBuilding();


    int assetWidth() const;

    int assetHeight() const;

    std::string assetPath() const;

    std::string acceptedPlaceAreaAssetPath() const;

    std::string deniedPlaceAreaAssetPath() const;

private:
    const std::string mAssetName{"castlebuilding"};
    const std::string mAssetPath{"assets/building/"+mAssetName+".png"};
    const std::string mAcceptedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"accept"+".png"};
    const std::string mDeniedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"deny"+".png"};


    const int mAssetWidth{170};
    const int mAssetHeight{108};
};

} // namespace Assets

#endif // ASSETS_CASTLEBUILDING_H
