#pragma once

#include <bit>
#include <ctime>
#include <cmath>
#include <mutex>

#include "macrocfg.hpp"
#include "platform.hpp"
#include "record.hpp"

namespace nominax {
	[[nodiscard]]
	__attribute__((flatten, pure)) inline auto rol(const u64 n_, const i32 x_) noexcept -> u64 {
        #if NOMINAX_OS_WINDOWS && NOMINAX_USE_ARCH_OPT && (NOMINAX_ARCH_X86_64 || NOMINAX_ARCH_X86_32)
			return _rotl64(n_, x_);
		#else
            return std::rotl<u64>(n_, x_);
		#endif
	}

	[[nodiscard]]
	__attribute__((flatten, pure)) inline auto ror(const u64 n_, const i32 x_) noexcept -> u64 {
        #if NOMINAX_OS_WINDOWS && NOMINAX_USE_ARCH_OPT && (NOMINAX_ARCH_X86_64 || NOMINAX_ARCH_X86_32)
				return _rotr64(n_, x_);
		#else
                return std::rotr<u64>(n_, x_);
		#endif
	}

	__attribute__((flatten)) inline void operator %=(record64& x_, const f64 y_) noexcept {
		x_.f = std::fmod(x_.f, y_);
	}

	#if NOMINAX_ARCH_X86_32 || NOMINAX_ARCH_X86_64
	
	[[nodiscard]]
	__attribute__((flatten, cold)) inline auto query_pi64_from_x87fpu() noexcept -> f64 {
		f64 pi;
		asm volatile (
			"fldpi\n"
			"fstpl %0\n"
			: "=m"(pi)
			:
			:
		);
		return pi;
	}

	[[nodiscard]]
	__attribute__((flatten, cold)) inline auto query_pi32_from_x87fpu() noexcept -> f32 {
		f32 pi;
		asm volatile (
			"fldpi\n"
			"fstps %0\n"
			: "=m"(pi)
			:
			:
		);
		return pi;
	}

	#endif

	enum class stack_growth_direction {
		upward,
		downward
	};

	__attribute__((noinline, cold)) constexpr auto sub_determine_stack_growth_direction(const int* const super_ptr_) noexcept -> stack_growth_direction {
		const int sub{};
		return super_ptr_ < &sub ? stack_growth_direction::upward : stack_growth_direction::downward;
	}
	
	/// <summary>
	/// Might return wrong results, for debugging only.
	/// The stack may not grow up or down.
	/// Each stack frame can potentially be allocated at random points inside the heap.
	/// This is actually done in several OS to try and prevent stack smashing by malicious code.
	/// </summary>
	__attribute__((noinline, cold)) constexpr auto determine_stack_growth_direction() noexcept -> stack_growth_direction {
		const int super{};
		return sub_determine_stack_growth_direction(&super);
	}

	__attribute__((always_inline, cold)) inline void breakpoint_interrupt() noexcept {
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

	__attribute__((flatten)) inline void read_fence() noexcept {
		asm volatile("":::"memory");
	}

	__attribute__((flatten)) inline void write_fence() noexcept {
		asm volatile("":::"memory");
	}

	__attribute__((flatten)) inline void read_write_fence() noexcept {
		asm volatile("":::"memory");
	}

	[[nodiscard]]
	inline auto safe_localtime(const std::time_t& time_) -> std::tm {
		std::tm buf{};
		#if NOMINAX_POSIX
            localtime_r(&time_, &buf);
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
