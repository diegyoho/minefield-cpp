#pragma once

enum class PositionState : char;

class Position
{
private:

	PositionState state;
	int minesAround;
	int x;
	int y;

public:
	
	Position(int x, int y);
	~Position();

	bool IsOpened() const;
	bool IsHiddingAMine() const;
	bool IsFlagged() const;

	void SetOpen(bool open);
	void SetMine(bool hasMine);
	void SetFlag(bool setFlag);

	int& GetMinesAround();

	const int& GetX() const;
	const int& GetY() const;
};

