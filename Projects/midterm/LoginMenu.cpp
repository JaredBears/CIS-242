/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           LoginMenu.cpp

*/

// Implementation file for the LoginMenu class

#include "LoginMenu.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Constructor for the LoginMenu class
LoginMenu::LoginMenu()
{
    userBase = new unordered_map<string, User *>;
    loadUserBase();
}

// Loads user data from a JSON file
void LoginMenu::loadUserBase()
{
    ifstream file("userbase.json");
    if (file.is_open())
    {
        stringstream buffer;
        buffer << file.rdbuf();
        string jsonStr = buffer.str();
        file.close();

        size_t pos = 0;
        while ((pos = jsonStr.find("{", pos)) != string::npos)
        {
            size_t endPos = jsonStr.find("}", pos);
            string userStr = jsonStr.substr(pos, endPos - pos + 1);
            pos = endPos + 1;

            size_t userPos = userStr.find("\"username\":");
            size_t passPos = userStr.find("\"password\":");
            size_t balPos = userStr.find("\"balance\":");

            string username = userStr.substr(userPos + 12, userStr.find(",", userPos) - userPos - 13);
            string password = userStr.substr(passPos + 12, userStr.find(",", passPos) - passPos - 13);
            double balance = stod(userStr.substr(balPos + 10, userStr.find("}", balPos) - balPos - 10));

            // Remove quotation marks from username and password
            username = username.substr(1, username.length() - 1);
            password = password.substr(1, password.length() - 1);

            userBase->insert({username, new User(username, password, balance)});
        }
    }
    else
    {
        // Default users if JSON file does not exist
        userBase->insert({"jared", new User("jared", "password")});
        userBase->insert({"jane", new User("jane", "password")});
    }
}

// Saves user data to a JSON file
void LoginMenu::saveUserBase()
{
    ofstream file("userbase.json", ofstream::trunc); // Open file in truncate mode to overwrite
    if (file.is_open())
    {
        file << "[\n";
        for (auto it = userBase->begin(); it != userBase->end(); ++it)
        {
            file << "  {\n";
            file << "    \"username\": \"" << it->first << "\",\n";
            file << "    \"password\": \"" << it->second->getPassword() << "\",\n";
            file << "    \"balance\": " << it->second->getBalance() << "\n";
            file << "  }";
            if (next(it) != userBase->end())
            {
                file << ",";
            }
            file << "\n";
        }
        file << "]";
        file.close();
    }
}

// Displays the login menu
void LoginMenu::displayMenu()
{
    string username;
    string password;

    cout << "Welcome to the ATM. Please log in." << endl;
    username = getStringInput("Enter Your Username: ");
    password = getStringInput("Enter Your Password: ");

    login(username, password);
}

// Handles user login
void LoginMenu::login(string username, string password)
{
    auto it = userBase->find(username);
    // if user exists, check password, else create new user
    if (it != userBase->end())
    {
        User *user = it->second;
        // if password matches, display transaction menu, else try again
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

// Destructor for the LoginMenu class
LoginMenu::~LoginMenu()
{
    saveUserBase();
    for (auto it = userBase->begin(); it != userBase->end(); ++it)
    {
        delete it->second; // Delete each User object
    }
    delete userBase; // Delete the unordered_map
}