CMAKE_MINIMUM_REQUIRED(VERSION 3.18)

SET("CMAKE_CXX_STANDARD_REQUIRED" TRUE)

# Set helper values:
SET(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
SET(CMAKE_C_COMPILER_WORKS TRUE)
SET(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")

ENABLE_TESTING()

# Set project name:
PROJECT("Corium" CXX ASM)

OPTION("CORIUM_FAST_MATH" "Use fast but IEEE incompatible math" ON)
OPTION("CORIUM_BUILD_UNIT_TESTS" "Build the unit tests for all projects" ON)
OPTION("CORIUM_BUILD_BENCHMARKS" "Build the benchmarks for all projects" ON)

INCLUDE("CMake/UnitTests.cmake")
INCLUDE("CMake/Benchmarks.cmake")

INCLUDE("Nominax/CMake/Build.cmake")
#INCLUDE("Corium/CMake/Build.cmake")
