/*

Assignment:     Lab 4 - List Equality
Name:           Jared Bears
Date:           2024-11-18
File:           List.h

*/

// Specification file for the List template class

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class T>
class List
{
private:
    // Structure for the list nodes
    struct ListNode
    {
        T value;        // Value of the node
        ListNode *next; // Pointer to the next node
        ListNode(T value1, ListNode *next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };

    ListNode *head; // Pointer to the head of the list

public:
    // Constructor
    List();

    // Destructor
    ~List();

    // Append a node to the end of the list
    void appendNode(T);

    // Print the list
    void printList();

    // compare two lists
    bool compareLists(List<T> &);

    // Find the highest value in the list
    T findHighest();

    // Find the lowest value in the list
    T findLowest();
};

// Constructor
template <class T>
List<T>::List()
{
    head = nullptr;
}

// Destructor
template <class T>
List<T>::~List()
{
    ListNode *nodePtr = head;
    while (nodePtr != nullptr)
    {
        ListNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

// Append a node to the end of the list
template <class T>
void List<T>::appendNode(T newValue)
{
    ListNode *newNode = new ListNode(newValue);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        ListNode *nodePtr = head;
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

// Print the list
template <class T>
void List<T>::printList()
{
    ListNode *nodePtr = head;
    cout << "[";
    while (nodePtr != nullptr)
    {
        cout << nodePtr->value;
        nodePtr = nodePtr->next;
        if (nodePtr != nullptr)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

// compare two lists
template <class T>
bool List<T>::compareLists(List<T> &list)
{
    bool same = true;
    ListNode *nodePtr1 = head;
    ListNode *nodePtr2 = list.head;
    int numsame = 0;
    for (int count = 0; nodePtr1 != nullptr && nodePtr2 != nullptr; count++)
    {

        if (nodePtr1->value != nodePtr2->value)
        {
            same = false;
        }
        else
        {
            cout << "Element " << count << " is the same: " << nodePtr1->value << endl;
            numsame++;
        }
        nodePtr1 = nodePtr1->next;
        nodePtr2 = nodePtr2->next;
    }
    if (nodePtr1 != nullptr || nodePtr2 != nullptr)
    {
        same = false;
    }
    if (same)
    {
        cout << "The lists are identical.\n";
        cout << "All elements are the same.\n";
    }
    else
    {
        cout << "The lists are not identical.\n";
        cout << "Number of elements that are the same: " << numsame << endl;
    }
    return same;
}

// Find the highest value in the list
template <class T>
T List<T>::findHighest()
{
    if (head == nullptr)
    {
        throw runtime_error("List is empty");
    }
    ListNode *nodePtr = head;
    T highest = nodePtr->value;
    while (nodePtr != nullptr)
    {
        if (nodePtr->value > highest)
        {
            highest = nodePtr->value;
        }
        nodePtr = nodePtr->next;
    }
    return highest;
}

// Find the lowest value in the list
template <class T>
T List<T>::findLowest()
{
    if (head == nullptr)
    {
        throw runtime_error("List is empty");
    }
    ListNode *nodePtr = head;
    T lowest = nodePtr->value;
    while (nodePtr != nullptr)
    {
        if (nodePtr->value < lowest)
        {
            lowest = nodePtr->value;
        }
        nodePtr = nodePtr->next;
    }
    return lowest;
}

#endif