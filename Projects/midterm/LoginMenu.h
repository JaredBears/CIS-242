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

class LoginMenu : public Menu
{
private:
    unordered_map<string, User *> *userBase;

public:
    LoginMenu();
    ~LoginMenu();
    void displayMenu();
    void login(string, string);
};

#endif