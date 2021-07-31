// File: Core.cpp
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

#include <algorithm>
#include <bitset>
#include <fstream>
#include <sstream>
#include <string_view>

#include "../../Nominax/Include/Nominax/Core.hpp"
#include "../../Nominax/Include/Nominax/Foundation.hpp"

#include "ReactorCores.hpp"

namespace Nominax
{
	extern const constinit std::string_view SYSTEM_COPYRIGHT_TEXT;
	extern const constinit std::string_view SYSTEM_LOGO_TEXT;

	namespace Core
	{
		using namespace Foundation;

		auto BasicReactorDescriptor::BuildDetailed() const -> VerboseReactorDescriptor
		{
			return
			{
				.CodeChunk = std::data(this->CodeChunk),
				.CodeChunkSize = std::size(this->CodeChunk),
				.IntrinsicTable = std::data(this->IntrinsicTable),
				.IntrinsicTableSize = std::size(this->IntrinsicTable),
				.InterruptHandler = &this->InterruptHandler,
				.Stack = std::data(this->Stack),
				.StackSize = std::size(this->Stack),
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
		static auto InitSysInfo() -> Snapshot
		{
			Print('\n');
			Snapshot snapshot { };
			snapshot.Print();
			return snapshot;
		}

		/// <summary>
		/// Query and print cpu features.
		/// </summary>
		/// <returns></returns>Common::
		static auto InitCpuFeatures() -> CpuFeatureDetector
		{
			Print('\n');
			CpuFeatureDetector cpuFeatureDetector { };
			cpuFeatureDetector.Dump();
			Print('\n');
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
			Print("{0: <14} | {1: <14} | {2: <14}\n", name, sizeof(T), alignof(T));
		}

		/// <summary>
		/// Print size and alignment of common types.
		/// </summary>
		/// <returns></returns>
		static auto PrintTypeInfoTable() -> void
		{
			Print("{0: <14} | {1: <14} | {2: <14}\n\n", "Type", "Byte WordSize", "Alignment");
			PrintTypeInfo<Record>("Record");
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
			Print(SYSTEM_LOGO_TEXT);
			Print(SYSTEM_COPYRIGHT_TEXT);
			Print("\nNominax Version: v.{}.{}\n", SYSTEM_VERSION.Major, SYSTEM_VERSION.Minor);
			Print("Platform: {} {}\n", NOX_OS_NAME, NOX_ARCH_SIZE_NAME);
			Print("Arch: {}\n", NOX_ARCH_NAME);
			Print("IsPosix: {}\n", NOX_IS_POSIX);
			Print("Compiled with: {} - C++ 20\n", NOX_COM_NAME);
			Print('\n');
			PrintTypeInfoTable();
			Print('\n');
		}

		#define DISPATCH_HOOK(method, ...)							\
        do															\
        {															\
            Foundation::Print("Dispatching hook: " #method "\n");	\
            NOX_PAS_TRUE											\
            (														\
                this-> method (__VA_ARGS__),						\
                "\" "#method "\" returned false!"					\
            );														\
        }															\
        while(false)

		#if NOX_TESTING || NOX_DEBUG
		#define VALIDATE_ONLINE_BOOT_STATE() NOX_PAS_TRUE(this->IsOnline(), "Environment is offline!")
		#else
		#define VALIDATE_ONLINE_BOOT_STATE()
		#endif

		/// <summary>
		/// Checks if the byte stack size is divisible by sizeof(Common::Record) and panics if not.
		/// Returns the counts of records.
		/// </summary>
		/// <param name="sizeInBytes"></param>
		/// <returns></returns>
		static inline auto MapStackSize(const U64 sizeInBytes) -> U64
		{
			if (sizeInBytes % sizeof(Record) != 0)
			{
				[[unlikely]]
					Panic(NOX_PANIC_INFO(), "Invalid stack size: {}! Must be a multiple of sizeof(Common::Record) -> 8!", sizeInBytes);
			}
			return sizeInBytes / sizeof(Record);
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
			U64       desiredSize,
			const U64 reactorCount,
			U64       reactorStackSize
		) -> U64
		{
			reactorStackSize = MapStackSize(reactorStackSize);
			desiredSize      = desiredSize ? desiredSize : Environment::FALLBACK_SYSTEM_POOL_SIZE;
			return desiredSize + reactorCount * (reactorStackSize * sizeof(Record));
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
		static constexpr auto ClampBootPoolSize(const U64 desiredSize) -> U64
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
			const U64                            idx, const ByteCode::Stream& appCode,
			const ByteCode::ValidationResultCode code
		)
		{
			const bool isInstructionFault
			{
				code == ByteCode::ValidationResultCode::NotEnoughArgumentsForInstruction
				|| code == ByteCode::ValidationResultCode::TooManyArgumentsForInstruction
				|| code == ByteCode::ValidationResultCode::ArgumentTypeMismatch
			};

			for (U64 i {idx}; i < idx + 8 && i < appCode.Size(); ++i)
			{
				if (appCode[i].Contains<ByteCode::Instruction>())
				{
					Print(TextColor::Green, "\n{:#018X}: ", i);
					Print(TextColor::BrightBlue, "{}", appCode[i].Value.R64.AsU64);
				}
				else
				{
					Print(TextColor::Magenta, " {}", appCode[i].Value.R64.AsU64);
				}

				if (isInstructionFault && i == idx)
				{
					Print(LogLevel::Error, " {} ->", code);
				}
			}

			Print('\n');
		}

		/// <summary>
		/// Helper to allocate a environment pool.
		/// </summary>
		[[nodiscard]]
		NOX_ALLOC_SIZE(1) static inline auto AllocatePool(const U64 size, const std::string_view poolId) -> U8*
		{
			Print("Allocating {} pool with size: {} MB\n", poolId, Bytes2Megabytes(static_cast<F64>(size)));
			auto* NOX_RESTRICT const mem {new(std::nothrow) U8[size]};
			if (!mem)
			{
				[[unlikely]]
					Panic(NOX_PANIC_INFO(), "Allocation of monotonic {} pool with size {} MB failed!", poolId,
					      Bytes2Megabytes(static_cast<F64>(size)));
			}
			return mem;
		}

		/// <summary>
		/// Computes the percent of used memory by a specific resource.
		/// </summary>
		/// <param name="used"></param>
		/// <param name="max"></param>
		/// <returns></returns>
		[[nodiscard]]
		static constexpr auto ComputeMemoryPercent(const U64 used, const U64 max) -> F64
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
			const U64                            size
		) -> std::pair<std::ptrdiff_t, F64>
		{
			const U8* const      needle {static_cast<U8*>(resource.allocate(sizeof(U8), alignof(U8)))};
			const std::ptrdiff_t offset {needle - *buffer};                             // compute allocation offset
			const F64            poolUsagePercent {ComputeMemoryPercent(offset, size)}; // compute percent usage
			return {offset, poolUsagePercent};
		}

		/// <summary>
		/// Query execution routine for environment.
		/// </summary>
		/// <param name="fallback"></param>
		/// <param name="cpu"></param>
		/// <returns></returns>
		static inline auto QueryExecRoutine(const bool fallback, const CpuFeatureDetector& cpu)
		{
			return fallback ? HyperVisor::GetFallbackRoutineLink() : HyperVisor::GetOptimalReactorRoutine(cpu);
		}

		/// <summary>
		/// Contains all the runtime variables required for the runtime system.
		/// </summary>
		/// <param name="descriptor"></param>
		/// <returns></returns>
		struct Environment::Context final
		{
			const U64                                                ReactorCount;
			const U64                                                BootPoolSize;
			const std::unique_ptr<U8[]>                              BootPool;
			std::pmr::monotonic_buffer_resource                      BootPoolResource;
			const U64                                                SystemPoolSize;
			const std::unique_ptr<U8[]>                              SystemPool;
			std::pmr::monotonic_buffer_resource                      SystemPoolResource;
			std::pmr::unordered_set<std::pmr::string>                Arguments;
			std::pmr::string                                         AppName;
			std::pmr::vector<std::chrono::duration<F64, std::micro>> ExecutionTimeHistory;
			const std::chrono::high_resolution_clock::time_point     BootStamp;
			std::chrono::milliseconds                                BootTime;
			const Snapshot                                           SysInfoSnapshot;
			const CpuFeatureDetector                                 CpuFeatures;
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
			OptimalReactorRoutine {QueryExecRoutine(descriptor.ForceFallback, CpuFeatures)},
			CorePool
			{
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

		auto Environment::OnPreExecutionHook([[maybe_unused]] const ByteCode::Image& appCodeBundle) -> bool
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

		Environment::Environment(const IAllocator* const allocator)
		{
			if (allocator)
			{
				GlobalAllocatorProxy = allocator;
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
			Print("Booting runtime environment...\nApp: \"{}\"\n", descriptor.AppName);
			const auto tik {std::chrono::high_resolution_clock::now()};

			// Invoke hook:
			DISPATCH_HOOK(OnPreBootHook,);

			Print
			(
				"Monotonic boot pool fixed size: {} MB, Min: {} MB, Max: {} MB\n",
				Bytes2Megabytes(static_cast<F64>(descriptor.BootPoolSize)),
				Bytes2Megabytes(static_cast<F64>(BOOT_POOL_SIZE_MIN)),
				Bytes2Megabytes(static_cast<F64>(BOOT_POOL_SIZE_MAX))
			);

			Print
			(
				"Monotonic system pool fixed size: {} MB, Fallback: {} MB\n",
				Bytes2Megabytes(descriptor.SystemPoolSize),
				Bytes2Megabytes(FALLBACK_SYSTEM_POOL_SIZE)
			);

			// No, we cannot use std::make_unique because we want it noexcept!
			// ReSharper disable once CppSmartPointerVsMakeFunction
			this->Context_ = std::unique_ptr<Context, ContextDeleter>(new(std::nothrow) Context(descriptor));
			NOX_PAS_NOT_NULL(this->Context_, "Context allocation failed!");

			// Invoke hook:
			DISPATCH_HOOK(OnPostBootHook,);

			const auto tok {std::chrono::high_resolution_clock::now()};

			// Get memory snapshot:
			const U64 memSnapshot {Os::QueryProcessMemoryUsed()};
			const F64 memUsagePercent {ComputeMemoryPercent(memSnapshot, this->Context_->SysInfoSnapshot.TotalSystemMemory)};

			// Query pool info
			const auto [bootPoolSize, bootPoolPer]
			{
				QueryMemoryResourceUsage
				(
					this->Context_->BootPoolResource,
					this->Context_->BootPool,
					this->Context_->BootPoolSize
				)
			};

			// Query pool info
			const auto [sysPoolSize, sysPoolPer]
			{
				QueryMemoryResourceUsage
				(
					this->Context_->SystemPoolResource,
					this->Context_->SystemPool,
					this->Context_->SystemPoolSize
				)
			};

			const auto ms {std::chrono::duration_cast<std::chrono::milliseconds>(tok - tik)};
			this->Context_->BootTime = ms;

			Print
			(
				"Runtime environment online!\n"
				"Process memory snapshot: {:.02f} % [{} MB / {} MB]\n"
				"Monotonic boot pool snapshot:	 {:.02f} % [{} KB / {} KB]\n"
				"Monotonic system pool snapshot: {:.02f} % [{} MB / {} MB]\n"
				"Boot time: {}\n"
				"\n",
				memUsagePercent,
				Bytes2Megabytes(static_cast<F64>(memSnapshot)),
				Bytes2Megabytes(static_cast<F64>(this->Context_->SysInfoSnapshot.TotalSystemMemory)),
				bootPoolPer,
				Bytes2Kilobytes(static_cast<F64>(bootPoolSize)),
				Bytes2Kilobytes(static_cast<F64>(this->Context_->BootPoolSize)),
				sysPoolPer,
				Bytes2Megabytes(static_cast<F64>(sysPoolSize)),
				Bytes2Megabytes(static_cast<F64>(this->Context_->SystemPoolSize)),
				ms
			);
		}

		auto Environment::Execute(const ByteCode::Image& image) -> ExecutionResult
		{
			using namespace Foundation;
			using std::chrono::duration_cast;
			using std::chrono::duration;

			VALIDATE_ONLINE_BOOT_STATE();

			// Invoke hook:
			DISPATCH_HOOK(OnPreExecutionHook, image);

			// Info
			Print(LogLevel::Warning, "Executing...\n");
			std::cout.flush();

			// Execute on alpha reactor:
			const auto& [reason, state] {(*this->Context_->CorePool)(image)};

			// Add execution time:
			const auto micros
			{
				std::chrono::duration_cast<duration<F64, std::micro>>(state.Duration)
			};
			this->Context_->ExecutionTimeHistory.emplace_back(micros);

			using Rsr = ReactorShutdownReason;

			// Print exec info:
			const auto level {reason == Rsr::Success ? LogLevel::Success : LogLevel::Error};
			const auto time {duration_cast<duration<F64, std::ratio<1>>>(micros)};
			Print(level, "Execution #{} done! Runtime {:.04}\n", std::size(this->Context_->ExecutionTimeHistory), time);
			std::cout.flush();

			// Invoke hook:
			DISPATCH_HOOK(OnPostExecutionHook,);
			return
			{
				.ShutdownReason = reason,
				.ReactorResultState = state
			};
		}

		auto Environment::Execute(ByteCode::Stream&& stream) -> ExecutionResult
		{
			ByteCode::Image codeImage { };
			const auto      buildResult {ByteCode::Stream::Build(std::move(stream), this->GetOptimizationHints(), codeImage)};
			NOX_PAS_EQ(buildResult, ByteCode::ValidationResultCode::Ok, Format("Byte code validation failed for stream! {}", REACTOR_VALIDATION_RESULT_ERROR_MESSAGES[ToUnderlying(buildResult)]));
			stream = { };
			return (*this)(codeImage);
		}

		auto Environment::Execute(const ByteCode::Stream& stream) -> ExecutionResult
		{
			ByteCode::Image codeImage { };
			const auto      buildResult {ByteCode::Stream::Build(stream, this->GetOptimizationHints(), codeImage)};
			NOX_PAS_EQ(buildResult, ByteCode::ValidationResultCode::Ok, Format("Byte code validation failed for stream! {}", REACTOR_VALIDATION_RESULT_ERROR_MESSAGES[ToUnderlying(buildResult)]));
			return (*this)(codeImage);
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

		auto Environment::GetSystemSnapshot() const -> const Snapshot&
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->SysInfoSnapshot;
		}

		auto Environment::GetProcessorFeatureSnapshot() const -> const CpuFeatureDetector&
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->CpuFeatures;
		}

		auto Environment::GetAppName() const -> const std::pmr::string&
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->AppName;
		}

		auto Environment::GetMonotonicSystemPoolSize() const -> U64
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->SystemPoolSize;
		}

		auto Environment::GetExecutionCount() const -> U64
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->ExecutionTimeHistory.size();
		}

		auto Environment::GetExecutionTimeHistory() const -> const std::pmr::vector<std::chrono::duration<F64, std::micro>>&
		{
			VALIDATE_ONLINE_BOOT_STATE();
			return this->Context_->ExecutionTimeHistory;
		}

		auto Environment::GetOptimizationHints() const -> ByteCode::OptimizationHints
		{
			VALIDATE_ONLINE_BOOT_STATE();
			const void*& jumpTable {*this->Context_->OptimalReactorRoutine.JumpTable};
			return
			{
				jumpTable
			};
		}

		#undef VALIDATE_ONLINE_BOOT_STATE
		#undef DISPATCH_HOOK

		FixedStack::FixedStack(std::pmr::memory_resource& allocator, const U64 sizeInRecords) : Buffer_ {&allocator}
		{
			NOX_PAS_NOT_ZERO(sizeInRecords, "Fixed stack with zero size was requested!");

			// allocate:
			this->Buffer_.resize(sizeInRecords);

			// insert padding:
			this->Buffer_.front() = Record::Padding();
		}

		auto DefaultInterruptRoutine(InterruptAccumulator) -> void { }

		auto GetDefaultInterruptRoutine() -> InterruptRoutineProxy*
		{
			return &DefaultInterruptRoutine;
		}

		[[maybe_unused]]
		static auto CreateDescriptor
		(
			FixedStack&                             stack,
			const ByteCode::Image&                  image,
			ByteCode::UserIntrinsicRoutineRegistry& intrinsicTable,
			InterruptRoutineProxy&                  interruptHandler
		) -> VerboseReactorDescriptor
		{
			const auto simpleDescriptor = BasicReactorDescriptor
			{
				.CodeChunk = image.GetReactorView(),
				.IntrinsicTable = intrinsicTable,
				.Stack = stack,
				.InterruptHandler = interruptHandler
			};
			return simpleDescriptor.BuildDetailed();
		}

		Reactor::Reactor
		(
			std::pmr::memory_resource&    allocator,
			const ReactorSpawnDescriptor& descriptor,
			const ReactorRoutineLink&     routineLink,
			const U64                     poolIdx
		) :
			Id_ {Xorshift128ThreadLocal()},
			PoolIndex_ {poolIdx},
			SpawnStamp_ {std::chrono::high_resolution_clock::now()},
			PowerPreference_ {descriptor.PowerPref},
			Input_ { },
			Output_ {.Input = &Input_},
			Stack_ {allocator, descriptor.StackSize},
			IntrinsicTable_ {descriptor.SharedIntrinsicTable},
			InterruptHandler_ {descriptor.InterruptHandler ? descriptor.InterruptHandler : GetDefaultInterruptRoutine()},
			RoutineLink_ {routineLink}
		{
			Print
			(
				"Reactor {:08X}: "
				"Stack: {} MB, "
				"{} KRec, "
				"Intrin: {}, "
				"Interrupt: {}, "
				"Power: {}, "
				"Pool: {:02}\n",
				this->Id_,
				Bytes2Megabytes(this->Stack_.Size() * sizeof(Record)),
				this->Stack_.Size() / 1000,
				std::size(this->IntrinsicTable_),
				this->InterruptHandler_ == GetDefaultInterruptRoutine() ? "Default" : "Overridden",
				this->PowerPreference_ == PowerPreference::HighPerformance ? "Performance" : "PowerSafe",
				this->PoolIndex_
			);
		}

		auto Reactor::Execute(const ByteCode::Image& bundle) -> std::pair<ReactorShutdownReason, const ReactorState&>
		{
			this->Input_ = CreateDescriptor
			(
				this->Stack_,
				bundle,
				this->IntrinsicTable_,
				*this->InterruptHandler_
			);
			const auto validationResult {this->Input_.Validate()};
			if (validationResult != ReactorValidationResult::Ok)
			[[unlikely]]
			{
				const std::string_view message {REACTOR_VALIDATION_RESULT_ERROR_MESSAGES[ToUnderlying(validationResult)]};
				Panic(NOX_PANIC_INFO(), "Reactor {:#X} validation failed with the following reason: {}", this->Id_, message);
			}
			ReactorCoreExecutionRoutine* const routine {this->RoutineLink_.ExecutionRoutine};
			NOX_PAS_NOT_NULL(routine, "Reactor execution routine is nullptr!");
			this->Output_.Input = &this->Input_;
			const ReactorShutdownReason result {(*routine)(&this->Input_, &this->Output_, nullptr)};
			return {result, this->Output_};
		}

		auto SingletonExecutionProxy
		(
			const VerboseReactorDescriptor& input, const CpuFeatureDetector& target,
			const void****                  outJumpTable
		) -> std::pair<ReactorShutdownReason, ReactorState>
		{
			ReactorState                output {.Input = &input};
			const ReactorShutdownReason result {SingletonExecutionProxy(input, output, target, outJumpTable)};
			return {result, output};
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
			NOX_PAS_NOT_NULL(this->ExecutionRoutine, "Routine for reactor routine link is null!");
			NOX_PAS_NOT_NULL(this->JumpTable, "Jump table for reactor routine link is null!");
		}

		static constexpr std::array<ReactorCoreExecutionRoutine*, static_cast<U64>(ReactorCoreSpecialization::Count)> REACTOR_REGISTRY
		{
			&ReactorCore_Fallback,
			&ReactorCore_Debug,

			#if NOX_ARCH_X86_64

			&ReactorCore_Avx,
			&ReactorCore_Avx512F,

			#endif
		};

		auto HyperVisor::SmartSelectReactor(const CpuFeatureDetector& cpuFeatureDetector) -> ReactorCoreSpecialization
		{
			#if NOX_ARCH_X86_64

			// if we have AVX 512, use AVX 512:
			if (cpuFeatureDetector[CpuFeatureBits::Avx512F])
			{
				return ReactorCoreSpecialization::Amd64_Avx512F;
			}

			// if we have AVX, use AVX:
			if (cpuFeatureDetector[CpuFeatureBits::Avx])
			{
				return ReactorCoreSpecialization::Amd64_Avx;
			}

			#elif NOX_ARCH_ARM_64
#	error "ARM64 not yet supported!"
			#endif

			return ReactorCoreSpecialization::Fallback;
		}

		auto HyperVisor::GetReactorRegistry() -> const ReactorRegistry&
		{
			return REACTOR_REGISTRY;
		}

		auto HyperVisor::GetFallbackRoutineLink() -> ReactorRoutineLink
		{
			constexpr auto specialization {ReactorCoreSpecialization::Fallback};

			ReactorCoreExecutionRoutine* const routine
			{
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

		auto HyperVisor::GetDebugRoutineLink() -> ReactorRoutineLink
		{
			constexpr auto specialization {ReactorCoreSpecialization::Debug};

			ReactorCoreExecutionRoutine* const routine
			{
				GetReactorRoutineFromRegistryByTarget(ReactorCoreSpecialization::Debug)
			};
			const void** const jumpTable {QueryJumpTable(*routine)};
			return
			{
				specialization,
				routine,
				jumpTable
			};
		}

		auto HyperVisor::GetReactorRoutineFromRegistryByTarget(const ReactorCoreSpecialization target) -> ReactorCoreExecutionRoutine*
		{
			ReactorCoreExecutionRoutine* const routine
			{
				REACTOR_REGISTRY[static_cast<U64>(target)]
			};
			NOX_PAS_NOT_NULL(routine, "Reactor core execution routine is nullptr!");
			return routine;
		}

		auto HyperVisor::GetOptimalReactorRoutine(const CpuFeatureDetector& features) -> ReactorRoutineLink
		{
			static thread_local constinit U16 QueryCounter;
			ReactorCoreSpecialization         specialization {SmartSelectReactor(features)};
			ReactorCoreExecutionRoutine*      routine {GetReactorRoutineFromRegistryByTarget(specialization)};
			const void**                      jumpTable {QueryJumpTable(*routine)};
			Print
			(
				"Execution Routine: {}, Registry ID: {:X}, Query: {}, Reactor Registry WordSize: {}\n",
				GetReactorCoreSpecializationName(specialization),
				static_cast<std::uint64_t>(specialization),
				++QueryCounter,
				std::size(REACTOR_REGISTRY)
			);
			if (QueryCounter > 1)
			{
				[[unlikely]]
					Print(LogLevel::Warning,
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
			const VerboseReactorDescriptor& input, ReactorState& output,
			const CpuFeatureDetector&       target,
			const void****                  outJumpTable
		) -> ReactorShutdownReason
		{
			return HyperVisor::GetOptimalReactorRoutine(target).ExecutionRoutine(&input, &output, outJumpTable);
		}

		auto QueryJumpTable(ReactorCoreExecutionRoutine& routine) -> const void**
		{
			const void**   jumpTable { };
			const void***  proxy {&jumpTable};
			const void**** writer {&proxy};
			return routine(nullptr, nullptr, writer) == ReactorShutdownReason::Success ? jumpTable : nullptr;
		}

		auto ReactorPool::SmartQueryReactorCount(const U64 desired) -> U64
		{
			return desired < MIN_REACTOR_COUNT ? std::thread::hardware_concurrency() : desired;
		}

		ReactorPool::ReactorPool
		(
			std::pmr::memory_resource&               allocator,
			const U64                                reactorCount,
			const ReactorSpawnDescriptor&            config,
			const std::optional<ReactorRoutineLink>& routineLink
		) : Pool_ {&allocator}
		{
			NOX_PAS_NOT_ZERO(reactorCount, "Reactor pool with zero size was requested!");

			Print("Initializing reactor pool...\n", reactorCount);
			Print("Reactors Min: {}, Fallback: {}, Preferred: {}\n\n", MIN_REACTOR_COUNT, FALLBACK_REACTOR_COUNT, reactorCount);

			this->Pool_.reserve(reactorCount);
			for (U64 i {0}; i < reactorCount; ++i)
			{
				if (!routineLink)
				{
					[[unlikely]]
						Print(LogLevel::Warning, "No reactor routine link specified. Using fallback reactor!\n");
				}
				Reactor reactor
				{
					allocator, config, routineLink ? *routineLink : HyperVisor::GetFallbackRoutineLink(), i
				};
				this->Pool_.emplace_back(std::move(reactor));
			}

			Print('\n');
		}

		ReactorPool::~ReactorPool()
		{
			const auto size {this->Pool_.size()};
			this->Pool_.clear();
			Print("Reactor pool destroyed! {} reactors destroyed!\n", size);
		}

		auto PrintShutdownReason(const ReactorShutdownReason reason, const InterruptAccumulator code) -> void
		{
			using namespace Foundation;

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

		auto TaskQueueThread::DispatchJobQueue() -> void
		{
			for (;;)
			{
				TaskRoutine routine;
				{
					std::unique_lock<std::mutex> lock {this->QueueMutex_};
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
					std::lock_guard<std::mutex> lock {this->QueueMutex_};
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
			std::unique_lock<std::mutex> lock {this->QueueMutex_};
			this->SharedCondition_.wait(lock, [this]
			{
				return this->TaskQueue_.empty();
			});
		}

		auto TaskQueueThread::Enqueue(TaskRoutine&& target) -> void
		{
			std::lock_guard<std::mutex> lock {this->QueueMutex_};
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

			// validate the size for the corresponding pointers:
			if (!this->CodeChunkSize || !this->StackSize)
			{
				[[unlikely]]
					return ReactorValidationResult::ZeroSize;
			}


			// If we are using execution address mapping,
			// all instructions are pointers so we cannot check the instruction type

			#if !NOX_OPT_EXECUTION_ADDRESS_MAPPING

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

			#endif

			// first stack entry is never used and must be nop-padding:
			if (*Stack != Record::Padding())
			{
				[[unlikely]]
					return ReactorValidationResult::MissingStackPrologue;
			}

			if (this->IntrinsicTable)
			[[likely]]
			{
				// validate intrinsic routines:
				auto* const*       begin {this->IntrinsicTable};
				auto* const* const end {this->IntrinsicTable + this->IntrinsicTableSize};
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
