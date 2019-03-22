#ifndef PlayerAchievementsWrapper_hpp
#define PlayerAchievementsWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
	const void *initializePlayerAchievements(const void *dataManager, const char* uid);
	void addAchievement(const void *achievementObj, const void *account, const char* achievementID);
#ifdef __cplusplus
}
#endif

#endif