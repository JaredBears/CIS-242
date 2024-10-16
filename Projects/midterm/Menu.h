/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           Menu.h

*/

// Specification file for the Menu class

#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

// Menu class declaration

class Menu
{
public:
    string getStringInput(string);
    int getIntInput(string, int, int);
    double getDoubleInput(string, double, double);
    double truncateDouble(double, int);
};

#endif