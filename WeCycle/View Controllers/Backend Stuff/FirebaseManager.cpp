#include "FirebaseManager.h"
#include <iostream>
#include <fstream> 
#include <firebase\app.h>


FirebaseManager::FirebaseManager(const char* filename) {
	//Initializing firebase app
	firebase::AppOptions *appOps = &appOptions;
	loadFirebaseJSON(filename, appOps);
	app = firebase::App::Create(appOptions);
	std::cout << "Firebase manager successfully built" << std::endl;
}

FirebaseManager::FirebaseManager() {
	//Initializing firebase app
	firebase::AppOptions *appOps = &appOptions;
	loadFirebaseJSON("C:/Users/Kim/Desktop/WeCycle/google-services.json", appOps);
	app = firebase::App::Create(appOptions);
	std::cout << "Firebase manager successfully built" << std::endl;
}

//Called at the object's termination
FirebaseManager::~FirebaseManager() {}

std::map<std::string, std::string> FirebaseManager::parseJSONfromFile(const char* filename) {
	std::map<std::string, std::string> result;
	std::ifstream ifs(filename);
	nlohmann::json j;
	ifs >> j;
	try {
		result["api_key"] = j["client"][0]["api_key"][0].value("current_key", "NULL");
		result["app_id"] = j["client"][0]["client_info"].value("mobilesdk_app_id", "NULL");
		result["database_url"] = j.at("project_info").value("firebase_url", "NULL");
		result["project_id"] = j.at("project_info").value("project_id", "NULL");
		result["storage_bucket"] = j.at("project_info").value("storage_bucket", "NULL");
	}
	catch (nlohmann::json::out_of_range &e) {
		std::cout << e.what();
	}
	catch (nlohmann::json::type_error &te) {
		std::cout << te.what();
	}
	return result;
}

void FirebaseManager::loadFirebaseJSON(const char * filename, firebase::AppOptions *appOptions) {

	std::map<std::string, std::string> jsonMap = FirebaseManager::parseJSONfromFile(filename);
	for (auto const& item : jsonMap) {
		std::string key = item.first;
		std::string value = item.second;

		if (key == "api_key") {
			appOptions->set_api_key(value.c_str());
		}
		else if (key == "app_id") {
			appOptions->set_app_id(value.c_str());
		}
		else if (key == "database_url") {
			appOptions->set_database_url(value.c_str());
		}
		else if (key == "project_id") {
			appOptions->set_project_id(value.c_str());
		}
		else if (key == "storage_bucket") {
			appOptions->set_storage_bucket(value.c_str());
		}
		else {
			return;
		}

	}
}

void FirebaseManager::setAppOptions(const char* filename) {
	firebase::AppOptions *appOps = &appOptions;
	loadFirebaseJSON(filename, appOps);
	app = firebase::App::Create(appOptions);
}

firebase::AppOptions FirebaseManager::getAppOptions() {
	return appOptions;
}

firebase::App* FirebaseManager::getApp() {
	return app;
}