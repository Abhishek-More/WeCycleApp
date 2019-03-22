#ifndef AccountWrapper_hpp
#define AccountWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
	const void *initializeAccount(const void *dataManager);

	void updateCheckAccount(const void *accountObj, bool res);
	void updateRank_override(const void *accountObj, const char* rank);
	void updateRank(const void *accountObj);
	void updateXP(const void *accountObj, int increment);
	void updateCoins(const void *accountObj, int incremenet);
	void updatePFP(const void *accountObj, const char* link);
	void updateDisplayName(const void *accountObj, const char* name);
	void updateScans(const void *accountObj, int increment);
	void addFriend(const void *accountObj, const char* uid);
	void addRequestFriend(const void *accountObj, const char* id);

	const bool checkAccount(const void *accountObj);
	const char* rank(const void *accountObj);
	const int experience(const void *accountObj);
	const int coins(const void *accountObj);
	const char* profilePicLink(const void *accountObj);
	const int numberOfScans(const void *accountObj);
	const char* displayName(const void *accountObj);
	const char **requestList(const void *accountObj);
	const char **friendsList(const void *accountObj);
#ifdef __cplusplus
}
#endif

#endif
