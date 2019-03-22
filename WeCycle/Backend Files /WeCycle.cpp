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

using variantMap = std::map<firebase::Variant, firebase::Variant>;

int main() {

	const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json"; //Desktop
	//const char *filename = "C:/Users/johnk/Desktop/WeCycle/WeCycle/google-services.json"; //Laptop
	FirebaseManager *fbManager = new FirebaseManager(filename);
	DataManager *dataManager = new DataManager(fbManager);
	
	/*
	PushableObject FirstRank;
	std::vector<variantMap> rank1List;
	variantMap name1;
	name1.insert(std::pair<firebase::Variant, firebase::Variant>("Junior Environmentalist", 500));
	variantMap name2;
	name2.insert(std::pair<firebase::Variant, firebase::Variant>("Environmentalist", 1500));
	variantMap name3;
	name3.insert(std::pair<firebase::Variant, firebase::Variant>("EPA Agent", 5000));

	rank1List.push_back(name1);
	rank1List.push_back(name2);
	rank1List.push_back(name3);

	variantMap map1;
	map1.insert(std::pair<firebase::Variant, firebase::Variant>("Ranks", rank1List));
	FirstRank.initialize(map1);

	dataManager->pushData(&FirstRank);
	*/
	
	Authentication auth(fbManager, dataManager);
	Account acc(dataManager);
	auth.signInUser(&acc, "asdasda@gmail.com", "password");

	//StorageManager *storageManager = new StorageManager(fbManager, &acc);
	//const char* k = storageManager->uploadImageRetreiveLink("C:/Users/Kim/Desktop/Gial_Ackbar_Resistance.jpg");

	//auth.createAndRegisterAccount(&acc, "asdasda@gmail.com", "oasswir");
	//auth.updateUserProfile(&acc, "https://firebasestorage.googleapis.com/v0/b/wecycle-316c1.appspot.com/o/Gial_Ackbar_Resistance.jpg?alt=media&token=1059357a-f84f-4185-a798-7f6c7b730778"
	//,"Jkim");
	//firebase::Variant v;
	//dataManager->retrieveData("Account Info", "hVjfDAEucXgzMj2pgDBHfJk6hpr2", v);
	//PlayerAchievements pA(dataManager, "hVjfDAEucXgzMj2pgDBHfJk6hpr2");
	//pA.addAchievement(&acc, "ID");
	//acc.addFriend("gtAkbdcSI4bizRSkhNPY4cl92dQ2");
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	acc.addFriend("Y2XgzWR21QWSENQCG22CfLogckT2");
	//const char **k = acc.requestListA();
	//acc.addRequestFriend();
	//acc.addRequestFriend("hVjfDAEucXgzMj2pgDBHfJk6hpr2");
	//acc.addFriend("BpaLWSoXUYR1Os0Yq9tsE4TqChj2");
	//delete fbManager;
	//delete dataManager;
	
	system("pause");

	return 0;
}
#endif // _WIN32