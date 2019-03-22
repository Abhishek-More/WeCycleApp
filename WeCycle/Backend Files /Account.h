#pragma once
#include <iostream>
#include "DataManager.h"
#include "PushableObject.h"
#include "AccountValueListener.h"
#include <firebase/auth.h>
#include <firebase/future.h>


using stringMap = std::map<std::string, std::string>;
using uIntMap = std::map<std::string, unsigned int>;
using VariantMap = std::map<firebase::Variant, firebase::Variant>;


class Account : public PushableObject
{
private:

	std::string uid;
	long phoneNumber;
	std::string rank;
	int experience;
	int coins;
	std::string profilePicLink;
	std::string display_name;
	int numberOfScans;
	std::vector<std::map<firebase::Variant, firebase::Variant>> dataList;
	DataManager *dbm;
	bool checkXPforRank();
	bool checkAccount;

public:
	Account(DataManager *dbm);
	Account(DataManager *dbm, std::string uid);
	Account(DataManager *dbm, std::string rank, unsigned int experience, unsigned int coins, std::string profilePicLink, std::string uid);
	Account(DataManager *dbm, std::vector<firebase::Variant> dataList, std::string uid);
	//TODO add intialize override function and addData function

	~Account();

	bool checkAccountA() const;
	const char* rankA() const;
	int experienceA() const;
	int coinsA() const;
	const char* profilePicLinkA() const;
	const char* displaynameA() const;
	int numberOfScansA() const;
	std::string uidA() const;

	void registerAccountListener();

	void updateCheckAccount(bool res);
	void createNewAccount(std::string uID);
	void updateUID(std::string uID);
	void updateDataList();
	void updateDataList(firebase::Variant object);
	void updateRank_override(const char* rank);
	void updateRank();
	void updateXP(int increment);
	void updateCoins(int incremenet);
	void updatePFP(std::string link);
	void updateDisplayName(std::string displayName);
	void updateScans(int increment);
};
