#pragma once
#include "Account.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include <iostream>
#include <firebase/auth.h>
#include <firebase/future.h>
#include <firebase/database/listener.h>
#include <firebase/database/data_snapshot.h>
#include <firebase/database/query.h>
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

	const char *getUID(const char* email);

	class EmailsValueListener : public firebase::database::ValueListener {
		firebase::Variant *object;
	public:
		EmailsValueListener(firebase::Variant *obj) {
			object = obj;
		}
		void OnValueChanged(const firebase::database::DataSnapshot &snapshot) override {
			firebase::Variant obj = snapshot.value();
			if (obj.is_mutable_string()) {
				object->set_mutable_string(obj.mutable_string());
				printf("Done454545\n");
			}
		}
		void OnCancelled(const firebase::database::Error& error_code,
						 const char* error_message) override {
			printf("ERROR: LeadersValueListener canceled: %d: %s", error_code,
				   error_message);
		}
	};
};
