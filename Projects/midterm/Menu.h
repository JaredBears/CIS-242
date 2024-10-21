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
// Provides utility functions for input handling and truncating double values
class Menu
{
public:
    // Prompts the user for a string input
    string getStringInput(string);

    // Prompts the user for an integer input within a specified range
    int getIntInput(string, int, int);

    // Prompts the user for any double input
    double getDoubleInput(string);

    // Prompts the user for a double input within a specified range
    double getDoubleInput(string, double, double);

    // Truncates a double value to a specified number of decimal places
    double truncateDouble(double, int);
};

#endif