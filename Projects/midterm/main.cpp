/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           main.cpp

*/

#include "LoginMenu.h"
#include "TransactionMenu.h"

int main()
{
    LoginMenu lm;
    TransactionMenu tm;
    lm.displayMenu(tm);

    return 0;
}