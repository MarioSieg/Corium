# release flags: -fno-exceptions -fno-common -Wconversion -Werror -Wall -Wextra -Wno-attributes -Wdouble-promotion -Wundef -ffast-math -fno-math-errno

cmake_minimum_required(VERSION 3.18)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project("nominax" CXX ASM)

set(CMAKE_C_COMPILER_WORKS true)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}")

add_library("libnominax"
	"inc/nominax/platform.hpp"
	"inc/nominax/reactor.hpp"
	"inc/nominax/reactor_internals.hpp"
    "inc/nominax/bytecode.hpp"
    "src/reactor.cpp" 
	"inc/nominax/record.hpp" 
	"inc/nominax/macrocfg.hpp" 
	"inc/nominax/runtime.hpp"
	"inc/nominax/interrupts.hpp" "inc/nominax/info.hpp" "inc/nominax/os.hpp" "src/os_windows.cpp" "src/os_linux.cpp" "src/os_android.cpp" "src/os_darwin.cpp" "inc/nominax/memunits.hpp" "inc/nominax/dll.hpp" "inc/nominax/sysintrin.hpp")

add_executable("nominax" "src/main.cpp")
target_link_libraries("nominax" "libnominax")

# tests:
file(GLOB "TEST_SRC_FILES" "tst/*.cpp")
add_subdirectory("tst/googletest/")
add_executable("nominax_unit_tests" ${TEST_SRC_FILES})
add_test(NAME "nominax_unit_tests" COMMAND "nominax_unit_tests")
target_include_directories("nominax_unit_tests" PUBLIC "tst/googletest/googletest/include/gtest")
target_link_libraries("nominax_unit_tests" "gtest" "libnominax")
