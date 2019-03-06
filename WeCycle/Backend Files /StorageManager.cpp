#include "StorageManager.h"

//TODO: ADD AUTHENTICATION TO FIREBASE

StorageManager::StorageManager(FirebaseManager *fbManager) {
	
	storage = firebase::storage::Storage::GetInstance(fbManager->getApp());
	storage_ref = storage->GetReferenceFromUrl("gs://wecycle-316c1.appspot.com");

}

StorageManager::~StorageManager() {}

const char *StorageManager::uploadImageRetreiveLink(std::string filepath) {
	 const std::string *resultPtr = new std::string("");

	firebase::storage::StorageReference image_ref = storage_ref.Child("images/image.jpg");

	StorageListener listener;

	StorageListener *listenerPtr = &listener; 

	firebase::storage::Controller *controller = new firebase::storage::Controller();

	const char* filePath = filepath.c_str();
	firebase::Future<firebase::storage::Metadata> futureUpload = image_ref.PutFile(filePath, listenerPtr, controller);

	//TODO: TRY TO CLEAN WHILE LOOPS

	while (futureUpload.status() != firebase::kFutureStatusComplete) {} //Loop to wait until upload is complete
	if (futureUpload.error() == 0) {
		std::cout << "Upload Complete" << std::endl;
	}
	else {
		std::cout << "Error" << std::endl;
	}

	firebase::storage::StorageReference download_ref = storage_ref.Child("images/image.jpg");
	firebase::Future<std::string> futureDownloadLink = download_ref.GetDownloadUrl();
	while (futureDownloadLink.status() != firebase::kFutureStatusComplete) {} //Loop to wait until download is complete
	if (futureDownloadLink.error() == firebase::storage::kErrorNone) {
		resultPtr = futureDownloadLink.result();
	}
	else {
		std::cout << "Error" << std::endl;
	}
	const std::string result = *resultPtr;

	const char *resultChar = strdup(result.c_str()); //strdup makes sure our char in the memory stays in the memory even when out of scope by creating a duplicate char array (string)

	delete controller;
	return resultChar;
	
}
