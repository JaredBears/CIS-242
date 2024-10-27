# Project 5 - Stacks and Queues

## Assignment Details
- **Assignment:** Project 5 - Stacks and Queues
- **Name:** Jared Bears
- **Date:** 2024-11-04

## Project Description
This project implements a stack data structure to manage an inventory system. The inventory items are stored in a stack, and the user can add or remove items through a menu interface.

## Files
- `Inventory.h` - Specification file for the `Inventory` class.
- `Inventory.cpp` - Implementation file for the `Inventory` class.
- `Menu.h` - Specification file for the `Menu` class.
- `Menu.cpp` - Implementation file for the `Menu` class.
- `Stack.h` - Specification file for the `Stack` class template.
- `main.cpp` - Main file to run the program.

## How to Compile
To compile the project, you can use the `g++` compiler. Follow the steps below:

1. Open a terminal and navigate to the project directory.
2. Run the following command to compile the project:

    ```sh
    g++ -o inventory.exe main.cpp Inventory.cpp Menu.cpp
    ```

    This command compiles the `main.cpp`, `Inventory.cpp`, and `Menu.cpp` files and links them into an executable named `inventory.exe`


## How to Run
After compiling the project, you can run the executable by using the following command:

```sh
./inventory.exe
```

This will start the program and display the menu interface.

## Menu Options
1. **Add an item to the inventory** - Prompts the user to enter the serial number, manufacturing date, and lot number of the inventory item and adds it to the stack.
2. **Remove an item from the inventory** - Removes the top item from the stack and displays its details.
3. **Exit** - Exits the program and displays the remaining items in the inventory.

## Testing
The `main.cpp` file includes a `testStack` function that tests the `Stack` class with different data types. To run the tests, uncomment the `testStack` function call in the `main` function and comment out the `menu.displayMenu()` function call and recompile the project, ie:
```cpp
int main()
{
    // Re-comment to stop running stack tests
    testStack();

    // Uncomment to run program
    // Menu menu;
    // menu.displayMenu();

    return 0;
}
```
Then, compile and run the project as described above.