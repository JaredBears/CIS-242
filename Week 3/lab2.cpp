/*

Assignment:     Lab 2 - On Pointers
Name:           Jared Bears
Date:           2024-09-08

Instructions:
The following function uses reference values as parameters.  Rewrite the
function so that it uses pointers instead of reference values, and then
demonstrate the function in a complete program.

int doSomething(int &x, int &y)
{
    int temp = x;
    x = y * 10;
    y = temp * 10;
    return x + y;
}

Please ask the user for the values do not hard code the values.

*/

#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Function Prototypes
int intPrompt(string);
int doSomething(int *, int *);

int main()
{
    int num1, num2, res;
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    num1 = intPrompt("Enter the first number: ");
    num2 = intPrompt("Enter the second number: ");

    res = doSomething(ptr1, ptr2);

    cout << "Result: " << res << endl;

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

int doSomething(int *x, int *y)
{
    int temp, res;
    temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    res = *x + *y;
    return res;
}