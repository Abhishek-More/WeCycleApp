#ifndef AuthenticationWrapper_hpp
#define AuthenticationWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
	const void *initializeAuthentication(const void *fbManager);
	const char* createAndRegisterAccount_account(const void *authObj, const void *account);
	const char* createAndRegisterAccount_string(const void *authObj, const char* email, const char* password);
	const char* signInUser_account(const void *authObj, const void  *account);
	const char* signInUser_string(const void *authObj, const char* email, const char* password);

#ifdef __cplusplus
}
#endif

#endif
