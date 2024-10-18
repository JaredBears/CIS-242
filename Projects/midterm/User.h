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

class User
{
private:
    string username;
    string password;
    double balance;

public:
    User();
    User(string, string);
    User(string, string, double);
    string getPassword();
    double getBalance();
    void setBalance(double);
};

#endif