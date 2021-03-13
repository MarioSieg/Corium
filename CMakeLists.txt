cmake_minimum_required (VERSION 3.8)

project("Nominax" CXX)

if(MSVC)
	message(FATAl_ERROR "MSVC is not supported! Use Clang or G++!")
else()
	set(CMAKE_CXX_FLAGS  "-fno-exceptions -flto -Ofast -march=native -Wall -Wextra")
	set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

message("${CMAKE_CXX_FLAGS}")

add_executable("Nominax" "Source/Entry.cpp" "Include/Nominax.hpp")
