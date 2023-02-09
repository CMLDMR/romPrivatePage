#include "item.h"

namespace GameCore {

Item::Item(const std::string &_name)
    :mItemName(_name)
{

}


std::string Item::itemName() const
{
    return mItemName;
}



} // namespace GameCore
