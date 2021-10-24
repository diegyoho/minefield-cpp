#include "Core/Grid.h"

#include <conio.h>
#include <iostream>

int main()
{
	bool gameOver = false;
	bool winner = false;
	
	int positionX{ 0 };
	int positionY{ 0 };

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

		Grid::GetSingleton()->Draw(positionX, positionY);

		/*std::cout << "\n\nInsert a position (X, Y) to open,\nseparated by spaces: ";

		int x{};
		int y{};

		std::cin >> x >> y;*/

		std::cout << "\n\nPress (W|A|S|D) to move (" << positionX << ", " << positionY << ")\n";
		std::cout << "Press (O) to open (" << positionX << ", " << positionY << ")\n";
		std::cout << "Press (F) to flag (" << positionX << ", " << positionY << ")\n";

		char key = _getch();

		switch (key)
		{
			case 'w':
				if (positionY > 0)
				{
					--positionY;
				}
				break;
			case 'a':
				if (positionX > 0)
				{
					--positionX;
				}
				break;
			case 's':
				if (positionY < Grid::GetSingleton()->GetHeight() - 1)
				{
					++positionY;
				}
				break;
			case 'd':
				if (positionX < Grid::GetSingleton()->GetHeight() - 1)
				{
					++positionX;
				}
				break;
			case 'o':
				gameOver = !Grid::GetSingleton()->OpenPosition(positionX, positionY);
				winner = Grid::GetSingleton()->IsAllMinesRevealed();
				break;
			case 'f':
				Grid::GetSingleton()->FlagPosition(positionX, positionY);
				break;
			default:
				break;
		}

		system("cls");

		/**/
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