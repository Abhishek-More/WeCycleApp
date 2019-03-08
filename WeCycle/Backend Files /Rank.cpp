#include "Rank.h"

Rank::Rank()
{
	this->xp = 0;
	this->rank = "Beginner";
}

Rank::Rank(unsigned int xp, std::string rank)
{
	this->xp = xp;
	this->rank = rank;
}

void Rank::LevelUpRank()
{
	if (250 <= xp < 500) { rank = "Junior Environmentalist"; }
	else if (500 <= xp < 1000) { rank = "Conscious Saver"; }
	else if (1000 <= xp < 2000) { rank = "Official Eco-citizen"; }
	else if (2000 <= xp < 5000) { rank = "EPA Agent"; }
}