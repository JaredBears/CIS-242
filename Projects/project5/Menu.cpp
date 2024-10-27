/*

Assignment:     Project 5 - Stacks and Queues
Name:           Jared Bears
Date:           2024-11-04
File:           Menu.cpp

*/

// Implementation file for the Menu class

#include "Menu.h"
#include <iostream>
#include <limits>
using namespace std;

void Menu::displayMenu()
{
    while (true)
    {
        cout << endl;
        cout << "1. Add an item to the inventory" << endl;
        cout << "2. Remove an item from the inventory" << endl;
        cout << "3. Exit" << endl;

        int choice = getIntInput("Enter your choice: ", 1, 3);

        switch (choice)
        {
        case 1:
            addInventoryItem();
            break;
        case 2:
            removeInventoryItem();
            break;
        case 3:
            exit();
            return;
        }
    }
}

int Menu::getIntInput(string prompt)
{
    int input;
    cout << prompt;
    cin >> input;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: ";
        cin >> input;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

int Menu::getIntInput(string prompt, int min)
{
    int input;
    cout << prompt;
    cin >> input;
    while (cin.fail() || input < min)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer greater than or equal to " << min << ": ";
        cin >> input;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

int Menu::getIntInput(string prompt, int min, int max)
{
    int input;
    cout << prompt;
    cin >> input;
    while (cin.fail() || input < min || input > max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer between " << min << " and " << max << ": ";
        cin >> input;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

string Menu::getStringInput(string prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

string Menu::getStringInput(string prompt, string pattern)
{
    string input;
    cout << prompt;
    getline(cin, input);
    while (!regex_match(input, regex(pattern)))
    {
        cout << "Invalid input. Please enter a valid string: " << endl;
        cin.clear();
        cout << prompt;
        getline(cin, input);
    }
    return input;
}

void Menu::addInventoryItem()
{
    int serial;
    string manDate;
    int lot;
    cout << endl;
    serial = getIntInput("Enter the serial number: ", 1);
    manDate = getStringInput("Enter the manufacturing date (YYYY-MM-DD): ", "\\d{4}-\\d{2}-\\d{2}");
    lot = getIntInput("Enter the lot number: ", 1);

    Inventory item(serial, manDate, lot);
    inventoryStack.push(item);
}

void Menu::removeInventoryItem()
{
    cout << endl;
    if (inventoryStack.isEmpty())
    {
        cout << "Inventory is empty.\n";
    }
    else
    {
        Inventory item = inventoryStack.pop();
        cout << "Removed item: " << endl;
        cout << item.toString() << endl
             << endl;
    }
}

void Menu::exit()
{
    cout << endl
         << "The Following items remain in the inventory: " << endl;
    while (!inventoryStack.isEmpty())
    {
        cout << "Item: " << endl;
        Inventory item = inventoryStack.pop();
        cout << item.toString() << endl
             << endl;
    }

    cout << "Goodbye!\n";
}