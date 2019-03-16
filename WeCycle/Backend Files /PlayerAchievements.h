#pragma once
#include <iostream>
#include "DataManager.h"
#include "PushableObject.h"
#include <firebase/auth.h>
#include <firebase/future.h>

class PlayerAchievements : public PushableObject
{
private:
	std::string uid;
	std::vector<std::map<firebase::Variant, firebase::Variant>> achievementsList;

	/*Achievements for Demo purpose:
		First Scan
		Raffle Alert
	*/
public:
	PlayerAchievements(std::vector<std::map<firebase::Variant, firebase::Variant>> achievementsList, std::string uid);
};