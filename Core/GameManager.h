#pragma once

class GameManager
{
private:
	
	int selectedX;
	int selectedY;
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

