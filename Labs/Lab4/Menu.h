/*

Assignment:     Lab 4 - List Equality
Name:           Jared Bears
Date:           2024-11-18
File:           Menu.h

*/

// Specification file for the Menu class

#ifndef MENU_H
#define MENU_H

#include "List.h"
#include <string>
using namespace std;

class Menu
{
public:
    // Display the menu and handle user input
    void displayMenu();

private:
    List<int> list1; // List to hold user-inputed integers
    List<int> list2; // List to hold user-inputed integers
    List<int> list3; // List to hold random integers

    // Fill a list with user-inputed integers
    void fillList(List<int> &, int);
    // Fill a list with random integers
    void fillRandomList(List<int> &, int);
    // Compare the three lists
    void compareLists();
};

#endif