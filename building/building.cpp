#include "building.h"

using namespace Wt;


std::list<Building::Area> Building::AreaSize() const
{
    return mSize;
}

int Building::baseWidth() const
{
    return mBaseWidth;
}

int Building::baseHeight() const
{
    return mBaseHeight;
}

void Building::setBackGround(const std::string &_imgUrl)
{
    this->setAttributeValue("style","background:url("+_imgUrl+");;background-repeat:no-repeat;");
}

int Building::x() const
{
    return mX;
}

int Building::y() const
{
    return mY;
}

void Building::setBaseWidth(int newBaseWidthMultiplier)
{
    mBaseWidth = mBaseOffSetW * newBaseWidthMultiplier * 2;
}

void Building::setBaseHeight(int newBaseHeightMultiplier)
{
    mBaseHeight = mBaseOffSetH * newBaseHeightMultiplier * 2;
}


