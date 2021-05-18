SET("CPU_FEATURES" "-mmmx -msse -msse2 -msse3 -mssse3 -msahf -mcx16")

MESSAGE("Enabled x86 CPU features: ${CPU_FEATURES}")

# Print info:
IF(CMAKE_BUILD_TYPE STREQUAL "Release")
	MESSAGE("Release build, using all optimization flags")
ENDIF()

# detect clang-cl
IF(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" AND "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
	MESSAGE("Using Clang-CL driver")

	# clang-cl common args:
	SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} ${DEFAULT_FLAGS} ${CPU_FEATURES}  -Xclang -Wall  -Xclang -Wextra  -Xclang -Werror -Xclang -Wno-undef -Xclang -std=c++20 -Xclang -Wno-unknown-attributes -Xclang -Wno-ignored-attributes -Xclang -Wno-deprecated-declarations")
	
	# if release, set more optimization flags:
	# -Xclang -fno-rtti
	IF(CMAKE_BUILD_TYPE STREQUAL "Release")
		SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} -Xclang -Ofast -Xclang -flto -Xclang -ffp-exception-behavior=ignore /EHsc /D_HAS_EXCEPTIONS=0")
	ENDIF()

	# if fast math is enabled, add flags:
	IF(${CORIUM_FAST_MATH} AND CMAKE_BUILD_TYPE STREQUAL "Release")
		SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} -Xclang -ffast-math")
	ENDIF()
# if not clang/cl use clang or GCC flags:
ELSE()
	SET("Using Clang/GCC directly")

	# gcc/clang common flags:
        SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} ${DEFAULT_FLAGS} ${CPU_FEATURES} -Wall -Wextra -Werror -Wno-undef -std=c++20 -Wno-unknown-attributes -Wno-ignored-attributes -Wno-deprecated-declarations")

	# if release, set more optimization flags:
	# -fno-rtti
	# why does -flto give linker errors?!
	IF(CMAKE_BUILD_TYPE STREQUAL "Release")
		SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} -Ofast -fno-exceptions")
	ENDIF()

	# if fast math is enabled, add flags:
	IF(${CORIUM_FAST_MATH} AND CMAKE_BUILD_TYPE STREQUAL "Release")
		SET("CMAKE_CXX_FLAGS" "${CMAKE_CXX_FLAGS} -ffast-math")
	ENDIF()
ENDIF()

SET("CMAKE_C_FLAGS" "${CMAKE_CXX_FLAGS}")
MESSAGE("Final compilation flags: ${CMAKE_CXX_FLAGS}")
