# release flags: -fno-exceptions -fno-common -Wconversion -Werror -Wall -Wextra -Wno-attributes -Wdouble-promotion -Wundef -ffast-math -fno-math-errno

cmake_minimum_required(VERSION 3.18)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project("Nominax" CXX ASM)

message("Initializing Nominax SDK")

set(CMAKE_C_COMPILER_WORKS true)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")

option(NOMINAX_SDK_32_BIT "Build for 32-bit system" OFF)
option(NOMINAX_SDK_FAST_MATH "Use fast but less correct math" ON)
option(NOMINAX_BUILD_UNIT_TESTS "Build unit tests" ON)
option(NOMINAX_BUILD_BENCHMARKS "Build a system benchmark" ON)

# Linux build info:
# Requires >= GCC 10!

# See steam hardware survey: https://store.steampowered.com/hwsurvey/Steam-Hardware-Software-Survey-Welcome-to-Steam
# If your system does not support any of the -m* flags, just remove them!

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message("Using LLVM Clang!")
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED on)
    set(CMAKE_CXX_EXTENSIONS off)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}                                            \
            -Xclang -Ofast                                                              \
            -Xclang -Wall                                                               \
            -Xclang -Wextra                                                             \
            -Xclang -Werror                                                             \
            -Xclang -Wno-undef                                                          \
            -Xclang -std=c++20                                                          \
            -Xclang -Wno-unknown-attributes                                             \
            -Xclang -Wno-ignored-attributes                                             \
            -Xclang -Wno-deprecated-declarations                                        \
            -Xclang -flto                                                               \
            -mmmx									                                    \
            -msse									                                    \
            -msse2									                                    \
            -msse3									                                    \
            -mssse3									                                    \
            -msahf									                                    \
            -mcx16									                                    \
    ")
    if(NOMINAX_SDK_32_BIT)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -m32")
    endif()
    if(NOMINAX_SDK_FASH_MATH)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Xclang -ffast-math")
    endif()
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("Using G++")
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED on)
    set(CMAKE_CXX_EXTENSIONS off)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}                                            \
            -Ofast                                                                      \
            -Wall                                                                       \
            -Wextra                                                                     \
            -Werror                                                                     \
            -Wno-undef                                                                  \
            -std=c++2a                                                                  \
            -Wno-unknown-attributes                                                     \
            -Wno-ignored-attributes                                                     \
            -Wno-deprecated-declarations                                                \
            -ffast-math                                                                 \
            -flto                                                                       \
            -mmmx									                                    \
            -msse									                                    \
            -msse2									                                    \
            -msse3									                                    \
            -mssse3									                                    \
            -msahf									                                    \
            -mcx16									                                    \
    ")
    if(NOMINAX_SDK_32_BIT)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -m32")
    endif()
    if(NOMINAX_SDK_FASH_MATH)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ffast-math")
    endif()
else()
    message(FATAL_ERROR, "Unknown compiler! Use G++/Clang!")
endif()

add_library("NominaxRuntime" STATIC
    "Include/Nominax/Platform.hpp"
    "Include/Nominax/Reactor.hpp"
    "Include/Nominax/ByteCode.hpp"
    "Include/Nominax/Record.hpp" 
    "Include/Nominax/MacroCfg.hpp" 	
    "Include/Nominax/Interrupts.hpp"
    "Include/Nominax/Info.hpp"
    "Include/Nominax/OS.hpp"
    "Include/Nominax/Utility.hpp"
    "Include/Nominax/DynamicLibrary.hpp"
    "Include/Nominax/Nominax.hpp" 
    "Include/Nominax/Environment.hpp" 

    "Source/Reactor.cpp"
    "Source/OsWindows.cpp"
    "Source/OsLinux.cpp"
    "Source/OsAndroid.cpp"
    "Source/OsDarwin.cpp"
    "Source/Interrupts.cpp"  
    "Source/Environment.cpp"
    "Source/Bytecode.cpp" 
    "Source/Os.cpp" 
    "Source/Utility.cpp" "Include/Nominax/FormatTable.hpp")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries("NominaxRuntime" "dl")
endif()

add_executable("Nominax" "Source/main.cpp")
target_link_libraries("Nominax" "NominaxRuntime")

# test executable:
if(NOMINAX_BUILD_UNIT_TESTS)
    file(GLOB "TEST_Source_FILES" "Tests/*.cpp")
    add_subdirectory("Tests/googletest/")
    add_executable("NominaxUnitTests" ${TEST_Source_FILES})
    add_test(NAME "NominaxUnitTests" COMMAND "NominaxUnitTests")
    target_include_directories("NominaxUnitTests" PUBLIC "Tests/googletest/googletest/Includelude/gtest")
    target_link_libraries("NominaxUnitTests" "NominaxRuntime" "gtest")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_libraries("NominaxUnitTests" "pthread")
    endif()
endif()

# benchmark executable:
if(NOMINAX_BUILD_BENCHMARKS)
    file(GLOB "TEST_Source_FILES" "Benchmarks/*.cpp")
    add_subdirectory("Benchmarks/googlebench/")
    add_executable("NominaxBenchmark" ${TEST_Source_FILES})
    target_include_directories("NominaxBenchmark" PUBLIC "Benchmarks/googlebench/Includelude/benchmark")
    target_link_libraries("NominaxBenchmark" "benchmark::benchmark" "NominaxRuntime")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_libraries("benchmark" "pthread")
    endif()
endif()
