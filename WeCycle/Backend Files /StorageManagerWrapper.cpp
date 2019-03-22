#include "StorageManagerWrapper.hpp"
#include "FirebaseManager.h"
#include "StorageManager.h"


const void *initializeStorage(const void *fbObject, const void *accountObj) {
	StorageManager *storeManager = new StorageManager((FirebaseManager *)fbObject, (Account *)accountObj);
	return (void *)storeManager;
}

const char *uploadImageRetreiveLink(const void *object, const char* filepath) {
	StorageManager *storageManager = (StorageManager *)object;
	return storageManager->uploadImageRetreiveLink(filepath);
}

