#include "StorageManager.h"

//TODO: ADD AUTHENTICATION TO FIREBASE

StorageManager::StorageManager(FirebaseManager *fbManager, Account *account) {
	storage = firebase::storage::Storage::GetInstance(fbManager->getApp());
	storage_ref = storage->GetReferenceFromUrl("gs://wecycle-316c1.appspot.com");
	acc = account;
}

StorageManager::~StorageManager() {}

void StorageManager::uploadImageLink(std::string filepath, std::string storagePath, bool *result) {
	firebase::storage::StorageReference image_ref = storage_ref.Child(storagePath);
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
			std::cout << "Upload Failed..." << std::endl;
			resultPtr = false;
		}
	}, result);

	delete controller;
}

void StorageManager::downloadImageLink(std::string imageRef, std::string *result) {
	firebase::storage::StorageReference download_ref = storage_ref.Child(imageRef);
	firebase::Future<std::string> futureDownloadLink = download_ref.GetDownloadUrl();
	futureDownloadLink.OnCompletion([](const firebase::Future<std::string>& futureDownloadLink, void* user_data) {
		std::string *result = static_cast<std::string *>(user_data);
		if (futureDownloadLink.error() == firebase::storage::kErrorNone) {
			const std::string *link = futureDownloadLink.result();
			result->assign(link->c_str());
			
			std::cout << "Link retrieved!" << std::endl;
		}
		else {
			std::cout << "Error" << std::endl;
		}

	}, result);

}

const char* StorageManager::uploadImageRetreiveLink(const char *filepath) {
	bool uploadResult = false;
	const char* result = nullptr;
	std::string storagePath ="User Images/" + this->acc->uidA() + "/image.jpg";
	uploadImageLink(filepath, storagePath, &uploadResult);
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	std::string imageLink;
	downloadImageLink(storagePath, &imageLink);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	result = strdup(imageLink.c_str());
	return result;
}