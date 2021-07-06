# runtime library:
FILE(GLOB_RECURSE "NOMINAX_SOURCES" "Nominax/Source/*.cpp" "Nominax/Source/*.S" "Include/Nominax/*.hpp")

# Set more optimizations for special reactors:
SET_SOURCE_FILES_PROPERTIES("Nominax/Source/VM_Impl_AVX.cpp" PROPERTIES COMPILE_FLAGS "-mavx")
SET_SOURCE_FILES_PROPERTIES("Nominax/Source/VM_Impl_AVX512F.cpp" PROPERTIES COMPILE_FLAGS "-mavx512f")

ADD_LIBRARY("NominaxRuntime" STATIC "${NOMINAX_SOURCES}")

# assembler code macros:
INCLUDE("Nominax/CMake/Assembly.cmake")

# compiler optimization flags:
INCLUDE("Nominax/CMake/CompilerFlags.cmake")

# unit tests:
INCLUDE("Nominax/CMake/UnitTests.cmake")

# extern libraries:
INCLUDE("Nominax/CMake/Externs.cmake")

# benchmark:
INCLUDE("Nominax/CMake/Benchmark.cmake")
