/*

Assignment:     Project 1 - Reverse Array
Name:           Jared Bears
Date:           2024-09-04

Instructions:
Write a function that accepts an int array and the array's size as arguments.
The function should create a copy of the array, except that the element values should be reversed
in the copy.  The function should return a pointer to the new array.  Demonstrate the function in a
complete program.

Additional Requirements:
Please ask the user for the 20 values for the array.

*/

#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Function Prototypes

int *arrayPrompt(string, int);
int *reverseArray(int *, int);
void printArray(int *, int);

const int MAX_SIZE = 20;

int main()
{
    int *array = arrayPrompt("Enter 20 values for the array: ", MAX_SIZE);
    int *reversedArray = reverseArray(array, MAX_SIZE);

    cout << "Original Array: ";
    printArray(array, MAX_SIZE);
    cout << "Reversed Array: ";
    printArray(reversedArray, MAX_SIZE);

    delete[] array;
    delete[] reversedArray;

    return 0;
}

int *arrayPrompt(string prompt, int size)
{
    int *array = new int[size];
    cout << prompt;
    for (int i = 0; i < size; i++)
    {
        while (!(cin >> array[i]))
        {
            i = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: ";
        }
    }
    return array;
}

int *reverseArray(int *array, int size)
{
    int *reversedArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        reversedArray[i] = array[size - i - 1];
    }
    return reversedArray;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}