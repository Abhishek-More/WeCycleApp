#pragma once
#include "Account.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include <iostream>
#include <firebase/auth.h>
#include <firebase/future.h>
#include <ctime>

class Authentication {

private:
	DataManager *dbManage;
public: 

	firebase::auth::Auth* auth;
	firebase::App* app;

	Authentication(FirebaseManager *fbManager, DataManager *dbManager);
	~Authentication();

	void createAndRegisterAccount(Account *acc, std::string emailO, std::string passwordO);
	void signInUser(Account *acc, std::string emailO, std::string passwordO);
	void signOutUser();

	void updateUserProfile(Account *acc, const char* pfplink, const char* displayname);
	void updateUserPFPLink(Account *acc, const char* pfplink);
};