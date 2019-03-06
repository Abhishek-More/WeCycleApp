#pragma once
#include <firebase/app.h>
#include <firebase/future.h>
#include <firebase/database.h>
#include "Account.h"
#include "PushableObject.h"
#include "FirebaseManager.h"

//TODO: ADD AUTHENTICATION TO FIREBASE

using stringMap = std::map<std::string, std::string>;

class DataManager
{
private:

	firebase::database::Database *database;
	firebase::database::DatabaseReference dbref;

public:
	DataManager(FirebaseManager *fbManager);
	~DataManager(); //Called at the object's termination

	void pushData(PushableObject *objectToPass, std::string parent);
	const char **retrieveData(std::string parent, std::string key);
	firebase::database::DatabaseReference getDBref();

};

