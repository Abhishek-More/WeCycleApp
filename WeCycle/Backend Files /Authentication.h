#pragma once
#include "Account.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include <iostream>
#include <firebase/auth.h>
#include <firebase/future.h>
#include "Crypto.h"

class Authentication {

private:
	Crypto crypto;
	DataManager *dbManage;
public: 

	firebase::auth::Auth* auth;
	firebase::App* app;

	Authentication(FirebaseManager *fbManager, DataManager *dbManager);
	~Authentication();

	void createAndRegisterAccount(Account *acc, std::string emailO, std::string passwordO);

	void signInUser(Account *acc, std::string emailO, std::string passwordO);
};