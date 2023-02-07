#ifndef ASSETS_CASTLEBUILDING_H
#define ASSETS_CASTLEBUILDING_H

#include <building/building.h>

namespace Assets {

class CastleBuilding : public Building::Building
{
public:
    CastleBuilding();


private:
    friend class Building::Building;
};

} // namespace Assets

#endif // ASSETS_CASTLEBUILDING_H
