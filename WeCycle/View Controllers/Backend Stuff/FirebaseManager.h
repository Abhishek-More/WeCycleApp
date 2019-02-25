#pragma once
#include <firebase/app.h>
#include <firebase/database.h>
#include <json.hpp>

class FirebaseManager
{
private:
	firebase::AppOptions appOptions;
	firebase::App *app;
	std::map<std::string, std::string> parseJSONfromFile(const char* filename);
	void loadFirebaseJSON(const char* parsedFile, firebase::AppOptions *appOptions);

public:
	FirebaseManager(const char* filename);
	FirebaseManager();
	~FirebaseManager(); //Called at the object's termination

	firebase::AppOptions getAppOptions();
	void setAppOptions(const char* filename);
	firebase::App* getApp();
};

