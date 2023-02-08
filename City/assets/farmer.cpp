#include "farmer.h"

namespace Assets {

Farmer::Farmer()
    :Building::Building("Çiftlik")
{
    this->setAssetPath("assets/building/farmer.png");
    this->setAssetsGeometry(230,137);

    this->mBuildType = ::Building::Type::farmer;
}

} // namespace Assets
