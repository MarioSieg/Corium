#pragma once

#include <cmath>
#include <mutex>

#include "macrocfg.hpp"
#include "platform.hpp"
#include "record.hpp"

#include <ctime>

namespace nominax {
	[[nodiscard]]
	__attribute__((flatten)) inline auto rol(const u64 n_, const i32 x_) noexcept -> u64 {
		#if NOMINAX_USE_ARCH_OPT && NOMINAX_ARCH_X86_64 || NOMINAX_ARCH_X86_32
			return _rotl64(n_, x_);
		#else
			return std::rotl<decltype(x)>(n_, x_);
		#endif
	}

	[[nodiscard]]
	__attribute__((flatten)) inline auto ror(const u64 n_, const i32 x_) noexcept -> u64 {
		#if NOMINAX_USE_ARCH_OPT && NOMINAX_ARCH_X86_64 || NOMINAX_ARCH_X86_32
				return _rotr64(n_, x_);
		#else
				return std::rotr<decltype(x)>(n_, x_);
		#endif
	}

	__attribute__((flatten)) inline void operator %=(record64& x_, const f64 y_) noexcept {
		x_.f = std::fmod(x_.f, y_);
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
	__attribute((flatten)) inline void hard_fault_trap() noexcept {
		std::abort();
	}

	__attribute__((flatten)) inline void read_fence() noexcept {
		asm volatile("":::"memory");
	}

	__attribute__((flatten)) inline void write_fence() noexcept {
		asm volatile("":::"memory");
	}

	__attribute__((flatten)) inline void read_write_fence() noexcept {
		asm volatile("":::"memory");
	}

	union f32_repr {
		explicit constexpr f32_repr(f32 x_) noexcept;
		
		f32 f;
		i32 i;

		[[nodiscard]] constexpr auto is_negative() const noexcept -> bool;
		[[nodiscard]] constexpr auto raw_mantissa() const noexcept -> std::uint32_t;
		[[nodiscard]] constexpr auto raw_exponent() const noexcept -> std::uint8_t;

	private:
		struct {
			std::uint32_t mantissa	: 23;
			std::uint32_t exponent	: 8;
			std::uint32_t sign		: 1;
		};
	};

	static_assert(sizeof(f32_repr) == 4);

	__attribute__((flatten)) constexpr f32_repr::f32_repr(const f32 x_) noexcept : f(x_) {}
	__attribute__((flatten)) constexpr auto f32_repr::is_negative() const noexcept -> bool { return (this->i >> 31) != 0; }
	__attribute__((flatten)) constexpr auto f32_repr::raw_mantissa() const noexcept -> std::uint32_t { return this->i & ((1 << 23) - 1); }
	__attribute__((flatten)) constexpr auto f32_repr::raw_exponent() const noexcept -> std::uint8_t { return (this->i >> 23) & 0xFF; }

	#if false
	[[deprecated("unsafe")]]
	[[maybe_unused]]
	__attribute__((always_inline)) inline auto ftoi_fast(const f32 x_) noexcept -> i32 {
	#if NOMINAX_ARCH_X86_64 && NOMINAX_NO_SSE
		i32 r;
		asm volatile(
			"fistp %0\n"
			: "=m"(r)
			: "t"(x_)
			: "st"
			);
		return r;
	#elif NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT && __SSE2__ && NOMINAX_NO_ARCH_INTRIN
		i32 r;
		asm volatile(
			"cvtss2si %%xmm0, %%eax\n"
			"movl %%eax, %0\n"
			: "=r"(r)
			: "r"(x_)
		);
	#elif NOMINAX_ARCH_X86_64 && NOMINAX_USE_ARCH_OPT && __SSE2__ && !NOMINAX_NO_ARCH_INTRIN
		return _mm_cvt_ss2si(_mm_set_ss(x_));
	#else
		return static_cast<i32>(x_);
	#endif
	}
	#endif

	[[nodiscard]]
	inline auto safe_localtime(const std::time_t& time_) -> std::tm {
		std::tm buf{};
		#if NOMINAX_POSIX
			localtime_r(&time, &buf);
		#elif NOMINAX_OS_WINDOWS
			localtime_s(&buf, &time_);
		#else
			static std::mutex mtx;
			std::lock_guard<decltype(mtx)> lock(mtx);
			buf = *std::localtime(&time);
		#endif
		return buf;
	}
}