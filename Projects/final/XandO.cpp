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
#include <algorithm>
#include <stdexcept>
using namespace std;

// Constructor to initialize the game board and players
XandO::XandO()
{
    board = vector<vector<char>>(3, vector<char>(3, ' ')); // Initialize a 3x3 board with empty spaces
    player1 = 'X';                                         // Player 1 is 'X'
    player2 = 'O';                                         // Player 2 is 'O'
    currentPlayer = player1;                               // Start with player 1
    srand(static_cast<unsigned int>(time(nullptr)));       // Seed the random number generator
}

// Function to start the game
void XandO::play(bool twoPlayerMode)
{
    this->twoPlayerMode = twoPlayerMode; // Set the game mode
    humanIsPlayer1 = rand() % 2 == 0;    // Randomly assign human to player 1 or player 2
    currentPlayer = player1;             // Start with player 1

    start = time(nullptr); // Start timing the game

    try
    {
        while (true)
        {
            displayBoard(); // Display the current state of the board
            if (twoPlayerMode || (humanIsPlayer1 && currentPlayer == player1) || (!humanIsPlayer1 && currentPlayer == player2))
            {
                playerMove(); // Human player's move
            }
            else
            {
                computerMove(); // Computer player's move
            }

            if (checkWin())
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                time_t end = time(nullptr); // End timing the game
                double duration = difftime(end, start);
                cout << "Game duration: " << duration << " seconds" << endl;
                saveScore(string(1, currentPlayer), duration); // Save the game result
                break;
            }
            if (checkDraw())
            {
                displayBoard();
                cout << "The game is a draw!" << endl;
                time_t end = time(nullptr); // End timing the game
                double duration = difftime(end, start);
                cout << "Game duration: " << duration << " seconds" << endl;
                saveScore("Draw", duration); // Save the game result
                break;
            }
            switchPlayer(); // Switch to the other player
        }
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
        // Return to the main menu
    }
}

// Function to handle the human player's move
void XandO::playerMove()
{
    string input;
    int row, col;
    int invalidAttempts = 0; // Counter for invalid input attempts
    while (true)
    {
        cout << "Player " << currentPlayer << ", enter your move (row and column as 'r c') or 'R' to resign: ";
        cin >> ws; // Eat up any leading whitespace
        getline(cin, input);

        if (input == "R" || input == "r")
        {
            cout << "Player " << currentPlayer << " has resigned. Game over." << endl;
            time_t end = time(nullptr); // End timing the game
            double duration = difftime(end, start);
            cout << "Game duration: " << duration << " seconds" << endl;
            saveScore(currentPlayer == player1 ? string(1, player2) : string(1, player1), duration); // Save the game result
            throw runtime_error("Player resigned");                                                  // Throw an exception to return to the main menu
        }

        istringstream iss(input);
        if (iss >> row >> col)
        {
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
            {
                board[row][col] = currentPlayer; // Make the move
                break;
            }
            else
            {
                cout << "Invalid move. Try again." << endl;
            }
        }
        else
        {
            cout << "Invalid input. Please enter a valid move." << endl;
            invalidAttempts++;
        }

        if (invalidAttempts >= 5)
        {
            time_t end = time(nullptr); // End timing the game
            double duration = difftime(end, start);
            saveScore("Invalid", duration);                                                                            // Save the game result
            throw runtime_error("Too many invalid attempts.  Game ending after " + to_string(duration) + " seconds."); // Throw an exception to return to the main menu
        }
    }
}

// Function to handle the computer player's move
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

// Helper function to make a move and print the move
void XandO::makeMove(int row, int col)
{
    board[row][col] = currentPlayer;
    cout << "Computer played at (" << row << ", " << col << ")" << endl;
}

// Function to display the current state of the board
void XandO::displayBoard()
{
    const int terminalWidth = 80;
    const int boardWidth = 17; // 3 cells * 4 characters (including borders) + 2 borders + 2 spaces for row labels
    const int padding = (terminalWidth - boardWidth) / 2;

    if (terminalWidth < boardWidth)
    {
        cout << "Warning: Terminal width is less than 80 characters. The board may not display correctly." << endl;
    }

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

// Function to switch to the other player
void XandO::switchPlayer()
{
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

// Function to check if the current player has won
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

// Function to check if the game is a draw
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

// Function to save the game result to a file
void XandO::saveScore(const string &winner, double duration)
{
    ofstream file("scores.txt", ios::app);
    if (file.is_open())
    {
        auto now = time(nullptr);
        tm ltm;
        safe_localtime(&ltm, &now); // Use safe_localtime for platform-specific time conversion
        file << put_time(&ltm, "%Y/%m/%d %H:%M:%S") << " | " << winner << " | Duration: " << duration << " seconds" << endl;
        file.close();
    }
    else
    {
        throw runtime_error("Unable to open file");
    }
}