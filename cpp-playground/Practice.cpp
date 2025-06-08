// Practice.cpp
//
#include <iostream>
#include "Practice.h"
#include <string>

using namespace std;

Practice::Practice()
{
    // Constructor implementation
    system("cls");
}

struct Monster
{
    string name;
    int hp;
    int att;
    int def;
    int speed;
};

void printMonster(const Monster &monster)
{
    cout << "Monster Name: " << monster.name << endl;
    cout << "HP: " << monster.hp << endl;
    cout << "Attack: " << monster.att << endl;
    cout << "Defense: " << monster.def << endl;
    cout << "Speed: " << monster.speed << endl;
}

void Practice::run()
{
    int *parr = new int[5];
    for (int idx = 0; idx < 5; idx++)
    {
        parr[idx] = idx + 1;
        cout << parr[idx] << endl;
    }
    
    delete[] parr; // Free the allocated memory

    Monster* monster = new Monster{"Goblin", 100, 20, 10, 5};
    printMonster(*monster);
    delete monster; // Free the allocated memory for the monster
    
    monster = new Monster{"Orc", 150, 30, 20, 10};
    printMonster(*monster);
    delete monster; // Free the allocated memory for the monster
}
