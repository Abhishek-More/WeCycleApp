#include "AccountWrapper.hpp"
#include "Account.h"

const void *initializeAccount(const void *dataManager) {
	DataManager *dataM = (DataManager *)dataManager;
	Account *account = new Account(dataM);
	return (void *)account;
}
void updateCheckAccount(const void *accountObj, bool res) {
	Account *account = (Account *)accountObj;
	account->updateCheckAccount(res);
}
void updateRank_override(const void *accountObj, const char* rank) {
	Account *account = (Account *)accountObj;
	account->updateRank_override(rank);
}
void updateRank(const void *accountObj) {
	Account *account = (Account *)accountObj;
	account->updateRank();
}
void updateXP(const void *accountObj, int increment) {
	Account *account = (Account *)accountObj;
	account->updateXP(increment);
}
void updateCoins(const void *accountObj, int incremenet) {
	Account *account = (Account *)accountObj;
	account->updateCoins(incremenet);
}
void updatePFP(const void *accountObj, const char* link) {
	Account *account = (Account *)accountObj;
	account->updatePFP(link);
}

void updateDisplayName(const void *accountObj, const char* name) {
    Account *account = (Account *)accountObj;
    account->updateDisplayName(name);
}

void updateScans(const void *accountObj, int increment) {
	Account *account = (Account *)accountObj;
	account->updateScans(increment);
}
const bool checkAccount(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->checkAccountA();
}
const char* rank(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->rankA();
}
const int experience(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->experienceA();
}
const int coins(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->coinsA();
}
const char* profilePicLink(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->profilePicLinkA();
}
const int numberOfScans(const void *accountObj) {
	Account *account = (Account *)accountObj;
	return account->numberOfScansA();
    
}

const char* displayName(const void *accountObj) {
    Account *account = (Account *)accountObj;
    return account->displaynameA();
}
