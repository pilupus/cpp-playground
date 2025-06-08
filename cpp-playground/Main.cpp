#include <iostream>
#include "Game.h"
#include "Practice.h"

#ifdef _WIN32
bool isWindows = true;
#else
bool isWindows = false;
#endif

int main() {
    Practice* practice = new Practice(); // Get the singleton instance
    practice -> run();

    delete practice; // Clean up the allocated memory

    Game game(20, 20, isWindows);
    game.run();
    
    return 0;
}
