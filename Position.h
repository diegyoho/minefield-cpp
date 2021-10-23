#pragma once

enum class PositionState : char;

class Position
{
private:

	int minesAround;
	PositionState state;

public:

	Position();
	~Position();

	bool IsOpened() const;
	bool IsHiddingAMine() const;
	bool IsFlagged() const;

	void SetOpen(bool open);
	void SetMine(bool hasMine);
	void SetFlag(bool setFlag);
};

