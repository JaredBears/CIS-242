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
        T value; // Value of the node
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
    cout << "List: [";
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
    // traverse the nodes of the lists, comparing the values
    // Output the elements of the list that are the same
    // if the entire list is the same, output that they are identical
    //  and return true else return false
    bool same = true;
    ListNode *nodePtr1 = head;
    ListNode *nodePtr2 = list.head;
    int count;
    for (count = 0; nodePtr1 != nullptr && nodePtr2 != nullptr; count++)
    {
        if (nodePtr1->value != nodePtr2->value)
        {
            same = false;
            break;
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
    }
    else
    {
        cout << "The lists are not identical.\n";
    }
    return same;
}

#endif