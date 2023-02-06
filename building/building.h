#ifndef BUILDING_H
#define BUILDING_H

#include "item.h"


namespace Building{

class Building : public GameCore::Item
{
public:
    Building(const std::string &_buildingName):GameCore::Item(_buildingName){}

private:

};


}








#endif // BUILDING_H
