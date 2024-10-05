/*

Assignment:     Project 4 - Menu of Shapes
Name:           Jared Bears
Date:           2024-10-06
File:           Menu.cpp

*/

// Implementation file for the Menu class
#include "Menu.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

void Menu::displayMenu()
{
    int choice;
    do
    {
        cout << "Menu of Shapes" << endl;
        cout << "1. Triangle" << endl;
        cout << "2. Inverted Triangle" << endl;
        cout << "3. Rectangle" << endl;
        cout << "4. Bowtie" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 5: ";
        }
        switch (choice)
        {
        case 1:
            cout << "Triangle" << endl;
            break;
        case 2:
            cout << "Inverted Triangle" << endl;
            break;
        case 3:
            cout << "Rectangle" << endl;
            break;
        case 4:
            cout << "Bowtie" << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        }
    } while (choice != 5);
}