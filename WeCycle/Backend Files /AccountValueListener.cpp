#include "AccountValueListener.h"

AccountValueListener::AccountValueListener(Account *acc) {
	this->acc = acc;
}

void AccountValueListener::OnValueChanged(const firebase::database::DataSnapshot &snapshot) {
	firebase::Variant vect = snapshot.value();
	if (vect.is_vector()) {
		firebase::Variant variant = vect;
		this->acc->updateDataList(variant);
		printf("Done1212121\n");
	}
}
void AccountValueListener::OnCancelled(const firebase::database::Error& error_code,
									   const char* error_message) {
	printf("ERROR: LeadersValueListener canceled: %d: %s", error_code,
		   error_message);
}