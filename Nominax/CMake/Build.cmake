# runtime library:

FILE(GLOB_RECURSE "NOMINAX_SOURCES" "Nominax/Source/*.cpp" "Nominax/Source/*.asm" "Include/Nominax/*.hpp")
ADD_LIBRARY("Nominax" STATIC "${NOMINAX_SOURCES}")

# unit tests:
INCLUDE("Nominax/CMake/UnitTests.cmake")

# benchmark:
INCLUDE("Nominax/CMake/Benchmark.cmake")