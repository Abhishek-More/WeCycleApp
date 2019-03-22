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
	void updateScans(const void *accountObj, int increment);
    void updateDisplayName(const void *accountObj, const char* name);
	const bool checkAccount(const void *accountObj);
	const char* rank(const void *accountObj);
	const int experience(const void *accountObj);
	const int coins(const void *accountObj);
	const char* profilePicLink(const void *accountObj);
	const int numberOfScans(const void *accountObj);
    const char* displayName(const void *accountObj);
#ifdef __cplusplus
}
#endif

#endif
