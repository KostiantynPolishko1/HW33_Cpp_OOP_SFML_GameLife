#include <iostream>
#include <ctime>
#include "Cell.h"

int main() 
{
	srand(time(NULL));

	short cellSteps[][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	short indexStep{};
	const short SIZE = 10;
	char grid[SIZE][SIZE]{};

	std::shared_ptr<Cell> cell = std::make_shared<Cell>(rand()%10, rand()%10);

	for (size_t i = 0; i < 10; i++)
		for (size_t j = 0; j < 10; j++)
			grid[i][j] = '-';

	while (true) 
	{
		grid[cell->getRow()][cell->getCol()] = cell->getCell();
		for (size_t i = 0; i < 10; i++) 
		{
			for (size_t j = 0; j < 10; j++)
			{
				std::cout << grid[i][j] << " ";
			}
			std::cout << std::endl;
		}
		system("CLS");
		grid[cell->getRow()][cell->getCol()] = '-';

	indexStep = rand() % std::size(cellSteps);

	if (cell->getRow() + cellSteps[indexStep][0] >= 0 && cell->getRow() + cellSteps[indexStep][0] < SIZE)
		cell->setRow(cellSteps[indexStep][0]);

	if (cell->getCol() + cellSteps[indexStep][1] >= 0 && cell->getCol() + cellSteps[indexStep][1] < SIZE)
		cell->setCol(cellSteps[indexStep][1]);

	}

	return 0;
}