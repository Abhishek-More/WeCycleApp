#include "Authentication.h"

Authentication::Authentication(FirebaseManager *fbManager, DataManager *dbManager) {
	app = fbManager->getApp();
	auth = firebase::auth::Auth::GetAuth(app);
	crypto = Crypto(dbManager);
}

Authentication::~Authentication() {}

std::string Authentication::createAndRegisterAccount(Account *acc) {
	
	std::string uID = "";

	const char *email = strdup(acc->getEmail().c_str());
	const char *password = crypto.hashSHAKE128(acc->getPassword()).c_str();

	firebase::Future<firebase::auth::User*> result = auth->CreateUserWithEmailAndPassword(email, password);

	if (result.status() == firebase::kFutureStatusComplete) {
		if (result.error() == firebase::auth::kAuthErrorNone) {
			firebase::auth::User *user = *result.result();
			uID = user->uid();
			std::cout << "Successfully created account: " << user->email() << std::endl;
		}
		else {
			std::cout << "Error creating account..." << result.error_message() << std::endl;
		}
	}

	return uID;
}
std::string Authentication::createAndRegisterAccount(std::string emailO, std::string passwordO) {

	std::string uID = "";

	const char *email = strdup(emailO.c_str());
	const char *password = crypto.hashSHAKE128(passwordO).c_str();

	firebase::Future<firebase::auth::User*> result = auth->CreateUserWithEmailAndPassword(email, password);

	if (result.status() == firebase::kFutureStatusComplete) {
		if (result.error() == firebase::auth::kAuthErrorNone) {
			firebase::auth::User *user = *result.result();
			uID = user->uid();
			std::cout << "Successfully created account: " << user->email() << std::endl;
		}
		else {
			std::cout << "Error creating account..." << result.error_message() <<std::endl;
		}
	}

	return uID;
}

std::string Authentication::signInUser(Account *acc) {

	std::string uID = "";

	const char *email = strdup(acc->getEmail().c_str());
	const char *password = crypto.hashSHAKE128(acc->getPassword()).c_str();

	firebase::Future<firebase::auth::User*> result =
		auth->SignInWithEmailAndPassword(email, password);

	if (result.status() == firebase::kFutureStatusComplete) {
		if (result.error() == firebase::auth::kAuthErrorNone) {
			firebase::auth::User* user = *result.result();
			uID = user->uid();
			printf("Sign in succeeded for email %s\n", user->email().c_str());
		}
		else {
			printf("Sign in failed with error '%s'\n", result.error_message());
		}
	}

	return uID;
}
std::string Authentication::signInUser(std::string emailO, std::string passwordO) {

	std::string uID = "";

	const char *email = strdup(emailO.c_str());
	const char *password = crypto.hashSHAKE128(passwordO).c_str();

	firebase::Future<firebase::auth::User*> result =
		auth->SignInWithEmailAndPassword(email, password);

	if (result.status() == firebase::kFutureStatusComplete) {
		if (result.error() == firebase::auth::kAuthErrorNone) {
			firebase::auth::User* user = *result.result();
			uID = user->uid();
			printf("Sign in succeeded for email %s\n", user->email().c_str());
		}
		else {
			printf("Sign in failed with error '%s'\n", result.error_message());
		}
	}

	return uID;
}
