#include "Account.h"

Account::Account(DataManager *dbm) {
	this->rank = "";
	this->experience = 0;
	this->coins = 0;
	this->profilePicLink = "";
	this->display_name = "";
	this->numberOfScans = 0;
	this->uid = "";
	this->dbm = dbm;
	this->checkAccount = false;

	VariantMap rankMap;
	rankMap.insert(std::pair<firebase::Variant, firebase::Variant>("Rank", this->rank));
	VariantMap experienceMap;
	experienceMap.insert(std::pair<firebase::Variant, firebase::Variant>("Experience", this->experience));
	VariantMap coinMap;
	coinMap.insert(std::pair<firebase::Variant, firebase::Variant>("Coins", this->coins));
	VariantMap profilePicMap;
	profilePicMap.insert(std::pair<firebase::Variant, firebase::Variant>("PFP Link", this->profilePicLink));
	VariantMap displayNameMap;
	displayNameMap.insert(std::pair<firebase::Variant, firebase::Variant>("Display Name", this->display_name));
	VariantMap numberOfScansMap;
	numberOfScansMap.insert(std::pair<firebase::Variant, firebase::Variant>("Number of Scans", this->numberOfScans));

	dataList.push_back(rankMap);
	dataList.push_back(experienceMap);
	dataList.push_back(coinMap);
	dataList.push_back(profilePicMap);
	dataList.push_back(displayNameMap);
	dataList.push_back(numberOfScansMap);

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));



	this->initialize(accountMap);
}

Account::Account(DataManager *dbm, std::string uid) {
	this->rank = "";
	this->experience = 0;
	this->coins = 0;
	this->profilePicLink = "";
	this->display_name = "";
	this->numberOfScans = 0;
	this->uid = uid;
	this->dbm = dbm;
	this->checkAccount = false;

	VariantMap rankMap;
	rankMap.insert(std::pair<firebase::Variant, firebase::Variant>("Rank", this->rank));
	VariantMap experienceMap;
	experienceMap.insert(std::pair<firebase::Variant, firebase::Variant>("Experience", this->experience));
	VariantMap coinMap;
	coinMap.insert(std::pair<firebase::Variant, firebase::Variant>("Coins", this->coins));
	VariantMap profilePicMap;
	profilePicMap.insert(std::pair<firebase::Variant, firebase::Variant>("PFP Link", this->profilePicLink));
	VariantMap displayNameMap;
	displayNameMap.insert(std::pair<firebase::Variant, firebase::Variant>("Display Name", this->display_name));
	VariantMap numberOfScansMap;
	numberOfScansMap.insert(std::pair<firebase::Variant, firebase::Variant>("Number of Scans", this->numberOfScans));

	dataList.push_back(rankMap);
	dataList.push_back(experienceMap);
	dataList.push_back(coinMap);
	dataList.push_back(profilePicMap);
	dataList.push_back(displayNameMap);
	dataList.push_back(numberOfScansMap);
	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));

	this->initialize(accountMap);
}

Account::Account(DataManager *dbm, std::string rank, unsigned int experience, unsigned int coins, std::string profilePicLink, std::string uid) {
	this->rank = rank;
	this->experience = experience;
	this->coins = coins;
	this->profilePicLink = profilePicLink;
	this->display_name = "";
	this->numberOfScans = 0;
	this->uid = uid;
	this->dbm = dbm;
	this->checkAccount = false;

	VariantMap rankMap;
	rankMap.insert(std::pair<std::string, std::string>("Rank", this->rank)); 
	VariantMap experienceMap;
	experienceMap.insert(std::pair<std::string, firebase::Variant>("Experience", this->experience));
	VariantMap coinMap;
	coinMap.insert(std::pair<std::string, firebase::Variant>("Coins", this->coins));
	VariantMap profilePicMap;
	profilePicMap.insert(std::pair<std::string, std::string>("PFP Link", this->profilePicLink));
	VariantMap displayNameMap;
	displayNameMap.insert(std::pair<firebase::Variant, firebase::Variant>("Display Name", this->display_name));
	VariantMap numberOfScansMap;
	numberOfScansMap.insert(std::pair<firebase::Variant, firebase::Variant>("Number of Scans", this->numberOfScans));

	dataList.push_back(rankMap);
	dataList.push_back(experienceMap);
	dataList.push_back(coinMap);
	dataList.push_back(profilePicMap);
	dataList.push_back(displayNameMap);
	dataList.push_back(numberOfScansMap);

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));

	this->initialize(accountMap);
}

Account::Account(DataManager *dbm, std::vector<firebase::Variant> dataList, std::string uid) {
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
	this->display_name = this->dataList[4].find("Display Name")->second.mutable_string();
	this->numberOfScans = this->dataList[5].find("Number of Scans")->second.int64_value();
	this->uid = uid;
	this->dbm = dbm;
	this->checkAccount = false;

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));

	this->initialize(accountMap);
}

Account::~Account() {
}

bool Account::checkAccountA() const {
	return this->checkAccount;
}
const char* Account::rankA() const {
	return this->rank.c_str();
}
int Account::experienceA() const {
	return this->experience;
}
int Account::coinsA() const {
	return this->coins;
}
const char* Account::profilePicLinkA() const {
	return this->profilePicLink.c_str();
}
const char* Account::displaynameA() const {
	return this->display_name.c_str();
}
int Account::numberOfScansA() const {
	return this->numberOfScans;
}
std::string Account::uidA() const {
	return this->uid;
}


void Account::updateCheckAccount(bool res) {
	this->checkAccount = res;
}
void Account::createNewAccount(std::string uID) {
	this->uid = uID;
	this->dbm->pushData(this, "Account Info", uID);
	registerAccountListener();
}
void Account::registerAccountListener() {
	AccountValueListener *listener = new AccountValueListener(this);
	this->dbm->getDBref().Child("Account Info").Child(this->uid).AddValueListener(listener);
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}
void Account::updateUID(std::string uID) {
	this->uid = uID;
}
void Account::updateDataList() { //UID MUST BE ALREADY INTIALIZED IN ORDER FOR THIS TO WORK
	firebase::Variant dataList;
	dbm->retrieveData("Account Info", this->uid, dataList);
	if (dataList.is_vector()) {
		int count = 0;
		for (auto &x : dataList.vector()) {
			if (x.is_map()) {
				for (auto &y : x.map()) {
					this->dataList.at(count) = x.map();
				}
			}	
			count++;
		}
	}
	this->rank = this->dataList[0].find("Rank")->second.mutable_string();
	this->experience = this->dataList[1].find("Experience")->second.int64_value();
	this->coins = this->dataList[2].find("Coins")->second.int64_value();
	this->profilePicLink = this->dataList[3].find("PFP Link")->second.mutable_string();
	this->display_name = this->dataList[4].find("Display Name")->second.mutable_string();
	this->numberOfScans = this->dataList[5].find("Number of Scans")->second.int64_value();

	if (this->uid == "") {
		return;
	}

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));

	this->initialize(accountMap);
}//UID MUST BE ALREADY INTIALIZED IN ORDER FOR THIS TO WORK
void Account::updateDataList(firebase::Variant object) { 
	firebase::Variant dataList = object;
	if (dataList.is_vector()) {
		int count = 0;
		for (auto &x : dataList.vector()) {
			if (x.is_map()) {
				for (auto &y : x.map()) {
					this->dataList.at(count) = x.map();
				}
			}
			count++;
		}
	}
	this->rank = this->dataList[0].find("Rank")->second.mutable_string();
	this->experience = this->dataList[1].find("Experience")->second.int64_value();
	this->coins = this->dataList[2].find("Coins")->second.int64_value();
	this->profilePicLink = this->dataList[3].find("PFP Link")->second.mutable_string();
	this->display_name = this->dataList[4].find("Display Name")->second.mutable_string();
	this->numberOfScans = this->dataList[5].find("Number of Scans")->second.int64_value();

	if (this->uid == "") {
		return;
	}

	std::map<firebase::Variant, firebase::Variant> accountMap;
	accountMap.insert(std::pair<firebase::Variant, firebase::Variant>(this->uid, dataList));

	this->initialize(accountMap);
}

void Account::updateRank_override(const char* rank) {
	this->rank = rank;
	VariantMap rankMap;
	std::string path = "/Account Info/" + this->uid + "/0/Rank";
	rankMap.insert(std::pair<std::string, std::string>(path, this->rank));
	this->dataList.at(0) = rankMap; //0 is rank position
	dbm->updateData(rankMap);
}

void Account::updateRank() {
	firebase::Variant rankList;
	dbm->retrieveData("Ranks", rankList);

	if (rankList.is_vector()) {
		std::vector<firebase::Variant> list = rankList.vector();
		for (int i = 0; i < list.size(); i++) {
			if (i != list.size()) {
				std::map<firebase::Variant, firebase::Variant> currentMap = list.at(i).map();
				for (auto &x : currentMap) {
					if (x.first == this->rank) {
						for (auto &y : list.at(i + 1).map()) {
							this->rank = y.first.mutable_string();
							VariantMap rankMap;
							std::string path = "/Account Info/" + this->uid + "/0/Rank";
							rankMap.insert(std::pair<std::string, std::string>(path, this->rank));
							this->dataList.at(0) = rankMap; //0 is rank position
							dbm->updateData(rankMap);
							return;
						} //End of map iteration
					}
				} //End of map iteration
			} 
		} //End of list iteration
	}

}
void Account::updateXP(int increment) {
	this->experience += increment;
	VariantMap experienceMap;
	std::string path = "/Account Info/" + this->uid + "/1/Experience";
	experienceMap.insert(std::pair<std::string, firebase::Variant>(path, this->experience));
	dbm->updateData(experienceMap);
	firebase::Variant rankList;
	dbm->retrieveData("Ranks", rankList);

	if(checkXPforRank()){
		updateRank();
	}

}
void Account::updateCoins(int increment) {
	this->coins += increment;
	VariantMap coinMap;
	std::string path = "/Account Info/" + this->uid + "/2/Coins";
	coinMap.insert(std::pair<firebase::Variant, firebase::Variant>(path, this->coins));
	dataList.at(2) = coinMap;
	firebase::Variant variant(coinMap);
	dbm->updateData(variant);
}
void Account::updatePFP(std::string link) {
	this->profilePicLink = link;
	VariantMap profilePicMap;
	std::string path = "/Account Info/" + this->uid + "/3/PFP Link";
	profilePicMap.insert(std::pair<std::string, std::string>(path, this->profilePicLink));
	this->dataList.at(3) = profilePicMap;
	dbm->updateData(profilePicMap);
}

void Account::updateDisplayName(std::string displayName) {

	this->display_name = displayName;
	VariantMap displayNameMap;
	std::string path = "/Account Info/" + this->uid + "/4/Display Name";
	displayNameMap.insert(std::pair<firebase::Variant, firebase::Variant>(path, this->display_name));
	dataList.at(4) = displayNameMap;
	dbm->updateData(displayNameMap);
}

void Account::updateScans(int increment) {
	this->numberOfScans = increment;
	VariantMap scanMap;
	std::string path = "/Account Info/" + this->uid + "/5/Number of Scans";
	scanMap.insert(std::pair<firebase::Variant, firebase::Variant>(path, this->numberOfScans));
	dataList.at(5) = scanMap;
	dbm->updateData(scanMap);

} 

bool Account::checkXPforRank() {
	firebase::Variant rankList;
	dbm->retrieveData("Ranks", rankList);
	bool result = false;
	if (rankList.is_vector()) {
		std::vector<firebase::Variant> list = rankList.vector();
		int i = 0;
		while (list.at(i).is_map() && list.size() != i) {
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
