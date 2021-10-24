#pragma once

class GameManager
{
private:
	
	// Variables that indicate the selected position
	int selectedX;
	int selectedY;

	// Keep the state if the game is over
	bool gameEnded;

	GameManager();
	~GameManager();

public:

	static GameManager* GetSingleton();

	/**
	* Singletons should not be cloneable.
	*/
	GameManager(GameManager& other) = delete;
	/**
	 * Singletons should not be assignable.
	 */
	void operator=(const GameManager&) = delete;

	void ShowDescription() const;
	void InitGame();
	void HandleInput();
	void GameOver() const;
};

