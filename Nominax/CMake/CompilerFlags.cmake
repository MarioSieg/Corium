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

TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wall")
TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Werror")
TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wextra")
TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-error=unused-function")


IF (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" AND "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")

	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-gnu-label-as-value")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-c++20-compat")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-c++20-compat-pedantic")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-c++98-compat")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-c++98-compat-pedantic")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-dollar-in-identifier-extension")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-unreachable-code")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-float-equal")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-global-constructors")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-exit-time-destructors")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-switch-enum")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-signed-enum-bitfield")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-sign-conversion")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-implicit-int-conversion")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-documentation-unknown-command")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-comma")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-undefined-func-template")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-unused-const-variable")

ELSEIF(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-std=c++20")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wc++20-compat")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wc++20-compat-pedantic")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-c++98-compat")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-c++98-compat-pedantic")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-unknown-attributes")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-gnu-label-as-value")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Wno-dollar-in-identifier-extension")

ELSE()

	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-std=c++20")

ENDIF()

IF(CMAKE_BUILD_TYPE STREQUAL "Release")
	TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-Ofast")

	IF (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" AND "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "/EHsc")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "/D_HAS_EXCEPTIONS=0")
		TARGET_LINK_OPTIONS("NominaxRuntime" PRIVATE "/LTCG")
		IF(${CORIUM_FAST_MATH})
			TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "/fp:fast")
		ENDIF()
	ELSE()
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-fno-exceptions")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-fomit-frame-pointer")
		TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-flto")
		IF(${CORIUM_FAST_MATH})
			TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "-ffast-math")
		ENDIF()
	ENDIF()

ENDIF()
