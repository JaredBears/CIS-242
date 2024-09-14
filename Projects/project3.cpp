/*

Assignment:     Project 3 - Lottery Application
Name:           Jared Bears
Date:           2024-09-25

Instructions:
Write a program that simulates a lottery. The program should have an array of 10
integers named lottery and should generate a random number in the range of 0
through 9 for each element in the array. The user should enter ten digits, which should
be stored in an integer array named user. The program is to compare the corresponding
elements in the two arrays and keep a count of the digits that match. For example,
the following shows the lottery array and the user array with sample numbers stored
in each. There are two matching digits (elements 2 and 4).

lottery array:
7 4 9 1 3 5 6 7 9 9

user array:
4 2 9 7 3 7 8 9 6 6

The program should display the random numbers stored in the lottery array and the
number of matching digits.

If all of the digits match, display a message proclaiming the user as a grand prize winner.
Also output the values that are the same as well as the elements.
Also output how many numbers were the same.
You are required to use a function for the user array and the lottery array.
Please reach out to me if you have any questions

*/

#include <iostream>
using namespace std;

// prototypes

void pickNumbers(int[]);
void verifyNumbers(int[]);
void drawLottery(int[]);
void determineWinner(int[], int[]);
void printArray(int[], int);
void displayMatches(int[]);

const int LOTTERY_SIZE = 10;

int main()
{
    int user[LOTTERY_SIZE];
    int lottery[LOTTERY_SIZE];

    pickNumbers(user);
    drawLottery(lottery);
    determineWinner(user, lottery);

    return 0;
}

void pickNumbers(int user[])
{
    cout << "Enter " << LOTTERY_SIZE << " numbers between 0 and 9: " << endl;
    for (int i = 0; i < LOTTERY_SIZE; i++)
    {
        while (!(cin >> user[i]) || user[i] < 0 || user[i] > 9)
        {
            cout << "Invalid input. Enter a digit between 0 and 9: " << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    verifyNumbers(user);
}

void verifyNumbers(int user[])
{
    char response;
    cout << "Your numbers are: ";
    printArray(user, LOTTERY_SIZE);
    cout << "Are you ok with these numbers? (y/n): ";
    while (!(cin >> response) || (response != 'y' && response != 'n'))
    {
        cout << "Invalid input. Enter 'y' or 'n': ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    if (response == 'n')
    {
        pickNumbers(user);
    }
}

void drawLottery(int lottery[])
{
    srand(time(0));
    for (int i = 0; i < LOTTERY_SIZE; i++)
    {
        lottery[i] = rand() % 10;
    }
    cout << "Lottery numbers have been drawn:" << endl;
    printArray(lottery, LOTTERY_SIZE);
}

void determineWinner(int user[], int lottery[])
{
    int numberMatched = 0;
    int matchedNumbers[LOTTERY_SIZE];

    for (int i = 0; i < LOTTERY_SIZE; i++)
    {
        if (user[i] == lottery[i])
        {
            matchedNumbers[i] = user[i];
            numberMatched++;
        }
        else
        {
            matchedNumbers[i] = -1;
        }
    }

    cout << "You matched " << numberMatched << " numbers." << endl;
    if (numberMatched == LOTTERY_SIZE)
    {
        cout << "Congratulations! You are a grand prize winner!" << endl;
    }
    else if (numberMatched > 0)
    {
        cout << "You matched the following numbers: " << endl;
        displayMatches(matchedNumbers);
    }
    else
    {
        cout << "No matches.  Better luck next time!" << endl;
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void displayMatches(int matchedNumbers[])
{
    for (int i = 0; i < LOTTERY_SIZE; i++)
    {
        if (matchedNumbers[i] != -1)
        {
            cout << "Element " << i << ": " << matchedNumbers[i] << endl;
        }
    }
}