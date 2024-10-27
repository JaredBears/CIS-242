/*

Assignment:     Project 5 - Stacks and Queues
Name:           Jared Bears
Date:           2024-11-04
File:           Stack.h

*/

// Specification file for the Stack class

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    // Structure for the stack nodes
    struct StackNode
    {
        T value;         // Value in the node
        StackNode *next; // Pointer to the next node
    };

    StackNode *top; // Pointer to the stack top

public:
    // Constructor
    Stack();

    // Destructor
    ~Stack();

    // Stack operations
    void push(T);
    T pop();
    bool isEmpty();
};

// Constructor
template <class T>
Stack<T>::Stack()
{
    top = nullptr;
}

// Destructor
template <class T>
Stack<T>::~Stack()
{
    StackNode *nodePtr = top;
    // Traverse the stack deleting each node
    while (nodePtr != nullptr)
    {
        StackNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

// Push value onto the stack
template <class T>
void Stack<T>::push(T value)
{
    StackNode *newNode = new StackNode;
    newNode->value = value;
    newNode->next = top;
    top = newNode;
}

// Pop top node from the stack and returns the contents
template <class T>
T Stack<T>::pop()
{
    T value;
    StackNode *temp = nullptr;
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else
    {
        value = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
    return value;
}

// Determine if the stack is empty
template <class T>
bool Stack<T>::isEmpty()
{
    return top == nullptr;
}

#endif