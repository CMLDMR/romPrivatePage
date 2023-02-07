#ifndef GAMECORE_ITEM_H
#define GAMECORE_ITEM_H

#include <string>


namespace GameCore {

class Item
{
public:
    Item(const std::string &_name);




    int xPos() const;
    void setXPos(int newXPos);

    int yPos() const;
    void setYPos(int newYPos);

    std::string itemName() const;

    std::string assetPath() const;
    void setAssetPath(const std::string &newAssetPath);

    void setAssetsGeometry( const int &w,const int &h );
    int assetWidth() const;
    int assetHeight() const;



private:
    int mXPos;
    int mYPos;
    std::string mItemName;
    std::string mAssetPath;

    int _width;
    int _height;
};

} // namespace GameCore

#endif // GAMECORE_ITEM_H
