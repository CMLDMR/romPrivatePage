#ifndef ASSETS_HOUSE_H
#define ASSETS_HOUSE_H

#include <string>

namespace Assets {

class House
{
public:
    House();

    int assetWidth() const;

    int assetHeight() const;

    std::string assetPath() const;

    std::string acceptedPlaceAreaAssetPath() const;

    std::string deniedPlaceAreaAssetPath() const;

private:
    const std::string mAssetName{"house1building"};
    const std::string mAssetPath{"assets/building/"+mAssetName+".png"};
    const std::string mAcceptedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"accept"+".png"};
    const std::string mDeniedPlaceAreaAssetPath{"assets/building/"+mAssetName+"-"+"deny"+".png"};


    const int mAssetWidth{224};
    const int mAssetHeight{127};
};

} // namespace Assets

#endif // ASSETS_HOUSE_H
