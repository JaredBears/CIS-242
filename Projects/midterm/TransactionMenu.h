/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           TransactionMenu.h

*/

// Specification file for the TransactionMenu class

#ifndef TRANSACTIONMENU_H
#define TRANSACTIONMENU_H

#include "Menu.h"

// TransactionMenu class declaration

class TransactionMenu : public Menu
{
public:
    TransactionMenu();
    void displayMenu();
    void checkBalance();
    void transact(bool);
    void checkInterest();

private:
    double balance;
};

#endif