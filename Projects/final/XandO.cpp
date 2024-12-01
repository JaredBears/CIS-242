/*

Assignment:     Final Project - Tic Tac Toe Game
Name:           Jared Bears
Date:           12/11/2024
File:           XandO.cpp

*/

#include "XandO.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

XandO::XandO()
{
    board = vector<vector<char>>(3, vector<char>(3, ' '));
    player1 = 'X';
    player2 = 'O';
    currentPlayer = player1;
    srand(time(0)); // Seed the random number generator
}

void XandO::play()
{
    start = chrono::high_resolution_clock::now(); // Start timing the game

    while (true)
    {
        displayBoard();
        playerMove();
        if (checkWin())
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            auto end = chrono::high_resolution_clock::now(); // End timing the game
            chrono::duration<double> duration = end - start;
            cout << "Game duration: " << duration.count() << " seconds" << endl;
            saveScore(string(1, currentPlayer), duration.count());
            break;
        }
        if (checkDraw())
        {
            displayBoard();
            cout << "The game is a draw!" << endl;
            auto end = chrono::high_resolution_clock::now(); // End timing the game
            chrono::duration<double> duration = end - start;
            cout << "Game duration: " << duration.count() << " seconds" << endl;
            saveScore("Draw", duration.count());
            break;
        }
        switchPlayer();
    }
}

void XandO::playerMove()
{
    string input;
    int row, col;
    while (true)
    {
        cout << "Player " << currentPlayer << ", enter your move (row and column) or 'R' to resign: ";
        cin >> input;

        if (input == "R" || input == "r")
        {
            cout << "Player " << currentPlayer << " has resigned. Game over." << endl;
            auto end = chrono::high_resolution_clock::now(); // End timing the game
            chrono::duration<double> duration = end - start;
            cout << "Game duration: " << duration.count() << " seconds" << endl;
            saveScore(currentPlayer == player1 ? string(1, player2) : string(1, player1), duration.count());
            exit(0);
        }

        try
        {
            row = stoi(input);
            cin >> col;
        }
        catch (invalid_argument &)
        {
            cout << "Invalid input. Please enter a valid move or 'R' to resign." << endl;
            continue;
        }

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;
            break;
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

void XandO::displayBoard()
{
    const int terminalWidth = 80;
    const int boardWidth = 17; // 3 cells * 4 characters (including borders) + 2 borders + 2 spaces for row labels
    const int padding = (terminalWidth - boardWidth) / 2;

    cout << string(padding, ' ') << "    0   1   2" << endl;
    cout << string(padding, ' ') << "  -------------" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << string(padding, ' ') << i << " | ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << string(padding, ' ') << "  -------------" << endl;
    }
}

void XandO::switchPlayer()
{
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

bool XandO::checkWin()
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool XandO::checkDraw()
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

void XandO::saveScore(const string &winner, double duration)
{
    ofstream file("scores.txt", ios::app);
    if (file.is_open())
    {
        auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        tm *ltm = localtime(&now);
        file << "Winner: " << winner << " at "
             << put_time(ltm, "%I:%M:%S %p on %m/%d/%Y")
             << " | Duration: " << duration << " seconds" << endl;
        file.close();
    }
    else
    {
        throw runtime_error("Unable to open file");
    }
}