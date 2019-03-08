#include "Account.h"

Account::Account(std::string emailAddress, std::string password) {
	this->emailAddress = emailAddress;
	this->password = password;

	stringMap emailMap;
	emailMap.insert(std::pair<std::string, std::string>("Email", this->emailAddress));
	stringMap passwordMap;
	passwordMap.insert(std::pair<std::string, std::string>("Password", this->password));

	firebase::Variant variant;

	dataList.push_back(passwordMap);
	dataList.push_back(emailMap);

	std::map<std::string, firebase::Variant> accountMap;
	accountMap.insert(std::pair<std::string, firebase::Variant>(this->emailAddress, dataList));

	this->initialize(accountMap);

}
Account::Account(std::string emailAddress, std::string password, long phoneNumber) {
	this->emailAddress = emailAddress;
	this->password = password;
	this->phoneNumber = phoneNumber;

	stringMap emailMap;
	emailMap.insert(std::pair<std::string, std::string>("Email", this->emailAddress));
	stringMap passwordMap;
	passwordMap.insert(std::pair<std::string, std::string>("Password", this->password));
	stringMap phoneNumberMap;
	phoneNumberMap.insert(std::pair<std::string, std::string>("Phone Number", this->phoneNumber + ""));

	dataList.push_back(phoneNumberMap);
	dataList.push_back(passwordMap);
	dataList.push_back(emailMap);

	std::map<std::string, firebase::Variant> accountMap;
	accountMap.insert(std::pair<std::string, firebase::Variant>(this->emailAddress, dataList));

	this->initialize(accountMap);

}

Account::~Account() {
}

std::string Account::getEmail() {
	return emailAddress;
}
std::string Account::getPassword() {
	return password;
}


