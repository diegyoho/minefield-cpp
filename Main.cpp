#include "Core/GameManager.h"

#include <conio.h>
#include <iostream>

int main()
{
	GameManager::GetSingleton()->InitGame();

	return 0;
}