/*

Assignment:     Lab 1 - On Operations
Name:           Jared Bears
Date:           2024-08-28

Instructions:
Have a user input of 2 numbers. Take those 2 numbers to add, multiply, divide, subtract and mod.
Each operation(+,-,*,/,%) must be a function and include a couple void functions,
call by reference functions. Extra credit a pointer function.
*/

#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Function Prototypes
int intPrompt(string);
int add(int, int);
int subtract(int, int);
int multiply(int &, int &);
void divide(int &, int &, double &);
void mod(int *, int *, int *);

int main()
{
    int num1, num2;
    int sum, difference, product, modulus;
    double quotient;
    int *ptr1 = &num1;
    int *ptr2 = &num2;
    int *modulusPtr = &modulus;

    num1 = intPrompt("Enter the first number: ");
    num2 = intPrompt("Enter the second number: ");

    sum = add(num1, num2);
    difference = subtract(num1, num2);
    product = multiply(num1, num2);
    divide(num1, num2, quotient);
    mod(ptr1, ptr2, modulusPtr);


    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;
    cout << "Modulus: " << modulus << endl;
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

int add(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}

int subtract(int num1, int num2)
{
    int difference = num1 - num2;
    return difference;
}

int multiply(int &num1, int &num2)
{
    int product = num1 * num2;
    return product;
}

void divide(int &num1, int &num2, double &quotient)
{
    if (num2 == 0)
    {
        quotient = 0;
        cout << "Quotient: Cannot divide by zero." << endl;
        return;
    }
    quotient = static_cast<double>(num1) / num2;
}

void mod(int *num1, int *num2, int *modulus)
{
    if (*num2 == 0)
    {
        *modulus = 0;
        cout << "Modulus: Cannot divide by zero." << endl;
        return;
    }
    *modulus = *num1 % *num2;
}