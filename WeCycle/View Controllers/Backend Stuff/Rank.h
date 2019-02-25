#pragma once
#include <iostream>
class Rank
{
private:
	unsigned int xp;
	std::string rank;

public:
	Rank();
	Rank(unsigned int xp, std::string rank);
	~Rank();

	void LevelUpRank();
};