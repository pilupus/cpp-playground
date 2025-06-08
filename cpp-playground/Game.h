// Game class: This class is intended to represent a game in a C++ project.

#pragma once

class Game
{
public:
    Game(int width, int height, bool isWindows);
    void run();

private:
    bool isWindows;

    int width;
    int height;
    int playerX;
    int playerY;
    bool running;
    bool moved;

    void drawMap() const;
    void processInput(char input);
    void clearScreen() const;
};
