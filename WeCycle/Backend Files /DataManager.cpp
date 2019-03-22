#include "DataManager.h"
#include <iostream>
#include <firebase/app.h>
#include <firebase/variant.h>
#include <ctime>

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
	//delete database;
}

void DataManager::pushData(PushableObject *objectToPass) {

	for (auto &x : objectToPass->dataMap()) {
		firebase::Variant firstKey = x.first;
		if (x.second.is_vector()) {
			std::string firstK = firstKey.mutable_string();
			try {
				firebase::Future<void> future = dbref.Child(firstK).SetValue(x.second);
				future.OnCompletion([](const firebase::Future<void>& future, void* user_data) {
					if (future.error() == 0) {
						std::cout << "Push Successful" << std::endl;
					}
					else {
						std::cout << "Push Failed" << future.error_message() << std::endl;
					}
				}, nullptr);
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		else {
			firebase::Variant value = x.second;
			firebase::Future<void> future = dbref.Child(firstKey.mutable_string()).SetValue(value);
			future.OnCompletion([](const firebase::Future<void>& future, void* user_data) {
				if (future.error() == 0) {
					std::cout << "Push Successful" << std::endl;
				}
				else {
					std::cout << "Push Failed" << future.error_message() << std::endl;
				}
			}, nullptr);
		}
	}

}

void DataManager::pushData(PushableObject *objectToPass, std::string parent) {
	
	for (auto &x : objectToPass->dataMap()) {
		firebase::Variant firstKey = x.first;
		if (x.second.is_vector()) {
			std::string firstK = firstKey.mutable_string();
			try {
				firebase::Future<void> future = dbref.Child(parent).Child(firstK).SetValue(x.second);
				future.OnCompletion([](const firebase::Future<void>& future, void* user_data) {
					if (future.error() == 0) {
						std::cout << "Push Successful" << std::endl;
					}
					else {
						std::cout << "Push Failed" << future.error_message() << std::endl;
					}
				}, nullptr);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		else {
			firebase::Variant value = x.second;
			firebase::Future<void> future = dbref.Child(parent).Child(firstKey.mutable_string()).SetValue(value);
			future.OnCompletion([](const firebase::Future<void>& future, void* user_data) {
				if (future.error() == 0) {
					std::cout << "Push Successful" << std::endl;
				}
				else {
					std::cout << "Push Failed" << future.error_message() << std::endl;
				}
			}, nullptr);
		}
	}

}

void DataManager::pushData(PushableObject *objectToPass, std::string parent, std::string child) {

	for (auto &x : objectToPass->dataMap()) {
		firebase::Variant firstKey = child;
		if (x.second.is_vector()) {
			std::string firstK = firstKey.mutable_string();
			try {
				firebase::Future<void> future = dbref.Child(parent).Child(firstK).SetValue(x.second);
				future.OnCompletion([](const firebase::Future<void>& future, void* user_data) {
					if (future.error() == 0) {
						std::cout << "Push Successful" << std::endl;
					}
					else {
						std::cout << "Push Failed" << future.error_message() << std::endl;
					}
				}, nullptr);
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			
		}
		else {
			firebase::Variant value = x.second;
			firebase::Future<void> future = dbref.Child(parent).Child(firstKey.mutable_string()).SetValue(value);
			future.OnCompletion([](const firebase::Future<void>& future, void* user_data) {
				if (future.error() == 0) {
					std::cout << "Push Successful" << std::endl;
				}
				else {
					std::cout << "Push Failed" << future.error_message() << std::endl;
				}
			}, nullptr);
		}
	}

}

void DataManager::updateData(firebase::Variant objectToPass, std::string parent, std::string child) {//Object isnt of type map

}
void DataManager::updateData(firebase::Variant objectToPass, std::string parent) { //Object isnt of type map

}
void DataManager::updateData(firebase::Variant objectToPass) { //Object is of type map
	firebase::Future<void> future = dbref.UpdateChildren(objectToPass);
	future.OnCompletion([](const firebase::Future<void>& future, void* user_data) {
		if (future.error() == 0) {
			printf("Updated!");
		}
		else {
			printf("Failed to update: ");
			printf(future.error_message());
		}
	}, nullptr);
}


firebase::Variant retrieveData_thread(firebase::Future<firebase::database::DataSnapshot> result, firebase::Variant object) {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	firebase::Variant variant;

	if (result.status() == firebase::kFutureStatusComplete) {
		if (result.error() == firebase::database::kErrorNone) {
			std::cout << "Retrival Complete" << std::endl;
			firebase::Variant childList = result.result()->value();
			std::cout << childList.is_vector() << std::endl;
			if (childList.is_vector()) {
				variant = childList.vector();
			}
		}
		else {
			std::cout << "Error Retrieving Data" << std::endl;
		}
	}
	/*
	result.OnCompletion([](const firebase::Future<firebase::database::DataSnapshot>& result, void* user_data) {
		firebase::Variant *ob = static_cast<firebase::Variant*>(user_data);
		firebase::Variant childList;
		if (result.error() == firebase::database::kErrorNone) {
			std::cout << "Retrival Complete" << std::endl;
			childList = result.result()->value();
			std::cout << childList.is_vector() << std::endl;
			if (childList.is_vector()) {
				ob = &childList;
			}
		}
		else {
			std::cout << "Error Retrieving Data" << std::endl;
		}
		std::cout << "Retrival CompleteXXXX" << std::endl;
		ob = &childList;
	}, &variant);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << variant.is_vector() << std::endl;
	*/
	return variant;
}

void DataManager::retrieveData(std::string parent, firebase::Variant &object) {
	firebase::Future<firebase::database::DataSnapshot> result = dbref.Child(parent).GetValue();
	result.OnCompletion([](const firebase::Future<firebase::database::DataSnapshot>& result, void* user_data) {
		firebase::Variant *ob = static_cast<firebase::Variant*>(user_data);
		firebase::Variant childList;
		if (result.error() == firebase::database::kErrorNone) {
			std::cout << "Retrival Complete" << std::endl;
			childList = result.result()->value();
			std::cout << childList.is_vector() << std::endl;
			if (childList.is_vector()) {
				ob = &childList;
			}
		}
		else {
			std::cout << "Error Retrieving Data" << std::endl;
		}
	}, &object);
	/*
	result.OnCompletion([](const firebase::Future<firebase::database::DataSnapshot>& result, void* user_data) {
		firebase::Variant ob = static_cast<firebase::Variant*>(user_data);
		if (result.error() == firebase::database::kErrorNone) {
			std::cout << "Retrival Complete" << std::endl;

			std::vector<firebase::database::DataSnapshot> childList = result.result()->children();
			std::vector<firebase::Variant> variantList;
			int counter = 0;
			for (auto &values : childList) { //Iterate through the vector of STRING VALUE
				firebase::Variant value = values.value();
				if (value.is_mutable_string()) {
					variantList[counter] = value.mutable_string();
				}
				else if (value.is_int64()) {
					variantList[counter] = value.int64_value();
				}
				else if (value.is_bool()) {
					variantList[counter] = value.bool_value();
				}
				else if (value.is_map()) {
					variantList[counter] = value.map();
				}
				counter++;
			}
			ob = &variantList;
		}
		else {
			std::cout << "Error Retrieving Data" << std::endl;
		}
	}, ob);
	*/
}


void DataManager::retrieveData(std::string parent, std::string key, firebase::Variant &object) {

	firebase::Future<firebase::database::DataSnapshot> result = dbref.Child(parent).Child(key).GetValue();
	result.OnCompletion([](const firebase::Future<firebase::database::DataSnapshot>& result, void* user_data) {
		firebase::Variant *ob = static_cast<firebase::Variant*>(user_data);
		firebase::Variant childList;
		if (result.error() == firebase::database::kErrorNone) {
			std::cout << "Retrival Complete" << std::endl;
			childList = result.result()->value();
			std::cout << childList.is_vector() << std::endl;
			if (childList.is_vector()) {
				ob = &childList;
			}
		}
		else {
			std::cout << "Error Retrieving Data" << std::endl;
		}
	}, &object);
}

firebase::database::DatabaseReference DataManager::getDBref() {
	return dbref;
}

