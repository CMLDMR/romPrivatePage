#include "castlebuilding.h"

namespace Assets {

CastleBuilding::CastleBuilding()
    :Building::Building("Kale")
{
    this->setAssetPath("assets/building/castlebuilding.png");
    this->setAssetsGeometry(124,149);
}

} // namespace Assets
