#ifndef BUILDING_H
#define BUILDING_H

#include "item.h"
#include <ostream>
namespace Assets {
    class CastleBuilding;
    class House;
    class MainBuilding;
    class Farmer;
}

namespace Building{


enum Type{
    main = 0,
    castle,
    house,
    farmer
};

//std::ostream& operator<<( std::ostream& ostream , const Type type ){

//    switch (type) {
//    case Type::castle:
//        ostream << "Building::Type::castle";
//        break;
//    case Type::main:
//        ostream << "Building::Type::main";
//    case Type::house:
//        ostream << "Building::Type::house";
//        break;
//    default:
//        break;
//    }

//    return ostream;
//}

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
    friend class Assets::Farmer;



};


}








#endif // BUILDING_H
