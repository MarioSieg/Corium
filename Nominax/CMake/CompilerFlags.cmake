# Print info:
IF(CMAKE_BUILD_TYPE STREQUAL "Release")
	MESSAGE("Release build, using all optimization flags")
ENDIF()

TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-mmmx")
TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-msse")
TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-msse2")
TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-msse3")
TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-mssse3")
TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-msahf")
TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-mcx16")

SET_PROPERTY(TARGET "NominaxRuntime" PROPERTY CXX_STANDARD 20)

IF(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" AND "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Xclang -Wall")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Xclang -Werror")

	IF(CMAKE_BUILD_TYPE STREQUAL "Release")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "/EHsc")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "/D_HAS_EXCEPTIONS=0")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Xclang -Ofast")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Xclang -flto")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Xclang -ffp-exception-behavior=ignore")
	ENDIF()

	IF(${CORIUM_FAST_MATH} AND CMAKE_BUILD_TYPE STREQUAL "Release")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Xclang -ffast-math")
	ENDIF()

ELSE()
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wall")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wextra")

	IF(CMAKE_BUILD_TYPE STREQUAL "Release")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Ofast")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-fno-exceptions")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-fomit-frame-pointer")
	ENDIF()

	IF(${CORIUM_FAST_MATH} AND CMAKE_BUILD_TYPE STREQUAL "Release")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-ffast-math")
	ENDIF()

ENDIF()

MESSAGE("Final compilation flags: ${NOMINAX_CXX_FLAGS}")
