#include <iostream>
#include "Practice.h"

int main() {
    Practice* practice = new Practice(); // Get the singleton instance
    practice -> run();

    delete practice; // Clean up the allocated memory

    return 0;
}