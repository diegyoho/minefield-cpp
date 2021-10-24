#pragma once

#include "Position.h"

#include <vector>

class Grid
{
private:

	int width;
	int height;
	int numberOfMines;
	mutable int numberOfPositionsOpened;

	std::vector<Position*> positions;

	Grid();
	~Grid();

	int CoordsToVectorPosition(const int& x, const int& y) const;
	void OpenAll() const;

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

	static void Initialize(const int& width, const int& height, const int& numberOfMines);

	void Draw(const int selectedX = -1, const int selectedY = -1) const;

	bool OpenPosition(int x, int y) const;
	void FlagPosition(int x, int y) const;

	bool IsAllMinesRevealed() const;

	const int& GetWidth() const;
	const int& GetHeight() const;
};

