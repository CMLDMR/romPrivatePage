#include "item.h"

namespace GameCore {

Item::Item()
{

}

int Item::xPos() const
{
    return mXPos;
}

void Item::setXPos(int newXPos)
{
    mXPos = newXPos;
}

int Item::yPos() const
{
    return mYPos;
}

void Item::setYPos(int newYPos)
{
    mYPos = newYPos;
}


} // namespace GameCore
