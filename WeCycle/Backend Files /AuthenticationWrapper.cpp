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
