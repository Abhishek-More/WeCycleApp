#ifndef DataManagerWrapper_hpp
#define DataManagerWrapper_hpp

#ifdef __cplusplus
extern "C" {
#endif
	const void *initializeDataManager(const void *object);
	void pushData(const void *object, const void *pushableobject, const char *parent);
	const char **retrieveData(const void *object, const char *parent, const char *key);
#ifdef __cplusplus
}
#endif

#endif