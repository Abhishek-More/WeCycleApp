#pragma once
#include <iostream>
#include "DataManager.h"
#include <cryptlib.h>
#include <shake.h>
class Crypto {

private:
	std::string salt0;
	std::string salt1;

	void acquireSaltConfiguration();

public: 
	std::string encrypt(std::string stringToEncrypt);
	std::string encrypt(std::string stringToEncrypt, std::string salt);
	std::string decrypt(std::string digest);
};