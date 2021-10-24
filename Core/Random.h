#pragma once

#include <random>

// Basic Utility Functions for Random Values
namespace Random
{
	static std::mt19937 mersenneTwisterRand(std::mt19937::default_seed);

	inline void SetSeed(const unsigned int seed)
	{
		mersenneTwisterRand.seed(static_cast<std::mt19937::result_type>(seed));
	}

	inline int RangeInt(int min, int max)
	{
		std::uniform_int_distribution die{ min, max };
		return die(mersenneTwisterRand);
	}
};
