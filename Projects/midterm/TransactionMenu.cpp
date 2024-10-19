/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           TransactionMenu.cpp

*/

// Implementation file for the TransactionMenu class

#include "TransactionMenu.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;

// Constructor for the TransactionMenu class
TransactionMenu::TransactionMenu(User *u)
{
    user = u;
}

// Displays the main menu for the TransactionMenu
void TransactionMenu::displayMenu()
{
    int choice;

    do
    {
        cout << "Main Menu" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Interest" << endl;
        cout << "5. Logout" << endl;

        choice = getIntInput("Enter your choice: ", 1, 5);

        switch (choice)
        {
        case 1:
            checkBalance();
            break;
        case 2:
            transact(true);
            break;
        case 3:
            transact(false);
            break;
        case 4:
            checkInterest();
            break;
        case 5:
            cout << "Exiting the program..." << endl;
            break;
        }
    } while (choice != 5);
}

// Checks the balance of the account
void TransactionMenu::checkBalance()
{
    cout << fixed << setprecision(2);
    cout << "Your current balance is: $" << user->getBalance() << endl;
}

// Handles deposit and withdrawal transactions
void TransactionMenu::transact(bool isDeposit)
{
    double startingBalance = user->getBalance();
    double newBalance;
    double amount;
    double maxAmount;
    int modifier;
    string action;
    string pastTense;
    // Set the modifier, action, and past tense based on the transaction type
    // The modifier is used to add or subtract the amount from the balance
    if (isDeposit)
    {
        modifier = 1;
        action = "deposit";
        pastTense = "deposited into";
        maxAmount = 10000;
    }
    else
    {
        modifier = -1;
        action = "withdraw";
        pastTense = "withdrawn from";
        maxAmount = startingBalance;
    }

    amount = getDoubleInput("Enter the amount to " + action + ": $", 0.01, maxAmount);

    amount = truncateDouble(amount, 2) * modifier;

    newBalance = user->getBalance() + amount;

    user->setBalance(newBalance);

    logTransaction(user->getUsername(), startingBalance, amount, newBalance);

    cout << fixed << setprecision(2);

    cout << "$" << abs(amount) << " has been " << pastTense << " your account." << endl;
    cout << "Your new balance is: $" << user->getBalance() << endl;
}

// Checks the interest on the account
void TransactionMenu::checkInterest()
{
    const double RATE = 0.01;
    double startingBalance = user->getBalance();
    double interest = truncateDouble(startingBalance * RATE, 2);
    double newBalance = startingBalance + interest;

    cout << fixed << setprecision(2);
    cout << "Your starting balance is: $" << startingBalance << endl;
    cout << "Your interest rate is: " << RATE * 100 << "%" << endl;
    cout << "Your interest earned is: $" << interest << endl;
    cout << "Your new balance is: $" << newBalance << endl;
    user->setBalance(newBalance);
    logTransaction(user->getUsername(), startingBalance, interest, newBalance);
}

// Logs the transaction to a CSV file
void TransactionMenu::logTransaction(const string &username, double startingBalance, double amount, double endingBalance)
{
    ofstream file("transactions.csv", ios::app);
    if (file.is_open())
    {
        file << username << "," << startingBalance << "," << amount << "," << endingBalance << "," << time(0) << endl;
        file.close();
    }
    else
    {
        cerr << "Unable to open file for logging transactions." << endl;
    }
}