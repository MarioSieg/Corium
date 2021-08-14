IF (${CORIUM_BUILD_BENCHMARKS})
	FILE(GLOB_RECURSE "NOMINAX_BENCHMARK_SOURCES" "Nominax/Benchmarks/*.cpp")
	ADD_EXECUTABLE("NominaxBenchmark" "${NOMINAX_BENCHMARK_SOURCES}")
	SET_PROPERTY(TARGET "NominaxBenchmark" PROPERTY CXX_STANDARD 20)
	TARGET_INCLUDE_DIRECTORIES("NominaxBenchmark" PUBLIC "Tools/benchmark/include")
	TARGET_LINK_LIBRARIES("NominaxBenchmark" "benchmark::benchmark")
	TARGET_LINK_LIBRARIES("NominaxBenchmark" "NominaxRuntime")
	TARGET_COMPILE_OPTIONS("NominaxBenchmark" PRIVATE "-Ofast")

	# with GCC we need to link posix threads
	IF (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        TARGET_LINK_LIBRARIES("NominaxBenchmark" "pthread")
    ENDIF()
ENDIF()
