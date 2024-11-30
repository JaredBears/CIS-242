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

public:
    virtual ~Game() {}
    virtual void play() = 0;
    virtual void displayBoard() = 0;
    virtual void switchPlayer() = 0;
    virtual bool checkWin() = 0;
    virtual bool checkDraw() = 0;
    virtual void saveScore(const string &winner) = 0;
};

#endif