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
using namespace std;

// Constructor for the TransactionMenu class
TransactionMenu::TransactionMenu()
{
    balance = 500;
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
    cout << "Your current balance is: $" << balance << endl;
}

// Deposits money into the account
void TransactionMenu::transact(bool isDeposit)
{
    double amount;
    string action = isDeposit ? "deposit" : "withdraw";
    string pastTense = isDeposit ? "deposited to" : "withdrawn from";

    amount = getDoubleInput("Enter the amount to " + action + ": $", 0.01, 10000);

    amount = truncateDouble(amount, 2);

    balance += isDeposit ? amount : -amount;

    cout << fixed << setprecision(2);

    cout << "$" << amount << " has been " << pastTense << " your account." << endl;
    cout << "Your new balance is: $" << balance << endl;
}

// Checks the interest on the account
void TransactionMenu::checkInterest()
{
    const double RATE = 0.01;
    double interest = balance * RATE;

    cout << fixed << setprecision(2);
    cout << "Your starting balance is: $" << balance << endl;
    cout << "Your interest rate is: " << RATE * 100 << "%" << endl;
    cout << "Your interest earned is: $" << interest << endl;
    cout << "Your new balance is: $" << balance + interest << endl;
    balance += interest;
}