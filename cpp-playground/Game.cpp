// Game class: This class is intended to represent a game in a C++ project.
// Game.cpp: Implementation of the Game class for a simple console game in C++.

#include "Game.h"
#include <iostream>
#include <string>
#include <conio.h> // for _kbhit() and _getch()
#include <thread>
#include <chrono>

Game::Game(int width, int height, bool isWindows)
    : width(width), height(height), playerX(width / 2), playerY(height / 2), running(true), isWindows(isWindows), moved(false) {}

void Game::run()
{
    std::cout << "Press Any Key to Start the Game...\n";
    while (running)
    {
        if (moved) // Only clear the screen if the player has moved
        {
            clearScreen();
            drawMap();

            moved = false; // Reset moved flag at the start of each loop
        }

        // async input handling
        if (_kbhit()) // Check if a key has been pressed
        {
            char input = _getch(); // Get the pressed key
            processInput(std::toupper(input)); // Convert to uppercase for consistency
        }

        // control the game speed
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Sleep for 100 milliseconds
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
        std::cout << '\n'; // New line after each row
    }
    std::cout << "\nUse WASD to move, Q to quit.\n";
}

void Game::processInput(char input)
{
    switch (input)
    {
        case 'W': // Move up
            if (playerY > 0) 
            {
                playerY--;
                moved = true; // Set moved flag to true when player moves
            }
            break;
        case 'A': // Move left
            if (playerX > 0) 
            {
                playerX--;
                moved = true; // Set moved flag to true when player moves
            }
            break;
        case 'S': // Move down
            if (playerY < height - 1) 
            {
                playerY++;
                moved = true; // Set moved flag to true when player moves
            }
            break;
        case 'D': // Move right
            if (playerX < width - 1) 
            {
                playerX++;
                moved = true; // Set moved flag to true when player moves
            }
            break;
        case 'Q': // Quit the game
            running = false;
            break;
        default:
            // std::cout << "Invalid input! Use WASD to move, Q to quit.\n";
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
