# runtime library:

SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

FILE(GLOB_RECURSE "NOMINAX_SOURCES" "Nominax/Source/*.cpp" "Nominax/Source/*.S" "Include/Nominax/*.hpp")
ADD_LIBRARY("Nominax" SHARED "${NOMINAX_SOURCES}")

# extern libraries:
INCLUDE("Nominax/CMake/Externs.cmake")

# unit tests:
INCLUDE("Nominax/CMake/UnitTests.cmake")

# benchmark:
INCLUDE("Nominax/CMake/Benchmark.cmake")

# Set more optimizations for special reactors:
SET_SOURCE_FILES_PROPERTIES("Nominax/Source/Core/ReactorCore_AVX.cpp" PROPERTIES COMPILE_FLAGS "-mavx")

SET_SOURCE_FILES_PROPERTIES("Nominax/Source/Core/ReactorCore_AVX512F.cpp" PROPERTIES COMPILE_FLAGS "-mavx512f")