// WeCycle.cpp : Defines the entry point for the application.
//

#include "WeCycle.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include "StorageManager.h"
#include <iostream>
#include "Account.h"
#include <json.hpp>
#include <fstream> 

using stringMap = std::map<std::string, std::string>;
/*
int main() {

	const char *filename = "google-services.json"; //Desktop
	//const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle/google-services.json"; //Laptop


	FirebaseManager *fbManager = new FirebaseManager(filename);
	DataManager dataManager(fbManager);
	StorageManager storageManager(fbManager);
	Account *acc = new Account("C@droptablecom", "passwordE");
	dataManager.pushData(acc, "Accounts");

	const std::string link = storageManager.uploadImageRetreiveLink("C:/Users/Kim/Desktop/image.jpg");
	std::cout << link << std::endl;

	const char **dataRetrived = dataManager.retrieveData("Accounts", "C@droptablecom");

	for (size_t i = 0; i < 2; i++)
	{
		std::cout << dataRetrived[i] << std::endl;
	}

	system("pause");

	return 0;
}
*/