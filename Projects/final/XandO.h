/*

Assignment:     Final Project - Tic Tac Toe Game
Name:           Jared Bears
Date:           12/11/2024
File:           XandO.h

*/

#ifndef XANDO_H
#define XANDO_H

#include "Game.h"
#include <chrono>
using namespace std;

class XandO : public Game
{
public:
    XandO();
    void play(bool twoPlayerMode) override;
    void playerMove();
    void computerMove();
    void displayBoard() override;
    void switchPlayer() override;
    bool checkWin() override;
    bool checkDraw() override;
    void saveScore(const string &winner, double duration) override;

private:
    chrono::time_point<chrono::high_resolution_clock> start;
    bool twoPlayerMode;
    bool humanIsPlayer1;
    void makeMove(int row, int col); // Declaration of the makeMove function
};

#endif