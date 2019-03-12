#include "Account.h"

Account::Account() {
	this->rank = "";
	this->experience = 0;
	this->coins = 0;
	this->profilePicLink = "";
	this->uid = "";

	VariantMap rankMap;
	rankMap.insert(std::pair<firebase::Variant, firebase::Variant>("Rank", this->rank));
	VariantMap experienceMap;
	experienceMap.insert(std::pair<firebase::Variant, firebase::Variant>("Experience", this->experience));
	VariantMap coinMap;
	coinMap.insert(std::pair<firebase::Variant, firebase::Variant>("Coins", this->coins));
	VariantMap profilePicMap;
	profilePicMap.insert(std::pair<firebase::Variant, firebase::Variant>("PFP Link", this->profilePicLink));

	dataList.push_back(profilePicMap);
	dataList.push_back(coinMap);
	dataList.push_back(experienceMap);
	dataList.push_back(rankMap);

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));

	this->initialize(accountMap);
}

Account::Account(std::string uid) {
	this->rank = "";
	this->experience = 0;
	this->coins = 0;
	this->profilePicLink = "";
	this->uid = uid;

	VariantMap rankMap;
	rankMap.insert(std::pair<firebase::Variant, firebase::Variant>("Rank", this->rank));
	VariantMap experienceMap;
	experienceMap.insert(std::pair<firebase::Variant, firebase::Variant>("Experience", this->experience));
	VariantMap coinMap;
	coinMap.insert(std::pair<firebase::Variant, firebase::Variant>("Coins", this->coins));
	VariantMap profilePicMap;
	profilePicMap.insert(std::pair<firebase::Variant, firebase::Variant>("PFP Link", this->profilePicLink));

	dataList.push_back(profilePicMap);
	dataList.push_back(coinMap);
	dataList.push_back(experienceMap);
	dataList.push_back(rankMap);

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));

	this->initialize(accountMap);
}

Account::Account(std::string rank, unsigned int experience, unsigned int coins, std::string profilePicLink, std::string uid) {
	this->rank = rank;
	this->experience = experience;
	this->coins = coins;
	this->profilePicLink = profilePicLink;
	this->uid = uid;

	VariantMap rankMap;
	rankMap.insert(std::pair<std::string, std::string>("Rank", this->rank)); 
	VariantMap experienceMap;
	experienceMap.insert(std::pair<std::string, firebase::Variant>("Experience", this->experience));
	VariantMap coinMap;
	coinMap.insert(std::pair<std::string, firebase::Variant>("Coins", this->coins));
	VariantMap profilePicMap;
	profilePicMap.insert(std::pair<std::string, std::string>("PFP Link", this->profilePicLink));

	dataList.push_back(profilePicMap);
	dataList.push_back(coinMap);
	dataList.push_back(experienceMap);
	dataList.push_back(rankMap);

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));

	this->initialize(accountMap);
}

Account::Account(std::vector<firebase::Variant> dataList, std::string uid) {
	int count = 0;
	for (auto &x : dataList) {
		if (x.is_map()) {
			for (auto &y : x.map()) {
				this->dataList.at(count) = x.map();
			}
		}
		count++;
	}
	this->rank = this->dataList[0].find("Rank")->second.mutable_string();
	this->experience = this->dataList[1].find("Experience")->second.int64_value();
	this->coins = this->dataList[2].find("Coins")->second.int64_value();
	this->profilePicLink = this->dataList[3].find("PFP Link")->second.mutable_string();
	this->uid = uid;

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));

	this->initialize(accountMap);
}

Account::~Account() {
}

void Account::updateRank(DataManager *dbm) {
	firebase::Variant rankList;
	dbm->retrieveData("Ranks", rankList);

	if (rankList.is_vector()) {
		std::vector<firebase::Variant> list = rankList.vector();
		int i = 0;
		while (list.at(i).is_map()) {
			std::map<firebase::Variant, firebase::Variant> currentMap = list.at(i).map();
			for (auto &x : currentMap) {
				if (x.first == this->rank) {
					for (auto &y : list.at(i + 1).map()) {
						this->rank = y.first.mutable_string();
						VariantMap rankMap;
						rankMap.insert(std::pair<std::string, std::string>("Rank", this->rank));
						this->dataList.at(0) = rankMap; //0 is rank position
						return;
					}
				}
			}
			i++;
		}
	}

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));
	this->initialize(accountMap);
	dbm->pushData(this, "Account Info");

}
void Account::updateXP(int increment, DataManager *dbm) {
	this->experience += increment;
	VariantMap experienceMap;
	experienceMap.insert(std::pair<std::string, firebase::Variant>("Experience", this->experience));
	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));
	this->initialize(accountMap);
	dbm->pushData(this, "Account Info");

	firebase::Variant rankList;
	dbm->retrieveData("Ranks", rankList);

	if(checkXPforRank(dbm)){
		updateRank(dbm);
	}

}
void Account::updateCoins(int incremenet, DataManager *dbm) {
	firebase::Variant accInfo;
	dbm->retrieveData("Account Info", this->uid, accInfo);
	if (accInfo.is_vector()) {
		int currCoinCount = accInfo.vector()[2].int64_value();
		currCoinCount += incremenet;
		this->coins = currCoinCount;
		std::map<firebase::Variant, firebase::Variant> accountMap;
		accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));
		this->initialize(accountMap);
		dbm->pushData(this, "Account Info");
	}
}
void Account::updatePFP(std::string link, DataManager *dbm) {

}

bool Account::checkXPforRank(DataManager *dbm) {
	firebase::Variant rankList;
	dbm->retrieveData("Ranks", rankList);
	bool result = false;
	if (rankList.is_vector()) {
		std::vector<firebase::Variant> list = rankList.vector();
		int i = 0;
		while (list.at(i).is_map()) {
			std::map<firebase::Variant, firebase::Variant> currentMap = list.at(i).map();
			for (auto &x : currentMap) {
				if (x.first == this->rank) {
					for (auto &y : list.at(i + 1).map()) {
						result = y.second <= this->experience;
					}
				}
			}
			i++;
		}
	}
	return result;
}