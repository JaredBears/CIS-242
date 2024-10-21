/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           LoginMenu.h

*/

// Specification file for the LoginMenu class

#ifndef LOGINMENU_H
#define LOGINMENU_H

#include "Menu.h"
#include "TransactionMenu.h"
#include "User.h"
#include <string>
#include <unordered_map>
using namespace std;

// LoginMenu class declaration
// Handles user login and user creation
class LoginMenu : public Menu
{
private:
    // map to store user objects by username
    unordered_map<string, User *> *userBase;

    // Handles user login
    void login(string, string);

    // Loads user data from a JSON file
    void loadUserBase();

    // Saves user data to a JSON file
    void saveUserBase();

public:
    // Constructor
    LoginMenu();

    // Destructor
    ~LoginMenu();

    // Displays the login menu
    void displayMenu();
};

#endif