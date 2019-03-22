#pragma once
#include <iostream>
#include "Account.h"
#include <firebase/database/listener.h>
#include <firebase/database/data_snapshot.h>


class AccountValueListener : public firebase::database::ValueListener {
private:
	Account *acc;

public:
	AccountValueListener(Account *acc);
	void OnValueChanged(const firebase::database::DataSnapshot &snapshot) override;
	void OnCancelled(const firebase::database::Error& error_code,
					 const char* error_message) override;
};