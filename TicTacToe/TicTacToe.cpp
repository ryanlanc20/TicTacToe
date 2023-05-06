// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Grid.h";


int main()
{
    Grid gameGrid(3);

    int row, col;
    while (true) {
        gameGrid.displayGrid();

        // Get coordinates for player move
        std::cout << "Enter row number" << std::endl;
        std::cin >> row;
        std::cout << "Enter col number" << std::endl;
        std::cin >> col;

        if (!gameGrid.checkVacant(row, col))
        {
            // Cell already occupied.
            std::cout << "Cell already occupied." << std::endl;
            continue;
        }

        gameGrid.insertChar(row, col, 'X');

        // Let computer take its turn

        if (gameGrid.hasVacantCells())
        {
            std::vector<int> randomTurn = gameGrid.getRandomPosition();
            gameGrid.insertChar(randomTurn.at(0), randomTurn.at(1), 'O');
        }

        // Did the player or computer win the game?
        char winner = gameGrid.checkForWinner();
        if (winner == 'X')
        {
            gameGrid.displayGrid();
            std::cout << "You won!" << std::endl;
            break;
        }
        if (winner == 'O')
        {
            gameGrid.displayGrid();
            std::cout << "Oops, the computer won this time. Better luck next time!" << std::endl;
            break;
        }
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
