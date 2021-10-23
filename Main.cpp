#include "Grid.h"

#include <iostream>

int main()
{
	std::cout << "Welcome to Minefield!\n\n";
	
	Grid::GetSingleton()->Draw();
	
	std::cin.get();

	return 0;
}