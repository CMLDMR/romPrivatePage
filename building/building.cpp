#include "building.h"





Building::Type Building::Building::buildType() const
{
    return mBuildType;
}
int Building::Building::yPos()  const
{
    return mYPos;
}

int Building::Building::xPos()  const
{
    return mXPos;
}


void Building::Building::setPosition(const int &x, const int &y)
{
    this->mXPos = x;
    this->mYPos = y;
}

std::pair<int, int> Building::Building::Position() const
{
    return std::make_pair(this->mXPos,this->mYPos);
}


