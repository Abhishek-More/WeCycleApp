#ifndef AccountWrapper_hpp
#define AccountWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
    const void *initializeAccount_basic(const char *emailAddress, const char *password);
    const void *initializeAccount_basic_phone(const char *emailAddress, const char *password, long phoneNumber);
#ifdef __cplusplus
}
#endif

#endif
