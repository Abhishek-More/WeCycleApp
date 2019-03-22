#include "StorageManager.h"

//TODO: ADD AUTHENTICATION TO FIREBASE

StorageManager::StorageManager(FirebaseManager *fbManager) {
	
	storage = firebase::storage::Storage::GetInstance(fbManager->getApp());
	storage_ref = storage->GetReferenceFromUrl("gs://wecycle-316c1.appspot.com");

}

StorageManager::~StorageManager() {}

void StorageManager::uploadImageRetreiveLink(std::string filepath, bool *result) {
	firebase::storage::StorageReference image_ref = storage_ref.Child(filepath);
	StorageListener listener;
	StorageListener *listenerPtr = &listener; 
	firebase::storage::Controller *controller = new firebase::storage::Controller();

	const char* filePath = filepath.c_str();
	firebase::Future<firebase::storage::Metadata> futureUpload = image_ref.PutFile(filePath, listenerPtr, controller);

	futureUpload.OnCompletion([](const firebase::Future<firebase::storage::Metadata>& futureUpload, void* user_data) {
		bool resultPtr = static_cast<bool *>(user_data);
		if (futureUpload.error() == 0) {
			std::cout << "Upload Complete" << std::endl;
			resultPtr = true;
		}
		else {
			std::cout << "Error" << std::endl;
			resultPtr = false;
		}
	}, result);

	delete controller;
}

void StorageManager::downloadImageLink(std::string imageRef, std::string *result) {
	firebase::storage::StorageReference download_ref = storage_ref.Child(imageRef);
	firebase::Future<std::string> futureDownloadLink = download_ref.GetDownloadUrl();
	futureDownloadLink.OnCompletion([](const firebase::Future<std::string>& futureDownloadLink, void* user_data) {
		const std::string *result = static_cast<std::string *>(user_data);
		if (futureDownloadLink.error() == firebase::storage::kErrorNone) {
			result = futureDownloadLink.result();
		}
		else {
			std::cout << "Error" << std::endl;
		}

	}, result);

}
