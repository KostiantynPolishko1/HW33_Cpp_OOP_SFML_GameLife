#include <iostream>
#include <random>
#include "Cell.h"

bool isGridFilled(const char grid[][10], const short& row, const short& col)
{
	return grid[row][col] != 'x';
}

bool isNotOutRow(const short& rowSize, const short& row)
{
	return row >= 0 && row < rowSize;
}

bool isNotOutCol(const short& colSize, const short& col)
{
	return col >= 0 && col < colSize;
}


int main() 
{
	bool flag = false;
	short cellSteps[][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	short sizeSteps = std::size(cellSteps);
	short step{};
	const short SIZE = 10;
	char grid[SIZE][SIZE]{};

	std::mt19937 rand(static_cast<unsigned int>(time(0)));
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

		do {
			flag = false;
			step = rand() % sizeSteps;

			if (!(step % 2)) 
			{
				flag = isGridFilled(grid, cell->getRow() + cellSteps[step][0], cell->getCol() + cellSteps[step][1]) && isNotOutRow(SIZE, cell->getRow() + cellSteps[step][0]);
			}
			else 
			{
				flag = isGridFilled(grid, cell->getRow() + cellSteps[step][0], cell->getCol() + cellSteps[step][1]) && isNotOutRow(SIZE, cell->getCol() + cellSteps[step][1]);
			}

		} while (!flag);

		grid[cell->getRow()][cell->getCol()] = '-';

		if (!(step % 2)) {
			cell->setRow(cellSteps[step][0]);
		}
		else {
			cell->setCol(cellSteps[step][1]);
		}
	}

	return 0;
}