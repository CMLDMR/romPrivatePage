#include "mainbuilding.h"

namespace Assets {

MainBuilding::MainBuilding()
    :Building::Building("Ana Bina")
{

    this->setAssetPath("assets/building/mainbuilding.png");
    this->setAcceptedPlaceAreaPath("assets/building/mainbuilding-accept.png");
    this->setDeniedPlaceAreaPath("assets/building/mainbuilding-deny.png");
    this->setAssetsGeometry(169,109);

    this->mBuildType = ::Building::Type::main;

}

} // namespace Assets
