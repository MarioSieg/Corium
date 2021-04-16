#include "benchmark.h"

#include <thread>

static void test([[maybe_unused]] benchmark::State& state) {
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(100ms);
}

BENCHMARK(test);

BENCHMARK_MAIN();