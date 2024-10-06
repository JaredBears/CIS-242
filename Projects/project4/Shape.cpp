/*

Assignment:     Project 4 - Menu of Shapes
Name:           Jared Bears
Date:           2024-10-06
File:           Shape.cpp

*/

// Implementation file for the Shape class

#include "Shape.h"
#include <iostream>
#include <limits>
using namespace std;

void Shape::triangle(bool inverted)
{

    int size = intPrompt("Enter the size of the triangle: ");
    int start = inverted ? size - 1 : 0;
    int end = inverted ? -1 : size;

    for (int i = start; i != end; inverted ? i-- : i++)
    {
        cout << "     ";
        for (int j = 0; j < size - i - 1; j++)
        {
            cout << " ";
        }
        // print characters
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Shape::rectangle()
{
    int height = intPrompt("Enter the height of the rectangle: ");
    int width = intPrompt("Enter the width of the rectangle: ");

    for (int i = 0; i < height; i++)
    {
        cout << "     ";
        for (int j = 0; j < width; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Shape::bowtie()
{
    cout << "        :JJJ?????~:.                                     .:^!7???J?J^" << endl;
    cout << "       ^#^    ..:~7JYJ7^.                            :!JYJ7~^..    :B7" << endl;
    cout << "       #!            .^7YY7:                     :!JY?^.            :&." << endl;
    cout << "      ~#                 .^J5J^               :?5Y~.                 GJ" << endl;
    cout << "      Y5                     :?5J!5YJYYYJY57?5J^                     7G" << endl;
    cout << "      #7                        ^&!       :&!                        ^&." << endl;
    cout << "      &~                         B~       .#.                        .&." << endl;
    cout << "     .&^                         B~       .#.                        .&:" << endl;
    cout << "     .&^                         B~       .#.                        .&:" << endl;
    cout << "     .&^                         B~       .#.                        .&:" << endl;
    cout << "      &~                         B~       .#.                        .&." << endl;
    cout << "      B?                       .!&7       ^&?.                       ^&." << endl;
    cout << "      JP                    .~Y5!^JYJJJJJJY~~Y5!.                    ?G" << endl;
    cout << "      ^#                 :!55!.               .~Y57:                 G?" << endl;
    cout << "       B?           .:!JY?~.                     .^?YY7^.           ^#." << endl;
    cout << "       :#7....:^~7JYJ7^.                             .^7JYJ?!^:....~#~" << endl;
    cout << "        .!7?77!~^:.                                       .:^~!77?77." << endl;
}

int Shape::intPrompt(string prompt)
{
    int value;
    cout << prompt;
    while (!(cin >> value) || value < 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer greater than zero." << endl;
        cout << prompt;
    }
    return value;
}