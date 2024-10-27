/*

Assignment:     Project 5 - Stacks and Queues
Name:           Jared Bears
Date:           2024-11-04
File:           main.cpp

*/

#include <iostream>
#include "Stack.h"
#include "Inventory.h"
#include "Menu.h"
using namespace std;

// Function to test the Stack class
void testStack();

int main()
{
    // Uncomment to run stack tests
    // testStack();

    Menu menu;
    menu.displayMenu();

    return 0;
}

// Function to test the Stack class with different data types
void testStack()
{
    Stack<int> intStack;
    Stack<double> doubleStack;
    Stack<char> charStack;
    Stack<Inventory> inventoryStack;

    // Push values onto the stacks
    intStack.push(5);
    intStack.push(10);
    intStack.push(15);
    intStack.push(20);

    doubleStack.push(5.5);
    doubleStack.push(10.5);
    doubleStack.push(15.5);
    doubleStack.push(20.5);

    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    charStack.push('D');

    Inventory inventory1(1, "2024-11-04", 1);
    Inventory inventory2(2, "2024-11-04", 2);
    Inventory inventory3(3, "2024-11-04", 3);
    Inventory inventory4(4, "2024-11-04", 4);

    inventoryStack.push(inventory1);
    inventoryStack.push(inventory2);
    inventoryStack.push(inventory3);
    inventoryStack.push(inventory4);

    // Pop values from the stacks and test
    bool test1 = intStack.pop() == 20;
    bool test2 = intStack.pop() == 15;
    bool test3 = intStack.pop() == 10;
    bool test4 = intStack.pop() == 5;

    bool test5 = doubleStack.pop() == 20.5;
    bool test6 = doubleStack.pop() == 15.5;
    bool test7 = doubleStack.pop() == 10.5;
    bool test8 = doubleStack.pop() == 5.5;

    bool test9 = charStack.pop() == 'D';
    bool test10 = charStack.pop() == 'C';
    bool test11 = charStack.pop() == 'B';
    bool test12 = charStack.pop() == 'A';

    bool test13 = inventoryStack.pop() == inventory4;
    bool test14 = inventoryStack.pop() == inventory3;
    bool test15 = inventoryStack.pop() == inventory2;
    bool test16 = inventoryStack.pop() == inventory1;

    // Output test results
    cout << "intStack tests: " << ((test1 && test2 && test3 && test4) ? "PASSED" : "FAILED") << endl;
    cout << "doubleStack tests: " << ((test5 && test6 && test7 && test8) ? "PASSED" : "FAILED") << endl;
    cout << "charStack tests: " << ((test9 && test10 && test11 && test12) ? "PASSED" : "FAILED") << endl;
    cout << "inventoryStack tests: " << ((test13 && test14 && test15 && test16) ? "PASSED" : "FAILED") << endl;

    cout << "All tests completed." << endl;
}