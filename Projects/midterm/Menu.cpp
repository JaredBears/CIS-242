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
#include <limits>
#include <cmath>
using namespace std;

int Menu::getIntInput(string prompt, int min, int max)
{
    int value;
    cout << prompt;
    while (!(cin >> value) || value < min || value > max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        cout << prompt;
    }
    return value;
}

string Menu::getStringInput(string prompt)
{
    string value;
    cout << prompt;
    cin >> value;
    return value;
}

double Menu::getDoubleInput(string prompt, double min, double max)
{
    double value;
    cout << prompt;
    while (!(cin >> value) || value < min || value > max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between $" << min << " and $" << max << ": ";
        cout << prompt;
    }
    return value;
}

double Menu::truncateDouble(double value, int places)
{
    value -= pow(10, -places) / 2;
    double factor = pow(10, places);
    return round(value * factor) / factor;
}