/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           User.cpp

*/

// Implementation file for the User class

#include "User.h"

// Default constructor
User::User()
{
    username = "jared";
    password = "password";
    balance = 500.0;
}

// Constructor with default balance
User::User(string u, string p)
{
    username = u;
    password = p;
    balance = 500.0;
}

// Constructor with specified balance
User::User(string u, string p, double b)
{
    username = u;
    password = p;
    balance = b;
}

// Accessor for username
string User::getUsername()
{
    return username;
}

// Accessor for password
string User::getPassword()
{
    return password;
}

// Accessor for balance
double User::getBalance()
{
    return balance;
}

// Mutator for balance
void User::setBalance(double b)
{
    balance = b;
}