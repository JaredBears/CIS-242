/*

Assignment:     Lab 4 - List Equality
Name:           Jared Bears
Date:           2024-11-18
File:           main.cpp

*/

#include <iostream>
#include "List.h"
using namespace std;

void testList();

int main()
{
    // Uncomment to run list tests
    // testList();

    return 0;
}

void testList(){
    List<int> intList1;
    List<int> intList2;

    intList1.appendNode(5);
    intList1.appendNode(10);
    intList1.appendNode(15);
    intList1.appendNode(20);

    intList2.appendNode(5);
    intList2.appendNode(10);
    intList2.appendNode(15);
    intList2.appendNode(20);

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

    List<int> intList3;

    intList3.appendNode(5);
    intList3.appendNode(10);
    intList3.appendNode(15);
    intList3.appendNode(25);

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