/*

Assignment:     Project 4 - Menu of Shapes
Name:           Jared Bears
Date:           2024-10-06
File:           Shape.h

*/

// Specification file for the Shape class

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

// Shape class declaration

class Shape
{
public:
    void triangle(bool);
    void rectangle();
    void bowtie();
    int intPrompt(string);
};

#endif