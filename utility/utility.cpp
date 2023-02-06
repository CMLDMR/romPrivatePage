#include "utility.h"

#include <random>

namespace Utility {

Utility::Utility()
{

}

int Utility::getRandom(const int min, const int max)
{


    std::random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    return mean;
}

} // namespace Utility
