// File: Foundation.hpp
// Author: Mario
// Created: 26.07.2021 6:43 PM
// Project: NominaxRuntime
// 
//                                  Apache License
//                            Version 2.0, January 2004
//                         http://www.apache.org/licenses/
// 
//    TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
// 
//    1. Definitions.
// 
//       "License" shall mean the terms and conditions for use, reproduction,
//       and distribution as defined by Sections 1 through 9 of this document.
// 
//       "Licensor" shall mean the copyright owner or entity authorized by
//       the copyright owner that is granting the License.
// 
//       "Legal Entity" shall mean the union of the acting entity and all
//       other entities that control, are controlled by, or are under common
//       control with that entity. For the purposes of this definition,
//       "control" means (i) the power, direct or indirect, to cause the
//       direction or management of such entity, whether by contract or
//       otherwise, or (ii) ownership of fifty percent (50%) or more of the
//       outstanding shares, or (iii) beneficial ownership of such entity.
// 
//       "You" (or "Your") shall mean an individual or Legal Entity
//       exercising permissions granted by this License.
// 
//       "Source" form shall mean the preferred form for making modifications,
//       including but not limited to software source code, documentation
//       source, and configuration files.
// 
//       "Object" form shall mean any form resulting from mechanical
//       transformation or translation of a Source form, including but
//       not limited to compiled object code, generated documentation,
//       and conversions to other media types.
// 
//       "Work" shall mean the work of authorship, whether in Source or
//       Object form, made available under the License, as indicated by a
//       copyright notice that is included in or attached to the work
//       (an example is provided in the Appendix below).
// 
//       "Derivative Works" shall mean any work, whether in Source or Object
//       form, that is based on (or derived from) the Work and for which the
//       editorial revisions, annotations, elaborations, or other modifications
//       represent, as a whole, an original work of authorship. For the purposes
//       of this License, Derivative Works shall not include works that remain
//       separable from, or merely link (or bind by name) to the interfaces of,
//       the Work and Derivative Works thereof.
// 
//       "Contribution" shall mean any work of authorship, including
//       the original version of the Work and any modifications or additions
//       to that Work or Derivative Works thereof, that is intentionally
//       submitted to Licensor for inclusion in the Work by the copyright owner
//       or by an individual or Legal Entity authorized to submit on behalf of
//       the copyright owner. For the purposes of this definition, "submitted"
//       means any form of electronic, verbal, or written communication sent
//       to the Licensor or its representatives, including but not limited to
//       communication on electronic mailing lists, source code control systems,
//       and issue tracking systems that are managed by, or on behalf of, the
//       Licensor for the purpose of discussing and improving the Work, but
//       excluding communication that is conspicuously marked or otherwise
//       designated in writing by the copyright owner as "Not a Contribution."
// 
//       "Contributor" shall mean Licensor and any individual or Legal Entity
//       on behalf of whom a Contribution has been received by Licensor and
//       subsequently incorporated within the Work.
// 
//    2. Grant of Copyright License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       copyright license to reproduce, prepare Derivative Works of,
//       publicly display, publicly perform, sublicense, and distribute the
//       Work and such Derivative Works in Source or Object form.
// 
//    3. Grant of Patent License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       (except as stated in this section) patent license to make, have made,
//       use, offer to sell, sell, import, and otherwise transfer the Work,
//       where such license applies only to those patent claims licensable
//       by such Contributor that are necessarily infringed by their
//       Contribution(s) alone or by combination of their Contribution(s)
//       with the Work to which such Contribution(s) was submitted. If You
//       institute patent litigation against any entity (including a
//       cross-claim or counterclaim in a lawsuit) alleging that the Work
//       or a Contribution incorporated within the Work constitutes direct
//       or contributory patent infringement, then any patent licenses
//       granted to You under this License for that Work shall terminate
//       as of the date such litigation is filed.
// 
//    4. Redistribution. You may reproduce and distribute copies of the
//       Work or Derivative Works thereof in any medium, with or without
//       modifications, and in Source or Object form, provided that You
//       meet the following conditions:
// 
//       (a) You must give any other recipients of the Work or
//           Derivative Works a copy of this License; and
// 
//       (b) You must cause any modified files to carry prominent notices
//           stating that You changed the files; and
// 
//       (c) You must retain, in the Source form of any Derivative Works
//           that You distribute, all copyright, patent, trademark, and
//           attribution notices from the Source form of the Work,
//           excluding those notices that do not pertain to any part of
//           the Derivative Works; and
// 
//       (d) If the Work includes a "NOTICE" text file as part of its
//           distribution, then any Derivative Works that You distribute must
//           include a readable copy of the attribution notices contained
//           within such NOTICE file, excluding those notices that do not
//           pertain to any part of the Derivative Works, in at least one
//           of the following places: within a NOTICE text file distributed
//           as part of the Derivative Works; within the Source form or
//           documentation, if provided along with the Derivative Works; or,
//           within a display generated by the Derivative Works, if and
//           wherever such third-party notices normally appear. The contents
//           of the NOTICE file are for informational purposes only and
//           do not modify the License. You may add Your own attribution
//           notices within Derivative Works that You distribute, alongside
//           or as an addendum to the NOTICE text from the Work, provided
//           that such additional attribution notices cannot be construed
//           as modifying the License.
// 
//       You may add Your own copyright statement to Your modifications and
//       may provide additional or different license terms and conditions
//       for use, reproduction, or distribution of Your modifications, or
//       for any such Derivative Works as a whole, provided Your use,
//       reproduction, and distribution of the Work otherwise complies with
//       the conditions stated in this License.
// 
//    5. Submission of Contributions. Unless You explicitly state otherwise,
//       any Contribution intentionally submitted for inclusion in the Work
//       by You to the Licensor shall be under the terms and conditions of
//       this License, without any additional terms or conditions.
//       Notwithstanding the above, nothing herein shall supersede or modify
//       the terms of any separate license agreement you may have executed
//       with Licensor regarding such Contributions.
// 
//    6. Trademarks. This License does not grant permission to use the trade
//       names, trademarks, service marks, or product names of the Licensor,
//       except as required for reasonable and customary use in describing the
//       origin of the Work and reproducing the content of the NOTICE file.
// 
//    7. Disclaimer of Warranty. Unless required by applicable law or
//       agreed to in writing, Licensor provides the Work (and each
//       Contributor provides its Contributions) on an "AS IS" BASIS,
//       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
//       implied, including, without limitation, any warranties or conditions
//       of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
//       PARTICULAR PURPOSE. You are solely responsible for determining the
//       appropriateness of using or redistributing the Work and assume any
//       risks associated with Your exercise of permissions under this License.
// 
//    8. Limitation of Liability. In no event and under no legal theory,
//       whether in tort (including negligence), contract, or otherwise,
//       unless required by applicable law (such as deliberate and grossly
//       negligent acts) or agreed to in writing, shall any Contributor be
//       liable to You for damages, including any direct, indirect, special,
//       incidental, or consequential damages of any character arising as a
//       result of this License or out of the use or inability to use the
//       Work (including but not limited to damages for loss of goodwill,
//       work stoppage, computer failure or malfunction, or any and all
//       other commercial damages or losses), even if such Contributor
//       has been advised of the possibility of such damages.
// 
//    9. Accepting Warranty or Additional Liability. While redistributing
//       the Work or Derivative Works thereof, You may choose to offer,
//       and charge a fee for, acceptance of support, warranty, indemnity,
//       or other liability obligations and/or rights consistent with this
//       License. However, in accepting such obligations, You may act only
//       on Your own behalf and on Your sole responsibility, not on behalf
//       of any other Contributor, and only if You agree to indemnify,
//       defend, and hold each Contributor harmless for any liability
//       incurred by, or claims asserted against, such Contributor by reason
//       of your accepting any such warranty or additional liability.
// 
//    END OF TERMS AND CONDITIONS
// 
//    APPENDIX: How to apply the Apache License to your work.
// 
//       To apply the Apache License to your work, attach the following
//       boilerplate notice, with the fields enclosed by brackets "[]"
//       replaced with your own identifying information. (Don't include
//       the brackets!)  The text should be enclosed in the appropriate
//       comment syntax for the file format. We also recommend that a
//       file or class name and description of purpose be included on the
//       same "printed page" as the copyright notice for easier
//       identification within third-party archives.
// 
//    Copyright 2021 Mario Sieg "pinsrq" <mt3000@gmx.de>
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#pragma once

#include <algorithm>
#include <array>
#include <atomic>
#include <bit>
#include <bitset>
#include <condition_variable>
#include <climits>
#include <csignal>
#include <cstring>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <execution>
#include <filesystem>
#include <functional>
#include <fstream>
#include <functional>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <memory_resource>
#include <mutex>
#include <optional>
#include <queue>
#include <string>
#include <string_view>
#include <span>
#include <stack>
#include <thread>
#include <type_traits>
#include <unordered_set>
#include <variant>

#if _WIN64
#	include <malloc.h>
#else
#	include <alloca.h>
#endif

// Will be replaced by std::format soon
#include <fmt/format.h>
#include <fmt/chrono.h>
#include <fmt/color.h>

namespace Nominax
{
	/// <summary>
	/// True if we are compiling for Windows, else false.
	/// </summary>
	#define NOX_OS_WINDOWS	false

	/// <summary>
	///True if we are compiling for macOS, else false.
	/// </summary>
	#define NOX_OS_MAC		false

	/// <summary>
	// True if we are compiling for Linux, else false.
	/// </summary>
	#define NOX_OS_LINUX	false

	/// <summary>
	///True if we are compiling for Android, else false.
	/// </summary>
	#define NOX_OS_ANDROID	false

	/// <summary>
	///True if we are compiling for iOS, else false.
	/// </summary>
	#define NOX_OS_IOS		false

	/// <summary>
	///True if we are compiling for x86-64 (AMD 64) (CISC)
	/// </summary>
	#define NOX_ARCH_X86_64	false

	/// <summary>
	///True if we are compiling for ARM 64 (RISC)
	/// </summary>
	#define NOX_ARCH_ARM_64	false

	/// <summary>
	///True if we are compiling in release mode
	///for max performance.
	/// </summary>
	#define NOX_RELEASE		false

	/// <summary>
	///True if we are compiling for debug mode.
	/// </summary>
	#define NOX_DEBUG		false

	/// <summary>
	///True if we are compiling using the (GCC) GNU Compiler Collection.
	/// </summary>
	#define NOX_COM_GCC		false

	/// <summary>
	///True if we are compiling using LLVM Clang.
	/// </summary>
	#define NOX_COM_CLANG	false

	/// <summary>
	///True if we are compiling using MinGW (Minimalist GNU for Windows).
	/// </summary>
	#define NOX_COM_MINGW	false

	#ifdef NDEBUG
	#	undef NOX_RELEASE
	#	define NOX_RELEASE true
	#	define NOX_DEBUG_ONLY(expr)
	#else
	#	undef NOX_DEBUG
	#	define NOX_DEBUG true
	#	define NOX_DEBUG_ONLY(expr) expr
	#endif

	#if defined(_WIN64) || defined(__CYGWIN__)
	#	undef NOX_OS_WINDOWS
	#	define NOX_OS_WINDOWS true
	#	define NOX_OS_NAME "Windows"
	#elif defined(__APPLE__)
	#	include <TargetConditionals.h>
	#	if TARGET_OS_MAC
	#		undef NOX_OS_MAC
	#		define NOX_OS_MAC true
	#		define NOX_OS_NAME "MacOS"
	#	elif defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR)
	#		undef NOX_OS_IOS
	#		define NOX_OS_IOS true
	#		define NOX_OS_NAME "iOS"
	#	else
	#		error "platform.hpp: Unknown Apple OS!"
	#	endif
	#elif defined(__linux__)
	#	ifdef __ANDROID__
	#		undef NOX_OS_ANDROID
	#		define NOX_OS_ANDROID true
	#		define NOX_OS_NAME "Android"
	#	else
	#	undef NOX_OS_LINUX
	#	define NOX_OS_LINUX true
	#	define NOX_OS_NAME "Linux"
	#	endif
	#else
	#	error "platform.hpp: Unknown operating system!"
	#endif

	#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
	#	undef NOX_ARCH_X86_64
	#	define NOX_ARCH_X86_64 true
	#	define NOX_ARCH_NAME "x86-64"
	#elif defined(i386)			\
			|| defined(__i386)		\
			|| defined(__i386__)	\
			|| defined(_M_IX86)
	#       error "32 bit is not supported - neither x86-32 or ARM 32!"
	#elif (defined(__arm__) || defined(_M_ARM)) && !defined(__aarch64__)
	#       error "32 bit is not supported - neither x86-32 or ARM 32"
	#elif defined(__aarch64__)
	#	undef NOX_ARCH_ARM_64
	#	define NOX_ARCH_ARM_64 true
	#	define NOX_ARCH_NAME "ARM-64"
	#else
	#	error "platform.hpp: Unknown architecture!"
	#endif

	#	define NOX_ARCH_SIZE_NAME "64-Bit"

	#define NOX_IS_POSIX (NOX_OS_LINUX || NOX_OS_ANDROID || NOX_OS_MAC || NOX_OS_IOS)

	#ifdef __GNUC__
	#	undef NOX_COM_GCC
	#	define NOX_COM_GCC true
	#	define NOX_COM_NAME "GCC"
	#elif defined(__clang__)
	#	undef NOX_COM_CLANG
	#	define NOX_COM_CLANG true
	#	define NOX_COM_NAME "Clang"
	#elif defined(__MINGW32__) || defined(__MINGW32__)
	#	undef NOX_COM_MINGW
	#	define NOX_COM_MINGW true
	#	define NOX_COM_NAME "MinGW"
	#endif

	/// <summary>
	/// Use architecture specific optimizations such as assembly or intrinsics?
	/// </summary>
	#define NOX_USE_ARCH_OPT true

	/// <summary>
	/// Insert assembly comments with the instruction name into the assembler code, to find the section in the compiled output.
	/// Should be disabled when building for release.
	/// </summary>
	#define NOX_REACTOR_ASM_MARKERS NOX_DEBUG

	/// <summary>
	/// Dump allocations.
	/// </summary>
	#define NOX_VERBOSE_ALLOCATOR false

	/// <summary>
	/// Use a slower but more correct floating point comparison algorithm.
	/// </summary>
	#define NOX_OPT_USE_ZERO_EPSILON NOX_DEBUG

	/// <summary>
	/// Insert instruction markers into the VM reactor assembly code.
	/// </summary>
	#define NOX_REACTOR_ASM_MARKERS NOX_DEBUG

	/// <summary>
	/// If enabled, the jump table addresses are directly mapped as pointers into the byte-code signals.
	/// </summary>
	#if NOX_RELEASE && !defined(NOX_TEST)
	#	define NOX_OPT_EXECUTION_ADDRESS_MAPPING true
	#else
	#	define NOX_OPT_EXECUTION_ADDRESS_MAPPING false
	#endif

	/// <summary>
	/// Optimize the branches for the condition that 'x' is equal to 'expect'.
	/// </summary>
	#define NOX_EXPECT_VALUE(x, expect)         __builtin_expect(( x ), ( expect ))

	/// <summary>
	/// Generates a cache prefetch instruction if the target supports it.
	/// </summary>
	#define NOX_CACHE_PREFETCH(ptr)				__builtin_prefetch(ptr)

	/// <summary>
	/// Marks a hot function.
	/// Hot path functions are optimized more and get a better code layout.
	/// </summary>
	#define NOX_HOT                             __attribute__((hot))

	#if NOX_COM_GCC

	/// <summary>
	/// Marks a hot label.
	/// Hot paths are optimized more and get a better code layout.
	/// </summary>
	#define NOX_HOT_LABEL NOX_HOT

	#else

	/// <summary>
	/// Marks a hot label.
	/// Hot paths are optimized more and get a better code layout.
	/// </summary>
	#define NOX_HOT_LABEL
		
	#endif

	/// <summary>
	/// Marks a cold function.
	/// Cold path functions are optimized less and get worse code layout,
	/// but make more space for hot functions.
	/// </summary>
	#define NOX_COLD                            __attribute__((cold))

	#if NOX_COM_GCC

	/// <summary>
	/// Marks a cold label.
	/// </summary>
	#define NOX_COLD_LABEL NOX_COLD

	#else

	/// <summary>
	/// Marks cold label.
	/// </summary>
	#define NOX_COLD_LABEL

	#endif

	/// <summary>
	/// Always inline this function.
	/// </summary>
	#define NOX_FORCE_INLINE                    __attribute__((always_inline))

	/// <summary>
	/// Never ever inline this function.
	/// </summary>
	#define NOX_NEVER_INLINE                    __attribute__((noinline))

	/// <summary>
	/// Smart inline this function.
	/// </summary>
	#define NOX_FLATTEN                         __attribute__((flatten))

	/// <summary>
	/// A pure function is a function that has the following properties:
	/// * The function return values are identical for identical arguments.
	/// * The function application has no side effects.
	/// Thus a pure function is a computational analogue of a mathematical function.
	/// </summary>
	#define NOX_PURE                            __attribute__((pure))

	/// <summary>
	/// The alloc_size attribute is used to tell the compiler that the function return value points to memory,
	/// where the size is given by one or two of the functions parameters.
	/// </summary>
	#define NOX_ALLOC_SIZE(x)                   __attribute__((alloc_size(( x ))))

	/// <summary>
	/// Attribute malloc indicates that a function is malloc-like.
	/// Allows for aliasing optimizations.
	/// </summary>
	#define NOX_MALLOC							__attribute__((malloc))

	/// <summary>
	/// Tells the compile that two pointers never alias each other.
	/// </summary>
	#define NOX_RESTRICT                        __restrict__

	/// <summary>
	/// Marks that a routine is implemented in assembler code.
	/// </summary>
	#define NOX_ASM_ROUTINE

	/// <summary>
	/// 8 bit unsigned integer.
	/// </summary>
	using U8 = std::uint8_t;

	/// <summary>
	/// 8 bit signed integer.
	/// </summary>
	using I8 = std::int8_t;

	/// <summary>
	/// 16 bit unsigned integer.
	/// </summary>
	using U16 = std::uint16_t;

	/// <summary>
	/// 16 bit signed integer.
	/// </summary>
	using I16 = std::int16_t;

	/// <summary>
	/// 32 bit unsigned integer.
	/// </summary>
	using U32 = std::uint32_t;

	/// <summary>
	/// 32 bit signed integer.
	/// </summary>
	using I32 = std::int32_t;

	/// <summary>
	/// 64 bit unsigned integer.
	/// </summary>
	using U64 = std::uint64_t;

	/// <summary>
	/// 64 bit signed integer.
	/// </summary>
	using I64 = std::int64_t;

	/// <summary>
	/// 64-bit unsigned pointer.
	/// </summary>
	using Uip64 = U64;

	/// <summary>
	/// 16 bit half precision float
	/// </summary>
	using F16 = U16;

	/// <summary>
	/// 32 bit single precision float
	/// </summary>
	using F32 = float;

	/// <summary>
	/// 64 bit double precision float
	/// </summary>
	using F64 = double;

	static_assert(sizeof(U8) == 1);
	static_assert(sizeof(I8) == 1);
	static_assert(sizeof(U16) == 2);
	static_assert(sizeof(I16) == 2);
	static_assert(sizeof(U32) == 4);
	static_assert(sizeof(I32) == 4);
	static_assert(sizeof(U64) == 8);
	static_assert(sizeof(I64) == 8);
	static_assert(sizeof(Uip64) == 8);
	static_assert(sizeof(std::uintptr_t) == 8);
	static_assert(sizeof(F16) == 2);
	static_assert(sizeof(F32) == 4);
	static_assert(sizeof(F64) == 8);

	/// <summary>
	/// Kilobytes.
	/// </summary>
	constexpr U64 KB {1000};

	/// <summary>
	/// Megabytes.
	/// </summary>
	constexpr U64 MB {KB * KB};

	/// <summary>
	/// Gigabytes.
	/// </summary>
	constexpr U64 GB {KB * KB * KB};

	/// <summary>
	/// Terabytes.
	/// </summary>
	constexpr U64 TB {KB * KB * KB * KB};

	/// <summary>
	/// Petabytes.
	/// </summary>
	constexpr U64 PB {KB * KB * KB * KB * KB};

	/// <summary>
	/// Convert between memory units.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="bytes"></param>
	/// <returns></returns>
	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Bytes2Gigabytes(T bytes) -> T
	{
		bytes = std::clamp<decltype(bytes)>(bytes, 1, bytes);
		return bytes / static_cast<T>(KB) / static_cast<T>(KB) / static_cast<T>(KB);
	}

	/// <summary>
	/// Convert between memory units.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="bytes"></param>
	/// <returns></returns>
	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Bytes2Megabytes(T bytes) -> T
	{
		bytes = std::clamp<decltype(bytes)>(bytes, 1, bytes);
		return bytes / static_cast<T>(KB) / static_cast<T>(KB);
	}

	/// <summary>
	/// Convert between memory units.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="bytes"></param>
	/// <returns></returns>
	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Bytes2Kilobytes(T bytes) -> T
	{
		bytes = std::clamp<decltype(bytes)>(bytes, 1, bytes);
		return bytes / static_cast<T>(KB);
	}

	/// <summary>
	/// Convert between memory units.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="gigabytes"></param>
	/// <returns></returns>
	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Gigabytes2Bytes(const T gigabytes) -> T
	{
		return gigabytes * static_cast<T>(KB) * static_cast<T>(KB) * static_cast<T>(KB);
	}

	/// <summary>
	/// Convert between memory units.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="megabytes"></param>
	/// <returns></returns>
	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Megabytes2Bytes(const T megabytes) -> T
	{
		return megabytes * static_cast<T>(KB) * static_cast<T>(KB);
	}

	/// <summary>
	/// Convert between memory units.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="kilobytes"></param>
	/// <returns></returns>
	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Kilobytes2Bytes(const T kilobytes) -> T
	{
		return kilobytes * static_cast<T>(KB);
	}

	/// <summary>
	/// Convert between memory units.
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	constexpr auto operator ""_kB(const unsigned long long value) -> U64
	{
		return Kilobytes2Bytes<decltype(value)>(value);
	}

	/// <summary>
	/// Convert between memory units.
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	constexpr auto operator ""_mB(const unsigned long long value) -> U64
	{
		return Megabytes2Bytes<decltype(value)>(value);
	}

	/// <summary>
	/// Convert between memory units.
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	constexpr auto operator ""_gB(const unsigned long long value) -> U64
	{
		return Gigabytes2Bytes<decltype(value)>(value);
	}

	namespace Foundation
	{
		/// <summary>
		/// Generic runtime entry point.
		/// </summary>
		/// <param name="argc"></param>
		/// <param name="argv"></param>
		/// <returns></returns>
		[[nodiscard]]
		extern auto NominaxMain(I32 argc, const char* const* argv) -> I32;

		/// <summary>
		/// Returns true if x is a power of two.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="x"></param>
		/// <returns></returns>
		template <typename T> requires std::is_integral_v<T>
		constexpr auto IsPowerOfTwo(const T x) -> bool
		{
			// See https://github.com/MarioSieg/Bit-Twiddling-Hacks-Collection/blob/master/bithax.h
			return !(x & (x - 1));
		}

		/// <summary>
		/// Rounds up x to the next power of 2.
		/// x should not be zero.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		constexpr auto RoundUpPow2(U64 x) -> U64
		{
			// See https://github.com/MarioSieg/Bit-Twiddling-Hacks-Collection/blob/master/bithax.h
			--x;
			x |= x >> 1;
			x |= x >> 2;
			x |= x >> 4;
			x |= x >> 8;
			x |= x >> 16;
			x |= x >> 32;
			return ++x;
		}

		/// <summary>
		/// Convert half precision 16-bit float to 32-bit single precision float.
		/// </summary>
		/// <param name="src"></param>
		/// <returns></returns>
		constexpr auto FP16ToFP32(const F16 src) -> F32
		{
			const U32 h {src};
			U32       sign {(h >> 15) & 1};
			U32       exp {(h >> 10) & 0x1F};
			U32       man {(h & 0x3FF) << 13};

			if (exp == 0x1F)
			{
				man = man ? (sign = 0, 0x7FFFFF) : 0;
				exp = 0xFF;
			}
			else if (!exp)
			{
				if (man)
				{
					exp = 0x71;
					U32 msb;
					do
					{
						msb = man & 0x400000;
						man <<= 1;
						++exp;
					}
					while (!msb);
					man &= 0x7FFFFF;
				}
			}
			else
			{
				exp += 0x70;
			}
			sign <<= 31;
			exp <<= 23;
			return static_cast<F32>(sign | exp | man);
		}

		/// <summary>
		/// Convert 32-bit single precision float to half precision 16-bit float.
		/// </summary>
		/// <param name="src"></param>
		/// <returns></returns>
		constexpr auto FP32ToFP16(const F32 src) -> F16
		{
			const U32 x {std::bit_cast<U32>(src)};
			const U32 u {x & 0x7FFFFFFF};

			if (u > 0x7F800000)
			{
				// Remove +NaN/-NaN
				return 0x7FFF;
			}

			const U32 sign {(x >> 16) & 0x8000};
			if (u > 0x477FEFFF)
			{
				return sign | 0x7C00U;
			}
			if (u < 0x33000001)
			{
				return sign | 0x0000;
			}

			U32 exp {(u >> 23) & 0xFF};
			U32 man {u & 0x7FFFFF};
			U32 shi;

			if (exp > 0x70)
			{
				shi = 13;
				exp -= 0x70;
			}
			else
			{
				shi = 0x7E - exp;
				exp = 0;
				man |= 0x800000;
			}

			const U32 lsb {static_cast<U32>(1) << shi};
			const U32 lsbS1 {lsb >> 1};
			const U32 lsbM1 {lsb - 1};
			const U32 rem {man & lsbM1};
			man >>= shi;
			if (rem > lsbM1 || (rem == lsbS1 && man & 1))
			{
				++man;
				if ((man & 0x3FF) == 0)
				{
					++exp;
					man = 0;
				}
			}

			exp <<= 10;
			return static_cast<U16>(sign | exp | man);
		}

		/// <summary>
		/// Computes the required bytes needed for the value or bit representation x.
		/// </summary>
		/// <param name="x"></param>
		/// <returns>The amount of bytes -> min: 1, max: 8</returns>
		constexpr auto ComputeRequiredBytes(U64 x) -> U8
		{
			U8 bytes {0};
			do
			{
				x >>= 8;
				++bytes;
			}
			while (x);
			return static_cast<U8>(RoundUpPow2(static_cast<U64>(bytes)));
		}

		/// <summary>
		/// Linearizes 2D coordinates using interleaved bits (morton table).
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <returns></returns>
		extern auto LinearizeCoords2D(U16 x, U16 y) -> U32;

		/// <summary>
		/// Fallback implementation for "ILog"
		/// using a table of De-Bruijn sequence numbers.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		extern auto ILog2DeBruijn(U64 x) -> U64;

		/// <summary>
		/// Computes the binary logarithm of log2(2)
		/// </summary>
		/// <param name="x">Should not be 0!</param>
		/// <returns></returns>
		inline auto ILog2(U64 x) -> U64
		{
			#if NOX_USE_ARCH_OPT
			--x;
			return sizeof x * CHAR_BIT - __builtin_clzll(x);
			#else
		return ILog2DeBruijn(x);
			#endif
		}

		/// <summary>
		/// Visit overload helper.
		/// </summary>
		template <typename... Ts>
		struct Overload : Ts...
		{
			using Ts::operator()...;
		};

		/// <summary>
		/// Visit overload helper.
		/// </summary>
		template <typename... Ts>
		Overload(Ts ...) -> Overload<Ts...>;

		/// <summary>
		/// Calculates and returns the next element in the array using pointer arithmetic.
		/// Is is important that T is a reference to an element in the array and NOT the last one.
		/// This is useful to get the next element when using std::for_each with parallel execution.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="iter"></param>
		/// <param name="begin"></param>
		/// <returns></returns>
		template <typename T> requires std::is_reference_v<T>
		[[nodiscard]]
		constexpr auto DistanceRef(T&& iter, const std::remove_reference_t<T>* const begin) -> std::ptrdiff_t
		{
			return std::addressof(iter) - begin;
		}

		/// <summary>
		/// Restricts to random access iterator.
		/// </summary>
		template <typename Iter>
		concept RandomAccessIterator = std::is_same_v<typename std::iterator_traits<Iter>::iterator_category, std::random_access_iterator_tag>;

		/// <summary>
		/// Splits the iterator range into chunks
		/// and invokes the function for each chunk range.
		/// This is useful for parallel processing or processing data in chunks.
		/// </summary>
		/// <typeparam name="Iter"></typeparam>
		/// <typeparam name="Func"></typeparam>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="chunkCount"></param>
		/// <param name="begin"></param>
		/// <param name="end"></param>
		/// <param name="func"></param>
		/// <param name="args"></param>
		/// <returns></returns>
		template <typename Iter, typename Func, typename... Args> requires RandomAccessIterator<Iter>
		constexpr auto UniformChunkSplit(const U64 chunkCount, const Iter begin, const Iter end, Func&& func, Args&&...args) -> void
		{
			using ValueType = const typename std::iterator_traits<Iter>::value_type;
			using Span = std::span<ValueType>;

			const auto length {std::distance(begin, end)};
			const bool mismatch {chunkCount <= 1 || static_cast<U64>(length) % chunkCount};

			if (mismatch)
			{
				const Span range {begin, end};
				std::invoke(std::forward<Func>(func), range, static_cast<U64>(0), std::forward<Args>(args)...);
			}
			else
			{
				const auto chunkSize {static_cast<U64>(length) / chunkCount};
				for (U64 i {0}; i < chunkCount; ++i)
				{
					const Iter beginChunk {begin + chunkSize * i};
					const Iter endChunk {i == chunkCount - 1 ? end : beginChunk + chunkSize};
					const Span range {beginChunk, endChunk};
					std::invoke(std::forward<Func>(func), range, chunkSize * i, std::forward<Args>(args)...);
				}
			}
		}

		/// <summary>
		/// Splits the iterator range into chunks
		/// and invokes the function for each chunk range.
		/// This is useful for parallel processing or processing data in chunks.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <typeparam name="Func"></typeparam>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="chunkCount"></param>
		/// <param name="range"></param>
		/// <param name="func"></param>
		/// <param name="args"></param>
		/// <returns></returns>
		template <typename T, typename Func, typename... Args>
		constexpr auto UniformChunkSplit(const U64 chunkCount, const std::span<const T> range, Func&& func, Args&&...args) -> void
		{
			UniformChunkSplit<decltype(std::begin(range)), Func, Args...>(chunkCount, std::begin(range), std::end(range), std::forward<Func>(func), std::forward(args)...);
		}

		/// <summary>
		/// Computes the index of T inside the variant type.
		/// </summary>
		/// <typeparam name="VariantType"></typeparam>
		/// <typeparam name="T"></typeparam>
		/// <returns></returns>
		template <typename VariantType, typename T, U64 Index = 0>
		[[nodiscard]]
		constexpr auto VariantIndexOf() -> U64
		{
			if constexpr (Index == std::variant_size_v<VariantType> || std::is_same_v<std::variant_alternative_t<Index, VariantType>, T>)
			{
				return Index;
			}
			else
			{
				return VariantIndexOf<VariantType, T, Index + 1>();
			}
		}

		/// <summary>
		/// Sign EXtend the integer.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="x"></param>
		/// <returns></returns>
		[[nodiscard]]
		constexpr auto Sex(const I8 x) -> U8
		{
			return x >> (CHAR_BIT * sizeof(x) - 1);
		}

		/// <summary>
		/// Sign EXtend the integer.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="x"></param>
		/// <returns></returns>
		[[nodiscard]]
		constexpr auto Sex(const I16 x) -> U16
		{
			return x >> (CHAR_BIT * sizeof(x) - 1);
		}

		/// <summary>
		/// Sign EXtend the integer.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="x"></param>
		/// <returns></returns>
		[[nodiscard]]
		constexpr auto Sex(const I32 x) -> U32
		{
			return x >> (CHAR_BIT * sizeof(x) - 1);
		}

		/// <summary>
		/// Sign EXtend the integer.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="x"></param>
		/// <returns></returns>
		[[nodiscard]]
		constexpr auto Sex(const I64 x) -> U64
		{
			return x >> (CHAR_BIT * sizeof(x) - 1);
		}

		/// <summary>
		/// Calculates and returns the next element in the array using pointer arithmetic.
		/// Is is important that T is a reference to an element in the array and NOT the last one.
		/// This is useful to get the next element when using std::for_each with parallel execution.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="iter"></param>
		/// <returns></returns>
		template <typename T> requires std::is_reference_v<T>
		[[nodiscard]]
		constexpr auto AdvanceRef(T&& iter) -> T&&
		{
			return *(std::addressof(iter) + 1);
		}

		#if NOX_OS_WINDOWS
		#define NOX_ALLOCA_STUB(size) ::_alloca(size)
		#else
			#define NOX_ALLOCA_STUB(size) ::alloca(size)
		#endif

		/// <summary>
		/// Above this size memory will be allocated on the heap
		/// instead of the stack.
		/// </summary>
		constexpr U64 STACK_ALLOC_HEAP_THRESHOLD {4_kB};

		/// <summary>
		/// Restrict fixed stack allocation type.
		/// </summary>
		template <typename T, const U64 C>
		concept FixedStackAllocatable = requires
		{
			std::is_trivial_v<T>;                       // trivial types only
			C != 0;                                     // must at least be one
			sizeof(T) != 0;                             // must at least be one
			sizeof(T) * C < STACK_ALLOC_HEAP_THRESHOLD; // no more than 4 kB
		};

		template <typename T, const U64 C> requires FixedStackAllocatable<T, C>
		struct FixedStackAllocationProxy final
		{
			static constexpr U64 BYTE_SIZE {C * sizeof(T)};
		};

		/// <summary>
		/// Performs a parameter checked stack allocation with fixed size.
		/// </summary>
		/// <param name="type">The generic type to allocation. Must be a POD type.</param>
		/// <param name="count">The amount of "type" to allocate. Here, the fixed version this is restricted and must be known at compile time..</param>
		/// <returns>The pointer to the allocated object which stays as long as the function scope exists.</returns>
		#define FixedStackAllocation(type, count)	\
			static_cast< type *>(NOX_ALLOCA_STUB(( FixedStackAllocationProxy< type, ( count ) >::BYTE_SIZE )))

		/// <summary>
		/// Restrict dynamic stack allocation type.
		/// </summary>
		template <typename T>
		concept DynamicStackAllocatable = requires
		{
			std::is_trivial_v<T>;
		};

		/// <summary>
		/// RAII release guard for objects which were too large for stack allocations,
		/// so they where allocated on the heap instead.
		/// </summary>
		template <typename T> requires DynamicStackAllocatable<T>
		class HybridStackGuard final
		{
			T* const NOX_RESTRICT Blob_;
			const bool            IsHeap_;

		public:
			/// <summary>
			/// Construct with heap flag and memory.
			/// </summary>
			/// <returns></returns>
			explicit constexpr HybridStackGuard(bool isOnHeap, T& memory);

			/// <summary>
			/// No copying.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			HybridStackGuard(const HybridStackGuard& other) = delete;

			/// <summary>
			/// No moving.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <returns></returns>
			HybridStackGuard(HybridStackGuard&& other) = delete;

			/// <summary>
			/// No copying.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <returns></returns>
			auto operator =(const HybridStackGuard& other) -> HybridStackGuard& = delete;

			/// <summary>
			/// No moving.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <returns></returns>
			auto operator =(HybridStackGuard&& other) -> HybridStackGuard& = delete;

			/// <summary>
			/// 
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <returns>True if the pointer is heap allocated, else false.</returns>
			constexpr operator bool() const &;

			/// <summary>
			/// Direct access.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			constexpr auto operator ->() & -> T*;

			/// <summary>
			/// Direct access.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			constexpr auto operator ->() const & -> const T*;

			/// <summary>
			/// Direct access.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			constexpr auto operator *() & -> T&;

			/// <summary>
			/// Direct access.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			constexpr auto operator *() const & -> const T&;

			/// <summary>
			/// Unchecked subscript.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// /// <param name="idx"></param>
			/// /// <returns></returns>
			constexpr auto operator [](U64 idx) & -> T&;

			/// <summary>
			/// Unchecked subscript.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="idx"></param>
			/// <returns></returns>
			constexpr auto operator [](U64 idx) const & -> const T&;

			/// <summary>
			/// 
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <returns>True if the pointer is heap allocated, else false.</returns>
			[[nodiscard]]
			constexpr auto IsHeapAllocated() const & -> bool;

			/// <summary>
			/// Destruct which releases the heap memory,
			/// if heap allocated.
			/// </summary>
			~HybridStackGuard();
		};

		template <typename T> requires DynamicStackAllocatable<T>
		constexpr HybridStackGuard<T>::HybridStackGuard(const bool isOnHeap, T& memory) : Blob_ {&memory},
		                                                                                  IsHeap_ {isOnHeap} { }

		template <typename T> requires DynamicStackAllocatable<T>
		constexpr HybridStackGuard<T>::operator bool() const &
		{
			return this->IsHeap_;
		}

		template <typename T> requires DynamicStackAllocatable<T>
		constexpr auto HybridStackGuard<T>::operator->() & -> T*
		{
			return this->Blob_;
		}

		template <typename T> requires DynamicStackAllocatable<T>
		constexpr auto HybridStackGuard<T>::operator->() const & -> const T*
		{
			return this->Blob_;
		}

		template <typename T> requires DynamicStackAllocatable<T>
		constexpr auto HybridStackGuard<T>::operator*() & -> T&
		{
			return *this->Blob_;
		}

		template <typename T> requires DynamicStackAllocatable<T>
		constexpr auto HybridStackGuard<T>::operator*() const & -> const T&
		{
			return *this->Blob_;
		}

		template <typename T> requires DynamicStackAllocatable<T>
		constexpr auto HybridStackGuard<T>::operator[](const U64 idx) & -> T&
		{
			return *(this->Blob_ + idx);
		}

		template <typename T> requires DynamicStackAllocatable<T>
		constexpr auto HybridStackGuard<T>::operator[](const U64 idx) const & -> const T&
		{
			return *(this->Blob_ + idx);
		}

		template <typename T> requires DynamicStackAllocatable<T>
		constexpr auto HybridStackGuard<T>::IsHeapAllocated() const & -> bool
		{
			return this->IsHeap_;
		}

		template <typename T> requires DynamicStackAllocatable<T>
		inline HybridStackGuard<T>::~HybridStackGuard()
		{
			if (this->IsHeapAllocated() && this->Blob_)
			{
				delete[] this->Blob_;
			}
		}

		/// <summary>
		/// Helper routine to determine if the memory
		/// for a dynamically stack allocation should be allocated
		/// on the heap or not.
		/// </summary>
		template <typename T>
		constexpr auto IsHybridHeap(const U64 count) -> bool
		{
			return count * sizeof(T) > STACK_ALLOC_HEAP_THRESHOLD;
		}

		/// <summary>
		/// Performs a parameter checked stack allocation with dynamic size.
		/// </summary>
		/// <param name="type">The generic type to allocation. Must be a POD type.</param>
		/// <param name="count">The amount of "type" to allocate. Here, the dynamic version allows dynamic values,
		/// but if the byte size is above "STACK_ALLOC_HEAP_THRESHOLD", the memory is allocated on the heap instead.</param>
		/// <returns>The stack guard which released the memory on exit.</returns>
		#define DynamicStackAllocation(type, count)										\
		{																				\
			IsHybridHeap < type >( count ),												\
			IsHybridHeap < type >( count )												\
			? *static_cast< type *>(new type [ count ])									\
			: *static_cast< type *>(NOX_ALLOCA_STUB( ( count ) * sizeof( type ) ))		\
		}

		/// <summary>
		/// Returns true if the alignment is valid,
		/// which means it is a power of two and not zero.
		/// </summary>
		/// <param name="alignment"></param>
		/// <returns></returns>
		[[nodiscard]]
		constexpr auto IsAlignmentValid(const U64 alignment) -> bool
		{
			return alignment && !(alignment & (alignment - 1));
		}

		static_assert(IsAlignmentValid(alignof(std::max_align_t)), "WTF");

		/// <summary>
		/// Checks is the address of the pointer is aligned to specified alignment,
		/// </summary>
		/// <param name="ptr">The address to check.</param>
		/// <param name="alignment">The alignment the address should have.</param>
		/// <returns>True if valid and corresponding alignment, else false.</returns>
		[[nodiscard]]
		constexpr auto IsAlignedTo(void* const ptr, const U64 alignment) -> bool
		{
			return std::bit_cast<Uip64>(ptr) % alignment == 0 && IsAlignmentValid(alignment);
		}

		/// <summary>
		/// Checks is the address of the pointer is aligned to specified alignment,
		/// </summary>
		/// <param name="ptr">The address to check.</param>
		/// <param name="alignment">The alignment the address should have.</param>
		/// <returns>True if valid and corresponding alignment, else false.</returns>
		[[nodiscard]]
		constexpr auto IsAlignedTo(const Uip64 ptr, const U64 alignment) -> bool
		{
			return IsAlignedTo(std::bit_cast<void*>(ptr), alignment);
		}

		/// <summary>
		/// Compute the required offset to align the pointer to the given alignment.
		/// The specified alignment must be valid, check with IsAlignmentValid() if needed. 
		/// </summary>
		/// <param name="ptr">The pointer address. Can be nullptr!</param>
		/// <param name="alignment">The alignment, which must be valid.</param>
		/// <returns>The required offset.</returns>
		constexpr auto ComputeMissingAlignmentOffset(void* const ptr, const U64 alignment) -> U64
		{
			const auto misalignment = std::bit_cast<Uip64>(ptr) & (alignment - 1);
			return misalignment ? alignment - misalignment : 0;
		}

		/// <summary>
		/// Compute the required offset to align the pointer to the given alignment.
		/// The specified alignment must be valid, check with IsAlignmentValid() if needed. 
		/// </summary>
		/// <param name="ptr">The pointer address. Can be nullptr!</param>
		/// <param name="alignment">The alignment, which must be valid.</param>
		/// <returns>The required offset.</returns>
		constexpr auto ComputeMissingAlignmentOffset(const Uip64 ptr, const U64 alignment) -> U64
		{
			return ComputeMissingAlignmentOffset(std::bit_cast<void*>(ptr), alignment);
		}

		/// <summary>
		/// Computes the minimum required alignment for an
		/// object of the specified size.
		/// </summary>
		/// <param name="size"></param>
		/// <returns></returns>
		inline auto ComputeMinAlignmentRequiredForSize(const U64 size) -> U64
		{
			return size >= alignof(std::max_align_t) ? alignof(std::max_align_t) : static_cast<U64>(1) << ILog2(size);
		}

		/// <summary>
		/// Generic system allocation routines.
		/// </summary>
		struct SystemAllocator final
		{
			/// <summary>
			/// Static class.
			/// </summary>
			SystemAllocator() = delete;

			/// <summary>
			/// Static class.
			/// </summary>
			/// <param name="other"></param>
			SystemAllocator(const SystemAllocator& other) = delete;

			/// <summary>
			/// Static class.
			/// </summary>
			/// <param name="other"></param>
			SystemAllocator(SystemAllocator&& other) = delete;

			/// <summary>
			/// Static class.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(const SystemAllocator& other) -> SystemAllocator& = delete;

			/// <summary>
			/// Static class.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(SystemAllocator&& other) -> SystemAllocator& = delete;

			/// <summary>
			/// Static class.
			/// </summary>
			~SystemAllocator() = delete;

			/// <summary>
			/// Allocates an uninitialized block of memory.
			/// Like std::malloc.
			/// </summary>
			/// <param name="size">The size in bytes.</param>
			/// <returns>The pointer or nullptr on fail.</returns>
			[[nodiscard]]
			NOX_HOT NOX_ALLOC_SIZE(1) NOX_MALLOC static auto Allocate(U64 size) -> void*;

			/// <summary>
			/// Allocates an zero initialized block of memory.
			/// Like std::calloc.
			/// </summary>
			/// <param name="size">The size in bytes.</param>
			/// <returns>The pointer or nullptr on fail.</returns>
			[[nodiscard]]
			NOX_HOT NOX_ALLOC_SIZE(1) static auto AllocateAndZero(U64 size) -> void*;

			/// <summary>
			/// Reallocates a block of memory.
			/// Like std::realloc.
			/// </summary>
			/// <param name="where">The block to reallocate.</param>
			/// <param name="size">The new size of the blob.</param>
			/// <returns>The pointer or nullptr on fail.</returns>
			[[nodiscard]]
			NOX_HOT NOX_ALLOC_SIZE(2) static auto Reallocate(void* where, U64 size) -> void*;

			/// <summary>
			/// Deallocates a block of memory.
			/// Like std::free.
			/// </summary>
			/// <param name="ptr">The pointer to deallocate.</param>
			/// <returns>Nothing.</returns>
			NOX_HOT static auto Deallocate(void* ptr) -> void;

			/// <summary>
			/// Allocates an uninitialized block of memory with special alignment.
			/// Like std::malloc.
			/// </summary>
			/// <param name="size">The size in bytes.</param>
			/// <param name="alignment">The alignment the new address should have.</param>
			/// <returns>The pointer or nullptr on fail.</returns>
			[[nodiscard]]
			NOX_HOT NOX_ALLOC_SIZE(1) NOX_MALLOC static auto AllocateAligned(U64 size, U64 alignment) -> void*;

			/// <summary>
			/// Allocates an zero initialized block of memory with special alignment.
			/// Like std::calloc.
			/// </summary>
			/// <param name="size">The size in bytes.</param>
			/// <param name="alignment">The alignment the new address should have.</param>
			/// <returns>The pointer or nullptr on fail.</returns>
			[[nodiscard]]
			NOX_HOT NOX_ALLOC_SIZE(1) NOX_MALLOC static auto AllocateAlignedAndZero(U64 size, U64 alignment) -> void*;

			/// <summary>
			/// Reallocates a block of memory with special alignment.
			/// Like std::realloc.
			/// </summary>
			/// <param name="where">The block to reallocate.</param>
			/// <param name="size">The new size of the blob.</param>
			/// <param name="alignment">The alignment the new address should have.</param>
			/// <returns>The pointer or nullptr on fail.</returns>
			NOX_HOT NOX_ALLOC_SIZE(2) static auto ReallocateAligned(void* where, U64 size, U64 alignment) -> void*;

			/// <summary>
			/// Deallocates a block of memory with special alignment.
			/// Like std::free.
			/// </summary>
			/// <param name="ptr">The pointer to deallocate.</param>
			/// <returns>Nothing.</returns>
			NOX_HOT static auto DeallocateAligned(void* ptr) -> void;

			/// <summary>
			/// Allocates an uninitialized block of memory.
			/// Like std::malloc but panics on allocation failture.
			/// </summary>
			/// <param name="size">The size in bytes.</param>
			/// <returns>The pointer.</returns>
			[[nodiscard]]
			NOX_ALLOC_SIZE(1) NOX_MALLOC static auto AllocateChecked(U64 size) -> void*;

			/// <summary>
			/// Allocates an zero initialized block of memory.
			/// Like std::calloc but panics on allocation failture.
			/// </summary>
			/// <param name="size">The size in bytes.</param>
			/// <returns>The pointer.</returns>
			[[nodiscard]]
			NOX_ALLOC_SIZE(1) static auto AllocateAndZeroChecked(U64 size) -> void*;

			/// <summary>
			/// Reallocates a block of memory.
			/// Like std::realloc but panics on allocation failture.
			/// </summary>
			/// <param name="where">The block to reallocate.</param>
			/// <param name="size">The new size of the blob.</param>
			/// <returns>The pointer.</returns>
			[[nodiscard]]
			NOX_ALLOC_SIZE(2) static auto ReallocateChecked(void* where, U64 size) -> void*;

			/// <summary>
			/// Deallocates a block of memory.
			/// Like std::free but panics on allocation failture.
			/// </summary>
			/// <param name="ptr">The pointer to deallocate.</param>
			/// <returns>Nothing.</returns>
			static auto DeallocateChecked(void* ptr) -> void;

			/// <summary>
			/// Allocates an uninitialized block of memory with special alignment.
			/// Like std::malloc but panics on allocation failture.
			/// </summary>
			/// <param name="size">The size in bytes.</param>
			/// <param name="alignment">The alignment the new address should have.</param>
			/// <returns>The pointer.</returns>
			[[nodiscard]]
			NOX_ALLOC_SIZE(1) NOX_MALLOC static auto AllocateAlignedChecked(U64 size, U64 alignment) -> void*;

			/// <summary>
			/// Allocates an zero initialized block of memory with special alignment.
			/// Like std::calloc but panics on allocation failture.
			/// </summary>
			/// <param name="size">The size in bytes.</param>
			/// <param name="alignment">The alignment the new address should have.</param>
			/// <returns>The pointer.</returns>
			[[nodiscard]]
			NOX_ALLOC_SIZE(1) NOX_MALLOC static auto AllocateAlignedAndZeroChecked(U64 size, U64 alignment) -> void*;

			/// <summary>
			/// Reallocates a block of memory with special alignment.
			/// Like std::realloc but panics on allocation failture.
			/// </summary>
			/// <param name="where">The block to reallocate.</param>
			/// <param name="size">The new size of the blob.</param>
			/// <param name="alignment">The alignment the new address should have.</param>
			/// <returns>The pointer.</returns>
			NOX_ALLOC_SIZE(2) static auto ReallocateAlignedChecked(void* where, U64 size, U64 alignment) -> void*;

			/// <summary>
			/// Deallocates a block of memory with special alignment.
			/// Like std::free but panics on allocation failture.
			/// </summary>
			/// <param name="ptr">The pointer to deallocate.</param>
			/// <returns>Nothing.</returns>
			static auto DeallocateAlignedChecked(void* ptr) -> void;
		};

		NOX_HOT NOX_FLATTEN inline auto SystemAllocator::Allocate(const U64 size) -> void*
		{
			return std::malloc(size);
		}

		NOX_HOT NOX_FLATTEN inline auto SystemAllocator::AllocateAndZero(const U64 size) -> void*
		{
			return std::calloc(1, size);
		}

		NOX_HOT NOX_FLATTEN inline auto SystemAllocator::Reallocate(void* const where, const U64 size) -> void*
		{
			return std::realloc(where, size);
		}

		NOX_HOT NOX_FLATTEN inline auto SystemAllocator::Deallocate(void* const ptr) -> void
		{
			std::free(ptr);
		}

		NOX_HOT NOX_FLATTEN inline auto SystemAllocator::AllocateAligned(const U64 size, const U64 alignment) -> void*
		{
			#if NOX_OS_WINDOWS && NOX_COM_CLANG
				return _aligned_malloc(size, alignment);
			#else
			return aligned_alloc(alignment, size);
			#endif
		}

		NOX_HOT NOX_FLATTEN NOX_MALLOC inline auto SystemAllocator::AllocateAlignedAndZero(const U64 size, const U64 alignment) -> void*
		{
			return std::memset(AllocateAligned(size, alignment), 0, size);
		}

		NOX_HOT NOX_FLATTEN inline auto SystemAllocator::ReallocateAligned(void* const where, const U64 size, const U64 alignment) -> void*
		{
			#if NOX_OS_WINDOWS && NOX_COM_CLANG
				return _aligned_realloc(where, size, alignment);
			#else
			auto* const mem {AllocateAligned(size, alignment)};
			std::memcpy(mem, where, size);
			DeallocateAligned(where);
			return mem;
			#endif
		}

		NOX_HOT NOX_FLATTEN inline auto SystemAllocator::DeallocateAligned(void* const ptr) -> void
		{
			#if NOX_OS_WINDOWS && NOX_COM_CLANG
				_aligned_free(ptr);
			#else
			std::free(ptr);
			#endif
		}

		/// <summary>
		/// Generic runtime allocator interface.
		/// </summary>
		struct IAllocator
		{
			/// <summary>
			/// Impl constructor.
			/// </summary>
			/// <returns></returns>
			constexpr IAllocator() = default;

			/// <summary>
			/// Copy constructor.
			/// </summary>
			/// <param name="other"></param>
			constexpr IAllocator(const IAllocator& other) = default;

			/// <summary>
			/// Move constructor.
			/// </summary>
			/// <param name="other"></param>
			constexpr IAllocator(IAllocator&& other) = default;

			/// <summary>
			/// Copy assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator =(const IAllocator& other) -> IAllocator& = default;

			/// <summary>
			/// Move assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator =(IAllocator&& other) -> IAllocator& = default;

			/// <summary>
			/// Destructor.
			/// </summary>
			virtual ~IAllocator() = default;

			/// <summary>
			/// Raw allocate like malloc().
			/// </summary>
			/// <param name="out">Output pointer.</param>
			/// <param name="size">The size of the block in bytes.</param>
			/// <returns></returns>
			virtual auto Allocate(void*& out, U64 size) const -> void;

			/// <summary>
			/// Raw reallocate like realloc().
			/// </summary>
			/// <param name="out">Output pointer.</param>
			/// <param name="size">The size of the block in bytes.</param>
			/// <returns></returns>
			virtual auto Reallocate(void*& out, U64 size) const -> void;

			/// <summary>
			/// Raw deallocate like free().
			/// </summary>
			/// <param name="out">Input pointer.</param>
			/// <returns></returns>
			virtual auto Deallocate(void*& out) const -> void;


			/// <summary>
			/// Raw allocate with alignment like aligned_malloc().
			/// </summary>
			/// <param name="out"></param>
			/// <param name="alignment"></param>
			/// <param name="size"></param>
			/// <returns></returns>
			virtual auto AllocateAligned(void*& out, U64 size, U64 alignment) const -> void;

			/// <summary>
			/// 
			/// </summary>
			/// <param name="out"></param>
			/// <param name="alignment"></param>
			/// <param name="size"></param>
			/// <returns></returns>
			virtual auto ReallocateAligned(void*& out, U64 size, U64 alignment) const -> void;

			/// <summary>
			/// Raw deallocate aligned like free().
			/// </summary>
			/// <param name="out">Input pointer.</param>
			/// <returns></returns>
			virtual auto DeallocateAligned(void*& out) const -> void;

			/// <summary>
			/// Virtual alloc.
			/// </summary>
			/// <param name="out"></param>
			/// <param name="size"></param>
			/// <returns></returns>
			virtual auto Valloc(void*& out, U64 size) const -> void;

			/// <summary>
			/// Virtual free.
			/// </summary>
			/// <param name="out"></param>
			/// <returns></returns>
			virtual auto Vdealloc(void*& out) const -> void;
		};

		/// <summary>
		/// Fast runtime allocator.
		/// </summary>
		inline constinit IAllocator GlobalRuntimeAllocator { };

		/// <summary>
		/// Allocator for debugging based on the runtime allocator.
		/// It prints the size and address of each allocation
		/// and counts the bytes.
		/// </summary>
		class DebugAllocator final : public IAllocator
		{
			mutable U64 Allocations_ {0};
			mutable U64 Reallocations_ {0};
			mutable U64 Deallocations_ {0};
			mutable U64 BytesAllocated_ {0};

		public:
			/// <summary>
			/// Default constructor.
			/// </summary>
			/// <returns></returns>
			constexpr DebugAllocator() = default;

			/// <summary>
			/// Copy constructor.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr DebugAllocator(const DebugAllocator& other) = default;

			/// <summary>
			/// Move constructor.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr DebugAllocator(DebugAllocator&& other) = default;

			/// <summary>
			/// Copy assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator =(const DebugAllocator& other) -> DebugAllocator& = default;

			/// <summary>
			/// Move assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator =(DebugAllocator&& other) -> DebugAllocator& = default;

			/// <summary>
			/// Destructor.
			/// </summary>
			virtual ~DebugAllocator() override = default;

			/// <summary>
			/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
			/// </summary>
			/// <param name="out"></param>
			/// <param name="size"></param>
			/// <returns></returns>
			virtual auto Allocate(void*& out, U64 size) const -> void override;

			/// <summary>
			/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
			/// </summary>
			/// <param name="out"></param>
			/// <param name="size"></param>
			/// <returns></returns>
			virtual auto Reallocate(void*& out, U64 size) const -> void override;

			/// <summary>
			/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
			/// </summary>
			/// <param name="out"></param>
			/// <returns></returns>
			virtual auto Deallocate(void*& out) const -> void override;

			/// <summary>
			/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
			/// </summary>
			/// <param name="out"></param>
			/// <param name="size"></param>
			/// <param name="alignment"></param>
			/// <returns></returns>
			virtual auto AllocateAligned(void*& out, U64 size, U64 alignment) const -> void override;

			/// <summary>
			/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
			/// </summary>
			/// <param name="out"></param>
			/// <param name="size"></param>
			/// <param name="alignment"></param>
			/// <returns></returns>
			virtual auto ReallocateAligned(void*& out, U64 size, U64 alignment) const -> void override;

			/// <summary>
			/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
			/// </summary>
			/// <param name="out"></param>
			/// <returns></returns>
			virtual auto DeallocateAligned(void*& out) const -> void override;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The amount of allocations so far.</returns>
			constexpr auto GetAllocationCount() const -> U64;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The amount of reallocations so far.</returns>
			constexpr auto GetReallocationCount() const -> U64;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The amount of deallocations so far.</returns>
			constexpr auto GetDeallocationCount() const -> U64;

			/// <summary>
			/// The amount of allocated bytes so far.
			/// </summary>
			/// <returns></returns>
			constexpr auto GetTotalBytesAllocated() const -> U64;

			/// <summary>
			/// Print the amount of allocations and bytes.
			/// </summary>
			/// <returns></returns>
			auto DumpAllocationInfo() const -> void;
		};

		constexpr auto DebugAllocator::GetAllocationCount() const -> U64
		{
			return this->Allocations_;
		}

		constexpr auto DebugAllocator::GetReallocationCount() const -> U64
		{
			return this->Reallocations_;
		}

		constexpr auto DebugAllocator::GetDeallocationCount() const -> U64
		{
			return this->Deallocations_;
		}

		constexpr auto DebugAllocator::GetTotalBytesAllocated() const -> U64
		{
			return this->BytesAllocated_;
		}

		/// <summary>
		/// Slow debug allocator.
		/// </summary>
		inline constinit DebugAllocator GlobalDebugAllocator { };

		/// <summary>
		/// Currently used allocator.
		/// </summary>
		inline constinit const IAllocator* GlobalAllocatorProxy
		{
			#if NOX_DEBUG && NOX_VERBOSE_ALLOCATOR
		&GlobalDebugAllocator
			#else
			&GlobalRuntimeAllocator
			#endif
		};

		/// <summary>
		/// Stores the underlying type of an enum atomically as error code.
		/// </summary>
		/// <typeparam name="T">The enumeration type.</typeparam>
		/// <typeparam name="SuccessState">The enumeration type success code like Ok.</typeparam>
		/// <typeparam name="SingletonLock">If true the state is only updated when it is untouched (first time).</typeparam>
		template <typename T, const T SuccessState = T::Ok, const bool SingletonLock = true> requires std::is_enum_v<T>
		class AtomicState final
		{
			/// <summary>
			/// Underlying value type of enum.
			/// </summary>
			using ValueType = std::underlying_type_t<std::decay_t<T>>;

			static_assert(std::atomic<ValueType>::is_always_lock_free);

			/// <summary>
			/// Atomic storage.
			/// </summary>
			std::atomic<ValueType> Value_;

		public:
			/// <summary>
			/// Update error state.
			/// If "SingletonLock" is true,
			/// the state is only updated on the first call of this operator.
			/// </summary>
			/// <param name="x"></param>
			/// <returns></returns>
			constexpr auto operator ()(T x) -> void;

			/// <summary>
			/// Return current error state.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			constexpr auto operator ()() const -> T;

			/// <summary>
			/// Get atomic value container.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			constexpr auto operator *() const -> const std::atomic<ValueType>&;

			/// <summary>
			/// Returns true if the current state is
			/// equals to success state, else false.
			/// </summary>
			/// <returns></returns>
			constexpr operator bool() const;

			/// <summary>
			/// Construct with success state as value.
			/// </summary>
			/// <returns></returns>
			constexpr AtomicState();

			/// <summary>
			/// Construct with custom state.
			/// </summary>
			/// <param name="x"></param>
			/// <returns></returns>
			explicit constexpr AtomicState(T x);

			/// <summary>
			/// Move constructor.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr AtomicState(AtomicState&& other) = default;

			/// <summary>
			/// Copy constructor.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr AtomicState(const AtomicState& other) = default;

			/// <summary>
			/// Move assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator =(AtomicState&& other) -> AtomicState& = default;

			/// <summary>
			/// Copy assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator =(const AtomicState& other) -> AtomicState& = default;

			/// <summary>
			/// Destructor.
			/// </summary>
			~AtomicState() = default;
		};

		/// <summary>
		/// Update error state.
		/// If "SingletonLock" is true,
		/// the state is only updated on the first call of this operator.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		template <typename T, const T SuccessState, const bool SingletonLock> requires std::is_enum_v<T>
		constexpr auto AtomicState<T, SuccessState, SingletonLock>::operator()(const T x) -> void
		{
			if constexpr (SingletonLock)
			{
				if (x != SuccessState)
				[[unlikely]] // Only store if error state
				{
					if (this->Value_.load() == static_cast<ValueType>(SuccessState)) // Only store if untouched state
					{
						[[likely]]
							this->Value_.store(static_cast<ValueType>(x));
					}
				}
			}
			else
			{
				this->Value_.store(static_cast<ValueType>(x));
			}
		}

		/// <summary>
		/// Return current error state.
		/// </summary>
		/// <returns></returns>
		template <typename T, const T SuccessState, const bool SingletonLock> requires std::is_enum_v<T>
		constexpr auto AtomicState<T, SuccessState, SingletonLock>::operator()() const -> T
		{
			return static_cast<T>(this->Value_.load());
		}

		/// <summary>
		/// Get atomic value container.
		/// </summary>
		/// <returns></returns>
		template <typename T, const T SuccessState, const bool SingletonLock> requires std::is_enum_v<T>
		constexpr auto AtomicState<T, SuccessState, SingletonLock>::operator*() const -> const std::atomic<ValueType>&
		{
			return this->Value_;
		}

		/// <summary>
		/// Returns true if the current state is
		/// equals to success state, else false.
		/// </summary>
		/// <returns></returns>
		template <typename T, const T SuccessState, const bool SingletonLock> requires std::is_enum_v<T>
		constexpr AtomicState<T, SuccessState, SingletonLock>::operator bool() const
		{
			return (*this)() == SuccessState;
		}

		/// <summary>
		/// Construct with success state as value.
		/// </summary>
		/// <returns></returns>
		template <typename T, const T SuccessState, const bool SingletonLock> requires std::is_enum_v<T>
		constexpr AtomicState<T, SuccessState, SingletonLock>::AtomicState() : Value_ {static_cast<ValueType>(SuccessState)} { }

		/// <summary>
		/// Construct with custom state.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		template <typename T, const T SuccessState, const bool SingletonLock> requires std::is_enum_v<T>
		constexpr AtomicState<T, SuccessState, SingletonLock>::AtomicState(const T x) : Value_ {static_cast<ValueType>(x)} { }

		/// <summary>
		/// Generic bit rotation left.
		/// </summary>
		/// <param name="value"></param>
		/// <param name="shift"></param>
		/// <returns>The bit shifted value.</returns>
		template <typename T> requires std::is_unsigned_v<T>
		[[nodiscard]]
		NOX_FORCE_INLINE NOX_PURE constexpr auto RolGeneric(const T value, const U8 shift) -> T
		{
			return ((value) << (shift)) | ((value) >> (-static_cast<I32>(shift) & (CHAR_BIT * sizeof(value) - 1)));
		}

		/// <summary>
		/// Generic bit rotation right.
		/// </summary>
		/// <param name="value"></param>
		/// <param name="shift"></param>
		/// <returns>The bit shifted value.</returns>
		template <typename T> requires std::is_unsigned_v<T>
		[[nodiscard]]
		NOX_FORCE_INLINE NOX_PURE constexpr auto RorGeneric(const T value, const U8 shift) -> T
		{
			return (((value) << (-static_cast<I32>(shift) & (CHAR_BIT * sizeof(value) - 1))) | ((value) >> (shift)));
		}

		/// <summary>
		/// Fast, platform dependent implementation for a bitwise left rotation.
		/// </summary>
		[[nodiscard]]
		NOX_FORCE_INLINE NOX_PURE inline auto Rol32
		(
			U32      value,
			const U8 shift
		) -> U32
		{
			#if NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64 && !NOX_COM_GCC
		return _rotl(value, shift);
			#elif !NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64
		asm volatile
		(
			"roll %%cl, %0"
			: "=r"(value)
			: "0" (value), "c"(shift)
		);
		return value;
			#else
			return RolGeneric<decltype(value)>(value, shift);
			#endif
		}

		/// <summary>
		/// Fast, platform dependent implementation for a bitwise right rotation.
		/// </summary>
		[[nodiscard]]
		NOX_FORCE_INLINE NOX_PURE inline auto Ror32
		(
			U32      value,
			const U8 shift
		) -> U32
		{
			#if NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64 && !NOX_COM_GCC
		return _rotr(value, shift);
			#elif !NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64
		asm volatile
		(
			"rorl %%cl, %0"
			: "=r"(value)
			: "0" (value), "c"(shift)
		);
		return value;
			#else
			return RorGeneric<decltype(value)>(value, shift);
			#endif
		}

		/// <summary>
		/// Fast, platform dependent implementation for a bitwise left rotation.
		/// </summary>
		[[nodiscard]]
		NOX_FORCE_INLINE NOX_PURE inline auto Rol64
		(
			U64      value,
			const U8 shift
		) -> U64
		{
			#if NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64 && !NOX_COM_GCC
		return _rotl64(value, shift);
			#elif !NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64
		asm volatile
		(
			"rolq %%cl, %0"
			: "=r"(value)
			: "0" (value), "c"(shift)
		);
		return value;
			#else
			return RolGeneric<decltype(value)>(value, shift);
			#endif
		}

		/// <summary>
		/// Fast, platform dependent implementation for a bitwise right rotation.
		/// </summary>
		[[nodiscard]]
		NOX_FORCE_INLINE NOX_PURE inline auto Ror64
		(
			U64      value,
			const U8 shift
		) -> U64
		{
			#if NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64 && !NOX_COM_GCC
		return _rotr64(value, shift);
			#elif !NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64
		asm volatile
		(
			"rorq %%cl, %0"
			: "=r"(value)
			: "0" (value), "c"(shift)
		);
		return value;
			#else
			return RorGeneric<decltype(value)>(value, shift);
			#endif
		}

		/// <summary>
		/// Trigger a breakpoint, works in release mode too.
		/// Good for debugging release code or looking at assembler.
		/// </summary>
		NOX_FORCE_INLINE NOX_COLD inline auto BreakpointInterrupt() -> void
		{
			#if NOX_ARCH_X86_64
			__asm__("int3");
			#elif NOX_ARCH_ARM_64
			#if NOX_OS_MAC || NOX_OS_IOS
				__asm__("trap");
			#else
				__asm__("bkpt 0");
			#endif
			#else
			*reinterpret_cast<volatile I32*>(3) = 3;
			#endif
		}

		/// <summary>
		/// Prevents the compiler from optimizing away the value.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="x"></param>
		/// <returns></returns>
		template <typename T>
		inline auto DisOpt(T& x) -> void
		{
			#if NOX_COM_CLANG
			asm volatile("" : "+r,m"(x) : : "memory");
			#else
			asm volatile("" : "+m,r"(x) :: "memory");
			#endif
		}

	// @formatter:off

	/// <summary>
	/// Insert memory read fence barrier.
	/// Force the compiler to flush queued writes to global memory.
	/// </summary>
	[[maybe_unused]]
	NOX_FORCE_INLINE inline auto ReadFence()  -> void
	{
		asm volatile("" : : : "memory");
	}

	/// <summary>
	/// Insert memory write fence barrier.
	/// Force the compiler to flush queued writes to global memory.
	/// </summary>
	[[maybe_unused]]
	NOX_FORCE_INLINE inline auto WriteFence()  -> void
	{
		asm volatile("" : : : "memory");
	}

	/// <summary>
	/// Insert memory read-write fence barrier.
	/// Force the compiler to flush queued writes to global memory.
	/// </summary>
	[[maybe_unused]]
	NOX_FORCE_INLINE inline auto ReadWriteFence()  -> void
	{
		asm volatile("" : : : "memory");
	}

		// @formatter:on

		/// <summary>
		/// No operation LOL
		/// </summary>
		NOX_FORCE_INLINE inline auto NoOperation() -> void
		{
			asm volatile("nop");
		}

		/// <summary>
		/// Signal status flag.
		/// </summary>
		extern constinit volatile thread_local std::sig_atomic_t SignalStatus;

		/// <summary>
		/// Query current signal status.
		/// </summary>
		/// <returns></returns>
		extern auto QuerySignalStatus() -> std::sig_atomic_t;

		/// <summary>
		/// Install global signal handler.
		/// </summary>
		/// <param name="handler"></param>
		/// <returns></returns>
		extern auto InstallSignalHandlers(auto (&handler)(std::sig_atomic_t) -> void) -> void;

		/// <summary>
		/// Reset all signal handles to default.
		/// </summary>
		/// <returns></returns>
		extern auto UninstallSignalHandlers() -> void;

		/// <summary>
		/// Helper to parse command line interface arguments.
		/// </summary>
		class CliArgParser final
		{
			std::unordered_set<std::string_view>                       Args_ { };
			std::vector<std::pair<std::string_view, std::string_view>> Options_ { };

		public:
			/// <summary>
			/// Construct with argc and argv from
			/// the entry point.
			/// </summary>
			/// <param name="argc"></param>
			/// <param name="argv"></param>
			/// <returns></returns>
			CliArgParser(signed argc, const char* const* argv);

			/// <summary>
			/// No copy.
			/// </summary>
			/// <param name="other"></param>
			CliArgParser(const CliArgParser& other) = delete;

			/// <summary>
			/// Move constructor.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			CliArgParser(CliArgParser&& other) = default;

			/// <summary>
			/// No copy.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(const CliArgParser& other) -> CliArgParser& = delete;

			/// <summary>
			/// Move assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(CliArgParser&& other) -> CliArgParser& = default;

			/// <summary>
			/// Destructor.
			/// </summary>
			~CliArgParser() = default;

			/// <summary>
			/// Returns true if the command line flag is set,
			/// else false.
			/// </summary>
			/// <param name="key"></param>
			/// <returns></returns>
			[[nodiscard]]
			auto HasFlag(std::string_view key) -> bool;

			/// <summary>
			/// Adds a command line option with description and returns true
			/// if the flag is set, else false.
			/// </summary>
			/// <param name="name"></param>
			/// <param name="description"></param>
			/// <returns></returns>
			[[nodiscard]]
			auto AddOption(std::string_view name, std::string_view description = "") -> bool;

			/// <summary>
			/// Prints all the added options with description.
			/// </summary>
			/// <returns></returns>
			auto PrintAllOptions() -> void;

			/// <summary>
			/// Returns true if the argument count is less or equal to one,
			/// because one is the self path, else false.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto IsEmpty() const -> bool;

			/// <summary>
			/// Returns argument set.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto GetArgs() const -> const std::unordered_set<std::string_view>&;

			/// <summary>
			/// Returns all added options.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto GetOptions() const -> const std::vector<std::pair<std::string_view, std::string_view>>&;
		};

		/// <summary>
		/// Zero tolerance epsilon.
		/// </summary>
		constexpr auto F64_ZERO_TOLERANCE {1e-6}; // 8 * 1.19209290E-07F

		/// <summary>
		/// Returns true if x is zero, else false.
		/// </summary>
		/// <param name="x">The number to check for zero.</param>
		/// <returns>True if x is zero, else false.</returns>
		NOX_FLATTEN NOX_PURE inline auto F64IsZero(const F64 x) -> bool
		{
			return std::abs(x) < F64_ZERO_TOLERANCE;
		}

		/// <summary>
		/// Returns true if x is one, else false.
		/// </summary>
		/// <param name="x">The number to check for zero.</param>
		/// <returns>True if x is zero, else false.</returns>
		NOX_FLATTEN NOX_PURE inline auto F64IsOne(const F64 x) -> bool
		{
			return F64IsZero(x - 1.0);
		}

		/// <summary>
		/// How many ULP's (Units in the Last Place) we want to tolerate when comparing two numbers.
		/// The large the value, the more error (mismatch) the comparison will allow.
		/// If the ULP value is zero, the two numbers must be exactly the same.
		/// See http://randomascii.wordpress.com/2012/02/25/comparing-F32ing-point-numbers-2012-edition/ by Bruce Dawson
		/// </summary>
		constexpr U32 F64_MAX_ULPS {4};

		/// <summary>
		/// Bit count inside F64.
		/// </summary>
		constexpr auto F64_BIT_COUNT {8 * sizeof(F64)};

		/// <summary>
		/// Fraction bit count.
		/// </summary>
		constexpr auto F64_FRACTION_BITS {std::numeric_limits<F64>::digits - 1};

		/// <summary>
		/// Exponent bit count.
		/// </summary>
		constexpr auto F64_EXPONENT_BITS {F64_BIT_COUNT - 1 - F64_FRACTION_BITS};

		/// <summary>
		/// Mask to extract sign bit.
		/// </summary>
		constexpr auto F64_SIGN_MASK {UINT64_C(1) << (F64_BIT_COUNT - 1)};

		/// <summary>
		/// Mask to extract fraction.
		/// </summary>
		constexpr auto F64_FRACTION_MASK {~UINT64_C(0) >> (F64_EXPONENT_BITS + 1)};

		/// <summary>
		/// Mask to extract exponent.
		/// </summary>
		constexpr auto F64_EXPONENT_MASK {~(F64_SIGN_MASK | F64_FRACTION_MASK)};

		/// <summary>
		/// Returns the bit representation of the F64.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		NOX_FLATTEN NOX_PURE constexpr auto BitsOf(const F64 x) -> U64
		{
			static_assert(sizeof(U64) == sizeof(F64));
			return std::bit_cast<U64>(x);
		}

		/// <summary>
		/// Extract exponent bits.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		NOX_FLATTEN NOX_PURE constexpr auto ExponentBitsOf(const F64 x) -> U64
		{
			return F64_EXPONENT_MASK & BitsOf(x);
		}

		/// <summary>
		/// Extract fraction bits.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		NOX_FLATTEN NOX_PURE constexpr auto FractionBitsOf(const F64 x) -> U64
		{
			return F64_FRACTION_MASK & BitsOf(x);
		}

		/// <summary>
		/// Extract sign bit.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		NOX_FLATTEN NOX_PURE constexpr auto SignBitOf(const F64 x) -> U64
		{
			return F64_SIGN_MASK & BitsOf(x);
		}

		/// <summary>
		/// Returns true if x is NAN, else false.
		/// NAN = Not A Number
		/// </summary>
		NOX_FLATTEN NOX_PURE constexpr auto IsNan(const F64 x) -> bool
		{
			return ExponentBitsOf(x) == F64_EXPONENT_MASK && FractionBitsOf(x) != 0;
		}

		/// <summary>
		/// Converts an integer from the "sign and magnitude" to the biased representation.
		/// See https://en.wikipedia.org/wiki/Signed_number_representations for more info.
		/// </summary>
		NOX_FLATTEN NOX_PURE constexpr auto SignMagnitudeToBiasedRepresentation(const U64 bits) -> U64
		{
			if (F64_SIGN_MASK & bits)
			{
				return ~bits + 1;
			}
			return F64_SIGN_MASK | bits;
		}

		/// <summary>
		/// Returns the unsigned distance between bitsA and bitsB.
		/// bitsA and bitsB must be converted into the biased representation first!
		/// </summary>
		/// <param name="bitsA">The first bits as biased representation.</param>
		/// <param name="bitsB">The second bits as biased representation.</param>
		/// <returns>The unsigned distance.</returns>
		NOX_FLATTEN NOX_PURE constexpr auto ComputeDistanceBetweenSignAndMagnitude(const U64 bitsA, const U64 bitsB) -> U64
		{
			const auto biasedA {SignMagnitudeToBiasedRepresentation(bitsA)};
			const auto biasedB {SignMagnitudeToBiasedRepresentation(bitsB)};
			return biasedA >= biasedB ? biasedA - biasedB : biasedB - biasedA;
		}

		/// <summary>
		/// Returns true if x and y are near or equal.
		/// Returns false if either x or y or both are NAN.
		/// Huge numbers are treated almost as infinity.
		/// Uses a ULP based approach.
		/// See https://randomascii.wordpress.com/2012/02/25/comparing-F32ing-point-numbers-2012-edition/
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <returns></returns>
		template <U32 Ulps = F64_MAX_ULPS>
		NOX_FLATTEN NOX_PURE constexpr auto F64Equals(const F64 x, const F64 y) -> bool
		{
			static_assert(Ulps > 0);
			// IEEE 754 required that any NAN comparison should yield false.
			if (IsNan(x) || IsNan(y))
			{
				return false;
			}

			return ComputeDistanceBetweenSignAndMagnitude(BitsOf(x), BitsOf(y)) <= Ulps;
		}

		/// <summary>
		/// Proxy gate for correct float comparison based on macro config.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		NOX_FORCE_INLINE NOX_PURE inline auto Proxy_F64IsZero(const F64 x) -> bool
		{
			#if NOX_OPT_USE_ZERO_EPSILON
			return F64IsZero(x);
			#else
			return x == 0.0;
			#endif
		}

		/// <summary>
		/// Proxy gate for correct float comparison based on macro config.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		NOX_FORCE_INLINE NOX_PURE inline auto Proxy_F64IsOne(const F64 x) -> bool
		{
			#if NOX_OPT_USE_ZERO_EPSILON
			return F64IsOne(x);
			#else
			return x == 1.0;
			#endif
		}

		/// <summary>
		/// Proxy gate for correct float comparison based on macro config.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		NOX_FORCE_INLINE NOX_PURE inline auto Proxy_F64Equals(const F64 x, const F64 y) -> bool
		{
			#if NOX_OPT_USE_ZERO_EPSILON
			return F64Equals(x, y);
			#else
			return x == y;
			#endif
		}

		/// <summary>
		/// Construct a runtime integer (64-bit).
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		constexpr auto operator""_int(const unsigned long long int value) -> I64
		{
			return static_cast<I64>(value);
		}

		/// <summary>
		/// Construct a runtime unsigned integer (64-bit).
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		constexpr auto operator""_uint(const unsigned long long int value) -> U64
		{
			return value;
		}

		/// <summary>
		/// Construct a runtime F32 (64-bit).
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
		constexpr auto operator""_float(const long double value) -> F64
		{
			return static_cast<F64>(value);
		}

		/// <summary>
		/// Represents a printable text color (if the terminal supports it).
		/// </summary>
		enum class TextColor : std::underlying_type_t<fmt::terminal_color>
		{
			Black = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::black),
			Red = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::red),
			Green = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::green),
			Yellow = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::yellow),
			Blue = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::blue),
			Magenta = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::magenta),
			Cyan = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::cyan),
			White = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::white),
			BrightBlack = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::bright_black),
			BrightRed = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::bright_red),
			BrightGreen = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::bright_green),
			BrightYellow = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::bright_yellow),
			BrightBlue = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::bright_blue),
			BrightMagenta = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::bright_magenta),
			BrightCyan = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::bright_cyan),
			BrightWhite = static_cast<std::underlying_type_t<fmt::terminal_color>>(fmt::terminal_color::bright_white)
		};

		/// <summary>
		/// Prints out the formatting string and
		/// formats the arguments into the string if format
		/// arguments are given.
		/// The formatting rules follow the C++ 20 <format> convention.
		/// All printing inside Nominax should be done via this functions
		/// and friends because it also allows different configurations.
		/// </summary>
		/// <typeparam name="Str">The string type.</typeparam>
		/// <typeparam name="...Args">The argument types.</typeparam>
		/// <param name="formatString">The format string.</param>
		/// <param name="args">The arguments to format.</param>
		template <typename Str, typename... Args>
		inline auto Print([[maybe_unused]] const Str& formatString, [[maybe_unused]] Args&&...args) -> void
		{
			#ifndef NOX_TEST
			fmt::print(formatString, std::forward<Args>(args)...);
			#endif
		}

		/// <summary>
		/// Print single char.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		inline auto Print(const char x) -> void
		{
			Print("{}", x);
		}

		/// <summary>
		/// Contains all log levels.
		/// </summary>
		enum class LogLevel
		{
			Info,
			Warning,
			Error,
			Success
		};

		/// <summary>
		/// Prints out the formatting string and
		/// formats the arguments into the string if format
		/// arguments are given.
		/// The formatting rules follow the C++ 20 <format> convention.
		/// All printing inside Nominax should be done via this functions
		/// and friends because it also allows different configurations.
		/// The logging level can be specified, which prints in different colors.
		/// </summary>
		/// <typeparam name="Str">The string type.</typeparam>
		/// <typeparam name="...Args">The argument types.</typeparam>
		/// <param name="level"> The logging level can be specified, which prints in different colors.</param>
		/// <param name="formatString">The format string.</param>
		/// <param name="args">The arguments to format.</param>
		template <typename Str, typename... Args>
		auto Print([[maybe_unused]] const LogLevel level, [[maybe_unused]] const Str& formatString, [[maybe_unused]] Args&&...args) -> void
		{
			#ifndef NOX_TEST
			auto color = TextColor::White;
			switch (level)
			{
				case LogLevel::Info:
					color = TextColor::White;
					break;
				case LogLevel::Warning:
					color = TextColor::Yellow;
					break;
				case LogLevel::Error:
					color = TextColor::Red;
					break;
				case LogLevel::Success:
					color = TextColor::Green;
					break;
			}
			fmt::print(fg(static_cast<fmt::terminal_color>(color)), formatString, std::forward<Args>(args)...);
			#endif
		}

		/// <summary>
		/// Prints out the formatting string and
		/// formats the arguments into the string if format
		/// arguments are given.
		/// The formatting rules follow the C++ 20 <format> convention.
		/// All printing inside Nominax should be done via this functions
		/// and friends because it also allows different configurations.
		/// </summary>
		/// <typeparam name="Str">The string type.</typeparam>
		/// <typeparam name="...Args">The argument types.</typeparam>
		/// <param name="color">The foreground color of the text.</param>
		/// <param name="formatString">The format string.</param>
		/// <param name="args">The arguments to format.</param>
		template <typename Str, typename... Args>
		inline auto Print([[maybe_unused]] const TextColor color, [[maybe_unused]] const Str& formatString, [[maybe_unused]] Args&&...args) -> void
		{
			#ifndef NOX_TEST
			fmt::print(fg(static_cast<fmt::terminal_color>(color)), formatString, std::forward<Args>(args)...);
			#endif
		}

		/// <summary>
		/// Formats the arguments into the string if format
		/// arguments are given.
		/// The formatting rules follow the C++ 20 <format> convention.
		/// All printing inside Nominax should be done via this functions
		/// and friends because it also allows different configurations.
		/// </summary>
		/// <typeparam name="Str">The string type.</typeparam>
		/// <typeparam name="...Args">The argument types.</typeparam>
		/// <param name="formatString">The format string.</param>
		/// <param name="args">The arguments to format.</param>
		template <typename Str, typename... Args>
		inline auto Format([[maybe_unused]] const Str& formatString, [[maybe_unused]] Args&&...args) -> std::string
		{
			return fmt::format(formatString, std::forward<Args>(args)...);
		}

		/// <summary>
		/// Thread safe local time.
		/// </summary>
		/// <param name="time"></param>
		/// <returns></returns>
		[[nodiscard]]
		extern auto SafeLocalTime(const std::time_t& time) -> std::tm;

		/// <summary>
		/// Represents a monotonic stopwatch.
		/// Used for profiling and time measurements.
		/// </summary>
		/// <typeparam name="Clock"></typeparam>
		template <typename Clock = std::chrono::high_resolution_clock>
		class Stopwatch final
		{
			typename Clock::time_point Stamp_ {Clock::now()};

		public:
			/// <summary>
			/// 
			/// </summary>
			/// <returns>The timestamp set when created.</returns>
			[[nodiscard]]
			auto Stamp() const -> typename Clock::time_point;

			/// <summary>
			/// Query elapsed time.
			/// </summary>
			/// <typeparam name="Dur">The duration type to use.</typeparam>
			/// <returns>The elapsed time.</returns>
			template <typename Dur = typename Clock::duration>
			[[nodiscard]]
			auto Elapsed() const -> typename Clock::duration;

			/// <summary>
			/// Query elapsed time as seconds.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto ElapsedSecs() const -> std::chrono::seconds;

			/// <summary>
			/// Query elapsed time as floating point seconds.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto ElapsedSecsF64() const -> std::chrono::duration<F64>;

			/// <summary>
			/// Reset time stamp to now.
			/// </summary>
			/// <returns></returns>
			auto Restart() -> void;
		};

		template <typename Clock>
		inline auto Stopwatch<Clock>::Stamp() const -> typename Clock::time_point
		{
			return this->Stamp_;
		}

		template <typename Clock>
		template <typename Dur>
		inline auto Stopwatch<Clock>::Elapsed() const -> typename Clock::duration
		{
			return std::chrono::duration_cast<Dur>(Clock::now() - this->Stamp_);
		}

		template <typename Clock>
		inline auto Stopwatch<Clock>::ElapsedSecs() const -> std::chrono::seconds
		{
			return std::chrono::duration_cast<std::chrono::seconds>(this->Elapsed<>());
		}

		template <typename Clock>
		inline auto Stopwatch<Clock>::ElapsedSecsF64() const -> std::chrono::duration<F64>
		{
			return std::chrono::duration_cast<std::chrono::duration<F64>>(this->Elapsed<>());
		}

		template <typename Clock>
		inline auto Stopwatch<Clock>::Restart() -> void
		{
			this->Stamp_ = Clock::now();
		}

		/// <summary>
		/// Base class for all serializable objects.
		/// </summary>
		class ISerializable
		{
		protected:
			/// <summary>
			/// Construct.
			/// </summary>
			constexpr ISerializable() = default;

		public:
			/// <summary>
			/// Copy constructor.
			/// </summary>
			/// <param name="other"></param>
			ISerializable(const ISerializable& other) = default;

			/// <summary>
			/// Move constructor.
			/// </summary>
			/// <param name="other"></param>
			ISerializable(ISerializable&& other) = default;

			/// <summary>
			/// Copy assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(const ISerializable& other) -> ISerializable& = default;

			/// <summary>
			/// Move assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(ISerializable&& other) -> ISerializable& = default;

			/// <summary>
			/// Destructor.
			/// </summary>
			virtual ~ISerializable() = default;

			/// <summary>
			/// Serialize to file stream.
			/// </summary>
			/// <returns>True on success, else false.</returns>
			[[nodiscard]]
			virtual auto SerializeToFile(const std::filesystem::path& file) const -> bool;

			/// <summary>
			/// Deserialize from file stream.
			/// </summary>
			/// <returns>True on success, else false.</returns>
			[[nodiscard]]
			virtual auto DeserializeFromFile(const std::filesystem::path& file) -> bool;

			/// <summary>
			/// Serialize to file stream.
			/// </summary>
			/// <returns>True on success, else false.</returns>
			[[nodiscard]]
			virtual auto Serialize(std::ofstream& out) const -> bool = 0;

			/// <summary>
			/// Deserialize from file stream.
			/// </summary>
			/// <returns>True on success, else false.</returns>
			[[nodiscard]]
			virtual auto Deserialize(std::ifstream& in) -> bool = 0;
		};
	}

	/// <summary>
	/// Contains info for the panic handler.
	/// </summary>
	struct PanicDescriptor final
	{
		/// <summary>
		/// The source code line - if any.
		/// </summary>
		U32 Line { };

		/// <summary>
		/// The source file name  - if any.
		/// </summary>
		std::string_view FileName { };

		/// <summary>
		/// The name of the subroutine - if any.
		/// </summary>
		std::string_view RoutineName { };

		/// <summary>
		/// The callsite message - if any.
		/// </summary>
		std::string_view Message { };

		/// <summary>
		/// If true, the content of the registers is dumped, else false.
		/// </summary>
		bool DumpRegisters {true};
	};

	/// <summary>
	/// Implementation of the panic routine.
	/// </summary>
	/// <param name="panicDescriptor"></param>
	/// <returns></returns>
	[[noreturn]]
	NOX_COLD NOX_NEVER_INLINE
	extern auto PanicTerminationImpl(const PanicDescriptor& panicDescriptor) -> void;

	/// <summary>
	/// Merges information about the current source file and the line.
	/// This will be replaced by C++ 20 std::source_location,
	/// but currently it's not yet implemented :(
	/// </summary>
	#define NOX_PANIC_INFO() __LINE__, __FILE__, __FUNCTION__

	/// <summary>
	/// Terminates the process with an error messages in the terminal.
	/// </summary>
	/// <typeparam name="Str"></typeparam>
	/// <typeparam name="...Args"></typeparam>
	/// <param name="line"></param>
	/// <param name="file"></param>
	/// <param name="routine"></param>
	/// <param name="formatString"></param>
	/// <param name="args"></param>
	/// <returns></returns>
	template <typename Str, typename... Args>
	[[noreturn]]
	NOX_COLD NOX_NEVER_INLINE
	auto Panic
	(
		const U32              line,
		const std::string_view file,
		const std::string_view routine,
		Str&&                  formatString,
		Args&&...              args
	) -> void
	{
		const auto            message {Foundation::Format(formatString, std::forward<Args>(args)...)};
		const PanicDescriptor desc
		{
			.Line = line,
			.FileName = file,
			.RoutineName = routine,
			.Message = message,
			.DumpRegisters = true
		};
		PanicTerminationImpl(desc);
	}

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_TRUE(x, msg)					\
	do												\
	{												\
		if (!( x ))                 				\
		{                                           \
		    [[unlikely]]                            \
            ::Nominax::Panic( NOX_PANIC_INFO(), ( msg ));	\
		}											\
	}												\
	while(false)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_FALSE(x, msg)					\
	do												\
	{												\
		if (( x ))				                    \
		{											\
		    [[unlikely]]                            \
            ::Nominax::Panic( NOX_PANIC_INFO(), ( msg ));	\
		}											\
	}												\
	while(false)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_NULL(x, msg) NOX_PAS_FALSE(x, msg)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_NOT_NULL(x, msg) NOX_PAS_TRUE(x, msg)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_ZERO(x, msg) NOX_PAS_FALSE(x, msg)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_NOT_ZERO(x, msg) NOX_PAS_TRUE(x, msg)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_EQ(x, y, msg)					\
	do												\
	{												\
		if (( x ) != ( y ))		                    \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic( NOX_PANIC_INFO(), ( msg ));	\
		}											\
	}												\
	while(false)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_NE(x, y, msg)					\
	do												\
	{												\
		if (( x ) == ( y ))		                    \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic( NOX_PANIC_INFO(), ( msg ));	\
		}											\
	}												\
	while(false)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_L(x, y, msg)					\
	do												\
	{												\
		if (!(( x ) < ( y )))		                \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic( NOX_PANIC_INFO(), ( msg ));	\
		}											\
	}												\
	while(false)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_LE(x, y, msg)					\
	do												\
	{												\
		if (!(( x ) <= ( y )))	                    \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic( NOX_PANIC_INFO(), ( msg ));	\
		}											\
	}												\
	while(false)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_G(x, y, msg)					\
	do												\
	{												\
		if (!(( x ) > ( y )))		                \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic( NOX_PANIC_INFO(), ( msg ));	\
		}											\
	}												\
	while(false)

	/// <summary>
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_PAS_GE(x, y, msg)					\
	do												\
	{												\
		if (!(( x ) >= ( y )))	                    \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic( NOX_PANIC_INFO(), ( msg ));	\
		}											\
	}												\
	while(false)

	#if NOX_DEBUG
	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_TRUE(x, msg)		NOX_PAS_TRUE(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_FALSE(x, msg)		NOX_PAS_FALSE(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_NULL(x, msg)		NOX_PAS_NULL(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_NOT_NULL(x, msg)	NOX_PAS_NOT_NULL(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_ZERO(x, msg)		NOX_PAS_ZERO(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_NOT_ZERO(x, msg)	NOX_PAS_NOT_ZERO(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_EQ(x, y, msg)		NOX_PAS_EQ(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_NE(x, y, msg)		NOX_PAS_NE(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_L(x, y, msg)		NOX_PAS_L(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_LE(x, y, msg)		NOX_PAS_LE(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_G(x, y, msg)		NOX_PAS_G(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_GE(x, y, msg)		NOX_PAS_GE(x, y, msg)

	#else
	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_TRUE(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_FALSE(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_NULL(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_NOT_NULL(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_ZERO(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_NOT_ZERO(x, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_EQ(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_NE(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_L(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_LE(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_G(x, y, msg)

	/// <summary>
	/// Only active when building for DEBUG.
	/// Checks the condition and panics with the specified message,
	/// if the condition is not true.
	/// </summary>
	#define NOX_DBG_PAS_GE(x, y, msg)
	#endif

	namespace Foundation
	{
		NOX_FLATTEN inline auto SystemAllocator::AllocateChecked(const U64 size) -> void*
		{
			void* mem {Allocate(size)};
			NOX_PAS_NOT_NULL(mem, "Allocation error!");
			return mem;
		}

		NOX_FLATTEN inline auto SystemAllocator::AllocateAndZeroChecked(const U64 size) -> void*
		{
			void* mem {AllocateAndZero(size)};
			NOX_PAS_NOT_NULL(mem, "Allocation error!");
			return mem;
		}

		NOX_FLATTEN inline auto SystemAllocator::ReallocateChecked(void* const where, const U64 size) -> void*
		{
			void* mem {Reallocate(where, size)};
			NOX_PAS_NOT_NULL(mem, "Allocation error!");
			return mem;
		}

		NOX_FLATTEN inline auto SystemAllocator::DeallocateChecked(void* const ptr) -> void
		{
			NOX_PAS_NOT_NULL(ptr, "Allocation error!");
			Deallocate(ptr);
		}

		NOX_FLATTEN inline auto SystemAllocator::AllocateAlignedChecked(const U64 size, const U64 alignment) -> void*
		{
			void* const mem {AllocateAligned(size, alignment)};
			NOX_PAS_NOT_NULL(mem, "Allocation error!");
			return mem;
		}

		NOX_FLATTEN inline auto SystemAllocator::AllocateAlignedAndZeroChecked(const U64 size, const U64 alignment) -> void*
		{
			void* const mem {AllocateAlignedAndZero(size, alignment)};
			NOX_PAS_NOT_NULL(mem, "Allocation error!");
			return mem;
		}

		NOX_FLATTEN inline auto SystemAllocator::ReallocateAlignedChecked(void* const where, const U64 size, const U64 alignment) -> void*
		{
			void* const mem {ReallocateAligned(where, size, alignment)};
			NOX_PAS_NOT_NULL(mem, "Allocation error!");
			return mem;
		}

		NOX_FLATTEN inline auto SystemAllocator::DeallocateAlignedChecked(void* const ptr) -> void
		{
			NOX_PAS_NOT_NULL(ptr, "Allocation error!");
			DeallocateAligned(ptr);
		}

		/// <summary>
		/// Helper to work with text files.
		/// </summary>
		class TextFile final
		{
		public:
			/// <summary>
			/// String type alias.
			/// </summary>
			using StringType = std::string;

			/// <summary>
			/// String view type.
			/// </summary>
			using ViewType = std::string_view;

		private:
			/// <summary>
			/// The content of the file.
			/// </summary>
			StringType Content_ { };

			/// <summary>
			/// The path of the file.
			/// </summary>
			std::filesystem::path FilePath_ { };

		public:
			/// <summary>
			/// The character type.
			/// </summary>
			using CharType = decltype(Content_)::value_type;

			/// <summary>
			/// The type for the file input stream.
			/// </summary>
			using InputStream = std::basic_ifstream<CharType, std::char_traits<CharType>>;

			/// <summary>
			/// The type for the file output stream.
			/// </summary>
			using OutputStream = std::basic_ofstream<CharType, std::char_traits<CharType>>;

			/// <summary>
			/// Construct empty.
			/// </summary>
			/// <returns></returns>
			TextFile() = default;

			/// <summary>
			/// Construct with content.
			/// </summary>
			/// <param name="content">Content of the file.</param>
			/// <returns></returns>
			explicit TextFile(StringType&& content);

			/// <summary>
			/// Construct with path and content.
			/// </summary>
			/// <param name="path"></param>
			/// <param name="content"></param>
			/// <returns></returns>
			TextFile(std::filesystem::path&& path, StringType&& content);

			/// <summary>
			/// No copy.
			/// </summary>
			/// <param name="other"></param>
			TextFile(const TextFile& other) = delete;

			/// <summary>
			/// Move constructor.
			/// </summary>
			/// <param name="other"></param>
			TextFile(TextFile&& other) = default;

			/// <summary>
			/// No copy.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(const TextFile& other) -> TextFile& = delete;

			/// <summary>
			/// Move assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(TextFile&& other) -> TextFile& = default;

			/// <summary>
			/// Destructor.
			/// </summary>
			~TextFile() = default;

			/// <summary>
			/// Writes the content into the specified path
			/// and saves the path argument into this class instance content.
			/// </summary>
			/// <param name="path"></param>
			/// <returns>True on success, else false.</returns>
			[[nodiscard]]
			auto WriteToFile(std::filesystem::path&& path) -> bool;

			/// <summary>
			/// Reads the content of the file into this class instance content.
			/// </summary>
			/// <param name="path"></param>
			/// <returns>True on success, else false.</returns>
			[[nodiscard]]
			auto ReadFromFile(std::filesystem::path&& path) -> bool;

			/// <summary>
			/// Reads the content of the file into this class instance and panics on any fail.
			/// </summary>
			/// <param name="path"></param>
			/// <returns></returns>
			auto ReadFromFileOrPanic(std::filesystem::path&& path) -> void;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The current text file content.</returns>
			[[nodiscard]]
			auto GetContentText() const & -> const StringType&;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The current text file content.</returns>
			[[nodiscard]]
			auto GetContentText() & -> StringType&;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The current text file content.</returns>
			[[nodiscard]]
			auto GetContentText() && -> StringType&&;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The current file path.</returns>
			[[nodiscard]]
			auto GetFilePath() const & -> const std::filesystem::path&;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The current file path.</returns>
			[[nodiscard]]
			auto GetFilePath() && -> std::filesystem::path&&;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>True if the content is empty, else false.</returns>
			[[nodiscard]]
			auto IsEmpty() const -> bool;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The capacity of the content.</returns>
			[[nodiscard]]
			auto GetCapacity() const -> U64;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The size of the content - the number of characters.</returns>
			[[nodiscard]]
			auto GetSize() const -> U64;

			/// <summary>
			/// 
			/// </summary>
			/// <returns>The size of the content in bytes (capacity * charSize)</returns>
			[[nodiscard]]
			auto GetSizeInBytes() const -> U64;

			/// <summary>
			/// Removes all the spaces (' ') from the content in parallel.
			/// </summary>
			/// <returns></returns>
			auto ParallelEraseSpaces() -> void;

			/// <summary>
			/// Removes all spaces and control characters from the content in parallel.
			/// </summary>
			/// <returns></returns>
			auto ParallelEraseSpacesAndControlChars() -> void;

			/// <summary>
			/// Removes all the occurrences of the character in parallel.
			/// </summary>
			/// <param name="x"></param>
			/// <returns></returns>
			auto ParallelErase(CharType x) -> void;

			/// <summary>
			/// Searches all the ranges between the two chars and removes the text between them and themselves.
			/// </summary>
			/// <param name="begin"></param>
			/// <param name="end"></param>
			/// <returns></returns>
			auto EraseRange(CharType begin, CharType end) -> void;

			/// <summary>
			/// Get a substring string view to the
			/// content between the two indices (both inclusive).
			/// </summary>
			/// <param name="beginIdx"></param>
			/// <param name="endIdx"></param>
			/// <returns></returns>
			[[nodiscard]]
			auto SubString(U64 beginIdx, U64 endIdx) const -> ViewType;

			/// <summary>
			/// Get a substring string view to the
			/// content between the two first chars found (both inclusive).
			/// </summary>
			/// <param name="beginChar"></param>
			/// <param name="endChar"></param>
			/// <returns></returns>
			[[nodiscard]]
			auto SubStringChar(CharType beginChar, CharType endChar) const -> ViewType;

			/// <summary>
			/// STL iterator compat.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto begin() -> StringType::iterator;

			/// <summary>
			/// STL iterator compat.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto end() -> StringType::iterator;

			/// <summary>
			/// STL iterator compat.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto rbegin() -> StringType::reverse_iterator;

			/// <summary>
			/// STL iterator compat.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto rend() -> StringType::reverse_iterator;

			/// <summary>
			/// STL iterator compat.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto cbegin() const -> StringType::const_iterator;

			/// <summary>
			/// STL iterator compat.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto cend() const -> StringType::const_iterator;

			/// <summary>
			/// STL iterator compat.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto crbegin() const -> StringType::const_reverse_iterator;

			/// <summary>
			/// STL iterator compat.
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto crend() const -> StringType::const_reverse_iterator;
		};

		inline TextFile::TextFile(StringType&& content) : Content_ {std::move(content)} { }

		inline TextFile::TextFile(std::filesystem::path&& path, StringType&& content) : Content_ {std::move(content)},
		                                                                                FilePath_ {std::move(path)} { }

		inline auto TextFile::GetContentText() const & -> const StringType&
		{
			return this->Content_;
		}

		inline auto TextFile::GetContentText() & -> StringType&
		{
			return this->Content_;
		}

		inline auto TextFile::GetContentText() && -> StringType&&
		{
			return std::move(this->Content_);
		}

		inline auto TextFile::GetFilePath() const & -> const std::filesystem::path&
		{
			return this->FilePath_;
		}

		inline auto TextFile::GetFilePath() && -> std::filesystem::path&&
		{
			return std::move(this->FilePath_);
		}

		inline auto TextFile::IsEmpty() const -> bool
		{
			return this->Content_.empty();
		}

		inline auto TextFile::GetCapacity() const -> U64
		{
			return this->Content_.capacity();
		}

		inline auto TextFile::GetSize() const -> U64
		{
			return this->Content_.size();
		}

		inline auto TextFile::GetSizeInBytes() const -> U64
		{
			return this->Content_.capacity() * sizeof(CharType);
		}

		inline auto TextFile::begin() -> StringType::iterator
		{
			return std::begin(this->Content_);
		}

		inline auto TextFile::end() -> StringType::iterator
		{
			return std::end(this->Content_);
		}

		inline auto TextFile::rbegin() -> StringType::reverse_iterator
		{
			return std::rbegin(this->Content_);
		}

		inline auto TextFile::rend() -> StringType::reverse_iterator
		{
			return std::rend(this->Content_);
		}

		inline auto TextFile::cbegin() const -> StringType::const_iterator
		{
			return std::cbegin(this->Content_);
		}

		inline auto TextFile::cend() const -> StringType::const_iterator
		{
			return std::cend(this->Content_);
		}

		inline auto TextFile::crbegin() const -> StringType::const_reverse_iterator
		{
			return std::crbegin(this->Content_);
		}

		inline auto TextFile::crend() const -> StringType::const_reverse_iterator
		{
			return std::crend(this->Content_);
		}

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		inline auto begin(TextFile& file) -> TextFile::StringType::iterator
		{
			return file.begin();
		}

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		inline auto end(TextFile& file) -> TextFile::StringType::iterator
		{
			return file.end();
		}

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		inline auto rbegin(TextFile& file) -> TextFile::StringType::reverse_iterator
		{
			return file.rbegin();
		}

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		inline auto rend(TextFile& file) -> TextFile::StringType::reverse_iterator
		{
			return file.rend();
		}

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		inline auto cbegin(const TextFile& file) -> TextFile::StringType::const_iterator
		{
			return file.cbegin();
		}

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		inline auto cend(const TextFile& file) -> TextFile::StringType::const_iterator
		{
			return file.cend();
		}

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		inline auto crbegin(const TextFile& file) -> TextFile::StringType::const_reverse_iterator
		{
			return file.crbegin();
		}

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		inline auto crend(const TextFile& file) -> TextFile::StringType::const_reverse_iterator
		{
			return file.crend();
		}

		/// <summary>
		/// Generate 32-bit xorshift atomically.
		/// </summary>
		/// <returns>A random generated number.</returns>
		extern auto Xorshift32Atomic() -> U32;

		/// <summary>
		/// Generate 64-bit xorshift atomically.
		/// </summary>
		/// <returns>A random generated number.</returns>
		extern auto Xorshift64Atomic() -> U64;

		/// <summary>
		/// Generate 128-bit xorshift atomically.
		/// </summary>
		/// <returns>A random generated number.</returns>
		extern auto Xorshift128Atomic() -> U32;

		/// <summary>
		/// Generate 32-bit xorshift atomically.
		/// </summary>
		/// <returns>A random generated number.</returns>
		extern auto Xorshift32ThreadLocal() -> U32;

		/// <summary>
		/// Generate 64-bit xorshift atomically.
		/// </summary>
		/// <returns>A random generated number.</returns>
		extern auto Xorshift64ThreadLocal() -> U64;

		/// <summary>
		/// Generate 128-bit xorshift atomically.
		/// </summary>
		/// <returns>A random generated number.</returns>
		extern auto Xorshift128ThreadLocal() -> U32;

		/// <summary>
		/// 64-bit memory record.
		/// Contains either: Record32, void*, U64, I64, F64
		/// </summary>
		union alignas(alignof(I64)) Record
		{
			/// <summary>
			/// Use as U32.
			/// </summary>
			U32 AsU32;

			/// <summary>
			/// Use as I32.
			/// </summary>
			I32 AsI32;

			/// <summary>
			/// Use as F32.
			/// </summary>
			F32 AsF32;

			/// <summary>
			/// Use as U64.
			/// </summary>
			U64 AsU64;

			/// <summary>
			/// Use as I64.
			/// </summary>
			I64 AsI64;

			/// <summary>
			/// Use as F64.
			/// </summary>
			F64 AsF64;

			/// <summary>
			/// Use as PTR 64.
			/// </summary>
			void* AsPtr;

			/// <summary>
			/// Use as ASCII/UTF-8 char.
			/// </summary>
			char8_t AsChar8;

			/// <summary>
			/// Use as UTF-16 char.
			/// </summary>
			char16_t AsChar16;

			/// <summary>
			/// Use as UTF-32 char.
			/// </summary>
			char32_t AsChar32;

			/// <summary>
			/// Use as U32's array.
			/// </summary>
			std::array<U32, 2> AsU32S;

			/// <summary>
			/// Use as I32's array.
			/// </summary>
			std::array<I32, 2> AsI32S;

			/// <summary>
			/// Use as F32's array.
			/// </summary>
			std::array<F32, 2> AsF32S;

			/// <summary>
			/// Default construct.
			/// </summary>
			/// <returns></returns>
			Record() = default;

			/// <summary>
			/// Construct from U32 and zero upper 32 bits.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(U32 value);

			/// <summary>
			/// Construct from I32 and zero upper 32 bits.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(I32 value);

			/// <summary>
			/// Construct from F32 and zero upper 32 bits.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(F32 value);

			/// <summary>
			/// Construct from U64.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(U64 value);

			/// <summary>
			/// Construct from I64.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(I64 value);

			/// <summary>
			/// Construct from F64.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(F64 value);

			/// <summary>
			/// Construct from PTR 64.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(void* value);

			/// <summary>
			/// Construct from ASCII/UTF-8 char.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(char8_t value);

			/// <summary>
			/// Construct from UTF-16 char.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(char16_t value);

			/// <summary>
			/// Construct from UTF-32 char.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(char32_t value);

			/// <summary>
			/// Construct from U32 array.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(std::array<U32, 2> value);

			/// <summary>
			/// Construct from I32 array.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(std::array<I32, 2> value);

			/// <summary>
			/// Construct from F32 array.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			explicit constexpr Record(std::array<F32, 2> value);

			/// <summary>
			/// Returns true if value contains non zero, else false.
			/// </summary>
			/// <returns></returns>
			explicit constexpr operator bool() const;

			/// <summary>
			/// Equal.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator ==(Record other) const -> bool;

			/// <summary>
			/// Not equal.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator !=(Record other) const -> bool;

			/// <summary>
			/// Less.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator <(Record other) const -> bool;

			/// <summary>
			/// Above.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator >(Record other) const -> bool;

			/// <summary>
			/// Less equal.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator <=(Record other) const -> bool;

			/// <summary>
			/// Above equal.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			constexpr auto operator >=(Record other) const -> bool;

			/// <summary>
			/// Get stack padding value.
			/// </summary>
			/// <returns></returns>
			static constexpr auto Padding() -> Record;
		};

		constexpr Record::Record(const U32 value) : AsU32 {value} {}
		constexpr Record::Record(const I32 value) : AsI32 {value} {}
		constexpr Record::Record(const F32 value) : AsF32 {value} {}
		constexpr Record::Record(const U64 value) : AsU64 {value} {}
		constexpr Record::Record(const I64 value) : AsI64 {value} {}
		constexpr Record::Record(const F64 value) : AsF64 {value} {}
		constexpr Record::Record(void* const value) : AsPtr {value} {}
		constexpr Record::Record(const char8_t value) : AsChar8 {value} {}
		constexpr Record::Record(const char16_t value) : AsChar16 {value} {}
		constexpr Record::Record(const char32_t value) : AsChar32 {value} {}
		constexpr Record::Record(const std::array<U32, 2> value) : AsU32S {value} {}
		constexpr Record::Record(const std::array<I32, 2> value) : AsI32S {value} {}
		constexpr Record::Record(const std::array<F32, 2> value) : AsF32S {value} {}

		constexpr Record::operator bool() const
		{
			return this->AsU64;
		}

		constexpr auto Record::operator ==(const Record other) const -> bool
		{
			return this->AsU64 == other.AsU64;
		}

		constexpr auto Record::operator !=(const Record other) const -> bool
		{
			return !(*this == other);
		}

		constexpr auto Record::operator <(const Record other) const -> bool
		{
			return this->AsU64 < other.AsU64;
		}

		constexpr auto Record::operator >(const Record other) const -> bool
		{
			return this->AsU64 > other.AsU64;
		}

		constexpr auto Record::operator <=(const Record other) const -> bool
		{
			return this->AsU64 <= other.AsU64;
		}

		constexpr auto Record::operator >=(const Record other) const -> bool
		{
			return this->AsU64 >= other.AsU64;
		}

		constexpr auto Record::Padding() -> Record
		{
			return Record {0xFF'FF'FF'FF'FF'FF'FF'FF};
		}

		static_assert(sizeof(F32) == sizeof(I32));
		static_assert(sizeof(F64) == sizeof(I64));
		static_assert(sizeof(Record) == sizeof(I64));
		static_assert(alignof(Record) == alignof(I64));
		static_assert(std::is_standard_layout_v<Record>);
		static_assert(std::is_trivial_v<Record>);
		static_assert(std::is_default_constructible_v<Record>);
	}

	#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT
	#	include <immintrin.h>
	#elif NOX_ARCH_ARM_64 && NOX_USE_ARCH_OPT && defined(__ARM_NEON)
#	include <arm_neon.h>
	#endif

	namespace VectorLib
	{
		constexpr U64 V128_ALIGN
		{
			#ifdef __SSE__
		16
			#else
			alignof(F32)
			#endif
		};

		constexpr U64 V256_ALIGN
		{
			#if defined(__AVX__)
		32
			#elif defined(__SSE__)
		16
			#else
			alignof(F32)
			#endif
		};

		constexpr U64 V512_ALIGN
		{
			#if defined(__AVX512F__)
		64
			#elif defined(__AVX__)
		32
			#elif defined(__SSE__)
		16
			#else
			alignof(F32)
			#endif
		};

		NOX_FORCE_INLINE inline auto F64_X2_To_F32_X2(F32* const NOX_RESTRICT out, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)
		const __m128d x = _mm_loadu_pd(in);
		const __m128 y = _mm_cvtpd_ps(x);
		_mm_storel_pi(reinterpret_cast<__m64*>(out), y);
			#else
			out[0] = static_cast<F32>(in[0]);
			out[1] = static_cast<F32>(in[1]);
			#endif
		}

		NOX_FORCE_INLINE inline auto F64_X4_To_F32_X4(F32* const NOX_RESTRICT out, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		const __m256d x = _mm256_loadu_pd(in);		// 32 B - 4 * F64
		const __m128 y = _mm256_cvtpd_ps(x);		// 16 B - 4 * F32
		_mm_storeu_ps(out, y);


			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

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

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X16_Add_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512 x = _mm512_load_ps(inout);
		const __m512 y = _mm512_load_ps(in);
		x = _mm512_add_ps(x, y);
		_mm512_store_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x1 = _mm256_load_ps(inout);
		__m256 x2 = _mm256_load_ps(inout + 8);
		const __m256 y1 = _mm256_load_ps(in);
		const __m256 y2 = _mm256_load_ps(in + 8);
		x1 = _mm256_add_ps(x1, y1);
		x2 = _mm256_add_ps(x2, y2);
		_mm256_store_ps(inout, x1);
		_mm256_store_ps(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_load_ps(inout);
		__m128 x2 = _mm_load_ps(inout + 4);
		__m128 x3 = _mm_load_ps(inout + 8);
		__m128 x4 = _mm_load_ps(inout + 12);
		const __m128 y1 = _mm_load_ps(in);
		const __m128 y2 = _mm_load_ps(in + 4);
		const __m128 y3 = _mm_load_ps(in + 8);
		const __m128 y4 = _mm_load_ps(in + 12);
		x1 = _mm_add_ps(x1, y1);
		x2 = _mm_add_ps(x2, y2);
		x3 = _mm_add_ps(x3, y3);
		x4 = _mm_add_ps(x4, y4);
		_mm_store_ps(inout, x1);
		_mm_store_ps(inout + 4, x2);
		_mm_store_ps(inout + 8, x3);
		_mm_store_ps(inout + 12, x4);
			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];
			inout[4] += in[4];
			inout[5] += in[5];
			inout[6] += in[6];
			inout[7] += in[7];
			inout[8] += in[8];
			inout[9] += in[9];
			inout[10] += in[10];
			inout[11] += in[11];
			inout[12] += in[12];
			inout[13] += in[13];
			inout[14] += in[14];
			inout[15] += in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X16_Sub_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512 x = _mm512_load_ps(inout);
		const __m512 y = _mm512_load_ps(in);
		x = _mm512_sub_ps(x, y);
		_mm512_store_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x1 = _mm256_load_ps(inout);
		__m256 x2 = _mm256_load_ps(inout + 8);
		const __m256 y1 = _mm256_load_ps(in);
		const __m256 y2 = _mm256_load_ps(in + 8);
		x1 = _mm256_sub_ps(x1, y1);
		x2 = _mm256_sub_ps(x2, y2);
		_mm256_store_ps(inout, x1);
		_mm256_store_ps(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_load_ps(inout);
		__m128 x2 = _mm_load_ps(inout + 4);
		__m128 x3 = _mm_load_ps(inout + 8);
		__m128 x4 = _mm_load_ps(inout + 12);
		const __m128 y1 = _mm_load_ps(in);
		const __m128 y2 = _mm_load_ps(in + 4);
		const __m128 y3 = _mm_load_ps(in + 8);
		const __m128 y4 = _mm_load_ps(in + 12);
		x1 = _mm_sub_ps(x1, y1);
		x2 = _mm_sub_ps(x2, y2);
		x3 = _mm_sub_ps(x3, y3);
		x4 = _mm_sub_ps(x4, y4);
		_mm_store_ps(inout, x1);
		_mm_store_ps(inout + 4, x2);
		_mm_store_ps(inout + 8, x3);
		_mm_store_ps(inout + 12, x4);
			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];
			inout[4] -= in[4];
			inout[5] -= in[5];
			inout[6] -= in[6];
			inout[7] -= in[7];
			inout[8] -= in[8];
			inout[9] -= in[9];
			inout[10] -= in[10];
			inout[11] -= in[11];
			inout[12] -= in[12];
			inout[13] -= in[13];
			inout[14] -= in[14];
			inout[15] -= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X16_Mul_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512 x = _mm512_load_ps(inout);
		const __m512 y = _mm512_load_ps(in);
		x = _mm512_mul_ps(x, y);
		_mm512_store_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x1 = _mm256_load_ps(inout);
		__m256 x2 = _mm256_load_ps(inout + 8);
		const __m256 y1 = _mm256_load_ps(in);
		const __m256 y2 = _mm256_load_ps(in + 8);
		x1 = _mm256_mul_ps(x1, y1);
		x2 = _mm256_mul_ps(x2, y2);
		_mm256_store_ps(inout, x1);
		_mm256_store_ps(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_load_ps(inout);
		__m128 x2 = _mm_load_ps(inout + 4);
		__m128 x3 = _mm_load_ps(inout + 8);
		__m128 x4 = _mm_load_ps(inout + 12);
		const __m128 y1 = _mm_load_ps(in);
		const __m128 y2 = _mm_load_ps(in + 4);
		const __m128 y3 = _mm_load_ps(in + 8);
		const __m128 y4 = _mm_load_ps(in + 12);
		x1 = _mm_mul_ps(x1, y1);
		x2 = _mm_mul_ps(x2, y2);
		x3 = _mm_mul_ps(x3, y3);
		x4 = _mm_mul_ps(x4, y4);
		_mm_store_ps(inout, x1);
		_mm_store_ps(inout + 4, x2);
		_mm_store_ps(inout + 8, x3);
		_mm_store_ps(inout + 12, x4);
			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];
			inout[4] *= in[4];
			inout[5] *= in[5];
			inout[6] *= in[6];
			inout[7] *= in[7];
			inout[8] *= in[8];
			inout[9] *= in[9];
			inout[10] *= in[10];
			inout[11] *= in[11];
			inout[12] *= in[12];
			inout[13] *= in[13];
			inout[14] *= in[14];
			inout[15] *= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X16_Div_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512 x = _mm512_load_ps(inout);
		const __m512 y = _mm512_load_ps(in);
		x = _mm512_div_ps(x, y);
		_mm512_store_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x1 = _mm256_load_ps(inout);
		__m256 x2 = _mm256_load_ps(inout + 8);
		const __m256 y1 = _mm256_load_ps(in);
		const __m256 y2 = _mm256_load_ps(in + 8);
		x1 = _mm256_div_ps(x1, y1);
		x2 = _mm256_div_ps(x2, y2);
		_mm256_store_ps(inout, x1);
		_mm256_store_ps(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_load_ps(inout);
		__m128 x2 = _mm_load_ps(inout + 4);
		__m128 x3 = _mm_load_ps(inout + 8);
		__m128 x4 = _mm_load_ps(inout + 12);
		const __m128 y1 = _mm_load_ps(in);
		const __m128 y2 = _mm_load_ps(in + 4);
		const __m128 y3 = _mm_load_ps(in + 8);
		const __m128 y4 = _mm_load_ps(in + 12);
		x1 = _mm_div_ps(x1, y1);
		x2 = _mm_div_ps(x2, y2);
		x3 = _mm_div_ps(x3, y3);
		x4 = _mm_div_ps(x4, y4);
		_mm_store_ps(inout, x1);
		_mm_store_ps(inout + 4, x2);
		_mm_store_ps(inout + 8, x3);
		_mm_store_ps(inout + 12, x4);
			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];
			inout[4] /= in[4];
			inout[5] /= in[5];
			inout[6] /= in[6];
			inout[7] /= in[7];
			inout[8] /= in[8];
			inout[9] /= in[9];
			inout[10] /= in[10];
			inout[11] /= in[11];
			inout[12] /= in[12];
			inout[13] /= in[13];
			inout[14] /= in[14];
			inout[15] /= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X16_Add_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512 x = _mm512_loadu_ps(inout);
		const __m512 y = _mm512_loadu_ps(in);
		x = _mm512_add_ps(x, y);
		_mm512_storeu_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x1 = _mm256_loadu_ps(inout);
		__m256 x2 = _mm256_loadu_ps(inout + 8);
		const __m256 y1 = _mm256_loadu_ps(in);
		const __m256 y2 = _mm256_loadu_ps(in + 8);
		x1 = _mm256_add_ps(x1, y1);
		x2 = _mm256_add_ps(x2, y2);
		_mm256_storeu_ps(inout, x1);
		_mm256_storeu_ps(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_loadu_ps(inout);
		__m128 x2 = _mm_loadu_ps(inout + 4);
		__m128 x3 = _mm_loadu_ps(inout + 8);
		__m128 x4 = _mm_loadu_ps(inout + 12);
		const __m128 y1 = _mm_loadu_ps(in);
		const __m128 y2 = _mm_loadu_ps(in + 4);
		const __m128 y3 = _mm_loadu_ps(in + 8);
		const __m128 y4 = _mm_loadu_ps(in + 12);
		x1 = _mm_add_ps(x1, y1);
		x2 = _mm_add_ps(x2, y2);
		x3 = _mm_add_ps(x3, y3);
		x4 = _mm_add_ps(x4, y4);
		_mm_storeu_ps(inout, x1);
		_mm_storeu_ps(inout + 4, x2);
		_mm_storeu_ps(inout + 8, x3);
		_mm_storeu_ps(inout + 12, x4);
			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];
			inout[4] += in[4];
			inout[5] += in[5];
			inout[6] += in[6];
			inout[7] += in[7];
			inout[8] += in[8];
			inout[9] += in[9];
			inout[10] += in[10];
			inout[11] += in[11];
			inout[12] += in[12];
			inout[13] += in[13];
			inout[14] += in[14];
			inout[15] += in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X16_Sub_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512 x = _mm512_loadu_ps(inout);
		const __m512 y = _mm512_loadu_ps(in);
		x = _mm512_sub_ps(x, y);
		_mm512_storeu_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x1 = _mm256_loadu_ps(inout);
		__m256 x2 = _mm256_loadu_ps(inout + 8);
		const __m256 y1 = _mm256_loadu_ps(in);
		const __m256 y2 = _mm256_loadu_ps(in + 8);
		x1 = _mm256_sub_ps(x1, y1);
		x2 = _mm256_sub_ps(x2, y2);
		_mm256_storeu_ps(inout, x1);
		_mm256_storeu_ps(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_loadu_ps(inout);
		__m128 x2 = _mm_loadu_ps(inout + 4);
		__m128 x3 = _mm_loadu_ps(inout + 8);
		__m128 x4 = _mm_loadu_ps(inout + 12);
		const __m128 y1 = _mm_loadu_ps(in);
		const __m128 y2 = _mm_loadu_ps(in + 4);
		const __m128 y3 = _mm_loadu_ps(in + 8);
		const __m128 y4 = _mm_loadu_ps(in + 12);
		x1 = _mm_sub_ps(x1, y1);
		x2 = _mm_sub_ps(x2, y2);
		x3 = _mm_sub_ps(x3, y3);
		x4 = _mm_sub_ps(x4, y4);
		_mm_storeu_ps(inout, x1);
		_mm_storeu_ps(inout + 4, x2);
		_mm_storeu_ps(inout + 8, x3);
		_mm_storeu_ps(inout + 12, x4);
			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];
			inout[4] -= in[4];
			inout[5] -= in[5];
			inout[6] -= in[6];
			inout[7] -= in[7];
			inout[8] -= in[8];
			inout[9] -= in[9];
			inout[10] -= in[10];
			inout[11] -= in[11];
			inout[12] -= in[12];
			inout[13] -= in[13];
			inout[14] -= in[14];
			inout[15] -= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X16_Mul_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512 x = _mm512_loadu_ps(inout);
		const __m512 y = _mm512_loadu_ps(in);
		x = _mm512_mul_ps(x, y);
		_mm512_storeu_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x1 = _mm256_loadu_ps(inout);
		__m256 x2 = _mm256_loadu_ps(inout + 8);
		const __m256 y1 = _mm256_loadu_ps(in);
		const __m256 y2 = _mm256_loadu_ps(in + 8);
		x1 = _mm256_mul_ps(x1, y1);
		x2 = _mm256_mul_ps(x2, y2);
		_mm256_storeu_ps(inout, x1);
		_mm256_storeu_ps(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_loadu_ps(inout);
		__m128 x2 = _mm_loadu_ps(inout + 4);
		__m128 x3 = _mm_loadu_ps(inout + 8);
		__m128 x4 = _mm_loadu_ps(inout + 12);
		const __m128 y1 = _mm_loadu_ps(in);
		const __m128 y2 = _mm_loadu_ps(in + 4);
		const __m128 y3 = _mm_loadu_ps(in + 8);
		const __m128 y4 = _mm_loadu_ps(in + 12);
		x1 = _mm_mul_ps(x1, y1);
		x2 = _mm_mul_ps(x2, y2);
		x3 = _mm_mul_ps(x3, y3);
		x4 = _mm_mul_ps(x4, y4);
		_mm_storeu_ps(inout, x1);
		_mm_storeu_ps(inout + 4, x2);
		_mm_storeu_ps(inout + 8, x3);
		_mm_storeu_ps(inout + 12, x4);
			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];
			inout[4] *= in[4];
			inout[5] *= in[5];
			inout[6] *= in[6];
			inout[7] *= in[7];
			inout[8] *= in[8];
			inout[9] *= in[9];
			inout[10] *= in[10];
			inout[11] *= in[11];
			inout[12] *= in[12];
			inout[13] *= in[13];
			inout[14] *= in[14];
			inout[15] *= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X16_Div_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512 x = _mm512_loadu_ps(inout);
		const __m512 y = _mm512_loadu_ps(in);
		x = _mm512_div_ps(x, y);
		_mm512_storeu_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x1 = _mm256_loadu_ps(inout);
		__m256 x2 = _mm256_loadu_ps(inout + 8);
		const __m256 y1 = _mm256_loadu_ps(in);
		const __m256 y2 = _mm256_loadu_ps(in + 8);
		x1 = _mm256_div_ps(x1, y1);
		x2 = _mm256_div_ps(x2, y2);
		_mm256_storeu_ps(inout, x1);
		_mm256_storeu_ps(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_loadu_ps(inout);
		__m128 x2 = _mm_loadu_ps(inout + 4);
		__m128 x3 = _mm_loadu_ps(inout + 8);
		__m128 x4 = _mm_loadu_ps(inout + 12);
		const __m128 y1 = _mm_loadu_ps(in);
		const __m128 y2 = _mm_loadu_ps(in + 4);
		const __m128 y3 = _mm_loadu_ps(in + 8);
		const __m128 y4 = _mm_loadu_ps(in + 12);
		x1 = _mm_div_ps(x1, y1);
		x2 = _mm_div_ps(x2, y2);
		x3 = _mm_div_ps(x3, y3);
		x4 = _mm_div_ps(x4, y4);
		_mm_storeu_ps(inout, x1);
		_mm_storeu_ps(inout + 4, x2);
		_mm_storeu_ps(inout + 8, x3);
		_mm_storeu_ps(inout + 12, x4);
			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];
			inout[4] /= in[4];
			inout[5] /= in[5];
			inout[6] /= in[6];
			inout[7] /= in[7];
			inout[8] /= in[8];
			inout[9] /= in[9];
			inout[10] /= in[10];
			inout[11] /= in[11];
			inout[12] /= in[12];
			inout[13] /= in[13];
			inout[14] /= in[14];
			inout[15] /= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X4_Add_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x = _mm_load_ps(inout);
		const __m128 y = _mm_load_ps(in);
		x = _mm_add_ps(x, y);
		_mm_store_ps(inout, x);

			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X4_Sub_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x = _mm_load_ps(inout);
		const __m128 y = _mm_load_ps(in);
		x = _mm_sub_ps(x, y);
		_mm_store_ps(inout, x);

			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X4_Mul_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x = _mm_load_ps(inout);
		const __m128 y = _mm_load_ps(in);
		x = _mm_mul_ps(x, y);
		_mm_store_ps(inout, x);

			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X4_Div_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x = _mm_load_ps(inout);
		const __m128 y = _mm_load_ps(in);
		x = _mm_div_ps(x, y);
		_mm_store_ps(inout, x);

			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X4_Add_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x = _mm_loadu_ps(inout);
		const __m128 y = _mm_loadu_ps(in);
		x = _mm_add_ps(x, y);
		_mm_storeu_ps(inout, x);

			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X4_Sub_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x = _mm_loadu_ps(inout);
		const __m128 y = _mm_loadu_ps(in);
		x = _mm_sub_ps(x, y);
		_mm_storeu_ps(inout, x);

			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X4_Mul_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x = _mm_loadu_ps(inout);
		const __m128 y = _mm_loadu_ps(in);
		x = _mm_mul_ps(x, y);
		_mm_storeu_ps(inout, x);

			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X4_Div_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x = _mm_loadu_ps(inout);
		const __m128 y = _mm_loadu_ps(in);
		x = _mm_div_ps(x, y);
		_mm_storeu_ps(inout, x);

			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X8_Add_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x = _mm256_load_ps(inout);
		const __m256 y = _mm256_load_ps(in);
		x = _mm256_add_ps(x, y);
		_mm256_store_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_load_ps(inout);
		__m128 x2 = _mm_load_ps(inout + 4);
		const __m128 y1 = _mm_load_ps(in);
		const __m128 y2 = _mm_load_ps(in + 4);
		x1 = _mm_add_ps(x1, y1);
		x2 = _mm_add_ps(x2, y2);
		_mm_store_ps(inout, x1);
		_mm_store_ps(inout + 4, x2);

			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];
			inout[4] += in[4];
			inout[5] += in[5];
			inout[6] += in[6];
			inout[7] += in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X8_Sub_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x = _mm256_load_ps(inout);
		const __m256 y = _mm256_load_ps(in);
		x = _mm256_sub_ps(x, y);
		_mm256_store_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_load_ps(inout);
		__m128 x2 = _mm_load_ps(inout + 4);
		const __m128 y1 = _mm_load_ps(in);
		const __m128 y2 = _mm_load_ps(in + 4);
		x1 = _mm_sub_ps(x1, y1);
		x2 = _mm_sub_ps(x2, y2);
		_mm_store_ps(inout, x1);
		_mm_store_ps(inout + 4, x2);

			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];
			inout[4] -= in[4];
			inout[5] -= in[5];
			inout[6] -= in[6];
			inout[7] -= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X8_Mul_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x = _mm256_load_ps(inout);
		const __m256 y = _mm256_load_ps(in);
		x = _mm256_mul_ps(x, y);
		_mm256_store_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_load_ps(inout);
		__m128 x2 = _mm_load_ps(inout + 4);
		const __m128 y1 = _mm_load_ps(in);
		const __m128 y2 = _mm_load_ps(in + 4);
		x1 = _mm_mul_ps(x1, y1);
		x2 = _mm_mul_ps(x2, y2);
		_mm_store_ps(inout, x1);
		_mm_store_ps(inout + 4, x2);

			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];
			inout[4] *= in[4];
			inout[5] *= in[5];
			inout[6] *= in[6];
			inout[7] *= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X8_Div_Aligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x = _mm256_load_ps(inout);
		const __m256 y = _mm256_load_ps(in);
		x = _mm256_div_ps(x, y);
		_mm256_store_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_load_ps(inout);
		__m128 x2 = _mm_load_ps(inout + 4);
		const __m128 y1 = _mm_load_ps(in);
		const __m128 y2 = _mm_load_ps(in + 4);
		x1 = _mm_div_ps(x1, y1);
		x2 = _mm_div_ps(x2, y2);
		_mm_store_ps(inout, x1);
		_mm_store_ps(inout + 4, x2);

			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];
			inout[4] /= in[4];
			inout[5] /= in[5];
			inout[6] /= in[6];
			inout[7] /= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X8_Add_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x = _mm256_loadu_ps(inout);
		const __m256 y = _mm256_loadu_ps(in);
		x = _mm256_add_ps(x, y);
		_mm256_storeu_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_loadu_ps(inout);
		__m128 x2 = _mm_loadu_ps(inout + 4);
		const __m128 y1 = _mm_loadu_ps(in);
		const __m128 y2 = _mm_loadu_ps(in + 4);
		x1 = _mm_add_ps(x1, y1);
		x2 = _mm_add_ps(x2, y2);
		_mm_storeu_ps(inout, x1);
		_mm_storeu_ps(inout + 4, x2);

			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];
			inout[4] += in[4];
			inout[5] += in[5];
			inout[6] += in[6];
			inout[7] += in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X8_Sub_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x = _mm256_loadu_ps(inout);
		const __m256 y = _mm256_loadu_ps(in);
		x = _mm256_sub_ps(x, y);
		_mm256_storeu_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_loadu_ps(inout);
		__m128 x2 = _mm_loadu_ps(inout + 4);
		const __m128 y1 = _mm_loadu_ps(in);
		const __m128 y2 = _mm_loadu_ps(in + 4);
		x1 = _mm_sub_ps(x1, y1);
		x2 = _mm_sub_ps(x2, y2);
		_mm_storeu_ps(inout, x1);
		_mm_storeu_ps(inout + 4, x2);

			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];
			inout[4] -= in[4];
			inout[5] -= in[5];
			inout[6] -= in[6];
			inout[7] -= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X8_Mul_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x = _mm256_loadu_ps(inout);
		const __m256 y = _mm256_loadu_ps(in);
		x = _mm256_mul_ps(x, y);
		_mm256_storeu_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_loadu_ps(inout);
		__m128 x2 = _mm_loadu_ps(inout + 4);
		const __m128 y1 = _mm_loadu_ps(in);
		const __m128 y2 = _mm_loadu_ps(in + 4);
		x1 = _mm_mul_ps(x1, y1);
		x2 = _mm_mul_ps(x2, y2);
		_mm_storeu_ps(inout, x1);
		_mm_storeu_ps(inout + 4, x2);

			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];
			inout[4] *= in[4];
			inout[5] *= in[5];
			inout[6] *= in[6];
			inout[7] *= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F32_X8_Div_Unaligned(F32* const NOX_RESTRICT inout, const F32* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256 x = _mm256_loadu_ps(inout);
		const __m256 y = _mm256_loadu_ps(in);
		x = _mm256_div_ps(x, y);
		_mm256_storeu_ps(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE__)

		__m128 x1 = _mm_loadu_ps(inout);
		__m128 x2 = _mm_loadu_ps(inout + 4);
		const __m128 y1 = _mm_loadu_ps(in);
		const __m128 y2 = _mm_loadu_ps(in + 4);
		x1 = _mm_div_ps(x1, y1);
		x2 = _mm_div_ps(x2, y2);
		_mm_storeu_ps(inout, x1);
		_mm_storeu_ps(inout + 4, x2);

			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];
			inout[4] /= in[4];
			inout[5] /= in[5];
			inout[6] /= in[6];
			inout[7] /= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X16_Add_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x1 = _mm512_load_pd(inout);
		__m512d x2 = _mm512_load_pd(inout + 8);
		const __m512d y1 = _mm512_load_pd(in);
		const __m512d y2 = _mm512_load_pd(in + 8);
		x1 = _mm512_add_pd(x1, y1);
		x2 = _mm512_add_pd(x2, y2);
		_mm512_store_pd(inout, x1);
		_mm512_store_pd(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_load_pd(inout);
		__m256d x2 = _mm256_load_pd(inout + 4);
		__m256d x3 = _mm256_load_pd(inout + 8);
		__m256d x4 = _mm256_load_pd(inout + 12);
		const __m256d y1 = _mm256_load_pd(in);
		const __m256d y2 = _mm256_load_pd(in + 4);
		const __m256d y3 = _mm256_load_pd(in + 8);
		const __m256d y4 = _mm256_load_pd(in + 12);
		x1 = _mm256_add_pd(x1, y1);
		x2 = _mm256_add_pd(x2, y2);
		x3 = _mm256_add_pd(x3, y3);
		x4 = _mm256_add_pd(x4, y4);
		_mm256_store_pd(inout, x1);
		_mm256_store_pd(inout + 4, x2);
		_mm256_store_pd(inout + 8, x3);
		_mm256_store_pd(inout + 12, x4);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		__m128d x3 = _mm_load_pd(inout + 4);
		__m128d x4 = _mm_load_pd(inout + 6);
		__m128d x5 = _mm_load_pd(inout + 8);
		__m128d x6 = _mm_load_pd(inout + 10);
		__m128d x7 = _mm_load_pd(inout + 12);
		__m128d x8 = _mm_load_pd(inout + 14);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		const __m128d y3 = _mm_load_pd(in + 4);
		const __m128d y4 = _mm_load_pd(in + 6);
		const __m128d y5 = _mm_load_pd(in + 8);
		const __m128d y6 = _mm_load_pd(in + 10);
		const __m128d y7 = _mm_load_pd(in + 12);
		const __m128d y8 = _mm_load_pd(in + 14);
		x1 = _mm_add_pd(x1, y1);
		x2 = _mm_add_pd(x2, y2);
		x3 = _mm_add_pd(x3, y3);
		x4 = _mm_add_pd(x4, y4);
		x5 = _mm_add_pd(x5, y5);
		x6 = _mm_add_pd(x6, y6);
		x7 = _mm_add_pd(x7, y7);
		x8 = _mm_add_pd(x8, y8);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		_mm_store_pd(inout + 4, x3);
		_mm_store_pd(inout + 6, x4);
		_mm_store_pd(inout + 8, x5);
		_mm_store_pd(inout + 10, x6);
		_mm_store_pd(inout + 12, x7);
		_mm_store_pd(inout + 14, x8);
			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];
			inout[4] += in[4];
			inout[5] += in[5];
			inout[6] += in[6];
			inout[7] += in[7];
			inout[8] += in[8];
			inout[9] += in[9];
			inout[10] += in[10];
			inout[11] += in[11];
			inout[12] += in[12];
			inout[13] += in[13];
			inout[14] += in[14];
			inout[15] += in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X16_Sub_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x1 = _mm512_load_pd(inout);
		__m512d x2 = _mm512_load_pd(inout + 8);
		const __m512d y1 = _mm512_load_pd(in);
		const __m512d y2 = _mm512_load_pd(in + 8);
		x1 = _mm512_sub_pd(x1, y1);
		x2 = _mm512_sub_pd(x2, y2);
		_mm512_store_pd(inout, x1);
		_mm512_store_pd(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_load_pd(inout);
		__m256d x2 = _mm256_load_pd(inout + 4);
		__m256d x3 = _mm256_load_pd(inout + 8);
		__m256d x4 = _mm256_load_pd(inout + 12);
		const __m256d y1 = _mm256_load_pd(in);
		const __m256d y2 = _mm256_load_pd(in + 4);
		const __m256d y3 = _mm256_load_pd(in + 8);
		const __m256d y4 = _mm256_load_pd(in + 12);
		x1 = _mm256_sub_pd(x1, y1);
		x2 = _mm256_sub_pd(x2, y2);
		x3 = _mm256_sub_pd(x3, y3);
		x4 = _mm256_sub_pd(x4, y4);
		_mm256_store_pd(inout, x1);
		_mm256_store_pd(inout + 4, x2);
		_mm256_store_pd(inout + 8, x3);
		_mm256_store_pd(inout + 12, x4);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		__m128d x3 = _mm_load_pd(inout + 4);
		__m128d x4 = _mm_load_pd(inout + 6);
		__m128d x5 = _mm_load_pd(inout + 8);
		__m128d x6 = _mm_load_pd(inout + 10);
		__m128d x7 = _mm_load_pd(inout + 12);
		__m128d x8 = _mm_load_pd(inout + 14);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		const __m128d y3 = _mm_load_pd(in + 4);
		const __m128d y4 = _mm_load_pd(in + 6);
		const __m128d y5 = _mm_load_pd(in + 8);
		const __m128d y6 = _mm_load_pd(in + 10);
		const __m128d y7 = _mm_load_pd(in + 12);
		const __m128d y8 = _mm_load_pd(in + 14);
		x1 = _mm_sub_pd(x1, y1);
		x2 = _mm_sub_pd(x2, y2);
		x3 = _mm_sub_pd(x3, y3);
		x4 = _mm_sub_pd(x4, y4);
		x5 = _mm_sub_pd(x5, y5);
		x6 = _mm_sub_pd(x6, y6);
		x7 = _mm_sub_pd(x7, y7);
		x8 = _mm_sub_pd(x8, y8);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		_mm_store_pd(inout + 4, x3);
		_mm_store_pd(inout + 6, x4);
		_mm_store_pd(inout + 8, x5);
		_mm_store_pd(inout + 10, x6);
		_mm_store_pd(inout + 12, x7);
		_mm_store_pd(inout + 14, x8);
			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];
			inout[4] -= in[4];
			inout[5] -= in[5];
			inout[6] -= in[6];
			inout[7] -= in[7];
			inout[8] -= in[8];
			inout[9] -= in[9];
			inout[10] -= in[10];
			inout[11] -= in[11];
			inout[12] -= in[12];
			inout[13] -= in[13];
			inout[14] -= in[14];
			inout[15] -= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X16_Mul_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x1 = _mm512_load_pd(inout);
		__m512d x2 = _mm512_load_pd(inout + 8);
		const __m512d y1 = _mm512_load_pd(in);
		const __m512d y2 = _mm512_load_pd(in + 8);
		x1 = _mm512_mul_pd(x1, y1);
		x2 = _mm512_mul_pd(x2, y2);
		_mm512_store_pd(inout, x1);
		_mm512_store_pd(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_load_pd(inout);
		__m256d x2 = _mm256_load_pd(inout + 4);
		__m256d x3 = _mm256_load_pd(inout + 8);
		__m256d x4 = _mm256_load_pd(inout + 12);
		const __m256d y1 = _mm256_load_pd(in);
		const __m256d y2 = _mm256_load_pd(in + 4);
		const __m256d y3 = _mm256_load_pd(in + 8);
		const __m256d y4 = _mm256_load_pd(in + 12);
		x1 = _mm256_mul_pd(x1, y1);
		x2 = _mm256_mul_pd(x2, y2);
		x3 = _mm256_mul_pd(x3, y3);
		x4 = _mm256_mul_pd(x4, y4);
		_mm256_store_pd(inout, x1);
		_mm256_store_pd(inout + 4, x2);
		_mm256_store_pd(inout + 8, x3);
		_mm256_store_pd(inout + 12, x4);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		__m128d x3 = _mm_load_pd(inout + 4);
		__m128d x4 = _mm_load_pd(inout + 6);
		__m128d x5 = _mm_load_pd(inout + 8);
		__m128d x6 = _mm_load_pd(inout + 10);
		__m128d x7 = _mm_load_pd(inout + 12);
		__m128d x8 = _mm_load_pd(inout + 14);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		const __m128d y3 = _mm_load_pd(in + 4);
		const __m128d y4 = _mm_load_pd(in + 6);
		const __m128d y5 = _mm_load_pd(in + 8);
		const __m128d y6 = _mm_load_pd(in + 10);
		const __m128d y7 = _mm_load_pd(in + 12);
		const __m128d y8 = _mm_load_pd(in + 14);
		x1 = _mm_mul_pd(x1, y1);
		x2 = _mm_mul_pd(x2, y2);
		x3 = _mm_mul_pd(x3, y3);
		x4 = _mm_mul_pd(x4, y4);
		x5 = _mm_mul_pd(x5, y5);
		x6 = _mm_mul_pd(x6, y6);
		x7 = _mm_mul_pd(x7, y7);
		x8 = _mm_mul_pd(x8, y8);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		_mm_store_pd(inout + 4, x3);
		_mm_store_pd(inout + 6, x4);
		_mm_store_pd(inout + 8, x5);
		_mm_store_pd(inout + 10, x6);
		_mm_store_pd(inout + 12, x7);
		_mm_store_pd(inout + 14, x8);
			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];
			inout[4] *= in[4];
			inout[5] *= in[5];
			inout[6] *= in[6];
			inout[7] *= in[7];
			inout[8] *= in[8];
			inout[9] *= in[9];
			inout[10] *= in[10];
			inout[11] *= in[11];
			inout[12] *= in[12];
			inout[13] *= in[13];
			inout[14] *= in[14];
			inout[15] *= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X16_Div_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x1 = _mm512_load_pd(inout);
		__m512d x2 = _mm512_load_pd(inout + 8);
		const __m512d y1 = _mm512_load_pd(in);
		const __m512d y2 = _mm512_load_pd(in + 8);
		x1 = _mm512_div_pd(x1, y1);
		x2 = _mm512_div_pd(x2, y2);
		_mm512_store_pd(inout, x1);
		_mm512_store_pd(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_load_pd(inout);
		__m256d x2 = _mm256_load_pd(inout + 4);
		__m256d x3 = _mm256_load_pd(inout + 8);
		__m256d x4 = _mm256_load_pd(inout + 12);
		const __m256d y1 = _mm256_load_pd(in);
		const __m256d y2 = _mm256_load_pd(in + 4);
		const __m256d y3 = _mm256_load_pd(in + 8);
		const __m256d y4 = _mm256_load_pd(in + 12);
		x1 = _mm256_div_pd(x1, y1);
		x2 = _mm256_div_pd(x2, y2);
		x3 = _mm256_div_pd(x3, y3);
		x4 = _mm256_div_pd(x4, y4);
		_mm256_store_pd(inout, x1);
		_mm256_store_pd(inout + 4, x2);
		_mm256_store_pd(inout + 8, x3);
		_mm256_store_pd(inout + 12, x4);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		__m128d x3 = _mm_load_pd(inout + 4);
		__m128d x4 = _mm_load_pd(inout + 6);
		__m128d x5 = _mm_load_pd(inout + 8);
		__m128d x6 = _mm_load_pd(inout + 10);
		__m128d x7 = _mm_load_pd(inout + 12);
		__m128d x8 = _mm_load_pd(inout + 14);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		const __m128d y3 = _mm_load_pd(in + 4);
		const __m128d y4 = _mm_load_pd(in + 6);
		const __m128d y5 = _mm_load_pd(in + 8);
		const __m128d y6 = _mm_load_pd(in + 10);
		const __m128d y7 = _mm_load_pd(in + 12);
		const __m128d y8 = _mm_load_pd(in + 14);
		x1 = _mm_div_pd(x1, y1);
		x2 = _mm_div_pd(x2, y2);
		x3 = _mm_div_pd(x3, y3);
		x4 = _mm_div_pd(x4, y4);
		x5 = _mm_div_pd(x5, y5);
		x6 = _mm_div_pd(x6, y6);
		x7 = _mm_div_pd(x7, y7);
		x8 = _mm_div_pd(x8, y8);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		_mm_store_pd(inout + 4, x3);
		_mm_store_pd(inout + 6, x4);
		_mm_store_pd(inout + 8, x5);
		_mm_store_pd(inout + 10, x6);
		_mm_store_pd(inout + 12, x7);
		_mm_store_pd(inout + 14, x8);
			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];
			inout[4] /= in[4];
			inout[5] /= in[5];
			inout[6] /= in[6];
			inout[7] /= in[7];
			inout[8] /= in[8];
			inout[9] /= in[9];
			inout[10] /= in[10];
			inout[11] /= in[11];
			inout[12] /= in[12];
			inout[13] /= in[13];
			inout[14] /= in[14];
			inout[15] /= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X16_Add_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x1 = _mm512_loadu_pd(inout);
		__m512d x2 = _mm512_loadu_pd(inout + 8);
		const __m512d y1 = _mm512_loadu_pd(in);
		const __m512d y2 = _mm512_loadu_pd(in + 8);
		x1 = _mm512_add_pd(x1, y1);
		x2 = _mm512_add_pd(x2, y2);
		_mm512_storeu_pd(inout, x1);
		_mm512_storeu_pd(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_loadu_pd(inout);
		__m256d x2 = _mm256_loadu_pd(inout + 4);
		__m256d x3 = _mm256_loadu_pd(inout + 8);
		__m256d x4 = _mm256_loadu_pd(inout + 12);
		const __m256d y1 = _mm256_loadu_pd(in);
		const __m256d y2 = _mm256_loadu_pd(in + 4);
		const __m256d y3 = _mm256_loadu_pd(in + 8);
		const __m256d y4 = _mm256_loadu_pd(in + 12);
		x1 = _mm256_add_pd(x1, y1);
		x2 = _mm256_add_pd(x2, y2);
		x3 = _mm256_add_pd(x3, y3);
		x4 = _mm256_add_pd(x4, y4);
		_mm256_storeu_pd(inout, x1);
		_mm256_storeu_pd(inout + 4, x2);
		_mm256_storeu_pd(inout + 8, x3);
		_mm256_storeu_pd(inout + 12, x4);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_loadu_pd(inout);
		__m128d x2 = _mm_loadu_pd(inout + 2);
		__m128d x3 = _mm_loadu_pd(inout + 4);
		__m128d x4 = _mm_loadu_pd(inout + 6);
		__m128d x5 = _mm_loadu_pd(inout + 8);
		__m128d x6 = _mm_loadu_pd(inout + 10);
		__m128d x7 = _mm_loadu_pd(inout + 12);
		__m128d x8 = _mm_loadu_pd(inout + 14);
		const __m128d y1 = _mm_loadu_pd(in);
		const __m128d y2 = _mm_loadu_pd(in + 2);
		const __m128d y3 = _mm_loadu_pd(in + 4);
		const __m128d y4 = _mm_loadu_pd(in + 6);
		const __m128d y5 = _mm_loadu_pd(in + 8);
		const __m128d y6 = _mm_loadu_pd(in + 10);
		const __m128d y7 = _mm_loadu_pd(in + 12);
		const __m128d y8 = _mm_loadu_pd(in + 14);
		x1 = _mm_add_pd(x1, y1);
		x2 = _mm_add_pd(x2, y2);
		x3 = _mm_add_pd(x3, y3);
		x4 = _mm_add_pd(x4, y4);
		x5 = _mm_add_pd(x5, y5);
		x6 = _mm_add_pd(x6, y6);
		x7 = _mm_add_pd(x7, y7);
		x8 = _mm_add_pd(x8, y8);
		_mm_storeu_pd(inout, x1);
		_mm_storeu_pd(inout + 2, x2);
		_mm_storeu_pd(inout + 4, x3);
		_mm_storeu_pd(inout + 6, x4);
		_mm_storeu_pd(inout + 8, x5);
		_mm_storeu_pd(inout + 10, x6);
		_mm_storeu_pd(inout + 12, x7);
		_mm_storeu_pd(inout + 14, x8);
			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];
			inout[4] += in[4];
			inout[5] += in[5];
			inout[6] += in[6];
			inout[7] += in[7];
			inout[8] += in[8];
			inout[9] += in[9];
			inout[10] += in[10];
			inout[11] += in[11];
			inout[12] += in[12];
			inout[13] += in[13];
			inout[14] += in[14];
			inout[15] += in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X16_Sub_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x1 = _mm512_loadu_pd(inout);
		__m512d x2 = _mm512_loadu_pd(inout + 8);
		const __m512d y1 = _mm512_loadu_pd(in);
		const __m512d y2 = _mm512_loadu_pd(in + 8);
		x1 = _mm512_sub_pd(x1, y1);
		x2 = _mm512_sub_pd(x2, y2);
		_mm512_storeu_pd(inout, x1);
		_mm512_storeu_pd(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_loadu_pd(inout);
		__m256d x2 = _mm256_loadu_pd(inout + 4);
		__m256d x3 = _mm256_loadu_pd(inout + 8);
		__m256d x4 = _mm256_loadu_pd(inout + 12);
		const __m256d y1 = _mm256_loadu_pd(in);
		const __m256d y2 = _mm256_loadu_pd(in + 4);
		const __m256d y3 = _mm256_loadu_pd(in + 8);
		const __m256d y4 = _mm256_loadu_pd(in + 12);
		x1 = _mm256_sub_pd(x1, y1);
		x2 = _mm256_sub_pd(x2, y2);
		x3 = _mm256_sub_pd(x3, y3);
		x4 = _mm256_sub_pd(x4, y4);
		_mm256_storeu_pd(inout, x1);
		_mm256_storeu_pd(inout + 4, x2);
		_mm256_storeu_pd(inout + 8, x3);
		_mm256_storeu_pd(inout + 12, x4);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_loadu_pd(inout);
		__m128d x2 = _mm_loadu_pd(inout + 2);
		__m128d x3 = _mm_loadu_pd(inout + 4);
		__m128d x4 = _mm_loadu_pd(inout + 6);
		__m128d x5 = _mm_loadu_pd(inout + 8);
		__m128d x6 = _mm_loadu_pd(inout + 10);
		__m128d x7 = _mm_loadu_pd(inout + 12);
		__m128d x8 = _mm_loadu_pd(inout + 14);
		const __m128d y1 = _mm_loadu_pd(in);
		const __m128d y2 = _mm_loadu_pd(in + 2);
		const __m128d y3 = _mm_loadu_pd(in + 4);
		const __m128d y4 = _mm_loadu_pd(in + 6);
		const __m128d y5 = _mm_loadu_pd(in + 8);
		const __m128d y6 = _mm_loadu_pd(in + 10);
		const __m128d y7 = _mm_loadu_pd(in + 12);
		const __m128d y8 = _mm_loadu_pd(in + 14);
		x1 = _mm_sub_pd(x1, y1);
		x2 = _mm_sub_pd(x2, y2);
		x3 = _mm_sub_pd(x3, y3);
		x4 = _mm_sub_pd(x4, y4);
		x5 = _mm_sub_pd(x5, y5);
		x6 = _mm_sub_pd(x6, y6);
		x7 = _mm_sub_pd(x7, y7);
		x8 = _mm_sub_pd(x8, y8);
		_mm_storeu_pd(inout, x1);
		_mm_storeu_pd(inout + 2, x2);
		_mm_storeu_pd(inout + 4, x3);
		_mm_storeu_pd(inout + 6, x4);
		_mm_storeu_pd(inout + 8, x5);
		_mm_storeu_pd(inout + 10, x6);
		_mm_storeu_pd(inout + 12, x7);
		_mm_storeu_pd(inout + 14, x8);
			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];
			inout[4] -= in[4];
			inout[5] -= in[5];
			inout[6] -= in[6];
			inout[7] -= in[7];
			inout[8] -= in[8];
			inout[9] -= in[9];
			inout[10] -= in[10];
			inout[11] -= in[11];
			inout[12] -= in[12];
			inout[13] -= in[13];
			inout[14] -= in[14];
			inout[15] -= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X16_Mul_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x1 = _mm512_loadu_pd(inout);
		__m512d x2 = _mm512_loadu_pd(inout + 8);
		const __m512d y1 = _mm512_loadu_pd(in);
		const __m512d y2 = _mm512_loadu_pd(in + 8);
		x1 = _mm512_mul_pd(x1, y1);
		x2 = _mm512_mul_pd(x2, y2);
		_mm512_storeu_pd(inout, x1);
		_mm512_storeu_pd(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_loadu_pd(inout);
		__m256d x2 = _mm256_loadu_pd(inout + 4);
		__m256d x3 = _mm256_loadu_pd(inout + 8);
		__m256d x4 = _mm256_loadu_pd(inout + 12);
		const __m256d y1 = _mm256_loadu_pd(in);
		const __m256d y2 = _mm256_loadu_pd(in + 4);
		const __m256d y3 = _mm256_loadu_pd(in + 8);
		const __m256d y4 = _mm256_loadu_pd(in + 12);
		x1 = _mm256_mul_pd(x1, y1);
		x2 = _mm256_mul_pd(x2, y2);
		x3 = _mm256_mul_pd(x3, y3);
		x4 = _mm256_mul_pd(x4, y4);
		_mm256_storeu_pd(inout, x1);
		_mm256_storeu_pd(inout + 4, x2);
		_mm256_storeu_pd(inout + 8, x3);
		_mm256_storeu_pd(inout + 12, x4);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_loadu_pd(inout);
		__m128d x2 = _mm_loadu_pd(inout + 2);
		__m128d x3 = _mm_loadu_pd(inout + 4);
		__m128d x4 = _mm_loadu_pd(inout + 6);
		__m128d x5 = _mm_loadu_pd(inout + 8);
		__m128d x6 = _mm_loadu_pd(inout + 10);
		__m128d x7 = _mm_loadu_pd(inout + 12);
		__m128d x8 = _mm_loadu_pd(inout + 14);
		const __m128d y1 = _mm_loadu_pd(in);
		const __m128d y2 = _mm_loadu_pd(in + 2);
		const __m128d y3 = _mm_loadu_pd(in + 4);
		const __m128d y4 = _mm_loadu_pd(in + 6);
		const __m128d y5 = _mm_loadu_pd(in + 8);
		const __m128d y6 = _mm_loadu_pd(in + 10);
		const __m128d y7 = _mm_loadu_pd(in + 12);
		const __m128d y8 = _mm_loadu_pd(in + 14);
		x1 = _mm_mul_pd(x1, y1);
		x2 = _mm_mul_pd(x2, y2);
		x3 = _mm_mul_pd(x3, y3);
		x4 = _mm_mul_pd(x4, y4);
		x5 = _mm_mul_pd(x5, y5);
		x6 = _mm_mul_pd(x6, y6);
		x7 = _mm_mul_pd(x7, y7);
		x8 = _mm_mul_pd(x8, y8);
		_mm_storeu_pd(inout, x1);
		_mm_storeu_pd(inout + 2, x2);
		_mm_storeu_pd(inout + 4, x3);
		_mm_storeu_pd(inout + 6, x4);
		_mm_storeu_pd(inout + 8, x5);
		_mm_storeu_pd(inout + 10, x6);
		_mm_storeu_pd(inout + 12, x7);
		_mm_storeu_pd(inout + 14, x8);
			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];
			inout[4] *= in[4];
			inout[5] *= in[5];
			inout[6] *= in[6];
			inout[7] *= in[7];
			inout[8] *= in[8];
			inout[9] *= in[9];
			inout[10] *= in[10];
			inout[11] *= in[11];
			inout[12] *= in[12];
			inout[13] *= in[13];
			inout[14] *= in[14];
			inout[15] *= in[15];

			#endif
		}

		/// <summary>
	/// Intrinsic vector code.
	/// </summary>
	/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
	/// <param name="in">The second input parameter.</param>
	/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X16_Div_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x1 = _mm512_loadu_pd(inout);
		__m512d x2 = _mm512_loadu_pd(inout + 8);
		const __m512d y1 = _mm512_loadu_pd(in);
		const __m512d y2 = _mm512_loadu_pd(in + 8);
		x1 = _mm512_div_pd(x1, y1);
		x2 = _mm512_div_pd(x2, y2);
		_mm512_storeu_pd(inout, x1);
		_mm512_storeu_pd(inout + 8, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_loadu_pd(inout);
		__m256d x2 = _mm256_loadu_pd(inout + 4);
		__m256d x3 = _mm256_loadu_pd(inout + 8);
		__m256d x4 = _mm256_loadu_pd(inout + 12);
		const __m256d y1 = _mm256_loadu_pd(in);
		const __m256d y2 = _mm256_loadu_pd(in + 4);
		const __m256d y3 = _mm256_loadu_pd(in + 8);
		const __m256d y4 = _mm256_loadu_pd(in + 12);
		x1 = _mm256_div_pd(x1, y1);
		x2 = _mm256_div_pd(x2, y2);
		x3 = _mm256_div_pd(x3, y3);
		x4 = _mm256_div_pd(x4, y4);
		_mm256_storeu_pd(inout, x1);
		_mm256_storeu_pd(inout + 4, x2);
		_mm256_storeu_pd(inout + 8, x3);
		_mm256_storeu_pd(inout + 12, x4);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_loadu_pd(inout);
		__m128d x2 = _mm_loadu_pd(inout + 2);
		__m128d x3 = _mm_loadu_pd(inout + 4);
		__m128d x4 = _mm_loadu_pd(inout + 6);
		__m128d x5 = _mm_loadu_pd(inout + 8);
		__m128d x6 = _mm_loadu_pd(inout + 10);
		__m128d x7 = _mm_loadu_pd(inout + 12);
		__m128d x8 = _mm_loadu_pd(inout + 14);
		const __m128d y1 = _mm_loadu_pd(in);
		const __m128d y2 = _mm_loadu_pd(in + 2);
		const __m128d y3 = _mm_loadu_pd(in + 4);
		const __m128d y4 = _mm_loadu_pd(in + 6);
		const __m128d y5 = _mm_loadu_pd(in + 8);
		const __m128d y6 = _mm_loadu_pd(in + 10);
		const __m128d y7 = _mm_loadu_pd(in + 12);
		const __m128d y8 = _mm_loadu_pd(in + 14);
		x1 = _mm_div_pd(x1, y1);
		x2 = _mm_div_pd(x2, y2);
		x3 = _mm_div_pd(x3, y3);
		x4 = _mm_div_pd(x4, y4);
		x5 = _mm_div_pd(x5, y5);
		x6 = _mm_div_pd(x6, y6);
		x7 = _mm_div_pd(x7, y7);
		x8 = _mm_div_pd(x8, y8);
		_mm_storeu_pd(inout, x1);
		_mm_storeu_pd(inout + 2, x2);
		_mm_storeu_pd(inout + 4, x3);
		_mm_storeu_pd(inout + 6, x4);
		_mm_storeu_pd(inout + 8, x5);
		_mm_storeu_pd(inout + 10, x6);
		_mm_storeu_pd(inout + 12, x7);
		_mm_storeu_pd(inout + 14, x8);
			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];
			inout[4] /= in[4];
			inout[5] /= in[5];
			inout[6] /= in[6];
			inout[7] /= in[7];
			inout[8] /= in[8];
			inout[9] /= in[9];
			inout[10] /= in[10];
			inout[11] /= in[11];
			inout[12] /= in[12];
			inout[13] /= in[13];
			inout[14] /= in[14];
			inout[15] /= in[15];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X2_Add_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x = _mm_load_pd(inout);
		const __m128d y = _mm_load_pd(in);
		x = _mm_add_pd(x, y);
		_mm_store_pd(inout, x);

			#else

			inout[0] += in[0];
			inout[1] += in[1];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X2_Sub_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x = _mm_load_pd(inout);
		const __m128d y = _mm_load_pd(in);
		x = _mm_sub_pd(x, y);
		_mm_store_pd(inout, x);

			#else

			inout[0] + -in[0];
			inout[1] -= in[1];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X2_Mul_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x = _mm_load_pd(inout);
		const __m128d y = _mm_load_pd(in);
		x = _mm_mul_pd(x, y);
		_mm_store_pd(inout, x);

			#else

			inout[0] *= in[0];
			inout[1] *= in[1];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X2_Div_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x = _mm_load_pd(inout);
		const __m128d y = _mm_load_pd(in);
		x = _mm_div_pd(x, y);
		_mm_store_pd(inout, x);

			#else

			inout[0] /= in[0];
			inout[1] /= in[1];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X2_Add_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x = _mm_loadu_pd(inout);
		const __m128d y = _mm_loadu_pd(in);
		x = _mm_add_pd(x, y);
		_mm_storeu_pd(inout, x);

			#else

			inout[0] += in[0];
			inout[1] += in[1];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X2_Sub_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x = _mm_loadu_pd(inout);
		const __m128d y = _mm_loadu_pd(in);
		x = _mm_sub_pd(x, y);
		_mm_storeu_pd(inout, x);

			#else
			inout[0] + -in[0];
			inout[1] -= in[1];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X2_Mul_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x = _mm_loadu_pd(inout);
		const __m128d y = _mm_loadu_pd(in);
		x = _mm_mul_pd(x, y);
		_mm_storeu_pd(inout, x);

			#else

			inout[0] *= in[0];
			inout[1] *= in[1];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X2_Div_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x = _mm_loadu_pd(inout);
		const __m128d y = _mm_loadu_pd(in);
		x = _mm_div_pd(x, y);
		_mm_storeu_pd(inout, x);

			#else

			inout[0] /= in[0];
			inout[1] /= in[1];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X4_Add_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x = _mm256_load_pd(inout);
		const __m256d y = _mm256_load_pd(in);
		x = _mm256_add_pd(x, y);
		_mm256_store_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		x1 = _mm_add_pd(x1, y1);
		x2 = _mm_add_pd(x2, y2);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		
			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X4_Sub_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x = _mm256_load_pd(inout);
		const __m256d y = _mm256_load_pd(in);
		x = _mm256_sub_pd(x, y);
		_mm256_store_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		x1 = _mm_sub_pd(x1, y1);
		x2 = _mm_sub_pd(x2, y2);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		
			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X4_Mul_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x = _mm256_load_pd(inout);
		const __m256d y = _mm256_load_pd(in);
		x = _mm256_mul_pd(x, y);
		_mm256_store_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		x1 = _mm_mul_pd(x1, y1);
		x2 = _mm_mul_pd(x2, y2);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		
			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X4_Div_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x = _mm256_load_pd(inout);
		const __m256d y = _mm256_load_pd(in);
		x = _mm256_div_pd(x, y);
		_mm256_store_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		x1 = _mm_div_pd(x1, y1);
		x2 = _mm_div_pd(x2, y2);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		
			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X4_Add_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x = _mm256_loadu_pd(inout);
		const __m256d y = _mm256_loadu_pd(in);
		x = _mm256_add_pd(x, y);
		_mm256_storeu_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_loadu_pd(inout);
		__m128d x2 = _mm_loadu_pd(inout + 2);
		const __m128d y1 = _mm_loadu_pd(in);
		const __m128d y2 = _mm_loadu_pd(in + 2);
		x1 = _mm_add_pd(x1, y1);
		x2 = _mm_add_pd(x2, y2);
		_mm_storeu_pd(inout, x1);
		_mm_storeu_pd(inout + 2, x2);
		
			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X4_Sub_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x = _mm256_loadu_pd(inout);
		const __m256d y = _mm256_loadu_pd(in);
		x = _mm256_sub_pd(x, y);
		_mm256_storeu_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_loadu_pd(inout);
		__m128d x2 = _mm_loadu_pd(inout + 2);
		const __m128d y1 = _mm_loadu_pd(in);
		const __m128d y2 = _mm_loadu_pd(in + 2);
		x1 = _mm_sub_pd(x1, y1);
		x2 = _mm_sub_pd(x2, y2);
		_mm_storeu_pd(inout, x1);
		_mm_storeu_pd(inout + 2, x2);
		
			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X4_Mul_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x = _mm256_loadu_pd(inout);
		const __m256d y = _mm256_loadu_pd(in);
		x = _mm256_mul_pd(x, y);
		_mm256_storeu_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_loadu_pd(inout);
		__m128d x2 = _mm_loadu_pd(inout + 2);
		const __m128d y1 = _mm_loadu_pd(in);
		const __m128d y2 = _mm_loadu_pd(in + 2);
		x1 = _mm_mul_pd(x1, y1);
		x2 = _mm_mul_pd(x2, y2);
		_mm_storeu_pd(inout, x1);
		_mm_storeu_pd(inout + 2, x2);
		
			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X4_Div_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x = _mm256_loadu_pd(inout);
		const __m256d y = _mm256_loadu_pd(in);
		x = _mm256_div_pd(x, y);
		_mm256_storeu_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_loadu_pd(inout);
		__m128d x2 = _mm_loadu_pd(inout + 2);
		const __m128d y1 = _mm_loadu_pd(in);
		const __m128d y2 = _mm_loadu_pd(in + 2);
		x1 = _mm_div_pd(x1, y1);
		x2 = _mm_div_pd(x2, y2);
		_mm_storeu_pd(inout, x1);
		_mm_storeu_pd(inout + 2, x2);
		
			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X8_Add_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x = _mm512_load_pd(inout);
		const __m512d y = _mm512_load_pd(in);
		x = _mm512_add_pd(x, y);
		_mm512_store_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_load_pd(inout);
		__m256d x2 = _mm256_load_pd(inout + 4);
		const __m256d y1 = _mm256_load_pd(in);
		const __m256d y2 = _mm256_load_pd(in + 4);
		x1 = _mm256_add_pd(x1, y1);
		x2 = _mm256_add_pd(x2, y2);
		_mm256_store_pd(inout, x1);
		_mm256_store_pd(inout + 4, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		__m128d x3 = _mm_load_pd(inout + 4);
		__m128d x4 = _mm_load_pd(inout + 6);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		const __m128d y3 = _mm_load_pd(in + 4);
		const __m128d y4 = _mm_load_pd(in + 6);
		x1 = _mm_add_pd(x1, y1);
		x2 = _mm_add_pd(x2, y2);
		x3 = _mm_add_pd(x3, y3);
		x4 = _mm_add_pd(x4, y4);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		_mm_store_pd(inout + 4, x3);
		_mm_store_pd(inout + 6, x4);
			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];
			inout[4] += in[4];
			inout[5] += in[5];
			inout[6] += in[6];
			inout[7] += in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X8_Sub_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x = _mm512_load_pd(inout);
		const __m512d y = _mm512_load_pd(in);
		x = _mm512_sub_pd(x, y);
		_mm512_store_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_load_pd(inout);
		__m256d x2 = _mm256_load_pd(inout + 4);
		const __m256d y1 = _mm256_load_pd(in);
		const __m256d y2 = _mm256_load_pd(in + 4);
		x1 = _mm256_sub_pd(x1, y1);
		x2 = _mm256_sub_pd(x2, y2);
		_mm256_store_pd(inout, x1);
		_mm256_store_pd(inout + 4, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		__m128d x3 = _mm_load_pd(inout + 4);
		__m128d x4 = _mm_load_pd(inout + 6);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		const __m128d y3 = _mm_load_pd(in + 4);
		const __m128d y4 = _mm_load_pd(in + 6);
		x1 = _mm_sub_pd(x1, y1);
		x2 = _mm_sub_pd(x2, y2);
		x3 = _mm_sub_pd(x3, y3);
		x4 = _mm_sub_pd(x4, y4);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		_mm_store_pd(inout + 4, x3);
		_mm_store_pd(inout + 6, x4);
			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];
			inout[4] -= in[4];
			inout[5] -= in[5];
			inout[6] -= in[6];
			inout[7] -= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X8_Mul_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x = _mm512_load_pd(inout);
		const __m512d y = _mm512_load_pd(in);
		x = _mm512_mul_pd(x, y);
		_mm512_store_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_load_pd(inout);
		__m256d x2 = _mm256_load_pd(inout + 4);
		const __m256d y1 = _mm256_load_pd(in);
		const __m256d y2 = _mm256_load_pd(in + 4);
		x1 = _mm256_mul_pd(x1, y1);
		x2 = _mm256_mul_pd(x2, y2);
		_mm256_store_pd(inout, x1);
		_mm256_store_pd(inout + 4, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_load_pd(inout);
		__m128d x2 = _mm_load_pd(inout + 2);
		__m128d x3 = _mm_load_pd(inout + 4);
		__m128d x4 = _mm_load_pd(inout + 6);
		const __m128d y1 = _mm_load_pd(in);
		const __m128d y2 = _mm_load_pd(in + 2);
		const __m128d y3 = _mm_load_pd(in + 4);
		const __m128d y4 = _mm_load_pd(in + 6);
		x1 = _mm_mul_pd(x1, y1);
		x2 = _mm_mul_pd(x2, y2);
		x3 = _mm_mul_pd(x3, y3);
		x4 = _mm_mul_pd(x4, y4);
		_mm_store_pd(inout, x1);
		_mm_store_pd(inout + 2, x2);
		_mm_store_pd(inout + 4, x3);
		_mm_store_pd(inout + 6, x4);
			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];
			inout[4] *= in[4];
			inout[5] *= in[5];
			inout[6] *= in[6];
			inout[7] *= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X8_Div_Aligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

		__m512d x = _mm512_loadu_pd(inout);
		const __m512d y = _mm512_loadu_pd(in);
		x = _mm512_div_pd(x, y);
		_mm512_storeu_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

		__m256d x1 = _mm256_loadu_pd(inout);
		__m256d x2 = _mm256_loadu_pd(inout + 4);
		const __m256d y1 = _mm256_loadu_pd(in);
		const __m256d y2 = _mm256_loadu_pd(in + 4);
		x1 = _mm256_div_pd(x1, y1);
		x2 = _mm256_div_pd(x2, y2);
		_mm256_storeu_pd(inout, x1);
		_mm256_storeu_pd(inout + 4, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

		__m128d x1 = _mm_loadu_pd(inout);
		__m128d x2 = _mm_loadu_pd(inout + 2);
		__m128d x3 = _mm_loadu_pd(inout + 4);
		__m128d x4 = _mm_loadu_pd(inout + 6);
		const __m128d y1 = _mm_loadu_pd(in);
		const __m128d y2 = _mm_loadu_pd(in + 2);
		const __m128d y3 = _mm_loadu_pd(in + 4);
		const __m128d y4 = _mm_loadu_pd(in + 6);
		x1 = _mm_div_pd(x1, y1);
		x2 = _mm_div_pd(x2, y2);
		x3 = _mm_div_pd(x3, y3);
		x4 = _mm_div_pd(x4, y4);
		_mm_storeu_pd(inout, x1);
		_mm_storeu_pd(inout + 2, x2);
		_mm_storeu_pd(inout + 4, x3);
		_mm_storeu_pd(inout + 6, x4);
			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];
			inout[4] /= in[4];
			inout[5] /= in[5];
			inout[6] /= in[6];
			inout[7] /= in[7];

			#endif
		}

		/// <summary>
	/// Intrinsic vector code.
	/// </summary>
	/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
	/// <param name="in">The second input parameter.</param>
	/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X8_Add_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

			__m512d x = _mm512_loadu_pd(inout);
			const __m512d y = _mm512_loadu_pd(in);
			x = _mm512_add_pd(x, y);
			_mm512_storeu_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

			__m256d x1 = _mm256_loadu_pd(inout);
			__m256d x2 = _mm256_loadu_pd(inout + 4);
			const __m256d y1 = _mm256_loadu_pd(in);
			const __m256d y2 = _mm256_loadu_pd(in + 4);
			x1 = _mm256_add_pd(x1, y1);
			x2 = _mm256_add_pd(x2, y2);
			_mm256_storeu_pd(inout, x1);
			_mm256_storeu_pd(inout + 4, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

			__m128d x1 = _mm_loadu_pd(inout);
			__m128d x2 = _mm_loadu_pd(inout + 2);
			__m128d x3 = _mm_loadu_pd(inout + 4);
			__m128d x4 = _mm_loadu_pd(inout + 6);
			const __m128d y1 = _mm_loadu_pd(in);
			const __m128d y2 = _mm_loadu_pd(in + 2);
			const __m128d y3 = _mm_loadu_pd(in + 4);
			const __m128d y4 = _mm_loadu_pd(in + 6);
			x1 = _mm_add_pd(x1, y1);
			x2 = _mm_add_pd(x2, y2);
			x3 = _mm_add_pd(x3, y3);
			x4 = _mm_add_pd(x4, y4);
			_mm_storeu_pd(inout, x1);
			_mm_storeu_pd(inout + 2, x2);
			_mm_storeu_pd(inout + 4, x3);
			_mm_storeu_pd(inout + 6, x4);
			#else

			inout[0] += in[0];
			inout[1] += in[1];
			inout[2] += in[2];
			inout[3] += in[3];
			inout[4] += in[4];
			inout[5] += in[5];
			inout[6] += in[6];
			inout[7] += in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X8_Sub_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

			__m512d x = _mm512_loadu_pd(inout);
			const __m512d y = _mm512_loadu_pd(in);
			x = _mm512_sub_pd(x, y);
			_mm512_storeu_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

			__m256d x1 = _mm256_loadu_pd(inout);
			__m256d x2 = _mm256_loadu_pd(inout + 4);
			const __m256d y1 = _mm256_loadu_pd(in);
			const __m256d y2 = _mm256_loadu_pd(in + 4);
			x1 = _mm256_sub_pd(x1, y1);
			x2 = _mm256_sub_pd(x2, y2);
			_mm256_storeu_pd(inout, x1);
			_mm256_storeu_pd(inout + 4, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

			__m128d x1 = _mm_loadu_pd(inout);
			__m128d x2 = _mm_loadu_pd(inout + 2);
			__m128d x3 = _mm_loadu_pd(inout + 4);
			__m128d x4 = _mm_loadu_pd(inout + 6);
			const __m128d y1 = _mm_loadu_pd(in);
			const __m128d y2 = _mm_loadu_pd(in + 2);
			const __m128d y3 = _mm_loadu_pd(in + 4);
			const __m128d y4 = _mm_loadu_pd(in + 6);
			x1 = _mm_sub_pd(x1, y1);
			x2 = _mm_sub_pd(x2, y2);
			x3 = _mm_sub_pd(x3, y3);
			x4 = _mm_sub_pd(x4, y4);
			_mm_storeu_pd(inout, x1);
			_mm_storeu_pd(inout + 2, x2);
			_mm_storeu_pd(inout + 4, x3);
			_mm_storeu_pd(inout + 6, x4);
			#else

			inout[0] -= in[0];
			inout[1] -= in[1];
			inout[2] -= in[2];
			inout[3] -= in[3];
			inout[4] -= in[4];
			inout[5] -= in[5];
			inout[6] -= in[6];
			inout[7] -= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X8_Mul_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

			__m512d x = _mm512_loadu_pd(inout);
			const __m512d y = _mm512_loadu_pd(in);
			x = _mm512_mul_pd(x, y);
			_mm512_storeu_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

			__m256d x1 = _mm256_loadu_pd(inout);
			__m256d x2 = _mm256_loadu_pd(inout + 4);
			const __m256d y1 = _mm256_loadu_pd(in);
			const __m256d y2 = _mm256_loadu_pd(in + 4);
			x1 = _mm256_mul_pd(x1, y1);
			x2 = _mm256_mul_pd(x2, y2);
			_mm256_storeu_pd(inout, x1);
			_mm256_storeu_pd(inout + 4, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

			__m128d x1 = _mm_loadu_pd(inout);
			__m128d x2 = _mm_loadu_pd(inout + 2);
			__m128d x3 = _mm_loadu_pd(inout + 4);
			__m128d x4 = _mm_loadu_pd(inout + 6);
			const __m128d y1 = _mm_loadu_pd(in);
			const __m128d y2 = _mm_loadu_pd(in + 2);
			const __m128d y3 = _mm_loadu_pd(in + 4);
			const __m128d y4 = _mm_loadu_pd(in + 6);
			x1 = _mm_mul_pd(x1, y1);
			x2 = _mm_mul_pd(x2, y2);
			x3 = _mm_mul_pd(x3, y3);
			x4 = _mm_mul_pd(x4, y4);
			_mm_storeu_pd(inout, x1);
			_mm_storeu_pd(inout + 2, x2);
			_mm_storeu_pd(inout + 4, x3);
			_mm_storeu_pd(inout + 6, x4);
			#else

			inout[0] *= in[0];
			inout[1] *= in[1];
			inout[2] *= in[2];
			inout[3] *= in[3];
			inout[4] *= in[4];
			inout[5] *= in[5];
			inout[6] *= in[6];
			inout[7] *= in[7];

			#endif
		}

		/// <summary>
		/// Intrinsic vector code.
		/// </summary>
		/// <param name="inout">The first input parameter which also contains the result after calculation.</param>
		/// <param name="in">The second input parameter.</param>
		/// <returns></returns>
		NOX_FORCE_INLINE inline auto F64_X8_Div_Unaligned(F64* const NOX_RESTRICT inout, const F64* const NOX_RESTRICT in) -> void
		{
			#if NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX512F__)

			__m512d x = _mm512_loadu_pd(inout);
			const __m512d y = _mm512_loadu_pd(in);
			x = _mm512_div_pd(x, y);
			_mm512_storeu_pd(inout, x);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__AVX__)

			__m256d x1 = _mm256_loadu_pd(inout);
			__m256d x2 = _mm256_loadu_pd(inout + 4);
			const __m256d y1 = _mm256_loadu_pd(in);
			const __m256d y2 = _mm256_loadu_pd(in + 4);
			x1 = _mm256_div_pd(x1, y1);
			x2 = _mm256_div_pd(x2, y2);
			_mm256_storeu_pd(inout, x1);
			_mm256_storeu_pd(inout + 4, x2);

			#elif NOX_ARCH_X86_64 && NOX_USE_ARCH_OPT && defined(__SSE2__)

			__m128d x1 = _mm_loadu_pd(inout);
			__m128d x2 = _mm_loadu_pd(inout + 2);
			__m128d x3 = _mm_loadu_pd(inout + 4);
			__m128d x4 = _mm_loadu_pd(inout + 6);
			const __m128d y1 = _mm_loadu_pd(in);
			const __m128d y2 = _mm_loadu_pd(in + 2);
			const __m128d y3 = _mm_loadu_pd(in + 4);
			const __m128d y4 = _mm_loadu_pd(in + 6);
			x1 = _mm_div_pd(x1, y1);
			x2 = _mm_div_pd(x2, y2);
			x3 = _mm_div_pd(x3, y3);
			x4 = _mm_div_pd(x4, y4);
			_mm_storeu_pd(inout, x1);
			_mm_storeu_pd(inout + 2, x2);
			_mm_storeu_pd(inout + 4, x3);
			_mm_storeu_pd(inout + 6, x4);
			#else

			inout[0] /= in[0];
			inout[1] /= in[1];
			inout[2] /= in[2];
			inout[3] /= in[3];
			inout[4] /= in[4];
			inout[5] /= in[5];
			inout[6] /= in[6];
			inout[7] /= in[7];

			#endif
		}
	}

	namespace Foundation
	{
		enum class CpuFeatureBits : U8
		{
			/// <summary>
			/// Onboard x87 FPU
			/// </summary>
			Fpu = 0,

			/// <summary>
			/// Virtual 8086 mode extensions (such as VIF, VIP, PIV)
			/// </summary>
			Vme = 1,

			/// <summary>
			/// Debugging extensions (CR4 bit 3)
			/// </summary>
			De = 2,

			/// <summary>
			/// Page WordSize Extension
			/// </summary>
			Pse = 3,

			/// <summary>
			/// Time Stamp Counter
			/// </summary>
			Tsc = 4,

			/// <summary>
			/// Model-specific registers
			/// </summary>
			Msr = 5,

			/// <summary>
			/// Physical Address Extension
			/// </summary>
			Pae = 6,

			/// <summary>
			/// Machine Check Exception
			/// </summary>
			Mce = 7,

			/// <summary>
			/// CMPXCHG8 (compare-and-swap) instruction
			/// </summary>
			Cx8 = 8,

			/// <summary>
			/// On-board Advanced Programmable Interrupt Controller
			/// </summary>
			Apic = 9,

			/// <summary>
			/// SYSENTER and SYSEXIT instructions
			/// </summary>
			Sep = 11,

			/// <summary>
			/// Memory Type Range Registers
			/// </summary>
			Mtrr = 12,

			/// <summary>
			/// Page Global Enable bit in CR4
			/// </summary>
			Pge = 13,

			/// <summary>
			/// Machine check architecture
			/// </summary>
			Mca = 14,

			/// <summary>
			///	Conditional move and FCMOV instructions
			/// </summary>
			CMov = 15,

			/// <summary>
			/// Page Attribute Table
			/// </summary>
			Pat = 16,

			/// <summary>
			/// 36-bit page size extension
			/// </summary>
			Pse36 = 17,

			/// <summary>
			/// Processor Serial Number
			/// </summary>
			Psn = 18,

			/// <summary>
			/// CLFLUSH instruction (SSE2)
			/// </summary>
			Clfsh = 19,

			/// <summary>
			/// Debug store: save trace of executed jumps
			/// </summary>
			Ds = 21,

			/// <summary>
			/// Onboard thermal control MSRs for ACPI
			/// </summary>
			Acpi = 22,


			/// <summary>
			/// MMX instructions
			/// </summary>
			Mmx = 23,

			/// <summary>
			/// FXSAVE, FXRESTOR instructions, CR4 bit 9
			/// </summary>
			Fxsr = 24,

			/// <summary>
			/// SSE instructions (a.k.a. Katmai New Instructions)
			/// </summary>
			Sse = 25,

			/// <summary>
			/// SSE2 instructions
			/// </summary>
			Sse2 = 26,

			/// <summary>
			/// CPU cache implements self-snoop
			/// </summary>
			Ss = 27,

			/// <summary>
			/// Hyper-threading
			/// </summary>
			Htt = 28,

			/// <summary>
			/// Thermal monitor automatically limits temperature
			/// </summary>
			Tm = 29,

			/// <summary>
			/// IA64 processor emulating x86
			/// </summary>
			Ia64 = 30,

			/// <summary>
			/// Pending Break Enable (PBE# pin) wakeup capability
			/// </summary>
			Pbe = 31,

			/// <summary>
			/// Prescott New Instructions-SSE3 (PNI)
			/// </summary>		
			Sse3 = 32,

			/// <summary>
			/// Carry-less Multiplication (CLMUL)
			/// </summary>
			PclMulDqd = 33,

			/// <summary>
			/// 64-bit debug store (edx bit 21)
			/// </summary>
			DTes64 = 34,

			/// <summary>
			/// MONITOR and MWAIT instructions (SSE3)
			/// </summary>
			Monitor = 35,

			/// <summary>
			/// CPL qualified debug store
			/// </summary>
			DsCpl = 36,

			/// <summary>
			/// Virtual Machine eXtensions
			/// </summary>
			Vmx = 37,

			/// <summary>
			/// Safer Mode Extensions (LaGrande)
			/// </summary>
			Smx = 38,

			/// <summary>
			/// Enhanced SpeedStep
			/// </summary>
			Est = 39,

			/// <summary>
			/// Thermal Monitor 2
			/// </summary>
			Tm2 = 40,

			/// <summary>
			/// Supplemental SSE3 instructions
			/// </summary>
			Ssse3 = 41,

			/// <summary>
			/// L1 Context ID
			/// </summary>
			CnxtId = 42,

			/// <summary>
			/// Silicon Debug interface
			/// </summary>
			Sdbg = 43,

			/// <summary>
			/// Fused multiply-add (FMA3)
			/// </summary>
			Fma3 = 44,

			/// <summary>
			/// CMPXCHG16B instruction
			/// </summary>
			Cx16 = 45,

			/// <summary>
			/// Can disable sending task priority messages
			/// </summary>
			Xtpr = 46,

			/// <summary>
			/// Perfmon & debug capability
			/// </summary>
			Pdcm = 47,

			/// <summary>
			/// Process context identifiers (CR4 bit 17)
			/// </summary>
			Pcid = 49,

			/// <summary>
			/// Direct cache access for DMA writes
			/// </summary>
			Dca = 50,

			/// <summary>
			/// SSE4.1 instructions
			/// </summary>
			Sse41 = 51,

			/// <summary>
			/// SSE4.2 instructions
			/// </summary>
			Sse42 = 52,

			/// <summary>
			/// x2APIC
			/// </summary>
			X2Apic = 53,

			/// <summary>
			/// MOVBE instruction (big-endian)
			/// </summary>
			MovBe = 54,

			/// <summary>
			/// POPCNT instruction
			/// </summary>
			PopCnt = 55,

			/// <summary>
			/// APIC implements one-shot operation using a TSC deadline value
			/// </summary>
			TscDeadLine = 56,

			/// <summary>
			/// AES instruction set
			/// </summary>
			Aes = 57,

			/// <summary>
			/// XSAVE, XRESTOR, XSETBV, XGETBV
			/// </summary>
			XSave = 58,

			/// <summary>
			/// XSAVE enabled by OS
			/// </summary>
			OsXSave = 59,

			/// <summary>
			/// Advanced Vector Extensions
			/// </summary>
			Avx = 60,

			/// <summary>
			/// F16C (half-precision) FP feature
			/// </summary>
			F16C = 61,

			/// <summary>
			/// RDRAND (on-chip random number generator) feature
			/// </summary>
			RdRand = 62,

			/// <summary>
			/// HyperVisor present (always zero on physical CPUs)
			/// </summary>
			HyperVisor = 63,

			/// <summary>
			/// Access to base of %fs and %gs
			/// </summary>
			FsGsBase = 64,

			/// <summary>
			/// IA32_TSC_ADJUST
			/// </summary>
			TscAdjust = 65,

			/// <summary>
			/// Software Guard Extensions
			/// </summary>
			Sgx = 66,

			/// <summary>
			/// Bit Manipulation Instruction Set 1
			/// </summary>
			Bmi1 = 67,

			/// <summary>
			/// TSX Hardware Lock Elision
			/// </summary>
			Hle = 68,

			/// <summary>
			/// Advanced Vector Extensions 2
			/// </summary>
			Avx2 = 69,

			/// <summary>
			/// FDP_EXCPTN_ONLY
			/// </summary>
			FdpExcept = 70,

			/// <summary>
			/// Supervisor Mode Execution Prevention
			/// </summary>
			Smep = 71,

			/// <summary>
			/// Bit Manipulation Instruction Set 2
			/// </summary>
			Bmi2 = 72,

			/// <summary>
			/// Enhanced REP MOVSB/STOSB
			/// </summary>
			Erms = 73,

			/// <summary>
			/// INVPCID instruction
			/// </summary>
			InvPcid = 74,

			/// <summary>
			/// TSX Restricted Transactional Memory
			/// </summary>
			Rtm = 75,

			/// <summary>
			/// Platform Quality of Service Monitoring
			/// </summary>
			Pqm = 76,

			/// <summary>
			/// FPU CS and FPU DS deprecated
			/// </summary>
			FpuCsDsDepr = 77,

			/// <summary>
			/// Intel MPX (Memory Protection Extensions)
			/// </summary>
			Mpx = 78,

			/// <summary>
			/// Platform Quality of Service Enforcement
			/// </summary>
			Pwe = 79,

			/// <summary>
			/// AVX-512 Foundation
			/// </summary>
			Avx512F = 80,

			/// <summary>
			/// AVX-512 Doubleword and Quadword Instructions
			/// </summary>
			Avx512Dq = 81,

			/// <summary>
			/// RDSEED instruction
			/// </summary>
			RdSeed = 82,

			/// <summary>
			/// Intel ADX (Multi-Precision Add-Carry Instruction Extensions)
			/// </summary>
			Adx = 83,

			/// <summary>
			/// Supervisor Mode Access Prevention
			/// </summary>
			SMap = 84,

			/// <summary>
			/// Integer Fused Multiply-Add Instructions
			/// </summary>
			Avx512Ifma = 85,

			/// <summary>
			/// PCOMMIT instruction
			/// </summary>
			PCommit = 86,

			/// <summary>
			/// CLFLUSHOPT instruction
			/// </summary>
			ClFlushOpt = 87,

			/// <summary>
			/// CLWB instruction
			/// </summary>
			Clwb = 88,

			/// <summary>
			/// Intel Processor Trace
			/// </summary>
			IntelPt = 89,

			/// <summary>
			/// AVX 512 Prefetch Instructions
			/// </summary>
			Avx512Pf = 90,

			/// <summary>
			///  Exponential and Reciprocal Instructions
			/// </summary>
			Avx512Er = 91,

			/// <summary>
			/// Conflict Detection Instructions
			/// </summary>
			Avx512Cd = 92,

			/// <summary>
			/// Intel secure hashing algorithm extensions
			/// </summary>
			Sha = 93,

			/// <summary>
			/// Byte and word Instructions
			/// </summary>
			Avx512Bw = 94,

			/// <summary>
			/// Vector Length Extensions
			/// </summary>
			Avx512Vl = 95,

			/// <summary>
			/// PREFETCHWT1 instruction
			/// </summary>
			PreFetchWt1 = 96,

			/// <summary>
			/// Vector Bit Manipulation Instructions
			/// </summary>
			Avx512Vbmi = 97,

			/// <summary>
			/// User-mode Instruction Prevention
			/// </summary>
			Umip = 98,

			/// <summary>
			/// Memory Protection Keys for User-mode pages
			/// </summary>
			Pku = 99,

			/// <summary>
			/// PKU enabled by OS
			/// </summary>
			OsPku = 100,

			/// <summary>
			/// Timed pause and user-level monitor/wait
			/// </summary>
			WaitPkg = 101,

			/// <summary>
			/// AVX-512 Vector Bit Manipulation Instructions 2
			/// </summary>
			Avx512Vmbi2 = 102,

			/// <summary>
			/// Control flow enforcement (CET) shadow stack
			/// </summary>
			CetSs = 103,

			/// <summary>
			/// AVX-512	galois field instructions
			/// </summary>
			Avx512Gfni = 104,

			/// <summary>
			/// Vector AES instruction set (VEX-256/EVEX)
			/// </summary>
			VAes = 105,

			/// <summary>
			/// Vector CLMUL instruction set (VEX-256/EVEX)
			/// </summary>
			VPclMulDqd = 106,

			/// <summary>
			/// AVX-512 vector neural network instructions
			/// </summary>
			Avx512Vnni = 107,

			/// <summary>
			/// AVX-512 bit algorithm instructions
			/// </summary>
			Avx512Bitalg = 108,

			/// <summary>
			/// AVX-512 vector population count double and qword
			/// </summary>
			Avx512PopCntdq = 110,

			/// <summary>
			/// 5-level paging
			/// </summary>
			Level5Paging = 112,

			/// <summary>
			/// Read Processor ID and IA32_TSC_AUX
			/// </summary>
			RdPid = 118,

			/// <summary>
			/// Cache line demote
			/// </summary>
			ClDemote = 121,

			/// <summary>
			/// 
			/// </summary>
			MovDiri = 123,

			/// <summary>
			/// 
			/// </summary>
			MovDir64B = 124,

			/// <summary>
			/// Enqueue Stores
			/// </summary>
			EnqCmd = 125,

			/// <summary>
			/// SGX Launch Configuration
			/// </summary>
			SgxLc = 126,

			/// <summary>
			/// Protection keys for supervisor-mode pages
			/// </summary>
			Pks = 127,

			/// <summary>
			/// AVX-512 4 register neural network instructions
			/// </summary>
			Avx512Vnniw4 = 130,

			/// <summary>
			/// AVX-512 4 register multiply accumulation single precision
			/// </summary>
			Avx512FMaps4 = 131,

			/// <summary>
			/// Fast Short REP MOVSB
			/// </summary>
			Fsrm = 132,

			/// <summary>
			/// AVX-512 intersection
			/// </summary>
			Avx512Vp2Intersect = 136,

			/// <summary>
			/// Special register system bump pool data sampling mitigations
			/// </summary>
			SrbdsCtrl = 137,

			/// <summary>
			/// Clears CPU buffers
			/// </summary>
			MdClear = 138,

			/// <summary>
			/// 
			/// </summary>
			TsxForceAbort = 141,

			/// <summary>
			/// Serialize instruction execution
			/// </summary>
			Serialize = 142,

			/// <summary>
			/// 
			/// </summary>
			Hybrid = 143,

			/// <summary>
			/// TSX suspend load address tracking
			/// </summary>
			TsxLdTrk = 144,

			/// <summary>
			/// Platform configuration (Memory Encryption Technologies Instructions)
			/// </summary>
			PConfig = 146,

			/// <summary>
			/// Architectural Last Branch Records
			/// </summary>
			Pbr = 147,

			/// <summary>
			/// Control flow enforcement (CET) indirect branch tracking
			/// </summary>
			CetIbt = 148,

			/// <summary>
			/// Tile computation on bfloat16 numbers
			/// </summary>
			AmxBf16 = 150,

			/// <summary>
			/// Tile architecture
			/// </summary>
			AmxTile = 152,

			/// <summary>
			///  Tile computation on 8-bit integers
			/// </summary>
			AmxInt8 = 153,

			/// <summary>
			/// Speculation Control, part of Indirect Branch 
			/// Indirect Branch Restricted Speculation(IBRS)
			///	SpecIndirect Branch Prediction Barrier(IBPB)
			///	</summary>
			Ctrl = 154,

			/// <summary>
			/// Single thread indirect branch predictor, part of IBC
			/// </summary>
			Stibp = 155,

			/// <summary>
			/// IA32_FLUSH_CMD MSR
			/// </summary>
			L1DFlush = 156,

			/// <summary>
			/// Speculative side channel mitigations
			/// </summary>
			Ia32ArchCompat = 157,

			/// <summary>
			/// Support for a MSR listing model-specific core capabilities
			/// </summary>
			Ia32CoreCompat = 158,

			/// <summary>
			/// Speculative Store Bypass Disable,
			/// as mitigation for Speculative Store Bypass (IA32_SPEC_CTRL)
			/// </summary>
			Ssbd = 159,

			/// <summary>
			/// LAHF/SAHF in long mode
			/// </summary>
			LahfLm = 160,

			/// <summary>
			/// Hyperthreading not valid
			/// </summary>
			CmpLegacy = 161,

			/// <summary>
			/// Secure Virtual Machine
			/// </summary>
			Svm = 162,

			/// <summary>
			/// Extended APIC space
			/// </summary>
			ExtApic = 163,

			/// <summary>
			/// CR8 in 32-bit mode
			/// </summary>
			Cr8Legacy = 164,

			/// <summary>
			/// Advanced bit manipulation (lzcnt and popcnt)
			/// </summary>
			Avm = 165,

			/// <summary>
			/// SSE4a
			/// </summary>
			Sse4A = 166,

			/// <summary>
			/// Misaligned SSE mode
			/// </summary>
			MisAlignedSse = 167,

			/// <summary>
			/// PREFETCH and PREFETCHW instructions
			/// </summary>
			D3NowPrefetch = 168,

			/// <summary>
			/// OS Visible Workaround
			/// </summary>
			OsVw = 169,

			/// <summary>
			/// Instruction based sampling
			/// </summary>
			Ibs = 170,

			/// <summary>
			/// XOP instruction set
			/// </summary>
			Xop = 171,

			/// <summary>
			/// SKINIT/STGI instructions
			/// </summary>
			SkInit = 172,

			/// <summary>
			/// Watchdog timer
			/// </summary>
			Dgt = 173,

			/// <summary>
			/// Light Weight Profiling[25]
			/// </summary>
			Lwp = 175,

			/// <summary>
			/// 4 operands fused multiply-add
			/// </summary>
			Fma4 = 176,

			/// <summary>
			/// Translation cache extension
			/// </summary>
			Tce = 177,

			/// <summary>
			/// NodeID MSR
			/// </summary>
			NodeIdMdr = 179,

			/// <summary>
			/// Trailing bit manipulation
			/// </summary>
			Tbm = 181,

			/// <summary>
			/// Topology extensions
			/// </summary>
			TopoExt = 182,

			/// <summary>
			///  Core performance counter extensions
			/// </summary>
			PerfCtrCore = 183,

			/// <summary>
			/// NB performance counter extensions
			/// </summary>
			PerCtrNb = 184,

			/// <summary>
			/// Data breakpoint extensions
			/// </summary>
			Dbx = 186,

			/// <summary>
			/// Performance TSC
			/// </summary>
			PerfTsc = 187,

			/// <summary>
			/// L2I perf counter extensions
			/// </summary>
			PcxL2i = 188,

			/// <summary>
			///  SYSCALL and SYSRET instructions
			/// </summary>
			SysCall = 203,

			/// <summary>
			/// Multiprocessor capable
			/// </summary>
			MpCap = 211,

			/// <summary>
			/// NX bit
			/// </summary>
			Nx = 212,

			/// <summary>
			/// Extended MMX
			/// </summary>
			MmxEx = 214,

			/// <summary>
			/// FXSAVE/FXRSTOR optimizations
			/// </summary>
			FxsrOpt = 217,

			/// <summary>
			/// Gigabyte pages
			/// </summary>
			Pdpe1Gb = 218,

			/// <summary>
			/// RDTSCP instruction
			/// </summary>
			RdTscP = 219,

			/// <summary>
			/// Long mode
			/// </summary>
			LongMode = 221,

			/// <summary>
			/// Extended 3DNow
			/// </summary>
			D3NowExt = 222,

			/// <summary>
			/// 3DNow!
			/// </summary>
			D3Now = 223,


			/// <summary>
			/// Amount of bits.
			/// </summary>
			Count_
		};

		/// <summary>
		/// Contains all CPU feature names.
		/// </summary>
		constexpr std::array<std::string_view, static_cast<U64>(CpuFeatureBits::Count_)> CPU_FEATURE_BIT_NAMES
		{
			#if NOX_ARCH_X86_64
			"FPU",
			"VME",
			"DE",
			"PSE",
			"TSC",
			"MSR",
			"PAE",
			"MCE",
			"CX8",
			"APIC",
			{ },
			"SEP",
			"MTRR",
			"PGE",
			"MCA",
			"CMOV",
			"PAT",
			"PSE36",
			"PSN",
			"CLFSH",
			{ },
			"DS",
			"ACPI",
			"MMX",
			"FXSR",
			"SSE",
			"SSE2",
			"SS",
			"HTT",
			"TM",
			"IA64",
			"PBE",
			"SSE3",
			"PCLMULDQD",
			"DTES64",
			"MONITOR",
			"DSCPL",
			"VMX",
			"SMX",
			"EST",
			"TM2",
			"SSSE3",
			"CNXTID",
			"SDBG",
			"FMA3",
			"CX16",
			"XTPR",
			"PDCM",
			{ },
			"PCID",
			"DCA",
			"SSE41",
			"SSE42",
			"X2APIC",
			"MOVBE",
			"POPCNT",
			"TSCDEADLINE",
			"AES",
			"XSAVE",
			"OSXSAVE",
			"AVX",
			"F16C",
			"RDRAND",
			"HYPERVISOR",
			"FSGSBASE",
			"TSCADJUST",
			"SGX",
			"BMI1",
			"HLE",
			"AVX2",
			"FDPEXCEPT",
			"SMEP",
			"BMI2",
			"ERMS",
			"INVPCID",
			"RTM",
			"PQM",
			"FPUCSDSDEPR",
			"MPX",
			"PWE",
			"AVX512F",
			"AVX512DQ",
			"RDSEED",
			"ADX",
			"SMAP",
			"AVX512IFMA",
			"PCOMMIT",
			"CLFLUSHOPT",
			"CLWB",
			"INTELPT",
			"AVX512PF",
			"AVX512ER",
			"AVX512CD",
			"SHA",
			"AVX512BW",
			"AVX512VL",
			"PREFETCHWT1",
			"AVX512VBMI",
			"UMIP",
			"PKU",
			"OSPKU",
			"WAITPKG",
			"AVX512VMBI2",
			"CETSS",
			"AVX512GFNI",
			"VAES",
			"VPCLMULDQD",
			"AVX512VNNI",
			"AVX512BITALG",
			{ },
			"AVX512POPCNTDQ",
			{ },
			"LEVEL5PAGING",
			{ },
			{ },
			{ },
			{ },
			{ },
			"RDPID",
			{ },
			{ },
			"CLDEMOTE",
			{ },
			"MOVDIRI",
			"MOVDIR64B",
			"ENQCMD",
			"SGXLC",
			"PKS",
			{ },
			{ },
			"AVX512VNNIW4",
			"AVX512FMAPS4",
			"FSRM",
			{ },
			{ },
			{ },
			"AVX512VP2INTERSECT",
			"SRBDSCTRL",
			"MDCLEAR",
			{ },
			{ },
			"TSXFORCEABORT",
			"SERIALIZE",
			"HYBRID",
			"TSXLDTRK",
			{ },
			"PCONFIG",
			"PBR",
			"CETIBT",
			{ },
			"AMXBF16",
			{ },
			"AMXTILE",
			"AMXINT8",
			"CTRL",
			"STIBP",
			"L1DFLUSH",
			"IA32ARCHCOMPAT",
			"IA32CORECOMPAT",
			"SSBD",
			"LAHFLM",
			"CMPLEGACY",
			"SVM",
			"EXTAPIC",
			"CR8LEGACY",
			"AVM",
			"SSE4A",
			"MISALIGNEDSSE",
			"D3NOWPREFETCH",
			"OSVW",
			"IBS",
			"XOP",
			"SKINIT",
			"DGT",
			{ },
			"LWP",
			"FMA4",
			"TCE",
			{ },
			"NODEIDMDR",
			{ },
			"TBM",
			"TOPOEXT",
			"PERFCTRCORE",
			"PERCTRNB",
			{ },
			"DBX",
			"PERFTSC",
			"PCXL2I",
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			"SYSCALL",
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			{ },
			"MPCAP",
			"NX",
			{ },
			"MMXEX",
			{ },
			{ },
			"FXSROPT",
			"PDPE1GB",
			"RDTSCP",
			{ },
			"LONGMODE",
			"D3NOWEXT",
			"D3NOW"
			#else
#error "Unimplemented architecture!"
			#endif
		};

		/// <summary>
		/// Feature mask.
		/// </summary>
		using CpuFeatureMask = std::array<bool, static_cast<U64>(CpuFeatureBits::Count_)>;

		/// <summary>
		/// Bitmask storage type.
		/// </summary>
		using CpuFeatureMaskBitStorage = std::bitset<static_cast<U64>(CpuFeatureBits::Count_)>;

		/// <summary>
		/// Feature mask.
		/// </summary>
		using CpuFeatureMaskBuffer = std::array<U8, static_cast<U64>(CpuFeatureBits::Count_) / CHAR_BIT>;

		/// <summary>
		/// Detects architecture dependent cpu features.
		/// </summary>
		class CpuFeatureDetector final
		{
			/// <summary>
			/// Architecture dependent bits.
			/// </summary>
			CpuFeatureMask FeatureBits_;

			/// <summary>
			/// Get or set support for special feature.
			/// </summary>
			/// <param name="bit"></param>
			/// <returns></returns>
			auto operator [](CpuFeatureBits bit) -> bool&;

		public:
			/// <summary>
			/// Construct new instance and query cpu feature
			/// using architecture dependent routines.
			/// </summary>
			CpuFeatureDetector();

			/// <summary>
			/// No copy.
			/// </summary>
			CpuFeatureDetector(const CpuFeatureDetector&) = delete;

			/// <summary>
			/// No move.
			/// </summary>
			CpuFeatureDetector(CpuFeatureDetector&&) = default;

			/// <summary>
			/// No copy.
			/// </summary>
			auto operator =(const CpuFeatureDetector&) -> CpuFeatureDetector& = delete;

			/// <summary>
			/// No move.
			/// </summary>
			auto operator =(CpuFeatureDetector&&) -> CpuFeatureDetector& = delete;

			/// <summary>
			/// Destructor.
			/// </summary>
			~CpuFeatureDetector() = default;

			/// <summary>
			/// Access the architecture dependent feature bits directly.
			/// </summary>
			[[nodiscard]]
			auto operator ->() const -> const CpuFeatureMask*;

			/// <summary>
			/// Access the architecture dependent feature bits directly.
			/// </summary>
			[[nodiscard]]
			auto operator *() const -> const CpuFeatureMask&;

			/// <summary>
			/// Check support for special feature.
			/// </summary>
			/// <param name="bit"></param>
			/// <returns></returns>
			auto operator [](CpuFeatureBits bit) const -> bool;

			/// <summary>
			/// Prints all the architecture dependent features as booleans with names.
			/// </summary>
			auto Dump() const -> void;
		};

		inline auto CpuFeatureDetector::operator[](const CpuFeatureBits bit) -> bool&
		{
			return this->FeatureBits_[static_cast<U64>(bit)];
		}

		inline auto CpuFeatureDetector::operator[](const CpuFeatureBits bit) const -> bool
		{
			return this->FeatureBits_[static_cast<U64>(bit)];
		}

		inline auto CpuFeatureDetector::operator*() const -> const CpuFeatureMask&
		{
			return this->FeatureBits_;
		}

		inline auto CpuFeatureDetector::operator->() const -> const CpuFeatureMask*
		{
			return &this->FeatureBits_;
		}

		/// <summary>
		/// Represents a machine rating.
		/// </summary>
		enum class MachineClass : char
		{
			/// <summary>
			/// Excellent
			/// </summary>
			A = 'A',

			/// <summary>
			/// Very Good
			/// </summary>
			B = 'B',

			/// <summary>
			/// Good
			/// </summary>
			C = 'C',

			/// <summary>
			/// Okay
			/// </summary>
			D = 'D',

			/// <summary>
			/// Bad
			/// </summary>
			E = 'E',

			/// <summary>
			/// Potato
			/// </summary>
			F = 'F'
		};

		/// <summary>
		/// Query machine class based on CPU threads.
		/// </summary>
		/// <param name="threads"></param>
		/// <returns></returns>
		constexpr auto MachineRating(const U64 threads) -> MachineClass
		{
			if (threads <= 2)
			{
				return MachineClass::F;
			}
			if (threads <= 4)
			{
				return MachineClass::E;
			}
			if (threads <= 8)
			{
				return MachineClass::D;
			}
			if (threads <= 16)
			{
				return MachineClass::C;
			}
			if (threads <= 32)
			{
				return MachineClass::B;
			}
			return MachineClass::A;
		}

		/// <summary>
		/// Contains operating specific routines.
		/// </summary>
		struct Os final
		{
			/// <summary>
			/// Static class!
			/// </summary>
			Os() = delete;

			/// <summary>
			/// Static class!
			/// </summary>
			/// <param name="other"></param>
			Os(const Os& other) = delete;

			/// <summary>
			/// Static class!
			/// </summary>
			/// <param name="other"></param>
			Os(Os&& other) = delete;

			/// <summary>
			/// Static class!
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(const Os& other) -> Os& = delete;

			/// <summary>
			/// Static class!
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(Os&& other) -> Os& = delete;

			/// <summary>
			/// Static class!
			/// </summary>
			~Os() = delete;

			/// <summary>
			/// Query system info.
			/// </summary>
			/// <returns>The total system memory in bytes.</returns>
			[[nodiscard]]
			static auto QuerySystemMemoryTotal() -> U64;

			/// <summary>
			/// Query system info.
			/// </summary>
			/// <returns>The amount of memory used by the current process in bytes.</returns>
			[[nodiscard]]
			static auto QueryProcessMemoryUsed() -> U64;

			/// <summary>
			/// Query system info.
			/// </summary>
			/// <returns>The name of the CPU.</returns>
			[[nodiscard]]
			static auto QueryCpuName() -> std::string;

			/// <summary>
			/// Query system info.
			/// </summary>
			/// <returns>The size of a page in bytes.</returns>
			[[nodiscard]]
			static auto QueryPageSize() -> U64;

			/// <summary>
			/// Open dynamic library file.
			/// </summary>
			/// <param name="filePath"></param>
			/// <returns></returns>
			[[nodiscard]]
			static auto DylibOpen(std::string_view filePath) -> void*;

			/// <summary>
			/// Lookup symbol in dynamic library.
			/// </summary>
			/// <param name="handle"></param>
			/// <param name="symbolName"></param>
			/// <returns></returns>
			[[nodiscard]]
			static auto DylibLookupSymbol(void* handle, std::string_view symbolName) -> void*;

			/// <summary>
			/// Close dynamic library.
			/// </summary>
			/// <param name="handle"></param>
			/// <returns></returns>
			static auto DylibClose(void*& handle) -> void;
		};

		/// <summary>
		/// Contains information about the current system and stats.
		/// </summary>
		struct Snapshot final
		{
			/// <summary>
			/// The current thread id.
			/// </summary>
			std::thread::id ThreadId { };

			/// <summary>
			/// Name of the operating system.
			/// </summary>
			std::string_view OperatingSystemName {NOX_OS_NAME};

			/// <summary>
			/// Architecture name.
			/// </summary>
			std::string_view ArchitectureName {NOX_ARCH_NAME};

			/// <summary>
			/// Name of the compiler.
			/// </summary>
			std::string_view CompilerName {NOX_COM_NAME};

			/// <summary>
			/// Amount of CPU supported threads.
			/// </summary>
			U64 ThreadCount { };

			/// <summary>
			/// Name of the CPU.
			/// </summary>
			std::string CpuName { };

			/// <summary>
			/// The total amount of memory in bytes.
			/// </summary>
			U64 TotalSystemMemory { };

			/// <summary>
			/// The total amount of process memory in bytes.
			/// </summary>
			U64 ProcessMemory { };

			/// <summary>
			/// The size of a page in bytes.
			/// </summary>
			U64 PageSize { };

			/// <summary>
			/// Construct and query data.
			/// </summary>
			Snapshot();

			/// <summary>
			/// Copy constructor.
			/// </summary>
			/// <param name="other"></param>
			Snapshot(const Snapshot& other) = default;

			/// <summary>
			/// Move constructor.
			/// </summary>
			/// <param name="other"></param>
			Snapshot(Snapshot&& other) = default;

			/// <summary>
			/// Copy assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(const Snapshot& other) -> Snapshot& = default;

			/// <summary>
			/// Move assignment operator.
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(Snapshot&& other) -> Snapshot& = default;

			/// <summary>
			/// Destructor.
			/// </summary>
			~Snapshot() = default;

			/// <summary>
			/// Query and refresh data.
			/// </summary>
			/// <returns></returns>
			auto QueryAll() -> void;

			/// <summary>
			/// Print the data.
			/// </summary>
			/// <returns></returns>
			auto Print() const -> void;
		};

		/// <summary>
		/// Represents a procedure address inside a dynamic library.
		/// </summary>
		struct DynamicProcedure final
		{
			/// <summary>
			/// Construct from pointer.
			/// </summary>
			/// <param name="value"></param>
			/// <returns></returns>
			constexpr explicit DynamicProcedure(void* value);

			/// <summary>
			/// Null pointers forbidden.
			/// </summary>
			/// <param name=""></param>
			explicit DynamicProcedure(std::nullptr_t) = delete;

			/// <summary>
			/// Cast to function reference.
			/// </summary>
			/// <typeparam name="F">The function signature to cast to. Must be the same as in the dynamic link library!</typeparam>
			/// <returns>The function ref.</returns>
			template <typename F> requires std::is_function_v<F>
			auto operator*() const -> F&;


			/// <summary>
			/// Cast to function reference and call function.
			/// </summary>
			/// <typeparam name="F">The function signature to cast to. Must be the same as in the dynamic link library!</typeparam>
			/// <typeparam name="...Ts">The arguments to call the function with.</typeparam>
			/// <param name="args">The arguments to call the function with.</param>
			/// <returns>The return value of the called function.</returns>
			template <typename F, typename... Ts> requires std::is_function_v<F> && std::is_invocable_v<F, Ts...>
			auto operator()(Ts&&...args) const -> decltype(F(std::forward<Ts...>(args...)));

			void* Ptr;
		};

		static_assert(std::is_copy_constructible_v<DynamicProcedure>);
		static_assert(std::is_move_assignable_v<DynamicProcedure>);
		static_assert(std::is_trivially_copy_assignable_v<DynamicProcedure>);
		static_assert(std::is_trivially_move_assignable_v<DynamicProcedure>);

		constexpr DynamicProcedure::DynamicProcedure(void* const value) : Ptr {value} { }

		template <typename F> requires std::is_function_v<F>
		inline auto DynamicProcedure::operator*() const -> F&
		{
			return *static_cast<F*>(this->Ptr);
		}

		template <typename F, typename ... Ts> requires std::is_function_v<F> && std::is_invocable_v<F, Ts...>
		inline auto DynamicProcedure::operator()(Ts&&...args) const -> decltype(F(std::forward<Ts...>(args...)))
		{
			return (*static_cast<F*>(this->Ptr))(std::forward<Ts...>(args...));
		}

		/// <summary>
		/// Represents a dynamically linked library. (.dll, .so) 
		/// </summary>
		struct DynamicLibrary final
		{
			/// <summary>
			/// Load from file.
			/// </summary>
			/// <param name="filePath">The file path to load from.</param>
			explicit DynamicLibrary(std::string_view filePath);

			/// <summary>
			/// Load from file.
			/// </summary>
			/// <param name="filePath">The file path to load from.</param>
			explicit DynamicLibrary(const std::filesystem::path& filePath);

			/// <summary>
			/// No moving, copying
			/// </summary>
			/// <param name="other"></param>
			DynamicLibrary(const DynamicLibrary& other) = delete;

			/// <summary>
			/// No moving, copying
			/// </summary>
			/// <param name="other"></param>
			DynamicLibrary(DynamicLibrary&& other) = delete;

			/// <summary>
			/// No moving, copying
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(const DynamicLibrary& other) -> DynamicLibrary& = delete;

			/// <summary>
			/// No moving, copying
			/// </summary>
			/// <param name="other"></param>
			/// <returns></returns>
			auto operator =(DynamicLibrary&& other) -> DynamicLibrary& = delete;

			/// <summary>
			/// Destructor, release library handle.
			/// </summary>
			~DynamicLibrary();

			/// <summary>
			/// Check if pointer handle is valid.
			/// </summary>
			/// <returns>True if pointer handle is valid, else false.</returns>
			[[nodiscard]] operator bool() const;

			/// <summary>
			/// Perform a symbol lookup.
			/// </summary>
			/// <param name="symbolName">The correct name of the dynamic symbol.</param>
			/// <returns>The corresponding dynamic procedure on success, else std::nullopt.</returns>
			[[nodiscard]] auto operator [](std::string_view symbolName) const -> std::optional<DynamicProcedure>;

		private:
			void* Handle_ {nullptr};
		};

		static_assert(!std::is_copy_constructible_v<DynamicLibrary>);
		static_assert(!std::is_move_assignable_v<DynamicLibrary>);
		static_assert(!std::is_trivially_copy_assignable_v<DynamicLibrary>);
		static_assert(!std::is_trivially_move_assignable_v<DynamicLibrary>);

		inline DynamicLibrary::DynamicLibrary(const std::string_view filePath) : Handle_ {Os::DylibOpen(filePath)} { }

		inline DynamicLibrary::DynamicLibrary(const std::filesystem::path& filePath) : Handle_ {
			Os::DylibOpen(filePath.string())
		} { }

		inline DynamicLibrary::~DynamicLibrary()
		{
			Os::DylibClose(this->Handle_);
		}

		inline DynamicLibrary::operator bool() const
		{
			return this->Handle_ != nullptr;
		}

		inline auto DynamicLibrary::operator[](const std::string_view symbolName) const -> std::optional<DynamicProcedure>
		{
			void* const symbolHandle = Os::DylibLookupSymbol(this->Handle_, symbolName);
			return symbolHandle ? std::optional {DynamicProcedure {symbolHandle}} : std::nullopt;
		}

		/// <summary>
		/// Type used for storing information in the meta header.
		/// </summary>
		using MetaHeaderScalar = U64;

		/// <summary>
		/// Contains all flags in the flag vector field in the object header.
		/// </summary>
		union alignas(alignof(MetaHeaderScalar)) ObjectFlagVector final
		{
			#if NOX_DEBUG
			struct
			{
				/// <summary>
				///
				/// </summary>
				bool Flag0 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag1 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag2 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag3 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag4 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag5 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag6 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag7 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag8 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag9 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag10 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag11 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag12 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag13 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag14 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag15 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag16 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag17 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag18 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag19 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag20 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag21 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag22 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag23 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag24 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag25 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag26 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag27 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag28 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag29 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag30 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag31 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag32 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag33 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag34 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag35 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag36 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag37 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag38 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag39 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag40 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag41 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag42 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag43 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag44 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag45 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag46 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag47 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag48 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag49 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag50 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag51 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag52 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag53 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag54 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag55 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag56 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag57 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag58 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag59 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag60 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag61 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag62 : 1;

				/// <summary>
				///
				/// </summary>
				bool Flag63 : 1;
			} Flags;

			#endif
			MetaHeaderScalar Merged;
		};

		static_assert(sizeof(ObjectFlagVector) == sizeof(MetaHeaderScalar));

		/// Every heap allocated object has an object header.
		/// The object header contains various meta data about the object.
		/// Each object header field is 32 - bits wide.
		///
		/// Offset	   Description	  WordSize
		/// +-----------------------+
		/// | 0 | Strong Ref Count  | 64 Bit - sizeof(MetaHeaderScalar64)
		/// +-----------------------+
		/// | 1 | WordSize in Records	| 64 Bit - sizeof(MetaHeaderScalar64)
		/// +-----------------------+
		/// | 2 | Type ID			| 64 Bit - sizeof(MetaHeaderScalar64)
		/// +-----------------------+
		/// | 3 | Flag Vector		| 64 Bit - sizeof(MetaHeaderScalar64)
		/// +-----------------------+
		/// Total size : 256 Bit(32 Bytes)
		struct alignas(alignof(MetaHeaderScalar)) ObjectHeader final
		{
			/// <summary>
			/// Reference counter for strong references.
			/// </summary>
			MetaHeaderScalar MetaField {0};

			/// <summary>
			/// Object size in records.
			/// </summary>
			MetaHeaderScalar Size {0};

			/// <summary>
			/// Type index for type DB.
			/// </summary>
			MetaHeaderScalar TypeId {0};

			/// <summary>
			/// Flag vector for object states.
			/// </summary>
			ObjectFlagVector FlagVector { };

			/// <summary>
			/// Maps this record into the specified memory region.
			/// ! The region must have at least 2 record entries to write to !
			/// Safe alternative is the overload using std::span.
			/// </summary>
			/// <param name="region"></param>
			/// <returns></returns>
			auto MapToRegionUnchecked(Record* region) const -> void;

			/// <summary>
			/// Maps this record into the specified memory region.
			/// ! The region must have at least 2 record entries to write to !
			/// </summary>
			/// <param name="region"></param>
			/// <returns>true if the size of the region was correct and the mapping succeeded, else false.</returns>
			[[nodiscard]]
			auto MapToRegionChecked(std::span<Record> region) const -> bool;

			/// <summary>
			/// Maps this record from the specified memory region.
			/// ! The region must have at least 2 record entries to read from!
			/// Safe alternative is the overload using std::span.
			/// </summary>
			/// <param name="region"></param>
			/// <returns></returns>
			auto MapFromRegionUnchecked(const Record* region) -> void;

			/// <summary>
			/// Maps this record from the specified memory region.
			/// ! The region must have at least 2 record entries to read from!
			/// </summary>
			/// <param name="region"></param>
			/// <returns>true if the size of the region was correct and the mapping succeeded, else false.</returns>
			[[nodiscard]]
			auto MapFromRegionChecked(std::span<const Record> region) -> bool;

			/// <summary>
			/// Map an object header to the region and return the current value of the strong ref count.
			/// </summary>
			/// <param name="region"></param>
			/// <returns>The current value of the strong ref count.</returns>
			[[nodiscard]]
			static constexpr auto ReadMapping_MetaField(const Record* region) -> MetaHeaderScalar;

			/// <summary>
			/// Map an object header to the region and return the current value of the size.
			/// </summary>
			/// <param name="region"></param>
			/// <returns>The current value of the size field.</returns>
			[[nodiscard]]
			static constexpr auto ReadMapping_Size(const Record* region) -> MetaHeaderScalar;

			/// <summary>
			/// Map an object header to the region and return the current value of the type id.
			/// </summary>
			/// <param name="region"></param>
			/// <returns>The current value of the type id.</returns>
			[[nodiscard]]
			static constexpr auto ReadMapping_TypeId(const Record* region) -> MetaHeaderScalar;

			/// <summary>
			/// Map an object header to the region and return the current value of the flag vector.
			/// </summary>
			/// <param name="region"></param>
			/// <returns>The current value of the flag vector.</returns>
			[[nodiscard ]]
			static constexpr auto ReadMapping_FlagVector(const Record* region) -> ObjectFlagVector;

			/// <summary>
			/// Map an object header to the region and writes the value into the strong ref count field.
			/// </summary>
			/// <param name="region"></param>
			/// <param name="metaField">The value to write.</param>
			/// <returns></returns>
			static constexpr auto WriteMapping_MetaField(Record* region, MetaHeaderScalar metaField) -> void;

			/// <summary>
			/// Implicit map the region to an object header and increment the strong reference counter by one.
			/// The region must have at least 2 record entries to read from!
			/// </summary>
			/// <param name="region"></param>
			/// <returns></returns>
			static constexpr auto WriteMapping_IncrementMetaField(Record* region) -> void;

			/// <summary>
			/// Implicit map the region to an object header and decrement the strong reference counter by one.
			/// The region must have at least 2 record entries to read from!
			/// </summary>
			/// <param name="region"></param>
			/// <returns></returns>
			static constexpr auto WriteMapping_DecrementMetaField(Record* region) -> void;

			/// <summary>
			/// Map an object header to the region and writes the value into the size field.
			/// </summary>
			/// <param name="region"></param>
			/// <param name="size">The value to write.</param>
			/// <returns></returns>
			static constexpr auto WriteMapping_Size(Record* region, MetaHeaderScalar size) -> void;

			/// <summary>
			/// Map an object header to the region and writes the value into the type id field.
			/// </summary>
			/// <param name="region"></param>
			/// <param name="typeId">The value to write.</param>
			/// <returns></returns>
			static constexpr auto WriteMapping_TypeId(Record* region, MetaHeaderScalar typeId) -> void;

			/// <summary>
			/// Map an object header to the region and writes the value into the flag vector field.
			/// </summary>
			/// <param name="region"></param>
			/// <param name="flagVector">The value to write.</param>
			/// <returns></returns>
			static constexpr auto WriteMapping_FlagVector(Record* region, ObjectFlagVector flagVector) -> void;

			/// <summary>
			/// Type-pun a region to an object header
			/// using reinterpret_cast. This is bug prone and unsafe.
			/// </summary>
			/// <param name="region"></param>
			/// <returns></returns>
			[[nodiscard]]
			static auto ReadMappedHeaderFromRegion(Record* region) -> ObjectHeader&;

			/// <summary>
			/// The size of each header block field.
			/// </summary>
			static constexpr auto STRIDE {sizeof(MetaHeaderScalar)};

			/// <summary>
			/// The count of header field blocks => 4 (MetaField, WordSize, TypeId, FlagVector)
			/// </summary>
			static constexpr U64 RECORD_BLOCKS {4};

			/// <summary>
			/// The offset in records from the blob base pointer.
			/// </summary>
			static constexpr Uip64 RECORD_OFFSET {STRIDE * RECORD_BLOCKS / sizeof(Record)};

			/// <summary>
			/// The amount of records required to store the header.
			/// </summary>
			static constexpr U32 RECORD_CHUNKS {RECORD_OFFSET};

			static_assert(STRIDE == sizeof(MetaHeaderScalar));
			static_assert(RECORD_BLOCKS == 4);
		};

		static_assert(sizeof(ObjectHeader) == ObjectHeader::RECORD_BLOCKS * ObjectHeader::STRIDE);
		static_assert(sizeof(ObjectHeader) == 32);
		static_assert(sizeof(ObjectHeader) % ObjectHeader::RECORD_BLOCKS == 0); // Ok, ok we know the size must be 16 bytes!
		static_assert(std::is_standard_layout_v<ObjectHeader>);
		static_assert(std::is_trivially_copyable_v<ObjectHeader>);

		NOX_FLATTEN inline auto ObjectHeader::MapToRegionUnchecked
		(
			Record* const region
		) const -> void
		{
			std::memcpy(region, this, sizeof(ObjectHeader));
		}

		NOX_FLATTEN inline auto ObjectHeader::MapToRegionChecked(const std::span<Record> region) const -> bool
		{
			if (std::size(region) < RECORD_BLOCKS)
			{
				[[unlikely]]
					return false;
			}
			return std::memcpy(std::data(region), this, sizeof(ObjectHeader));
		}

		NOX_FLATTEN inline auto ObjectHeader::MapFromRegionUnchecked(const Record* const region) -> void
		{
			std::memcpy(this, region, sizeof(ObjectHeader));
		}

		NOX_FLATTEN inline auto ObjectHeader::MapFromRegionChecked(const std::span<const Record> region) -> bool
		{
			if (std::size(region) < RECORD_BLOCKS)
			{
				[[unlikely]]
					return false;
			}
			return std::memcpy(this, std::data(region), sizeof(ObjectHeader));
		}

		NOX_FLATTEN constexpr auto ObjectHeader::ReadMapping_MetaField(const Record* const region) -> MetaHeaderScalar
		{
			return (*region).AsU64;
		}

		NOX_FLATTEN constexpr auto ObjectHeader::ReadMapping_Size(const Record* const region) -> MetaHeaderScalar
		{
			return (*(region + 1)).AsU64;
		}

		NOX_FLATTEN constexpr auto ObjectHeader::ReadMapping_TypeId(const Record* const region) -> MetaHeaderScalar
		{
			return (*(region + 2)).AsU64;
		}

		NOX_FLATTEN constexpr auto ObjectHeader::ReadMapping_FlagVector(const Record* const region) -> ObjectFlagVector
		{
			const auto flags = ObjectFlagVector
			{
				.Merged = (*(region + 3)).AsU64
			};
			return flags;
		}

		NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_MetaField
		(
			Record* const          region,
			const MetaHeaderScalar metaField
		) -> void
		{
			(*region).AsU64 = metaField;
		}

		NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_IncrementMetaField
		(
			Record* const region
		) -> void
		{
			++(*region).AsU64;
		}

		NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_DecrementMetaField
		(
			Record* const region
		) -> void
		{
			--(*region).AsU64;
		}

		NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_Size
		(
			Record* const          region,
			const MetaHeaderScalar size
		) -> void
		{
			(*(region + 1)).AsU64 = size;
		}

		NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_TypeId
		(
			Record* const          region,
			const MetaHeaderScalar typeId
		) -> void
		{
			(*(region + 2)).AsU64 = typeId;
		}

		NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_FlagVector
		(
			Record* const          region,
			const ObjectFlagVector flagVector
		) -> void
		{
			(*(region + 3)).AsU64 = flagVector.Merged;
		}

		NOX_FLATTEN inline auto ObjectHeader::ReadMappedHeaderFromRegion
		(
			Record* const region
		) -> ObjectHeader&
		{
			return *reinterpret_cast<ObjectHeader*>(region);
		}

		#define MUTATOR
		#define IMMUTATOR

		/// <summary>
		/// Represents any heap allocated object.
		/// </summary>
		class Object final
		{
		public:
			using BlobBlockType = Record;

		private:
			friend class RuntimeObjectAllocator;

			/// <summary>
			/// Full data blob.
			/// Array of records which contains the
			/// object header and the object itself.
			/// The first two records are always the header,
			/// so the allocator must always allocate minimum 2 two records
			/// for the header plus the size in records for the object.
			/// So the blob length will be: ObjectHeader::RECORD_CHUNKS + sizeInRecords
			/// This size must be written into the header field "WordSize"!
			/// </summary>
			BlobBlockType* Blob_ {nullptr};

		public:
			explicit Object(BlobBlockType* blob);

			/// <summary>
			///
			/// </summary>
			/// <returns>The strong reference count field from the object header.</returns>
			[[nodiscard]]
			auto IMMUTATOR HeaderRead_StrongReferenceCount() const -> MetaHeaderScalar;

			/// <summary>
			///
			/// </summary>
			/// <returns>The size of the object in records. The size field from the object header.</returns>
			[[nodiscard]]
			auto IMMUTATOR HeaderRead_BlockSize() const -> MetaHeaderScalar;

			/// <summary>
			///
			/// </summary>
			/// <returns>The type id field from the object header.</returns>
			[[nodiscard]]
			auto IMMUTATOR HeaderRead_TypeId() const -> MetaHeaderScalar;

			/// <summary>
			///
			/// </summary>
			/// <returns>The flag vector field from the object header.</returns>
			[[nodiscard]]
			auto IMMUTATOR Header_ReadFlagVector() const -> ObjectFlagVector;

			/// <summary>
			/// Writes the value into the strong ref count header field.
			/// </summary>
			/// <param name="MetaField">The new value to write.</param>
			/// <returns></returns>
			auto MUTATOR HeaderWrite_MetaField(MetaHeaderScalar metaField) const -> void;

			/// <summary>
			/// Increments the object header strong reference counter by one.
			/// </summary>
			/// <returns></returns>
			auto MUTATOR HeaderWrite_IncrementMetaField() const -> void;

			/// <summary>
			/// Decrements the object header strong reference counter by one.
			/// </summary>
			/// <returns></returns>
			auto MUTATOR HeaderWrite_DecrementMetaField() const -> void;

			/// <summary>
			/// Same as HeaderWrite_IncrementMetaField()
			/// </summary>
			/// <returns></returns>
			auto MUTATOR operator ++() const -> void;

			/// <summary>
			/// Same as HeaderWrite_DecrementMetaField()
			/// </summary>
			/// <returns></returns>
			auto MUTATOR operator --() const -> void;

			/// <summary>
			/// Same as HeaderWrite_IncrementMetaField()
			/// </summary>
			/// <returns></returns>
			auto MUTATOR operator ++(int) const -> void;

			/// <summary>
			/// Same as HeaderWrite_DecrementMetaField()
			/// </summary>
			/// <returns></returns>
			auto MUTATOR operator --(int) const -> void;

			/// <summary>
			/// Writes the value of size into the WordSize object header field.
			/// </summary>
			/// <param name="size">The new value to write.</param>
			/// <returns></returns>
			auto MUTATOR HeaderWrite_Size(MetaHeaderScalar size) const -> void;

			/// <summary>
			/// Writes the value of typeId into the TypeId object header field.
			/// </summary>
			/// <param name="typeId">The new value to write.</param>
			/// <returns></returns>
			auto MUTATOR HeaderWrite_TypeId(MetaHeaderScalar typeId) const -> void;

			/// <summary>
			/// Writes the value of flagVector into the ObjectFlags object header field.
			/// </summary>
			/// <param name="flagVector">The new value to write.</param>
			/// <returns></returns>
			auto MUTATOR HeaderWrite_FlagVector(ObjectFlagVector flagVector) const -> void;

			/// <summary>
			/// Get the raw object header pointer.
			/// </summary>
			/// <returns>The object header pointer.</returns>
			[[nodiscard]]
			auto IMMUTATOR QueryRawHeader() const -> BlobBlockType*;

			/// <summary>
			/// Get the object header.
			/// </summary>
			/// <returns>The object header.</returns>
			[[nodiscard]]
			auto IMMUTATOR QueryHeader() const -> ObjectHeader;

			/// <summary>
			/// Get underlying object block.
			/// </summary>
			/// <returns>The begin pointer of the underlying object block.</returns>
			[[nodiscard]]
			auto IMMUTATOR LookupObjectBlock() const -> BlobBlockType*;

			/// <summary>
			/// Get underlying object block end iterator.
			/// </summary>
			/// <returns>The end pointer of the underlying object block.</returns>
			[[nodiscard]]
			auto IMMUTATOR LookupObjectBlockEnd() const -> BlobBlockType*;

			/// <summary>
			/// Checks if the underlying object block is null, but the object header is null.
			/// </summary>
			/// <returns>True if the underlying object is null, else false.</returns>
			[[nodiscard]]
			auto IMMUTATOR IsUnderlyingObjectBlockNull() const -> bool;

			/// <summary>
			/// Checks if the whole data blob (underlying object) and the object header is null.
			/// </summary>
			/// <returns>true if the whole data blob (underlying object) and the object header is null, else false.</returns>
			[[nodiscard]]
			auto IMMUTATOR IsBlobNull() const -> bool;

			/// <summary>
			/// The size in records of the whole data blob:
			/// header + object
			/// </summary>
			/// <returns>The size in records of the object header plus the size of object it self.</returns>
			[[nodiscard]]
			auto IMMUTATOR BlobSize() const -> U64;

			/// <summary>
			/// The size in bytes of the whole data blob:
			/// header + object
			/// </summary>
			/// <returns>The size in bytes of the whole object header plus the whole size of object it self.</returns>
			[[nodiscard]]
			auto IMMUTATOR BlobSizeInBytes() const -> U64;

			/// <summary>
			/// Returns the size of the object block in bytes.
			/// Same as HeaderRead_BlockSize() * sizeof(Common::Record)
			/// </summary>
			/// <returns></returns>
			[[nodiscard]]
			auto IMMUTATOR ObjectBlockSizeInBytes() const -> U64;

			/// <summary>
			/// Tries to copy the object block into the buffer.
			/// The buffer must have the same size or must be larger, if
			/// not it will return false.
			/// </summary>
			/// <param name="buffer">The target buffer.</param>
			/// <returns>True if the size was large enough, else false.</returns>
			[[nodiscard]]
			auto IMMUTATOR ShallowCopyObjectBlockToBuffer(std::span<BlobBlockType> buffer) const -> bool;

			/// <summary>
			/// Resizes the buffer to the size of the object block and copies the whole
			/// object block into the vector.
			/// </summary>
			/// <param name="buffer">The target buffer.</param>
			/// <returns></returns>
			auto IMMUTATOR ShallowCopyObjectBlockToBuffer(std::vector<BlobBlockType>& buffer) const -> void;

			/// <summary>
			/// SLT-Compat
			/// Required for range loops, same as begin(object)
			/// </summary>
			/// <returns>Begin iterator.</returns>
			[[nodiscard]]
			// ReSharper disable once CppInconsistentNaming
			auto IMMUTATOR begin() const -> BlobBlockType*;

			/// <summary>
			/// SLT-Compat
			/// Required for range loops, same as end(object)
			/// </summary>
			/// <returns>End iterator.</returns>
			[[nodiscard]]
			// ReSharper disable once CppInconsistentNaming
			auto IMMUTATOR end() const -> BlobBlockType*;

			/// <summary>
			/// Resizes the vector to the correct size
			/// and copies the whole object (header + object block) into it.
			/// </summary>
			/// <param name="buffer"></param>
			/// <returns></returns>
			auto IMMUTATOR CopyBlob(std::vector<BlobBlockType>& buffer) const -> void;

			/// <summary>
			/// Lookup object block.
			/// </summary>
			/// <returns></returns>
			auto IMMUTATOR operator *() const -> BlobBlockType*;

			/// <summary>
			/// Lookup object block.
			/// </summary>
			/// <returns></returns>
			auto IMMUTATOR operator ->() const -> BlobBlockType*;

			/// <summary>
			/// Lookup object block end.
			/// </summary>
			/// <returns></returns>
			auto IMMUTATOR operator ~() const -> BlobBlockType*;

			/// <summary>
			/// Unchecked subscript in object block.
			/// </summary>
			/// <param name="idx"></param>
			/// <returns></returns>
			auto IMMUTATOR operator [](U64 idx) -> BlobBlockType&;

			/// <summary>
			/// Unchecked subscript in object block.
			/// </summary>
			/// <param name="idx"></param>
			/// <returns></returns>
			auto IMMUTATOR operator [](U64 idx) const -> BlobBlockType;

			/// <summary>
			/// Sets the object block to zero - all object fields will be zero.
			/// </summary>
			/// <returns>std::memset return ptr (start of block)</returns>
			auto MUTATOR ZeroObjectBlock() const -> void;

			/// <summary>
			/// Compares the pointer values of a and b.
			/// This only compares pointers, not values.
			/// For value compare, refer to DeepCompare.
			/// </summary>
			/// <param name="a">The first object.</param>
			/// <param name="b">The second object to compare to first.</param>
			/// <returns>True if the two objects point to the same object blob, else false.</returns>
			[[nodiscard]]
			static auto ShallowCmp(Object a, Object b) -> bool;

			/// <summary>
			/// Compares the values of the object block of the two objects.
			/// This is overkill for most cases, pointer comparison can be enough.
			/// </summary>
			/// <param name="a">The first object.</param>
			/// <param name="b">The second object to compare to first.</param>
			/// <returns>True if the object block data is equal, else false.</returns>
			[[nodiscard]]
			static auto DeepCmp(Object a, Object b) -> bool;

			/// <summary>
			/// Compares the values of the object block of the two objects.
			/// This is overkill for most cases, pointer comparison can be enough.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="a">The first object.</param>
			/// <param name="b">The second object to compare to first.</param>
			/// <returns>True if all values of a are equal than all values of b, else false.</returns>
			template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
			[[nodiscard]]
			static auto DeepValueCmp_Equal(Object a, Object b) -> bool;


			/// <summary>
			/// Compares the values of the object block of the two objects.
			/// This is overkill for most cases, pointer comparison can be enough.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="a">The first object.</param>
			/// <param name="b">The second object to compare to first.</param>
			/// <returns>True if all values of a are not equal than all values of b, else false.</returns>
			template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
			[[nodiscard]]
			static auto DeepValueCmp_NotEqual(Object a, Object b) -> bool;

			/// <summary>
			/// Compares the values of the object block of the two objects.
			/// This is overkill for most cases, pointer comparison can be enough.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="a">The first object.</param>
			/// <param name="b">The second object to compare to first.</param>
			/// <returns>True if all values of a are less than all values of b, else false.</returns>
			template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
			[[nodiscard]]
			static auto DeepValueCmp_Less(Object a, Object b) -> bool;

			/// <summary>
			/// Compares the values of the object block of the two objects.
			/// This is overkill for most cases, pointer comparison can be enough.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="a">The first object.</param>
			/// <param name="b">The second object to compare to first.</param>
			/// <returns>True if all values of a are less equal than all values of b, else false.</returns>
			template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
			[[nodiscard]]
			static auto DeepValueCmp_LessEqual(Object a, Object b) -> bool;

			/// <summary>
			/// Compares the values of the object block of the two objects.
			/// This is overkill for most cases, pointer comparison can be enough.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="a">The first object.</param>
			/// <param name="b">The second object to compare to first.</param>
			/// <returns>True if all values of a are greater than all values of b, else false.</returns>
			template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
			[[nodiscard]]
			static auto DeepValueCmp_Greater(Object a, Object b) -> bool;

			/// <summary>
			/// Compares the values of the object block of the two objects.
			/// This is overkill for most cases, pointer comparison can be enough.
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="a">The first object.</param>
			/// <param name="b">The second object to compare to first.</param>
			/// <returns>True if all values of a are greater or equal than all values of b, else false.</returns>
			template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
			[[nodiscard]]
			static auto DeepValueCmp_GreaterEqual(Object a, Object b) -> bool;

			/// <summary>
			/// Deleter for unique objects allocated with std::unique_ptr.
			/// </summary>
			struct UniquePtrObjectDeleter final
			{
				inline auto operator()(Object* const target) const -> void
				{
					delete[] target->Blob_;
					delete target;
				}
			};

			/// <summary>
			/// Allocates a mock object for use in tests or debug stuff.
			/// Do not use for real allocation!
			/// </summary>
			/// <param name="sizeInRecords">The size of the object in RECORDS NOT in BYTES</param>
			/// <returns>The mock object.</returns>
			static auto AllocateUnique(U32 sizeInRecords) -> std::unique_ptr<Object, UniquePtrObjectDeleter>;
		};

		static_assert(sizeof(Object) == sizeof(Object::BlobBlockType*));
		static_assert(std::is_trivially_copyable_v<Object>);
		static_assert(std::is_standard_layout_v<Object>);

		inline Object::Object(BlobBlockType* const blob) : Blob_(blob) {}

		/// <summary>
		/// Prevent using with invalid type.
		/// Allowed are the record types:
		/// U64
		/// I64
		/// F64
		/// char32_t
		/// void*
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns></returns>
		template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
		NOX_FLATTEN inline auto Object::DeepValueCmp_Equal([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) -> bool
		{
			return false;
		}

		/// <summary>
		/// Specialization for bitwise compare of U64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are equal, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Equal<U64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of I64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are equal, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Equal<I64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of F64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are equal, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Equal<F64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of char32_t.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are equal, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Equal<char32_t>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of void*.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are equal, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Equal<void*>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of void*.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are equal, else false.</returns>
		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_Equal<char32_t>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Equal<U64>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of void*.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are equal, else false.</returns>
		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_Equal<void*>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Equal<U64>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of U64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all not equal, else false.</returns>
		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_NotEqual<U64>(const Object a, const Object b) -> bool
		{
			return !DeepValueCmp_Equal<U64>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of I64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all not equal, else false.</returns>
		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_NotEqual<I64>(const Object a, const Object b) -> bool
		{
			return !DeepValueCmp_Equal<I64>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of F64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all not equal, else false.</returns>
		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_NotEqual<F64>(const Object a, const Object b) -> bool
		{
			return !DeepValueCmp_Equal<F64>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of char32_t.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all not equal, else false.</returns>
		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_NotEqual<char32_t>(const Object a, const Object b) -> bool
		{
			return !DeepValueCmp_Equal<char32_t>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of void*.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all not equal, else false.</returns>
		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_NotEqual<void*>(const Object a, const Object b) -> bool
		{
			return !DeepValueCmp_Equal<void*>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of U64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Less<U64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of I64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less else false.</returns>
		template <>
		auto Object::DeepValueCmp_Less<I64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of F64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Less<F64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of char32_t.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Less<char32_t>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of void*.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Less<void*>(Object a, Object b) -> bool;

		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_Less<char32_t>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Less<U64>(a, b);
		}

		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_Less<void*>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Less<U64>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of U64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_LessEqual<U64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of I64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less else false.</returns>
		template <>
		auto Object::DeepValueCmp_LessEqual<I64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of F64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_LessEqual<F64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of char32_t.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_LessEqual<char32_t>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of void*.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_LessEqual<void*>(Object a, Object b) -> bool;

		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_LessEqual<char32_t>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Less<U64>(a, b);
		}

		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_LessEqual<void*>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Less<U64>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of U64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Greater<U64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of I64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less else false.</returns>
		template <>
		auto Object::DeepValueCmp_Greater<I64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of F64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Greater<F64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of char32_t.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Greater<char32_t>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of void*.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_Greater<void*>(Object a, Object b) -> bool;

		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_Greater<char32_t>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Less<U64>(a, b);
		}

		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_Greater<void*>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Less<U64>(a, b);
		}

		/// <summary>
		/// Specialization for bitwise compare of U64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_GreaterEqual<U64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of I64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less else false.</returns>
		template <>
		auto Object::DeepValueCmp_GreaterEqual<I64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of F64.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_GreaterEqual<F64>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of char32_t.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_GreaterEqual<char32_t>(Object a, Object b) -> bool;

		/// <summary>
		/// Specialization for bitwise compare of void*.
		/// </summary>
		/// <param name="a"></param>
		/// <param name="b"></param>
		/// <returns>True if the two object values are all less, else false.</returns>
		template <>
		auto Object::DeepValueCmp_GreaterEqual<void*>(Object a, Object b) -> bool;

		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_GreaterEqual<char32_t>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Less<U64>(a, b);
		}

		template <>
		NOX_FLATTEN inline auto Object::DeepValueCmp_GreaterEqual<void*>(const Object a, const Object b) -> bool
		{
			return DeepValueCmp_Less<U64>(a, b);
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::QueryRawHeader() const -> BlobBlockType*
		{
			NOX_DBG_PAS_TRUE(this->Blob_ != nullptr, "Blob is null");
			return this->Blob_;
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::QueryHeader() const -> ObjectHeader
		{
			ObjectHeader header;
			header.MapFromRegionUnchecked(this->QueryRawHeader());
			return header;
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::LookupObjectBlock() const -> BlobBlockType*
		{
			NOX_DBG_PAS_TRUE(this->Blob_ != nullptr, "Blob is null");
			return this->Blob_ + ObjectHeader::RECORD_OFFSET;
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::LookupObjectBlockEnd() const -> BlobBlockType*
		{
			NOX_DBG_PAS_TRUE(this->HeaderRead_BlockSize() > 0, "Invalid header block size");
			return this->LookupObjectBlock() + this->HeaderRead_BlockSize();
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::IsUnderlyingObjectBlockNull() const -> bool
		{
			return this->LookupObjectBlock() == nullptr;
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::IsBlobNull() const -> bool
		{
			return this->Blob_ == nullptr;
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::BlobSize() const -> U64
		{
			return ObjectHeader::RECORD_CHUNKS + ObjectHeader::ReadMapping_Size(this->QueryRawHeader());
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::BlobSizeInBytes() const -> U64
		{
			return BlobSize() * sizeof(Record);
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::ObjectBlockSizeInBytes() const -> U64
		{
			return this->HeaderRead_BlockSize() * sizeof(Record);
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::HeaderRead_StrongReferenceCount() const -> MetaHeaderScalar
		{
			return ObjectHeader::ReadMapping_MetaField(this->QueryRawHeader());
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::HeaderRead_BlockSize() const -> MetaHeaderScalar
		{
			return ObjectHeader::ReadMapping_Size(this->QueryRawHeader());
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::HeaderRead_TypeId() const -> MetaHeaderScalar
		{
			return ObjectHeader::ReadMapping_TypeId(this->QueryRawHeader());
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::Header_ReadFlagVector() const -> ObjectFlagVector
		{
			return ObjectHeader::ReadMapping_FlagVector(this->QueryRawHeader());
		}

		NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_IncrementMetaField() const -> void
		{
			ObjectHeader::WriteMapping_IncrementMetaField(this->QueryRawHeader());
		}

		NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_DecrementMetaField() const -> void
		{
			ObjectHeader::WriteMapping_DecrementMetaField(this->QueryRawHeader());
		}

		NOX_FLATTEN inline auto MUTATOR Object::operator++() const -> void
		{
			this->HeaderWrite_IncrementMetaField();
		}

		NOX_FLATTEN inline auto MUTATOR Object::operator--() const -> void
		{
			this->HeaderWrite_DecrementMetaField();
		}

		NOX_FLATTEN inline auto MUTATOR Object::operator++(int) const -> void
		{
			this->HeaderWrite_IncrementMetaField();
		}

		NOX_FLATTEN inline auto MUTATOR Object::operator--(int) const -> void
		{
			this->HeaderWrite_DecrementMetaField();
		}

		NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_MetaField(const MetaHeaderScalar metaField) const -> void
		{
			ObjectHeader::WriteMapping_MetaField(this->QueryRawHeader(), metaField);
		}

		NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_Size(const MetaHeaderScalar size) const -> void
		{
			ObjectHeader::WriteMapping_Size(this->QueryRawHeader(), size);
		}

		NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_TypeId(const MetaHeaderScalar typeId) const -> void
		{
			ObjectHeader::WriteMapping_TypeId(this->QueryRawHeader(), typeId);
		}

		NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_FlagVector(const ObjectFlagVector flagVector) const -> void
		{
			ObjectHeader::WriteMapping_FlagVector(this->QueryRawHeader(), flagVector);
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::operator*() const -> BlobBlockType*
		{
			return this->LookupObjectBlock();
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::operator->() const -> BlobBlockType*
		{
			return this->LookupObjectBlock();
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::operator~() const -> BlobBlockType*
		{
			return this->LookupObjectBlockEnd();
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::operator[](const U64 idx) -> BlobBlockType&
		{
			return *(this->LookupObjectBlock() + idx);
		}

		NOX_FLATTEN inline auto IMMUTATOR Object::operator[](const U64 idx) const -> BlobBlockType
		{
			return *(this->LookupObjectBlock() + idx);
		}

		// ReSharper disable once CppInconsistentNaming
		NOX_FLATTEN inline auto IMMUTATOR Object::begin() const -> BlobBlockType*
		{
			return this->LookupObjectBlock();
		}

		// ReSharper disable once CppInconsistentNaming
		NOX_FLATTEN inline auto IMMUTATOR Object::end() const -> BlobBlockType*
		{
			return this->LookupObjectBlockEnd();
		}

		NOX_FLATTEN inline auto MUTATOR Object::ZeroObjectBlock() const -> void
		{
			std::memset(this->LookupObjectBlock(), 0, this->ObjectBlockSizeInBytes());
		}

		NOX_FLATTEN inline auto Object::ShallowCmp(const Object a, const Object b) -> bool
		{
			return a.Blob_ == b.Blob_;
		}

		/// <summary>
		/// STL Compat Overload
		/// Iterate over object block fields without header.
		/// Begin iterator.
		/// </summary>
		/// <param name="object"></param>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		NOX_FLATTEN inline auto begin(const Object object) -> Object::BlobBlockType*
		{
			return object.LookupObjectBlock();
		}

		/// <summary>
		/// STL Compat Overload
		/// Iterate over object block fields without header.
		/// End iterator (one element after the last one)
		/// </summary>
		/// <param name="object"></param>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		NOX_FLATTEN inline auto end(const Object object) -> Object::BlobBlockType*
		{
			return object.LookupObjectBlockEnd();
		}

		#undef MUTATOR
		#undef IMMUTATOR
	}
}
