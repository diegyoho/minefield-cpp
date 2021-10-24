#include "Grid.h"

#include "Random.h"

#include <iostream>

Grid* Grid::GetSingleton()
{
	static Grid* grid = new Grid();
	return grid;
}

void Grid::Draw(const int selectedX, const int selectedY) const
{
	for (int j = 0; j <= height; ++j)
	{
		for (int i = 0; i <= width; ++i)
		{
			int x = i - 1;
			int y = j - 1;
			

			if (j == 0)
			{
				if (i == 0)
				{
					std::cout << "   ";
				}
				else
				{
					std::cout << ' ' << x << ' ';
				}
			}
			else
			{
				if (i == 0)
				{
					std::cout << ' ' << y << ' ';
				}
				else
				{
					Position* position = positions[CoordsToVectorPosition(x, y)];
					
					if (!position->IsOpened())
					{
						if (selectedX == x && selectedY == y)
						{
							std::cout << (position->IsFlagged() ? "[F]" : "[?]");
						}
						else
						{
							std::cout << (position->IsFlagged() ? " F " : " ? ");
						}
					}
					else if (position->IsHiddingAMine())
					{
						if (selectedX == x && selectedY == y)
						{
							std::cout << "[*]";
						}
						else
						{
							std::cout << " * ";
						}
					}
					else if(position->GetMinesAround() > 0)
					{
						if (selectedX == x && selectedY == y)
						{
							std::cout << "[" << position->GetMinesAround() << "]";
						}
						else
						{
							std::cout << " " << position->GetMinesAround() << " ";
						}
					}
					else
					{
						if (selectedX == x && selectedY == y)
						{
							std::cout << "[ ]";
						}
						else
						{
							std::cout << "   ";
						}
					}
				}
			}
		}

		std::cout << '\n';
	}
}

bool Grid::OpenPosition(int x, int y) const
{
	Position* position = positions[CoordsToVectorPosition(x, y)];
	
	if (position->IsOpened())
	{
		return true;
	}

	position->SetOpen(true);
	numberOfPositionsOpened++;

	if (position->IsHiddingAMine())
	{
		OpenAll();
		return false;
	}

	std::vector<Position*> positionsAround;

	for (int j = -1; j < 2; ++j)
	{
		for (int i = -1; i < 2; ++i)
		{
			int _x = x + i;
			int _y = y + j;

			
			if (_x < 0 || _x >= width || _y < 0 || _y >= height || (_x == x && _y == y))
			{
				continue;
			}
			
			Position* positionAround = positions[CoordsToVectorPosition(_x, _y)];
			
			if (!positionAround->IsOpened())
			{
				if (positionAround->IsHiddingAMine())
				{
					position->GetMinesAround()++;
				}
				else
				{
					positionsAround.push_back(positionAround);
				}
			}
		}
	}

	if (position->GetMinesAround() == 0)
	{
		for (Position* positionAround : positionsAround)
		{
			OpenPosition(positionAround->GetX(), positionAround->GetY());
		}
	}

	return true;
}

void Grid::FlagPosition(int x, int y) const
{
	Position* position = positions[CoordsToVectorPosition(x, y)];
	position->SetFlag(!position->IsFlagged());
}

void Grid::OpenAll() const
{
	for (Position* position : positions)
	{
		position->SetOpen(true);
		position->SetFlag(false);
		position->GetMinesAround() = 0;
	}
}

bool Grid::IsAllMinesRevealed() const
{
	bool winner = (width * height) - numberOfPositionsOpened == numberOfMines;
	
	if (winner)
	{
		OpenAll();
	}

	return winner;
}

const int& Grid::GetWidth() const
{
	return width;
}

const int& Grid::GetHeight() const
{
	return height;
}

Grid::Grid() :
	width(10),
	height(10),
	numberOfMines(10),
	numberOfPositionsOpened(0)
{
	for (int i = 0; i < width * height; ++i)
	{
		positions.push_back(new Position(i % width, i / width));
	}

	for (int i = 0; i < numberOfMines; ++i)
	{
		int position = Random::RangeInt(0, width * height - 1);
		
		if (!positions[position]->IsHiddingAMine())
		{
			positions[position]->SetMine(true);
		}
		else
		{
			--i;
		}
	}
}

Grid::~Grid()
{
	std::cout << "Grid destroyed!\n";
}

int Grid::CoordsToVectorPosition(int x, int y) const
{
	return width * y + x;
}
