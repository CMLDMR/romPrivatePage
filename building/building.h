#ifndef BUILDING_H
#define BUILDING_H

#include "item.h"

namespace Assets {
    class CastleBuilding;
    class House;
    class MainBuilding;
}

namespace Building{


enum Type{
    main = 0,
    castle,
    house
};


class Building : public GameCore::Item
{
public:
    Building(const std::string &_buildingName):GameCore::Item(_buildingName){}

    Type buildType() const;

private:
    Type mBuildType;



public:
    friend class Assets::CastleBuilding;
    friend class Assets::House;
    friend class Assets::MainBuilding;


};


}








#endif // BUILDING_H
