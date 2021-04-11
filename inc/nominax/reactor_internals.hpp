#pragma once

#include <cmath>
#include <mutex>

#include "macrocfg.hpp"
#include "platform.hpp"
#include "record.hpp"

#include <ctime>

namespace nominax {
	[[nodiscard]]
	__attribute__((always_inline)) inline auto rol(const u32 n, u32 x) noexcept -> u32 {
		#if NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT && !NOMINAX_NO_ARCH_INTRIN
			return _rotl(n, x);
		#else
			return std::rotl<decltype(x)>(n, x);
		#endif
	}

	[[nodiscard]]
	__attribute__((always_inline)) inline auto ror(const u32 n, u32 x) noexcept -> u32 {
		#if NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT && !NOMINAX_NO_ARCH_INTRIN
				return _rotr(n, x);
		#else
				return std::rotr<decltype(x)>(n, x);
		#endif
	}

	__attribute__((always_inline)) inline void operator %=(record32& x, const f32 y) noexcept {
		x.f = std::fmod(x.f, y);
	}

	__attribute__((always_inline)) inline void breakpoint_interrupt() noexcept {
		#if NOMINAX_ARCH_X86_64
			asm("int $3");
		#elif NOMINAX_ARCH_ARM_64
			#if NOMINAX_OS_MAC || NOMINAX_OS_IOS
				asm("trap");
			#else
				asm("bkpt 0");
			#endif
		#else
			auto* int3 = reinterpret_cast<int*>(3);
			*int3 = 3;
		#endif
	}

	[[noreturn]]
	__attribute((always_inline)) inline void hard_fault_trap() noexcept {
		std::abort();
	}

	__attribute__((always_inline)) inline void read_fence() noexcept {
		asm volatile("":::"memory");
	}

	__attribute__((always_inline)) inline void write_fence() noexcept {
		asm volatile("":::"memory");
	}

	__attribute__((always_inline)) inline void read_write_fence() noexcept {
		asm volatile("":::"memory");
	}

	#if false
	[[deprecated("unsafe")]]
	[[maybe_unused]]
	__attribute__((always_inline)) inline auto ftoi_fast(const f32 x) noexcept -> i32 {
	#if NOMINAX_ARCH_X86_64 && NOMINAX_NO_SSE
		i32 r;
		asm volatile(
			"fistp %0\n"
			: "=m"(r)
			: "t"(x)
			: "st"
			);
		return r;
	#elif NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT && __SSE2__ && NOMINAX_NO_ARCH_INTRIN
		i32 r;
		asm volatile(
			"cvtss2si %%xmm0, %%eax\n"
			"movl %%eax, %0\n"
			: "=r"(r)
			: "r"(x)
		);
	#elif NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT && __SSE2__ && !NOMINAX_NO_ARCH_INTRIN
		return _mm_cvt_ss2si(_mm_set_ss(x));
	#else
		return static_cast<i32>(x);
	#endif
	}
	#endif

	[[nodiscard]]
	inline auto safe_localtime(const std::time_t& time) -> std::tm {
		std::tm buf{};
		#if NOMINAX_POSIX
			localtime_r(&time, &buf);
		#elif NOMINAX_OS_WINDOWS
			localtime_s(&buf, &time);
		#else
			static std::mutex mtx;
			std::lock_guard<decltype(mtx)> lock(mtx);
			buf = *std::localtime(&time);
		#endif
		return buf;
	}
}