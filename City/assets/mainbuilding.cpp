#include "mainbuilding.h"

namespace Assets {

MainBuilding::MainBuilding()
    :Building::Building("Ana Bina")
{

    this->setAssetPath("assets/building/mainbuilding.png");
    this->setAssetsGeometry(124,92);

    this->mBuildType = ::Building::Type::main;

}

} // namespace Assets
