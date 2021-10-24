#include "Core/Grid.h"

#include <iostream>

int main()
{
	bool gameOver = false;
	bool winner = false;

	while (!(gameOver || winner))
	{
		//Temporary Description
		std::cout << "\n\tWelcome to Minefield!\n\n";
		std::cout << "Your objective is to reveal the entire\nminefield without any being detonated.\n\n";
		std::cout << "Below is the caption of each symbol:\n\n";

		std::cout << "[?] : Unknown.\n";
		std::cout << "[ ] : Open | 0 mines around.\n";
		std::cout << "[n] : n mines around.\n";
		std::cout << "[*] : Mine! Boom!\n";
		std::cout << "[F] : Flag!\n\n";

		Grid::GetSingleton()->Draw();

		std::cout << "\n\nInsert a position (X, Y) to open,\nseparated by spaces: ";

		int x{};
		int y{};

		std::cin >> x >> y;

		system("cls");

		gameOver = !Grid::GetSingleton()->OpenPosition(x, y);
		winner = Grid::GetSingleton()->IsAllMinesRevealed();
	}

	if (winner)
	{
		std::cout << "\n\tCONGRATULATIONS!\n\n";

		Grid::GetSingleton()->Draw();

		std::cout << "\n\nYou revealed all mines!\n";
	}
	else
	{
		std::cout << "\n\tBOOOOMMMMMMM!\n\n";

		Grid::GetSingleton()->Draw();

		std::cout << "\n\nYou hit a mine, game over!\n";
	}

	std::cout << "Thank you for playing.\n";
	
	return 0;
}