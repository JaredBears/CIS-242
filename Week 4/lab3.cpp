/*

Assignment:     Lab 3 - Pattern Displays
Name:           Jared Bears
Date:           2024-09-16

Instructions:
Write a program that uses a loop to display Pattern A below, followed by another loop
to display Pattern B.

Your output must look exactly how you see it below. Your required to use functions and loops.

Extra Credit items:
Place Pattern A in its own function and Pattern B in its own function.
Use pointers.

[lab3.png]

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void printHeader();
void printPattern();
void horizontalLine();
void patternA(int);
void patternB(int);

int main()
{

    printHeader();

    printPattern();

    return 0;
}

void printHeader()
{
    horizontalLine();
    cout << setw(25) << left << "Pattern A" << setw(25) << left << "Pattern B" << endl;
    horizontalLine();
}

void printPattern()
{
    for (int line = 1; line <= 10; line++)
    {
        patternA(line);
        patternB(line);
    }
}

void horizontalLine()
{
    cout << setw(50) << "―――――――――――――――――――――――――――――――――――――――――――――――――――――――" << endl;
}

void patternA(int line)
{
    string pattern = "";
    for (int character = 1; character <= line; character++)
    {
        pattern += "+";
    }
    cout << setw(25) << left << pattern;
}

void patternB(int line)
{
    string pattern = "";
    for (int character = 10; character >= line; character--)
    {
        pattern += "+";
    }

    cout << setw(25) << left << pattern << endl;
    if(line == 10)
    {
        horizontalLine();
    }
}