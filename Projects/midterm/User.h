/*

Assignment:     Midterm Project - ATM
Name:           Jared Bears
Date:           2024-10-27
File:           User.h

*/

// Specification file for the User class

#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// User class declaration
// Manages user information including username, password, and balance
class User
{
private:
    string username;
    string password;
    double balance;

public:
    // Default constructor
    User();

    // Constructor with default balance
    User(string, string);

    // Constructor with specified balance
    User(string, string, double);

    // Accessor for username
    string getUsername();

    // Accessor for password
    string getPassword();

    // Accessor for balance
    double getBalance();

    // Mutator for balance
    void setBalance(double);
};

#endif