#pragma once
#include <iostream>
#include "DataManager.h"
#include "PushableObject.h"
#include <firebase/auth.h>
#include <firebase/future.h>
#include "Account.h"
#include <future>
#include <chrono>


class PlayerAchievements : public PushableObject
{
private:
	std::string uid;
	std::vector<std::map<firebase::Variant, firebase::Variant>> achievementsList;
	DataManager *dbm;
	/*Achievements for Demo purpose:
		First Scan
		Raffle Alert
	*/
public:
	PlayerAchievements(DataManager *dbm, std::vector<std::map<firebase::Variant, firebase::Variant>> achievementsList, std::string uid);
	PlayerAchievements(DataManager *dbm, std::string uid);
	void addAchievement(Account *acc, std::string achievementID);
};
