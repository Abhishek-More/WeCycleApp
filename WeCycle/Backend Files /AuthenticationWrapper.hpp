#ifndef AuthenticationWrapper_hpp
#define AuthenticationWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
	const void *initializeAuthentication(const void *fbManager, const void *dbManager);
	const void createAndRegisterAccount(const void *auth, const void *account, const char* email, const char* password);
	const void signInUser(const void *auth, const void *account, const char* email, const char* password);
	void signOutUser(const void *auth);
	void updateUserProfile(const void *auth, const void *acc, const char* pfplink, const char* displayname);
	void updateUserPFPLink(const void *auth, const void *acc, const char* pfplink);
#ifdef __cplusplus
}
#endif

#endif
