#pragma once

#include "Position.h"

#include <vector>

class Grid
{
private:

	int width;
	int height;

	std::vector<Position> positions;

	Grid();
	~Grid();

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

};

