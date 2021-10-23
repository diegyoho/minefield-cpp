#include "Grid.h"

#include <iostream>

Grid* Grid::GetSingleton()
{
	static Grid* grid = new Grid();
	return grid;
}

void Grid::Draw() const
{
	for (int j = 0; j <= height; ++j)
	{
		for (int i = 0; i <= width; ++i)
		{
			if (j == 0)
			{
				if (i == 0)
				{
					std::cout << "   ";
				}
				else
				{
					std::cout << ' ' << i - 1 << ' ';
				}
			}
			else
			{
				if (i == 0)
				{
					std::cout << ' ' << j - 1 << ' ';
				}
				else
				{
					std::cout << "[ ]";
				}
			}
		}

		std::cout << '\n';
	}
}

Grid::Grid() :
	width(10),
	height(10)
{
}

Grid::~Grid()
{
	std::cout << "Grid destroyed!\n";
}
