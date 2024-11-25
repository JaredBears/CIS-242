/*

Assignment:     Project 6 - Virtual Classes
Name:           Jared Bears
Date:           2024-11-25
File:           Rectangle.h

*/


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
    long width;
    long length;

public:
    // Constructor
    Rectangle(long w, long l);

    // Function to get the width
    long getWidth() const;

    // Function to get the length
    long getLength() const;

    // Override the calcArea function
    void calcArea() override;
};

#endif