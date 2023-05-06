#include "Grid.h"
#include <vector>
#include <string>

Grid::Grid(const int size)
{
	for (int row = 0; row < size; row++)
	{
		// Add row
		this->grid.push_back(std::vector<char>());

		// Populate each column in the row
		for (int col = 0; col < size; col++)
		{
			this->grid.at(row).push_back('_');

			// Hash coordinate string to vector
			std::vector<int> coords;
			coords.push_back(row);
			coords.push_back(col);
			this->vacantCoords[std::to_string(row) + std::to_string(col)] = coords;
		}
	}
}

void Grid::displayGrid()
{
	std::system("cls");
	for (int row = 0; row < this->grid.size(); row++)
	{
		for (int col = 0; col < this->grid.size(); col++)
		{
			std::cout << grid.at(row).at(col);
		}
		std::cout << std::endl;
	}
}

bool Grid::checkVacant(int row, int col)
{
	if (row < this->grid.size() && col < this->grid.size())
	{
		// Search for coordinates
		std::string coordString = std::to_string(row) + std::to_string(col);
		return this->vacantCoords.find(coordString) != this->vacantCoords.end();
	}
	return false;
}

void Grid::insertChar(int row, int col, char typeChar)
{
	this->grid.at(row).at(col) = typeChar;

	// Cell is now occupied
	this->vacantCoords.erase(std::to_string(row) + std::to_string(col));
}

bool Grid::hasVacantCells()
{
	return this->vacantCoords.size() != 0;
}

std::vector<int> Grid::getRandomPosition()
{
	int random = rand() % (this->vacantCoords.size());
	int index = 0;
	std::vector<int> coords;

	for (std::pair<std::string,std::vector<int>> pair : this->vacantCoords)
	{
		if (index == random)
		{
			return pair.second;
		}
		index++;
	}

}

char Grid::checkForWinner()
{
	// Check rows
	for (int row = 0; row < this->grid.size(); row++)
	{
		char previous = this->grid.at(row).at(0);
		bool noMatch = false;
		for (int col = 1; col < this->grid.size(); col++)
		{
			if (this->grid.at(row).at(col) != previous)
			{
				noMatch = true;
				break;
			}
		}
		
		if (!noMatch)
			return previous;
	}

	// Check colums
	for (int col = 0; col < this->grid.size(); col++)
	{
		char previous = this->grid.at(0).at(col);
		bool noMatch = false;

		for (int row = 1; row < this->grid.size(); row++)
		{
			if (this->grid.at(row).at(col) != previous)
			{
				noMatch = true;
				break;
			}
		}

		if (!noMatch)
			return previous;
	}

	// Check top left to bottom right
	bool isComplete = true;
	char prev = this->grid.at(0).at(0);

	for (int row = 1; row < this->grid.size(); row++)
	{
		if (this->grid.at(row).at(row) != prev)
		{
			isComplete = false;
			break;
		}
	}

	if (isComplete)
		return prev;

	// Check bottom left to top right
	isComplete = true;
	prev = this->grid.at(0).at(this->grid.size() - 1);

	for (int row = 0; row < this->grid.size(); row++)
	{
		if (this->grid.at(row).at(this->grid.size() - 1 - row) != prev)
		{
			isComplete = false;
			break;
		}
	}

	if (isComplete)
		return prev;

	return '_';
}
