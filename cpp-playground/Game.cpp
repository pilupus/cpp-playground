// Game class: This class is intended to represent a game in a C++ project.
// Game.cpp: Implementation of the Game class for a simple console game in C++.

#include "Game.h"
#include <iostream>
#include <string>

Game::Game(int width, int height, bool isWindows)
    : width(width), height(height), playerX(width / 2), playerY(height / 2), running(true), isWindows(isWindows) {}

void Game::run()
{
    while (running)
    {
        clearScreen();
        drawMap();

        std::cout << "\n"
                  << "Use WASD to move, Q to quit.\n";
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty())
        {
            processInput(std::toupper(input[0]));
        }
    }
    std::cout << "Game Over!" << std::endl;
}

void Game::drawMap() const
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x == playerX && y == playerY)
            {
                std::cout << '@'; // Player character
            }
            else
            {
                std::cout << '.'; // Empty space
            }
        }
        std::cout << '\n';
    }
}

void Game::processInput(char input)
{
    switch (input)
    {
        case 'W': // Move up
            if (playerY > 0) playerY--;
            break;
        case 'A': // Move left
            if (playerX > 0) playerX--;
            break;
        case 'S': // Move down
            if (playerY < height - 1) playerY++;
            break;
        case 'D': // Move right
            if (playerX < width - 1) playerX++;
            break;
        case 'Q': // Quit the game
            running = false;
            break;
        default:
            std::cout << "Invalid input! Use WASD to move, Q to quit.\n";
            break;
    }
}

void Game::clearScreen() const
{
    if (isWindows) // for Windows
    {
        system("cls");
    }
    else // for Unix/Linux
    {
        system("clear");
    }
}
