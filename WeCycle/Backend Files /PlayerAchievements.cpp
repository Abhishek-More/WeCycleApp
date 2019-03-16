#include "PlayerAchievements.h"

PlayerAchievements::PlayerAchievements(std::vector<std::map<firebase::Variant, firebase::Variant>> achievementsList, std::string uid)
{
	this->achievementsList = achievementsList;
	this->uid = uid;
	std::map<firebase::Variant, firebase::Variant> map;
	map.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, this->achievementsList));
	this->initialize(map);
}