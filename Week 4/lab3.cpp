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

string *generatePatternArray();
void printHeader();
void printPattern(string*);
void horizontalLine();
void patternA(int, string*);
void patternB(int, string*);

const int SIZE = 10;
const int WIDTH = 50;

int main()
{

    string* patternArray = generatePatternArray();

    printHeader();

    printPattern(patternArray);

    return 0;
}

string* generatePatternArray()
{
    string* patternArray = new string[SIZE];
    for (int line = 0; line < SIZE; line++)
    {
        string pattern = "";
        for (int character = 0; character <= line; character++)
        {
            pattern += "+";
        }
        patternArray[line] = pattern;
    }
    return patternArray;
}

void printHeader()
{
    horizontalLine();
    cout << setw(WIDTH/2) << left << "Pattern A" << setw(WIDTH/2) << left << "Pattern B" << endl;
    horizontalLine();
}

void printPattern(string *patternArray)
{
    for (int line = 1; line <= SIZE; line++)
    {
        patternA(line, patternArray);
        patternB(line, patternArray);
    }
}

void horizontalLine()
{
    cout << setw(WIDTH) << "―――――――――――――――――――――――――――――――――――――――――――――――――――――――" << endl;
}

void patternA(int line, string *patternArray)
{
    cout << setw(WIDTH/2) << left << patternArray[line - 1];
}

void patternB(int line, string *patternArray)
{
    cout << setw(WIDTH/2) << left << patternArray[SIZE - line];
    cout << endl;
    if(line == SIZE)
    {
        horizontalLine();
    }
}