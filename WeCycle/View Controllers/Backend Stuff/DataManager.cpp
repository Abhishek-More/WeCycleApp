#include "DataManager.h"
#include <iostream>
#include <firebase\app.h>
#include <firebase\variant.h>

//TODO: ADD AUTHENTICATION TO FIREBASE


DataManager::DataManager(FirebaseManager *fbManager) {
	//Initializing firebase database and reference
	database = firebase::database::Database::GetInstance(fbManager->getApp());
	dbref = database->GetReference();

	bool checkIfBuiltCorrectly;//TODO: Check if the data manager is successfully built
	std::cout << "Data manager successfully built" << std::endl;
}

//Called at the object's termination
DataManager::~DataManager() {
	delete database;
}

void DataManager::pushData(PushableObject *objectToPass, std::string parent) {
	
	std::string key = dbref.Child(parent).PushChild().key_string();
	objectToPass->setKey(key);
	//Accounts: multiple for loops that access each data point.
	for (auto &x : objectToPass->dataMap()) {
		std::string firstKey = x.first;
		if (x.second.vector().size() > 0) {
			for (auto &y : x.second.vector()) {
				for (auto &z : y.map()) {
					std::string keys = z.first.string_value();
					firebase::Variant values = z.second;
					dbref.Child(parent).Child(firstKey).Child(keys).SetValue(values);
				}
			}
		}
		else {
			firebase::Variant value = x.second;
			dbref.Child(parent).Child(firstKey).SetValue(value);
		}
	}

	std::cout << "Push Successful" << std::endl; //TODO: LOOK AT FIREBASE DOCUMENTATION FOR CHECKING
}

const char **DataManager::retrieveData(std::string parent, std::string key) {

	const char **resultArray = nullptr;

	firebase::Future<firebase::database::DataSnapshot> result = dbref.Child(parent).Child(key).GetValue();

		while (result.status() != firebase::kFutureStatusComplete) {} //Loop to wait until retrieval is complete
		if (result.error() == firebase::database::kErrorNone) {
			std::cout << "Retrival Complete" << std::endl;

			std::vector<firebase::database::DataSnapshot> childList = result.result()->children();

			unsigned int heightMax = childList.size();
			resultArray = new const char*[heightMax];

			int counter = 0;
			for (auto &values : childList) { //Iterate through the vector of STRING VALUE
				resultArray[counter] = strdup(values.value().string_value());  //strdup makes sure our char in the memory stays in the memory even when out of scope by creating a duplicate char array (string
				counter++;
			}
		} 
		else {
			std::cout << "Error Retrieving Data" << std::endl;
		}

	return resultArray;
}

firebase::database::DatabaseReference DataManager::getDBref() {
	return dbref;
}

