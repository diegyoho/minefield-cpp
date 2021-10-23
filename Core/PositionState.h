#pragma once

enum class PositionState : char
{
	Opened = 0x01,
	HiddenMine = 0x02,
	Flagged = 0x04
};

//Bitwise operator overloading for enum class PositionState

inline PositionState operator~(const PositionState& flag)
{
	return static_cast<PositionState>(~static_cast<char>(flag));
}

inline PositionState operator|(const PositionState& lFlag, const PositionState& rFlag)
{
	return static_cast<PositionState>(static_cast<char>(lFlag) | static_cast<char>(rFlag));
}

inline PositionState operator&(const PositionState& lFlag, const PositionState& rFlag)
{
	return static_cast<PositionState>(static_cast<char>(lFlag) & static_cast<char>(rFlag));
}

inline PositionState& operator|=(PositionState& lFlag, PositionState rFlag)
{
	return lFlag = static_cast<PositionState>(static_cast<char>(lFlag) | static_cast<char>(rFlag));
}

inline PositionState& operator&=(PositionState& lFlag, PositionState rFlag)
{
	return lFlag = static_cast<PositionState>(static_cast<char>(lFlag) & static_cast<char>(rFlag));
}
