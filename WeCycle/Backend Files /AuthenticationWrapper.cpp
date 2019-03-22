#include "AuthenticationWrapper.hpp"
#include "Authentication.h"
#include "Account.h"
#include "FirebaseManager.h"

const void *initializeAuthentication(const void *fbManager, const void *dbManager) {
	Authentication *auth = new Authentication((FirebaseManager *)fbManager, (DataManager *)dbManager);
	return (void *)auth;
}

const void createAndRegisterAccount(const void *auth, const void *account, const char* email, const char* password) {
	Authentication *authObject = (Authentication *)auth;
	authObject->createAndRegisterAccount((Account *)account, email, password);
}

const void signInUser(const void *auth, const void *account, const char* email, const char* password) {
	Authentication *authObject = (Authentication *)auth;
	authObject->signInUser((Account *)account, email, password);
}

void signOutUser(const void *auth) {
	Authentication *authObject = (Authentication *)auth;
	authObject->signOutUser();
}

void updateUserProfile(const void *auth, const void *acc, const char* pfplink, const char* displayname) {
	Authentication *authObject = (Authentication *)auth;
	Account *account = (Account *)acc;
	authObject->updateUserProfile(account, pfplink, displayname);
}
void updateUserPFPLink(const void *auth, const void *acc, const char* pfplink) {
	Authentication *authObject = (Authentication *)auth;
	Account *account = (Account *)acc;
	authObject->updateUserPFPLink(account, pfplink);
}