// Practice.cpp
//
#include "Practice.h"

#include <iostream>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>

using namespace std;

class accelerator;
const int dummy = 0;

class engine
{
private:
    virtual void acceleration_output() = 0;
    virtual void reduce_output() = 0;
    friend class accelerator;
};

class ic_engine : public engine
{
private:
    virtual void acceleration_output() = 0;
    virtual void reduce_output() = 0;
};

class gs_engine : public engine
{
private:
    void acceleration_output() override { increasing_fuel(); };
    void reduce_output() override { decreasing_fuel(); };
    void increasing_fuel() { increasing_piston_speed(); };
    void decreasing_fuel() { decreasing_piston_speed(); };
    void increasing_piston_speed() { cout << "Increasing piston speed in gs_engine." << endl; };
    void decreasing_piston_speed() { cout << "Decreasing piston speed in gs_engine." << endl; };
};

class elec_engin : public engine
{
private:
    void acceleration_output() override { increasing_motor_speed(); };
    void reduce_output() override { decreasing_motor_speed(); };
    void increasing_motor_speed() { cout << "Increasing motor speed in elec_engin." << endl; };
    void decreasing_motor_speed() { cout << "Decreasing motor speed in elec_engin." << endl; };
};



Practice::Practice()
{
    // Constructor implementation
    system("cls");
    cout << "Welcome to the C++ Practice Program!" << endl;
};

void Practice::run() {
};
