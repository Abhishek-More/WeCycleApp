#pragma once
#include<firebase/storage/listener.h>
#include<firebase/storage/controller.h>

using Controller = firebase::storage::Controller;

class StorageListener : public firebase::storage::Listener {
public :
	void OnPaused(Controller *controller) override;
	void OnProgress(Controller *controller) override;
};