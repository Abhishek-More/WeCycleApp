#include "Crypto.h"

Crypto::Crypto(DataManager *dbManager) {
	acquireSaltConfiguration(dbManager);
}

Crypto::Crypto() {

}
void Crypto::acquireSaltConfiguration(DataManager *dbManager) {
	const char** salts = dbManager->retrieveData("s4lT");
	salt0 = salts[0];
	salt1 = salts[1];
}

std::string Crypto::hashSHAKE128(std::string stringToEncrypt) {

	std::string msg = stringToEncrypt;
	std::string digest;
	
	CryptoPP::SHAKE128 hash;
	hash.Update((const CryptoPP::byte*)msg.data(), msg.size());
	digest.resize(hash.DigestSize());
	hash.Final((CryptoPP::byte*)&digest[0]);

	std::string res;
	CryptoPP::HexEncoder encoder;
	encoder.Attach(new CryptoPP::StringSink(res));
	encoder.Put((CryptoPP::byte*)&digest[0], sizeof(digest));
	encoder.MessageEnd();

	std::string msgSalts = salt0 + res + salt1;
	std::string resultDigest;

	CryptoPP::SHAKE128 hash1;
	hash1.Update((const CryptoPP::byte*)msgSalts.data(), msgSalts.size());
	resultDigest.resize(hash1.DigestSize());
	hash1.Final((CryptoPP::byte*)&resultDigest[0]);

	std::string res1;
	CryptoPP::HexEncoder encoder1;
	encoder1.Attach(new CryptoPP::StringSink(res1));
	encoder1.Put((CryptoPP::byte*)&resultDigest[0], sizeof(resultDigest));
	encoder1.MessageEnd();
	return res1;
}

const bool Crypto::verifySHAKE128(std::string stringToVerify, std::string encoding) {
	std::string encoded_initial = stringToVerify;
	std::string resultDigest = hashSHAKE128(encoded_initial);
	return (resultDigest == encoding);
}