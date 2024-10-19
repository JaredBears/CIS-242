/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           Menu.cpp

*/

// Implementation file for the Menu class

#include "Menu.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

// Prompts the user for an integer input within a specified range
int Menu::getIntInput(string prompt, int min, int max)
{
    int value;
    cout << prompt;
    while (!(cin >> value) || value < min || value > max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": " << endl;
        cout << prompt;
    }
    return value;
}

// Prompts the user for a string input
string Menu::getStringInput(string prompt)
{
    string value;
    cout << prompt;
    cin >> value;
    return value;
}

// Prompts the user for a double input within a specified range
double Menu::getDoubleInput(string prompt, double min, double max)
{
    double value;
    cout << prompt;
    while (!(cin >> value) || value < min || value > max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << fixed << setprecision(2);
        cout << "Invalid input. Please enter a number between $" << min << " and $" << max << ": " << endl;
        cout << prompt;
    }
    return value;
}

// Truncates a double value to a specified number of decimal places
double Menu::truncateDouble(double value, int places)
{
    value -= pow(10, -places) / 2;
    double factor = pow(10, places);
    return round(value * factor) / factor;
}