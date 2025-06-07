#include <iostream>
#include "Game.h"

#ifdef _WIN32
bool isWindows = true;
#else
bool isWindows = false;
#endif

int main() {
    Game game(10, 10, isWindows);
    game.run();
    
    return 0;
}