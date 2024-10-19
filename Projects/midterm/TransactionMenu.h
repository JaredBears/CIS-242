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
#include "User.h"

// TransactionMenu class declaration
// Manages transactions such as checking balance, depositing, withdrawing, and calculating interest
class TransactionMenu : public Menu
{
public:
    // Constructor
    TransactionMenu(User *);

    // Displays the main menu for the TransactionMenu
    void displayMenu();

    // Checks the balance of the account
    void checkBalance();

    // Handles deposit and withdrawal transactions
    void transact(bool);

    // Checks the interest on the account
    void checkInterest();

private:
    User *user;

    // Logs the transaction to a CSV file
    void logTransaction(const string &username, double startingBalance, double amount, double endingBalance);
};

#endif