// WeCycle.cpp : Defines the entry point for the application.
//
#ifdef _WIN32

#include "WeCycle.h"
#include "DataManager.h"
#include "FirebaseManager.h"
#include "StorageManager.h"
#include <iostream>
#include "Account.h"
#include <json.hpp>
#include <fstream> 
#include "Authentication.h"
#include "Crypto.h"
#include "PlayerAchievements.h"

//using variantMap = std::map<firebase::Variant, firebase::Variant>;

int main() {

	const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json"; //Desktop
	//const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle/google-services.json"; //Laptop
	FirebaseManager *fbManager = new FirebaseManager(filename);
	DataManager *dataManager = new DataManager(fbManager);

	
	/*
	PushableObject FirstScan;
	PushableObject *objPtr1 = &FirstScan;
	std::vector<variantMap> ach1List;
	variantMap name1;
	name1.insert(std::pair<firebase::Variant, firebase::Variant>("Name", "First Scan!"));
	variantMap iconLink1;
	iconLink1.insert(std::pair<firebase::Variant, firebase::Variant>("Icon Link", ""));
	variantMap coinVal1;
	coinVal1.insert(std::pair<firebase::Variant, firebase::Variant>("Coin Value", 100));

	ach1List.push_back(name1);
	ach1List.push_back(iconLink1);
	ach1List.push_back(coinVal1);

	variantMap map1;
	map1.insert(std::pair<firebase::Variant, firebase::Variant>("ID", ach1List));
	FirstScan.initialize(map1);

	dataManager->pushData(objPtr1, "Achievements");
	*/
	
	Authentication auth(fbManager, dataManager);
	Account acc(dataManager);
	auth.signInUser(&acc, "user@gmail.com", "password");
	//auth.createAndRegisterAccount(&acc, "asdasda@gmail.com", "oasswir");
	//auth.updateUserProfile(&acc, "https://firebasestorage.googleapis.com/v0/b/wecycle-316c1.appspot.com/o/Gial_Ackbar_Resistance.jpg?alt=media&token=1059357a-f84f-4185-a798-7f6c7b730778"
	//,"Jkim");
	//firebase::Variant v;
	//dataManager->retrieveData("Account Info", "hVjfDAEucXgzMj2pgDBHfJk6hpr2", v);
	//PlayerAchievements pA(dataManager, "hVjfDAEucXgzMj2pgDBHfJk6hpr2");
	//pA.addAchievement(&acc, "ID");
	
	acc.updateXP(100);

	//delete fbManager;
	//delete dataManager;

	system("pause");

	return 0;
}
#endif // _WIN32