#ifndef GAMECORE_ITEM_H
#define GAMECORE_ITEM_H

#include <string>


namespace GameCore {

class Item
{
public:
    Item(const std::string &_name);



    std::string itemName() const;


private:

    std::string mItemName;



};

} // namespace GameCore

#endif // GAMECORE_ITEM_H
