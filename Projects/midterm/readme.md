# ATM Simulation Project

## Overview

This project is a simulation of an ATM system. It allows users to log in, check their balance, deposit and withdraw money, and calculate interest. The project is divided into multiple classes to handle different functionalities such as user management, login, and transactions.

## Classes

### `Menu`

- **File:** [Menu.h](./Menu.h), [Menu.cpp](./Menu.cpp)
- **Description:** Provides utility functions for input handling and truncating double values.

### `User`

- **File:** [User.h](./User.h), [User.cpp](./User.cpp)
- **Description:** Manages user information including username, password, and balance.

### `LoginMenu`
- **File:** [LoginMenu.h](./LoginMenu.h), [LoginMenu.cpp](./LoginMenu.cpp)
- **Description:** Handles user login and user creation.

### `TransactionMenu`

- **File:** [TransactionMenu.h](./TransactionMenu.h), [TransactionMenu.cpp](./TransactionMenu.cpp)
- **Description:** Manages transactions such as checking balance, depositing, withdrawing, and calculating interest.

## How to Compile

To compile the project using `g++`, follow these steps:

1. Open a terminal and navigate to the location where the project is saved.
2. Run the following command to compile all the `.cpp` files:

```sh
g++ -o atm.exe main.cpp Menu.cpp User.cpp LoginMenu.cpp TransactionMenu.cpp
```

And then to run the executable:
```sh
./atm.exe
```

## Usage
When you run the program, you will be prompted to log in.
Enter your username and password. If the user does not exist, a new user will be created.
After logging in, you will be presented with a menu to check your balance, deposit money, withdraw money, or check interest.
Follow the prompts to perform the desired actions.

## Author
Name: Jared Bears
Date: 2024-10-27