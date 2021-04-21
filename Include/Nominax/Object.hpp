// File: Object.hpp
// Author: Mario
// Created: 19.04.2021 17:13
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

#include <atomic>
#include <cassert>
#include <cstring>
#include <memory>
#include <span>
#include <vector>

#include "MacroCfg.hpp"
#include "Record.hpp"

namespace Nominax
{
	/// <summary>
	/// Contains all flags in the flag vector field in the object header.
	/// </summary>
	union ObjectFlagsVectorCompound final
	{
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
		} Flags;

		std::uint32_t Compound;
	};

	static_assert(sizeof(ObjectFlagsVectorCompound) == sizeof(std::uint32_t));

	/// Every heap allocated object has an object header.
	/// The object header contains various meta data about the object.
	/// Each object header field is 32 - bits wide.
	///
	/// Offset	   Description	  Size
	/// +-----------------------+
	/// | 0 | Strong Ref Count  | 32 Bit
	/// +-----------------------+
	/// | 1 |  Size in Records	| 32 Bit
	/// +-----------------------+
	/// | 2 | Type ID			| 32 Bit
	/// +-----------------------+
	/// | 3 | Flag Vector		| 32 Bit
	/// +-----------------------+
	/// Total size : 128 Bit(16 Bytes)
	struct ObjectHeader final
	{
		/// <summary>
		/// Reference counter for strong references.
		/// </summary>
		std::uint32_t StrongRefCount {0};

		/// <summary>
		/// Object size in records.
		/// </summary>
		std::uint32_t Size {0};

		/// <summary>
		/// Type index for type DB.
		/// </summary>
		std::uint32_t TypeId {0};

		/// <summary>
		/// Flag vector for object states.
		/// </summary>
		ObjectFlagsVectorCompound FlagVector { };

		/// <summary>
		/// Maps this record into the specified memory region.
		/// ! The region must have at least 2 record entries to write to !
		/// Safe alternative is the overload using std::span.
		/// </summary>
		/// <param name="region"></param>
		/// <returns></returns>
		auto MapToRegionUnchecked(Record* region) const noexcept -> void;

		/// <summary>
		/// Maps this record into the specified memory region.
		/// ! The region must have at least 2 record entries to write to !
		/// </summary>
		/// <param name="region"></param>
		/// <returns>true if the size of the region was correct and the mapping succeeded, else false.</returns>
		[[nodiscard]]
		auto MapToRegionChecked(std::span<Record> region) const noexcept -> bool;

		/// <summary>
		/// Maps this record from the specified memory region.
		/// ! The region must have at least 2 record entries to read from!
		/// Safe alternative is the overload using std::span.
		/// </summary>
		/// <param name="region"></param>
		/// <returns></returns>
		auto MapFromRegionUnchecked(const Record* region) noexcept -> void;

		/// <summary>
		/// Maps this record from the specified memory region.
		/// ! The region must have at least 2 record entries to read from!
		/// </summary>
		/// <param name="region"></param>
		/// <returns>true if the size of the region was correct and the mapping succeeded, else false.</returns>
		[[nodiscard]]
		auto MapFromRegionChecked(std::span<const Record> region) noexcept -> bool;

		/// <summary>
		/// Map an object header to the region and return the current value of the strong ref count.
		/// </summary>
		/// <param name="region"></param>
		/// <returns>The current value of the strong ref count.</returns>
		[[nodiscard]]
		static constexpr auto ReadMapping_StrongRefCount(const Record* region) noexcept -> std::uint32_t;

		/// <summary>
		/// Map an object header to the region and return the current value of the size.
		/// </summary>
		/// <param name="region"></param>
		/// <returns>The current value of the size field.</returns>
		[[nodiscard]]
		static constexpr auto ReadMapping_Size(const Record* region) noexcept -> std::uint32_t;

		/// <summary>
		/// Map an object header to the region and return the current value of the type id.
		/// </summary>
		/// <param name="region"></param>
		/// <returns>The current value of the type id.</returns>
		[[nodiscard]]
		static constexpr auto ReadMapping_TypeId(const Record* region) noexcept -> std::uint32_t;

		/// <summary>
		/// Map an object header to the region and return the current value of the flag vector.
		/// </summary>
		/// <param name="region"></param>
		/// <returns>The current value of the flag vector.</returns>
		[[nodiscard ]]
		static constexpr auto ReadMapping_FlagVector(const Record* region) noexcept -> ObjectFlagsVectorCompound;

		/// <summary>
		/// Map an object header to the region and writes the value into the strong ref count field.
		/// </summary>
		/// <param name="region"></param>
		/// <param name="strongRefCount">The value to write.</param>
		/// <returns></returns>
		static constexpr auto WriteMapping_StrongRefCount(Record* region, std::uint32_t strongRefCount) noexcept -> void;

		/// <summary>
		/// Implicit map the region to an object header and increment the strong reference counter by one.
		/// The region must have at least 2 record entries to read from!
		/// </summary>
		/// <param name="region"></param>
		/// <returns></returns>
		static constexpr auto WriteMapping_IncrementStrongRefCount(Record* region) noexcept -> void;

		/// <summary>
		/// Implicit map the region to an object header and decrement the strong reference counter by one.
		/// The region must have at least 2 record entries to read from!
		/// </summary>
		/// <param name="region"></param>
		/// <returns></returns>
		static constexpr auto WriteMapping_DecrementStrongRefCount(Record* region) noexcept -> void;

		/// <summary>
		/// Map an object header to the region and writes the value into the size field.
		/// </summary>
		/// <param name="region"></param>
		/// <param name="size">The value to write.</param>
		/// <returns></returns>
		static constexpr auto WriteMapping_Size(Record* region, std::uint32_t size) noexcept -> void;

		/// <summary>
		/// Map an object header to the region and writes the value into the type id field.
		/// </summary>
		/// <param name="region"></param>
		/// <param name="typeId">The value to write.</param>
		/// <returns></returns>
		static constexpr auto WriteMapping_TypeId(Record* region, std::uint32_t typeId) noexcept -> void;

		/// <summary>
		/// Map an object header to the region and writes the value into the flag vector field.
		/// </summary>
		/// <param name="region"></param>
		/// <param name="flagVector">The value to write.</param>
		/// <returns></returns>
		static constexpr auto WriteMapping_FlagVector(Record* region, ObjectFlagsVectorCompound flagVector) noexcept -> void;

		/// <summary>
		/// Type-pun a region to an object header
		/// using reinterpret_cast. This is bug prone and unsafe.
		/// </summary>
		/// <param name="region"></param>
		/// <returns></returns>
		[[nodiscard]]
		static auto RawQueryTypePun(Record* region) -> ObjectHeader&;

		/// <summary>
		/// The size of each header block field.
		/// </summary>
		static constexpr auto STRIDE {sizeof(std::uint32_t)};

		/// <summary>
		/// The count of header field blocks => 4 (StrongRefCount, Size, TypeId, FlagVector)
		/// </summary>
		static constexpr std::size_t BLOCKS {4};

		/// <summary>
		/// The offset in records from the blob base pointer.
		/// </summary>
		static constexpr std::uintptr_t RECORD_OFFSET {STRIDE * BLOCKS / sizeof(Record)};

		/// <summary>
		/// The amount of records required to store the header.
		/// </summary>
		static constexpr std::uint32_t RECORD_CHUNKS {RECORD_OFFSET};

		static_assert(STRIDE == 4);
		static_assert(BLOCKS == 4);
	};

	static_assert(sizeof(ObjectHeader) == ObjectHeader::BLOCKS * ObjectHeader::STRIDE);
	static_assert(sizeof(ObjectHeader) == 16);
	static_assert(sizeof(ObjectHeader) % ObjectHeader::BLOCKS == 0); // Ok, ok we know the size must be 16 bytes!
	static_assert(std::is_standard_layout_v<ObjectHeader>);
	static_assert(std::is_trivially_copyable_v<ObjectHeader>);

	__attribute__((flatten)) inline auto ObjectHeader::MapToRegionUnchecked(Record* const region) const noexcept -> void
	{
		std::memcpy(region, this, sizeof(ObjectHeader));
	}

	__attribute__((flatten)) inline auto ObjectHeader::MapToRegionChecked(const std::span<Record> region) const noexcept -> bool
	{
		if (__builtin_expect(region.size() < 2, 0))
		{
			return false;
		}
		return std::memcpy(region.data(), this, sizeof(ObjectHeader));
	}

	__attribute__((flatten)) inline auto ObjectHeader::MapFromRegionUnchecked(const Record* const region) noexcept -> void
	{
		std::memcpy(this, region, sizeof(ObjectHeader));
	}

	__attribute__((flatten)) inline auto ObjectHeader::MapFromRegionChecked(const std::span<const Record> region) noexcept -> bool
	{
		if (__builtin_expect(region.size() < 2, 0))
		{
			return false;
		}
		return std::memcpy(this, region.data(), sizeof(ObjectHeader));
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::ReadMapping_StrongRefCount(const Record* const region) noexcept -> std::uint32_t
	{
		return *(*region).U32C;
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::ReadMapping_Size(const Record* const region) noexcept -> std::uint32_t
	{
		return *((*region).U32C + 1);
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::ReadMapping_TypeId(const Record* const region) noexcept -> std::uint32_t
	{
		return *(*(region + 1)).U32C;
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::ReadMapping_FlagVector(const Record* const region) noexcept -> ObjectFlagsVectorCompound
	{
		const auto flags = ObjectFlagsVectorCompound
		{
			.Compound = *((*(region + 1)).U32C + 1)
		};
		return flags;
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::WriteMapping_StrongRefCount(Record* const region, const std::uint32_t strongRefCount) noexcept -> void
	{
		*(*region).U32C = strongRefCount;
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::WriteMapping_IncrementStrongRefCount(Record* const region) noexcept -> void
	{
		++*(*region).U32C;
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::WriteMapping_DecrementStrongRefCount(Record* const region) noexcept -> void
	{
		--*(*region).U32C;
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::WriteMapping_Size(Record* const region, const std::uint32_t size) noexcept -> void
	{
		*((*region).U32C + 1) = size;
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::WriteMapping_TypeId(Record* const region, const std::uint32_t typeId) noexcept -> void
	{
		*(*(region + 1)).U32C = typeId;
	}

	__attribute__((flatten)) constexpr auto ObjectHeader::WriteMapping_FlagVector(Record* const region, const ObjectFlagsVectorCompound flagVector) noexcept -> void
	{
		*((*(region + 1)).U32C + 1) = flagVector.Compound;
	}

	__attribute__((flatten)) inline auto ObjectHeader::RawQueryTypePun(Record* const region) -> ObjectHeader&
	{
		return *reinterpret_cast<ObjectHeader*>(region);
	}

#define MUTATOR
#define IMMUTATOR

	/// <summary>
	/// Represents any heap allocated object.
	/// </summary>
	struct Object final
	{
		using BlobBlockType = Record;

		/// <summary>
		/// Full data blob.
		/// Array of records which contains the
		/// object header and the object itself.
		/// The first two records are always the header,
		/// so the allocator must always allocate minimum 2 two records
		/// for the header plus the size in records for the object.
		/// So the blob length will be: ObjectHeader::RECORD_CHUNKS + sizeInRecords
		/// This size must be written into the header field "Size"!
		/// </summary>
		BlobBlockType* Blob {nullptr};

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The strong reference count field from the object header.</returns>
		[[nodiscard]]
		auto IMMUTATOR HeaderRead_StrongReferenceCount() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the object in records. The size field from the object header.</returns>
		[[nodiscard]]
		auto IMMUTATOR HeaderRead_BlockSize() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The type id field from the object header.</returns>
		[[nodiscard]]
		auto IMMUTATOR HeaderRead_TypeId() const noexcept -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The flag vector field from the object header.</returns>
		[[nodiscard]]
		auto IMMUTATOR Header_ReadFlagVector() const noexcept -> ObjectFlagsVectorCompound;

		/// <summary>
		/// Writes the value into the strong ref count header field.
		/// </summary>
		/// <param name="strongRefCount">The new value to write.</param>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_StrongRefCount(std::uint32_t strongRefCount) const noexcept -> void;

		/// <summary>
		/// Increments the object header strong reference counter by one.
		/// </summary>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_IncrementStrongRefCount() const noexcept -> void;

		/// <summary>
		/// Decrements the object header strong reference counter by one.
		/// </summary>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_DecrementStrongRefCount() const noexcept -> void;

		/// <summary>
		/// Same as HeaderWrite_IncrementStrongRefCount()
		/// </summary>
		/// <returns></returns>
		auto MUTATOR operator ++() const noexcept -> void;

		/// <summary>
		/// Same as HeaderWrite_DecrementStrongRefCount()
		/// </summary>
		/// <returns></returns>
		auto MUTATOR operator --() const noexcept -> void;

		/// <summary>
		/// Same as HeaderWrite_IncrementStrongRefCount()
		/// </summary>
		/// <returns></returns>
		auto MUTATOR operator ++(int) const noexcept -> void;

		/// <summary>
		/// Same as HeaderWrite_DecrementStrongRefCount()
		/// </summary>
		/// <returns></returns>
		auto MUTATOR operator --(int) const noexcept -> void;

		/// <summary>
		/// Writes the value of size into the Size object header field.
		/// </summary>
		/// <param name="size">The new value to write.</param>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_Size(std::uint32_t size) const noexcept -> void;

		/// <summary>
		/// Writes the value of typeId into the TypeId object header field.
		/// </summary>
		/// <param name="typeId">The new value to write.</param>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_TypeId(std::uint32_t typeId) const noexcept -> void;

		/// <summary>
		/// Writes the value of flagVector into the ObjectFlags object header field.
		/// </summary>
		/// <param name="flagVector">The new value to write.</param>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_FlagVector(ObjectFlagsVectorCompound flagVector) const noexcept -> void;

		/// <summary>
		/// Get the raw object header pointer.
		/// </summary>
		/// <returns>The object header pointer.</returns>
		[[nodiscard]]
		auto IMMUTATOR QueryRawHeader() const noexcept -> BlobBlockType*;

		/// <summary>
		/// Get the object header.
		/// </summary>
		/// <returns>The object header.</returns>
		[[nodiscard]]
		auto IMMUTATOR QueryHeader() const noexcept -> ObjectHeader;

		/// <summary>
		/// Get underlying object block.
		/// </summary>
		/// <returns>The begin pointer of the underlying object block.</returns>
		[[nodiscard]]
		auto IMMUTATOR LookupObjectBlock() const noexcept -> BlobBlockType*;

		/// <summary>
		/// Get underlying object block end iterator.
		/// </summary>
		/// <returns>The end pointer of the underlying object block.</returns>
		[[nodiscard]]
		auto IMMUTATOR LookupObjectBlockEnd() const noexcept -> BlobBlockType*;

		/// <summary>
		/// Checks if the underlying object block is null, but the object header is null.
		/// </summary>
		/// <returns>True if the underlying object is null, else false.</returns>
		[[nodiscard]]
		auto IMMUTATOR IsUnderlyingObjectBlockNull() const noexcept -> bool;

		/// <summary>
		/// Checks if the whole data blob (underlying object) and the object header is null.
		/// </summary>
		/// <returns>true if the whole data blob (underlying object) and the object header is null, else false.</returns>
		[[nodiscard]]
		auto IMMUTATOR IsBlobNull() const noexcept -> bool;

		/// <summary>
		/// The size in records of the whole data blob:
		/// header + object
		/// </summary>
		/// <returns>The size in records of the object header plus the size of object it self.</returns>
		[[nodiscard]]
		auto IMMUTATOR BlobSize() const noexcept -> std::size_t;

		/// <summary>
		/// The size in bytes of the whole data blob:
		/// header + object
		/// </summary>
		/// <returns>The size in bytes of the whole object header plus the whole size of object it self.</returns>
		[[nodiscard]]
		auto IMMUTATOR BlobSizeInBytes() const noexcept -> std::size_t;

		/// <summary>
		/// Returns the size of the object block in bytes.
		/// Same as HeaderRead_BlockSize() * sizeof(Record) 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto IMMUTATOR ObjectBlockSizeInBytes() const noexcept -> std::size_t;

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
		auto IMMUTATOR begin() const noexcept -> BlobBlockType*;

		/// <summary>
		/// SLT-Compat
		/// Required for range loops, same as end(object)
		/// </summary>
		/// <returns>End iterator.</returns>
		[[nodiscard]]
		// ReSharper disable once CppInconsistentNaming
		auto IMMUTATOR end() const noexcept -> BlobBlockType*;

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
		auto IMMUTATOR operator *() const noexcept -> BlobBlockType*;

		/// <summary>
		/// Lookup object block.
		/// </summary>
		/// <returns></returns>
		auto IMMUTATOR operator ->() const noexcept -> BlobBlockType*;

		/// <summary>
		/// Lookup object block end.
		/// </summary>
		/// <returns></returns>
		auto IMMUTATOR operator ~() const noexcept -> BlobBlockType*;

		/// <summary>
		/// Unchecked subscript in object block.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto IMMUTATOR operator [](std::size_t idx) noexcept -> BlobBlockType&;

		/// <summary>
		/// Unchecked subscript in object block.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto IMMUTATOR operator [](std::size_t idx) const noexcept -> BlobBlockType;

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
		static auto ShallowCmp(Object a, Object b) noexcept -> bool;

		/// <summary>
		/// Compares the values of the object block of the two objects.
		/// This is overkill for most cases, pointer comparison can be enough.
		/// </summary>
		/// <param name="a">The first object.</param>
		/// <param name="b">The second object to compare to first.</param>
		/// <returns>True if the object block data is equal, else false.</returns>
		[[nodiscard]]
		static auto DeepCmp(Object a, Object b) noexcept -> bool;

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
		static auto DeepValueCmp_Equal(Object a, Object b) noexcept -> bool;


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
		static auto DeepValueCmp_NotEqual(Object a, Object b) noexcept -> bool;

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
		static auto DeepValueCmp_Less(Object a, Object b) noexcept -> bool;

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
		static auto DeepValueCmp_LessEqual(Object a, Object b) noexcept -> bool;

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
		static auto DeepValueCmp_Greater(Object a, Object b) noexcept -> bool;

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
		static auto DeepValueCmp_GreaterEqual(Object a, Object b) noexcept -> bool;

		/// <summary>
		/// Deleter for unique objects allocated with std::unique_ptr.
		/// </summary>
		struct UniquePtrObjectDeleter final
		{
			inline auto operator()(Object* const target) const noexcept -> void
			{
				delete[] target->Blob;
				delete target;
			}
		};

		/// <summary>
		/// Allocates a mock object for use in tests or debug stuff.
		/// Do not use for real allocation!
		/// </summary>
		/// <param name="sizeInRecords">BUG-PRONE The size of the object in RECORDS NOT in BYTES</param>
		/// <returns>The mock object.</returns>
		static auto AllocateUnique(std::uint32_t sizeInRecords) noexcept -> std::unique_ptr<Object, UniquePtrObjectDeleter>;
	};

	static_assert(sizeof(Object) == sizeof(Object::BlobBlockType*));
	static_assert(std::is_standard_layout_v<Object>);

	/// <summary>
	/// Prevent using with invalid type.
	/// Allowed are the record types:
	/// std::uint64_t
	/// std::int64_t
	/// double
	/// char32_t
	/// void*
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
    [[deprecated("invalid type for specialization")]]
    inline auto Object::DeepValueCmp_Equal([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) noexcept -> bool
	{
		return false;
	}

	/// <summary>
	/// Specialization for bitwise compare of std::uint64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are equal, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Equal<std::uint64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of std::int64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are equal, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Equal<std::int64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of double.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are equal, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Equal<double>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of char32_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are equal, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Equal<char32_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of void*.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are equal, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Equal<void*>(Object a, Object b) noexcept -> bool;

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_Equal<char32_t>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Equal<std::uint64_t>(a, b);
	}

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_Equal<void*>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Equal<std::uint64_t>(a, b);
	}

	/// <summary>
	/// Prevent using with invalid type.
	/// Allowed are the record types:
	/// std::uint64_t
	/// std::int64_t
	/// double
	/// char32_t
	/// void*
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
    inline auto Object::DeepValueCmp_NotEqual([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) noexcept -> bool
	{
        assert(false);
		return false;
	}

	/// <summary>
	/// Specialization for bitwise compare of std::uint64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all not equal, else false.</returns>
	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_NotEqual<std::uint64_t>(const Object a, const Object b) noexcept -> bool
	{
		return !DeepValueCmp_Equal<std::uint64_t>(a, b);
	}

	/// <summary>
	/// Specialization for bitwise compare of std::int64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all not equal, else false.</returns>
	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_NotEqual<std::int64_t>(const Object a, const Object b) noexcept -> bool
	{
		return !DeepValueCmp_Equal<std::int64_t>(a, b);
	}

	/// <summary>
	/// Specialization for bitwise compare of double.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all not equal, else false.</returns>
	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_NotEqual<double>(const Object a, const Object b) noexcept -> bool
	{
		return !DeepValueCmp_Equal<double>(a, b);
	}

	/// <summary>
	/// Specialization for bitwise compare of char32_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all not equal, else false.</returns>
	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_NotEqual<char32_t>(const Object a, const Object b) noexcept -> bool
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
	__attribute__((flatten)) inline auto Object::DeepValueCmp_NotEqual<void*>(const Object a, const Object b) noexcept -> bool
	{
		return !DeepValueCmp_Equal<void*>(a, b);
	}

	/// <summary>
	/// Prevent using with invalid type.
	/// Allowed are the record types:
	/// std::uint64_t
	/// std::int64_t
	/// double
	/// char32_t
	/// void*
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
    inline auto Object::DeepValueCmp_Less([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) noexcept -> bool
	{
        assert(false);
		return false;
	}

	/// <summary>
	/// Specialization for bitwise compare of std::uint64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Less<std::uint64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of std::int64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less else false.</returns>
	template <>
	auto Object::DeepValueCmp_Less<std::int64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of double.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Less<double>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of char32_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Less<char32_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of void*.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Less<void*>(Object a, Object b) noexcept -> bool;

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_Less<char32_t>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Less<std::uint64_t>(a, b);
	}

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_Less<void*>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Less<std::uint64_t>(a, b);
	}

	/// <summary>
	/// Prevent using with invalid type.
	/// Allowed are the record types:
	/// std::uint64_t
	/// std::int64_t
	/// double
	/// char32_t
	/// void*
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
    inline auto Object::DeepValueCmp_LessEqual([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) noexcept -> bool
	{
        assert(false);
		return false;
	}

	/// <summary>
	/// Specialization for bitwise compare of std::uint64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_LessEqual<std::uint64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of std::int64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less else false.</returns>
	template <>
	auto Object::DeepValueCmp_LessEqual<std::int64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of double.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_LessEqual<double>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of char32_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_LessEqual<char32_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of void*.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_LessEqual<void*>(Object a, Object b) noexcept -> bool;

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_LessEqual<char32_t>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Less<std::uint64_t>(a, b);
	}

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_LessEqual<void*>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Less<std::uint64_t>(a, b);
	}

	/// <summary>
	/// Prevent using with invalid type.
	/// Allowed are the record types:
	/// std::uint64_t
	/// std::int64_t
	/// double
	/// char32_t
	/// void*
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
    inline auto Object::DeepValueCmp_Greater([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) noexcept -> bool
	{
        assert(false);
		return false;
	}

	/// <summary>
	/// Specialization for bitwise compare of std::uint64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Greater<std::uint64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of std::int64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less else false.</returns>
	template <>
	auto Object::DeepValueCmp_Greater<std::int64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of double.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Greater<double>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of char32_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Greater<char32_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of void*.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_Greater<void*>(Object a, Object b) noexcept -> bool;

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_Greater<char32_t>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Less<std::uint64_t>(a, b);
	}

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_Greater<void*>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Less<std::uint64_t>(a, b);
	}

	/// <summary>
	/// Prevent using with invalid type.
	/// Allowed are the record types:
	/// std::uint64_t
	/// std::int64_t
	/// double
	/// char32_t
	/// void*
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	template <typename T> requires std::is_standard_layout_v<T> && std::is_trivial_v<T>
    inline auto Object::DeepValueCmp_GreaterEqual([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) noexcept -> bool
	{
        assert(false);
		return false;
	}

	/// <summary>
	/// Specialization for bitwise compare of std::uint64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_GreaterEqual<std::uint64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of std::int64_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less else false.</returns>
	template <>
	auto Object::DeepValueCmp_GreaterEqual<std::int64_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of double.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_GreaterEqual<double>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of char32_t.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_GreaterEqual<char32_t>(Object a, Object b) noexcept -> bool;

	/// <summary>
	/// Specialization for bitwise compare of void*.
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>True if the two object values are all less, else false.</returns>
	template <>
	auto Object::DeepValueCmp_GreaterEqual<void*>(Object a, Object b) noexcept -> bool;

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_GreaterEqual<char32_t>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Less<std::uint64_t>(a, b);
	}

	template <>
	__attribute__((flatten)) inline auto Object::DeepValueCmp_GreaterEqual<void*>(const Object a, const Object b) noexcept -> bool
	{
		return DeepValueCmp_Less<std::uint64_t>(a, b);
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::QueryRawHeader() const noexcept -> BlobBlockType*
	{
		assert(this->Blob != nullptr);
		return this->Blob;
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::QueryHeader() const noexcept -> ObjectHeader
	{
		ObjectHeader header;
		header.MapFromRegionUnchecked(this->QueryRawHeader());
		return header;
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::LookupObjectBlock() const noexcept -> BlobBlockType*
	{
		assert(this->Blob != nullptr);
		return this->Blob + ObjectHeader::RECORD_OFFSET;
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::LookupObjectBlockEnd() const noexcept -> BlobBlockType*
	{
		assert(this->HeaderRead_BlockSize() > 0);
		return this->LookupObjectBlock() + this->HeaderRead_BlockSize();
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::IsUnderlyingObjectBlockNull() const noexcept -> bool
	{
		return this->LookupObjectBlock() == nullptr;
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::IsBlobNull() const noexcept -> bool
	{
		return this->Blob == nullptr;
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::BlobSize() const noexcept -> std::size_t
	{
		return ObjectHeader::RECORD_CHUNKS + ObjectHeader::ReadMapping_Size(this->QueryRawHeader());
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::BlobSizeInBytes() const noexcept -> std::size_t
	{
		return BlobSize() * sizeof(Record);
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::ObjectBlockSizeInBytes() const noexcept -> std::size_t
	{
		return this->HeaderRead_BlockSize() * sizeof(Record);
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::HeaderRead_StrongReferenceCount() const noexcept -> std::uint32_t
	{
		return ObjectHeader::ReadMapping_StrongRefCount(this->QueryRawHeader());
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::HeaderRead_BlockSize() const noexcept -> std::uint32_t
	{
		return ObjectHeader::ReadMapping_Size(this->QueryRawHeader());
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::HeaderRead_TypeId() const noexcept -> std::uint32_t
	{
		return ObjectHeader::ReadMapping_TypeId(this->QueryRawHeader());
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::Header_ReadFlagVector() const noexcept -> ObjectFlagsVectorCompound
	{
		return ObjectHeader::ReadMapping_FlagVector(this->QueryRawHeader());
	}

	__attribute__((flatten)) inline auto MUTATOR Object::HeaderWrite_IncrementStrongRefCount() const noexcept -> void
	{
		ObjectHeader::WriteMapping_IncrementStrongRefCount(this->QueryRawHeader());
	}

	__attribute__((flatten)) inline auto MUTATOR Object::HeaderWrite_DecrementStrongRefCount() const noexcept -> void
	{
		ObjectHeader::WriteMapping_DecrementStrongRefCount(this->QueryRawHeader());
	}

	__attribute__((flatten)) inline auto MUTATOR Object::operator++() const noexcept -> void
	{
		this->HeaderWrite_IncrementStrongRefCount();
	}

	__attribute__((flatten)) inline auto MUTATOR Object::operator--() const noexcept -> void
	{
		this->HeaderWrite_DecrementStrongRefCount();
	}

	__attribute__((flatten)) inline auto MUTATOR Object::operator++(int) const noexcept -> void
	{
		this->HeaderWrite_IncrementStrongRefCount();
	}

	__attribute__((flatten)) inline auto MUTATOR Object::operator--(int) const noexcept -> void
	{
		this->HeaderWrite_DecrementStrongRefCount();
	}

	__attribute__((flatten)) inline auto MUTATOR Object::HeaderWrite_StrongRefCount(const std::uint32_t strongRefCount) const noexcept -> void
	{
		ObjectHeader::WriteMapping_StrongRefCount(this->QueryRawHeader(), strongRefCount);
	}

	__attribute__((flatten)) inline auto MUTATOR Object::HeaderWrite_Size(const std::uint32_t size) const noexcept -> void
	{
		ObjectHeader::WriteMapping_Size(this->QueryRawHeader(), size);
	}

	__attribute__((flatten)) inline auto MUTATOR Object::HeaderWrite_TypeId(const std::uint32_t typeId) const noexcept -> void
	{
		ObjectHeader::WriteMapping_TypeId(this->QueryRawHeader(), typeId);
	}

	__attribute__((flatten)) inline auto MUTATOR Object::HeaderWrite_FlagVector(const ObjectFlagsVectorCompound flagVector) const noexcept -> void
	{
		ObjectHeader::WriteMapping_FlagVector(this->QueryRawHeader(), flagVector);
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::operator*() const noexcept -> BlobBlockType*
	{
		return this->LookupObjectBlock();
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::operator->() const noexcept -> BlobBlockType*
	{
		return this->LookupObjectBlock();
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::operator~() const noexcept -> BlobBlockType*
	{
		return this->LookupObjectBlockEnd();
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::operator[](const std::size_t idx) noexcept -> BlobBlockType&
	{
		return *(this->LookupObjectBlock() + idx);
	}

	__attribute__((flatten)) inline auto IMMUTATOR Object::operator[](const std::size_t idx) const noexcept -> BlobBlockType
	{
		return *(this->LookupObjectBlock() + idx);
	}

	// ReSharper disable once CppInconsistentNaming
	__attribute__((flatten)) inline auto IMMUTATOR Object::begin() const noexcept -> BlobBlockType*
	{
		return this->LookupObjectBlock();
	}

	// ReSharper disable once CppInconsistentNaming
	__attribute__((flatten)) inline auto IMMUTATOR Object::end() const noexcept -> BlobBlockType*
	{
		return this->LookupObjectBlockEnd();
	}

	__attribute__((flatten)) inline auto MUTATOR Object::ZeroObjectBlock() const -> void
	{
		std::memset(this->LookupObjectBlock(), 0, this->ObjectBlockSizeInBytes());
	}

	__attribute__((flatten)) inline auto Object::ShallowCmp(const Object a, const Object b) noexcept -> bool
	{
		return a.Blob == b.Blob;
	}

	/// <summary>
	/// STL Compat Overload
	/// Iterate over object block fields without header.
	/// Begin iterator.
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	// ReSharper disable once CppInconsistentNaming
	__attribute__((flatten)) inline auto begin(const Object object) noexcept -> Object::BlobBlockType*
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
	__attribute__((flatten)) inline auto end(const Object object) noexcept -> Object::BlobBlockType*
	{
		return object.LookupObjectBlockEnd();
	}

#undef MUTATOR
#undef IMMUTATOR

	/// <summary>
	/// Runtime allocator for object instances.
	/// </summary>
	class RuntimeObjectAllocator final
	{
		inline static constinit std::atomic_size_t AllocatedBlocks {0};

	public:
		/// <summary>
		/// Gets the amount of all currently allocated blocks (records).
		/// </summary>
		/// <returns>The amount of all currently allocated blocks (records).</returns>
		static auto GetGlobalAllocatedBlocks() noexcept -> std::size_t;

		/// <summary>
		/// Gets the amount of bytes of all currently allocated blocks (records).
		/// </summary>
		/// <returns>The amount of bytes of all currently allocated blocks (records).</returns>
		static auto GetGlobalAllocatedBytes() noexcept -> std::size_t;

		/// <summary>
		/// Allocate and zero raw memory for an object instance, and write the size into the object header.
		/// The memory is initialized to zero.
		/// The sizeInRecords value is written into the object header field "Size".
		/// On fail, nullptr is returned!
		/// </summary>
		/// <param name="sizeInRecords">The size of the object in bytes.
		/// The final object will be larger because of the object header.
		/// If zero is passed, the allocation will return nullptr.
		/// </param>
		/// <returns>The valid memory on success, else nullptr.</returns>
		static auto RawAllocateAndWriteSize(std::uint32_t sizeInRecords) -> Object::BlobBlockType*;

		/// <summary>
		/// Deallocate raw memory from an object instance.
		/// </summary>
		/// <param name="instance"></param>
		/// <returns></returns>
		static auto RawDeallocate(Object::BlobBlockType*& instance) -> void;
	};

	inline auto RuntimeObjectAllocator::GetGlobalAllocatedBlocks() noexcept -> std::size_t
	{
		return AllocatedBlocks;
	}

	inline auto RuntimeObjectAllocator::GetGlobalAllocatedBytes() noexcept -> std::size_t
	{
		return AllocatedBlocks * sizeof(Object::BlobBlockType);
	}
}
