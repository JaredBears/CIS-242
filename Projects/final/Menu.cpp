/*

Assignment:     Final Project - Tic Tac Toe Game
Name:           Jared Bears
Date:           12/11/2024
File:           Menu.cpp

*/

#include "Menu.h"
#include <iostream>
#include <limits>

void Menu::displayMenu()
{
    cout << "Welcome to the Ultimate Tic Tac Toe Game!" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Exit" << endl;
}

void Menu::handleInput()
{
    int choice;
    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1)
        {
            XandO game;
            game.play();
        }
        else if (choice == 2)
        {
            cout << "Exiting the game. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}