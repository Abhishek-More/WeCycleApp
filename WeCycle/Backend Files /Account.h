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
	std::string email;

	std::vector<firebase::Variant> friendsList;
	std::vector<firebase::Variant> friendsListPending;
	std::vector<firebase::Variant> friendsListRequests;


public:
	Account(DataManager *dbm);
	Account(DataManager *dbm, std::string uid);
	Account(DataManager *dbm, std::string rank, unsigned int experience, unsigned int coins, std::string profilePicLink, std::string uid);
	Account(DataManager *dbm, std::vector<firebase::Variant> dataList, std::string uid);

	~Account();

	bool checkAccountA() const;
	const char* rankA() const;
	int experienceA() const;
	int coinsA() const;
	const char* profilePicLinkA() const;
	const char* displaynameA() const;
	int numberOfScansA() const;
	std::string uidA() const;
	const char **requestListA() const;
	const char **friendsListA() const;

	//Dont need wrappers
	void registerAccountListener();
	void registerFriendsListeners();
	void updateFriendsList(firebase::Variant object);
	void updateRequestFriendsList(firebase::Variant object);

	//Need wrappers
	void addFriend(std::string uid);
	void addRequestFriend(std::string id);

	//Need wrappers
	void updateCheckAccount(bool res);
	void createNewAccount(std::string uID);
	
	//Dont need wrappers
	void updateUID(std::string uID);
	void updateDataList();
	void updateDataList(firebase::Variant object);

	//Needs wrappers
	void updateRank_override(const char* rank);
	void updateRank();
	void updateXP(int increment);
	void updateCoins(int incremenet);
	void updatePFP(std::string link);
	void updateDisplayName(std::string displayName);
	void updateScans(int increment);
	void updateEmail(std::string email);

	//Dont need wrappers
	class FriendsRequestValueListener : public firebase::database::ValueListener {
		Account *acc;
	public:
		FriendsRequestValueListener(Account *account) {
			acc = account;
		}
		void OnValueChanged(const firebase::database::DataSnapshot &snapshot) override {
			firebase::Variant obj = snapshot.value();
			acc->updateRequestFriendsList(obj);
		}
		void OnCancelled(const firebase::database::Error& error_code,
						 const char* error_message) override {
			printf("ERROR: LeadersValueListener canceled: %d: %s", error_code,
				   error_message);
		}
	};
	class FriendsValueListener : public firebase::database::ValueListener {
		Account *acc;
	public:
		FriendsValueListener(Account *account) {
			acc = account;
		}
		void OnValueChanged(const firebase::database::DataSnapshot &snapshot) override {
			firebase::Variant obj = snapshot.value();
			acc->updateFriendsList(obj);
		}
		void OnCancelled(const firebase::database::Error& error_code,
						 const char* error_message) override {
			printf("ERROR: LeadersValueListener canceled: %d: %s", error_code,
				   error_message);
		}
	};
	class FriendsPendingValueListener : public firebase::database::ValueListener {
		firebase::Variant *object;
	public:
		FriendsPendingValueListener(firebase::Variant *obj) {
			object = obj;
		}
		void OnValueChanged(const firebase::database::DataSnapshot &snapshot) override {
			firebase::Variant obj = snapshot.value();
			if (obj.is_vector())
				object->set_vector(obj.vector());
			printf("Done232323232\n");
		}
		void OnCancelled(const firebase::database::Error& error_code,
						 const char* error_message) override {
			printf("ERROR: LeadersValueListener canceled: %d: %s", error_code,
				   error_message);
		}
	};
};
