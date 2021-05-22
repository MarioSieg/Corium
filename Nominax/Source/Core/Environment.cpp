// File: Environment.cpp
// Author: Mario
// Created: 17.04.2021 2:32 PM
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

#include <iomanip>
#include <iostream>

#include "../../Include/Nominax/Nominax.hpp"

namespace Nominax::Core
{
	using namespace Nominax;
	using namespace ByteCode;
	using namespace Common;
	using namespace System;

	/// <summary>
	/// Query and print machine info.
	/// </summary>
	/// <returns></returns>
	static auto InitSysInfo() noexcept(false) -> Snapshot
	{
		Print('\n');
		Snapshot snapshot { };
		snapshot.Print();
		return snapshot;
	}

	/// <summary>
	/// Query and print cpu features.
	/// </summary>
	/// <returns></returns>
	static auto InitCpuFeatures() noexcept(false) -> CpuFeatureDetector
	{
		Print('\n');
		CpuFeatureDetector cpuFeatureDetector { };
		cpuFeatureDetector.Print();
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
	/// <param name="threads"></param>
	/// <returns></returns>
	static auto PrintTypeInfoTable() -> void
	{
		Print("{0: <14} | {1: <14} | {2: <14}\n\n", "Type", "Byte Size", "Alignment");
		PrintTypeInfo<Record>("Record");
		PrintTypeInfo<Signal>("Signal");
		PrintTypeInfo<Signal::Discriminator>("SignalDisc");
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
	static auto PrintSystemInfo() -> void
	{
		Print(SYSTEM_LOGO_TEXT);
		Print(SYSTEM_COPYRIGHT_TEXT);
		Print("\nNominax Version: v.{}.{}\n", SYSTEM_VERSION.Major, SYSTEM_VERSION.Minor);
		Print("Platform: {} {}\n", NOMINAX_OS_NAME, NOMINAX_ARCH_SIZE_NAME);
		Print("Arch: {}\n", NOMINAX_ARCH_NAME);
		Print("IsPosix: {}\n", NOMINAX_IS_POSIX);
		Print("Compiled with: {} - C++ 20\n", NOMINAX_COM_NAME);
		Print("\n");
		PrintTypeInfoTable();
		Print("\n");
	}

#define DISPATCH_HOOK(method, ...)						\
	do													\
	{													\
		Print("Dispatching hook: " #method "\n");		\
		NOMINAX_PANIC_ASSERT_TRUE						\
		(												\
			this-> method (__VA_ARGS__),				\
			"\" "#method "\" returned false!"			\
		);												\
	}													\
	while(false)

#define VALIDATE_ONLINE_BOOT_STATE() NOMINAX_PANIC_ASSERT_TRUE(this->IsOnline(), "Environment is offline!")

	/// <summary>
	/// Compute the final size of the system pool.
	/// If the desired size is 0, fallback size is used.
	/// Y = Y != 0 + F
	/// S = Y + (C * (Z * R))
	/// Y = desired size
	/// S = final size
	/// C = reactor count
	/// Z = reactor stack size
	/// R = sizeof(Record)
	/// </summary>
	/// <param name="desiredSize"></param>
	/// <param name="reactorCount"></param>
	/// <param name="reactorStackSize"></param>
	/// <returns></returns>
	static constexpr auto ComputePoolSize
	(
		std::size_t       desiredSize,
		const std::size_t reactorCount,
		const std::size_t reactorStackSize
	)
	noexcept(true) -> std::size_t
	{
		desiredSize = !desiredSize ? Environment::FALLBACK_SYSTEM_POOL_SIZE : desiredSize;
		return desiredSize + reactorCount * (reactorStackSize * sizeof(Record));
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="idx"></param>
	/// <param name="appCode"></param>
	/// <param name="code"></param>
	/// <returns></returns>
	static auto PrintByteCodeErrorSector(const std::size_t idx, const Stream& appCode, const ValidationResultCode code)
	{
		const bool isInstructionFault
		{
			code == ValidationResultCode::NotEnoughArgumentsForInstruction
			|| code == ValidationResultCode::TooManyArgumentsForInstruction
			|| code == ValidationResultCode::ArgumentTypeMismatch
		};

		for (std::size_t i {idx}; i < idx + 8 && i < appCode.Size(); ++i)
		{
			if (appCode[i].Contains<Instruction>())
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
	/// 
	/// </summary>
	/// <param name="result"></param>
	/// <param name="appCode"></param>
	/// <returns></returns>
	[[noreturn]]
	static auto TriggerByteCodeStreamValidationPanic(const ValidationResult& result, const Stream& appCode)
	{
		const auto& [code, idx] = result;

		// Print sample:
		PrintByteCodeErrorSector(idx + 1, appCode, code);

		// Print error message:
		PANIC
		(
			"Byte code validation of stream failed!\n"
			"Index: {:#X}, Instruction: \"{}\", Message: {}",
			idx + 1,
			appCode[idx + 1].Unwrap<Instruction>().value_or(Instruction::NOp),
			code
		);
	}

	/// <summary>
	/// Contains all the runtime variables required for the runtime system.
	/// </summary>
	/// <param name="descriptor"></param>
	/// <returns></returns>
	struct Environment::Context final
	{
		const std::size_t                                        ReactorCount;
		const std::size_t                                        SystemPoolSize;
		std::unique_ptr<U8[]>                                    SystemPool;
		std::pmr::monotonic_buffer_resource                      MonotonicResource;
		std::pmr::vector<std::pmr::string>                       Arguments;
		std::pmr::string                                         AppName;
		std::pmr::vector<std::chrono::duration<F64, std::micro>> ExecutionTimeHistory;
		std::chrono::high_resolution_clock::time_point           BootStamp;
		std::chrono::milliseconds                                BootTime;
		Snapshot                                                 SysInfoSnapshot;
		CpuFeatureDetector                                       CpuFeatures;
		ReactorRoutineLink                                       OptimalReactorRoutine;
		ReactorPool                                              CorePool;

		explicit Context(const EnvironmentDescriptor& descriptor) noexcept(false);
		Context(const Context&)                     = delete;
		Context(Context&&)                          = delete;
		auto operator =(const Context&) -> Context& = delete;
		auto operator =(Context&&) -> Context&      = delete;
		~Context()                                  = default;
	};

	Environment::Context::Context(const EnvironmentDescriptor& descriptor) noexcept(false) :
		ReactorCount {ReactorPool::SmartQueryReactorCount(descriptor.ReactorCount)},
		SystemPoolSize {ComputePoolSize(descriptor.SystemPoolSize, ReactorCount, descriptor.ReactorDescriptor.StackSize)},
		SystemPool
		{
			[size = SystemPoolSize]() noexcept(false) -> auto*
			{
				Print("Allocating system pool with size: {}MB\n", Bytes2Megabytes(size));
				auto* const mem {new(std::nothrow) U8[size]};
				NOMINAX_PANIC_ASSERT_NOT_NULL(mem, "System pool allocation failed!");
				return mem;
			}()
		},
		MonotonicResource {SystemPool.get(), SystemPoolSize},
		Arguments {&MonotonicResource},
		AppName {&MonotonicResource},
		ExecutionTimeHistory {&MonotonicResource},
		BootStamp {std::chrono::high_resolution_clock::now()},
		BootTime { },
		SysInfoSnapshot {InitSysInfo()},
		CpuFeatures {InitCpuFeatures()},
		OptimalReactorRoutine {descriptor.ForceFallback ? GetFallbackRoutineLink() : GetOptimalReactorRoutine(CpuFeatures)},
		CorePool {MonotonicResource, ReactorCount, descriptor.ReactorDescriptor, OptimalReactorRoutine}
	{
		if (NOMINAX_LIKELY(descriptor.ArgC && descriptor.ArgV))
		{
			// copy arguments:
			this->Arguments.assign(descriptor.ArgV + 1, descriptor.ArgV + descriptor.ArgC);
		}

		// copy app name:
		this->AppName = descriptor.AppName;
	}

	auto Environment::ContextDeleter::operator()(Context* const kernel) const noexcept(true) -> void
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

	auto Environment::OnPreExecutionHook([[maybe_unused]] const AppCodeBundle& appCodeBundle) -> bool
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

	Environment::~Environment()
	{
		Shutdown();
	}

	auto Environment::Boot(const EnvironmentDescriptor& descriptor) noexcept(false) -> void
	{
		if (NOMINAX_UNLIKELY(this->Context_))
		{
			return;
		}

		// Basic setup:
		std::ios_base::sync_with_stdio(!descriptor.FastHostIoSync);
		PrintSystemInfo();
		Print("Booting runtime environment...\nApp: \"{}\"\n", descriptor.AppName);
		const auto tik {std::chrono::high_resolution_clock::now()};

		// Invoke hook:
		DISPATCH_HOOK(OnPreBootHook,);

		// Clamp system pool size:
		Print
		(
			"Monotonic system pool fixed size: {} MB, Fallback: {} MB\n",
			Bytes2Megabytes(descriptor.SystemPoolSize),
			Bytes2Megabytes(FALLBACK_SYSTEM_POOL_SIZE)
		);

		// No, we cannot use std::make_unique because we want it noexcept!
		// ReSharper disable once CppSmartPointerVsMakeFunction
		this->Context_ = std::unique_ptr<Context, ContextDeleter>(new(std::nothrow) Context(descriptor));
		NOMINAX_PANIC_ASSERT_NOT_NULL(this->Context_, "Context allocation failed!");

		// Invoke hook:
		DISPATCH_HOOK(OnPostBootHook,);

		const auto tok {std::chrono::high_resolution_clock::now()};
		const auto ms {std::chrono::duration_cast<std::chrono::milliseconds>(tok - tik)};

		this->Context_->BootTime = ms;

		// Get memory snapshot:
		const std::size_t memSnapshot {Os::QueryProcessMemoryUsed()};
		const F32         memUsagePercent {static_cast<F32>(memSnapshot) * 100.F / static_cast<F32>(this->Context_->SysInfoSnapshot.TotalSystemMemory)};

		// Allocate one byte to get current needle:
		const U8* const      needle {static_cast<U8*>(this->Context_->MonotonicResource.allocate(sizeof(U8), alignof(U8)))};
		const std::ptrdiff_t offset {needle - this->Context_->SystemPool.get()};                                                     // compute allocation offset
		const F32            poolUsagePercent {static_cast<F32>(offset) * 100.F / static_cast<F32>(this->Context_->SystemPoolSize)}; // compute percent usage

		Print
		(
			"Runtime environment online!\n"
			"Boot time: {}\n"
			"Process memory snapshot: {:.02f} % [{} MB / {} MB]\n"
			"Monotonic pool snapshot: {:.02f} % [{} MB / {} MB]\n"
			"\n",
			ms,
			memUsagePercent,
			Bytes2Megabytes(memSnapshot),
			Bytes2Megabytes(this->Context_->SysInfoSnapshot.TotalSystemMemory),
			poolUsagePercent,
			Bytes2Megabytes(offset),
			Bytes2Megabytes(this->Context_->SystemPoolSize)
		);
	}

	auto Environment::Execute(Stream&& appCode) noexcept(false) -> const ReactorOutput&
	{
		VALIDATE_ONLINE_BOOT_STATE();

		AppCodeBundle appCodeBundle { };
		if (const auto result {appCode.Build(appCodeBundle)}; NOMINAX_UNLIKELY(result.first != ValidationResultCode::Ok))
		{
			TriggerByteCodeStreamValidationPanic(result, appCode);
		}

		// Deallocate stream:
		appCode = { };

		// Invoke hook:
		DISPATCH_HOOK(OnPreExecutionHook, appCodeBundle);

		// Info
		Print(LogLevel::Warning, "Executing...\n");
		std::cout.flush();

		// Execute on alpha reactor:
		const auto& result {(*this->Context_->CorePool)(std::move(appCodeBundle))};

		// Add execution time:
		const auto micros {std::chrono::duration_cast<std::chrono::duration<F64, std::micro>>(result.Duration)};
		this->Context_->ExecutionTimeHistory.push_back(micros);

		// Print exec info:
		const auto level {result.ShutdownReason == ReactorShutdownReason::Success ? LogLevel::Success : LogLevel::Error};
		Print(level, "Execution #{} done! Runtime {:.04}\n", this->Context_->ExecutionTimeHistory.size(), std::chrono::duration_cast<std::chrono::duration<F64, std::ratio<1>>>(micros));
		std::cout.flush();

		// Invoke hook:
		DISPATCH_HOOK(OnPostExecutionHook,);
		return result;
	}

	auto Environment::Shutdown() noexcept(false) -> void
	{
		if (NOMINAX_UNLIKELY(!this->Context_))
		{
			return;
		}

		// Invoke hook:
		DISPATCH_HOOK(OnPreShutdownHook,);

		this->Context_.reset();
		this->Context_ = nullptr;

		// Invoke hook:
		DISPATCH_HOOK(OnPostShutdownHook,);
	}

	auto Environment::IsOnline() const noexcept(true) -> bool
	{
		return this->Context_ != nullptr;
	}

	auto Environment::GetKernel() const noexcept(true) -> const void*
	{
		return this->Context_.get();
	}

	auto Environment::GetBootStamp() const noexcept(false) -> std::chrono::high_resolution_clock::time_point
	{
		VALIDATE_ONLINE_BOOT_STATE();
		return this->Context_->BootStamp;
	}

	auto Environment::GetBootTime() const noexcept(false) -> std::chrono::milliseconds
	{
		VALIDATE_ONLINE_BOOT_STATE();
		return this->Context_->BootTime;
	}

	auto Environment::GetInputArguments() const noexcept(false) -> const std::pmr::vector<std::pmr::string>&
	{
		VALIDATE_ONLINE_BOOT_STATE();
		return this->Context_->Arguments;
	}

	auto Environment::GetSystemSnapshot() const noexcept(false) -> const Snapshot&
	{
		VALIDATE_ONLINE_BOOT_STATE();
		return this->Context_->SysInfoSnapshot;
	}

	auto Environment::GetProcessorFeatureSnapshot() const noexcept(false) -> const CpuFeatureDetector&
	{
		VALIDATE_ONLINE_BOOT_STATE();
		return this->Context_->CpuFeatures;
	}

	auto Environment::GetAppName() const noexcept(false) -> const std::pmr::string&
	{
		VALIDATE_ONLINE_BOOT_STATE();
		return this->Context_->AppName;
	}

	auto Environment::GetMonotonicSystemPoolSize() const noexcept(false) -> std::size_t
	{
		VALIDATE_ONLINE_BOOT_STATE();
		return this->Context_->SystemPoolSize;
	}

	auto Environment::GetExecutionCount() const noexcept(false) -> std::size_t
	{
		VALIDATE_ONLINE_BOOT_STATE();
		return this->Context_->ExecutionTimeHistory.size();
	}

	auto Environment::GetExecutionTimeHistory() const noexcept(false) -> const std::pmr::vector<std::chrono::duration<F64, std::micro>>&
	{
		VALIDATE_ONLINE_BOOT_STATE();
		return this->Context_->ExecutionTimeHistory;
	}
}
