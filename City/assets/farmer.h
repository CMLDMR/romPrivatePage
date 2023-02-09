#ifndef ASSETS_FARMER_H
#define ASSETS_FARMER_H

#include <string>

namespace Assets {

class Farmer
{
public:
    Farmer();

    int assetWidth() const;

    int assetHeight() const;

    std::string assetPath() const;

    std::string acceptedPlaceAreaAssetPath() const;

    std::string deniedPlaceAreaAssetPath() const;

private:
    const std::string mAssetName{"farmer"};
    const std::string mAssetPath{"assets/building/"+mAssetName+".png"};
    const std::string mAcceptedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"accept"+".png"};
    const std::string mDeniedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"deny"+".png"};


    const int mAssetWidth{230};
    const int mAssetHeight{137};
};

} // namespace Assets

#endif // ASSETS_FARMER_H
