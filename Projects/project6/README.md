# Pure Abstract Base Class Project

This project demonstrates the use of pure abstract base classes in C++ by defining a `BasicShape` class and two derived classes, `Circle` and `Rectangle`. The program calculates and reports the area of these shapes based on user input.

## Classes

### BasicShape

The `BasicShape` class is a pure abstract base class with the following members:

- **Protected Member Variable:**
  - `area` - A double used to hold the area of the shape.

- **Public Member Functions:**
  - `virtual ~BasicShape()` - A virtual destructor.
  - `virtual void calcArea() = 0` - A pure virtual function to calculate the area of the shape.
  - `double getArea() const` - A function to return the value of the `area` member variable.

### Circle

The `Circle` class is derived from the `BasicShape` class and has the following members:

- **Private Member Variables:**
  - `centerX` - A long integer used to hold the x coordinate of the circle's center.
  - `centerY` - A long integer used to hold the y coordinate of the circle's center.
  - `radius` - A double used to hold the circle's radius.

- **Public Member Functions:**
  - `Circle(long x, long y, double r)` - A constructor that accepts values for `centerX`, `centerY`, and `radius`. It calls the overridden `calcArea` function.
  - `long getCenterX() const` - Returns the value of `centerX`.
  - `long getCenterY() const` - Returns the value of `centerY`.
  - `void calcArea() override` - Calculates the area of the circle (`area = pi * radius^2`) and stores the result in the inherited `area` member variable.

### Rectangle

The `Rectangle` class is derived from the `BasicShape` class and has the following members:

- **Private Member Variables:**
  - `width` - A long integer used to hold the width of the rectangle.
  - `length` - A long integer used to hold the length of the rectangle.

- **Public Member Functions:**
  - `Rectangle(long w, long l)` - A constructor that accepts values for `width` and `length`. It calls the overridden `calcArea` function.
  - `long getWidth() const` - Returns the value of `width`.
  - `long getLength() const` - Returns the value of `length`.
  - `void calcArea() override` - Calculates the area of the rectangle (`area = length * width`) and stores the result in the inherited `area` member variable.

## Driver Program

The driver program (`main.cpp`) demonstrates the functionality of the `Circle` and `Rectangle` classes based on user input. It performs the following steps:

1. Prompts the user to enter the center coordinates and radius of a circle.
2. Creates a `Circle` object and displays its area.
3. Prompts the user to enter the width and length of a rectangle.
4. Creates a `Rectangle` object and displays its area.

## File Structure
```
project-directory/ 
├── BasicShape.h # Header file for the BasicShape class 
├── Circle.h # Header file for the Circle class 
├── Circle.cpp # Implementation file for the Circle class 
├── Rectangle.h # Header file for the Rectangle class 
├── Rectangle.cpp # Implementation file for the Rectangle class 
├── main.cpp # Driver program 
└── README.md # Project documentation
```


## Compilation and Execution

To compile and run the program, use the following commands:

```sh
g++ -o ShapeProgram.exe main.cpp Circle.cpp Rectangle.cpp
./ShapeProgram.exe
```

## Conclusion
This project demonstrates the use of pure abstract base classes and inheritance in C++. It shows how to define a base class with pure virtual functions and how to derive classes that implement these functions. The program calculates and reports the area of a circle and a rectangle based on user input.