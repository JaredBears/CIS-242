# List Equality Program

This program compares three lists of integers to determine if they are identical. The first two lists are filled with user-inputted integers, while the third list is filled with randomly generated integers. The program then compares the three lists and reports whether they are identical or not.

## Features

- **User Input:** Allows the user to input integers into two separate lists.
- **Random List Generation:** Generates a third list with random integers.
- **List Comparison:** Compares the three lists to check if they are identical.
- **Equality Operator Overload:** Uses an overloaded equality operator to compare the lists.
- **Menu Interface:** Provides a menu interface for user interaction.

## Requirements

- **C++ Compiler:** A C++ compiler that supports C++11 or later.
- **Standard Library:** The program uses the C++ Standard Library for input/output operations and random number generation.

## Installation

1. **Clone the repository:**
   ```sh
   git clone <repository-url>
   ```
2. **Navigate to the project directory:**
    ```sh
    cd <project-directory>
    ```
3. **Compile the program:**
    ```sh
    g++ -o ListEquality.exe main.cpp Menu.cpp
    ```

## Usage
1. **Run the compiled program:**
   ```sh
   ./ListEquality.exe
   ```
2. **Follow the on-screen instructions:**
    - Enter 10 integers for the first list when prompted.
    - Enter 10 integers for the second list when prompted.
    - The program will automatically generate 10 random integers for the third list.
    - The program will then compare the three lists and display whether they are identical or not.

## File Structure
```
project-directory/ 
├── List.h # Specification file for the List template class
├── Menu.h # Specification file for the Menu class 
├── Menu.cpp # Implementation file for the Menu class 
├── main.cpp # Main program file 
├── README.md # Project documentation 
└── instructions.md # Instructions for the project
```
