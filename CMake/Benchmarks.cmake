IF (${NOMINAX_BUILD_BENCHMARKS})
	ADD_SUBDIRECTORY("Tools/benchmark")
	SET("BENCHMARK_INCLUDE" "Tools/benchmark/include/benchmark/")
ENDIF()