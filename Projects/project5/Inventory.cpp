/*

Assignment:     Project 5 - Stacks and Queues
Name:           Jared Bears
Date:           2024-11-04
File:           Inventory.cpp

*/

// Implementation file for the Inventory class

#include "Inventory.h"
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

// Default constructor
Inventory::Inventory()
{
    serialNumber = 0;
    manufactDate = "";
    lotNum = 0;
}

// Parameterized constructor
Inventory::Inventory(int serial, string date, int lot)
{
    serialNumber = serial;
    manufactDate = date;
    lotNum = lot;
}

// Destructor
Inventory::~Inventory()
{
    // Destructor
}

// Set the serial number
void Inventory::setSerialNumber(int serial)
{
    serialNumber = serial;
}

// Set the manufacturing date
void Inventory::setManufactDate(string date)
{
    manufactDate = date;
}

// Set the lot number
void Inventory::setLotNum(int lot)
{
    lotNum = lot;
}

// Get the serial number
int Inventory::getSerialNumber() const
{
    return serialNumber;
}

// Get the manufacturing date
string Inventory::getManufactDate() const
{
    return manufactDate;
}

// Get the lot number
int Inventory::getLotNum() const
{
    return lotNum;
}

// Equality check operator
bool Inventory::operator==(const Inventory &right) const
{
    if (serialNumber == right.serialNumber && manufactDate == right.manufactDate && lotNum == right.lotNum)
    {
        return true;
    }
    return false;
}

// Convert the inventory item to a string representation
string Inventory::toString() const
{
    string str = "Serial Number: " + to_string(serialNumber) + "\nManufacture Date: " + manufactDate + "\nLot Number: " + to_string(lotNum);
    return str;
}