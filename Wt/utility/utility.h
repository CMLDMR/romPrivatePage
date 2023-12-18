#ifndef UTILITY_UTILITY_H
#define UTILITY_UTILITY_H


#include <iostream>
#include <ostream>
#include <Wt/WString.h>

#define LOG     std::cout << "\n["<<__LINE__ <<  "]["<<  __FUNCTION__ << "]: "

namespace Utility {

class Utility
{
public:
    Utility();

    int getRandom( const int min, const int max );


};

} // namespace Utility

#endif // UTILITY_UTILITY_H
