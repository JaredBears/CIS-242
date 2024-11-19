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
#include <ctime>
#include <cstdlib>
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
        // fillList(list3, SIZE);
        fillRandomList(list3, SIZE);
        cout << endl;

        // print the lists
        cout << "List1: ";
        list1.printList();
        cout << "List2: ";
        list2.printList();
        cout << "List3: ";
        list3.printList();

        // Find the highest value in the lists
        cout << "The highest value in list1 is: " << list1.findHighest() << endl;
        cout << "The highest value in list2 is: " << list2.findHighest() << endl;
        cout << "The highest value in list3 is: " << list3.findHighest() << endl;

        // Find the lowest value in the lists
        cout << "The lowest value in list1 is: " << list1.findLowest() << endl;
        cout << "The lowest value in list2 is: " << list2.findLowest() << endl;
        cout << "The lowest value in list3 is: " << list3.findLowest() << endl;

        // Compare the three lists
        cout << endl;
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

    cout << endl;

    // Compare list1 and list2
    cout << "Comparing list1 and list2." << endl;
    check1and2 = list1.compareLists(list2);
    cout << endl;

    // Compare list1 and list3
    cout << "Comparing list1 and list3." << endl;
    check1and3 = list1.compareLists(list3);
    cout << endl;

    if (check1and2 && check1and3)
    {
        cout << "Grand Prize Winner!" << endl;
        cout << "The three lists are identical." << endl;
        return;
    }

    // Compare list2 and list3
    cout << "Comparing list2 and list3." << endl;
    check2and3 = list2.compareLists(list3);
    cout << endl;
}