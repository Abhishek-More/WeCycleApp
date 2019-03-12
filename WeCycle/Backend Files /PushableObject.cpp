#include "PushableObject.h"


PushableObject::PushableObject(){}

PushableObject::~PushableObject(){}

void PushableObject::initialize(std::map<firebase::Variant, firebase::Variant> &map) {
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

std::map<firebase::Variant, firebase::Variant> PushableObject::dataMap() {
	std::map<firebase::Variant, firebase::Variant> result;
	for (auto &x : pushableData) {
		result.insert(std::pair<firebase::Variant, firebase::Variant>(x.first, x.second));
	}
	return result;
}



