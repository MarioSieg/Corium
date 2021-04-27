IF (${CORIUM_BUILD_BENCHMARKS})
	FILE(GLOB_RECURSE "NOMINAX_BENCHMARK_SOURCES" "Nominax/Benchmarks/*.cpp")
	ADD_EXECUTABLE("NominaxBenchmarks" "${NOMINAX_BENCHMARK_SOURCES}")
	TARGET_INCLUDE_DIRECTORIES("NominaxBenchmarks" PUBLIC "${BENCHMARK_INCLUDE}")
	TARGET_LINK_LIBRARIES("NominaxBenchmarks" "benchmark::benchmark")
	TARGET_LINK_LIBRARIES("NominaxBenchmarks" "Nominax")

	# with GCC we need to link posix threads
	IF (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        TARGET_LINK_LIBRARIES("NominaxBenchmarks" "pthread")
    ENDIF()
ENDIF()