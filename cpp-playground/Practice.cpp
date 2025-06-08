// Practice.cpp
//
#include <iostream>
#include "Practice.h"
#include <string>

using namespace std;

struct Person
{
    std::string name;
    int age;
    float height;
    float weight;
};

void check_age(Person* adult, int count)
{
    for (int idx = 0; idx < count; idx++)
    {
        if (adult[idx].age >= 25)
        {
            cout << "name: " << adult[idx].name << endl;
            cout << "age: " << adult[idx].age << endl;
            cout << "height: " << adult[idx].height << endl;
            cout << "weight: " << adult[idx].weight << endl;
        }
    }
}

void Practice::run() {
    std::cout << "Running practice code..." << std::endl;
    // Add your practice code here
    // For example, you can implement a simple algorithm or data structure

    Person adults[] = {
        {"Alice", 30, 5.5, 130.0},
        {"Bob", 22, 6.0, 180.0},
        {"Charlie", 28, 5.8, 150.0},
        {"David", 24, 5.9, 160.0}
    };

    cout << sizeof(adults) << endl;
    cout << sizeof(adults[0]) << endl;
    cout << "Number of adults: " << sizeof(adults) / sizeof(adults[0]) << endl;
    
    int count = sizeof(adults) / sizeof(adults[0]);
    check_age(adults, count);
}
