#include "Core/GameManager.h"

#include <conio.h>
#include <iostream>

int main()
{
	char key{};
	do
	{
		GameManager::GetSingleton()->InitGame();
		
		std::cout << "\nWant to play again? Press (y/n)\n";

		key = _getch();

	} while (key == 'y');

	std::cout << "\n\nThank you for playing.\n\n";
	
	system("pause");

	return 0;
}