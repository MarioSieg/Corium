# runtime library:

SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

FILE(GLOB_RECURSE "NOMINAX_SOURCES" "Nominax/Source/*.cpp" "Nominax/Source/*.S" "Include/Nominax/*.hpp")
ADD_LIBRARY("Nominax" STATIC "${NOMINAX_SOURCES}")
ADD_LIBRARY("NominaxTest" STATIC "${NOMINAX_SOURCES}")

# Set test flags and disable execution address mapping:
TARGET_COMPILE_DEFINITIONS("NominaxTest" PUBLIC "-DNOMINAX_TEST")

IF(CMAKE_BUILD_TYPE STREQUAL "Release")
	# detect clang-cl
	IF(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" AND "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
		TARGET_COMPILE_OPTIONS("Nominax" PRIVATE "-Xclang -fno-rtti")
	ELSE()
		TARGET_COMPILE_OPTIONS("Nominax" PRIVATE "-fno-rtti")
	ENDIF()
ENDIF()

# extern libraries:
INCLUDE("Nominax/CMake/Externs.cmake")

# unit tests:
INCLUDE("Nominax/CMake/UnitTests.cmake")

# benchmark:
INCLUDE("Nominax/CMake/Benchmark.cmake")

# Set more optimizations for special reactors:
SET_SOURCE_FILES_PROPERTIES("Nominax/Source/Core/ReactorCore_AVX.cpp" PROPERTIES COMPILE_FLAGS "-mavx")

SET_SOURCE_FILES_PROPERTIES("Nominax/Source/Core/ReactorCore_AVX512F.cpp" PROPERTIES COMPILE_FLAGS "-mavx512f")