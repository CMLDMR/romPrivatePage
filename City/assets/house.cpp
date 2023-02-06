#include "house.h"

namespace Assets {

House::House()
    :Building::Building("Ev")
{
    this->setAssetPath("assets/building/house1building.png");
    this->setAssetsGeometry(266,216);
}

} // namespace Assets
