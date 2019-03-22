#include "PlayerAchievementsWrapper.hpp"
#include "PlayerAchievements.h"

const void *initializePlayerAchievements(const void *dataManager, const char* uid) {
	DataManager *dataM = (DataManager *)dataManager;
	PlayerAchievements *playerAchieve = new PlayerAchievements(dataM, uid);
	return (void *)playerAchieve;
}

void addAchievement(const void *achievementObj, const void *account, const char* achievementID) {
	PlayerAchievements *playerAchieve = (PlayerAchievements *)achievementObj;
	Account *acc = (Account *)account;
	playerAchieve->addAchievement(acc, achievementID);
}