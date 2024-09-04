/*

Assignment:     Project 2 - Array Allocator
Name:           Jared Bears
Date:           2024-09-10

Instructions:
Write a function that dynamically allocates an array of integers.  The function should accept an 
integer argument indicating the number of elements to allocate.  The function should return a
pointer to the array.

*/

#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Function Prototypes
int intPrompt(string);
int *arrayAllocator(int);
void printArray(int *, int);

int main()
{
    int size = intPrompt("Enter the number of elements to allocate: ");
    int *array = arrayAllocator(size);

    cout << "Array allocated with " << size << " elements." << endl;
    printArray(array, size);

    delete[] array;

    return 0;
}

int intPrompt(string prompt)
{
    int num;
    cout << prompt;
    while (!(cin >> num))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return num;
}

int *arrayAllocator(int size)
{
    int *array = new int[size];
    return array;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}