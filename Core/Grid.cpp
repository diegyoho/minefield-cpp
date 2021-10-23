#include "Grid.h"

#include "Random.h"

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
					std::cout << " X ";
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
					std::cout << (positions[((i-1) * (j-1)) + (i-1)]->IsHiddingAMine() ? "[*]" : "[?]");
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
	for (int i = 0; i < 10 * 10; ++i)
	{
		positions.push_back(new Position());
		positions[i]->SetMine(Random::RangeInt(0, 1) == 0);
	}
}

Grid::~Grid()
{
	std::cout << "Grid destroyed!\n";
}
