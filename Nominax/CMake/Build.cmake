# runtime library:

SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

FILE(GLOB_RECURSE "NOMINAX_SOURCES" "Nominax/Source/*.cpp" "Nominax/Source/*.S" "Include/Nominax/*.hpp")

# Set more optimizations for special reactors:
SET_SOURCE_FILES_PROPERTIES("Nominax/Source/Core/ReactorCore_AVX.cpp" PROPERTIES COMPILE_FLAGS "-mavx")
SET_SOURCE_FILES_PROPERTIES("Nominax/Source/Core/ReactorCore_AVX512F.cpp" PROPERTIES COMPILE_FLAGS "-mavx512f")

# We have 3 targets:

# 1. The fast release version without debugging tools:
ADD_LIBRARY("NominaxRuntime" STATIC "${NOMINAX_SOURCES}")

# 3. The unit test verion with special checks
ADD_LIBRARY("NominaxRuntimeTest" STATIC "${NOMINAX_SOURCES}")
TARGET_COMPILE_DEFINITIONS("NominaxRuntimeTest" PUBLIC "NOMINAX_TEST")

# extern libraries:
INCLUDE("Nominax/CMake/Externs.cmake")

# unit tests:
INCLUDE("Nominax/CMake/UnitTests.cmake")

# benchmark:
INCLUDE("Nominax/CMake/Benchmark.cmake")

# add entry executables
INCLUDE("Nominax/CMake/NominaxExe.cmake")