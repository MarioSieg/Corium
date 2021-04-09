# release flags: -fno-exceptions -fno-common -Wconversion -Werror -Wall -Wextra -Wno-attributes -Wdouble-promotion -Wundef -ffast-math -fno-math-errno

cmake_minimum_required(VERSION 3.18)

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
    "inc/nominax/bytecode.hpp"
    "src/reactor.cpp" "inc/nominax/anatomy.hpp" "inc/nominax/macrocfg.hpp")

add_executable("nominax" "src/main.cpp")
target_link_libraries("nominax" "libnominax")

# tests:
file(GLOB "TEST_SRC_FILES" "tst/*.cpp")
add_subdirectory("tst/googletest/")
add_executable("nominax_unit_tests" ${TEST_SRC_FILES})
add_test(NAME "nominax_unit_tests" COMMAND "nominax_unit_tests")
target_include_directories("nominax_unit_tests" PUBLIC "tst/googletest/googletest/include/gtest")
target_link_libraries("nominax_unit_tests" "gtest" "libnominax")
