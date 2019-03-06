#include "PushableObject.h"


PushableObject::PushableObject(){}

PushableObject::~PushableObject(){}

void PushableObject::initialize(std::map<std::string, firebase::Variant> &map) {
	pushableData = map;
}
void PushableObject::addData(std::string key, stringMap value) {
	pushableData.insert(std::pair<std::string, stringMap>(key, value));
}

std::string PushableObject::getKey() {
	return objKey;
}

void PushableObject::setKey(std::string key) {
	objKey = key;
}

std::map<std::string, firebase::Variant> PushableObject::dataMap() {
	std::map<std::string, firebase::Variant> result;
	for (auto &x : pushableData) {
		result.insert(std::pair<std::string, firebase::Variant>(x.first, x.second));
	}
	return result;
}



