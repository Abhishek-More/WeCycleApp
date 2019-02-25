# CMakeList.txt : CMake project for WeCycle, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Include linked directories
link_directories("Firebase_libs")
include_directories(${PROJECT_SOURCE_DIR}/WeCycle ${PROJECT_SOURCE_DIR}/firebase ${PROJECT_SOURCE_DIR}/nlohmann ${PROJECT_SOURCE_DIR}/c-headers-wrappers)


# Add source to this project's executable.
add_executable (WeCycle "main.c" "WeCycle.cpp" "WeCycle.h" "Account.cpp" "Account.h" "DataManager.cpp" "DataManager.h" "PushableObject.cpp" 
				"PushableObject.h" "FirebaseManager.h" "FirebaseManager.cpp" "StorageManager.h" "StorageManager.cpp" "StorageListener.h" 
				"StorageListener.cpp"
				"c-headers-wrappers/DataManagerWrapper.hpp"
				"c-headers-wrappers/DataManagerWrapper.cpp" 
				"c-headers-wrappers/AccountWrapper.hpp"
				"c-headers-wrappers/AccountWrapper.cpp" 
				"c-headers-wrappers/FirebaseManagerWrapper.hpp" 
				"c-headers-wrappers/FirebaseManagerWrapper.cpp"
				"c-headers-wrappers/PushableObjectWrapper.hpp"
				"c-headers-wrappers/PushableObjectWrapper.cpp" 
				"c-headers-wrappers/StorageManagerWrapper.hpp" 
				"c-headers-wrappers/StorageManagerWrapper.cpp")


target_link_libraries(WeCycle ${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_admob.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_analytics.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_app.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_auth.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_database.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_dynamic_links.lib
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_functions.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_instance_id.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_invites.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_messaging.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_remote_config.lib 
						${CMAKE_SOURCE_DIR}/Firebase_libs/Debug/firebase_storage.lib
						${WinSDK}advapi32.lib
						${WinSDK}ws2_32.lib
						${WinSDK}crypt32.lib
						${WinSDK}iphlpapi.lib
						${WinSDK}psapi.lib
						${WinSDK}userenv.lib)

# TODO: Add tests and install targets if needed.
