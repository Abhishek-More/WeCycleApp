// WeCycle.cpp : Defines the entry point for the application.
//

#include "WeCycle.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include "StorageManager.h"
#include <iostream>
#include "Account.h"
#include "json.hpp"
#include <fstream> 
#include "Authentication.h"
#include "Crypto.h"

//using stringMap = std::map<std::string, firebase::Variant>;

int main() {

	const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json"; //Desktop
	//const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle/google-services.json"; //Laptop


	FirebaseManager *fbManager = new FirebaseManager(filename);
	DataManager *dataManager = new DataManager(fbManager);
	StorageManager storageManager(fbManager);
//	Account *acc = new Account("C@droptablecom", "passwordE");
	//Authentication auth(fbManager);
	//auth.createAndRegisterAccount(acc);

	//const std::string link = storageManager.uploadImageRetreiveLink("C:/Users/Kim/Desktop/image.jpg");
	//std::cout << link << std::endl;
	/*
	dataManager.pushData(acc, "Account");

	const char **dataRetrived = dataManager.retrieveData("Account", "C@droptablecom");

	for (size_t i = 0; i < 2; i++)
	{
		std::cout << dataRetrived[i] << std::endl;
	}
	*/
	
	Crypto *c = new Crypto(dataManager);
	std::string s = c->hashSHAKE128("password");
	std::cout << s << std::endl;

	std::cout << c->verifySHAKE128("password", s) << std::endl;
	
	//delete c;
	//delete acc;
	delete fbManager;
	//delete push;
	//delete push1;

//	system("pause");

	return 0;
}
