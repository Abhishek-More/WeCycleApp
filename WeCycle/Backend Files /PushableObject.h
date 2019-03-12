#pragma once
#include <iostream>
#include <map>
#include <firebase/variant.h>

//TODO SWITCH ALL VARAINTS TO TYPE STRING. CHANGE IT IN THE CPP FILE. THEN CREATE WRAPPERS

using stringMap = std::map<std::string, std::string>;

class PushableObject
{
private:
	std::string objKey;
	std::map<firebase::Variant, firebase::Variant> pushableData;
public:
	PushableObject();
	~PushableObject();

	virtual void initialize(std::map<firebase::Variant, firebase::Variant> &map); //Creates a new map and replaces original
	virtual void addData(std::string key, stringMap value); //Adds data to existing map

	//TODO: Think of more ways that a pushable object MUST have
	std::string getKey();
	void setKey(std::string key);

	virtual std::map<firebase::Variant, firebase::Variant> dataMap(); //Final data product
};

