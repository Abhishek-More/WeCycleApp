#include "PushableObjectWrapper.hpp"
#include "PushableObject.h"
#include "firebase/variant.h"

const void *initializePushableObject() {
	PushableObject *pushableObject = new PushableObject();
	return (void *)pushableObject;
}

void addData(const void *object, const char *key, const char *mapKey, const char *mapValue) {
	PushableObject *pushableObject = (PushableObject *)object;
	std::map<std::string, std::string> map;
	map[mapKey] = mapValue;
	pushableObject->addData(key,map);
}

void initializeMap_basic(const void *object, const char *keyMap, const char *keyValue) {
	
	PushableObject *pushableObject = (PushableObject *)object;

	std::string keyValueString = keyValue;
	std::string keyMapString = keyMap;

	firebase::Variant keyValueVariant(keyValueString);
	std::map<std::string, firebase::Variant> map;
	map.insert(std::pair<std::string, firebase::Variant>(keyMapString, keyValueVariant));
	//pushableObject->initialize(map);
	
}

void initializeMap_basic_map(const void *object, const char *keyMap, const char *keyValue, const char *keyValue2) {
	PushableObject *pushableObject = (PushableObject *)object;

	std::string keyMapString = keyMap;
	std::string keyValueString = keyValue;
	std::string keyValue2String = keyValue2;

	std::map<std::string, std::string> valueMap;
	valueMap.insert(std::pair<std::string, std::string>(keyValueString, keyValue2String));
	firebase::Variant keyValueVariant(valueMap);
	std::map<std::string, firebase::Variant> map;
	map.insert(std::pair<std::string, firebase::Variant>(keyMapString, keyValueVariant));
	//pushableObject->initialize(map);

}
