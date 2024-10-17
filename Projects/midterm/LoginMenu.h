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
#include <string>
#include <unordered_map>
using namespace std;

// LoginMenu class declaration

class LoginMenu : public Menu
{
public:
    LoginMenu();
    void displayMenu(TransactionMenu);
    void login(string, string, TransactionMenu);

private:
    unordered_map<string, string> *userBase;
};

#endif