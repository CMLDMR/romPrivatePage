#include "item.h"

namespace GameCore {

Item::Item(const std::string &_name)
    :mItemName(_name)
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

std::string Item::itemName() const
{
    return mItemName;
}

std::string Item::assetPath() const
{
    return mAssetPath;
}

void Item::setAssetPath(const std::string &newAssetPath)
{
    mAssetPath = newAssetPath;
}

void Item::setAssetsGeometry(const int &w, const int &h)
{
    this->_height = h;
    this->_width = w;
}

int Item::assetWidth() const
{
    return _width;
}

int Item::assetHeight() const
{
    return _height;
}


} // namespace GameCore
