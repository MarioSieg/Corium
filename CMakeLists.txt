CMAKE_MINIMUM_REQUIRED(VERSION 3.18)

SET("CMAKE_CXX_STANDARD_REQUIRED" TRUE)
# Set helper values:
SET(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
SET(CMAKE_C_COMPILER_WORKS TRUE)
SET(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

ENABLE_TESTING()

# Set project name:
PROJECT("Nominax" CXX ASM)

IF (MSVC AND NOT ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    MESSAGE(FATAL_ERROR, "MSVC is not supported! Please use Clang, GCC, MINGW or any other POSIX like compiler!")
ENDIF()

OPTION("NOMINAX_FAST_MATH" "Use fast but IEEE incompatible math" ON)
OPTION("NOMINAX_BUILD_UNIT_TESTS" "Build the unit tests for all projects" ON)
OPTION("NOMINAX_BUILD_BENCHMARKS" "Build the benchmarks for all projects" ON)

INCLUDE("CMake/UnitTests.cmake")
INCLUDE("CMake/Benchmarks.cmake")

INCLUDE("Nominax/CMake/Build.cmake")
