/*

Assignment:     Lab 4 - List Equality
Name:           Jared Bears
Date:           2024-11-18
File:           main.cpp

*/

#include <iostream>
#include "List.h"
#include "Menu.h"
using namespace std;

// Function prototype for testing the List class
void testList();

int main()
{
    // Uncomment to run list tests
    // testList();

    // Create a Menu object and display the menu
    Menu menu;
    menu.displayMenu();

    return 0;
}

// Function to test the List class
void testList(){
    // Create two lists of integers
    List<int> intList1;
    List<int> intList2;

    // Append nodes to the first list
    intList1.appendNode(5);
    intList1.appendNode(10);
    intList1.appendNode(15);
    intList1.appendNode(20);

    // Append nodes to the second list
    intList2.appendNode(5);
    intList2.appendNode(10);
    intList2.appendNode(15);
    intList2.appendNode(20);

    // Test for equality between the two lists
    cout << "Equality Test\n";
    cout << "List 1:\n";
    intList1.printList();
    cout << "List 2:\n";
    intList2.printList();

    if (intList1 == intList2)
    {
        cout << "Equality Test Passed\n";
    } 
    else
    {
        cout << "Equality Test Failed\n";
    }

    // Create a third list of integers
    List<int> intList3;

    // Append nodes to the third list
    intList3.appendNode(5);
    intList3.appendNode(10);
    intList3.appendNode(15);
    intList3.appendNode(25);

    // Test for inequality between the first and third lists
    cout << "Inequality Test\n";
    cout << "List 1:\n";
    intList1.printList();
    cout << "List 3:\n";
    intList3.printList();

    if (intList1 == intList3)
    {
        cout << "Inequality Test Failed\n";
    } 
    else
    {
        cout << "Inequality Test Passed\n";
    }
}