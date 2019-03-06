#pragma once
//#include <iostream>
#include "DataManager.h"
#include "PushableObject.h"
#include "Rank.h"

using stringMap = std::map<std::string, std::string>;

class Account : public PushableObject
{
private:
	std::string emailAddress;
	std::string password;
	long phoneNumber;
	std::vector<stringMap> dataList;
	

public:
	Account(std::string emailAddress, std::string password);
	Account(std::string emailAddress, std::string password, long phoneNumber);


	//TODO add intialize override function and addData function
	
	~Account();
};

