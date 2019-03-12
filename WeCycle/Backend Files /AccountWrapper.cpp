#include "AccountWrapper.hpp"
#include "Account.h"

const void *initializeAccount() {
	Account *account = new Account();
	return (void *)account;
}
const void updateRank(const void *accountObj, const void *dbManager) {
	Account *account = (Account *)accountObj;
	DataManager *dbm = (DataManager *)dbManager;
	account->updateRank(dbm);
}
const void updateXP(const void *accountObj, int increment, const void *dbManager) {
	Account *account = (Account *)accountObj;
	DataManager *dbm = (DataManager *)dbManager;
	account->updateXP(increment, dbm);
}
const void updateCoins(const void *accountObj, int incremenet, const void *dbManager) {
	Account *account = (Account *)accountObj;
	DataManager *dbm = (DataManager *)dbManager;
	account->updateCoins(incremenet, dbm);
}
const void updatePFP(const void *accountObj, const char* link, const void *dbManager) {
	Account *account = (Account *)accountObj;
	DataManager *dbm = (DataManager *)dbManager;
	account->updatePFP(link, dbm);
}