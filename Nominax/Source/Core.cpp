// File: Core.cpp
// Author: Mario
// Created: 05.07.2021 4:43 PM
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

#include <algorithm>
#include <bitset>
#include <fstream>
#include <sstream>
#include <string_view>

#include "../../Nominax/Include/Nominax/Core.hpp"
#include "../../Nominax/Include/Nominax/Common.hpp"
#include "../../Nominax/Include/Nominax/System/System.hpp"

#include "ReactorCores.hpp"

namespace Nominax
{
	extern const constinit std::string_view SYSTEM_COPYRIGHT_TEXT;
	extern const constinit std::string_view SYSTEM_LOGO_TEXT;

	namespace Core
	{
		auto BasicReactorDescriptor::BuildDetailed() const -> VerboseReactorDescriptor
		{
			return
			{
				.CodeChunk = this->CodeChunk.data(),
				.CodeChunkInstructionMap = this->CodeChunkInstructionMap.data(),
				.CodeChunkSize = this->CodeChunk.size(),
				.IntrinsicTable = this->IntrinsicTable.data(),
				.IntrinsicTableSize = this->IntrinsicTable.size(),
				.InterruptHandler = &this->InterruptHandler,
				.Stack = this->Stack.data(),
				.StackSize = this->Stack.size(),
			};
		}

		auto BasicReactorDescriptor::Validate() const -> ReactorValidationResult
		{
			return this->BuildDetailed().Validate();
		}

		/// <summary>
		/// Query and print machine info.
		/// </summary>
		/// <returns></returns>
		static auto InitSysInfo() -> System::Snapshot
		{
			Common::Print('\n');
			System::Snapshot snapshot { };
			snapshot.Print();
			return snapshot;
		}

		/// <summary>
		/// Query and print cpu features.
		/// </summary>
		/// <returns></returns>Common::
		static auto InitCpuFeatures() -> System::CpuFeatureDetector
		{
			Common::Print('\n');
			System::CpuFeatureDetector cpuFeatureDetector { };
			cpuFeatureDetector.Print();
			Common::Print('\n');
			return cpuFeatureDetector;
		}

		/// <summary>
		/// Prints the info of one type.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="name"></param>
		/// <returns></returns>
		template <typename T>
		static inline auto PrintTypeInfo(const std::string_view name) -> void
		{
			Common::Print("{0: <14} | {1: <14} | {2: <14}\n", name, sizeof(T), alignof(T));
		}

		/// <summary>
		/// Print size and alignment of common types.
		/// </summary>
		/// <param name="threads"></param>
		/// <returns></returns>
		static auto PrintTypeInfoTable() -> void
		{
			Common::Print("{0: <14} | {1: <14} | {2: <14}\n\n", "Type", "Byte Size", "Alignment");
			PrintTypeInfo<Common::Record>("Common::Record");
			PrintTypeInfo<ByteCode::Signal>("Signal");
			PrintTypeInfo<ByteCode::Signal::Discriminator>("SignalDisc");
			PrintTypeInfo<Object>("Object");
			PrintTypeInfo<ObjectHeader>("ObjectHeader");
			PrintTypeInfo<I64>("int");
			PrintTypeInfo<U64>("uint");
			PrintTypeInfo<F64>("float");
			PrintTypeInfo<char32_t>("char");
			PrintTypeInfo<bool>("bool");
			PrintTypeInfo<void*>("void*");
		}

		/// <summary>
		/// Print Nominax runtime info.
		/// </summary>
		/// <returns></returns>
		auto PrintSystemInfo() -> void
		{
			Common::Print(SYSTEM_LOGO_TEXT);
			Common::Print(SYSTEM_COPYRIGHT_TEXT);
			Common::Print("\nNominax Version: v.{}.{}\n", SYSTEM_VERSION.Major, SYSTEM_VERSION.Minor);
			Common::Print("Platform: {} {}\n", NOX_OS_NAME, NOX_ARCH_SIZE_NAME);
			Common::Print("Arch: {}\n", NOX_ARCH_NAME);
			Common::Print("IsPosix: {}\n", NOX_IS_POSIX);
			Common::Print("Compiled with: {} - C++ 20\n", NOX_COM_NAME);
			Common::Print("\n");
			PrintTypeInfoTable();
			Common::Print("\n");
		}

		#define DISPATCH_HOOK(method, ...)							\
	do														\
	{														\
		Common::Print("Dispatching hook: " #method "\n");	\
		NOX_PANIC_ASSERT_TRUE								\
		(													\
			this-> method (__VA_ARGS__),					\	
			"\" "#method "\" returned false!"				\
		);													\
	}														\
	while(false)

		#define VALIDATE_ONLINE_BOOT_STATE() NOX_PANIC_ASSERT_TRUE(this->IsOnline(), "Environment is offline!")

		/// <summary>
		/// Checks if the byte stack size is divisible by sizeof(Common::Record) and panics if not.
		/// Returns the counts of records.
		/// </summary>
		/// <param name="appCode"></param>
		/// <returns></returns>
		static inline auto MapStackSize(const std::size_t sizeInBytes) -> std::size_t
		{
			if (sizeInBytes % sizeof(Common::Record) != 0)
			{
				[[unlikely]]
					Panic(NOX_PAINF, "Invalid stack size: {}! Must be a multiple of sizeof(Common::Record) -> 8!", sizeInBytes);
			}
			return sizeInBytes / sizeof(Common::Record);
		}

		/// <summary>
		/// Compute the final size of the system pool.
		/// If the desired size is 0, fallback size is used.
		/// Y = Y != 0 + F
		/// S = Y + (C * (Z * R))
		/// Y = desired size
		/// S = final size
		/// C = reactor count
		/// Z = reactor stack size
		/// R = sizeof(Common::Record)
		/// </summary>
		/// <param name="desiredSize"></param>
		/// <param name="reactorCount"></param>
		/// <param name="reactorStackSize"></param>
		/// <returns></returns>
		static inline auto ComputePoolSize
		(
			std::size_t       desiredSize,
			const std::size_t reactorCount,
			std::size_t       reactorStackSize
		) -> std::size_t
		{
			reactorStackSize = MapStackSize(reactorStackSize);
			desiredSize      = desiredSize ? desiredSize : Environment::FALLBACK_SYSTEM_POOL_SIZE;
			return desiredSize + reactorCount * (reactorStackSize * sizeof(Common::Record));
		}

		/// <summary>
		/// Faster to write than get() each time.
		/// This is implemented for the default unique_ptr but not for the array specialization.
		/// </summary>
		/// <param name="ptr"></param>
		/// <returns></returns>
		static inline auto operator*(const std::unique_ptr<U8[]>& ptr) -> U8*
		{
			return ptr.get();
		}

		/// <summary>
		/// Clamps the size of the boot pool between a valid range,
		/// </summary>
		/// <param name="desiredSize"></param>
		/// <returns></returns>
		static constexpr auto ClampBootPoolSize(const std::size_t desiredSize) -> std::size_t
		{
			return std::clamp(desiredSize, Environment::BOOT_POOL_SIZE_MIN, Environment::BOOT_POOL_SIZE_MAX);
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="idx"></param>
		/// <param name="appCode"></param>
		/// <param name="code"></param>
		/// <returns></returns>
		[[maybe_unused]]
		static auto PrintByteCodeErrorSector
		(
			const std::size_t                    idx, const ByteCode::Stream& appCode,
			const ByteCode::ValidationResultCode code
		)
		{
			const bool isInstructionFault
			{
				code == ByteCode::ValidationResultCode::NotEnoughArgumentsForInstruction
				|| code == ByteCode::ValidationResultCode::TooManyArgumentsForInstruction
				|| code == ByteCode::ValidationResultCode::ArgumentTypeMismatch
			};

			for (std::size_t i {idx}; i < idx + 8 && i < appCode.Size(); ++i)
			{
				if (appCode[i].Contains<ByteCode::Instruction>())
				{
					Print(Common::TextColor::Green, "\n{:#018X}: ", i);
					Print(Common::TextColor::BrightBlue, "{}", appCode[i].Value.R64.AsU64);
				}
				else
				{
					Print(Common::TextColor::Magenta, " {}", appCode[i].Value.R64.AsU64);
				}

				if (isInstructionFault && i == idx)
				{
					Print(Common::LogLevel::Error, " {} ->", code);
				}
			}

			Common::Print('\n');
		}

		/// <summary>
		/// Helper to allocate a environment pool.
		/// </summary>
		[[nodiscard]]
		NOX_ALLOC_SIZE(1) static inline auto AllocatePool(const std::size_t size, const std::string_view poolId) -> U8*
		{
			Common::Print("Allocating {} pool with size: {} MB\n", poolId, Common::Bytes2Megabytes(static_cast<F64>(size)));
			auto* NOX_RESTRICT const mem {new(std::nothrow) U8[size]};
			if (!mem)
			{
				[[unlikely]]
					Panic(NOX_PAINF, "Allocation of monotonic {} pool with size {} MB failed!", poolId,
					      Common::Bytes2Megabytes(static_cast<F64>(size)));
			}
			return mem;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="result"></param>
		/// <param name="appCode"></param>
		/// <returns></returns>
		[[noreturn]]
		static auto TriggerByteCodeStreamValidationPanic
		(
			const ByteCode::ValidationResultCode     result,
			[[maybe_unused]] const ByteCode::Stream& appCode
		)
		{
			// Print error message:
			Panic(NOX_PAINF, "Byte code validation of stream failed: {}\n", result);
		}

		/// <summary>
		/// Computes the percent of used memory by a specific resource.
		/// </summary>
		/// <param name="used"></param>
		/// <param name="max"></param>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto ComputeMemoryPercent(const std::size_t used, const std::size_t max) -> F64
		{
			return static_cast<F64>(used) * 100.0 / static_cast<F64>(max);
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="resource"></param>
		/// <param name="buffer"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		[[nodiscard]]
		static auto QueryMemoryResourceUsage
		(
			std::pmr::monotonic_buffer_resource& resource,
			const std::unique_ptr<U8[]>&         buffer,
			const std::size_t                    size
		) -> std::pair<std::ptrdiff_t, F64>
		{
			const U8* const      needle {static_cast<U8*>(resource.allocate(sizeof(U8), alignof(U8)))};
			const std::ptrdiff_t offset {needle - *buffer};                             // compute allocation offset
			const F64            poolUsagePercent {ComputeMemoryPercent(offset, size)}; // compute percent usage
			return {offset, poolUsagePercent};
		}

		/// <summary>
		/// Contains all the runtime variables required for the runtime system.
		/// </summary>
		/// <param name="descriptor"></param>
		/// <returns></returns>
		struct Environment::Context final
		{
			const std::size_t                                        ReactorCount;
			const std::size_t                                        BootPoolSize;
			const std::unique_ptr<U8[]>                              BootPool;
			std::pmr::monotonic_buffer_resource                      BootPoolResource;
			const std::size_t                                        SystemPoolSize;
			const std::unique_ptr<U8[]>                              SystemPool;
			std::pmr::monotonic_buffer_resource                      SystemPoolResource;
			std::pmr::unordered_set<std::pmr::string>                Arguments;
			std::pmr::string                                         AppName;
			std::pmr::vector<std::chrono::duration<F64, std::micro>> ExecutionTimeHistory;
			const std::chrono::high_resolution_clock::time_point     BootStamp;
			std::chrono::milliseconds                                BootTime;
			const System::Snapshot                                   SysInfoSnapshot;
			const System::CpuFeatureDetector                         CpuFeatures;
			const ReactorRoutineLink                                 OptimalReactorRoutine;
			ReactorPool                                              CorePool;

			explicit Context(const EnvironmentDescriptor& descriptor);
			Context(const Context&)                     = delete;
			Context(Context&&)                          = delete;
			auto operator =(const Context&) -> Context& = delete;
			auto operator =(Context&&) -> Context&      = delete;
			~Context()                                  = default;
		};

		Environment::Context::Context(const EnvironmentDescriptor& descriptor) :
			ReactorCount {ReactorPool::SmartQueryReactorCount(descriptor.ReactorCount)},
			BootPoolSize {ClampBootPoolSize(descriptor.BootPoolSize)},
			BootPool {AllocatePool(BootPoolSize, "boot")},
			BootPoolResource {*BootPool, BootPoolSize},
			SystemPoolSize {ComputePoolSize(descriptor.SystemPoolSize, ReactorCount, descriptor.StackSize)},
			SystemPool {AllocatePool(SystemPoolSize, "system")},
			SystemPoolResource {*SystemPool, SystemPoolSize},
			Arguments {&BootPoolResource},
			AppName {&SystemPoolResource},
			ExecutionTimeHistory {&SystemPoolResource},
			BootStamp {std::chrono::high_resolution_clock::now()},
			BootTime { },
			SysInfoSnapshot {InitSysInfo()},
			CpuFeatures {InitCpuFeatures()},
			OptimalReactorRoutine {
				descriptor.ForceFallback ? GetFallbackRoutineLink() : GetOptimalReactorRoutine(CpuFeatures)
			},
			CorePool {
				SystemPoolResource, ReactorCount, ReactorSpawnDescriptor
				{
					.StackSize = MapStackSize(descriptor.StackSize),
					.SharedIntrinsicTable = { },
					.InterruptHandler = nullptr,
					.PowerPref = descriptor.PowerPref
				},
				OptimalReactorRoutine
			}
		{
			if (descriptor.ArgC && descriptor.ArgV)
			{
				// copy arguments:
				[[likely]]
					this->Arguments.insert(descriptor.ArgV + 1, descriptor.ArgV + descriptor.ArgC);
			}

			// copy app name:
			this->AppName = descriptor.AppName;
		}

		auto Environment::ContextDeleter::operator()(Context* const kernel) const -> void
		{
			delete kernel;
		}

		auto Environment::OnPreBootHook() -> bool
		{
			return true;
		}

		auto Environment::OnPostBootHook() -> bool
		{
			return true;
		}

		auto Environment::OnPreExecutionHook([[maybe_unused]] const ByteCode::AppCodeBundle& appCodeBundle) -> bool
		{
			return true;
		}

		auto Environment::OnPostExecutionHook() -> bool
		{
			return true;
		}

		auto Environment::OnPreShutdownHook() -> bool
		{
			return true;
		}

		auto Environment::OnPostShutdownHook() -> bool
		{
			return true;
		}

		Environment::Environment(const Common::IAllocator* const allocator)
		{
			if (allocator)
			{
				Common::GlobalAllocatorProxy = allocator;
			}
		}

		Environment::~Environment()
		{
			Shutdown();
		}

		auto Environment::Boot(const EnvironmentDescriptor& descriptor) -> void
		{
			if (this->Context_)
			{
				[[unlikely]]
					return;
			}

			// Basic setup:
			std::ios_base::sync_with_stdio(!descriptor.FastHostIoSync);
			PrintSystemInfo();
			Common::Print("Booting runtime environment...\nApp: \"{}\"\n", descriptor.AppName);
			const auto tik {std::chrono::high_resolution_clock::now()};

			// Invoke hook:
			DISPATCH_HOOK(OnPreBootHook,);

			Common::Print
			(
				"Monotonic boot pool fixed size: {} MB, Min: {} MB, Max: {} MB\n",
				Common::Bytes2Megabytes(static_cast<F64>(descriptor.BootPoolSize)),
				Common::Bytes2Megabytes(static_cast<F64>(BOOT_POOL_SIZE_MIN)),
				Common::Bytes2Megabytes(static_cast<F64>(BOOT_POOL_SIZE_MAX))
			);

			Common::Print
			(
				"Monotonic system pool fixed size: {} MB, Fallback: {} MB\n",
				Common::Bytes2Megabytes(descriptor.SystemPoolSize),
				Common::Bytes2Megabytes(FALLBACK_SYSTEM_POOL_SIZE)
			);

			// No, we cannot use std::make_unique because we want it noexcept!
			// ReSharper disable once CppSmartPointerVsMakeFunction
			this->Context_ = std::unique_ptr<Context, ContextDeleter>(new(std::nothrow) Context(descriptor));
			NOX_PANIC_ASSERT_NOT_NULL(this->Context_, "Context allocation failed!");

			// Invoke hook:
			DISPATCH_HOOK(OnPostBootHook,);

			const auto tok {std::chrono::high_resolution_clock::now()};

			// Get memory snapshot:
			const std::size_t memSnapshot {System::Os::QueryProcessMemoryUsed()};
			const F64         memUsagePercent {
				ComputeMemoryPercent(memSnapshot, this->Context_->SysInfoSnapshot.TotalSystemMemory)
			};

			// Query pool info
			const auto [bootPoolSize, bootPoolPer] {
				QueryMemoryResourceUsage
				(
					this->Context_->BootPoolResource,
					this->Context_->BootPool,
					this->Context_->BootPoolSize
				)
			};

			// Query pool info
			const auto [sysPoolSize, sysPoolPer] {
				QueryMemoryResourceUsage
				(
					this->Context_->SystemPoolResource,
					this->Context_->SystemPool,
					this->Context_->SystemPoolSize
				)
			};

			const auto ms {std::chrono::duration_cast<std::chrono::milliseconds>(tok - tik)};
			this->Context_->BootTime = ms;

			Common::Print
			(
				"Runtime environment online!\n"
				"Process memory snapshot: {:.02f} % [{} MB / {} MB]\n"
				"Monotonic boot pool snapshot:	 {:.02f} % [{} KB / {} KB]\n"
				"Monotonic system pool snapshot: {:.02f} % [{} MB / {} MB]\n"
				"Boot time: {}\n"
				"\n",
				memUsagePercent,
				Common::Bytes2Megabytes(static_cast<F64>(memSnapshot)),
				Common::Bytes2Megabytes(static_cast<F64>(this->Context_->SysInfoSnapshot.TotalSystemMemory)),
				bootPoolPer,
				Common::Bytes2Kilobytes(static_cast<F64>(bootPoolSize)),
				Common::Bytes2Kilobytes(static_cast<F64>(this->Context_->BootPoolSize)),
				sysPoolPer,
				Common::Bytes2Megabytes(static_cast<F64>(sysPoolSize)),
				Common::Bytes2Megabytes(static_cast<F64>(this->Context_->SystemPoolSize)),
				ms
			);
		}

		auto Environment::Execute(ByteCode::Stream&& appCode) -> std::pair<ReactorShutdownReason, const ReactorState&>
		{
			VALIDATE_ONLINE_BOOT_STATE();

			ByteCode::AppCodeBundle appCodeBundle { };
			if (const auto result {appCode.Build(appCodeBundle)}; result != ByteCode::ValidationResultCode::Ok)
			{
				[[unlikely]]
					TriggerByteCodeStreamValidationPanic(result, appCode);
			}

			// Deallocate stream:
			appCode = { };

			// Invoke hook:
			DISPATCH_HOOK(OnPreExecutionHook, appCodeBundle);

			// Info
			Print(Common::LogLevel::Warning, "Executing...\n");
			std::cout.flush();

			// Execute on alpha reactor:
			const auto& result {(*this->Context_->CorePool)(std::move(appCodeBundle))};

			// Add execution time:
			const auto micros {
				std::chrono::duration_cast<std::chrono::duration<F64, std::micro>>(result.second.Duration)
			};
			this->Context_->ExecutionTimeHistory.push_back(micros);

			// Print exec info:
			const auto level {
				result.first == ReactorShutdownReason::Success ? Common::LogLevel::Success : Common::LogLevel::Error
			};
			Print(level, "Execution #{} done! Runtime {:.04}\n", this->Context_->ExecutionTimeHistory.size(),
			      std::chrono::duration_cast<std::chrono::duration<F64, std::ratio<1>>>(micros));
			std::cout.flush();

			// Invoke hook:
			DISPATCH_HOOK(OnPostExecutionHook,);
			return result;
		}

		auto Environment::Shutdown() -> void
		{
			if (!this->Context_)
			{
				[[unlikely]]
					return;
			}

			// Invoke hook:
			DISPATCH_HOOK(OnPreShutdownHook,);

			this->Context_.reset();
			this->Context_ = nullptr;

			// Invoke hook:
			DISPATCH_HOOK(OnPostShutdownHook,);
		}

		auto Environment::IsOnline() const -> bool
		{
			return this->Context_ != nullptr;
		}

		auto Environment::GetKernel() const -> const void*
		{
			return this->Context_.get();
		}

		auto Environment::GetBootStamp() const -> std::chrono::high_resolution_clock::time_point
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->BootStamp;
		}

		auto Environment::GetBootTime() const -> std::chrono::milliseconds
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->BootTime;
		}

		auto Environment::GetSystemSnapshot() const -> const System::Snapshot&
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->SysInfoSnapshot;
		}

		auto Environment::GetProcessorFeatureSnapshot() const -> const System::CpuFeatureDetector&
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->CpuFeatures;
		}

		auto Environment::GetAppName() const -> const std::pmr::string&
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->AppName;
		}

		auto Environment::GetMonotonicSystemPoolSize() const -> std::size_t
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->SystemPoolSize;
		}

		auto Environment::GetExecutionCount() const -> std::size_t
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->ExecutionTimeHistory.size();
		}

		auto Environment::GetExecutionTimeHistory() const -> const std::pmr::vector<std::chrono::duration<F64, std::micro>>&
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->ExecutionTimeHistory;
		}

		auto ComputeInstructionMapBinding
		(
			std::span<const ByteCode::Signal::Discriminator> input,
			std::span<bool>&                                 output
		) -> bool
		{
			if (std::size(input) != std::size(output))
			{
				[[unlikely]]
					return false;
			}

			auto       iterator {std::begin(input)};
			const auto end {std::end(input)};

			for (bool* flag = output.data(); iterator < end; ++iterator, ++flag)
			{
				*flag = *iterator == ByteCode::Signal::Discriminator::Instruction;
			}

			return true;
		}

		auto PerformJumpTableMapping
		(
			ByteCode::Signal* NOX_RESTRICT             bucket,
			const ByteCode::Signal* const NOX_RESTRICT bucketEnd,
			const bool*                                jumpAddressMap,
			JumpTable                                  jumpTable
		) -> bool
		{
			NOX_PANIC_ASSERT_NOT_NULL(bucket, "Code chunk bucket table was nullptr!");
			NOX_PANIC_ASSERT_NOT_NULL(bucketEnd, "Code chunk bucket table end was nullptr!");
			NOX_PANIC_ASSERT_NOT_NULL(jumpAddressMap, "Jump address map was nullptr!");
			NOX_PANIC_ASSERT_NOT_NULL(jumpTable, "Jump table was nullptr!");
			NOX_PANIC_ASSERT_NOT_NULL(*jumpTable, "First element of jump table was nullptr!");
			NOX_PANIC_ASSERT_TRUE(*jumpAddressMap,
			                      "First element of jump address map was false, but should be true because of code prologue!")
			;
			NOX_PANIC_ASSERT_EQ(bucket->Instr, ByteCode::Instruction::NOp, "Missing code prologue in code bucket!");

			// skip first "nop" padding instruction:
			++bucket;
			++jumpAddressMap;

			while (bucket < bucketEnd)
			{
				if (*jumpAddressMap)
				{
					bucket->Ptr = const_cast<void*>(*(jumpTable + bucket->OpCode));
				}

				++bucket;
				++jumpAddressMap;
			}

			return true;
		}

		FixedStack::FixedStack(std::pmr::memory_resource& allocator, std::size_t sizeInRecords) : Buffer_ {&allocator}
		{
			NOX_PANIC_ASSERT_NOT_ZERO(sizeInRecords, "Fixed stack with zero size was requested!");

			// because first padding element.
			++sizeInRecords;

			// allocate:
			this->Buffer_.resize(sizeInRecords);

			// insert padding:
			this->Buffer_.front() = Common::Record::Padding();
		}

		static constexpr std::string_view CRASH_DIRECTORY {"Crashes/"};

		/// <summary>
	/// Writes a full error dump into the stream.
	/// </summary>
	/// <param name="out"></param>
	/// <param name="sp"></param>
	/// <param name="ip"></param>
	/// <param name="bp"></param>
	/// <param name="stackSize"></param>
	/// <param name="codeSize"></param>
	/// <param name="stackDumpSize"></param>
	/// <param name="codeDumpSize"></param>
	/// <returns></returns>
		auto WriteHardFaultReport
		(
			std::ostream&                 out,
			const Common::Record* const   sp,
			const ByteCode::Signal* const ip,
			const ByteCode::Signal* const bp,
			const std::size_t             stackSize,
			const std::size_t             codeSize,
			const std::string_view        message,
			std::size_t                   stackDumpSize,
			std::size_t                   codeDumpSize
		) -> void
		{
			[[maybe_unused]] GprRegisterLane gpr { };

			[[maybe_unused]] VectorRegisterLane128 v128 { };

			[[maybe_unused]] VectorRegisterLane256 v256 { };

			{
				#if NOX_ARCH_X86_32
				/// <summary>
				/// Read 32-bit GPR registers.
				/// Output is:
				/// %eax = gpr[0];
				/// %ebx = gpr[1];
				/// %ecx = gpr[2];
				/// %edx = gpr[3];
				/// %esi = gpr[4];
				/// %edi = gpr[5];
				///	%ebp = gpr[6];
				/// %esp = gpr[7];
				/// </summary>
				asm volatile
					(
						"movl %%eax, %0"
						: "=r" (gpr[0])
						:
						:
						);

				asm volatile
					(
						"movl %%ebx, %0"
						: "=r" (gpr[1])
						:
						:
						);

				asm volatile
					(
						"movl %%ecx, %0"
						: "=r" (gpr[2])
						:
						:
						);

				asm volatile
					(
						"movl %%edx, %0"
						: "=r" (gpr[3])
						:
						:
						);

				asm volatile
					(
						"movl %%esi, %0"
						: "=r" (gpr[4])
						:
						:
						);

				asm volatile
					(
						"movl %%edi, %0"
						: "=r" (gpr[5])
						:
						:
						);


				asm volatile
					(
						"movl %%ebp, %0"
						: "=r" (gpr[6])
						:
						:
						);

				asm volatile
					(
						"movl %%esp, %0"
						: "=r" (gpr[7])
						:
						:
						);

				// dump registers
				RegisterDump_X86_32(out, gpr);

				#elif NOX_ARCH_X86_64
				/// <summary>
				/// Read 64-bit GPR registers.
				/// Output is:
				/// %rax = gpr[0];
				/// %rbx = gpr[1];
				/// %rcx = gpr[2];
				/// %rdx = gpr[3];
				/// %rsi = gpr[4];
				/// %rdi = gpr[5];
				/// %rbp = gpr[6];
				/// %rsp = gpr[7];
				/// %rax = gpr[8];
				/// %rbx = gpr[9];
				/// %rcx = gpr[10];
				/// %rdx = gpr[11];
				/// %rsi = gpr[12];
				/// %rdi = gpr[13];
				/// %rbp = gpr[14];
				/// %rsp = gpr[15];
				/// %xmm0 = v128[0];
				/// %xmm1 = v128[1];
				/// %xmm2 = v128[2];
				/// %xmm3 = v128[3];
				/// %xmm4 = v128[4];
				/// %xmm5 = v128[5];
				/// %xmm6 = v128[6];
				/// %xmm7 = v128[7];
				/// %xmm8 = v128[8];
				/// %xmm9 = v128[9];
				/// %xmm10 = v128[10];
				/// %xmm11 = v128[11];
				/// %xmm12 = v128[12];
				/// %xmm13 = v128[13];
				/// %xmm14 = v128[14];
				/// %xmm15 = v128[15];
				/// %ymm0 = v128[0];
				/// %ymm1 = v128[1];
				/// %ymm2 = v128[2];
				/// %ymm3 = v128[3];
				/// %ymm4 = sse[4];
				/// %ymm5 = sse[5];
				/// %ymm6 = sse[6];
				/// %ymm7 = sse[7];
				/// %ymm8 = sse[8];
				/// %ymm9 = sse[9];
				/// %ymm10 = sse[10];
				/// %ymm11 = sse[11];
				/// %ymm12 = sse[12];
				/// %ymm13 = sse[13];
				/// %ymm14 = sse[14];
				/// %ymm15 = sse[15];
				/// </summary>
				asm volatile
				(
					"movq %%rax, %0"
					: "=m" (gpr[0])
					:
					:
				);

				asm volatile
				(
					"movq %%rbx, %0"
					: "=m" (gpr[1])
					:
					:
				);

				asm volatile
				(
					"movq %%rcx, %0"
					: "=m" (gpr[2])
					:
					:
				);

				asm volatile
				(
					"movq %%rdx, %0"
					: "=m" (gpr[3])
					:
					:
				);

				asm volatile
				(
					"movq %%rsi, %0"
					: "=m" (gpr[4])
					:
					:
				);

				asm volatile
				(
					"movq %%rdi, %0"
					: "=m" (gpr[5])
					:
					:
				);

				asm volatile
				(
					"movq %%rbp, %0"
					: "=m" (gpr[6])
					:
					:
				);

				asm volatile
				(
					"movq %%rsp, %0"
					: "=m" (gpr[7])
					:
					:
				);

				asm volatile
				(
					"movq %%r8, %0"
					: "=m" (gpr[8])
					:
					:
				);

				asm volatile
				(
					"movq %%r9, %0"
					: "=m" (gpr[9])
					:
					:
				);

				asm volatile
				(
					"movq %%r10, %0"
					: "=m" (gpr[10])
					:
					:
				);

				asm volatile
				(
					"movq %%r11, %0"
					: "=m" (gpr[11])
					:
					:
				);

				asm volatile
				(
					"movq %%r12, %0"
					: "=m" (gpr[12])
					:
					:
				);

				asm volatile
				(
					"movq %%r13, %0"
					: "=m" (gpr[13])
					:
					:
				);

				asm volatile
				(
					"movq %%r14, %0"
					: "=m" (gpr[14])
					:
					:
				);

				asm volatile
				(
					"movq %%r15, %0"
					: "=m" (gpr[15])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm0, %0"
					: "=m" (v128[0])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm1, %0"
					: "=m" (v128[1])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm2, %0"
					: "=m" (v128[2])
					:
					:
				);


				asm volatile
				(
					"movdqu %%xmm3, %0"
					: "=m" (v128[3])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm4, %0"
					: "=m" (v128[4])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm5, %0"
					: "=m" (v128[5])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm6, %0"
					: "=m" (v128[6])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm7, %0"
					: "=m" (v128[7])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm8, %0"
					: "=m" (v128[8])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm9, %0"
					: "=m" (v128[9])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm10, %0"
					: "=m" (v128[10])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm11, %0"
					: "=m" (v128[11])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm12, %0"
					: "=m" (v128[12])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm13, %0"
					: "=m" (v128[13])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm14, %0"
					: "=m" (v128[14])
					:
					:
				);

				asm volatile
				(
					"movdqu %%xmm15, %0"
					: "=m" (v128[15])
					:
					:
				);

				#ifdef __AVX__

				asm volatile
					(
						"vmovdqu %%ymm0, %0"
						: "=m" (v256[0])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm1, %0"
						: "=m" (v256[1])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm2, %0"
						: "=m" (v256[2])
						:
						:
						);


				asm volatile
					(
						"vmovdqu %%ymm3, %0"
						: "=m" (v256[3])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%xmm4, %0"
						: "=m" (v256[4])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm5, %0"
						: "=m" (v256[5])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm6, %0"
						: "=m" (v256[6])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm7, %0"
						: "=m" (v256[7])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm8, %0"
						: "=m" (v256[8])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm9, %0"
						: "=m" (v256[9])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm10, %0"
						: "=m" (v256[10])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm11, %0"
						: "=m" (v256[11])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm12, %0"
						: "=m" (v256[12])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm13, %0"
						: "=m" (v256[13])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm14, %0"
						: "=m" (v256[14])
						:
						:
						);

				asm volatile
					(
						"vmovdqu %%ymm15, %0"
						: "=m" (v256[15])
						:
						:
						);

				#endif
				#endif
			}

			out << "=========================\n";
			out << " !HARD FAULT TRAP ERROR!\n";
			out << "=========================\n";
			out << "Nominax runtime reactor " << std::hex << "0x" << std::this_thread::get_id() << std::dec <<
				" has encountered a major problem and has been terminated.\n";
			out << "We are sorry for the inconvenience!\n";
			out << "Please send this file to: mt3000@gmx.de" << '\n';
			out << "Or create an issue: https://github.com/MarioSieg/NominaX" << "\n\n";
			out << "=========================\n";
			out << "         System\n";
			out << "=========================\n";
			out << "Nominax Version: " << SYSTEM_VERSION << '\n';
			out << "Platform: " NOX_OS_NAME " " NOX_ARCH_SIZE_NAME << '\n';
			out << "Arch: " << NOX_ARCH_NAME << '\n';
			out << "Posix: " << std::boolalpha << NOX_IS_POSIX << '\n';
			out << "Compiler: " << NOX_COM_NAME " - C++ 20" << '\n';
			out << "CPU: " << System::Os::QueryCpuName() << '\n';
			out << "CPU Threads: " << std::thread::hardware_concurrency() << '\n';
			out << "System RAM: " << Common::Bytes2Megabytes(System::Os::QuerySystemMemoryTotal()) << " MB\n";
			out << "Process RAM: " << Common::Bytes2Megabytes(System::Os::QueryProcessMemoryUsed()) << " MB\n";
			out << '\n';
			out << "MS = " << (!message.empty() && message.data() ? message : "none") << '\n';
			out << "SP = &0x" << std::hex << sp << '\n';
			out << "IP = &0x" << std::hex << ip << '\n';
			out << "BP = &0x" << std::hex << bp << "\n";
			out << std::endl;

			/*
			 * The problem with the register dump is that the values are very undefined.
			 * The idea originally was to dump the register values to help debugging,
			 * but the values are not really that useful. Also because this function is called,
			 * the registers are modified too. So this register dump feature is not that useful,
			 * but it's integrated into the debug pipeline, so it will stay.
			 */

			// dump registers:
			out << "=========================\n";
			out << "     Register Dump\n";
			out << "=========================\n";
			RegisterDump_X86_64(out, gpr, v128, v256);

			stackDumpSize = std::clamp(stackDumpSize, stackDumpSize, stackSize);
			codeDumpSize  = std::clamp(codeDumpSize, codeDumpSize, codeSize);

			// TODO Check if the stack dump could be a security vulnerability
			out << "=========================\n";
			out << "       Stack Dump        \n";
			out << "=========================\n";
			for (std::size_t i {0}; i < stackDumpSize && sp; ++i)
			{
				out << "0x" << std::hex << i << " = 0x" << std::hex << sp[-i].AsU64 << '\n';
			}

			out << std::endl;

			// TODO Check if the code dump could be a security vulnerability
			out << "=========================\n";
			out << "        Code Dump        \n";
			out << "=========================\n";
			for (std::size_t i {0}; i < codeDumpSize && ip; ++i)
			{
				out << "0x" << std::hex << i << " = 0x" << std::hex << ip[-i].R64.AsU64 << '\n';
			}
			out << std::endl;
		}

		/// <summary>
		/// Writes a full error dump into std::cerr and into a file.
		/// </summary>
		/// <param name="sp"></param>
		/// <param name="ip"></param>
		/// <param name="bp"></param>
		/// <param name="stackSize"></param>
		/// <param name="codeSize"></param>
		/// <param name="stackDumpSize"></param>
		/// <param name="codeDumpSize"></param>
		/// <returns></returns>
		auto WriteHardFaultReport
		(
			const Common::Record* const   sp,
			const ByteCode::Signal* const ip,
			const ByteCode::Signal* const bp,
			const std::size_t             stackSize,
			const std::size_t             codeSize,
			const std::string_view        message,
			const std::size_t             stackDumpSize,
			const std::size_t             codeDumpSize
		) -> void
		{
			std::stringstream dump;
			WriteHardFaultReport(dump, sp, ip, bp, stackSize, codeSize, message, stackDumpSize, codeDumpSize);
			const std::string str = dump.str();
			std::cerr << str << std::endl;
			std::filesystem::create_directory(CRASH_DIRECTORY);
			const std::time_t t  = std::time(nullptr);
			const std::tm     tm = Common::SafeLocalTime(t);
			std::stringstream crashFilePath;
			crashFilePath << CRASH_DIRECTORY;
			crashFilePath << std::put_time(&tm, "NominaxCrash_%d_%m_%Y_%H_%M_%S.dmp");
			const std::string crashFilePathStr = crashFilePath.str();
			if (std::ofstream crashFile {crashFilePathStr}; crashFile.is_open())
			[[likely]]
			{
				crashFile << str;
				crashFile.flush();

				std::cerr << "Crash file generated in: " << std::filesystem::absolute(crashFilePathStr) << "\n\n";
			}
		}

		auto WriteHardFaultReport(const std::string_view message) -> void
		{
			WriteHardFaultReport(nullptr, nullptr, nullptr, 0, 0, message, 0, 0);
		}

		auto DefaultInterruptRoutine(InterruptAccumulator) -> void { }

		auto GetDefaultInterruptRoutine() -> InterruptRoutine*
		{
			return &DefaultInterruptRoutine;
		}

		auto Object::ShallowCopyObjectBlockToBuffer(const std::span<Common::Record> buffer) const -> bool
		{
			if (buffer.size() < this->HeaderRead_BlockSize())
			{
				[[unlikely]]
					return false;
			}

			std::memcpy(buffer.data(), this->LookupObjectBlock(), this->ObjectBlockSizeInBytes());

			return true;
		}

		auto Object::ShallowCopyObjectBlockToBuffer(std::vector<Common::Record>& buffer) const -> void
		{
			buffer.resize(this->HeaderRead_BlockSize());
			std::memcpy(buffer.data(), this->LookupObjectBlock(), this->ObjectBlockSizeInBytes());
		}

		auto Object::CopyBlob(std::vector<Common::Record>& buffer) const -> void
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
			[[unlikely]]
			{
				return nullptr;
			}
			const U32                finalObjectSize = ObjectHeader::RECORD_CHUNKS + sizeInRecords;
			auto* NOX_RESTRICT const object          = new Common::Record[finalObjectSize]();
			assert(object);

			// Write object header:
			// No ref count:
			ObjectHeader::WriteMapping_StrongRefCount(object, 0);

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

		[[maybe_unused]]
		static auto CreateDescriptor
		(
			FixedStack&                             stack,
			ByteCode::Image&                        image,
			ByteCode::JumpMap&                      jumpMap,
			ByteCode::UserIntrinsicRoutineRegistry& intrinsicTable,
			InterruptRoutine&                       interruptHandler
		) -> VerboseReactorDescriptor
		{
			const std::span instrMapTableView
			{
				reinterpret_cast<const bool*>(jumpMap.data()),
				reinterpret_cast<const bool*>(jumpMap.data() + jumpMap.size())
			};
			const auto simpleDescriptor = BasicReactorDescriptor
			{
				.CodeChunk = image.GetReactorView(),
				.CodeChunkInstructionMap = instrMapTableView,
				.IntrinsicTable = intrinsicTable,
				.Stack = stack,
				.InterruptHandler = interruptHandler
			};
			return simpleDescriptor.BuildDetailed();
		}

		Reactor::Reactor
		(
			std::pmr::memory_resource&               allocator,
			const ReactorSpawnDescriptor&            descriptor,
			const std::optional<ReactorRoutineLink>& routineLink,
			const std::size_t                        poolIdx
		) :
			Id_ {Common::Xorshift128ThreadLocal()},
			PoolIndex_ {poolIdx},
			SpawnStamp_ {std::chrono::high_resolution_clock::now()},
			PowerPreference_ {descriptor.PowerPref},
			Input_ { },
			Output_ {&Input_},
			Stack_ {allocator, descriptor.StackSize},
			IntrinsicTable_ {descriptor.SharedIntrinsicTable},
			InterruptHandler_ {descriptor.InterruptHandler ? descriptor.InterruptHandler : &DefaultInterruptRoutine},
			RoutineLink_
			{
				[&routineLink]() -> ReactorRoutineLink
				{
					if (!routineLink)
					{
						[[unlikely]]
							Print(Common::LogLevel::Warning,
							      "No reactor routine link specified. Querying CPU features and selecting accordingly...\n");
					}
					return routineLink ? *routineLink : GetOptimalReactorRoutine({ });
				}()
			}
		{
			Common::Print
			(
				"Reactor {:010X} "
				"Stack: {} MB, "
				"{} Records, "
				"Intrinsics: {}, "
				"Interrupt Routine: {}, "
				"Power: {}, "
				"Pool: {:02}\n",
				this->Id_,
				Common::Bytes2Megabytes(this->Stack_.Size() * sizeof(Common::Record)),
				this->Stack_.Size(),
				this->IntrinsicTable_.size(),
				this->InterruptHandler_ == &DefaultInterruptRoutine ? "Def" : "Usr",
				this->PowerPreference_ == PowerPreference::HighPerformance ? "Perf" : "Safe",
				this->PoolIndex_
			);
		}

		auto Reactor::Execute(ByteCode::AppCodeBundle&& bundle) -> std::pair<ReactorShutdownReason, const ReactorState&>
		{
			this->AppCode_ = std::move(bundle);
			this->Input_   = CreateDescriptor
			(
				this->Stack_,
				std::get<0>(this->AppCode_),
				std::get<1>(this->AppCode_),
				this->IntrinsicTable_,
				*this->InterruptHandler_
			);
			if (const auto validationResult {this->Input_.Validate()}; validationResult != ReactorValidationResult::Ok)
			{
				[[unlikely]]
					Panic(NOX_PAINF, "Reactor {:#X} validation failed with the following reason: {}", this->Id_,
					      validationResult);
			}
			ReactorCoreExecutionRoutine* const routine = this->RoutineLink_.ExecutionRoutine;
			NOX_PANIC_ASSERT_NOT_NULL(routine, "Reactor execution routine is nullptr!");
			const ReactorShutdownReason result {(*routine)(&this->Input_, &this->Output_, nullptr)};
			return {result, this->Output_};
		}

		auto SingletonExecutionProxy
		(
			const VerboseReactorDescriptor& input, const System::CpuFeatureDetector& target,
			const void****                  outJumpTable
		) -> std::pair<ReactorShutdownReason, ReactorState>
		{
			ReactorState                output {.Input = &input};
			const ReactorShutdownReason result {SingletonExecutionProxy(input, output, target, outJumpTable)};
			return {result, output};
		}

		static constexpr std::array<ReactorCoreExecutionRoutine*, static_cast<std::size_t>(
			                            ReactorCoreSpecialization::Count)> REACTOR_REGISTRY
		{
			&ReactorCore_Fallback,
			#if NOX_ARCH_X86_64

			&ReactorCore_AVX,
			&ReactorCore_AVX512F,

			#elif NOX_ARCH_ARM_64
		#	error "ARM64 not yet supported!"
			#endif
		};

		auto SmartSelectReactor(const System::CpuFeatureDetector& cpuFeatureDetector) -> ReactorCoreSpecialization
		{
			#if NOX_ARCH_X86_64

			// if we have AVX 512, use AVX 512:
			if (cpuFeatureDetector->Avx512F)
			{
				return ReactorCoreSpecialization::X86_64_AVX512F;
			}

			// if we have AVX, use AVX:
			if (cpuFeatureDetector->Avx)
			{
				return ReactorCoreSpecialization::X86_64_AVX;
			}

			#elif NOX_ARCH_ARM_64
#	error "ARM64 not yet supported!"
			#endif

			return ReactorCoreSpecialization::Fallback;
		}

		auto GetReactorRegistry() -> const ReactorRegistry&
		{
			return REACTOR_REGISTRY;
		}

		ReactorRoutineLink::ReactorRoutineLink
		(
			const ReactorCoreSpecialization    specialization,
			ReactorCoreExecutionRoutine* const executionRoutine,
			const void** const                 jumpTable
		) : Specialization {specialization},
		    ExecutionRoutine {executionRoutine},
		    JumpTable {jumpTable}
		{
			NOX_PANIC_ASSERT_NOT_NULL(this->ExecutionRoutine, "Routine for reactor routine link is null!");
			NOX_PANIC_ASSERT_NOT_NULL(this->JumpTable, "Jump table for reactor routine link is null!");
		}

		auto GetFallbackRoutineLink() -> ReactorRoutineLink
		{
			const auto                         specialization {ReactorCoreSpecialization::Fallback};
			ReactorCoreExecutionRoutine* const routine {
				GetReactorRoutineFromRegistryByTarget(ReactorCoreSpecialization::Fallback)
			};
			const void** const jumpTable {QueryJumpTable(*routine)};
			return
			{
				specialization,
				routine,
				jumpTable
			};
		}

		auto GetReactorRoutineFromRegistryByTarget(const ReactorCoreSpecialization target) -> ReactorCoreExecutionRoutine*
		{
			ReactorCoreExecutionRoutine* routine {
				REACTOR_REGISTRY[static_cast<std::underlying_type_t<decltype(target)>>(target)]
			};
			NOX_PANIC_ASSERT_NOT_NULL(routine, "Reactor core execution routine is nullptr!");
			return routine;
		}

		auto GetOptimalReactorRoutine(const System::CpuFeatureDetector& features) -> ReactorRoutineLink
		{
			static thread_local constinit U16 QueryCounter;
			ReactorCoreSpecialization         specialization {SmartSelectReactor(features)};
			ReactorCoreExecutionRoutine*      routine {GetReactorRoutineFromRegistryByTarget(specialization)};
			const void**                      jumpTable {QueryJumpTable(*routine)};
			Common::Print
			(
				"Execution Routine: {}, Registry ID: {:X}, Query: {}, Reactor Registry Size: {}\n",
				GetReactorCoreSpecializationName(specialization),
				static_cast<std::uint64_t>(specialization),
				++QueryCounter,
				std::size(REACTOR_REGISTRY)
			);
			if (QueryCounter > 1)
			{
				[[unlikely]]
					Print(Common::LogLevel::Warning,
					      "Current query count is: {}! Multiple queries should be avoided, consider caching the routine link!\n",
					      QueryCounter);
			}
			return
			{
				specialization,
				routine,
				jumpTable
			};
		}

		auto SingletonExecutionProxy
		(
			const VerboseReactorDescriptor&   input, ReactorState& output,
			const System::CpuFeatureDetector& target,
			const void****                    outJumpTable
		) -> ReactorShutdownReason
		{
			return GetOptimalReactorRoutine(target).ExecutionRoutine(&input, &output, outJumpTable);
		}

		auto QueryJumpTable(ReactorCoreExecutionRoutine& routine) -> const void**
		{
			const void**   jumpTable { };
			const void***  proxy {&jumpTable};
			const void**** writer {&proxy};
			return routine(nullptr, nullptr, writer) == ReactorShutdownReason::Success ? jumpTable : nullptr;
		}

		auto ReactorPool::SmartQueryReactorCount(const std::size_t desired) -> std::size_t
		{
			return desired < MIN_REACTOR_COUNT ? std::thread::hardware_concurrency() : desired;
		}

		ReactorPool::ReactorPool
		(
			std::pmr::memory_resource&               allocator,
			const std::size_t                        reactorCount,
			const ReactorSpawnDescriptor&            config,
			const std::optional<ReactorRoutineLink>& routineLink
		) : Pool_ {&allocator}
		{
			NOX_PANIC_ASSERT_NOT_ZERO(reactorCount, "Reactor pool with zero size was requested!");

			Common::Print("Initializing reactor pool...\n", reactorCount);
			Common::Print("Reactors Min: {}, Fallback: {}, Preferred: {}\n\n", MIN_REACTOR_COUNT,
			              FALLBACK_REACTOR_COUNT, reactorCount);

			this->Pool_.reserve(reactorCount);
			for (std::size_t i {0}; i < reactorCount; ++i)
			{
				if (!routineLink)
				{
					Print(Common::LogLevel::Warning,
					      "No reactor routine link specified. Querying CPU features and selecting accordingly...\n");
				}
				this->Pool_.emplace_back(Reactor {
					allocator, config, routineLink ? *routineLink : GetOptimalReactorRoutine({ }), i
				});
			}

			Common::Print('\n');
		}

		ReactorPool::~ReactorPool()
		{
			const auto size {this->Pool_.size()};
			this->Pool_.clear();
			Common::Print("Reactor pool destroyed! {} reactors destroyed!\n", size);
		}

		auto PrintShutdownReason(const ReactorShutdownReason reason, const InterruptAccumulator code) -> void
		{
			using namespace Common;

			switch (reason)
			{
				case ReactorShutdownReason::Success:
					Print(TextColor::BrightGreen, "OK ({:#X})\n", code);
					break;

				case ReactorShutdownReason::Error:
					Print(TextColor::Red, "Fatal Runtime Error ({:#X})\n", code);
					break;

				case ReactorShutdownReason::UserException:
					Print(TextColor::Red, "Exception ({:#X})\n", code);
					break;
			}
		}

		#if NOX_ARCH_X86_32

			auto RegisterDump_X86_32(std::ostream& out, const GprRegisterLane& gpr) -> void
			{
				out << "\n%eax = " << std::bitset<32>{gpr[0]};
				out << "\n%ebx = " << std::bitset<32>{gpr[1]};
				out << "\n%ecx = " << std::bitset<32>{gpr[2]};
				out << "\n%edx = " << std::bitset<32>{gpr[3]};
				out << "\n%esi = " << std::bitset<32>{gpr[4]};
				out << "\n%edi = " << std::bitset<32>{gpr[5]};
				out << "\n%ebp = " << std::bitset<32>{gpr[6]};
				out << "\n%esp = " << std::bitset<32>{gpr[7]};
			}

		#elif NOX_ARCH_X86_64

		/// <summary>
		/// Read and dump all the register values into the stream.
		/// </summary>
		/// <param name="out"></param>
		/// <param name="gpr"></param>
		/// <param name="xmm"></param>
		/// <param name="ymm"></param>
		/// <param name="zmm"></param>
		/// <returns></returns>
		auto RegisterDump_X86_64
		(
			std::ostream&                out,
			const GprRegisterLane&       gpr,
			const VectorRegisterLane128& xmm,
			const VectorRegisterLane256& ymm
		) -> void
		{
			out << std::dec;
			out << "\n%RAX   = " << std::bitset<64> {gpr[0]};
			out << "\n%RBX   = " << std::bitset<64> {gpr[1]};
			out << "\n%RCX   = " << std::bitset<64> {gpr[2]};
			out << "\n%RDX   = " << std::bitset<64> {gpr[3]};
			out << "\n%RSI   = " << std::bitset<64> {gpr[4]};
			out << "\n%RDI   = " << std::bitset<64> {gpr[5]};
			out << "\n%RBP   = " << std::bitset<64> {gpr[6]};
			out << "\n%RSP   = " << std::bitset<64> {gpr[7]};
			out << "\n%R8    = " << std::bitset<64> {gpr[8]};
			out << "\n%R9    = " << std::bitset<64> {gpr[9]};
			out << "\n%R10   = " << std::bitset<64> {gpr[10]};
			out << "\n%R11   = " << std::bitset<64> {gpr[11]};
			out << "\n%R12   = " << std::bitset<64> {gpr[12]};
			out << "\n%R13   = " << std::bitset<64> {gpr[13]};
			out << "\n%R14   = " << std::bitset<64> {gpr[14]};
			out << "\n%R15   = " << std::bitset<64> {gpr[15]};

			out << '\n';

			out << "\n%XMM0  = " << std::bitset<64> {xmm[0][0]} << std::bitset<64> {xmm[0][1]};
			out << "\n%XMM1  = " << std::bitset<64> {xmm[1][0]} << std::bitset<64> {xmm[1][1]};
			out << "\n%XMM2  = " << std::bitset<64> {xmm[2][0]} << std::bitset<64> {xmm[2][1]};
			out << "\n%XMM3  = " << std::bitset<64> {xmm[3][0]} << std::bitset<64> {xmm[3][1]};
			out << "\n%XMM4  = " << std::bitset<64> {xmm[4][0]} << std::bitset<64> {xmm[4][1]};
			out << "\n%XMM5  = " << std::bitset<64> {xmm[5][0]} << std::bitset<64> {xmm[5][1]};
			out << "\n%XMM6  = " << std::bitset<64> {xmm[6][0]} << std::bitset<64> {xmm[6][1]};
			out << "\n%XMM7  = " << std::bitset<64> {xmm[7][0]} << std::bitset<64> {xmm[7][1]};
			out << "\n%XMM8  = " << std::bitset<64> {xmm[8][0]} << std::bitset<64> {xmm[8][1]};
			out << "\n%XMM9  = " << std::bitset<64> {xmm[9][0]} << std::bitset<64> {xmm[9][1]};
			out << "\n%XMM10 = " << std::bitset<64> {xmm[10][0]} << std::bitset<64> {xmm[10][1]};
			out << "\n%XMM11 = " << std::bitset<64> {xmm[11][0]} << std::bitset<64> {xmm[11][1]};
			out << "\n%XMM12 = " << std::bitset<64> {xmm[12][0]} << std::bitset<64> {xmm[12][1]};
			out << "\n%XMM13 = " << std::bitset<64> {xmm[13][0]} << std::bitset<64> {xmm[13][1]};
			out << "\n%XMM14 = " << std::bitset<64> {xmm[14][0]} << std::bitset<64> {xmm[14][1]};
			out << "\n%XMM15 = " << std::bitset<64> {xmm[15][0]} << std::bitset<64> {xmm[15][1]};

			out << '\n';

			out << "\n%YMM0  = " << std::bitset<64> {ymm[0][0]} << std::bitset<64> {ymm[0][1]} << std::bitset<64> {
				ymm[0][2]
			} << std::bitset<64> {ymm[0][3]};
			out << "\n%YMM1  = " << std::bitset<64> {ymm[1][0]} << std::bitset<64> {ymm[1][1]} << std::bitset<64> {
				ymm[1][2]
			} << std::bitset<64> {ymm[1][3]};
			out << "\n%YMM2  = " << std::bitset<64> {ymm[2][0]} << std::bitset<64> {ymm[2][1]} << std::bitset<64> {
				ymm[2][2]
			} << std::bitset<64> {ymm[2][3]};
			out << "\n%YMM3  = " << std::bitset<64> {ymm[3][0]} << std::bitset<64> {ymm[3][1]} << std::bitset<64> {
				ymm[3][2]
			} << std::bitset<64> {ymm[3][3]};
			out << "\n%YMM4  = " << std::bitset<64> {ymm[4][0]} << std::bitset<64> {ymm[4][1]} << std::bitset<64> {
				ymm[4][2]
			} << std::bitset<64> {ymm[4][3]};
			out << "\n%YMM5  = " << std::bitset<64> {ymm[5][0]} << std::bitset<64> {ymm[5][1]} << std::bitset<64> {
				ymm[5][2]
			} << std::bitset<64> {ymm[5][3]};
			out << "\n%YMM6  = " << std::bitset<64> {ymm[6][0]} << std::bitset<64> {ymm[6][1]} << std::bitset<64> {
				ymm[6][2]
			} << std::bitset<64> {ymm[6][3]};
			out << "\n%YMM7  = " << std::bitset<64> {ymm[7][0]} << std::bitset<64> {ymm[7][1]} << std::bitset<64> {
				ymm[7][2]
			} << std::bitset<64> {ymm[7][3]};
			out << "\n%YMM8  = " << std::bitset<64> {ymm[8][0]} << std::bitset<64> {ymm[8][1]} << std::bitset<64> {
				ymm[8][2]
			} << std::bitset<64> {ymm[8][3]};
			out << "\n%YMM9  = " << std::bitset<64> {ymm[9][0]} << std::bitset<64> {ymm[9][1]} << std::bitset<64> {
				ymm[9][2]
			} << std::bitset<64> {ymm[9][3]};
			out << "\n%YMM10 = " << std::bitset<64> {ymm[10][0]} << std::bitset<64> {ymm[10][1]} << std::bitset<64> {
				ymm[10][2]
			} << std::bitset<64> {ymm[10][3]};
			out << "\n%YMM11 = " << std::bitset<64> {ymm[11][0]} << std::bitset<64> {ymm[11][1]} << std::bitset<64> {
				ymm[11][2]
			} << std::bitset<64> {ymm[11][3]};
			out << "\n%YMM12 = " << std::bitset<64> {ymm[12][0]} << std::bitset<64> {ymm[12][1]} << std::bitset<64> {
				ymm[12][2]
			} << std::bitset<64> {ymm[12][3]};
			out << "\n%YMM13 = " << std::bitset<64> {ymm[13][0]} << std::bitset<64> {ymm[13][1]} << std::bitset<64> {
				ymm[13][2]
			} << std::bitset<64> {ymm[13][3]};
			out << "\n%YMM14 = " << std::bitset<64> {ymm[14][0]} << std::bitset<64> {ymm[14][1]} << std::bitset<64> {
				ymm[14][2]
			} << std::bitset<64> {ymm[14][3]};
			out << "\n%YMM15 = " << std::bitset<64> {ymm[15][0]} << std::bitset<64> {ymm[15][1]} << std::bitset<64> {
				ymm[15][2]
			} << std::bitset<64> {ymm[15][3]};

			out << "\n\nUncaptured:\n\n";
			out << "%RIP\n\n";
			out << "%ZMM0,  %ZMM1,  %ZMM2,  %ZMM3\n";
			out << "%ZMM4,  %ZMM5,  %ZMM6,  %ZMM7\n";
			out << "%ZMM8,  %ZMM9,  %ZMM10, %ZMM11\n";
			out << "%ZMM12, %ZMM13, %ZMM14, %ZMM15\n";
			out << "%ZMM16, %ZMM17, %ZMM18, %ZMM19\n";
			out << "%ZMM20, %ZMM21, %ZMM22, %ZMM23\n";
			out << "%ZMM24, %ZMM25, %ZMM26, %ZMM27\n";
			out << "%ZMM28, %ZMM29, %ZMM30, %ZMM31\n\n";

			out << "%K0, %K1, %K2, %K3\n";
			out << "%K4, %K5, %K6, %K7\n";
			out << '\n';
		}

		#elif NOX_ARCH_ARM_64
#	error "Not yet implemented!"
		#else
#	error "Unknown arch!"
		#endif

		auto TaskQueueThread::DispatchJobQueue() -> void
		{
			for (;;)
			{
				TaskRoutine routine;
				{
					std::unique_lock lock {this->QueueMutex_};
					this->SharedCondition_.wait(lock, [this]
					{
						return
							!this->TaskQueue_.empty()
							|| this->Disposing_;
					});
					if (this->Disposing_)
					{
						break;
					}
					routine = this->TaskQueue_.front();
				}
				std::invoke(routine);
				{
					std::lock_guard lock {this->QueueMutex_};
					this->TaskQueue_.pop();
					this->SharedCondition_.notify_one();
				}
			}
		}

		TaskQueueThread::TaskQueueThread()
		{
			this->Worker_ = std::thread(&TaskQueueThread::DispatchJobQueue, this);
		}

		TaskQueueThread::TaskQueueThread(std::pmr::memory_resource& allocator) : TaskQueue_ {&allocator}
		{
			this->Worker_ = std::thread(&TaskQueueThread::DispatchJobQueue, this);
		}

		TaskQueueThread::~TaskQueueThread()
		{
			if (!this->Worker_.joinable())
			{
				[[unlikely]]
					return;
			}

			this->Join();
			this->QueueMutex_.lock();
			this->Disposing_ = true;
			this->SharedCondition_.notify_one();
			this->QueueMutex_.unlock();
			this->Worker_.join();
		}

		auto TaskQueueThread::Join() -> void
		{
			std::unique_lock lock {this->QueueMutex_};
			this->SharedCondition_.wait(lock, [this]
			{
				return this->TaskQueue_.empty();
			});
		}

		auto TaskQueueThread::Enqueue(TaskRoutine&& target) -> void
		{
			std::lock_guard lock {this->QueueMutex_};
			this->TaskQueue_.push(std::move(target));
			this->SharedCondition_.notify_one();
		}

		auto VerboseReactorDescriptor::Validate() const -> ReactorValidationResult
		{
			// validate all pointers:
			if (!this->CodeChunk || !this->InterruptHandler || !this->Stack)
			{
				[[unlikely]]
					return ReactorValidationResult::NullPtr;
			}

			#if NOX_OPT_EXECUTION_ADDRESS_MAPPING

			if (!this->CodeChunkInstructionMap || !(this->CodeChunkInstructionMap + this->CodeChunkSize - 1))
			{
				[[unlikely]]
					return ReactorValidationResult::NullPtr;
			}

			#endif

			// validate the size for the corresponding pointers:
			if (!this->CodeChunkSize || !this->StackSize)
			{
				[[unlikely]]
					return ReactorValidationResult::ZeroSize;
			}

			// first instruction will be skipped and must be NOP:
			if (CodeChunk->Instr != ByteCode::Instruction::NOp)
			{
				[[unlikely]]
					return ReactorValidationResult::MissingCodePrologue;
			}

			// last instruction must be interrupt:
			if (CodeChunkSize < 2 || (CodeChunk + CodeChunkSize - 2)->Instr != ByteCode::Instruction::Int)
			{
				[[unlikely]]
					return ReactorValidationResult::MissingCodeEpilogue;
			}

			// first stack entry is never used and must be nop-padding:
			if (*Stack != Common::Record::Padding())
			{
				[[unlikely]]
					return ReactorValidationResult::MissingStackPrologue;
			}

			if (this->IntrinsicTable)
			[[likely]]
			{
				// validate intrinsic routines:
				auto* const*       begin = this->IntrinsicTable;
				auto* const* const end   = this->IntrinsicTable + this->IntrinsicTableSize;
				while (begin < end)
				{
					if (!*begin++)
					{
						[[unlikely]]
							return ReactorValidationResult::NullIntrinsicRoutine;
					}
				}
			}

			return ReactorValidationResult::Ok;
		}
	}

	const constinit std::string_view SYSTEM_COPYRIGHT_TEXT =
		"(c) Copyright Mario Sieg <pinsrq> mt3000@gmx.de 2019-2021! All rights reserved!\n"
		"The Corium programming language and the Nominax runtime system is open source software:\nhttps://github.com/MarioSieg/Corium\n"
		"See the LICENSE file for licensing and copyright information!\n";

	const constinit std::string_view SYSTEM_LOGO_TEXT = R"(
                                                         #@@#   
                                                      %@@@@@@@@@
                                                     .@@@    (@@
                                                            &@@@
                                                          /@@@  
                                                         @@@*   
                                                       @@@@@@@@@
   @@@@@@@&             /@@@@@@@*           #@@@@@@@            
  ,@@@@@@@@@/            @@@@@@@@@         @@@@@@@@@            
  ,@@@@@@@@@@@            *@@@@@@@@@     @@@@@@@@@              
  ,@@@@@@@@@@@@@            @@@@@@@@@& @@@@@@@@@%               
  ,@@@@@@@@@@@@@@#            @@@@@@@@@@@@@@@@@                 
  ,@@@@@@@@@@@@@@@@            .@@@@@@@@@@@@@                   
  ,@@@@@@@@@@@@@@@@@@            %@@@@@@@@@*                    
  ,@@@@@@@(  #@@@@@@@@@         (@@@@@@@@@@@,                   
  ,@@@@@@@(    @@@@@@@@@*      @@@@@@@@@@@@@@@                  
  ,@@@@@@@(      @@@@@@@@@   @@@@@@@@@@@@@@@@@@@                
  ,@@@@@@@(       /@@@@@@@@@@@@@@@@@&   @@@@@@@@@(              
  ,@@@@@@@(         @@@@@@@@@@@@@@@       @@@@@@@@@             
  ,@@@@@@@(           @@@@@@@@@@@          .@@@@@@@@@           
                                          
     _   _  ___  __  __ ___ _   _    _   __  __
    | \ | |/ _ \|  \/  |_ _| \ | |  / \  \ \/ /
    |  \| | | | | |\/| || ||  \| | / _ \  \  / 
    | |\  | |_| | |  | || || |\  |/ ___ \ /  \
    |_| \_|\___/|_|  |_|___|_| \_/_/   \_/_/\_\

)";

	constexpr std::string_view LICENSE = R"(
	                                  Apache License
                            Version 2.0, January 2004
                         http:www.apache.org/licenses/
 
    TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
 
    1. Definitions.
 
       "License" shall mean the terms and conditions for use, reproduction,
       and distribution as defined by Sections 1 through 9 of this document.
 
       "Licensor" shall mean the copyright owner or entity authorized by
       the copyright owner that is granting the License.
 
       "Legal Entity" shall mean the union of the acting entity and all
       other entities that control, are controlled by, or are under common
       control with that entity. For the purposes of this definition,
       "control" means (i) the power, direct or indirect, to cause the
       direction or management of such entity, whether by contract or
       otherwise, or (ii) ownership of fifty percent (50%) or more of the
       outstanding shares, or (iii) beneficial ownership of such entity.
 
       "You" (or "Your") shall mean an individual or Legal Entity
       exercising permissions granted by this License.
 
       "Source" form shall mean the preferred form for making modifications,
       including but not limited to software source code, documentation
       source, and configuration files.
 
       "Object" form shall mean any form resulting from mechanical
       transformation or translation of a Source form, including but
       not limited to compiled object code, generated documentation,
       and conversions to other media types.
 
       "Work" shall mean the work of authorship, whether in Source or
       Object form, made available under the License, as indicated by a
       copyright notice that is included in or attached to the work
       (an example is provided in the Appendix below).
 
       "Derivative Works" shall mean any work, whether in Source or Object
       form, that is based on (or derived from) the Work and for which the
       editorial revisions, annotations, elaborations, or other modifications
       represent, as a whole, an original work of authorship. For the purposes
       of this License, Derivative Works shall not include works that remain
       separable from, or merely link (or bind by name) to the interfaces of,
       the Work and Derivative Works thereof.
 
       "Contribution" shall mean any work of authorship, including
       the original version of the Work and any modifications or additions
       to that Work or Derivative Works thereof, that is intentionally
       submitted to Licensor for inclusion in the Work by the copyright owner
       or by an individual or Legal Entity authorized to submit on behalf of
       the copyright owner. For the purposes of this definition, "submitted"
       means any form of electronic, verbal, or written communication sent
       to the Licensor or its representatives, including but not limited to
       communication on electronic mailing lists, source code control systems,
       and issue tracking systems that are managed by, or on behalf of, the
       Licensor for the purpose of discussing and improving the Work, but
       excluding communication that is conspicuously marked or otherwise
       designated in writing by the copyright owner as "Not a Contribution."
 
       "Contributor" shall mean Licensor and any individual or Legal Entity
       on behalf of whom a Contribution has been received by Licensor and
       subsequently incorporated within the Work.
 
    2. Grant of Copyright License. Subject to the terms and conditions of
       this License, each Contributor hereby grants to You a perpetual,
       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
       copyright license to reproduce, prepare Derivative Works of,
       publicly display, publicly perform, sublicense, and distribute the
       Work and such Derivative Works in Source or Object form.
 
    3. Grant of Patent License. Subject to the terms and conditions of
       this License, each Contributor hereby grants to You a perpetual,
       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
       (except as stated in this section) patent license to make, have made,
       use, offer to sell, sell, import, and otherwise transfer the Work,
       where such license applies only to those patent claims licensable
       by such Contributor that are necessarily infringed by their
       Contribution(s) alone or by combination of their Contribution(s)
       with the Work to which such Contribution(s) was submitted. If You
       institute patent litigation against any entity (including a
       cross-claim or counterclaim in a lawsuit) alleging that the Work
       or a Contribution incorporated within the Work constitutes direct
       or contributory patent infringement, then any patent licenses
       granted to You under this License for that Work shall terminate
       as of the date such litigation is filed.
 
    4. Redistribution. You may reproduce and distribute copies of the
       Work or Derivative Works thereof in any medium, with or without
       modifications, and in Source or Object form, provided that You
       meet the following conditions:
 
       (a) You must give any other recipients of the Work or
           Derivative Works a copy of this License; and
 
       (b) You must cause any modified files to carry prominent notices
           stating that You changed the files; and
 
       (c) You must retain, in the Source form of any Derivative Works
           that You distribute, all copyright, patent, trademark, and
           attribution notices from the Source form of the Work,
           excluding those notices that do not pertain to any part of
           the Derivative Works; and
 
       (d) If the Work includes a "NOTICE" text file as part of its
           distribution, then any Derivative Works that You distribute must
           include a readable copy of the attribution notices contained
           within such NOTICE file, excluding those notices that do not
           pertain to any part of the Derivative Works, in at least one
           of the following places: within a NOTICE text file distributed
           as part of the Derivative Works; within the Source form or
           documentation, if provided along with the Derivative Works; or,
           within a display generated by the Derivative Works, if and
           wherever such third-party notices normally appear. The contents
           of the NOTICE file are for informational purposes only and
           do not modify the License. You may add Your own attribution
           notices within Derivative Works that You distribute, alongside
           or as an addendum to the NOTICE text from the Work, provided
           that such additional attribution notices cannot be construed
           as modifying the License.
 
       You may add Your own copyright statement to Your modifications and
       may provide additional or different license terms and conditions
       for use, reproduction, or distribution of Your modifications, or
       for any such Derivative Works as a whole, provided Your use,
       reproduction, and distribution of the Work otherwise complies with
       the conditions stated in this License.
 
    5. Submission of Contributions. Unless You explicitly state otherwise,
       any Contribution intentionally submitted for inclusion in the Work
       by You to the Licensor shall be under the terms and conditions of
       this License, without any additional terms or conditions.
       Notwithstanding the above, nothing herein shall supersede or modify
       the terms of any separate license agreement you may have executed
       with Licensor regarding such Contributions.
 
    6. Trademarks. This License does not grant permission to use the trade
       names, trademarks, service marks, or product names of the Licensor,
       except as required for reasonable and customary use in describing the
       origin of the Work and reproducing the content of the NOTICE file.
 
    7. Disclaimer of Warranty. Unless required by applicable law or
       agreed to in writing, Licensor provides the Work (and each
       Contributor provides its Contributions) on an "AS IS" BASIS,
       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
       implied, including, without limitation, any warranties or conditions
       of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
       PARTICULAR PURPOSE. You are solely responsible for determining the
       appropriateness of using or redistributing the Work and assume any
       risks associated with Your exercise of permissions under this License.
 
    8. Limitation of Liability. In no event and under no legal theory,
       whether in tort (including negligence), contract, or otherwise,
       unless required by applicable law (such as deliberate and grossly
       negligent acts) or agreed to in writing, shall any Contributor be
       liable to You for damages, including any direct, indirect, special,
       incidental, or consequential damages of any character arising as a
       result of this License or out of the use or inability to use the
       Work (including but not limited to damages for loss of goodwill,
       work stoppage, computer failure or malfunction, or any and all
       other commercial damages or losses), even if such Contributor
       has been advised of the possibility of such damages.
 
    9. Accepting Warranty or Additional Liability. While redistributing
       the Work or Derivative Works thereof, You may choose to offer,
       and charge a fee for, acceptance of support, warranty, indemnity,
       or other liability obligations and/or rights consistent with this
       License. However, in accepting such obligations, You may act only
       on Your own behalf and on Your sole responsibility, not on behalf
       of any other Contributor, and only if You agree to indemnify,
       defend, and hold each Contributor harmless for any liability
       incurred by, or claims asserted against, such Contributor by reason
       of your accepting any such warranty or additional liability.
 
    END OF TERMS AND CONDITIONS
 
    APPENDIX: How to apply the Apache License to your work.
 
       To apply the Apache License to your work, attach the following
       boilerplate notice, with the fields enclosed by brackets "[]"
       replaced with your own identifying information. (Don't include
       the brackets!)  The text should be enclosed in the appropriate
       comment syntax for the file format. We also recommend that a
       file or class name and description of purpose be included on the
       same "printed page" as the copyright notice for easier
       identification within third-party archives.
 
    Copyright 2021 Mario Sieg "pinsrq" <mt3000@gmx.de>
 
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
 
        http:www.apache.org/licenses/LICENSE-2.0
 
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
	)";
}
