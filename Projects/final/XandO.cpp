/*

Assignment:     Final Project - Tic Tac Toe Game
Name:           Jared Bears
Date:           12/11/2024
File:           XandO.cpp

*/

#include "XandO.h"
using namespace std;

XandO::XandO()
{
    board = vector<vector<char>>(3, vector<char>(3, ' '));
    player1 = 'X';
    player2 = 'O';
    currentPlayer = player1;
}

void XandO::play()
{
    while (true)
    {
        displayBoard();
        playerMove();
        if (checkWin())
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            saveScore(string(1, currentPlayer));
            break;
        }
        if (checkDraw())
        {
            displayBoard();
            cout << "The game is a draw!" << endl;
            saveScore("Draw");
            break;
        }
        switchPlayer();
    }
}

void XandO::playerMove()
{
    int row, col;
    while (true)
    {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
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
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
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

void XandO::saveScore(const string &winner)
{
    ofstream file("scores.txt", ios::app);
    if (file.is_open())
    {
        file << "Winner: " << winner << " at " << time(nullptr) << endl;
        file.close();
    }
    else
    {
        throw runtime_error("Unable to open file");
    }
}