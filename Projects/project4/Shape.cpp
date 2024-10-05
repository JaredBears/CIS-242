/*

Assignment:     Project 4 - Menu of Shapes
Name:           Jared Bears
Date:           2024-10-06
File:           Shape.cpp

*/

// Implementation file for the Shape class

#include "Shape.h"
#include <iostream>
using namespace std;

void Shape::triangle(int size, bool inverted)
{
    if (inverted)
    {
        cout << "Inverted Triangle" << endl;
    }
    else
    {
        cout << "Triangle" << endl;
    }
}

void Shape::square(int size)
{
    cout << "Square" << endl;
}

void Shape::bowtie()
{
    cout << "Bowtie" << endl;
}