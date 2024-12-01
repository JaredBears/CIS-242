/*

Assignment:     Final Project - Tic Tac Toe Game
Name:           Jared Bears
Date:           12/11/2024
File:           main.cpp

*/

#include <iostream>
#include "Menu.h"
using namespace std;

int main()
{
    try
    {
        Menu menu;
        menu.handleInput();
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}