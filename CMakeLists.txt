CMAKE_MINIMUM_REQUIRED(VERSION 3.18)

# C++ 20 is required:
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set helper values:
SET(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
SET(CMAKE_C_COMPILER_WORKS TRUE)
SET(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")

# Set project name:
PROJECT("Corium" CXX ASM)

OPTION("CORIUM_FAST_MATH" "Use fast but IEEE incompatible math" ON)
OPTION("CORIUM_BUILD_UNIT_TESTS" "Build the unit tests for all projects" ON)
OPTION("CORIUM_BUILD_BENCHMARKS" "Build the benchmarks for all projects" ON)

INCLUDE("CMake/UnitTests.cmake")
INCLUDE("CMake/Benchmarks.cmake")
INCLUDE("CMake/CompilerFlags.cmake")
INCLUDE("Nominax/CMake/Build.cmake")
INCLUDE("Corium/CMake/Build.cmake")