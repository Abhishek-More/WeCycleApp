#ifndef AccountWrapper_hpp
#define AccountWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
	const void *initializeAccount();
	const void updateRank(const void *accountObj, const void *dbManager);
	const void updateXP(const void *accountObj, int increment, const void *dbManager);
	const void updateCoins(const void *accountObj, int incremenet, const void *dbManager);
	const void updatePFP(const void *accountObj, const char* link, const void *dbManager);
#ifdef __cplusplus
}
#endif

#endif
