#ifndef CSSKEYS_H
#define CSSKEYS_H

#include <string>


// Buradaki Propertiesler
//https://www.w3schools.com/cssref/pr_background-color.php


namespace CSS {

namespace Key{
inline constexpr std::string background_color(const std::string &value ){ return "background-color:"+value+";";};
}
}

#endif // CSSKEYS_H
