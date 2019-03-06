#include "StorageListener.h"
#include <iostream>


void StorageListener::OnPaused(Controller *controller) {
	std::cout << "Paused";
}
void StorageListener::OnProgress(Controller *controller) {
	std::cout << "Uploading...";
}