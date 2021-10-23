#pragma once

#include "Position.h"

#include <vector>

class Grid
{
private:

	int width;
	int height;
	int numberOfMines;

	std::vector<Position*> positions;

	Grid();
	~Grid();

	int CoordsToVectorPosition(int x, int y) const;

public:

	static Grid* GetSingleton();

	/**
	* Singletons should not be cloneable.
	*/
	Grid(Grid& other) = delete;
	/**
	 * Singletons should not be assignable.
	 */
	void operator=(const Grid&) = delete;

	void Draw() const;

	bool OpenPosition(int x, int y) const;
	void OpenAll() const;
};

