/*

Assignment:     Final Project - Tic Tac Toe Game
Name:           Jared Bears
Date:           12/11/2024
File:           Game.h

*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <stdexcept>
using namespace std;

class Game
{
protected:
    vector<vector<char>> board;
    char player1;
    char player2;
    char currentPlayer;
    time_t start; // Member variable to store the start time

public:
    virtual ~Game() {}
    virtual void play(bool twoPlayerMode) = 0;
    virtual void displayBoard() = 0;
    virtual void switchPlayer() = 0;
    virtual bool checkWin() = 0;
    virtual bool checkDraw() = 0;
    virtual void saveScore(const string &winner, double duration) = 0;

protected:
    // Platform-specific function for converting time_t to tm
    void safe_localtime(tm *result, const time_t *time)
    {
#ifdef _WIN32
        localtime_s(result, time); // Use localtime_s for Windows
#else
        localtime_r(time, result); // Use localtime_r for POSIX
#endif
    }
};

#endif