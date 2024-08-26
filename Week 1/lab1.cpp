/*

Assignment:     Lab 1 - On Operations
Name:           Jared Bears
Date:           2024-08-26

Instructions:
Have a user input of 2 numbers. Take those 2 numbers to add, multiply, divide, subtract and mod.
Each operation(+,-,*,/,%) must be a function and include a couple void functions,
call by reference functions. Extra credit a pointer function.
*/

#include <iostream>
using namespace std;

// Function Prototypes
int add(int, int);
int subtract(int, int);
int multiply(int &, int &);
void divide(int &, int &);
void mod(int *, int *);

int main()
{
    int num1, num2;
    int *ptr1 = &num1;
    int *ptr2 = &num2;
    cout << "Enter the first number: ";
    cin >> num1;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> num1;
    }
    cout << "Enter the second number: ";
    cin >> num2;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
        cin >> num2;
    }

    int sum = add(num1, num2);
    int difference = subtract(num1, num2);
    int product = multiply(num1, num2);

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;

    divide(num1, num2);
    mod(ptr1, ptr2);

    return 0;
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

void divide(int &num1, int &num2)
{
    if (num2 == 0)
    {
        cout << "Quotient: Cannot divide by zero." << endl;
        return;
    }
    double quotient = static_cast<double>(num1) / num2;
    cout << "Quotient: " << quotient << endl;
}

void mod(int *num1, int *num2)
{
    if (*num2 == 0)
    {
        cout << "Modulus: Cannot divide by zero." << endl;
        return;
    }
    int modulus = *num1 % *num2;
    cout << "Modulus: " << modulus << endl;
}
