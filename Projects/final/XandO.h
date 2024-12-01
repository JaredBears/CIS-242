/*

Assignment:     Final Project - Tic Tac Toe Game
Name:           Jared Bears
Date:           12/11/2024
File:           XandO.h

*/

#ifndef XANDO_H
#define XANDO_H

#include "Game.h"

class XandO : public Game
{
public:
    XandO();
    void play() override;
    void playerMove();
    void displayBoard() override;
    void switchPlayer() override;
    bool checkWin() override;
    bool checkDraw() override;
    void saveScore(const string &winner) override;
};

#endif