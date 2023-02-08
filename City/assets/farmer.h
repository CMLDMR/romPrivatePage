#ifndef ASSETS_FARMER_H
#define ASSETS_FARMER_H

#include <building/building.h>

namespace Assets {

class Farmer : public Building::Building
{
public:
    Farmer();

private:
    friend class Building::Building;
};

} // namespace Assets

#endif // ASSETS_FARMER_H
