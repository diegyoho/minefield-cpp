#pragma once

class Grid
{

private:

	int width;
	int height;

protected:

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

