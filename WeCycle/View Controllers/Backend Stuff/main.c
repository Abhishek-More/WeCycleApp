#include "c-headers-wrappers\AccountWrapper.hpp"
#include "c-headers-wrappers\DataManagerWrapper.hpp"
#include "c-headers-wrappers\FirebaseManagerWrapper.hpp"
#include "c-headers-wrappers\StorageManagerWrapper.hpp"
#include "c-headers-wrappers\PushableObjectWrapper.hpp"

int main() {
	const char *filename = "C:/Users/Kim/Desktop/WeCycle/google-services.json";

	const void *firebase = initializeFirebase(filename);
	const void *dataManager = initializeDataManager(firebase);
	const void *account = initializeAccount_basic("Ctest@droptablecom", "passwordE");

	pushData(dataManager, account, "Accounts");

	return 0;
}


