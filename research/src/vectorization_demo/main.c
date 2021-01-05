#include <inttypes.h>
#include <stdio.h>
#include <immintrin.h>
#include <time.h>

#define TEST_ITERATIONS 100000000

typedef __declspec(align(16)) struct
{
	int32_t v;
} aligned_int32_t;

// Addiert die 16 Integer mit einer primitiv ausgerollten Schleife.
void add_16_integers_unrolled_loop(register int32_t(*__restrict const _x)[8], const register int32_t(*__restrict const _y)[8])
{
	**_x += **_y;
	*(*_x + 1) += *(*_y + 1);
	*(*_x + 2) += *(*_y + 2);
	*(*_x + 3) += *(*_y + 3);
	*(*_x + 4) += *(*_y + 4);
	*(*_x + 5) += *(*_y + 5);
	*(*_x + 6) += *(*_y + 6);
	*(*_x + 7) += *(*_y + 7);
	*(*_x + 8) += *(*_y + 8);
}

// TODO: Fix
void add_16_integers_avx(register int32_t(*__restrict const _x)[8], const register int32_t(*__restrict const _y)[8])
{
	__m256i x = _mm256_load_si256(*_x); 	// Lädt die Daten aus "_x" in ein ymm* register (AVX). Nimmt an dass "_x" eine 16 Byte Ausrichtung hat.
	__m256i y = _mm256_load_si256(*_y);		// Lädt die Daten aus "_y" in ein ymm* register (AVX). Nimmt an dass "_y" eine 16 Byte Ausrichtung hat.
	__m256i r = _mm256_add_epi32(x, y);		
	_mm256_store_si256((__m256i*)*_x, r);
}

void add_16_integers_loop(register int32_t(*const _x)[8], const register int32_t(*const _y)[8])
{
	for(register unsigned i = 0; i < 16; ++i)
	{
		(*_x)[i] += (*_y)[i];
	}
}

signed int main(const signed int _argc, const char* const *const _argv)
{
	aligned_int32_t test_data_x[8];
	aligned_int32_t test_data_y[8];
	
	for(register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		test_data_x[i].v = test_data_y[i].v = i * i;
	}

	printf("Benchmarking calculations... %u iterations over %zu 32-bit signed integers!\n", TEST_ITERATIONS, sizeof test_data_x / sizeof *test_data_x);

#ifndef __AVX__
	printf("Warning! AVX is not enabled!\n");
#endif
	
	// Teste AVX2:
	printf("Testing \"add_16_integers_avx\"...\n");
	clock_t tick = clock();
	for(register unsigned int i = 0; i < TEST_ITERATIONS; ++i)
	{
		add_16_integers_avx((int32_t(*const)[8])&test_data_x, (const int32_t(*const)[8])&test_data_y);
	}
	printf("Needed %fs\n", (double)(clock() - tick) / CLOCKS_PER_SEC);
	for(register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		printf("%" PRIi32, test_data_x[i].v);
	}
	putchar('\n');

	// Teste ausgerollte Schleife:
	printf("Testing \"add_16_integers_unrolled_loop\"...\n");
	tick = clock();
	for (register unsigned int i = 0; i < TEST_ITERATIONS; ++i)
	{
		add_16_integers_unrolled_loop((int32_t(*const)[8])&test_data_x, (const int32_t(*const)[8])&test_data_y);
	}
	printf("Needed %fs\n", (double)(clock() - tick) / CLOCKS_PER_SEC);
	for (register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		printf("%" PRIi32, test_data_x[i].v);
	}
	putchar('\n');

	// Teste Schleife:
	printf("Testing \"add_16_integers_loop\"...\n");
	tick = clock();
	for (register unsigned int i = 0; i < TEST_ITERATIONS; ++i)
	{
		add_16_integers_loop((int32_t(*const)[8])&test_data_x, (const int32_t(*const)[8])&test_data_y);
	}
	printf("Needed %fs\n", (double)(clock() - tick) / CLOCKS_PER_SEC);
	for (register unsigned int i = 0; i < sizeof test_data_x / sizeof *test_data_x; ++i)
	{
		printf("%" PRIi32, test_data_x[i].v);
	}
	putchar('\n');
}