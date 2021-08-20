// File: Algorithm.hpp
// Author: Mario
// Created: 20.08.2021 2:40 PM
// Project: Corium
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

#include <bit>
#include <functional>
#include <iterator>
#include <span>
#include <variant>
#include <climits>

#include "Platform.hpp"
#include <cstdint>

namespace Nominax
{
	/// <summary>
	/// Converts the enum into the underlying type.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="x"></param>
	/// <returns></returns>
	template <typename T> requires std::is_enum_v<T>
	constexpr auto ToUnderlying(const T x) -> auto
	{
		return static_cast<std::underlying_type_t<std::decay_t<T>>>(x);
	}
}

namespace Nominax::Foundation
{
	/// <summary>
		/// Generic bit rotation left.
		/// </summary>
		/// <param name="value"></param>
		/// <param name="shift"></param>
		/// <returns>The bit shifted value.</returns>
	template <typename T> requires std::is_unsigned_v<T>
	[[nodiscard]]
	NOX_FORCE_INLINE NOX_PURE constexpr auto RolGeneric(const T value, const std::uint8_t shift) -> T
	{
		return ((value) << (shift)) | ((value) >> (-static_cast<std::int32_t>(shift) & (CHAR_BIT * sizeof(value) - 1)));
	}

	/// <summary>
	/// Generic bit rotation right.
	/// </summary>
	/// <param name="value"></param>
	/// <param name="shift"></param>
	/// <returns>The bit shifted value.</returns>
	template <typename T> requires std::is_unsigned_v<T>
	[[nodiscard]]
	NOX_FORCE_INLINE NOX_PURE constexpr auto RorGeneric(const T value, const std::uint8_t shift) -> T
	{
		return (((value) << (-static_cast<std::int32_t>(shift) & (CHAR_BIT * sizeof(value) - 1))) | ((value) >> (shift)));
	}

	/// <summary>
	/// Fast, platform dependent implementation for a bitwise left rotation.
	/// </summary>
	[[nodiscard]]
	NOX_FORCE_INLINE NOX_PURE inline auto Rol32
	(
		std::uint32_t      value,
		const std::uint8_t shift
	) -> std::uint32_t
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
		std::uint32_t      value,
		const std::uint8_t shift
	) -> std::uint32_t
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
		std::uint64_t      value,
		const std::uint8_t shift
	) -> std::uint64_t
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
		std::uint64_t      value,
		const std::uint8_t shift
	) -> std::uint64_t
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
	constexpr auto RoundUpPow2(std::uint64_t x) -> std::uint64_t
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
	constexpr auto FP16ToFP32(const std::uint16_t src) -> float
	{
		const std::uint32_t h {src};
		std::uint32_t       sign {(h >> 15) & 1};
		std::uint32_t       exp {(h >> 10) & 0x1F};
		std::uint32_t       man {(h & 0x3FF) << 13};

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
				std::uint32_t msb;
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
		return static_cast<float>(sign | exp | man);
	}

	/// <summary>
	/// Convert 32-bit single precision float to half precision 16-bit float.
	/// </summary>
	/// <param name="src"></param>
	/// <returns></returns>
	constexpr auto FP32ToFP16(const float src) -> std::uint16_t
	{
		const std::uint32_t x {std::bit_cast<std::uint32_t>(src)};
		const std::uint32_t u {x & 0x7FFFFFFF};

		if (u > 0x7F800000)
		{
			// Remove +NaN/-NaN
			return 0x7FFF;
		}

		const std::uint32_t sign {(x >> 16) & 0x8000};
		if (u > 0x477FEFFF)
		{
			return sign | 0x7C00U;
		}
		if (u < 0x33000001)
		{
			return sign | 0x0000;
		}

		std::uint32_t exp {(u >> 23) & 0xFF};
		std::uint32_t man {u & 0x7FFFFF};
		std::uint32_t shi;

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

		const std::uint32_t lsb {static_cast<std::uint32_t>(1) << shi};
		const std::uint32_t lsbS1 {lsb >> 1};
		const std::uint32_t lsbM1 {lsb - 1};
		const std::uint32_t rem {man & lsbM1};
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
		return static_cast<std::uint16_t>(sign | exp | man);
	}

	/// <summary>
	/// Computes the required bytes needed for the value or bit representation x.
	/// </summary>
	/// <param name="x"></param>
	/// <returns>The amount of bytes -> min: 1, max: 8</returns>
	constexpr auto ComputeRequiredBytes(std::uint64_t x) -> std::uint8_t
	{
		std::uint8_t bytes {0};
		do
		{
			x >>= 8;
			++bytes;
		}
		while (x);
		return static_cast<std::uint8_t>(RoundUpPow2(static_cast<std::uint64_t>(bytes)));
	}

	/// <summary>
	/// Linearizes 2D coordinates using interleaved bits (morton table).
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	extern auto LinearizeCoords2D(std::uint16_t x, std::uint16_t y) -> std::uint32_t;

	/// <summary>
	/// Fallback implementation for "ILog"
	/// using a table of De-Bruijn sequence numbers.
	/// </summary>
	/// <param name="x"></param>
	/// <returns></returns>
	extern auto ILog2DeBruijn(std::uint64_t x) -> std::uint64_t;

	/// <summary>
	/// Computes the binary logarithm of log2(2)
	/// </summary>
	/// <param name="x">Should not be 0!</param>
	/// <returns></returns>
	inline auto ILog2(std::uint64_t x) -> std::uint64_t
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
	constexpr auto UniformChunkSplit(const std::uint64_t chunkCount, const Iter begin, const Iter end, Func&& func, Args&&...args) -> void
	{
		using ValueType = const typename std::iterator_traits<Iter>::value_type;
		using Span = std::span<ValueType>;

		const auto length {std::distance(begin, end)};
		const bool mismatch {chunkCount <= 1 || static_cast<std::uint64_t>(length) % chunkCount};

		if (mismatch)
		{
			const Span range {begin, end};
			std::invoke(std::forward<Func>(func), range, static_cast<std::uint64_t>(0), std::forward<Args>(args)...);
		}
		else
		{
			const auto chunkSize {static_cast<std::uint64_t>(length) / chunkCount};
			for (std::uint64_t i {0}; i < chunkCount; ++i)
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
	constexpr auto UniformChunkSplit(const std::uint64_t chunkCount, const std::span<const T> range, Func&& func, Args&&...args) -> void
	{
		UniformChunkSplit<decltype(std::begin(range)), Func, Args...>(chunkCount, std::begin(range), std::end(range), std::forward<Func>(func), std::forward(args)...);
	}

	/// <summary>
	/// Computes the index of T inside the variant type.
	/// </summary>
	/// <typeparam name="VariantType"></typeparam>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template <typename VariantType, typename T, std::uint64_t Index = 0>
	[[nodiscard]]
	constexpr auto VariantIndexOf() -> std::uint64_t
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
	constexpr auto Sex(const std::int8_t x) -> std::uint8_t
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
	constexpr auto Sex(const std::int16_t x) -> std::uint16_t
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
	constexpr auto Sex(const std::int32_t x) -> std::uint32_t
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
	constexpr auto Sex(const std::int64_t x) -> std::uint64_t
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
}
