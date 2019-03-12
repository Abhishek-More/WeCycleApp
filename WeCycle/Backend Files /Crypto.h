#pragma once
#include <iostream>
#include "DataManager.h"
#include "cryptlib.h"
#include "shake.h"
#include "filters.h"
#include "hex.h"

class Crypto {

private:
	std::string salt0;
	std::string salt1;

	void acquireSaltConfiguration(DataManager *dbManger);

public: 
	Crypto(DataManager *dbManager);
	Crypto();
	std::string hashSHAKE128(std::string stringToEncrypt);
	const bool verifySHAKE128(std::string stringToVerify, std::string encoding);
};
