#include "DataManagerWrapper.hpp"
#include "DataManager.h"
#include "FirebaseManager.h"
#include "PushableObject.h"
#include "Account.h"

const void *initializeDataManager(const void *object) {
	DataManager *dataManager = new DataManager((FirebaseManager *)object);
	return (void *)dataManager;
}

void pushData(const void *object, const void *pushableobject, const char *parent) {
	DataManager *dataManager = (DataManager *)object;
	PushableObject *objectToPush = (PushableObject *)pushableobject;
	return dataManager->pushData(objectToPush, parent);
}

const char **retrieveData(const void *object, const char *parent, const char *key) {
	DataManager *dataManager = (DataManager *)object;
	return dataManager->retrieveData(parent, key);
}
