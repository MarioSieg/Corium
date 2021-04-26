# release flags: -fno-exceptions -fno-common -Wconversion -Werror -Wall -Wextra -Wno-attributes -Wdouble-promotion -Wundef -ffast-math -fno-math-errno

cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project("Nominax" CXX ASM)

message("Initializing Nominax SDK")

set(CMAKE_C_COMPILER_WORKS true)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")

option(ANOMINAX_SDK_32_BIT "Build for 32-bit system" OFF)
option(ANOMINAX_SDK_FAST_MATH "Use fast but less correct math" ON)
option(ANOMINAX_BUILD_UNIT_TESTS "Build unit tests" ON)
option(ANOMINAX_BUILD_BENCHMARKS "Build a system benchmark" ON)

# Linux build info:
# Requires >= GCC 10!

add_library("NominaxRuntime" STATIC
        Include/Nominax/System/Platform.hpp
        Include/Nominax/Core/Reactor.hpp
        Include/Nominax/ByteCode/ByteCode.hpp
        Include/Nominax/Core/Record.hpp
        Include/Nominax/System/MacroCfg.hpp
        Include/Nominax/Core/Interrupts.hpp
        Include/Nominax/Core/Info.hpp
        Include/Nominax/System/Os.hpp
        Include/Nominax/System/DynamicLibrary.hpp
        Include/Nominax/Nominax.hpp
        Include/Nominax/Core/Environment.hpp
        Include/Nominax/Core/Object.hpp
        Include/Nominax/ByteCode/Instruction.hpp
        Include/Nominax/ByteCode/SystemIntrinsic.hpp
        Include/Nominax/ByteCode/InstructionCategory.hpp
        Include/Nominax/ByteCode/ImmediateArgumentType.hpp
        Include/Nominax/ByteCode/CustomIntrinsic.hpp
        Include/Nominax/ByteCode/Mnemonic.hpp
        Include/Nominax/ByteCode/Descriptor.hpp
        Include/Nominax/ByteCode/Category.hpp
        Include/Nominax/ByteCode/PopCount.hpp
        Include/Nominax/ByteCode/ImmediateArgumentCount.hpp
        Include/Nominax/ByteCode/ImmediateArgumentTypeList.hpp
        Include/Nominax/ByteCode/Signal.hpp
        Include/Nominax/ByteCode/DynamicSignal.hpp
        Include/Nominax/ByteCode/Validator.hpp
        Include/Nominax/ByteCode/LiteralOp.hpp
        Include/Nominax/ByteCode/OptBase.hpp
        Include/Nominax/ByteCode/ScopedVariable.hpp
        Include/Nominax/ByteCode/Stream.hpp
        Include/Nominax/ByteCode/Lexeme.hpp
        Include/Nominax/Core/ObjectFlagVector.hpp
        Include/Nominax/Core/ObjectHeader.hpp
        Include/Nominax/Core/ObjectAllocator.hpp
        Include/Nominax/ByteCode/StreamScalar.hpp
        Include/Nominax/Core/HardFaultReport.hpp
        Include/Nominax/Core/ReactorValidationResult.hpp
        
        Include/Nominax/Core/ReactorOutput.hpp
        Include/Nominax/Core/RegisterDump.hpp
        Include/Nominax/Core/Core.hpp
        Include/Nominax/Common/VisitOverload.hpp
        Include/Nominax/Common/XorshiftThreadLocal.hpp
        Include/Nominax/Common/XorshiftAtomic.hpp
        Include/Nominax/Common/MemoryUnits.hpp
        Include/Nominax/Common/SafeLocalTime.hpp
        Include/Nominax/Common/Common.hpp
        Include/Nominax/System/System.hpp
        Include/Nominax/Core/Marker.hpp
        Include/Nominax/Common/F64Comparator.hpp

        Source/Core/Reactor.cpp
        Source/System/OsWindows.cpp
        Source/System/OsLinux.cpp
        Source/System/OsAndroid.cpp
        Source/System/OsDarwin.cpp
        Source/Core/Interrupts.cpp
        Source/Core/Environment.cpp
        Source/System/Os.cpp
        Source/Core/Object.cpp
        Source/ByteCode/DynamicSignal.cpp
        Source/ByteCode/Validator.cpp
        Source/ByteCode/Stream.cpp
        Source/ByteCode/ScopedVariable.cpp
        Source/Core/ObjectAllocator.cpp
        Source/Core/HardFaultReport.cpp
        Source/Core/RegisterDump.cpp
        Source/Common/XorshiftThreadLocal.cpp
        Source/Common/XorshiftAtomic.cpp
        Source/Common/MemoryUnits.cpp
        Source/Common/SafeLocalTime.cpp 
        Source/Core/BasicReactorDescriptor.cpp
        Source/Core/DetailedReactorDescriptor.cpp "Include/Nominax/Core/BasicReactorDescriptor.hpp" "Include/Nominax/Core/ThreadLocalStack.hpp"  "Source/Core/ThreadLocalStack.cpp")

# See steam hardware survey: https://store.steampowered.com/hwsurvey/Steam-Hardware-Software-Survey-Welcome-to-Steam
# If your system does not support any of the -m* flags, just remove them!

# Clang-CL!
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message("Using LLVM Clang!")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
            message("Debug build!")
            set_target_properties("NominaxRuntime" PROPERTIES COMPILE_FLAGS "                       \
                -Xclang -Wall                                                                       \
                -Xclang -Wextra                                                                     \
                -Xclang -Werror                                                                     \
                -Xclang -Wno-undef                                                                  \
                -Xclang -std=c++20                                                                  \
                -Xclang -Wno-unknown-attributes                                                     \
                -Xclang -Wno-ignored-attributes                                                     \
                -Xclang -Wno-deprecated-declarations                                                \
                -mmmx									                                    \
                -msse									                                    \
                -msse2									                                    \
                -msse3									                                    \
                -mssse3									                                    \
                -msahf									                                    \
                -mcx16									                                    \
        ")
    else()
        message("Release build!")
        set_target_properties("NominaxRuntime" PROPERTIES COMPILE_FLAGS "                   \
               -Xclang -Ofast                                                                      \
               -Xclang -Wall                                                                       \
               -Xclang -Wextra                                                                     \
               -Xclang -Werror                                                                     \
               -Xclang -Wno-undef                                                                  \
               -Xclang -std=c++20                                                                  \
               -Xclang -Wno-unknown-attributes                                                     \
               -Xclang -Wno-ignored-attributes                                                     \
               -Xclang -Wno-deprecated-declarations                                                \
               -Xclang -flto                                                                       \
               -Xclang -fno-rtti                                                                   \
                -mmmx									                                    \
                -msse									                                    \
                -msse2									                                    \
                -msse3									                                    \
                -mssse3									                                    \
                -msahf									                                    \
                -mcx16									                                    \
        ")
    endif()
    if(ANOMINAX_SDK_32_BIT)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -m32")
    endif()
    if(ANOMINAX_SDK_FASH_MATH)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Xclang -ffast-math")
    endif()
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("Using G++")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message("Debug build!")
        set_target_properties("NominaxRuntime" PROPERTIES COMPILE_FLAGS "               \
            -Wall                                                                       \
            -Wextra                                                                     \
            -Werror                                                                     \
            -Wno-undef                                                                  \
            -std=c++2a                                                                  \
            -Wno-unknown-attributes                                                     \
            -Wno-ignored-attributes                                                     \
            -Wno-deprecated-declarations                                                \
            -fno-rtti                                                                   \
            -ffast-math                                                                 \
            -mmmx									                                    \
            -msse									                                    \
            -msse2									                                    \
            -msse3									                                    \
            -mssse3									                                    \
            -msahf									                                    \
            -mcx16									                                    \
        ")
    else()
        message("Release build!")
        set_target_properties("NominaxRuntime" PROPERTIES COMPILE_FLAGS "                   \
                -Ofast                                                                      \
                -Wall                                                                       \
                -Wextra                                                                     \
                -Werror                                                                     \
                -Wno-undef                                                                  \
                -std=c++2a                                                                  \
                -Wno-unknown-attributes                                                     \
                -Wno-ignored-attributes                                                     \
                -Wno-deprecated-declarations                                                \
                -fno-rtti                                                                   \
                -ffast-math                                                                 \
                -mmmx									                                    \
                -msse									                                    \
                -msse2									                                    \
                -msse3									                                    \
                -mssse3									                                    \
                -msahf									                                    \
                -mcx16									                                    \
        ")
    endif()
    if(ANOMINAX_SDK_32_BIT)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -m32")
    endif()
    if(ANOMINAX_SDK_FASH_MATH)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ffast-math")
    endif()
else()
    message(FATAL_ERROR, "Unknown compiler! Use G++/Clang!")
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries("NominaxRuntime" "dl" "psapi")
    if (WIN32)
        target_link_libraries("NominaxRuntime" "psapi")
    endif()
endif()

add_executable("Nominax" "Source/Main.cpp")
target_link_libraries("Nominax" "NominaxRuntime")

# test executable:
# disable BUID_GMOCK in Tests/googletest/CMakeLists.txt if there are weird errors
if(ANOMINAX_BUILD_UNIT_TESTS)
    set(GOOGLETEST_PATH "Tests/googletest/googletest" CACHE PATH "")
    file(GLOB "TEST_SOURCE_FILES" "Tests/*.cpp")
    add_subdirectory("Tests/googletest/")
    add_executable("NominaxUnitTests" ${TEST_SOURCE_FILES})
    add_test(NAME "NominaxUnitTests" COMMAND "NominaxUnitTests")
    target_include_directories("NominaxUnitTests" PUBLIC "Tests/googletest/googletest/include/gtest")
    target_link_libraries("NominaxUnitTests" "NominaxRuntime" "gtest")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_libraries("NominaxUnitTests" "pthread")
    endif()
endif()

# benchmark executable:
if(ANOMINAX_BUILD_BENCHMARKS)
    set(GOOGLETEST_PATH "Tests/googletest/googletest" CACHE PATH "")
    file(GLOB "TEST_Source_FILES" "Benchmarks/*.cpp")
    add_subdirectory("Benchmarks/googlebench/")
    add_executable("NominaxBenchmark" ${TEST_Source_FILES})
    target_include_directories("NominaxBenchmark" PUBLIC "Benchmarks/googlebench/include/benchmark")
    target_link_libraries("NominaxBenchmark" "benchmark::benchmark" "NominaxRuntime")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_libraries("benchmark" "pthread")
    endif()
endif()
