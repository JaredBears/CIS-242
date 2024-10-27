/*

Assignment:     Project 5 - Stacks and Queues
Name:           Jared Bears
Date:           2024-11-04
File:           Inventory.h

*/

// Specification file for the Inventory class

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <ctime>
using namespace std;

class Inventory
{
private:
    int serialNumber;
    string manufactDate;
    int lotNum;

public:
    // Constructors
    Inventory();
    Inventory(int, string, int);

    // Destructor
    ~Inventory();

    // Setters
    void setSerialNumber(int);
    void setManufactDate(string);
    void setLotNum(int);

    // Getters
    int getSerialNumber() const;
    string getManufactDate() const;
    int getLotNum() const;

    // Equality check
    bool operator==(const Inventory &) const;
};

#endif