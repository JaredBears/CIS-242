/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           LoginMenu.cpp

*/

// Implementation file for the LoginMenu class

#include "LoginMenu.h"
#include "TransactionMenu.h"
#include <iostream>

LoginMenu::LoginMenu()
{
    userBase = new unordered_map<string, User *>;
    userBase->insert({"jared", new User("jared", "password1")});
    userBase->insert({"jane", new User("jane", "password2")});
}

void LoginMenu::displayMenu()
{
    string username;
    string password;

    cout << "Welcome to the ATM. Please log in." << endl;
    username = getStringInput("Enter Your Username: ");
    password = getStringInput("Enter Your Password: ");

    login(username, password);
}

void LoginMenu::login(string username, string password)
{
    auto it = userBase->find(username);
    if (it != userBase->end())
    {
        User *user = it->second;
        if (user->getPassword() == password)
        {
            cout << "Welcome, " << username << "!" << endl;
            TransactionMenu tm(user);
            tm.displayMenu();
        }
        else
        {
            cout << "Incorrect password. Please try again." << endl;
            displayMenu();
        }
    }
    else
    {
        User *newUser = new User(username, password);
        userBase->insert({username, newUser});
        cout << "New user created: " << username << endl;
        cout << "Welcome, " << username << "!" << endl;
        TransactionMenu tm(newUser);
        tm.displayMenu();
    }
}

LoginMenu::~LoginMenu()
{
    for (auto it = userBase->begin(); it != userBase->end(); ++it)
    {
        delete it->second; // Delete each User object
    }
    delete userBase; // Delete the unordered_map
}