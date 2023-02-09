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


class Building : public GameCore::Item
{
public:
    Building(const std::string &_buildingName):GameCore::Item(_buildingName){}

    Type buildType() const;

    void setPosition( const int &x , const int &y );
    std::pair<int,int> Position() const;

    int xPos() const;

    int yPos() const;
private:
    Type mBuildType;

    int mXPos;
    int mYPos;

public:
    friend class Assets::CastleBuilding;
    friend class Assets::House;
    friend class Assets::MainBuilding;
    friend class Assets::Farmer;



};


}








#endif // BUILDING_H
