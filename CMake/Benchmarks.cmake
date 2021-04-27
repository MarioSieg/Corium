IF (${CORIUM_BUILD_BENCHMARKS})
	ADD_SUBDIRECTORY("SharedTools/googlebench")
	SET("BENCHMARK_INCLUDE" "SharedTools/googlebench/include/benchmark/")
ENDIF()