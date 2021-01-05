#include <inttypes.h>
#include <stdio.h>
#include <immintrin.h>
#include <time.h>

#define TEST_ITERATIONS 2000000000

#if defined(__clang__) || defined(__GNUC__)
#define ALIGN_16 __attribute__((aligned(16)))
#define __restrict restrict
#elif defined(_MSC_VER)
#define ALIGN_16 __declspec(align(16))
#endif

typedef ALIGN_16 struct
{
	int32_t v;
} aligned_int32_t;

// Addiert die 16 Integer mit einer primitiv ausgerollten Schleife.
void add_16_integers_unrolled_loop(register int64_t(*__restrict const _x)[8], const register int64_t(*__restrict const _y)[8])
{
	(**_x) += (**_y);
	(*(*_x + 1)) += (*(*_y + 1));
	(*(*_x + 2)) += (*(*_y + 2));
	(*(*_x + 3)) += (*(*_y + 3));
	(*(*_x + 4)) += (*(*_y + 4));
	(*(*_x + 5)) += (*(*_y + 5));
	(*(*_x + 6)) += (*(*_y + 6));
	(*(*_x + 7)) += (*(*_y + 7));
	(*(*_x + 8)) += (*(*_y + 8));
}

void add_16_integers_explicit_avx2(register int64_t(*__restrict const _x)[8], const register int64_t(*__restrict const _y)[8])
{
	const __m256i x_lo = _mm256_loadu_si256(*_x);
	const __m256i y_lo = _mm256_loadu_si256(*_y);
	const __m256i x_hi = _mm256_loadu_si256(*_x + 4);
	const __m256i y_hi = _mm256_loadu_si256(*_y + 4);
	const __m256i r_lo = _mm256_add_epi32(x_lo, y_lo);
	const __m256i r_hi = _mm256_add_epi32(x_hi, y_hi);
	_mm256_storeu_si256(*_x, r_lo);
	_mm256_storeu_si256(*_x + 4, r_hi);
}

void add_16_integers_loop(register int64_t(* const _x)[8], const register int64_t(* const _y)[8])
{
	for (register unsigned i = 0; i < sizeof *_x / sizeof **_x; ++i)
	{
		(*_x)[i] += (*_y)[i];
	}
}

#define FILL_DUMMY_FUNC(_x) ((_x) + (_x))

signed int main(const signed int _argc, const char* const* const _argv)
{
	int64_t test_data_x[8];
	int64_t test_data_y[8];

	for (register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		test_data_x[i] = test_data_y[i] = FILL_DUMMY_FUNC(i);
	}

	printf("Benchmarking calculations... %u iterations over %zu 32-bit signed integers!\n", TEST_ITERATIONS, sizeof test_data_x / sizeof * test_data_x);

#ifndef __AVX2__
	printf("Warning! AVX is not enabled!\n");
#endif

	printf("Original values: ");
	for (register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		printf(" %" PRIi64, test_data_x[i]);
	}
	putchar('\n');

	// Teste AVX2:
	printf("Testing \"add_16_integers_explicit_avx2\"...\n");
	clock_t tick = clock();
	for (register unsigned int i = 0; i < TEST_ITERATIONS; ++i)
	{
		add_16_integers_explicit_avx2(&test_data_x, &test_data_y);
	}
	printf("Needed %fs\n", (double)(clock() - tick) / CLOCKS_PER_SEC);
	for (register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		printf(" %" PRIi64, test_data_x[i]);
	}
	putchar('\n');

	// Teste ausgerollte Schleife:
	for (register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		test_data_x[i] = test_data_y[i] = FILL_DUMMY_FUNC(i);
	}
	printf("Testing \"add_16_integers_unrolled_loop\"...\n");
	tick = clock();
	for (register unsigned int i = 0; i < TEST_ITERATIONS; ++i)
	{
		add_16_integers_unrolled_loop(&test_data_x, &test_data_y);
	}
	printf("Needed %fs\n", (double)(clock() - tick) / CLOCKS_PER_SEC);
	for (register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		printf(" %" PRIi64, test_data_x[i]);
	}
	putchar('\n');

	// Teste Schleife:
	for (register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		test_data_x[i] = test_data_y[i] = FILL_DUMMY_FUNC(i);
	}
	printf("Testing \"add_16_integers_loop\"...\n");
	tick = clock();
	for (register unsigned int i = 0; i < TEST_ITERATIONS; ++i)
	{
		add_16_integers_loop(&test_data_x, &test_data_y);
	}
	printf("Needed %fs\n", (double)(clock() - tick) / CLOCKS_PER_SEC);
	for (register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		printf(" %" PRIi64, test_data_x[i]);
	}
	putchar('\n');
}