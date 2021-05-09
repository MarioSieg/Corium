# runtime library:

FILE(GLOB_RECURSE "NOMINAX_SOURCES" "Nominax/Source/*.cpp" "Nominax/Source/*.S" "Include/Nominax/*.hpp")
ADD_LIBRARY("Nominax" STATIC "${NOMINAX_SOURCES}")

# extern libraries:
INCLUDE("Nominax/CMake/Externs.cmake")

# unit tests:
INCLUDE("Nominax/CMake/UnitTests.cmake")

# benchmark:
INCLUDE("Nominax/CMake/Benchmark.cmake")

# Set more optimizations for special reactors:
SET_SOURCE_FILES_PROPERTIES("Nominax/Source/Core/ReactorCore_Avx.cpp" PROPERTIES COMPILE_FLAGS "-mavx")