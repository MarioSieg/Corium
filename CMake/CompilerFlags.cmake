SET("CPU_FEATURES" "-mmmx -msse -msse2 -msse3 -mssse3 -msahf -mcx16")

MESSAGE("Enabled x86 CPU features: ${CPU_FEATURES}")

# Print info:
IF(CMAKE_BUILD_TYPE STREQUAL "Release")
	MESSAGE("Release build, using all optimization flags")
ENDIF()

IF(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" AND "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC") # detect clang-cl
	SET("IS_CLANG_CL" TRUE)
	MESSAGE("Using Clang-CL driver")
	SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} ${DEFAULT_FLAGS} ${CPU_FEATURES} -Xclang -Wall -Xclang -Wextra -Xclang -Xclang -std=c++20 -Xclang -Wno-unknown-attributes -Xclang -Wno-ignored-attributes -Xclang -Wno-deprecated-declarations")
	IF(CMAKE_BUILD_TYPE STREQUAL "Release") 	# if release, set more optimization flags:
		SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} /EHsc /D_HAS_EXCEPTIONS=0 -Xclang -Ofast -Xclang -flto -Xclang -ffp-exception-behavior=ignore")
	ENDIF()
	IF(${CORIUM_FAST_MATH} AND CMAKE_BUILD_TYPE STREQUAL "Release") 	# if fast math is enabled, add flags:
		SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} -Xclang -ffast-math")
	ENDIF()
ELSE() # if not clang/cl use clang or GCC flags:
	SET("IS_CLANG_CL" FALSE)
	SET("Using Clang/GCC directly")
        SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} ${DEFAULT_FLAGS} ${CPU_FEATURES} -Wall -Wextra -std=c++20 -Wno-unknown-attributes -Wno-ignored-attributes -Wno-deprecated-declarations")
	IF(CMAKE_BUILD_TYPE STREQUAL "Release") 	# why does -flto give linker errors?!
		SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} -Ofast -fopenmp -fno-exceptions -fomit-frame-pointer")
	ENDIF()
	IF(${CORIUM_FAST_MATH} AND CMAKE_BUILD_TYPE STREQUAL "Release") 	# if fast math is enabled, add flags:
		SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} -ffast-math")
	ENDIF()
ENDIF()
SET("CMAKE_C_FLAGS" "${CMAKE_CXX_FLAGS}")
MESSAGE("Final compilation flags: ${CMAKE_CXX_FLAGS}")
