# release flags: -fno-exceptions -fno-common -Wconversion -Werror -Wall -Wextra -Wno-attributes -Wdouble-promotion -Wundef -ffast-math -fno-math-errno

cmake_minimum_required(VERSION 3.18)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project("nominax" CXX ASM)

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

add_library("libnominax" STATIC
	"inc/nominax/platform.hpp"
	"inc/nominax/reactor.hpp"
    "inc/nominax/bytecode.hpp"
    "src/reactor.cpp"
	"inc/nominax/record.hpp" 
	"inc/nominax/macrocfg.hpp" 
	"inc/nominax/runtime.hpp"
    "inc/nominax/interrupts.hpp"
    "inc/nominax/info.hpp"
    "inc/nominax/os.hpp"
    "src/os_windows.cpp"
    "src/os_linux.cpp"
    "src/os_android.cpp"
    "src/os_darwin.cpp"
    "inc/nominax/memunits.hpp"
    "inc/nominax/dll.hpp"
    "inc/nominax/sysintrin.hpp"
    "inc/nominax/idb.hpp" 
    "src/interrupts.cpp" 
    "inc/nominax/validator.hpp"
    "src/validator.cpp" "inc/nominax/environment.hpp" "src/environment.cpp")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries("libnominax" "dl")
endif()

add_executable("nominax" "src/main.cpp")
target_link_libraries("nominax" "libnominax")

# test executable:
if(NOMINAX_BUILD_UNIT_TESTS)
    file(GLOB "TEST_SRC_FILES" "tst/*.cpp")
    add_subdirectory("tst/googletest/")
    add_executable("nominax_unit_tests" ${TEST_SRC_FILES})
    add_test(NAME "nominax_unit_tests" COMMAND "nominax_unit_tests")
    target_include_directories("nominax_unit_tests" PUBLIC "tst/googletest/googletest/include/gtest")
    target_link_libraries("nominax_unit_tests" "libnominax" "gtest")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_libraries("nominax_unit_tests" "pthread")
    endif()
endif()

# benchmark executable:
if(NOMINAX_BUILD_BENCHMARKS)
    file(GLOB "TEST_SRC_FILES" "bch/*.cpp")
    add_subdirectory("bch/googlebench/")
    add_executable("nominax_benchmark" ${TEST_SRC_FILES})
    target_include_directories("nominax_benchmark" PUBLIC "bch/googlebench/include/benchmark")
    target_link_libraries("nominax_benchmark" "benchmark::benchmark" "libnominax")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_libraries("benchmark" "pthread")
    endif()
endif()
