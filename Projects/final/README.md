# Exes and Ohs

## Overview
Exes and Ohs is a Tic Tac Toe game that supports both single-player and two-player modes. The game allows players to play against each other or against the computer. The game also tracks the duration of each game and saves the results to a file.

## Features
- Single-player mode: Play against the computer.
- Two-player mode: Play against another player.
- Tracks the duration of each game.
- Saves the results to a file in the format `yyyy/mm/dd hh:mm:ss | [results] | [duration]`

## Requirements
C++ compiler that supports C++11 or later.

## Compilation
To compile the program, open your terminal, navigate to the project folder, and execute the following command:
```sh
g++ -o XandO.exe main.cpp Menu.cpp XandO.cpp
```

## Usage
To run the program, use the following command:
```sh
./XandO.exe
```

## How to Play
1. Run the program.
2. Select either single-player or two-player mode.
3. Follow the on-screen instructions to make your moves.
4. The game will display the winner or if the game is a draw.
5. The game duration will be displayed and saved to the scores.txt file.

## File Structure
project-directory/   
├── main.cpp # The main driver file.  
├── Menu.h # Header file for the Menu class.  
├── Menu.cpp # The Menu class that handles user input and displays the menu.  
├── Game.h #  The abstract base class for the game.  
├── XandO.h # Header file for XandO class.  
├── XandO.cpp # The XandO class that implements the game logic.  
└── README.md # Project documentation.  