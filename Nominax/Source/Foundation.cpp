// File: Foundation.cpp
// Author: Mario
// Created: 06.07.2021 4:08 PM
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

#include "../../Nominax/Include/Nominax/Foundation.hpp"
#include "../../Nominax/Include/Nominax/ByteCode.hpp"
#include "../../Nominax/Include/Nominax/Core.hpp"
#include "../../Nominax/Include/Nominax/Asm_x86_64.hpp"

namespace Nominax
{
	namespace Foundation
	{
		auto ILog2DeBruijn(U64 x) -> U64
		{
			static constexpr std::array<U64, 64> DE_BRUIJN_TABLE
			{
				0x00, 0x3A, 0x01, 0x3B,
				0x2F, 0x35, 0x02, 0x3C,
				0x27, 0x30, 0x1B, 0x36,
				0x21, 0x2A, 0x03, 0x3D,
				0x33, 0x25, 0x28, 0x31,
				0x12, 0x1C, 0x14, 0x37,
				0x1E, 0x22, 0x0B, 0x2B,
				0x0E, 0x16, 0x04, 0x3E,
				0x39, 0x2E, 0x34, 0x26,
				0x1A, 0x20, 0x29, 0x32,
				0x24, 0x11, 0x13, 0x1D,
				0x0A, 0x0D, 0x15, 0x38,
				0x2D, 0x19, 0x1F, 0x23,
				0x10, 0x09, 0x0C, 0x2C,
				0x18, 0x0F, 0x08, 0x17,
				0x07, 0x06, 0x05, 0x3F
			};

			x |= x >> UINT64_C(1);
			x |= x >> UINT64_C(2);
			x |= x >> UINT64_C(4);
			x |= x >> UINT64_C(8);
			x |= x >> UINT64_C(16);
			x |= x >> UINT64_C(32);

			return DE_BRUIJN_TABLE[x * UINT64_C(0x03F6EAF2CD271461) >> UINT64_C(58)];
		}

		auto LinearizeCoords2D(const U16 x, const U16 y) -> U32
		{
			static constexpr std::array<U16, 256> MORTON_TABLE
			{
				0x0000, 0x0001, 0x0004, 0x0005, 0x0010, 0x0011, 0x0014, 0x0015,
				0x0040, 0x0041, 0x0044, 0x0045, 0x0050, 0x0051, 0x0054, 0x0055,
				0x0100, 0x0101, 0x0104, 0x0105, 0x0110, 0x0111, 0x0114, 0x0115,
				0x0140, 0x0141, 0x0144, 0x0145, 0x0150, 0x0151, 0x0154, 0x0155,
				0x0400, 0x0401, 0x0404, 0x0405, 0x0410, 0x0411, 0x0414, 0x0415,
				0x0440, 0x0441, 0x0444, 0x0445, 0x0450, 0x0451, 0x0454, 0x0455,
				0x0500, 0x0501, 0x0504, 0x0505, 0x0510, 0x0511, 0x0514, 0x0515,
				0x0540, 0x0541, 0x0544, 0x0545, 0x0550, 0x0551, 0x0554, 0x0555,
				0x1000, 0x1001, 0x1004, 0x1005, 0x1010, 0x1011, 0x1014, 0x1015,
				0x1040, 0x1041, 0x1044, 0x1045, 0x1050, 0x1051, 0x1054, 0x1055,
				0x1100, 0x1101, 0x1104, 0x1105, 0x1110, 0x1111, 0x1114, 0x1115,
				0x1140, 0x1141, 0x1144, 0x1145, 0x1150, 0x1151, 0x1154, 0x1155,
				0x1400, 0x1401, 0x1404, 0x1405, 0x1410, 0x1411, 0x1414, 0x1415,
				0x1440, 0x1441, 0x1444, 0x1445, 0x1450, 0x1451, 0x1454, 0x1455,
				0x1500, 0x1501, 0x1504, 0x1505, 0x1510, 0x1511, 0x1514, 0x1515,
				0x1540, 0x1541, 0x1544, 0x1545, 0x1550, 0x1551, 0x1554, 0x1555,
				0x4000, 0x4001, 0x4004, 0x4005, 0x4010, 0x4011, 0x4014, 0x4015,
				0x4040, 0x4041, 0x4044, 0x4045, 0x4050, 0x4051, 0x4054, 0x4055,
				0x4100, 0x4101, 0x4104, 0x4105, 0x4110, 0x4111, 0x4114, 0x4115,
				0x4140, 0x4141, 0x4144, 0x4145, 0x4150, 0x4151, 0x4154, 0x4155,
				0x4400, 0x4401, 0x4404, 0x4405, 0x4410, 0x4411, 0x4414, 0x4415,
				0x4440, 0x4441, 0x4444, 0x4445, 0x4450, 0x4451, 0x4454, 0x4455,
				0x4500, 0x4501, 0x4504, 0x4505, 0x4510, 0x4511, 0x4514, 0x4515,
				0x4540, 0x4541, 0x4544, 0x4545, 0x4550, 0x4551, 0x4554, 0x4555,
				0x5000, 0x5001, 0x5004, 0x5005, 0x5010, 0x5011, 0x5014, 0x5015,
				0x5040, 0x5041, 0x5044, 0x5045, 0x5050, 0x5051, 0x5054, 0x5055,
				0x5100, 0x5101, 0x5104, 0x5105, 0x5110, 0x5111, 0x5114, 0x5115,
				0x5140, 0x5141, 0x5144, 0x5145, 0x5150, 0x5151, 0x5154, 0x5155,
				0x5400, 0x5401, 0x5404, 0x5405, 0x5410, 0x5411, 0x5414, 0x5415,
				0x5440, 0x5441, 0x5444, 0x5445, 0x5450, 0x5451, 0x5454, 0x5455,
				0x5500, 0x5501, 0x5504, 0x5505, 0x5510, 0x5511, 0x5514, 0x5515,
				0x5540, 0x5541, 0x5544, 0x5545, 0x5550, 0x5551, 0x5554, 0x5555
			};

			return MORTON_TABLE[y >> 8] << 17 | MORTON_TABLE[x >> 8] << 16 | MORTON_TABLE[y & 0xFF] << 1 | MORTON_TABLE[x & 0xFF];
		}

		auto Xorshift32Atomic() -> U32
		{
			static constinit std::atomic_uint32_t seed32 {0x12B9B0A1};
			seed32 ^= seed32 << 0xD;
			seed32 ^= seed32 >> 0x11;
			seed32 ^= seed32 << 0x5;
			return seed32;
		}

		auto Xorshift64Atomic() -> U64
		{
			static constinit std::atomic_uint64_t seed64 {0x139408DCBBF7A44};
			seed64 ^= seed64 << 0xD;
			seed64 ^= seed64 >> 0x7;
			seed64 ^= seed64 << 0x11;
			return seed64;
		}

		auto Xorshift128Atomic() -> U32
		{
			static constinit std::atomic_uint32_t x {0x75BCD15};
			static constinit std::atomic_uint32_t y {0x159A55E5};
			static constinit std::atomic_uint32_t z {0x1F123BB5};
			static constinit std::atomic_uint32_t w {0x5491333};

			const uint32_t t = x ^ x << 0xB;
			x.exchange(y);
			y.exchange(z);
			z.exchange(w);
			w ^= w >> 0xD ^ t ^ t >> 0x8;
			return w;
		}

		auto Xorshift32ThreadLocal() -> U32
		{
			static constinit thread_local U32 seed32 {0x12B9B0A1};
			seed32 ^= seed32 << 0xD;
			seed32 ^= seed32 >> 0x11;
			seed32 ^= seed32 << 0x5;
			return seed32;
		}

		auto Xorshift64ThreadLocal() -> U64
		{
			static constinit thread_local U64 seed64 {0x139408DCBBF7A44};
			seed64 ^= seed64 << 0xD;
			seed64 ^= seed64 >> 0x7;
			seed64 ^= seed64 << 0x11;
			return seed64;
		}

		auto Xorshift128ThreadLocal() -> U32
		{
			static constinit thread_local U32 x {0x75BCD15};
			static constinit thread_local U32 y {0x159A55E5};
			static constinit thread_local U32 z {0x1F123BB5};
			static constinit thread_local U32 w {0x5491333};

			const uint32_t t = x ^ x << 0xB;
			x                = y;
			y                = z;
			z                = w;
			w ^= w >> 0xD ^ t ^ t >> 0x8;
			return w;
		}

		auto IAllocator::Allocate(void*& out, const U64 size) const -> void
		{
			out = SystemAllocator::AllocateChecked(size);
		}

		auto IAllocator::Reallocate(void*& out, const U64 size) const -> void
		{
			out = SystemAllocator::ReallocateChecked(out, size);
		}

		auto IAllocator::Deallocate(void*& out) const -> void
		{
			SystemAllocator::DeallocateChecked(out);
			out = nullptr;
		}

		auto IAllocator::AllocateAligned(void*& out, const U64 size, const U64 alignment) const -> void
		{
			out = SystemAllocator::AllocateAlignedChecked(size, alignment);
		}

		auto IAllocator::ReallocateAligned(void*& out, const U64 size, const U64 alignment) const -> void
		{
			out = SystemAllocator::ReallocateAlignedChecked(out, size, alignment);
		}

		auto IAllocator::DeallocateAligned(void*& out) const -> void
		{
			SystemAllocator::DeallocateAlignedChecked(out);
			out = nullptr;
		}

		auto IAllocator::Valloc(void*& out, const U64 size) const -> void
		{
			this->Allocate(out, size);
		}

		auto IAllocator::Vdealloc(void*& out) const -> void
		{
			this->Deallocate(out);
		}

		CliArgParser::CliArgParser(const signed argc, const char* const* const argv)
		{
			Args_.reserve(argc);
			Args_.insert(argv, argc + argv);
		}

		auto CliArgParser::AddOption(const std::string_view name, const std::string_view description) -> bool
		{
			Options_.emplace_back(std::make_pair(name, description));
			return this->HasFlag(name);
		}

		auto CliArgParser::PrintAllOptions() -> void
		{
			for (const auto& [k, v] : this->Options_)
			{
				Print("{} = {}\n", k, v);
			}
		}

		auto CliArgParser::IsEmpty() const -> bool
		{
			return this->Args_.size() <= 1;
		}

		auto CliArgParser::GetArgs() const -> const std::unordered_set<std::string_view>&
		{
			return this->Args_;
		}

		auto CliArgParser::GetOptions() const -> const std::vector<std::pair<std::string_view, std::string_view>>&
		{
			return this->Options_;
		}

		auto CliArgParser::HasFlag(const std::string_view key) -> bool
		{
			return std::ranges::find(this->Args_, key) != this->Args_.end();
		}

		static constexpr auto GetMemoryUnitInfo(const U64 bytes) -> std::pair<U64, std::string_view>
		{
			if (bytes == 0 || bytes < KB)
			{
				return {bytes, "B"};
			}
			if (bytes < MB)
			{
				return {bytes / KB, "KB"};
			}
			if (bytes < GB)
			{
				return {bytes / MB, "MB"};
			}
			if (bytes < TB)
			{
				return {bytes / GB, "GB"};
			}
			return {bytes, "B"};
		}

		auto DebugAllocator::Allocate(void*& out, const U64 size) const -> void
		{
			IAllocator::Allocate(out, size);
			const auto [count, suffix] {GetMemoryUnitInfo(size)};
			Print(TextColor::BrightGreen, "Allocate({:#X}, {} {})\n", reinterpret_cast<Uip64>(out), count, suffix);
			++this->Allocations_;
			this->BytesAllocated_ += size;
		}

		auto DebugAllocator::Reallocate(void*& out, const U64 size) const -> void
		{
			IAllocator::Reallocate(out, size);
			const auto [count, suffix] {GetMemoryUnitInfo(size)};
			Print(TextColor::BrightYellow, "Reallocate({:#X}, {} {})\n", reinterpret_cast<Uip64>(out), count,
			      suffix);
			++this->Reallocations_;
		}

		auto DebugAllocator::Deallocate(void*& out) const -> void
		{
			Print(TextColor::BrightRed, "Deallocate({:#X})\n", reinterpret_cast<Uip64>(out));
			IAllocator::Deallocate(out);
			++this->Deallocations_;
		}

		auto DebugAllocator::AllocateAligned(void*& out, const U64 size, const U64 alignment) const -> void
		{
			IAllocator::AllocateAligned(out, size, alignment);
			const auto [count, suffix] {GetMemoryUnitInfo(size)};
			Print(TextColor::BrightGreen, "AllocateAligned({:#X}, {} {}, {} A)\n", reinterpret_cast<Uip64>(out),
			      count, suffix, alignment);
			++this->Allocations_;
			this->BytesAllocated_ += size;
		}

		auto DebugAllocator::ReallocateAligned(void*& out, const U64 size, const U64 alignment) const -> void
		{
			IAllocator::ReallocateAligned(out, size, alignment);
			const auto [count, suffix] {GetMemoryUnitInfo(size)};
			Print(TextColor::BrightGreen, "ReallocateAligned({:#X}, {} {}, {} A)\n", reinterpret_cast<Uip64>(out),
			      count, suffix, alignment);
			++this->Reallocations_;
		}

		auto DebugAllocator::DeallocateAligned(void*& out) const -> void
		{
			Print(TextColor::BrightRed, "DeallocateAligned({:#X})\n", reinterpret_cast<Uip64>(out));
			IAllocator::DeallocateAligned(out);
			++this->Deallocations_;
		}

		auto DebugAllocator::DumpAllocationInfo() const -> void
		{
			const auto [count, suffix] {GetMemoryUnitInfo(this->BytesAllocated_)};
			Print(TextColor::BrightGreen, "Allocations: {}\n", this->Allocations_);
			Print(TextColor::BrightGreen, "Reallocations: {}\n", this->Reallocations_);
			Print(TextColor::BrightGreen, "Deallocations: {}\n", this->Deallocations_);
			Print(TextColor::BrightGreen, "Total: {} {}\n", count, suffix);
			if (this->Allocations_ != this->Deallocations_)
			{
				Print(TextColor::BrightYellow, "Missing allocations: {}\n", this->Allocations_ - this->Deallocations_);
			}
			Print(TextColor::BrightYellow, "Warning! Some global shutdown deallocations might not be tracked!\n");
		}

		auto SafeLocalTime(const std::time_t& time) -> std::tm
		{
			std::tm buffer { };
			#if NOX_COM_GCC
			localtime_r(&time, &buffer);
			#elif NOX_OS_WINDOWS
		localtime_s(&buffer, &time);
			#else
		static std::mutex mtx;
		std::lock_guard<std::mutex> lock(mtx);
		buffer = *std::localtime(&_time);
			#endif
			return buffer;
		}

		auto ISerializable::SerializeToFile(const std::filesystem::path& file) const -> bool
		{
			std::ofstream stream {file};
			if (!stream)
			{
				[[unlikely]]
					return false;
			}
			return this->Serialize(stream);
		}

		auto ISerializable::DeserializeFromFile(const std::filesystem::path& file) -> bool
		{
			std::ifstream stream {file};
			if (!stream)
			{
				[[unlikely]]
					return false;
			}
			return this->Deserialize(stream);
		}

		/// <summary>
		/// Global per thread signal status.
		/// </summary>
		constinit volatile thread_local std::sig_atomic_t SignalStatus {0};

		auto QuerySignalStatus() -> std::sig_atomic_t
		{
			return SignalStatus;
		}

		auto InstallSignalHandlers(auto (&handler)(std::sig_atomic_t) -> void) -> void
		{
			std::signal(SIGINT, &handler);
			std::signal(SIGILL, &handler);
			std::signal(SIGFPE, &handler);
			std::signal(SIGSEGV, &handler);
			std::signal(SIGTERM, &handler);
			std::signal(SIGABRT, &handler);
		}

		auto UninstallSignalHandlers() -> void
		{
			std::signal(SIGINT, SIG_DFL);
			std::signal(SIGILL, SIG_DFL);
			std::signal(SIGFPE, SIG_DFL);
			std::signal(SIGSEGV, SIG_DFL);
			std::signal(SIGTERM, SIG_DFL);
			std::signal(SIGABRT, SIG_DFL);
		}

		[[nodiscard]]
		static inline auto SubstringView
		(
			const TextFile::StringType&         source,
			const size_t                        offset = 0,
			const TextFile::ViewType::size_type count  = std::numeric_limits<TextFile::ViewType::size_type>::max()
		) -> TextFile::ViewType
		{
			if (offset < source.size())
			[[likely]]
			{
				return
				{
					source.data() + offset,
					std::min(source.size() - offset, count)
				};
			}
			return { };
		}

		static inline auto SubstringView
		(
			std::string&&               source,
			size_t                      offset = 0,
			std::string_view::size_type count  = std::numeric_limits<std::string_view::size_type>::max()
		) -> std::string_view = delete;

		auto TextFile::WriteToFile(std::filesystem::path&& path) -> bool
		{
			this->FilePath_ = std::move(path);
			std::ofstream stream {this->FilePath_};
			if (!stream)
			{
				[[likely]]
					return false;
			}
			stream << this->Content_;
			return true;
		}

		auto TextFile::ReadFromFile(std::filesystem::path&& path) -> bool
		{
			this->FilePath_ = std::move(path);
			std::ifstream stream {this->FilePath_};
			if (!stream)
			{
				[[unlikely]]
					return false;
			}
			stream.seekg(0, std::ios::end);
			this->Content_.resize(stream.tellg());
			stream.seekg(0, std::ios::beg);
			stream.read(std::data(this->Content_), std::size(this->Content_));
			return true;
		}

		auto TextFile::ReadFromFileOrPanic(std::filesystem::path&& path) -> void
		{
			if (!this->ReadFromFile(std::move(path)))
			{
				[[unlikely]]
					Panic(NOX_PANIC_INFO(), "Failed to read text file from path: {}", path.string());
			}
		}

		auto TextFile::ParallelEraseSpaces() -> void
		{
			this->Content_.erase
			(
				std::remove_if(std::execution::par_unseq, std::begin(this->Content_), std::end(this->Content_),
				               [](const char c) -> bool
				               {
					               return c == ' ';
				               }),
				std::end(this->Content_)
			);
		}

		auto TextFile::ParallelEraseSpacesAndControlChars() -> void
		{
			this->Content_.erase
			(
				std::remove_if(std::execution::par_unseq, std::begin(this->Content_), std::end(this->Content_),
				               [](const char c) -> bool
				               {
					               return std::isspace<char>(c, std::locale::classic());
				               }),
				std::end(this->Content_)
			);
		}

		auto TextFile::ParallelErase(const CharType x) -> void
		{
			this->Content_.erase
			(
				std::remove_if(std::execution::par_unseq, std::begin(this->Content_), std::end(this->Content_),
				               [x](const char c) -> bool
				               {
					               return c == x;
				               }),
				std::end(this->Content_)
			);
		}

		auto TextFile::EraseRange(const CharType begin, const CharType end) -> void
		{
			const U64 beginIndex {this->Content_.find(begin)};
			const U64 endIndex {this->Content_.find(end, beginIndex + 1)};
			this->Content_.erase(beginIndex, endIndex - beginIndex + 1);
		}

		auto TextFile::SubString(const U64 beginIdx, const U64 endIdx) const -> ViewType
		{
			return SubstringView(this->Content_, beginIdx, endIdx - beginIdx + 1);
		}

		auto TextFile::SubStringChar(const CharType beginChar, const CharType endChar) const -> ViewType
		{
			const U64 beginIndex {this->Content_.find_first_of(beginChar)};
			const U64 endIndex {this->Content_.find_first_of(endChar, beginIndex + 1)};
			return SubstringView(this->Content_, beginIndex, endIndex - beginIndex + 1);
		}

		auto Object::ShallowCopyObjectBlockToBuffer(const std::span<Record> buffer) const -> bool
		{
			if (buffer.size() < this->HeaderRead_BlockSize())
			{
				[[unlikely]]
					return false;
			}

			std::memcpy(buffer.data(), this->LookupObjectBlock(), this->ObjectBlockSizeInBytes());

			return true;
		}

		auto Object::ShallowCopyObjectBlockToBuffer(std::vector<Record>& buffer) const -> void
		{
			buffer.resize(this->HeaderRead_BlockSize());
			std::memcpy(buffer.data(), this->LookupObjectBlock(), this->ObjectBlockSizeInBytes());
		}

		auto Object::CopyBlob(std::vector<Record>& buffer) const -> void
		{
			buffer.resize(this->BlobSize());
			std::memcpy(buffer.data(), this->Blob_, this->BlobSizeInBytes());
		}

		auto Object::DeepCmp(const Object a, const Object b) -> bool
		{
			return a.HeaderRead_BlockSize() == b.HeaderRead_BlockSize()
				&& std::memcmp(a.LookupObjectBlock(), b.LookupObjectBlock(), a.ObjectBlockSizeInBytes()) == 0;
		}

		auto Object::AllocateUnique(const U32 sizeInRecords) -> std::unique_ptr<Object, UniquePtrObjectDeleter>
		{
			if (sizeInRecords == 0)
			{
				[[unlikely]]
					return nullptr;
			}
			const U32                finalObjectSize {ObjectHeader::RECORD_CHUNKS + sizeInRecords};
			auto* NOX_RESTRICT const object {new Record[finalObjectSize]()};

			// Write object header:
			ObjectHeader::WriteMapping_MetaField(object, 0);

			// !! Important !! Write the size:
			ObjectHeader::WriteMapping_Size(object, sizeInRecords);

			// Use pointer as dummy type id:
			ObjectHeader::WriteMapping_TypeId(object, 0);

			// Write empty flag vector:
			ObjectHeader::WriteMapping_FlagVector(object, ObjectFlagVector { });

			return std::unique_ptr<Object, UniquePtrObjectDeleter>
			{
				new Object {object},
				UniquePtrObjectDeleter()
			};
		}

		template <>
		auto Object::DeepValueCmp_Equal<U64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (x->AsU64 != y->AsU64)
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_Equal<I64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (x->AsI64 != y->AsI64)
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_Equal<F64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (x->AsF64 != y->AsF64)
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_Less<U64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsU64 < y->AsU64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_Less<I64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsI64 < y->AsI64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_Less<F64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsF64 < y->AsF64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_LessEqual<U64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsU64 <= y->AsU64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_LessEqual<I64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsI64 <= y->AsI64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_LessEqual<F64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsF64 <= y->AsF64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_Greater<U64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsU64 > y->AsU64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_Greater<I64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsI64 > y->AsI64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_Greater<F64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsF64 > y->AsF64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_GreaterEqual<U64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsU64 >= y->AsU64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_GreaterEqual<I64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsI64 >= y->AsI64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}

		template <>
		auto Object::DeepValueCmp_GreaterEqual<F64>(const Object a, const Object b) -> bool
		{
			// If their size is not equal, their values cannot be equal too.
			if (a.HeaderRead_BlockSize() != b.HeaderRead_BlockSize())
			{
				return false;
			}

			const auto* x {*a};
			const auto* w {~a};
			const auto* y {*b};

			while (x < w)
			{
				if (!(x->AsF64 >= y->AsF64))
				{
					return false;
				}
				++x;
				++y;
			}

			return true;
		}
	}

	auto PanicTerminationImpl(const PanicDescriptor& panicDescriptor) -> void
	{
		using namespace Foundation;

		#if NOX_ARCH_X86_64
		U64   gpr[16] { };
		U64   sse[32] { };
		Uip64 rip { };
		if (panicDescriptor.DumpRegisters)
		{
			using namespace Assembler::X86_64::Routines;
			QueryRegSet(gpr, sse);
			rip = reinterpret_cast<U64>(QueryRip());
		}
		#endif

		Print(TextColor::Red, "\n! NOMINAX RUNTIME PANIC !\n");
		Print
		(
			"File: {}\nLine: {}\nSubroutine: {}\n",
			panicDescriptor.FileName,
			panicDescriptor.Line,
			panicDescriptor.RoutineName
		);
		Print("{}\n", panicDescriptor.Message);

		#if NOX_ARCH_X86_64
		if (panicDescriptor.DumpRegisters)
		{
			Print("%rip = {:016X}\n", rip);
			static constexpr std::array<std::string_view, 16> GPR_LUT
			{
				"%rax",
				"%rbx",
				"%rcx",
				"%rdx",
				"%rsi",
				"%rdi",
				"%rsp",
				"%rbp",
				"%r8 ",
				"%r9 ",
				"%r10",
				"%r11",
				"%r12",
				"%r13",
				"%r14",
				"%r15"
			};
			for (U64 i {0}; i < sizeof gpr / sizeof *gpr; ++i)
			{
				Print("{} = {:016X}\n", GPR_LUT[i], gpr[i]);
			}
			for (U64 i {0}; i < sizeof sse / sizeof *sse >> 1; ++i)
			{
				Print("%xmm{}{} = ", i, i < 10 ? " " : "");
				Print("{:016X}", sse[i]);
				Print("{:016X}\n", sse[i + 1]);
			}
		}
		#endif

		std::cout.flush();
		std::abort();
	}
}

auto operator new(const Nominax::U64 size) -> void*
{
	void* mem;
	Nominax::Foundation::GlobalAllocatorProxy->Allocate(mem, size);
	return mem;
}

auto operator new[](const Nominax::U64 size) -> void*
{
	void* mem;
	Nominax::Foundation::GlobalAllocatorProxy->Allocate(mem, size);
	return mem;
}

#if false

auto operator new(const Nominax::U64 size, const std::align_val_t alignment)  -> void*
{
	void* mem;
	Nominax::Common::GlobalAllocatorProxy->AllocateAligned(mem, size, static_cast<U64>(alignment));
	return mem;
}

auto operator new[](const Nominax::U64 size, const std::align_val_t alignment)  -> void*
{
	void* mem;
	Nominax::Common::GlobalAllocatorProxy->AllocateAligned(mem, size, static_cast<U64>(alignment));
	return mem;
}

#endif

auto operator new(const Nominax::U64 size, [[maybe_unused]] const std::nothrow_t& tag) noexcept(true) -> void*
{
	void* mem;
	Nominax::Foundation::GlobalAllocatorProxy->Allocate(mem, size);
	return mem;
}

auto operator new[](const Nominax::U64 size, [[maybe_unused]] const std::nothrow_t& tag) noexcept(true) -> void*
{
	void* mem;
	Nominax::Foundation::GlobalAllocatorProxy->Allocate(mem, size);
	return mem;
}

#if false

auto operator new(const Nominax::U64 size, const std::align_val_t alignment, [[maybe_unused]] const std::nothrow_t& tag)  -> void*
{
	void* mem;
	Nominax::Common::GlobalAllocatorProxy->AllocateAligned(mem, size, static_cast<U64>(alignment));
	return mem;
}

auto operator new[](const Nominax::U64 size, const std::align_val_t alignment, [[maybe_unused]] const std::nothrow_t& tag)  -> void*
{
	void* mem;
	Nominax::Common::GlobalAllocatorProxy->AllocateAligned(mem, size, static_cast<U64>(alignment));
	return mem;
}

#endif

auto operator delete(void* mem) noexcept(true) -> void
{
	Nominax::Foundation::GlobalAllocatorProxy->Deallocate(mem);
}

auto operator delete(void* mem, Nominax::U64) noexcept(true) -> void
{
	Nominax::Foundation::GlobalAllocatorProxy->Deallocate(mem);
}

auto operator delete[](void* mem) noexcept(true) -> void
{
	Nominax::Foundation::GlobalAllocatorProxy->Deallocate(mem);
}

auto operator delete[](void* mem, Nominax::U64) noexcept(true) -> void
{
	Nominax::Foundation::GlobalAllocatorProxy->Deallocate(mem);
}

namespace Nominax::Foundation
{
	CpuFeatureDetector::CpuFeatureDetector() : FeatureBits_ { }
	{
		#if NOX_ARCH_X86_64

		using namespace Assembler::X86_64::Routines;
		using Cfb = CpuFeatureBits;

		// check if cpuid is supported on system
		NOX_PAS_TRUE(IsCpuIdSupported(), "CPUID instruction is not supported on system!");

		// extract gathered CPU feature bits:
		CpuFeatureMaskBuffer buffer { };
		std::array<U64, 3>   merged { };
		U32                  result;
		result = CpuId(&merged[0], &merged[1], &merged[2]);
		U8* const needle {std::data(buffer)};
		std::memcpy(needle, std::data(merged), sizeof merged);
		std::memcpy(needle + sizeof merged, &result, sizeof result);
		for (U64 i {0}; i < sizeof buffer; ++i)
		{
			for (U64 j {0}; j < CHAR_BIT; ++j)
			{
				this->FeatureBits_[i * CHAR_BIT + j] = buffer[i] & 1 << j;
			}
		}

		// Check if CPU and OS supports XSave
		const bool xSaveSupport {(*this)[Cfb::XSave] && (*this)[Cfb::OsXSave]};
		if (!xSaveSupport)
		{
			// XSave is required for AVX and AVX 512
			[[unlikely]]
			return;
		}

		// Validate OS support and update flags for AVX:
		const bool avxOsSupport {IsAvxSupportedByOs()};
		(*this)[Cfb::Avx] &= avxOsSupport;
		(*this)[Cfb::Avx2] &= avxOsSupport;
		(*this)[Cfb::F16C] &= avxOsSupport;

		// Validate OS support and update flags for AVX-512 F:
		const bool avx512OsSupport {avxOsSupport && IsAvx512SupportedByOs()};
		(*this)[Cfb::Avx512F] &= avx512OsSupport;
		(*this)[Cfb::Avx512Dq] &= avx512OsSupport;
		(*this)[Cfb::Avx512Ifma] &= avx512OsSupport;
		(*this)[Cfb::Avx512Pf] &= avx512OsSupport;
		(*this)[Cfb::Avx512Er] &= avx512OsSupport;
		(*this)[Cfb::Avx512Cd] &= avx512OsSupport;
		(*this)[Cfb::Avx512Bw] &= avx512OsSupport;
		(*this)[Cfb::Avx512Vl] &= avx512OsSupport;
		(*this)[Cfb::Avx512Vbmi] &= avx512OsSupport;
		(*this)[Cfb::Avx512Vmbi2] &= avx512OsSupport;
		(*this)[Cfb::Avx512Gfni] &= avx512OsSupport;
		(*this)[Cfb::Avx512Vnni] &= avx512OsSupport;
		(*this)[Cfb::Avx512Bitalg] &= avx512OsSupport;
		(*this)[Cfb::Avx512PopCntdq] &= avx512OsSupport;
		(*this)[Cfb::Avx512Vnniw4] &= avx512OsSupport;
		(*this)[Cfb::Avx512FMaps4] &= avx512OsSupport;
		(*this)[Cfb::Avx512Vp2Intersect] &= avx512OsSupport;

		#else
			#error "Unimplemented architecture!"
		#endif
	}

	auto CpuFeatureDetector::Dump() const -> void
	{
		Print("CPU feature detection result:\n");
		for (U64 i {0}; i < std::size(this->FeatureBits_); ++i)
		{
			if (!std::empty(CPU_FEATURE_BIT_NAMES[i]))
			{
				Print("{}: {}\n", CPU_FEATURE_BIT_NAMES[i], this->FeatureBits_[i]);
			}
		}
	}

	Snapshot::Snapshot()
	{
		this->QueryAll();
	}

	auto Snapshot::QueryAll() -> void
	{
		this->ThreadCount       = std::thread::hardware_concurrency();
		this->ThreadId          = std::this_thread::get_id();
		this->CpuName           = Os::QueryCpuName();
		this->TotalSystemMemory = Os::QuerySystemMemoryTotal();
		this->ProcessMemory     = Os::QueryProcessMemoryUsed();
		this->PageSize          = Os::QueryPageSize();
	}

	auto Snapshot::Print() const -> void
	{
		using namespace Foundation;

		const auto&
		[
			ThreadId,
			OperatingSystemName,
			ArchitectureName,
			CompilerName,
			ThreadCount,
			CpuName,
			TotalSystemMemory,
			UsedSystemMemory,
			PageSize
		] = *this;

		Foundation::Print("Boot date: {:%A %c}\n", SafeLocalTime(std::time(nullptr)));
		Foundation::Print("TID: {:#X}\n", std::hash<std::thread::id>()(ThreadId));
		Foundation::Print("CPU: {}\n", CpuName);
		Foundation::Print("CPU Hardware threads: {}\n", ThreadCount);
		Foundation::Print("CPU Machine class: {}\n", static_cast<char>(MachineRating(ThreadCount)));
		Foundation::Print("System memory: {}MB\n", Bytes2Megabytes(TotalSystemMemory));
		Foundation::Print("Process memory: {}MB\n", Bytes2Megabytes(UsedSystemMemory));
		Foundation::Print("Page size: {}B\n", PageSize);
	}
}

#if NOX_OS_LINUX

#include <cstdio>
#include <fstream>
#include <string>

#include <dlfcn.h>
#include <unistd.h>

	namespace Nominax::Foundation
	{
		auto Os::QuerySystemMemoryTotal()  -> U64
		{
			const long pages = sysconf(_SC_PHYS_PAGES);
			const long page_size = sysconf(_SC_PAGE_SIZE);
			return static_cast<U64>(pages * page_size);
		}

		auto Os::QueryProcessMemoryUsed()  -> U64 {
			auto* const file = fopen("/proc/self/statm", "r");
			if (file == nullptr)
			{
				return 0;
			}
			long pages = 0;
			const auto items = fscanf(file, "%*s%ld", &pages);
			fclose(file);
			return static_cast<U64>(items == 1 ? pages * sysconf(_SC_PAGESIZE) : 0);
		}

		auto Os::QueryCpuName()  -> std::string
		{
			std::ifstream cpuinfo("/proc/cpuinfo");

			if (!cpuinfo.is_open() || !cpuinfo)
			{
				return "Unknown";
			}

			for (std::string line; std::getline(cpuinfo, line); )
			{
				if (line.find("model name") == 0)
				{
					const auto colon_id = line.find_first_of(':');
					const auto nonspace_id = line.find_first_not_of(" \t", colon_id + 1);
					return line.c_str() + nonspace_id;
				}
			}

			return {};
		}

		auto Os::QueryPageSize() ->U64
		{
			return static_cast<U64>(sysconf(_SC_PAGE_SIZE));
		}

		auto Os::DylibOpen(const std::string_view file_)  -> void*
		{
			return ::dlopen(file_.data(), RTLD_LOCAL | RTLD_LAZY);
		}

		auto Os::DylibLookupSymbol(void* const handle_, const std::string_view symbol_)  -> void*
		{
			return ::dlsym(handle_, symbol_.data());
		}

		auto Os::DylibClose(void*& handle_)  -> void
		{
			::dlclose(handle_);
			handle_ = nullptr;
		}
	}

#endif

#if NOX_OS_WINDOWS

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinUser.h>
#include <Psapi.h>

namespace Nominax::Foundation
{
	auto Os::QuerySystemMemoryTotal() -> U64
	{
		MEMORYSTATUSEX status;
		status.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&status);
		return status.ullTotalPhys;
	}

	auto Os::QueryProcessMemoryUsed() -> U64
	{
		PROCESS_MEMORY_COUNTERS pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof pmc);
		return pmc.WorkingSetSize;
	}

	auto Os::QueryCpuName() -> std::string
	{
		HKEY key;
		if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, R"(HARDWARE\DESCRIPTION\System\CentralProcessor\0)", 0, KEY_READ,
		                  &key))
		{
			return "Unknown";
		}
		TCHAR id[64 + 1];
		DWORD idLen = sizeof id;
		if (const auto data = static_cast<LPBYTE>(static_cast<void*>(id)); RegQueryValueExA(
			key, "ProcessorNameString", nullptr, nullptr, data, &idLen))
		{
			return "Unknown";
		}
		return id;
	}

	auto Os::QueryPageSize() -> U64
	{
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		return static_cast<U64>(sysInfo.dwPageSize);
	}

	auto Os::DylibOpen(const std::string_view filePath) -> void*
	{
		return LoadLibraryA(filePath.data());
	}

	auto Os::DylibLookupSymbol(void* const handle, const std::string_view symbolName) -> void*
	{
		// ReSharper disable once CppRedundantCastExpression
		return reinterpret_cast<void*>(GetProcAddress(static_cast<HMODULE>(handle), symbolName.data()));
	}

	auto Os::DylibClose(void*& handle) -> void
	{
		FreeLibrary(static_cast<HMODULE>(handle));
		handle = nullptr;
	}
}

#endif
