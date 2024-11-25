/*

Assignment:     Project 6 - Virtual Classes
Name:           Jared Bears
Date:           2024-11-25
File:           BasicShape.h

*/

#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class BasicShape
{
protected:
    double area; // Protected member variable to hold the area

public:
    // Virtual destructor
    virtual ~BasicShape() {}

    // Pure virtual function to calculate the area
    virtual void calcArea() = 0;

    // Function to get the area
    double getArea() const
    {
        return area;
    }
};

#endif