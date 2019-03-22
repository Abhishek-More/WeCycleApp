#include "PlayerAchievements.h"

PlayerAchievements::PlayerAchievements(DataManager *dbm, std::vector<std::map<firebase::Variant, firebase::Variant>> achievementsList, std::string uid)
{
	this->dbm = dbm;
	this->achievementsList = achievementsList;
	this->uid = uid;
	std::map<firebase::Variant, firebase::Variant> map;
	map.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, this->achievementsList));
	this->initialize(map);
}

PlayerAchievements::PlayerAchievements(DataManager *dbm, std::string uid)
{
	this->dbm = dbm;
	this->uid = uid;
	std::map<firebase::Variant, firebase::Variant> map;
	map.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, this->achievementsList));
	this->initialize(map);
}

void PlayerAchievements::addAchievement(Account *acc, std::string achievementID) 
{

	std::map<firebase::Variant, firebase::Variant> map;
	map.insert(std::pair<firebase::Variant, firebase::Variant>(achievementID, true));
	this->achievementsList.push_back(map);
	std::map<firebase::Variant, firebase::Variant> map1;
	map1.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, this->achievementsList));
	this->initialize(map1);
 //Vector of variants1
	firebase::Variant achievementList;
	this->dbm->retrieveData("Achievements", achievementID, achievementList);
	
	if (achievementList.is_vector()) {
		if (achievementList.vector()[2].is_map()) { //2 is index value of the number of coins achievement is worth
			for (auto &x : achievementList.vector()[2].map()) {
				if (x.second.is_int64()) {
					int increment = x.second.int64_value();
					acc->updateCoins(increment);
				}
			}
		}
	}

	dbm->pushData(this, "User Achievements");
}
//TODO IMPLEMENT AUTOMATIC CHECKING USING VALUE LISTENERS

class AchievementListener : public firebase::database::ValueListener {

};