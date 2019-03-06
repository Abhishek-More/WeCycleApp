#include "FirebaseManagerWrapper.hpp"
#include "FirebaseManager.h"

const void *initializeFirebase(const char *filename) {
	FirebaseManager *fireManager = new FirebaseManager(filename);
	return (void *)fireManager;
}
