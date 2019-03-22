#pragma once
#include <iostream>
#include <firebase/storage.h>
#include <firebase/app.h>
#include <firebase/future.h>
#include <firebase/storage/metadata.h>
#include "FirebaseManager.h"
#include "StorageListener.h"
#include "Account.h"

//TODO: ADD AUTHENTICATION TO FIREBASE


class StorageManager {

private:
	firebase::storage::Storage *storage;
	firebase::storage::StorageReference storage_ref;
public:
	StorageManager(FirebaseManager *fbManager);
	~StorageManager();
	void uploadImageRetreiveLink(std::string filepath, bool *result);
	void downloadImageLink(std::string imageRef, std::string *result);


};
