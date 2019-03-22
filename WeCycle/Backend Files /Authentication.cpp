#include "Authentication.h"

Authentication::Authentication(FirebaseManager *fbManager, DataManager *dbManager) {
	app = fbManager->getApp();
	auth = firebase::auth::Auth::GetAuth(app);
	this->dbManage = dbManager;
}

Authentication::~Authentication() {}

void printWait1() {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	printf("Done!\n");
}

void Authentication::createAndRegisterAccount(Account *acc, std::string emailO, std::string passwordO) {

	const char *email = strdup(emailO.c_str());
	const char *password = strdup(passwordO.c_str());

	firebase::Future<firebase::auth::User*> result = auth->CreateUserWithEmailAndPassword(email, password);
	std::future<void> future = std::async(std::launch::async, printWait1);
	future.wait();
	acc->updateEmail(email);
	result.OnCompletion([](const firebase::Future<firebase::auth::User*>& result, void* user_data) {
		std::cout << "result completed" << std::endl;
		if (result.error() == firebase::auth::kAuthErrorNone) {
			Account *acc = static_cast<Account *>(user_data);
			firebase::auth::User *user = *result.result();
			std::string uID = user->uid();
			acc->createNewAccount(uID);
			acc->registerFriendsListeners();
			acc->updateCheckAccount(true);
			std::cout << "Successfully created account: " << user->email() << std::endl;
		}
		else {
			Account *acc = static_cast<Account *>(user_data);
			acc->updateCheckAccount(false);
			std::cout << "Error creating account..." << result.error_message() << std::endl;
		}
	}, acc);
}

void Authentication::signInUser(Account *acc, std::string emailO, std::string passwordO) {

	const char *email = strdup(emailO.c_str());
	const char *password = strdup(passwordO.c_str());

	firebase::Future<firebase::auth::User*> result =
		auth->SignInWithEmailAndPassword(email, password);
	std::future<void> future = std::async(std::launch::async, printWait1);
	future.wait();
	//while (result.status() != firebase::kFutureStatusComplete) {}

	acc->updateEmail(email);
	result.OnCompletion([](const firebase::Future<firebase::auth::User*>& result, void* user_data) {
		if (result.error() == firebase::auth::kAuthErrorNone) {
			std::cout << "result completed" << std::endl;
			Account *acc = static_cast<Account *>(user_data);
			firebase::auth::User* user = *result.result();
			std::string uID = user->uid();
			acc->updateUID(uID);
			acc->registerAccountListener();
			acc->registerFriendsListeners();
			acc->updateCheckAccount(true);
			printf("Sign in succeeded for email %s\n", user->email().c_str());
		}
		else {
			Account *acc = static_cast<Account *>(user_data);
			acc->updateCheckAccount(false);
			printf("Sign in failed with error '%s'\n", result.error_message());
		}
	}, acc);
	

}

void Authentication::signOutUser() {
	auth->SignOut();
}

void Authentication::updateUserProfile(Account *acc, const char* pfplink, const char* displayname) {
	firebase::auth::User *user = auth->current_user();
	if (user != nullptr) {
		firebase::auth::User::UserProfile profile;
		profile.display_name = displayname;
		profile.photo_url = pfplink;
		firebase::Future<void> future = user->UpdateUserProfile(profile);
		//while (future.status() != firebase::kFutureStatusComplete);
		future.OnCompletion([](const firebase::Future<void>& future, void* user_data) {
			Account *acc = static_cast<Account *>(user_data);
			if (future.error() == 0) {
				printf("Updated user profile");
			}
			else {
				printf("Failed to update user profile");
			}
		}, acc);
		acc->updatePFP(profile.photo_url);
		acc->updateDisplayName(profile.display_name);
	}
}
void Authentication::updateUserPFPLink(Account *acc, const char* pfplink) {
	firebase::auth::User *user = auth->current_user();
	if (user != nullptr) {
		firebase::auth::User::UserProfile profile;
		profile.photo_url = pfplink;
		printf(user->display_name().c_str());
		profile.display_name = strdup(user->display_name().c_str());
		firebase::Future<void> future = user->UpdateUserProfile(profile);
		future.OnCompletion([](const firebase::Future<void>& future, void* user_data) {
			if (future.error() == 0) {
				printf("Updated user profile pic link");
			}
			else {
				printf("Failed to update user profile pic link");
			}
		}, nullptr);
		acc->updatePFP(profile.photo_url);
	}
}

std::string findAndRemovePeriod1(std::string inp) {
	std::string input = inp;
	std::size_t index = input.find(".");
	input.erase(input.begin() + index);
	return input;
}

const char *Authentication::getUID(const char *email) { 
	firebase::Variant string;
	EmailsValueListener *listener = new EmailsValueListener(&string);
	std::string emailO = findAndRemovePeriod1(email);
    this->dbManage->getDBref().Child("Emails").Child(emailO).AddValueListener(listener);
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	const char *result = strdup(string.mutable_string().c_str());
	return result;
}

