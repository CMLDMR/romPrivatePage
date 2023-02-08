#include "castlebuilding.h"

namespace Assets {

CastleBuilding::CastleBuilding()
    :Building::Building("Kale")
{
    this->setAssetPath("assets/building/castlebuilding.png");
    this->setAssetsGeometry(170,108);

    this->mBuildType = ::Building::Type::castle;
}

} // namespace Assets
