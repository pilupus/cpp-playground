// Practice.cpp
//
#include <iostream>
#include "Practice.h"
#include <string>

using namespace std;

Practice::Practice() {
    // Constructor implementation
    system("cls");
}


int getNewID(const int val) {
    cout << "getNewID called with value: " << val << endl;
    
    static int ID = 0;
    return ++ID;
}

void swap(int &ref_a, int &ref_b) {
    int temp = ref_a;
    ref_a = ref_b;
    ref_b = temp;
}

void Practice::run() {
    for (int seq = 0; seq < 5; seq++)
    {
        cout << "ID: " << getNewID(seq) << endl;
    }

    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
}
