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
    int serialNumber;    // Serial number of the inventory item
    string manufactDate; // Manufacturing date of the inventory item
    int lotNum;          // Lot number of the inventory item

public:
    // Constructors
    Inventory();                 // Default constructor
    Inventory(int, string, int); // Parameterized constructor

    // Destructor
    ~Inventory();

    // Setters
    void setSerialNumber(int);    // Set the serial number
    void setManufactDate(string); // Set the manufacturing date
    void setLotNum(int);          // Set the lot number

    // Getters
    int getSerialNumber() const;    // Get the serial number
    string getManufactDate() const; // Get the manufacturing date
    int getLotNum() const;          // Get the lot number

    // Equality check
    bool operator==(const Inventory &) const; // Check if two inventory items are equal

    // Convert inventory item to string
    string toString() const;
};

#endif