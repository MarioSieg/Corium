// File: Foundation.hpp
// Author: Mario
// Created: 06.06.2021 5:38 PM
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
#include <atomic>
#include <bit>
#include <climits>
#include <csignal>
#include <cstddef>
#include <cstdint>
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
#include <string>
#include <string_view>
#include <span>
#include <type_traits>
#include <unordered_set>
#include <variant>

namespace Nominax
{
	#define NOX_OS_WINDOWS	false
	#define NOX_OS_MAC		false
	#define NOX_OS_LINUX	false
	#define NOX_OS_ANDROID	false
	#define NOX_OS_IOS		false
	#define NOX_ARCH_X86_64	false
	#define NOX_ARCH_ARM_64	false
	#define NOX_RELEASE		false
	#define NOX_DEBUG		false
	#define NOX_COM_GCC		false
	#define NOX_COM_CLANG	false
	#define NOX_COM_MINGW	false

	#if NDEBUG
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
	static_assert(sizeof(F32) == 4);
	static_assert(sizeof(F64) == 8);
}

#if NOX_OS_WINDOWS
#	include <malloc.h>
#else
#	include <alloca.h>
#endif

namespace Nominax::Common
{
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
	///
	/// </summary>
	#define NOX_VERBOSE_ALLOCATOR NOX_DEBUG


	#define NOX_OPT_USE_ZERO_EPSILON NOX_DEBUG

	/// <summary>
	/// If enabled, the jump table addresses are directly mapped as pointers into the byte-code signals.
	/// </summary>
	#if NOX_RELEASE && !defined(NOX_TEST)
	#	define NOX_OPT_EXECUTION_ADDRESS_MAPPING true
	#else
	#	define NOX_OPT_EXECUTION_ADDRESS_MAPPING false
	#endif

	#define NOX_EXPECT_VALUE(x, expect)         __builtin_expect(( x ), ( expect ))
	#define NOX_HOT                             __attribute__((hot))
	#define NOX_COLD                            __attribute__((cold))
	#define NOX_FORCE_INLINE                    __attribute__((always_inline))
	#define NOX_NEVER_INLINE                    __attribute__((noinline))
	#define NOX_FLATTEN                         __attribute__((flatten))
	#define NOX_PURE                            __attribute__((flatten))
	#define NOX_ALLOC_SIZE(x)                   __attribute__((alloc_size(( x ))))
	#define NOX_RESTRICT                        __restrict__

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
	constexpr auto UniformChunkSplit(const std::size_t chunkCount, const Iter begin, const Iter end, Func&& func, Args&&...args) -> void
	{
		using ValueType = const typename std::iterator_traits<Iter>::value_type;
		using Span = std::span<ValueType>;

		const auto length {std::distance(begin, end)};
		const bool mismatch {chunkCount <= 1 || static_cast<std::size_t>(length) % chunkCount};

		if (mismatch)
		{
			const Span range {begin, end};
			std::invoke(std::forward<Func>(func), range, static_cast<std::size_t>(0), std::forward<Args>(args)...);
		}
		else
		{
			const auto chunkSize {static_cast<std::size_t>(length) / chunkCount};
			for (std::size_t i {0}; i < chunkCount; ++i)
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
	constexpr auto UniformChunkSplit(const std::size_t chunkCount, const std::span<const T> range, Func&& func, Args&&...args) -> void
	{
		UniformChunkSplit<decltype(std::begin(range)), Func, Args...>(chunkCount, std::begin(range), std::end(range), std::forward<Func>(func), std::forward(args)...);
	}

	/// <summary>
	///  std::visit auto overload helper
	/// </summary>
	/// <typeparam name="...Ts">The call types.</typeparam>
	template <typename... Ts>
	struct Overloaded : Ts...
	{
		using Ts::operator()...;
	};

	template <typename... Ts>
	Overloaded(Ts&&...) -> Overloaded<Ts...>;

	/// <summary>
	/// Computes the index of T inside the variant type.
	/// </summary>
	/// <typeparam name="VariantType"></typeparam>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template <typename VariantType, typename T, std::size_t Index = 0>
	[[nodiscard]]
	constexpr auto VariantIndexOf() -> std::size_t
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
	/// Restrict stack allocations type.
	/// </summary>
	template <typename T, const std::size_t C>
	concept StackAlloca = requires
	{
		std::is_trivial_v<T>; // trivial types only
		C != 0;               // must at least be one
		sizeof(T) != 0;       // must at least be one
		sizeof(T) * C < 1024; // no more than 1KB
	};

	/// <summary>
	/// Allocate small structure/array on stack using alloca.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template <typename T, const std::size_t Count = 1> requires StackAlloca<T, Count>
	[[nodiscard]]
	NOX_FORCE_INLINE inline auto StackAlloc() -> T*
	{
		#if NOX_OS_WINDOWS && !NOX_COM_GCC
		return static_cast<T*>(::_alloca(sizeof(T) * Count));
		#else
		return static_cast<T*>(::alloca(sizeof(T) * Count));
		#endif
	}

	/// <summary>
	/// Returns true if the alignment is valid,
	/// which means it is a power of two and not zero.
	/// </summary>
	/// <param name="alignment"></param>
	/// <returns></returns>
	[[nodiscard]]
	constexpr auto IsAlignmentValid(const std::size_t alignment) -> bool
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
	constexpr auto IsAlignedTo(void* const ptr, const std::size_t alignment) -> bool
	{
		return std::bit_cast<std::uintptr_t>(ptr) % alignment == 0 && IsAlignmentValid(alignment);
	}

	/// <summary>
	/// Checks is the address of the pointer is aligned to specified alignment,
	/// </summary>
	/// <param name="ptr">The address to check.</param>
	/// <param name="alignment">The alignment the address should have.</param>
	/// <returns>True if valid and corresponding alignment, else false.</returns>
	[[nodiscard]]
	constexpr auto IsAlignedTo(const std::uintptr_t ptr, const std::size_t alignment) -> bool
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
	constexpr auto ComputeMissingAlignmentOffset(void* const ptr, const std::size_t alignment) -> std::size_t
	{
		const auto misalignment = std::bit_cast<std::uintptr_t>(ptr) & (alignment - 1);
		return misalignment ? alignment - misalignment : 0;
	}

	/// <summary>
	/// Compute the required offset to align the pointer to the given alignment.
	/// The specified alignment must be valid, check with IsAlignmentValid() if needed. 
	/// </summary>
	/// <param name="ptr">The pointer address. Can be nullptr!</param>
	/// <param name="alignment">The alignment, which must be valid.</param>
	/// <returns>The required offset.</returns>
	constexpr auto ComputeMissingAlignmentOffset(const std::uintptr_t ptr, const std::size_t alignment) -> std::size_t
	{
		return ComputeMissingAlignmentOffset(std::bit_cast<void*>(ptr), alignment);
	}

	/// <summary>
	/// Computes the minimum required alignment for an
	/// object of the specified size.
	/// </summary>
	/// <param name="size"></param>
	/// <returns></returns>
	inline auto ComputeMinAlignmentRequiredForSize(const std::size_t size) -> std::size_t
	{
		return size >= alignof(std::max_align_t) ? alignof(std::max_align_t) : static_cast<std::size_t>(1) << ILog2(size);
	}

	constexpr U64 KB {1000};
	constexpr U64 MB {KB * KB};
	constexpr U64 GB {KB * KB * KB};
	constexpr U64 TB {KB * KB * KB * KB};
	constexpr U64 PB {KB * KB * KB * KB * KB};

	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Bytes2Gigabytes(T bytes) -> T
	{
		bytes = std::clamp<decltype(bytes)>(bytes, 1, bytes);
		return bytes / static_cast<T>(KB) / static_cast<T>(KB) / static_cast<T>(KB);
	}

	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Bytes2Megabytes(T bytes) -> T
	{
		bytes = std::clamp<decltype(bytes)>(bytes, 1, bytes);
		return bytes / static_cast<T>(KB) / static_cast<T>(KB);
	}

	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Bytes2Kilobytes(T bytes) -> T
	{
		bytes = std::clamp<decltype(bytes)>(bytes, 1, bytes);
		return bytes / static_cast<T>(KB);
	}

	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Gigabytes2Bytes(const T gigabytes) -> T
	{
		return gigabytes * static_cast<T>(KB) * static_cast<T>(KB) * static_cast<T>(KB);
	}

	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Megabytes2Bytes(const T megabytes) -> T
	{
		return megabytes * static_cast<T>(KB) * static_cast<T>(KB);
	}

	template <typename T> requires std::is_integral_v<T> || std::is_floating_point_v<T>
	[[nodiscard]]
	constexpr auto Kilobytes2Bytes(const T kilobytes) -> T
	{
		return kilobytes * static_cast<T>(KB);
	}

	/// <summary>
	/// Generic runtime allocator interface.
	/// </summary>
	class IAllocator
	{
	public:
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
		virtual auto Allocate(void*& out, std::size_t size) const -> void;

		/// <summary>
		/// Raw reallocate like realloc().
		/// </summary>
		/// <param name="out">Output pointer.</param>
		/// <param name="size">The size of the block in bytes.</param>
		/// <returns></returns>
		virtual auto Reallocate(void*& out, std::size_t size) const -> void;

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
		virtual auto AllocateAligned(void*& out, std::size_t size, std::size_t alignment) const -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="out"></param>
		/// <param name="alignment"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		virtual auto ReallocateAligned(void*& out, std::size_t size, std::size_t alignment) const -> void;

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
		virtual auto Valloc(void*& out, std::size_t size) const -> void;

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
		virtual auto Allocate(void*& out, std::size_t size) const -> void override;

		/// <summary>
		/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		virtual auto Reallocate(void*& out, std::size_t size) const -> void override;

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
		virtual auto AllocateAligned(void*& out, std::size_t size, std::size_t alignment) const -> void override;

		/// <summary>
		/// Call the equivalent RuntimeAllocator (superclass) method and print debug info.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="size"></param>
		/// <param name="alignment"></param>
		/// <returns></returns>
		virtual auto ReallocateAligned(void*& out, std::size_t size, std::size_t alignment) const -> void override;

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
		#if NOX_DEBUG && NOX_DBG_ALLOC
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
	struct AtomicState final
	{
		/// <summary>
		/// Underlying value type of enum.
		/// </summary>
		using ValueType = std::underlying_type_t<std::decay_t<T>>;

		static_assert(std::atomic<ValueType>::is_always_lock_free);

	private:
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
	/// Fast, platform dependent implementation for a bitwise left rotation.
	/// </summary>
	[[nodiscard]] NOX_FORCE_INLINE NOX_PURE inline auto Rol32
	(
		U32      value,
		const U8 shift
	) -> U32
	{
		#if NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64 && !NOX_COM_GCC
		return _rotl(value, shift);
		#elif !NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64
		__asm__ __volatile__
		(
			"roll %%cl, %0"
			: "=r"(value)
			: "0" (value), "c"(shift)
		);
		return value;
		#else
		return std::rotl<decltype(value)>(value, shift);
		#endif
	}

	/// <summary>
	/// Fast, platform dependent implementation for a bitwise right rotation.
	/// </summary>
	[[nodiscard]] NOX_FORCE_INLINE NOX_PURE inline auto Ror32
	(
		U32      value,
		const U8 shift
	) -> U32
	{
		#if NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64 && !NOX_COM_GCC
		return _rotr(value, shift);
		#elif !NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64
		__asm__ __volatile__
		(
			"rorl %%cl, %0"
			: "=r"(value)
			: "0" (value), "c"(shift)
		);
		return value;
		#else
		return std::rotr<decltype(value)>(value, shift);
		#endif
	}

	/// <summary>
	/// Fast, platform dependent implementation for a bitwise left rotation.
	/// </summary>
	[[nodiscard]] NOX_FORCE_INLINE NOX_PURE inline auto Rol64
	(
		U64      value,
		const U8 shift
	) -> U64
	{
		#if NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64 && !NOX_COM_GCC
		return _rotl64(value, shift);
		#elif !NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64
		__asm__ __volatile__
		(
			"rolq %%cl, %0"
			: "=r"(value)
			: "0" (value), "c"(shift)
		);
		return value;
		#else
		return std::rotl<U64>(value, shift);
		#endif
	}

	/// <summary>
	/// Fast, platform dependent implementation for a bitwise right rotation.
	/// </summary>
	[[nodiscard]] NOX_FORCE_INLINE NOX_PURE inline auto Ror64
	(
		U64      value,
		const U8 shift
	) -> U64
	{
		#if NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64 && !NOX_COM_GCC
		return _rotr64(value, shift);
		#elif !NOX_OS_WINDOWS && NOX_USE_ARCH_OPT && NOX_ARCH_X86_64
		__asm__ __volatile__
		(
			"rorq %%cl, %0"
			: "=r"(value)
			: "0" (value), "c"(shift)
		);
		return value;
		#else
		return std::rotr<U64>(value, shift);
		#endif
	}

	/// <summary>
	/// Trigger a breakpoint, works in release mode too.
	/// Good for debugging release code or looking at assembler.
	/// </summary>
	NOX_FORCE_INLINE NOX_COLD inline auto BreakpointInterrupt() -> void
	{
		#if NOX_ARCH_X86_64
		__asm__ __volatile__("int3");
		#elif NOX_ARCH_ARM_64
		#if NOX_OS_MAC || NOX_OS_IOS
			__asm__ __volatile__("trap");
		#else
			__asm__ __volatile__("bkpt 0");
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
				__asm__ __volatile__("" : "+r,m"(x) :: "memory");
		#else
		__asm__ __volatile__("" : "+m,r"(x) :: "memory");
		#endif
	}

	/// <summary>
	/// Prevents the compiler from optimizing away the value.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="x"></param>
	/// <returns></returns>
	template <typename T>
	inline auto DisOpt(const T& x) -> void
	{
		__asm__ __volatile__("" : "r,m"(x) :: "memory");
	}

	// @formatter:off

	/// <summary>
	/// Insert memory read fence barrier.
	/// Force the compiler to flush queued writes to global memory.
	/// </summary>
	[[maybe_unused]]
	NOX_FORCE_INLINE inline auto ReadFence()  -> void
	{
		__asm__ __volatile__("" : : : "memory");
	}

	/// <summary>
	/// Insert memory write fence barrier.
	/// Force the compiler to flush queued writes to global memory.
	/// </summary>
	[[maybe_unused]]
	NOX_FORCE_INLINE inline auto WriteFence()  -> void
	{
		__asm__ __volatile__("" : : : "memory");
	}

	/// <summary>
	/// Insert memory read-write fence barrier.
	/// Force the compiler to flush queued writes to global memory.
	/// </summary>
	[[maybe_unused]]
	NOX_FORCE_INLINE inline auto ReadWriteFence()  -> void
	{
		__asm__ __volatile__("" : : : "memory");
	}

	// @formatter:on

	/// <summary>
	/// No operation LOL
	/// </summary>
	NOX_FORCE_INLINE NOX_COLD inline auto NoOperation() -> void
	{
		__asm__ __volatile__("nop");
	}

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
	constexpr auto ZERO_TOLERANCE {1e-6}; // 8 * 1.19209290E-07F

	/// <summary>
	/// Returns true if x is zero, else false.
	/// </summary>
	/// <param name="x">The number to check for zero.</param>
	/// <returns>True if x is zero, else false.</returns>
	NOX_FLATTEN NOX_PURE inline auto F64IsZero(const F64 x) -> bool
	{
		return std::abs(x) < ZERO_TOLERANCE;
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
	constexpr U32 MAX_ULPS {4};

	/// <summary>
	/// Bit count inside F64.
	/// </summary>
	constexpr auto BIT_COUNT {8 * sizeof(F64)};

	/// <summary>
	/// Fraction bit count.
	/// </summary>
	constexpr auto FRACTION_BITS {std::numeric_limits<F64>::digits - 1};

	/// <summary>
	/// Exponent bit count.
	/// </summary>
	constexpr auto EXPONENT_BITS {BIT_COUNT - 1 - FRACTION_BITS};

	/// <summary>
	/// Mask to extract sign bit.
	/// </summary>
	constexpr auto SIGN_MASK {UINT64_C(1) << (BIT_COUNT - 1)};

	/// <summary>
	/// Mask to extract fraction.
	/// </summary>
	constexpr auto FRACTION_MASK {~UINT64_C(0) >> (EXPONENT_BITS + 1)};

	/// <summary>
	/// Mask to extract exponent.
	/// </summary>
	constexpr auto EXPONENT_MASK {~(SIGN_MASK | FRACTION_MASK)};

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

	NOX_FLATTEN NOX_PURE constexpr auto ExponentBitsOf(const F64 x) -> U64
	{
		return EXPONENT_MASK & BitsOf(x);
	}

	NOX_FLATTEN NOX_PURE constexpr auto FractionBitsOf(const F64 x) -> U64
	{
		return FRACTION_MASK & BitsOf(x);
	}

	NOX_FLATTEN NOX_PURE constexpr auto SignBitOf(const F64 x) -> U64
	{
		return SIGN_MASK & BitsOf(x);
	}

	/// <summary>
	/// Returns true if x is NAN, else false.
	/// NAN = Not A Number
	/// </summary>
	NOX_FLATTEN NOX_PURE constexpr auto IsNan(const F64 x) -> bool
	{
		return ExponentBitsOf(x) == EXPONENT_MASK && FractionBitsOf(x) != 0;
	}

	/// <summary>
	/// Converts an integer from the "sign and magnitude" to the biased representation.
	/// See https://en.wikipedia.org/wiki/Signed_number_representations for more info.
	/// </summary>
	NOX_FLATTEN NOX_PURE constexpr auto SignMagnitudeToBiasedRepresentation(const U64 bits) -> U64
	{
		if (SIGN_MASK & bits)
		{
			return ~bits + 1;
		}
		return SIGN_MASK | bits;
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
	template <U32 Ulps = MAX_ULPS>
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

	NOX_FORCE_INLINE NOX_PURE inline auto Proxy_F64IsZero(const F64 x) -> bool
	{
		#if NOX_OPT_USE_ZERO_EPSILON
		return F64IsZero(x);
		#else
		return x == 0.0;
		#endif
	}

	NOX_FORCE_INLINE NOX_PURE inline auto Proxy_F64IsOne(const F64 x) -> bool
	{
		#if NOX_OPT_USE_ZERO_EPSILON
		return F64IsOne(x);
		#else
		return x == 1.0;
		#endif
	}

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
}

#include <fmt/format.h>
#include <fmt/chrono.h>
#include <fmt/color.h>

namespace Nominax::Common
{
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
}

namespace Nominax
{
	constexpr auto operator ""_kb(const U64 value) -> U64
	{
		return Common::Kilobytes2Bytes<decltype(value)>(value);
	}

	constexpr auto operator ""_mb(const U64 value) -> U64
	{
		return Common::Megabytes2Bytes<decltype(value)>(value);
	}

	constexpr auto operator ""_gb(const U64 value) -> U64
	{
		return Common::Gigabytes2Bytes<decltype(value)>(value);
	}

	#define NOX_PAINF __LINE__, 0, __FILE__, __FUNCTION__

	template <typename Str, typename... Args>
	[[noreturn]]
	NOX_COLD NOX_NEVER_INLINE auto Panic
	(
		const U32         line,
		const U32         column,
		const char* const file,
		const char* const routine,
		Str&&             formatString,
		Args&&...         args
	) -> void
	{
		using namespace Common;
		Print(TextColor::Red, "\n! NOMINAX RUNTIME PANIC !\n");
		Print(TextColor::White, "Line: {}\nColumn: {}\nSubroutine: {}\nFile: {}\n", line, column, routine ? routine : "?", file ? file : "?");
		Print(TextColor::White, formatString, std::forward<Args>(args)...);
		std::cout.flush();
		std::abort();
	}

	#define NOX_PANIC_ASSERT_TRUE(x, msg)				\
	do												\
	{												\
		if (!( x ))                 				\
		{                                           \
		    [[unlikely]]                            \
            ::Nominax::Panic(NOX_PAINF, ( msg ));	\
		}											\
	}												\
	while(false)

	#define NOX_PANIC_ASSERT_FALSE(x, msg)				\
	do												\
	{												\
		if (( x ))				                    \
		{											\
		    [[unlikely]]                            \
            ::Nominax::Panic(NOX_PAINF, ( msg ));	\
		}											\
	}												\
	while(false)

	#define NOX_PANIC_ASSERT_NULL(x, msg) NOX_PANIC_ASSERT_FALSE(x, msg)
	#define NOX_PANIC_ASSERT_NOT_NULL(x, msg) NOX_PANIC_ASSERT_TRUE(x, msg)
	#define NOX_PANIC_ASSERT_ZERO(x, msg) NOX_PANIC_ASSERT_FALSE(x, msg)
	#define NOX_PANIC_ASSERT_NOT_ZERO(x, msg) NOX_PANIC_ASSERT_TRUE(x, msg)

	#define NOX_PANIC_ASSERT_EQ(x, y, msg)				\
	do												\
	{												\
		if (( x ) != ( y ))		                    \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic(NOX_PAINF, ( msg ));	\
		}											\
	}												\
	while(false)


	#define NOX_PANIC_ASSERT_NE(x, y, msg)				\
	do												\
	{												\
		if (( x ) == ( y ))		                    \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic(NOX_PAINF, ( msg ));	\
		}											\
	}												\
	while(false)

	#define NOX_PANIC_ASSERT_L(x, y, msg)				\
	do												\
	{												\
		if (!(( x ) < ( y )))		                \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic(NOX_PAINF, ( msg ));	\
		}											\
	}												\
	while(false)

	#define NOX_PANIC_ASSERT_LE(x, y, msg)				\
	do												\
	{												\
		if (!(( x ) <= ( y )))	                    \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic(NOX_PAINF, ( msg ));	\
		}											\
	}												\
	while(false)

	#define NOX_PANIC_ASSERT_G(x, y, msg)				\
	do												\
	{												\
		if (!(( x ) > ( y )))		                \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic(NOX_PAINF, ( msg ));	\
		}											\
	}												\
	while(false)

	#define NOX_PANIC_ASSERT_GE(x, y, msg)				\
	do												\
	{												\
		if (!(( x ) >= ( y )))	                    \
		{											\
            [[unlikely]]                            \
            ::Nominax::Panic(NOX_PAINF, ( msg ));	\
		}											\
	}												\
	while(false)
}

namespace Nominax::Common
{
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
		auto GetCapacity() const -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the content - the number of characters.</returns>
		[[nodiscard]]
		auto GetSize() const -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the content in bytes (capacity * charSize)</returns>
		[[nodiscard]]
		auto GetSizeInBytes() const -> std::size_t;

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
		auto SubString(std::size_t beginIdx, std::size_t endIdx) const -> ViewType;

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

	inline auto TextFile::GetCapacity() const -> std::size_t
	{
		return this->Content_.capacity();
	}

	inline auto TextFile::GetSize() const -> std::size_t
	{
		return this->Content_.size();
	}

	inline auto TextFile::GetSizeInBytes() const -> std::size_t
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

namespace Nominax::VectorLib
{
	constexpr std::size_t V128_ALIGN
	{
		#ifdef __SSE__
		16
		#else
		alignof(F32)
		#endif
	};

	constexpr std::size_t V256_ALIGN
	{
		#if defined(__AVX__)
		32
		#elif defined(__SSE__)
		16
		#else
		alignof(F32)
		#endif
	};

	constexpr std::size_t V512_ALIGN
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
		_mm512_store_pd(inout + 8, x1);

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
		_mm512_store_pd(inout + 8, x1);

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
		_mm512_store_pd(inout + 8, x1);

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
		_mm512_store_pd(inout + 8, x1);

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
		_mm512_storeu_pd(inout + 8, x1);

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
		_mm512_storeu_pd(inout + 8, x1);

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
		_mm512_storeu_pd(inout + 8, x1);

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
		_mm512_storeu_pd(inout + 8, x1);

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

namespace Nominax::Arch::X86_64
{
	/// <summary>
	/// Contains all feature bits for a x86-64 cpu.
	/// </summary>
	struct CpuFeatureBits final
	{
		CpuFeatureBits();

		// QWORD 1 LO

		/// <summary>
		/// Onboard x87 FPU
		/// </summary>
		bool Fpu : 1 { };

		/// <summary>
		/// Virtual 8086 mode extensions (such as VIF, VIP, PIV)
		/// </summary>
		bool Vme : 1 { };

		/// <summary>
		/// Debugging extensions (CR4 bit 3)
		/// </summary>
		bool De : 1 { };

		/// <summary>
		/// Page Size Extension
		/// </summary>
		bool Pse : 1 { };

		/// <summary>
		/// Time Stamp Counter
		/// </summary>
		bool Tsc : 1 { };

		/// <summary>
		/// Model-specific registers
		/// </summary>
		bool Msr : 1 { };

		/// <summary>
		/// Physical Address Extension
		/// </summary>
		bool Pae : 1 { };

		/// <summary>
		/// Machine Check Exception
		/// </summary>
		bool Mce : 1 { };

		/// <summary>
		/// CMPXCHG8 (compare-and-swap) instruction
		/// </summary>
		bool Cx8 : 1 { };

		/// <summary>
		/// Onboard Advanced Programmable Interrupt Controller
		/// </summary>
		bool Apic : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved0 : 1 { };

		/// <summary>
		/// SYSENTER and SYSEXIT instructions
		/// </summary>
		bool Sep : 1 { };

		/// <summary>
		/// Memory Type Range Registers
		/// </summary>
		bool Mtrr : 1 { };

		/// <summary>
		/// Page Global Enable bit in CR4
		/// </summary>
		bool Pge : 1 { };

		/// <summary>
		/// Machine check architecture
		/// </summary>
		bool Mca : 1 { };

		/// <summary>
		///	Conditional move and FCMOV instructions
		/// </summary>
		bool CMov : 1 { };

		/// <summary>
		/// Page Attribute Table
		/// </summary>
		bool Pat : 1 { };

		/// <summary>
		/// 36-bit page size extension
		/// </summary>
		bool Pse36 : 1 { };

		/// <summary>
		/// Processor Serial Number
		/// </summary>
		bool Psn : 1 { };

		/// <summary>
		/// CLFLUSH instruction (SSE2)
		/// </summary>
		bool Clfsh : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved1 : 1 { };

		/// <summary>
		/// Debug store: save trace of executed jumps
		/// </summary>
		bool Ds : 1 { };

		/// <summary>
		/// Onboard thermal control MSRs for ACPI
		/// </summary>
		bool Acpi : 1 { };

		/// <summary>
		/// MMX instructions
		/// </summary>
		bool Mmx : 1 { };

		/// <summary>
		/// FXSAVE, FXRESTOR instructions, CR4 bit 9
		/// </summary>
		bool Fxsr : 1 { };

		/// <summary>
		/// SSE instructions (a.k.a. Katmai New Instructions)
		/// </summary>
		bool Sse : 1 { };

		/// <summary>
		/// SSE2 instructions
		/// </summary>
		bool Sse2 : 1 { };

		/// <summary>
		/// CPU cache implements self-snoop
		/// </summary>
		bool Ss : 1 { };

		/// <summary>
		/// Hyper-threading
		/// </summary>
		bool Htt : 1 { };

		/// <summary>
		/// Thermal monitor automatically limits temperature
		/// </summary>
		bool Tm : 1 { };

		/// <summary>
		/// IA64 processor emulating x86
		/// </summary>
		bool Ia64 : 1 { };

		/// <summary>
		/// Pending Break Enable (PBE# pin) wakeup capability
		/// </summary>
		bool Pbe : 1 { };

		// QWORD 1 HI

		/// <summary>
		/// Prescott New Instructions-SSE3 (PNI)
		/// </summary>
		bool Sse3 : 1 { };

		/// <summary>
		/// Carry-less Multiplication (CLMUL)
		/// </summary>
		bool PclMulDqd : 1 { };

		/// <summary>
		/// 64-bit debug store (edx bit 21)
		/// </summary>
		bool DTes64 : 1 { };

		/// <summary>
		/// MONITOR and MWAIT instructions (SSE3)
		/// </summary>
		bool Monitor : 1 { };

		/// <summary>
		/// CPL qualified debug store
		/// </summary>
		bool DsCpl : 1 { };

		/// <summary>
		/// Virtual Machine eXtensions
		/// </summary>
		bool Vmx : 1 { };

		/// <summary>
		/// Safer Mode Extensions (LaGrande)
		/// </summary>
		bool Smx : 1 { };

		/// <summary>
		/// Enhanced SpeedStep
		/// </summary>
		bool Est : 1 { };

		/// <summary>
		/// Thermal Monitor 2
		/// </summary>
		bool Tm2 : 1 { };

		/// <summary>
		/// Supplemental SSE3 instructions
		/// </summary>
		bool Ssse3 : 1 { };

		/// <summary>
		/// L1 Context ID
		/// </summary>
		bool CnxtId : 1 { };

		/// <summary>
		/// Silicon Debug interface
		/// </summary>
		bool Sdbg : 1 { };

		/// <summary>
		/// Fused multiply-add (FMA3)
		/// </summary>
		bool Fma3 : 1 { };

		/// <summary>
		/// CMPXCHG16B instruction
		/// </summary>
		bool Cx16 : 1 { };

		/// <summary>
		/// Can disable sending task priority messages
		/// </summary>
		bool Xtpr : 1 { };

		/// <summary>
		/// Perfmon & debug capability
		/// </summary>
		bool Pdcm : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved2 : 1 { };

		/// <summary>
		/// Process context identifiers (CR4 bit 17)
		/// </summary>
		bool Pcid : 1 { };

		/// <summary>
		/// Direct cache access for DMA writes
		/// </summary>
		bool Dca : 1 { };

		/// <summary>
		/// SSE4.1 instructions
		/// </summary>
		bool Sse41 : 1 { };

		/// <summary>
		/// SSE4.2 instructions
		/// </summary>
		bool Sse42 : 1 { };

		/// <summary>
		/// x2APIC
		/// </summary>
		bool X2Apic : 1 { };

		/// <summary>
		/// MOVBE instruction (big-endian)
		/// </summary>
		bool MovBe : 1 { };

		/// <summary>
		/// POPCNT instruction
		/// </summary>
		bool PopCnt : 1 { };

		/// <summary>
		/// APIC implements one-shot operation using a TSC deadline value
		/// </summary>
		bool TscDeadline : 1 { };

		/// <summary>
		/// AES instruction set
		/// </summary>
		bool Aes : 1 { };

		/// <summary>
		/// XSAVE, XRESTOR, XSETBV, XGETBV
		/// </summary>
		bool XSave : 1 { };

		/// <summary>
		/// XSAVE enabled by OS
		/// </summary>
		bool OsXSave : 1 { };

		/// <summary>
		/// Advanced Vector Extensions
		/// </summary>
		bool Avx : 1 { };

		/// <summary>
		/// F16C (half-precision) FP feature
		/// </summary>
		bool F16C : 1 { };

		/// <summary>
		/// RDRAND (on-chip random number generator) feature
		/// </summary>
		bool RdRnd : 1 { };

		/// <summary>
		/// Hypervisor present (always zero on physical CPUs)
		/// </summary>
		bool HyperVisor : 1 { };

		// QWORD 2 LO

		/// <summary>
		/// Access to base of %fs and %gs
		/// </summary>
		bool FsGsBase : 1 { };

		/// <summary>
		/// IA32_TSC_ADJUST
		/// </summary>
		bool TscAdjust : 1 { };

		/// <summary>
		/// Software Guard Extensions
		/// </summary>
		bool Sgx : 1 { };

		/// <summary>
		/// Bit Manipulation Instruction Set 1
		/// </summary>
		bool Bmi1 : 1 { };

		/// <summary>
		/// TSX Hardware Lock Elision
		/// </summary>
		bool Hle : 1 { };

		/// <summary>
		/// Advanced Vector Extensions 2
		/// </summary>
		bool Avx2 : 1 { };

		/// <summary>
		/// FDP_EXCPTN_ONLY
		/// </summary>
		bool FdpExcept : 1 { };

		/// <summary>
		/// Supervisor Mode Execution Prevention
		/// </summary>
		bool Smep : 1 { };

		/// <summary>
		/// Bit Manipulation Instruction Set 2
		/// </summary>
		bool Bmi2 : 1 { };

		/// <summary>
		/// Enhanced REP MOVSB/STOSB
		/// </summary>
		bool Erms : 1 { };

		/// <summary>
		/// INVPCID instruction
		/// </summary>
		bool InvPcid : 1 { };

		/// <summary>
		/// TSX Restricted Transactional Memory
		/// </summary>
		bool Rtm : 1 { };

		/// <summary>
		/// Platform Quality of Service Monitoring
		/// </summary>
		bool Pqm : 1 { };

		/// <summary>
		/// 	FPU CS and FPU DS deprecated
		/// </summary>
		bool FpuCsDsDepr : 1 { };

		/// <summary>
		/// 	Intel MPX (Memory Protection Extensions)
		/// </summary>
		bool Mpx : 1 { };

		/// <summary>
		/// 	Platform Quality of Service Enforcement
		/// </summary>
		bool Pqe : 1 { };

		/// <summary>
		/// 	AVX-512 Foundation
		/// </summary>
		bool Avx512F : 1 { };

		/// <summary>
		/// AVX-512 Doubleword and Quadword Instructions
		/// </summary>
		bool Avx512Dq : 1 { };

		/// <summary>
		/// RDSEED instruction
		/// </summary>
		bool RdSeed : 1 { };

		/// <summary>
		/// Intel ADX (Multi-Precision Add-Carry Instruction Extensions)
		/// </summary>
		bool Adx : 1 { };

		/// <summary>
		/// 	Supervisor Mode Access Prevention
		/// </summary>
		bool SMap : 1 { };

		/// <summary>
		/// Integer Fused Multiply-Add Instructions
		/// </summary>
		bool Avx512Ifma : 1 { };

		/// <summary>
		/// PCOMMIT instruction
		/// </summary>
		bool PCommit : 1 { };

		/// <summary>
		/// CLFLUSHOPT instruction
		/// </summary>
		bool ClFlushOpt : 1 { };

		/// <summary>
		/// 	CLWB instruction
		/// </summary>
		bool Clwb : 1 { };

		/// <summary>
		/// 	Intel Processor Trace
		/// </summary>
		bool IntelPt : 1 { };

		/// <summary>
		/// Prefetch Instructions
		/// </summary>
		bool Avx512Pf : 1 { };

		/// <summary>
		///  Exponential and Reciprocal Instructions
		/// </summary>
		bool Avx512Er : 1 { };

		/// <summary>
		/// Conflict Detection Instructions
		/// </summary>
		bool Avx512Cd : 1 { };

		/// <summary>
		/// 	Intel SHA extensions
		/// </summary>
		bool Sha : 1 { };

		/// <summary>
		/// Byte and Word Instructions
		/// </summary>
		bool Avx512Bw : 1 { };

		/// <summary>
		/// Vector Length Extensions
		/// </summary>
		bool Avx512Vl : 1 { };

		// QWORD 2 HI

		/// <summary>
		/// PREFETCHWT1 instruction
		/// </summary>
		bool PreFetchWt1 : 1 { };

		/// <summary>
		/// Vector Bit Manipulation Instructions
		/// </summary>
		bool Avx512Vbmi : 1 { };

		/// <summary>
		/// User-mode Instruction Prevention
		/// </summary>
		bool Umip : 1 { };

		/// <summary>
		/// Memory Protection Keys for User-mode pages
		/// </summary>
		bool Pku : 1 { };

		/// <summary>
		/// PKU enabled by OS
		/// </summary>
		bool OsPke : 1 { };

		/// <summary>
		/// Timed pause and user-level monitor/wait
		/// </summary>
		bool WaitPkg : 1 { };

		/// <summary>
		/// AVX-512 Vector Bit Manipulation Instructions 2
		/// </summary>
		bool Avx512Vbmi2 : 1 { };

		/// <summary>
		/// 	Control flow enforcement (CET) shadow stack
		/// </summary>
		bool CetSS : 1 { };

		/// <summary>
		/// 	Galois Field instructions
		/// </summary>
		bool Gfni : 1 { };

		/// <summary>
		/// Vector AES instruction set (VEX-256/EVEX)
		/// </summary>
		bool VAes : 1 { };

		/// <summary>
		/// 	CLMUL instruction set (VEX-256/EVEX)
		/// </summary>
		bool VPclMulDqd : 1 { };

		/// <summary>
		/// Vector Neural Network Instructions
		/// </summary>
		bool Avx512Vnni : 1 { };

		/// <summary>
		/// BITALG instructions
		/// </summary>
		bool Avx512Bitalg : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved3 : 1 { };

		/// <summary>
		/// 	AVX-512 Vector Population Count Double and Quad-word
		/// </summary>
		bool Avx512VPopCntdq : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved4 : 1 { };

		/// <summary>
		/// 	5-level paging
		/// </summary>
		bool Level5Paging : 1 { };

		/// <summary>
		/// Unused.
		/// The value of userspace MPX Address-Width Adjust used by the BNDLDX and BNDSTX Intel MPX instructions in 64-bit mode
		/// </summary>
		U8 IngoredM0 : 5 { };

		/// <summary>
		/// Read Processor ID and IA32_TSC_AUX
		/// </summary>
		bool RdPid : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved5 : 1 { };

		/// <summary>
		/// Unused.
		/// </summary>
		bool Reserved6 : 1 { };

		/// <summary>
		/// 	Cache line demote
		/// </summary>
		bool ClDemote : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved7 : 1 { };

		/// <summary>
		/// 
		/// </summary>
		bool MovDiri : 1 { };

		/// <summary>
		/// 
		/// </summary>
		bool MovDir64B : 1 { };

		/// <summary>
		/// Enqueue Stores
		/// </summary>
		bool EnqCmd : 1 { };

		/// <summary>
		/// SGX Launch Configuration
		/// </summary>
		bool SgxLc : 1 { };

		/// <summary>
		/// Protection keys for supervisor-mode pages
		/// </summary>
		bool Pks : 1 { };

		// U64 3 LO

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved8 : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved9 : 1{ };

		/// <summary>
		/// 4-register Neural Network Instructions
		/// </summary>
		bool Avx5124Vnniw : 1{ };

		/// <summary>
		/// 4-register Multiply Accumulation Single precision
		/// </summary>
		bool Avx5124FMaps : 1{ };

		/// <summary>
		/// Fast Short REP MOVSB
		/// </summary>
		bool Fsrm : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved10 : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved11 : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved12 : 1{ };

		/// <summary>
		/// Doubleword and Quadword Instructions
		/// </summary>
		bool Avx512Vp2Intersect : 1{ };

		/// <summary>
		/// Special Register SystemBumpPool Data Sampling Mitigations
		/// </summary>
		bool SrbdsCtrl : 1{ };

		/// <summary>
		/// 	VERW instruction clears CPU buffers
		/// </summary>
		bool MdClear : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved13 : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved14 : 1{ };

		/// <summary>
		/// 
		/// </summary>
		bool TsxForceAbort : 1{ };

		/// <summary>
		/// 	Serialize instruction execution
		/// </summary>
		bool Serialize : 1{ };

		/// <summary>
		/// 
		/// </summary>
		bool Hybrid : 1{ };

		/// <summary>
		/// 	TSX suspend load address tracking
		/// </summary>
		bool Tsxldtrk : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved15 : 1{ };

		/// <summary>
		/// Platform configuration (Memory Encryption Technologies Instructions)
		/// </summary>
		bool PConfig : 1{ };

		/// <summary>
		/// 	Architectural Last Branch Records
		/// </summary>
		bool Lbr : 1{ };

		/// <summary>
		/// Control flow enforcement (CET) indirect branch tracking
		/// </summary>
		bool CetIbt : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved16 : 1{ };

		/// <summary>
		/// Tile computation on bfloat16 numbers
		/// </summary>
		bool AmxBf16 : 1{ };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved17 : 1{ };

		/// <summary>
		/// Tile architecture
		/// </summary>
		bool AmxTile : 1{ };

		/// <summary>
		/// Tile computation on 8-bit integers
		/// </summary>
		bool AmxInt8 : 1{ };

		/// <summary>
		/// Speculation Control, part of Indirect Branch Control (IBC):
		/// Indirect Branch Restricted Speculation(IBRS) and
		/// Indirect Branch Prediction Barrier(IBPB)
		/// </summary>
		bool SpecCtrl : 1{ };

		/// <summary>
		/// 	Single Thread Indirect Branch Predictor, part of IBC
		/// </summary>
		bool Stibp : 1{ };

		/// <summary>
		/// 	IA32_FLUSH_CMD MSR
		/// </summary>
		bool L1DFlush : 1{ };

		/// <summary>
		/// Speculative Side Channel Mitigations
		/// </summary>
		bool Ia32ArchCompat : 1{ };

		/// <summary>
		/// Support for a MSR listing model-specific core capabilities
		/// </summary>
		bool Ia32CoreCompat : 1{ };

		/// <summary>
		/// 	Speculative Store Bypass Disable,
		/// 	as mitigation for Speculative Store Bypass (IA32_SPEC_CTRL)
		/// </summary>
		bool Ssbd : 1{ };

		// U64 3 HI

		/// <summary>
		/// LAHF/SAHF in long mode
		/// </summary>
		bool LahfLm : 1{ };

		/// <summary>
		/// 	Hyperthreading not valid
		/// </summary>
		bool CmpLegacy : 1 { };

		/// <summary>
		/// 	Secure Virtual Machine
		/// </summary>
		bool Svm : 1 { };

		/// <summary>
		/// 	Extended APIC space
		/// </summary>
		bool ExtApic : 1 { };

		/// <summary>
		/// CR8 in 32-bit mode
		/// </summary>
		bool Cr8Legacy : 1 { };

		/// <summary>
		/// 	Advanced bit manipulation (lzcnt and popcnt)
		/// </summary>
		bool Abm : 1 { };

		/// <summary>
		/// 	SSE4a
		/// </summary>
		bool Sse4a : 1 { };

		/// <summary>
		/// Misaligned SSE mode
		/// </summary>
		bool MisAlignSse : 1 { };

		/// <summary>
		/// PREFETCH and PREFETCHW instructions
		/// </summary>
		bool D3NowPrefetch : 1 { };

		/// <summary>
		/// 	OS Visible Workaround
		/// </summary>
		bool OsVw : 1 { };

		/// <summary>
		/// 	Instruction Based Sampling
		/// </summary>
		bool Ibs : 1 { };

		/// <summary>
		/// 	XOP instruction set
		/// </summary>
		bool Xop : 1 { };

		/// <summary>
		/// SKINIT/STGI instructions
		/// </summary>
		bool SkInit : 1 { };

		/// <summary>
		/// 	Watchdog timer
		/// </summary>
		bool Wdt : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved18 : 1 { };

		/// <summary>
		/// 	Light Weight Profiling[25]
		/// </summary>
		bool Lwp : 1 { };

		/// <summary>
		/// 	4 operands fused multiply-add
		/// </summary>
		bool Fma4 : 1 { };

		/// <summary>
		/// 	Translation Cache Extension
		/// </summary>
		bool Tce : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved19 : 1 { };

		/// <summary>
		/// 	NodeID MSR
		/// </summary>
		bool NodeIdMsr : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved20 : 1 { };

		/// <summary>
		/// Trailing Bit Manipulation
		/// </summary>
		bool Tbm : 1 { };

		/// <summary>
		/// 	Topology Extensions
		/// </summary>
		bool TopoExt : 1 { };

		/// <summary>
		/// Core performance counter extensions
		/// </summary>
		bool PerfCtrCore : 1 { };

		/// <summary>
		/// 	NB performance counter extensions
		/// </summary>
		bool PerCtrNb : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved21 : 1 { };

		/// <summary>
		/// 	Data breakpoint extensions
		/// </summary>
		bool Dbx : 1 { };

		/// <summary>
		/// 	Performance TSC
		/// </summary>
		bool PerfTsc : 1 { };

		/// <summary>
		/// 	L2I perf counter extensions
		/// </summary>
		bool PcxL2i : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved22 : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved23 : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved24 : 1 { };

		// DWORD RET

		/// <summary>
		/// Unused
		/// </summary>
		U16 Ignored0 : 11 { };

		/// <summary>
		/// SYSCALL and SYSRET instructions
		/// </summary>
		bool SysCall : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		U8 Ignored1 : 7 { };

		/// <summary>
		/// Multiprocessor Capable
		/// </summary>
		bool Mp : 1 { };

		/// <summary>
		/// 	NX bit
		/// </summary>
		bool Nx : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved25 : 1 { };

		/// <summary>
		/// 	Extended MMX
		/// </summary>
		bool MmmxExt : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		U8 Ignored2 : 2 { };

		/// <summary>
		/// 	FXSAVE/FXRSTOR optimizations
		/// </summary>
		bool FxsrOpt : 1 { };

		/// <summary>
		/// Gigabyte pages
		/// </summary>
		bool Pdpe1Gb : 1 { };

		/// <summary>
		/// RDTSCP instruction
		/// </summary>
		bool Rdtscp : 1 { };

		/// <summary>
		/// Unused
		/// </summary>
		bool Reserved26 : 1 { };

		/// <summary>
		/// Long mode
		/// </summary>
		bool LongMode : 1 { };

		/// <summary>
		/// 	Extended 3DNow!
		/// </summary>
		bool D3NowExt : 1 { };

		/// <summary>
		/// 	3DNow!
		/// </summary>
		bool D3Now : 1 { };

		/// <summary>
		/// Prints all the features into a table
		/// coloring the available features green
		/// and the unavailable red.
		/// </summary>
		/// <returns></returns>
		auto PrintFeatures() const -> void;
	};

	static_assert(sizeof(CpuFeatureBits) == 30);
	static_assert(std::is_trivially_copyable_v<CpuFeatureBits>);

	/// <summary>
	/// Contains merged info table.
	/// One 64-bit instance contains two 32-bit info tables.
	/// </summary>
	union MergedInfoTable
	{
		U64 Merged { };

		struct
		{
			U32 Table1;
			U32 Table2;
		};
	};

	static_assert(sizeof(MergedInfoTable) == 8);
	static_assert(std::is_trivially_copyable_v<MergedInfoTable>);

	/// <summary>
	/// Assembly routine which calls cpuid
	/// multiple time to determine all cpu features.
	/// The first 6 feature tables are returned via
	/// out1, out2 and out3. Each contains two info tables.
	/// (See MergedInfoTable). The last info table is returned
	/// as return value. Do not use this function, better use
	/// CpuFeatureBits instead, which calls this function in the
	/// constructor.
	/// Implementation: Source/Arch/X86_64.CpuId.S
	/// </summary>
	extern "C" auto Asm_CpuId
	(
		MergedInfoTable* out1,
		MergedInfoTable* out2,
		MergedInfoTable* out3
	) -> U32;

	/// <summary>
	/// Returns 1 if the current CPU supports the CPUID instruction, else 0.
	/// Implementation: Source/Arch/X86_64.CpuId.S
	/// </summary>
	extern "C" auto Asm_IsCpuIdSupported() -> U8;

	/// <summary>
	/// Returns true if the OS supports AVX YMM registers, else false.
	/// Warning! Check if os supports OSXSAVE first!
	/// </summary>
	extern "C" auto Asm_IsAvxSupportedByOs() -> U8;

	/// <summary>
	/// Returns true if the OS supports AVX512 ZMM registers, else false.
	/// Warning! Check if os supports OSXSAVE first!
	/// </summary>
	extern "C" auto Asm_IsAvx512SupportedByOs() -> U8;
}


namespace Nominax::System
{
	#if NOX_ARCH_X86_64
	/// <summary>
	/// Architecture dependent cpu feature flags.
	/// </summary>
	using FeatureBits = Arch::X86_64::CpuFeatureBits;
	#else
		using FeatureBits = void;
#   error "ARM is not yet implemented!"
	#endif

	static_assert(std::is_default_constructible_v<FeatureBits>);

	/// <summary>
	/// Detects architecture dependent cpu features.
	/// </summary>
	struct CpuFeatureDetector final
	{
	private:
		/// <summary>
		/// Architecture dependent bits.
		/// </summary>
		const FeatureBits Features_;

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
		auto operator ->() const -> const FeatureBits*;

		/// <summary>
		/// Access the architecture dependent feature bits directly.
		/// </summary>
		auto operator *() const -> const FeatureBits&;

		/// <summary>
		/// Prints all the architecture dependent features in different colors.
		/// </summary>
		auto Print() const -> void;
	};

	inline auto CpuFeatureDetector::operator ->() const -> const FeatureBits*
	{
		return &this->Features_;
	}

	inline auto CpuFeatureDetector::operator *() const -> const FeatureBits&
	{
		return this->Features_;
	}

	namespace Os
	{
		[[nodiscard]]
		extern auto QuerySystemMemoryTotal() -> std::size_t;

		[[nodiscard]]
		extern auto QueryProcessMemoryUsed() -> std::size_t;

		[[nodiscard]]
		extern auto QueryCpuName() -> std::string;

		[[nodiscard]]
		extern auto QueryPageSize() -> std::size_t;

		[[nodiscard]]
		extern auto DylibOpen(std::string_view filePath) -> void*;

		[[nodiscard]]
		extern auto DylibLookupSymbol(void* handle, std::string_view symbolName) -> void*;

		extern auto DylibClose(void*& handle) -> void;
	}

	struct Snapshot final
	{
		std::thread::id  ThreadId { };
		std::string_view OperatingSystemName {NOX_OS_NAME};
		std::string_view ArchitectureName {NOX_ARCH_NAME};
		std::string_view CompilerName {NOX_COM_NAME};
		std::size_t      ThreadCount { };
		std::string      CpuName { };
		std::size_t      TotalSystemMemory { };
		std::size_t      ProcessMemory { };
		std::size_t      PageSize { };

		Snapshot();

		auto QueryAll() -> void;
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
		/// <param name=""></param>
		DynamicLibrary(const DynamicLibrary&) = delete;

		/// <summary>
		/// No moving, copying
		/// </summary>
		/// <param name=""></param>
		DynamicLibrary(DynamicLibrary&&) = delete;

		/// <summary>
		/// No moving, copying
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		auto operator =(const DynamicLibrary&) -> DynamicLibrary& = delete;

		/// <summary>
		/// No moving, copying
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		auto operator =(DynamicLibrary&&) -> DynamicLibrary& = delete;

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
}
