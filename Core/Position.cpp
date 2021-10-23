#include "Position.h"

#include "PositionState.h"

#include <iostream>

Position::Position() :
	minesAround(-1),
	state(static_cast<PositionState>(0))
{
}

Position::~Position()
{
	std::cout << "Position destroyed!\n";
}

bool Position::IsOpened() const
{
	return static_cast<char>(state & PositionState::Opened);
}

bool Position::IsHiddingAMine() const
{
	return static_cast<char>(state & PositionState::HiddenMine);
}

bool Position::IsFlagged() const
{
	return static_cast<char>(state & PositionState::Flagged);
}

void Position::SetOpen(bool open)
{
	if (open)
	{
		state |= PositionState::Opened;
	}
	else
	{
		state &= ~PositionState::Opened;
	}
}

void Position::SetMine(bool hasMine)
{
	if (hasMine)
	{
		state |= PositionState::HiddenMine;
	}
	else
	{
		state &= ~PositionState::HiddenMine;
	}
}

void Position::SetFlag(bool setFlag)
{
	if (setFlag)
	{
		state |= PositionState::Flagged;
	}
	else
	{
		state &= ~PositionState::Flagged;
	}
}