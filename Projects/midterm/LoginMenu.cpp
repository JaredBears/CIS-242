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

// Pulls up the database of existing users.  For now, it's just a hardcoded map,
// but will eventually be a JSON file full of User Objects.

LoginMenu::LoginMenu()
{
    // use dynamic memory allocation to create a new unordered_map
    userBase = new unordered_map<string, string>;
    // add some users to the map
    userBase->insert({"jared", "password1"});
    userBase->insert({"jane", "password2"});
    // TODO: Once User Objects are created, add them to the map instead of strings
}

// Prompts the user for a username and password, then checks them against the database.
// If the user is found, returns the username.  If not, creates a new user.
// TODO: Passes the User to the TransactionMenu.

void LoginMenu::displayMenu(TransactionMenu tm)
{
    string username;
    string password;

    cout << "Welcome to the ATM.  Please log in." << endl;
    username = getStringInput("Enter Your Username: ");
    password = getStringInput("Enter Your Password: ");

    login(username, password, tm);
}

void LoginMenu::login(string username, string password, TransactionMenu tm)
{
    // check if the username exists in the database
    if (userBase->find(username) != userBase->end())
    {
        // if the username exists, check if the password matches
        if (userBase->at(username) == password)
        {
            // if the password matches, display the username
            // TODO: Pass user to TransactionMenu
            cout << "Welcome, " << username << "!" << endl;
            tm.displayMenu();
        }
        else
        {
            // if the password doesn't match, display an error message and
            // return to the menu
            cout << "Incorrect password.  Please try again." << endl;
            displayMenu(tm);
        }
    }
    else
    {
        // if the username doesn't exist, add it to the database and display it.
        // TODO: Create a User Object and add it to the database
        // TODO: Pass user to TransactionMenu
        userBase->insert({username, password});
        cout << "New user created: " << username << endl;
        cout << "Welcome, " << username << "!" << endl;
        tm.displayMenu();
    }
}