// Circle.cpp
#include "Circle.h"
#include <cmath>

// Constructor
Circle::Circle(long x, long y, double r) : centerX(x), centerY(y), radius(r)
{
    calcArea();
}

// Function to get the x coordinate of the center
long Circle::getCenterX() const
{
    return centerX;
}

// Function to get the y coordinate of the center
long Circle::getCenterY() const
{
    return centerY;
}

// Override the calcArea function
void Circle::calcArea()
{
    area = M_PI * radius * radius;
}