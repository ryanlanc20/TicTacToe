#pragma once
#include <iostream>
#include <vector>
#include <map>

class Grid
{
public:
	Grid(const int size);
	void displayGrid();
	bool checkVacant(int x, int y);
	void insertChar(int x, int y, char playerChar);
	std::vector<int> getRandomPosition();
	bool hasVacantCells();
	char checkForWinner();

private:
	std::vector<std::vector<char>> grid;
	std::map<std::string, std::vector<int>> vacantCoords;
};

