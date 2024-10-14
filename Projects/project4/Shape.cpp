/*

Assignment:     Project 4 - Menu of Shapes
Name:           Jared Bears
Date:           2024-10-06
File:           Shape.cpp

*/

// Implementation file for the Shape class

#include "Shape.h"
#include <iostream>
#include <limits>
using namespace std;

void Shape::triangle(bool inverted)
{

    int size = intPrompt("Enter the size of the triangle: ");
    int start = inverted ? size - 1 : 0;
    int end = inverted ? -1 : size;

    for (int i = start; i != end; inverted ? i-- : i++)
    {
        cout << "     ";
        for (int j = 0; j < size - i - 1; j++)
        {
            cout << "  ";
        }
        // print characters
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void Shape::rectangle()
{
    int height = intPrompt("Enter the height of the rectangle: ");
    int width = intPrompt("Enter the width of the rectangle: ");

    for (int i = 0; i < height; i++)
    {
        cout << "     ";
        for (int j = 0; j < width; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void Shape::bowtie()
{
    int half = intPrompt("Enter the size for each half of the bowtie: ");
    int size = 2 * half + 1;
    bool reverse = false;
    for(int row = 0; row > -1; reverse ? row-- : row++)
    {
        cout << "     ";
        for(int col = 0; col < size; col++)
        {
            if(col <= row || col >= size - row - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
        if(row == half){
            reverse = true;
        }
    }
}

int Shape::intPrompt(string prompt)
{
    int value;
    cout << prompt;
    while (!(cin >> value) || value < 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer greater than zero." << endl;
        cout << prompt;
    }
    return value;
}