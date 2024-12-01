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
#include <algorithm>
using namespace std;

XandO::XandO()
{
    board = vector<vector<char>>(3, vector<char>(3, ' '));
    player1 = 'X';
    player2 = 'O';
    currentPlayer = player1;
    srand(time(0)); // Seed the random number generator
}

void XandO::play(bool twoPlayerMode)
{
    this->twoPlayerMode = twoPlayerMode;
    humanIsPlayer1 = rand() % 2 == 0; // Randomly assign human to player 1 or player 2
    currentPlayer = player1;

    start = chrono::high_resolution_clock::now(); // Start timing the game

    while (true)
    {
        displayBoard();
        if (twoPlayerMode || (humanIsPlayer1 && currentPlayer == player1) || (!humanIsPlayer1 && currentPlayer == player2))
        {
            playerMove();
        }
        else
        {
            computerMove();
        }

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

void XandO::computerMove()
{
    // First move is random
    if (count(board.begin(), board.end(), vector<char>{' ', ' ', ' '}) == 3)
    {
        makeMove(rand() % 3, rand() % 3);
        return;
    }

    // Block human player from winning
    char humanPlayer = humanIsPlayer1 ? player1 : player2;
    for (int i = 0; i < 3; ++i)
    {
        // Check rows
        if (board[i][0] == humanPlayer && board[i][1] == humanPlayer && board[i][2] == ' ')
        {
            makeMove(i, 2);
            return;
        }
        if (board[i][0] == humanPlayer && board[i][2] == humanPlayer && board[i][1] == ' ')
        {
            makeMove(i, 1);
            return;
        }
        if (board[i][1] == humanPlayer && board[i][2] == humanPlayer && board[i][0] == ' ')
        {
            makeMove(i, 0);
            return;
        }

        // Check columns
        if (board[0][i] == humanPlayer && board[1][i] == humanPlayer && board[2][i] == ' ')
        {
            makeMove(2, i);
            return;
        }
        if (board[0][i] == humanPlayer && board[2][i] == humanPlayer && board[1][i] == ' ')
        {
            makeMove(1, i);
            return;
        }
        if (board[1][i] == humanPlayer && board[2][i] == humanPlayer && board[0][i] == ' ')
        {
            makeMove(0, i);
            return;
        }
    }

    // Check diagonals
    if (board[0][0] == humanPlayer && board[1][1] == humanPlayer && board[2][2] == ' ')
    {
        makeMove(2, 2);
        return;
    }
    if (board[0][0] == humanPlayer && board[2][2] == humanPlayer && board[1][1] == ' ')
    {
        makeMove(1, 1);
        return;
    }
    if (board[1][1] == humanPlayer && board[2][2] == humanPlayer && board[0][0] == ' ')
    {
        makeMove(0, 0);
        return;
    }
    if (board[0][2] == humanPlayer && board[1][1] == humanPlayer && board[2][0] == ' ')
    {
        makeMove(2, 0);
        return;
    }
    if (board[0][2] == humanPlayer && board[2][0] == humanPlayer && board[1][1] == ' ')
    {
        makeMove(1, 1);
        return;
    }
    if (board[1][1] == humanPlayer && board[2][0] == humanPlayer && board[0][2] == ' ')
    {
        makeMove(0, 2);
        return;
    }

    // If no blocking move is found, make a random move
    int row, col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    makeMove(row, col);
}

void XandO::makeMove(int row, int col)
{
    board[row][col] = currentPlayer;
    cout << "Computer played at (" << row << ", " << col << ")" << endl;
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
        file << put_time(ltm, "%Y/%m/%d %H:%M:%S") << " | " << winner << " | Duration: " << duration << " seconds" << endl;
        file.close();
    }
    else
    {
        throw runtime_error("Unable to open file");
    }
}