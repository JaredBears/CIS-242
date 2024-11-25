// Rectangle.cpp
#include "Rectangle.h"

// Constructor
Rectangle::Rectangle(long w, long l) : width(w), length(l)
{
    calcArea();
}

// Function to get the width
long Rectangle::getWidth() const
{
    return width;
}

// Function to get the length
long Rectangle::getLength() const
{
    return length;
}

// Override the calcArea function
void Rectangle::calcArea()
{
    area = width * length;
}