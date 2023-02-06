#ifndef GAMECORE_ITEM_H
#define GAMECORE_ITEM_H

#include <string>

namespace GameCore {

class Item
{
public:
    Item();




    int xPos() const;
    void setXPos(int newXPos);

    int yPos() const;
    void setYPos(int newYPos);

private:
    int mXPos;
    int mYPos;
    std::string mItemName;
};

} // namespace GameCore

#endif // GAMECORE_ITEM_H
