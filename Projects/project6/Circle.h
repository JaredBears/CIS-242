// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "BasicShape.h"

class Circle : public BasicShape
{
private:
    long centerX;
    long centerY;
    double radius;

public:
    // Constructor
    Circle(long x, long y, double r);

    // Function to get the x coordinate of the center
    long getCenterX() const;

    // Function to get the y coordinate of the center
    long getCenterY() const;

    // Override the calcArea function
    void calcArea() override;
};

#endif