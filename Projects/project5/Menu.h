/*

Assignment:     Project 5 - Stacks and Queues
Name:           Jared Bears
Date:           2024-11-04
File:           Menu.h

*/

// Specification file for the Menu class

#ifndef MENU_H
#define MENU_H

#include "Stack.h"
#include "Inventory.h"
#include <string>
#include <regex>
using namespace std;

class Menu
{
public:
    // Display the menu and handle user input
    void displayMenu();

private:
    Stack<Inventory> inventoryStack; // Stack to hold inventory items

    // Helper functions to get user input
    int getIntInput(string);
    int getIntInput(string, int);
    int getIntInput(string, int, int);
    string getStringInput(string);
    string getStringInput(string, string);

    // Functions to handle menu options
    void addInventoryItem();
    void removeInventoryItem();
    void exit();
};

#endif