/*

Assignment:     Lab 4 - List Equality
Name:           Jared Bears
Date:           2024-11-18
File:           Menu.cpp

*/

// Implementation file for the Menu class

#include "Menu.h"
#include <iostream>
#include <limits>
using namespace std;

const int SIZE = 10;

// Display the menu and handle user input
void Menu::displayMenu()
{
    while (true)
    {
        // Display the program description
        cout << "Welcome to the List Equality program!" << endl;
        cout << "This program will compare three lists of integers." << endl;
        cout << "The first two lists will be filled with user-inputed integers." << endl;
        cout << "The third list will be filled with random integers." << endl;
        cout << "The program will then compare the three lists." << endl;
        cout << endl;

        // Fill the first list with user-inputed integers
        cout << "Please enter " << SIZE << " integers for the first list." << endl;
        fillList(list1, SIZE);
        cout << endl;

        // Fill the second list with user-inputed integers
        cout << "Please enter " << SIZE << " integers for the second list." << endl;
        fillList(list2, SIZE);
        cout << endl;

        // Fill the third list with random integers
        cout << "Filling the third list with random integers." << endl;
        // fillRandomList(list3, SIZE);
        fillList(list3, SIZE);
        cout << endl;

        // Compare the three lists
        cout << "Comparing the three lists." << endl;
        compareLists();
        cout << endl;

        // Ask the user if they want to run the program again
        cout << "Would you like to run the program again? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y')
        {
            break;
        }
    }
}

// Fill a list with user-inputed integers
void Menu::fillList(List<int> &list, int size)
{
    int num;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter an integer: (integer " << i + 1 << " of " << size << "): ";
        while (!(cin >> num))
        {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        list.appendNode(num);
    }
}

// Fill a list with random integers
void Menu::fillRandomList(List<int> &list, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        list.appendNode(rand() % 201 - 100);
    }
}

// Compare the three lists
void Menu::compareLists()
{
    bool check1and2;
    bool check1and3;
    bool check2and3;

    // Compare list1 and list2
    cout << "Comparing list1 and list2." << endl;
    cout << "List1: ";
    list1.printList();
    cout << "List2: ";
    list2.printList();
    check1and2 = list1.compareLists(list2);

    // Compare list1 and list3
    cout << "Comparing list1 and list3." << endl;
    cout << "List1: ";
    list1.printList();
    cout << "List3: ";
    list3.printList();
    check1and3 = list1.compareLists(list3);

    if (check1and2 && check1and3)
    {
        cout << "The three lists are identical." << endl;
        return;
    }

    // Compare list2 and list3
    cout << "Comparing list2 and list3." << endl;
    cout << "List2: ";
    list2.printList();
    cout << "List3: ";
    list3.printList();
    check2and3 = list2.compareLists(list3);
}