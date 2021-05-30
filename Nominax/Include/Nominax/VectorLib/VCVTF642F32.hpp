#pragma once

#include "VBase.hpp"

namespace Nominax::VectorLib
{
	__attribute__((always_inline)) inline auto F64_X2_To_F32_X2(F32* const __restrict__ out, const F64* const __restrict__ in) noexcept(true) -> void
	{
#if NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT && defined(__SSE__)
		const __m128d x = _mm_loadu_pd(in);
		const __m128 y = _mm_cvtpd_ps(x);
		_mm_storel_pi(reinterpret_cast<__m64*>(out), y);
#else
		out[0] = static_cast<F32>(in[0]);
		out[1] = static_cast<F32>(in[1]);
#endif
	}

	__attribute__((always_inline)) inline auto F64_X4_To_F32_X4(F32* const __restrict__ out, const F64* const __restrict__ in) noexcept(true) -> void
	{
#if NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT && defined(__AVX__)
		
		const __m256d x = _mm256_loadu_pd(in);		// 32 B - 4 * F64
		const __m128 y = _mm256_cvtpd_ps(x);		// 16 B - 4 * F32
		_mm_storeu_ps(out, y);

		
#elif NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT && defined(__SSE__)

		const __m128d x1 = _mm_loadu_pd(in);		// 16 B - 2 * F64
		const __m128d x2 = _mm_loadu_pd(in + 2);	// 16 B - 2 * F64
		const __m128 y1 = _mm_cvtpd_ps(x1);			// 8 B - 2 * F32
		__m128 y2 = _mm_cvtpd_ps(x2);				// 8 B - 2 * F32
		y2 = _mm_movelh_ps(y2, y1);					// y1_lo -> y2_hi
		_mm_storeu_ps(out, y2);
		
#else
		out[0] = static_cast<F32>(in[0]);
		out[1] = static_cast<F32>(in[1]);
		out[2] = static_cast<F32>(in[2]);
		out[3] = static_cast<F32>(in[3]);
#endif
	}
}