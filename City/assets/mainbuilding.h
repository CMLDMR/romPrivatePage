#ifndef ASSETS_MAINBUILDING_H
#define ASSETS_MAINBUILDING_H

#include <string>
#include <building/building.h>

namespace Assets {

class MainBuilding
{
public:
    MainBuilding();

    int assetWidth() const;

    int assetHeight() const;

    std::string assetPath() const;

    std::string acceptedPlaceAreaAssetPath() const;

    std::string deniedPlaceAreaAssetPath() const;

private:
    const std::string mAssetName{"mainbuilding"};
    const std::string mAssetPath{"assets/building/"+mAssetName+".png"};
    const std::string mAcceptedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"accept"+".png"};
    const std::string mDeniedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"deny"+".png"};


    const int mAssetWidth{169};
    const int mAssetHeight{109};
};

} // namespace Assets

#endif // ASSETS_MAINBUILDING_H
