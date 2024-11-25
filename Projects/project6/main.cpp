// main.cpp
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
    // Get user input for Circle
    long centerX, centerY;
    double radius;
    cout << "Enter the center x coordinate of the circle: ";
    cin >> centerX;
    cout << "Enter the center y coordinate of the circle: ";
    cin >> centerY;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    // Create Circle object
    Circle circle(centerX, centerY, radius);
    cout << "The area of the circle is: " << circle.getArea() << endl;

    // Get user input for Rectangle
    long width, length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;

    // Create Rectangle object
    Rectangle rectangle(width, length);
    cout << "The area of the rectangle is: " << rectangle.getArea() << endl;

    return 0;
}