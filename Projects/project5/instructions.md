# Project 5 - Stack and Queues

## 1. Static Stack Template
Write your own version of a class template that will create a static stack of any data type.  Demonstrate the class with a driver program.

## Inventory Bin Stack
Design an inventory class that stores the following members:

1. serialNum: An integer that hold's a part's serial number.
2. manufactDate: A member that holds the fate the part was manufactured.
3. lotNum: An integer that holds the part's lot number.

The clas should have appropriate member functions for storing data into, and retrieving data from, these members.

Next, design a stack class that can hold objects of the class described above.  If you wish, you may use the template you designed in Programming Challenge 1 or 2.

Last, design a program that uses the stack class described above.  The program should have a loop that asks the user if he or she wishes to add a part to the inventory, or take a part from inventory.  The loop should repeat until the user is finished.

If the user wishes to add a part to inventory, the program should ask for the serial number, date of manufacture, and lot number.  The data should be stored in an inventory object, and pushed onto the stack.

If the user wishes to take part to inventory, the program should ask for the serial number, date of manufacture, and lot number.  The data should be stored in an inventory object, and pushed onto the stack.

If the user wishes to take a part from inventory, the program should pop the top-most part from the stack and display the contents of its member variables.

When the user finishes the program, it should display the contents of the member values of all the objects that remain on the stack.