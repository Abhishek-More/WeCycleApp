#include "AccountValueListener.h"

AccountValueListener::AccountValueListener(Account *acc) {
	this->acc = acc;
}

void AccountValueListener::OnValueChanged(const firebase::database::DataSnapshot &snapshot) {
	std::vector<firebase::database::DataSnapshot> vect = snapshot.children();
	std::vector<firebase::Variant> variantList;
	for (int i = 0; i < snapshot.children_count(); i++) {
		variantList.push_back(vect.at(i).value());
	}

	firebase::Variant variant = variantList;
	this->acc->updateDataList(variant);

	printf("Done1212121\n");
}
void AccountValueListener::OnCancelled(const firebase::database::Error& error_code,
									   const char* error_message) {
	printf("ERROR: LeadersValueListener canceled: %d: %s", error_code,
		   error_message);
}