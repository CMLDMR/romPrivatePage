#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H


//TODO: Remove When Releasing
#define DEVELOPMENTMODE



// Control Panel Select Map
enum class Map{
    World = 0x00000001,
    City,
    Village,
    unKnown = 0x11111111 // 8bit
};


#endif // GLOBALVARIABLE_H
