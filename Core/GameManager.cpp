#include "GameManager.h"

#include "Grid.h"

#include <conio.h>
#include <iostream>

GameManager::GameManager() :
	selectedX(0),
	selectedY(0),
	gameEnded(false)
{
}

GameManager::~GameManager()
{
}

GameManager* GameManager::GetSingleton()
{
	static GameManager* gameManager = new GameManager();
	return gameManager;
}

void GameManager::ShowDescription() const
{
	std::cout << "\n\tWelcome to Minefield!\n\n";
	std::cout << "Your objective is to reveal the entire\nminefield without any being detonated.\n\n";
	std::cout << "Below is the caption of each symbol:\n\n";

	std::cout << "[?] : Unknown.\n";
	std::cout << "[ ] : Open | 0 mines around.\n";
	std::cout << "[n] : n mines around.\n";
	std::cout << "[*] : Mine! Boom!\n";
	std::cout << "[F] : Flag!\n\n";
}

void GameManager::InitGame()
{
	gameEnded = false;
	selectedX = 0;
	selectedY = 0;

	system("cls");

	ShowDescription();

	int width{ 10 };
	int height{ 10 };
	int numberOfMines{ 10 };

	std::cout << "Want to customize the game? Press (y/n)\n";

	char key = _getch();

	if (key == 'y')
	{
		std::cout << "\nEnter the grid dimensions,\nseparated by space (E.g. 10 10): ";
		std::cin >> width >> height;
		std::cout << "\nEnter the number of mines: ";
		std::cin >> numberOfMines;
	}

	Grid::Initialize(width, height, numberOfMines);

	while (!gameEnded)
	{
		system("cls");

		ShowDescription();

		Grid::GetSingleton()->Draw(selectedX, selectedY);

		HandleInput();
	}

	system("cls");
	
	GameOver();
}

void GameManager::HandleInput()
{
	std::cout << "\n\nPress (W|A|S|D) to move (" << selectedX << ", " << selectedY << ")\n";
	std::cout << "Press (O) to open (" << selectedX << ", " << selectedY << ")\n";
	std::cout << "Press (F) to flag (" << selectedX << ", " << selectedY << ")\n";

	char key = _getch();

	switch (key)
	{
		case 'w':
			if (selectedY > 0)
			{
				--selectedY;
			}
			break;
		case 'a':
			if (selectedX > 0)
			{
				--selectedX;
			}
			break;
		case 's':
			if (selectedY < Grid::GetSingleton()->GetHeight() - 1)
			{
				++selectedY;
			}
			break;
		case 'd':
			if (selectedX < Grid::GetSingleton()->GetHeight() - 1)
			{
				++selectedX;
			}
			break;
		case 'o':
			gameEnded = !Grid::GetSingleton()->OpenPosition(selectedX, selectedY) || Grid::GetSingleton()->IsAllMinesRevealed();
			break;
		case 'f':
			Grid::GetSingleton()->FlagPosition(selectedX, selectedY);
			break;
		default:
			break;
	}
}

void GameManager::GameOver() const
{
	if (Grid::GetSingleton()->IsAllMinesRevealed())
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
}
