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

// Constructor
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

// Setters
void Inventory::setSerialNumber(int serial)
{
    serialNumber = serial;
}

void Inventory::setManufactDate(string date)
{
    manufactDate = date;
}

void Inventory::setLotNum(int lot)
{
    lotNum = lot;
}

// Getters

int Inventory::getSerialNumber() const
{
    return serialNumber;
}

string Inventory::getManufactDate() const
{
    return manufactDate;
}

int Inventory::getLotNum() const
{
    return lotNum;
}

// Equality check
bool Inventory::operator==(const Inventory &right) const
{
    if (serialNumber == right.serialNumber && manufactDate == right.manufactDate && lotNum == right.lotNum)
    {
        return true;
    }
    return false;
}