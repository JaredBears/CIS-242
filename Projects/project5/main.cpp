/*

Assignment:     Project 5 - Stacks and Queues
Name:           Jared Bears
Date:           2024-11-04
File:           main.cpp

*/

#include <iostream>
#include "Stack.h"
using namespace std;

void testStack();

int main()
{
    testStack();
    return 0;
}

// test stacks
void testStack()
{
    Stack<int> intStack;
    Stack<double> doubleStack;
    Stack<char> charStack;

    intStack.push(5);
    intStack.push(10);
    intStack.push(15);
    intStack.push(20);

    doubleStack.push(5.5);
    doubleStack.push(10.5);
    doubleStack.push(15.5);
    doubleStack.push(20.5);

    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    charStack.push('D');

    bool test1 = intStack.pop() == 20;
    bool test2 = intStack.pop() == 15;
    bool test3 = intStack.pop() == 10;
    bool test4 = intStack.pop() == 5;

    bool test5 = doubleStack.pop() == 20.5;
    bool test6 = doubleStack.pop() == 15.5;
    bool test7 = doubleStack.pop() == 10.5;
    bool test8 = doubleStack.pop() == 5.5;

    bool test9 = charStack.pop() == 'D';
    bool test10 = charStack.pop() == 'C';
    bool test11 = charStack.pop() == 'B';
    bool test12 = charStack.pop() == 'A';

    cout << "intStack tests: " << ((test1 && test2 && test3 && test4) ? "PASSED" : "FAILED") << endl;
    cout << "doubleStack tests: " << ((test5 && test6 && test7 && test8) ? "PASSED" : "FAILED") << endl;
    cout << "charStack tests: " << ((test9 && test10 && test11 && test12) ? "PASSED" : "FAILED") << endl;
}