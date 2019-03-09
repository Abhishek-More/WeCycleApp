#include "AuthenticationWrapper.hpp"
#include "Authentication.h"
#include "Account.h"
#include "FirebaseManager.h"

const void *initializeAuthentication(const void *fbManager, const void *dbManager) {
	Authentication *auth = new Authentication((FirebaseManager *)fbManager);
	return (void *)auth;
}

const char* createAndRegisterAccount_account(const void *authObj, const void *auth, const void *account) {
	Authentication *authObject = (Authentication *)auth;
	const char *result = authObject->createAndRegisterAccount((Account *)account).c_str();
	return result;
}

const char* createAndRegisterAccount_string(const void *authObj, const void *auth, const char* email, const char* password) {
	Authentication *authObject = (Authentication *)auth;
	return authObject->createAndRegisterAccount(email, password).c_str();
}

const char* signInUser_account(const void *authObj, const void *auth, const void  *account) {
	Authentication *authObject = (Authentication *)auth;
	return authObject->signInUser((Account *)account).c_str();
}

const char* signInUser_string(const void *authObj, const void *auth, const char* email, const char* password) {
	Authentication *authObject = (Authentication *)auth;
	return authObject->signInUser(email, password).c_str();
}
