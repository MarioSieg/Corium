// File: Core.hpp
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

#include "ByteCode.hpp"
#include "Foundation.hpp"

namespace Nominax::Core
{
	/// <summary>
	/// Represents a version.
	/// </summary>
	struct Version final
	{
		U8 Major { };
		U8 Minor { };
		U8 Build { };
		U8 Revision { };
	};

	/// <summary>
	/// The current nominax runtime version.
	/// </summary>
	constexpr Version SYSTEM_VERSION
	{
		.Major = 0,
		.Minor = 8,
		.Build = 0,
		.Revision = 0,
	};

	inline auto operator <<(std::ostream& out, const Version version) -> std::ostream&
	{
		return out << static_cast<U16>(version.Major) << '.' << static_cast<U16>(version.Minor) <<
			'.' << static_cast<U16>(version.Build) << '.' << static_cast<U16>(version.Revision);
	}

	extern auto PrintSystemInfo() -> void;

	/// <summary>
	/// The type used to store interrupt codes.
	/// </summary>
	using InterruptAccumulator = I32;

	/// <summary>
	/// The function prototype for interrupt handlers.
	/// </summary>
	using InterruptRoutineProxy = auto(InterruptAccumulator) -> void;

	/// <summary>
	/// Interrupt code indicating a fatal reactor error.
	/// </summary>
	constexpr InterruptAccumulator INT_CODE_FATAL_ERROR {std::numeric_limits<InterruptAccumulator>::min()};

	/// <summary>
	/// Iterrupt code indicating success.
	/// </summary>
	constexpr InterruptAccumulator INT_CODE_OK {0};

	/// <summary>
	/// Interrupt code indicating user space exception.
	/// </summary>
	constexpr InterruptAccumulator INT_CODE_EXCEPTIONS {std::numeric_limits<InterruptAccumulator>::max()};

	/// <summary>
	/// Default interrupt routine,
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	extern auto DefaultInterruptRoutine(InterruptAccumulator) -> void;

	/// <summary>
	/// 
	/// </summary>
	/// <returns>A pointer to the default interrupt routine.</returns>
	[[nodiscard]]
	extern auto GetDefaultInterruptRoutine() -> InterruptRoutineProxy*;

	/// <summary>
	/// Contains all results of a reactor validation.
	/// </summary>
	enum class ReactorValidationResult : U8
	{
		Ok = 0,
		NullPtr,
		ZeroSize,
		MissingCodePrologue,
		MissingCodeEpilogue,
		MissingStackPrologue,
		NullIntrinsicRoutine,
		ExecutionAddressMappingError,
	};

	constexpr std::array<std::string_view, 8> REACTOR_VALIDATION_RESULT_ERROR_MESSAGES
	{
		"Ok",
		"Required input parameter is null!",
		"Required input parameter has zero size!",
		"Missing code prologue!",
		"Missing code epilogue!",
		"Missing stack prologue padding!",
		"User intrinsic routine table contains an entry which is null!",
		"Execution address mapping error!"
	};

	/// <summary>
	/// Contains all input data for the VM reactor.
	/// </summary>
	struct VerboseReactorDescriptor final
	{
		/// <summary>
		/// Code chunk data pointer.
		/// </summary>
		const ByteCode::Signal* CodeChunk {nullptr};

		/// <summary>
		/// Code chunk and instruction map length.
		/// </summary>
		U64 CodeChunkSize {0};

		/// <summary>
		/// Intrinsic routine registry data pointer.
		/// </summary>
		ByteCode::IntrinsicRoutine* const* IntrinsicTable {nullptr};

		/// <summary>
		/// Intrinsic routine registry length.
		/// </summary>
		U64 IntrinsicTableSize {0};

		/// <summary>
		/// Interrupt routine proxy.
		/// </summary>
		InterruptRoutineProxy* InterruptHandler {nullptr};

		/// <summary>
		/// Stack data pointer.
		/// </summary>
		Foundation::Record* Stack {nullptr};

		/// <summary>
		/// Stack length.
		/// </summary>
		U64 StackSize {0};

		/// <summary>
		/// Checks if the current descriptor is valid for
		/// reactor execution or creation.
		/// </summary>
		/// <returns>Validation result.</returns>
		[[nodiscard]]
		auto Validate() const -> ReactorValidationResult;
	};

	/// <summary>
	/// A simpler version of the "ReactorInput" struct.
	/// If you prefer simpler reactor configuration, use this struct.
	/// </summary>
	struct BasicReactorDescriptor final
	{
		/// <summary>
		/// Code image view.
		/// </summary>
		std::span<const ByteCode::Signal> CodeChunk;

		/// <summary>
		/// Intrinsic routine view.
		/// </summary>
		std::span<ByteCode::IntrinsicRoutine*> IntrinsicTable;

		/// <summary>
		/// Stack view.
		/// </summary>
		std::span<Foundation::Record> Stack;

		/// <summary>
		/// Interrupt routine proxy.
		/// </summary>
		InterruptRoutineProxy& InterruptHandler;

		/// <summary>
		/// Will build a detailed descriptor out of this instance and return it.
		/// </summary>
		/// <returns>The detailed descriptor, created from this instance.</returns>
		[[nodiscard]]
		auto BuildDetailed() const -> VerboseReactorDescriptor;

		/// <summary>
		/// Will build a detailed descriptor out of this instance and validate it.
		/// Because this must create a new detailed descriptor and drop if after validation,
		/// better use BuildDetailed() if you need the detailed instance afterwards.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto Validate() const -> ReactorValidationResult;
	};

	/// <summary>
	/// Represents a stack buffer with fixed size.
	/// Uses as a thread local reactor stack.
	/// </summary>
	class [[nodiscard]] FixedStack final
	{
	public:
		/// <summary>
		/// Storage type for the reactor stack.
		/// </summary>
		using StorageType = std::pmr::vector<Foundation::Record>;

	private:
		/// <summary>
		/// Internal buffer.
		/// </summary>
		StorageType Buffer_;

	public:
		/// <summary>
		/// Small 1 MB stack.
		/// Contains the size in records, not bytes.
		/// </summary>
		static constexpr U64 SIZE_SMALL {1_mB / sizeof(Foundation::Record)};

		/// <summary>
		/// Medium sizes 4 MB stack.
		/// Contains the size in records, not bytes.
		/// </summary>
		static constexpr U64 SIZE_MEDIUM {4_mB / sizeof(Foundation::Record)};

		/// <summary>
		/// Medium sizes 8 MB stack.
		/// Contains the size in records, not bytes.
		/// </summary>
		static constexpr U64 SIZE_LARGE {8_mB / sizeof(Foundation::Record)};
		/// <summary>
		/// 
		/// </summary>
		/// <returns>The memory buffer pointer.</returns>
		[[nodiscard]]
		auto Buffer() -> Foundation::Record*;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The memory buffer pointer.</returns>
		[[nodiscard]]
		auto Buffer() const -> const Foundation::Record*;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the memory buffer in records.</returns>
		[[nodiscard]]
		auto Size() const -> U64;

		/// <summary>
		/// STL Compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto begin() -> StorageType::iterator;

		/// <summary>
		/// STL Compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto begin() const -> StorageType::const_iterator;

		/// <summary>
		/// STL Compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto end() -> StorageType::iterator;

		/// <summary>
		/// STL Compat
		/// </summary>
		/// <returns></returns>
		// ReSharper disable once CppInconsistentNaming
		[[nodiscard]]
		auto end() const -> StorageType::const_iterator;

		/// <summary>
		/// Construct with size in records.
		/// If the size is zero, fatal termination.
		/// It will set the first element to padding, so it allocates one more than specified.
		/// </summary>
		/// <param name="allocator"></param>
		/// <param name="sizeInRecords">Size in records. If the size is zero, fatal termination.</param>
		/// <returns></returns>
		explicit FixedStack(std::pmr::memory_resource& allocator, U64 sizeInRecords);

		/// <summary>
		/// No copy.
		/// </summary>
		FixedStack(const FixedStack&) = delete;

		/// <summary>
		/// Move allowed.
		/// </summary>
		/// <returns></returns>
		FixedStack(FixedStack&& value) = default;

		/// <summary>
		/// No copy.
		/// </summary>
		/// <returns></returns>
		auto operator =(const FixedStack&) -> FixedStack& = delete;

		/// <summary>
		/// Move allowed.
		/// </summary>
		/// <returns></returns>
		auto operator =(FixedStack&& value) -> FixedStack& = default;

		/// <summary>
		/// Deallocate stack.
		/// </summary>
		~FixedStack() = default;
	};

	inline auto FixedStack::Buffer() -> Foundation::Record*
	{
		return this->Buffer_.data();
	}

	inline auto FixedStack::Buffer() const -> const Foundation::Record*
	{
		return this->Buffer_.data();
	}

	inline auto FixedStack::Size() const -> U64
	{
		return this->Buffer_.size();
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto FixedStack::begin() -> StorageType::iterator
	{
		return std::begin(this->Buffer_);
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto FixedStack::begin() const -> StorageType::const_iterator
	{
		return std::begin(this->Buffer_);
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto FixedStack::end() -> StorageType::iterator
	{
		return std::end(this->Buffer_);
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto FixedStack::end() const -> StorageType::const_iterator
	{
		return std::end(this->Buffer_);
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto begin(FixedStack& self) -> FixedStack::StorageType::iterator
	{
		return self.begin();
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto begin(const FixedStack& self) -> FixedStack::StorageType::const_iterator
	{
		return self.begin();
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto end(FixedStack& self) -> FixedStack::StorageType::iterator
	{
		return self.end();
	}

	// ReSharper disable once CppInconsistentNaming
	inline auto end(const FixedStack& self) -> FixedStack::StorageType::const_iterator
	{
		return self.end();
	}

	/// <summary>
	/// Power preference for a VM reactor.
	/// </summary>
	enum class PowerPreference
	{
		/// <summary>
		/// Prefer faster performance but more power usage (desktop, server)
		/// </summary>
		HighPerformance,

		/// <summary>
		/// Prefer low power usage but slower performance (mobile, tablet, laptop)
		/// </summary>
		LowPowerUsage
	};

	/// <summary>
	/// Contains information to create a reactor.
	/// </summary>
	struct ReactorSpawnDescriptor final
	{
		/// <summary>
		/// The stack size in records.
		/// </summary>
		U64 StackSize {FixedStack::SIZE_LARGE};

		/// <summary>
		/// The intrinsic routines.
		/// </summary>
		ByteCode::UserIntrinsicRoutineRegistry SharedIntrinsicTable { };

		/// <summary>
		/// Interrupt handler.
		/// </summary>
		InterruptRoutineProxy* InterruptHandler { };

		/// <summary>
		/// Reactor power preference.
		/// </summary>
		PowerPreference PowerPref {PowerPreference::HighPerformance};

		/// <summary>
		/// Get platform dependent default configuration.
		/// </summary>
		/// <returns></returns>
		static constexpr auto Default(U64 stackSize = FixedStack::SIZE_LARGE) -> ReactorSpawnDescriptor;
	};

	/// <summary>
	/// Get platform specific best fitting power preference.
	/// </summary>
	/// <returns>The power preference most matching the current platform.</returns>
	constexpr auto GetPlatformPowerPreference() -> PowerPreference
	{
		// ARM-64 is a low power device (probably mobile) so we enable power
		// safe mode by default:
		#if NOX_ARCH_ARM_64
			return PowerPreference::LowPowerUsage;
		#else
		return PowerPreference::HighPerformance;
		#endif
	}

	/// <summary>
	/// Construct default reactor spawn descriptor.
	/// </summary>
	/// <param name="stackSize"></param>
	/// <returns></returns>
	constexpr auto ReactorSpawnDescriptor::Default(const U64 stackSize) -> ReactorSpawnDescriptor
	{
		return ReactorSpawnDescriptor
		{
			.StackSize = stackSize,
			.SharedIntrinsicTable = { },
			.InterruptHandler = nullptr,
			.PowerPref = GetPlatformPowerPreference()
		};
	}

	/// <summary>
	/// Config descriptor for an environment.
	/// </summary>
	struct EnvironmentDescriptor final
	{
		/// <summary>
		/// Argument count.
		/// </summary>
		I32 ArgC {0};

		/// <summary>
		/// Argument vector.
		/// </summary>
		const char* const* ArgV {nullptr};

		/// <summary>
		/// The name of the app.
		/// </summary>
		std::string_view AppName {"Untitled App"};

		/// <summary>
		/// If true, the fallback reactor implementation
		/// will be used for all reactors, not the
		/// runtime selected one (based on CPU features).
		/// </summary>
		bool ForceFallback {false};

		/// <summary>
		/// If true, synchronization between
		/// C++ io-streams (cout, err, cin) and C io-streams (stdout, stdin)
		/// is deactivated, which makes printing faster.
		/// This should be activated in most cases when executing code.
		/// </summary>
		bool FastHostIoSync {true};

		/// <summary>
		/// The size of the boot pool
		/// </summary>
		U64 BootPoolSize {128_kB};

		/// <summary>
		/// The size of the system memory pool size.
		/// </summary>
		U64 SystemPoolSize {512_kB};

		/// <summary>
		/// The count of reactors.
		/// If 0, the system will use the number of CPU threads.
		/// </summary>
		U64 ReactorCount {0};

		/// <summary>
		/// The reactor stack size in bytes.
		/// Must be divisible by 8!
		/// </summary>
		U64 StackSize {8_mB};

		/// <summary>
		/// Power preference of the system.
		/// </summary>
		PowerPreference PowerPref {PowerPreference::HighPerformance};
	};

	/// <summary>
	/// Result type from a reactor shutdown.
	/// </summary>
	enum class ReactorShutdownReason : U8
	{
		/// <summary>
		/// Terminated normally.
		/// </summary>
		Success = 0,

		/// <summary>
		/// Internal reactor error.
		/// </summary>
		Error,

		/// <summary>
		/// User space exception.
		/// </summary>
		UserException
	};

	/// <summary>
	/// Map interrupt accumulator to shutdown reason.
	/// </summary>
	/// <param name="x"></param>
	/// <returns></returns>
	[[nodiscard]]
	constexpr auto MapIntAccum2ShutdownReason(const InterruptAccumulator x) -> ReactorShutdownReason
	{
		return x == INT_CODE_OK ? ReactorShutdownReason::Success : x < INT_CODE_OK ? ReactorShutdownReason::Error : ReactorShutdownReason::UserException;
	}

	extern auto PrintShutdownReason(ReactorShutdownReason reason, InterruptAccumulator code = std::numeric_limits<InterruptAccumulator>::min()) -> void;

	/// <summary>
	/// Contains all the output data from the VM reactor.
	/// </summary>
	struct ReactorState final
	{
		/// <summary>
		/// The input descriptor (if any).
		/// </summary>
		const VerboseReactorDescriptor* Input {nullptr};

		/// <summary>
		/// The shutdown reason.
		/// </summary>
		ReactorShutdownReason ShutdownReason {ReactorShutdownReason::Success};

		/// <summary>
		/// Pre execution time stamp.
		/// </summary>
		std::chrono::high_resolution_clock::time_point Pre { };

		/// <summary>
		/// Post execution time stamp.
		/// </summary>
		std::chrono::high_resolution_clock::time_point Post { };

		/// <summary>
		/// Duration diff between pre and post execution time stamp.
		/// </summary>
		std::chrono::high_resolution_clock::duration Duration { };

		/// <summary>
		/// Interrupt accumulator code.
		/// </summary>
		InterruptAccumulator InterruptCode { };

		/// <summary>
		/// Instruction pointer diff.
		/// </summary>
		std::ptrdiff_t IpDiff { };

		/// <summary>
		/// Stack pointer diff.
		/// </summary>
		std::ptrdiff_t SpDiff { };

		/// <summary>
		/// Base pointer diff.
		/// </summary>
		std::ptrdiff_t BpDiff { };

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The return code (interrupt code casted). Zero if success.</returns>
		[[nodiscard]]
		constexpr auto ReturnCode() const -> I32;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The result of the program evaluation (the first stack record, if any).</returns>
		[[nodiscard]]
		constexpr auto EvaluationResult() const -> Foundation::Record;
	};

	constexpr auto ReactorState::ReturnCode() const -> I32
	{
		return this->InterruptCode;
	}

	constexpr auto ReactorState::EvaluationResult() const -> Foundation::Record
	{
		return this->Input->Stack[1];
	}

	/// <summary>
	/// Results from a VM execution.
	/// </summary>
	using ExecutionResult = std::pair<ReactorShutdownReason, const ReactorState&>;

	/// <summary>
	/// Represents the whole runtime environment.
	/// </summary>
	class [[nodiscard]] Environment
	{
		/// <summary>
		/// Pimpl.
		/// </summary>
		struct Context;

		/// <summary>
		/// Context deallocator.
		/// </summary>
		struct ContextDeleter final
		{
			auto operator()(Context* kernel) const -> void;
		};

		/// <summary>
		/// Pimpl ptr.
		/// </summary>
		std::unique_ptr<Context, ContextDeleter> Context_ {nullptr};

	protected:
		/// <summary>
		/// This hook is executed before the environment boots.
		/// </summary>
		/// <returns>True on success, panic on false.</returns>
		[[nodiscard]]
		virtual auto OnPreBootHook() -> bool;

		/// <summary>
		/// This hook is executed after the environment boots.
		/// </summary>
		/// <returns>True on success, panic on false.</returns>
		[[nodiscard]]
		virtual auto OnPostBootHook() -> bool;

		/// <summary>
		/// This hook is executed before any code execution.
		/// </summary>
		/// <returns>True on success, panic on false.</returns>
		[[nodiscard]]
		virtual auto OnPreExecutionHook(const ByteCode::Image& appCodeBundle) -> bool;

		/// <summary>
		/// This hook is executed after any code execution.
		/// </summary>
		/// <returns>True on success, panic on false.</returns>
		[[nodiscard]]
		virtual auto OnPostExecutionHook() -> bool;

		/// <summary>
		/// This hook is executed before the environment shuts down.
		/// </summary>
		/// <returns>True on success, panic on false.</returns>
		[[nodiscard]]
		virtual auto OnPreShutdownHook() -> bool;

		/// <summary>
		/// This hook is executed after the environment shuts down.
		/// </summary>
		/// <returns>True on success, panic on false.</returns>
		[[nodiscard]]
		virtual auto OnPostShutdownHook() -> bool;

	public:
		/// <summary>
		/// Size in bytes of the system pool, if the given count was invalid.
		/// </summary>
		static constexpr U64 FALLBACK_SYSTEM_POOL_SIZE {256_kB};
		static_assert(FALLBACK_SYSTEM_POOL_SIZE);

		/// <summary>
		/// The min size of the boot pool.
		/// </summary>
		static constexpr U64 BOOT_POOL_SIZE_MIN {32_kB};
		static_assert(BOOT_POOL_SIZE_MIN);

		/// <summary>
		/// The max size of the boot pool.
		/// </summary>
		static constexpr U64 BOOT_POOL_SIZE_MAX {256_kB};
		static_assert(BOOT_POOL_SIZE_MAX);

		/// <summary>
		/// Default constructor. Does not initialize the environment.
		/// </summary>
		explicit Environment(const Foundation::IAllocator* allocator = nullptr);

		/// <summary>
		/// No copy.
		/// </summary>
		/// <param name="other"></param>
		Environment(const Environment& other) = delete;

		/// <summary>
		/// No move.
		/// </summary>
		/// <param name="other"></param>
		Environment(Environment&& other) = delete;

		/// <summary>
		/// No copy.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const Environment& other) -> Environment& = delete;

		/// <summary>
		/// No move.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(Environment&& other) -> Environment& = delete;

		/// <summary>
		/// Destructor.
		/// If Shutdown() has not been called before
		/// the destructor, the destructor will call it.
		/// </summary>
		virtual ~Environment();

		/// <summary>
		/// Boot up runtime environment.
		/// Will panic if fatal errors are encountered.
		/// </summary>
		/// <returns></returns>
		auto Boot(const EnvironmentDescriptor& descriptor) -> void;

		/// <summary>
		/// Execute stream on alpha reactor.
		/// </summary>
		/// <param name="image"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto Execute(const ByteCode::Image& image) -> ExecutionResult;

		/// <summary>
		/// Execute stream on alpha reactor.
		/// </summary>
		/// <param name="stream"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto Execute(ByteCode::Stream&& stream) -> ExecutionResult;

		/// <summary>
		/// Execute stream on alpha reactor.
		/// </summary>
		/// <param name="stream"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto Execute(const ByteCode::Stream& stream) -> ExecutionResult;

		/// <summary>
		/// Execute stream on alpha reactor.
		/// </summary>
		/// <param name="image"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto operator()(ByteCode::Image& image) -> ExecutionResult;

		/// <summary>
		/// Execute stream on alpha reactor.
		/// </summary>
		/// <param name="stream"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto operator()(ByteCode::Stream&& stream) -> ExecutionResult;

		/// <summary>
		/// Execute stream on alpha reactor.
		/// </summary>
		/// <param name="stream"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto operator()(const ByteCode::Stream& stream) -> ExecutionResult;

		/// <summary>
		/// Shutdown runtime environment.
		/// Will panic if fatal errors are encountered.
		/// </summary>
		/// <returns></returns>
		auto Shutdown() -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the system is booted and online!</returns>
		[[nodiscard]]
		auto IsOnline() const -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The raw kernel pointer. Only useful for internal interop.-</returns>
		[[nodiscard]]
		auto GetKernel() const -> const void*;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot time stamp.</returns>
		[[nodiscard]]
		auto GetBootStamp() const -> std::chrono::high_resolution_clock::time_point;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The boot time in milliseconds.</returns>
		[[nodiscard]]
		auto GetBootTime() const -> std::chrono::milliseconds;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The system stat snapshot.</returns>
		[[nodiscard]]
		auto GetSystemSnapshot() const -> const Foundation::Snapshot&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The cpu feature detector.</returns>
		[[nodiscard]]
		auto GetProcessorFeatureSnapshot() const -> const Foundation::CpuFeatureDetector&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The app name for which the environment is hosted for.</returns>
		[[nodiscard]]
		auto GetAppName() const -> const std::pmr::string&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the system pool in bytes.</returns>
		[[nodiscard]]
		auto GetMonotonicSystemPoolSize() const -> U64;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The count of reactor executions so far.</returns>
		[[nodiscard]]
		auto GetExecutionCount() const -> U64;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The history of execution times.</returns>
		[[nodiscard]]
		auto GetExecutionTimeHistory() const -> const std::pmr::vector<std::chrono::duration<F64, std::micro>>&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The local optimization info for the current machine.</returns>
		[[nodiscard]]
		auto GetOptimizationHints() const -> ByteCode::OptimizationHints;
	};

	inline auto Environment::operator()(ByteCode::Image& image) -> ExecutionResult
	{
		return this->Execute(image);
	}

	inline auto Environment::operator()(ByteCode::Stream&& stream) -> ExecutionResult
	{
		return this->Execute(std::move(stream));
	}

	inline auto Environment::operator()(const ByteCode::Stream& stream) -> ExecutionResult
	{
		return this->Execute(stream);
	}

	/// <summary>
	/// Checks if all pointers inside the jump table are non null.
	/// Use it with static_assert because it is consteval :)
	/// </summary>
	/// <param name="jumpTable">The jump table to check.</param>
	/// <param name="jumpTableSize">The amount of jump table entries.</param>
	/// <returns>true if all entries are valid, else false.</returns>
	consteval auto ValidateJumpTable
	(
		const void* NOX_RESTRICT const* NOX_RESTRICT const jumpTable,
		const U64                                          jumpTableSize
	) -> bool
	{
		if (!jumpTable || !jumpTableSize)
		{
			return false;
		}

		for (const auto* current{ jumpTable }, * const end{ jumpTable + jumpTableSize }; current < end; ++current)
		{
			if (!*current)
			{
				return false;
			}
		}

		return true;
	}

	/// <summary>
	/// Contains all sub implementations for the reactor core.
	/// </summary>
	enum class ReactorCoreSpecialization : U64
	{
		/// <summary>
		/// Fast fallback implementation - available on all platforms.
		/// </summary>
		Fallback,

		/// <summary>
		/// Slow debug implementation - available on all platforms.
		/// </summary>
		Debug,

		/// <summary>
		/// AMD 64 optimized implementation for advanced vector extensions -> 256-bit (YMM* registers) -> VEX
		/// </summary>
		Amd64_Avx,

		/// <summary>
		/// AMD 64 optimized implementation for advanced vector extensions 512 -> 512-bit (ZMM* registers, K* mask registers) -> EVEX
		/// </summary>
		Amd64_Avx512F,

		Count
	};

	/// <summary>
	/// Get string representations of a specialization target.
	/// </summary>
	/// <param name="target"></param>
	/// <returns></returns>
	constexpr auto GetReactorCoreSpecializationName(const ReactorCoreSpecialization target) -> std::string_view
	{
		switch (target)
		{
			case ReactorCoreSpecialization::Fallback:
				return "Fallback";

			case ReactorCoreSpecialization::Debug:
				return "Debug";

			case ReactorCoreSpecialization::Amd64_Avx:
				return "X86-64 AVX";

			case ReactorCoreSpecialization::Amd64_Avx512F:
				return "X86-64 AVX512F";

				[[unlikely]]
			default:
				return { };
		}
	}

	/// <summary>
	/// Signature of the reactor core execution routine.
	/// </summary>
	using ReactorCoreExecutionRoutine = auto(const VerboseReactorDescriptor* descriptor, ReactorState* outputState, const void**** jumpTableQuery) -> ReactorShutdownReason;

	/// <summary>
	/// Contains the reactor routine and additional information.
	/// </summary>
	struct ReactorRoutineLink
	{
		/// <summary>
		/// Specialization type.
		/// </summary>
		const ReactorCoreSpecialization Specialization;

		/// <summary>
		/// Execution routine link.
		/// </summary>
		ReactorCoreExecutionRoutine* const ExecutionRoutine;

		/// <summary>
		/// Jump table link.
		/// </summary>
		const void** const JumpTable;

		/// <summary>
		/// Construct and validate parameters.
		/// Panics if any parameter is null.
		/// </summary>
		/// <param name="specialization"></param>
		/// <param name="executionRoutine"></param>
		/// <param name="jumpTable"></param>
		ReactorRoutineLink
		(
			ReactorCoreSpecialization    specialization,
			ReactorCoreExecutionRoutine* executionRoutine,
			const void**                 jumpTable
		);
	};

	/// <summary>
	/// Contains all available reactor implementations for the current platform.
	/// </summary>
	using ReactorRegistry = std::array<ReactorCoreExecutionRoutine*, static_cast<U64>(ReactorCoreSpecialization::Count)>;

	/// <summary>
	/// The reactor hyper visor manages the correct selection
	/// of reactor execution routines for the current runtime.
	/// </summary>
	class HyperVisor final
	{
	public:
		/// <summary>
		/// static class
		/// </summary>
		HyperVisor() = delete;

		/// <summary>
		/// static class
		/// </summary>
		/// <param name="other"></param>
		HyperVisor(const HyperVisor& other) = delete;

		/// <summary>
		/// static class
		/// </summary>
		/// <param name="other"></param>
		HyperVisor(HyperVisor&& other) = delete;

		/// <summary>
		/// static class
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const HyperVisor& other) -> HyperVisor& = delete;

		/// <summary>
		/// static class
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(HyperVisor&& other) -> HyperVisor& = delete;

		/// <summary>
		/// static class
		/// </summary>
		~HyperVisor() = delete;

		/// <summary>
		/// Returns the fallback reactor routine with no platform specific optimizations.
		/// This is always available, independent of any platform.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static auto GetFallbackRoutineLink() -> ReactorRoutineLink;

		/// <summary>
		/// Returns the reactor used for debugging.
		/// This is always available, independent of any platform.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static auto GetDebugRoutineLink() -> ReactorRoutineLink;

		/// <summary>
		/// Returns the reactor specialization based on the cpu features available.
		/// </summary>
		/// <param name="cpuFeatureDetector"></param>
		/// <returns></returns>
		[[nodiscard]]
		static auto SmartSelectReactor(const Foundation::CpuFeatureDetector& cpuFeatureDetector) -> ReactorCoreSpecialization;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current reactor registry.</returns>
		[[nodiscard]]
		static auto GetReactorRegistry() -> const ReactorRegistry&;

		/// <summary>
		/// Returns the reactor routine of the corresponding target.
		/// </summary>
		/// <param name="target"></param>
		/// <returns></returns>
		[[nodiscard]]
		static auto GetReactorRoutineFromRegistryByTarget(ReactorCoreSpecialization target) -> ReactorCoreExecutionRoutine*;

		/// <summary>
		/// Selects the best reactor routine matching the cpu features and saves it.
		/// </summary>
		/// <param name="features"></param>
		/// <returns></returns>
		[[nodiscard]]
		static auto GetOptimalReactorRoutine(const Foundation::CpuFeatureDetector& features) -> ReactorRoutineLink;
	};

	/// <summary>
	/// Helpers to quickly execute a reactor with specified cpu features.
	/// Good for testing and debugging.
	/// </summary>
	/// <param name="target"></param>
	/// <param name="input"></param>
	/// <param name="output"></param>
	/// <param name="outJumpTable"></param>
	/// <returns></returns>
	[[nodiscard]]
	extern auto SingletonExecutionProxy
	(
		const VerboseReactorDescriptor&       input,
		ReactorState&                         output,
		const Foundation::CpuFeatureDetector& target,
		const void****                        outJumpTable = nullptr
	) -> ReactorShutdownReason;

	/// <summary>
	/// Queries the jump table from the specified reactor routine.
	/// </summary>
	/// <param name="routine"></param>
	/// <returns></returns>
	extern auto QueryJumpTable(ReactorCoreExecutionRoutine& routine) -> const void**;

	/// <summary>
	/// Represents a reactor.
	/// </summary>
	class [[nodiscard]] Reactor final
	{
		/// <summary>
		/// Unique reactor id.
		/// </summary>
		std::uint32_t Id_;

		/// <summary>
		/// The reactor pool index of this reactor.
		/// </summary>
		U64 PoolIndex_;

		/// <summary>
		/// Time stamp when the reactor was spawned.
		/// </summary>
		std::chrono::high_resolution_clock::time_point SpawnStamp_;

		/// <summary>
		/// Reactor power preference.
		/// </summary>
		PowerPreference PowerPreference_;

		/// <summary>
		/// The reactor input descriptor build
		/// when Execute() is called.
		/// </summary>
		VerboseReactorDescriptor Input_;

		/// <summary>
		/// The reactor output from previous executions.
		/// </summary>
		ReactorState Output_;

		/// <summary>
		/// The thread local fixed reactor stack (TLFRS)
		/// </summary>
		FixedStack Stack_;

		/// <summary>
		/// The table of custom intrinsic routines.
		/// </summary>
		ByteCode::UserIntrinsicRoutineRegistry IntrinsicTable_;

		/// <summary>
		/// The interrupt routine using for reactor interrupts.
		/// </summary>
		InterruptRoutineProxy* InterruptHandler_;

		/// <summary>
		/// Contains the reactor routine.
		/// </summary>
		ReactorRoutineLink RoutineLink_;

	public:
		/// <summary>
		/// Create reactor with fixed stack size. If zero, panic!
		/// </summary>
		explicit Reactor
		(
			std::pmr::memory_resource&               allocator,
			const ReactorSpawnDescriptor&            descriptor,
			const std::optional<ReactorRoutineLink>& routineLink = std::nullopt,
			U64                                      poolIdx     = 0
		);

		/// <summary>
		/// No copy!
		/// </summary>
		Reactor(const Reactor&) = delete;

		/// <summary>
		/// Move constructing okay.
		/// </summary>
		Reactor(Reactor&&) = default;

		/// <summary>
		/// No copy!
		/// </summary>
		auto operator =(const Reactor&) -> Reactor& = delete;

		/// <summary>
		/// no move!
		/// </summary>
		auto operator =(Reactor&&) -> Reactor& = delete;

		/// <summary>
		/// Destructs all reactor related resources, such as stack etc..
		/// </summary>
		~Reactor() = default;

		/// <summary>
		/// Execute reactor with specified application code bundle.
		/// </summary>
		/// <param name="bundle"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto Execute(const ByteCode::Image& bundle) -> std::pair<ReactorShutdownReason, const ReactorState&>;

		/// <summary>
		/// Execute reactor with specified application code bundle.
		/// </summary>
		/// <param name="bundle"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto operator ()(const ByteCode::Image& bundle) -> std::pair<ReactorShutdownReason, const ReactorState&>;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The unique reactor id.</returns>
		[[nodiscard]]
		auto GetId() const -> std::uint32_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The index of this rector in the hosting reactor pool</returns>
		[[nodiscard]]
		auto GetPoolIndex() const -> U64;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The time stamp when the reactor was spawned.</returns>
		[[nodiscard]]
		auto GetSpawnStamp() const -> std::chrono::high_resolution_clock::time_point;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The power preference of this reactor.</returns>
		[[nodiscard]]
		auto GetPowerPreference() const -> PowerPreference;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current descriptor of the reactor.</returns>
		[[nodiscard]]
		auto GetInputDescriptor() const -> const VerboseReactorDescriptor&;

		/// <summary>
		/// Returns the reactor output of any previous
		/// execution or the default value.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto GetOutput() const -> const ReactorState&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current stack.</returns>
		[[nodiscard]]
		auto GetStack() const -> const FixedStack&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto GetIntrinsicTable() const -> const ByteCode::UserIntrinsicRoutineRegistry&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto GetInterruptHandler() const -> InterruptRoutineProxy*;
	};

	inline auto Reactor::GetId() const -> std::uint32_t
	{
		return this->Id_;
	}

	inline auto Reactor::GetPoolIndex() const -> U64
	{
		return this->PoolIndex_;
	}

	inline auto Reactor::GetSpawnStamp() const -> std::chrono::high_resolution_clock::time_point
	{
		return this->SpawnStamp_;
	}

	inline auto Reactor::GetPowerPreference() const -> PowerPreference
	{
		return this->PowerPreference_;
	}

	inline auto Reactor::GetStack() const -> const FixedStack&
	{
		return this->Stack_;
	}

	inline auto Reactor::GetIntrinsicTable() const -> const ByteCode::UserIntrinsicRoutineRegistry&
	{
		return this->IntrinsicTable_;
	}

	inline auto Reactor::GetInterruptHandler() const -> InterruptRoutineProxy*
	{
		return this->InterruptHandler_;
	}

	inline auto Reactor::GetInputDescriptor() const -> const VerboseReactorDescriptor&
	{
		return this->Input_;
	}

	inline auto Reactor::GetOutput() const -> const ReactorState&
	{
		return this->Output_;
	}

	inline auto Reactor::operator()(const ByteCode::Image& bundle) -> std::pair<ReactorShutdownReason, const ReactorState&>
	{
		return this->Execute(bundle);
	}

	/// <summary>
	/// Proxy function to perform a single reactor
	/// execution with provided descriptors.
	/// </summary>
	/// <param name="input">The reactor input descriptor.</param>
	/// <param name="target">The cpu target.</param>
	/// <returns></returns>
	extern auto SingletonExecutionProxy
	(
		const VerboseReactorDescriptor& input, const Foundation::CpuFeatureDetector& target = { },
		const void****                  outJumpTable                                        = nullptr
	) -> std::pair<ReactorShutdownReason, ReactorState>;

	/// <summary>
	/// A pool holding all existing reactors.
	/// </summary>
	class [[nodiscard]] ReactorPool final
	{
		std::pmr::vector<Reactor> Pool_ { };
		ReactorSpawnDescriptor    ReactorConfig_ { };

	public:
		/// <summary>
		/// Calculates the best and correct reactor count.
		/// </summary>
		/// <param name="desired">How many reactors the user requested. If zero, logical cpu count will be used.</param>
		/// <returns>The best reactor count for the current system.</returns>
		static auto SmartQueryReactorCount(U64 desired = 0) -> U64;

		/// <summary>
		/// Minimal one reactor is required.
		/// </summary>
		static constexpr U64 MIN_REACTOR_COUNT {1};

		/// <summary>
		/// Fallback reactor count.
		/// </summary>
		static constexpr U64 FALLBACK_REACTOR_COUNT {MIN_REACTOR_COUNT};

		/// <summary>
		/// Construct and initialize all new reactors.
		/// If the reactor count is zero, panic!
		/// </summary>
		ReactorPool
		(
			std::pmr::memory_resource&               resource,
			U64                                      reactorCount,
			const ReactorSpawnDescriptor&            config,
			const std::optional<ReactorRoutineLink>& routineLink = std::nullopt
		);

		/// <summary>
		/// No copy.
		/// </summary>
		ReactorPool(const ReactorPool&) = delete;

		/// <summary>
		/// No move.
		/// </summary>
		ReactorPool(ReactorPool&&) = delete;

		/// <summary>
		/// No copy.
		/// </summary>
		auto operator =(const ReactorPool&) -> ReactorPool& = delete;

		/// <summary>
		/// No move.
		/// </summary>
		auto operator =(ReactorPool&&) -> ReactorPool& = delete;

		/// <summary>
		/// Destructor.
		/// </summary>
		~ReactorPool();

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Returns the pool pointer.</returns>
		[[nodiscard]]
		auto GetBuffer() const -> const Reactor*;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Returns the size of the pool.</returns>
		[[nodiscard]]
		auto GetSize() const -> U64;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>Returns the config used to create each reactor.</returns>
		[[nodiscard]]
		auto GetSpawnConfig() const -> const ReactorSpawnDescriptor&;

		/// <summary>
		/// Returns the reactor at index.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto GetReactor(U64 idx) const -> const Reactor&;


		/// <summary>
		/// Returns the reactor at index.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto operator [](U64 idx) const -> const Reactor&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The first reactor in the pool running on the main thread.</returns>
		[[nodiscard]]
		auto GetAlphaReactor() -> Reactor&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The first reactor in the pool running on the main thread.</returns>
		[[nodiscard]]
		auto operator *() -> Reactor&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The first reactor in the pool running on the main thread.</returns>
		[[nodiscard]]
		auto GetAlphaReactor() const -> const Reactor&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The first reactor in the pool running on the main thread.</returns>
		[[nodiscard]]
		auto operator *() const -> const Reactor&;
	};

	inline auto ReactorPool::GetBuffer() const -> const Reactor*
	{
		return this->Pool_.data();
	}

	inline auto ReactorPool::GetSize() const -> U64
	{
		return this->Pool_.size();
	}

	inline auto ReactorPool::GetSpawnConfig() const -> const ReactorSpawnDescriptor&
	{
		return this->ReactorConfig_;
	}

	inline auto ReactorPool::GetReactor(const U64 idx) const -> const Reactor&
	{
		return this->Pool_[idx];
	}

	inline auto ReactorPool::operator[](const U64 idx) const -> const Reactor&
	{
		return this->GetReactor(idx);
	}

	inline auto ReactorPool::GetAlphaReactor() -> Reactor&
	{
		return this->Pool_.front();
	}

	inline auto ReactorPool::operator*() -> Reactor&
	{
		return this->Pool_.front();
	}

	inline auto ReactorPool::GetAlphaReactor() const -> const Reactor&
	{
		return this->Pool_.front();
	}

	inline auto ReactorPool::operator*() const -> const Reactor&
	{
		return this->Pool_.front();
	}

	/// <summary>
	/// 128 bit vector type for SIMD data
	/// SSE %XMM registers on x86
	/// ARM Neon registers on ARM
	/// </summary>
	using Vector128 = std::array<U64, 2>;

	static_assert(sizeof(Vector128) == 16);

	/// <summary>
	/// 256 bit vector register type.
	/// AVX %YMM registers on x86
	/// </summary>
	using Vector256 = std::array<U64, 4>;

	static_assert(sizeof(Vector256) == 32);

	/// <summary>
	/// 512 bit vector register type.
	/// AVX-512 %ZMM registers on x86
	/// </summary>
	using Vector512 = std::array<U64, 8>;

	static_assert(sizeof(Vector512) == 64);

	/// <summary>
	/// Task routine function.
	/// </summary>
	using TaskRoutine = std::function<auto() -> void>;

	/// <summary>
	/// Represents a queue of task which are executed on a worker threads.
	/// </summary>
	class [[nodiscard]] TaskQueueThread final
	{
		/// <summary>
		/// Is the thread currently disposing?!
		/// </summary>
		bool Disposing_ {false};

		/// <summary>
		/// Job queue.
		/// </summary>
		std::queue<TaskRoutine, std::pmr::deque<TaskRoutine>> TaskQueue_ { };

		/// <summary>
		/// Mutex for the queue.
		/// </summary>
		std::mutex QueueMutex_ { };

		/// <summary>
		/// Condition notifier.
		/// </summary>
		std::condition_variable SharedCondition_ { };

		/// <summary>
		/// Worker thread.
		/// </summary>
		std::thread Worker_;

		/// <summary>
		/// Loop for the thread,
		/// executes all jobs in the queue.
		/// </summary>
		/// <returns></returns>
		auto DispatchJobQueue() -> void;

	public:
		/// <summary>
		/// Construct and launch background thread on queue.
		/// </summary>
		/// <returns></returns>
		TaskQueueThread();

		/// <summary>
		/// Construct and launch background thread on queue.
		/// </summary>
		/// <param name="allocator">The memory resource to use.</param>
		/// <returns></returns>
		explicit TaskQueueThread(std::pmr::memory_resource& allocator);

		/// <summary>
		/// No copy.
		/// </summary>
		TaskQueueThread(const TaskQueueThread&) = delete;

		/// <summary>
		/// No move.
		/// </summary>
		TaskQueueThread(TaskQueueThread&&) = delete;

		/// <summary>
		/// No copy.
		/// </summary>
		/// <returns></returns>
		auto operator=(const TaskQueueThread&) -> TaskQueueThread& = delete;

		/// <summary>
		/// No move.
		/// </summary>
		/// <returns></returns>
		auto operator=(TaskQueueThread&&) -> TaskQueueThread& = delete;

		/// <summary>
		/// Destroy and join thread.
		/// </summary>
		~TaskQueueThread();

		/// <summary>
		/// Wait until all tasks are done.
		/// </summary>
		/// <returns></returns>
		auto Join() -> void;

		/// <summary>
		/// Enqueue a task into the queue.
		/// </summary>
		/// <param name="target">The task routine to execute.</param>
		/// <returns></returns>
		auto Enqueue(TaskRoutine&& target) -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the task queue is disposing the resources and the thread.</returns>
		[[nodiscard]]
		auto IsDisposing() const -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The task queue.</returns>
		[[nodiscard]]
		auto GetTaskQueue() const -> const std::queue<TaskRoutine, std::pmr::deque<TaskRoutine>>&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The worker thread used to do all the work.</returns>
		[[nodiscard]]
		auto GetWorkerThread() const -> const std::thread&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The remaining amount of tasks in the queue.</returns>
		[[nodiscard]]
		auto GetRemainingTaskCount() const -> U64;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if task queue is currently empty, else false.</returns>
		[[nodiscard]]
		auto IsEmpty() const -> bool;
	};

	inline auto TaskQueueThread::IsDisposing() const -> bool
	{
		return this->Disposing_;
	}

	inline auto TaskQueueThread::GetTaskQueue() const -> const std::queue<TaskRoutine, std::pmr::deque<TaskRoutine>>&
	{
		return this->TaskQueue_;
	}

	inline auto TaskQueueThread::GetWorkerThread() const -> const std::thread&
	{
		return this->Worker_;
	}

	inline auto TaskQueueThread::GetRemainingTaskCount() const -> U64
	{
		return this->TaskQueue_.size();
	}

	inline auto TaskQueueThread::IsEmpty() const -> bool
	{
		return this->TaskQueue_.empty();
	}

	/// <summary>
	/// Contains a pool of scheduler queues.
	/// </summary>
	class TaskQueueThreadPool final
	{
		std::pmr::monotonic_buffer_resource* Allocator_ {nullptr};

	public:
		/// <summary>
		/// Data types used to store.
		/// </summary>
		using StorageType = std::pmr::vector<std::unique_ptr<TaskQueueThread>>;

		/// <summary>
		/// The list of task queue threads.
		/// </summary>
		StorageType Threads { };

		/// <summary>
		/// Default constructor.
		/// </summary>
		/// <returns></returns>
		TaskQueueThreadPool() = default;

		/// <summary>
		/// Construct and start n threads.
		/// </summary>
		/// <param name="threadCount"></param>
		/// <returns></returns>
		explicit TaskQueueThreadPool(U64 threadCount);

		/// <summary>
		/// Construct empty with allocator.
		/// </summary>
		/// <param name="allocator"></param>
		/// <returns></returns>
		explicit TaskQueueThreadPool(std::pmr::monotonic_buffer_resource& allocator);

		/// <summary>
		/// Construct with allocator and launch threads.
		/// </summary>
		/// <param name="allocator"></param>
		/// <param name="threadCount"></param>
		/// <returns></returns>
		TaskQueueThreadPool(std::pmr::monotonic_buffer_resource& allocator, U64 threadCount);

		/// <summary>
		/// No copying.
		/// </summary>
		/// <param name="other"></param>
		TaskQueueThreadPool(const TaskQueueThreadPool& other) = delete;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		TaskQueueThreadPool(TaskQueueThreadPool&& other) = default;

		/// <summary>
		/// No copying.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const TaskQueueThreadPool& other) -> TaskQueueThreadPool& = delete;

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(TaskQueueThreadPool&& other) -> TaskQueueThreadPool& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		~TaskQueueThreadPool() = default;

		/// <summary>
		/// Join all threads.
		/// </summary>
		/// <returns></returns>
		auto JoinAll() -> void;

		/// <summary>
		/// Joins and removes all threads.
		/// </summary>
		/// <returns></returns>
		auto Clear() -> void;

		/// <summary>
		/// Resizes the container size.
		/// </summary>
		/// <param name="size"></param>
		/// <returns></returns>
		auto Resize(U64 size) -> void;

		/// <summary>
		/// Pushes a new task queue thread into the queue.
		/// </summary>
		/// <param name="elem"></param>
		/// <returns></returns>
		auto Push() -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The amount of threads.</returns>
		[[nodiscard]]
		auto GetSize() const -> U64;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto begin() -> StorageType::iterator;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto end() -> StorageType::iterator;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto rbegin() -> StorageType::reverse_iterator;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto rend() -> StorageType::reverse_iterator;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto cbegin() const -> StorageType::const_iterator;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto cend() const -> StorageType::const_iterator;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto crbegin() const -> StorageType::const_reverse_iterator;

		/// <summary>
		/// STL iterator interface.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto crend() const -> StorageType::const_reverse_iterator;
	};

	inline auto TaskQueueThreadPool::Clear() -> void
	{
		this->JoinAll();
		this->Threads.clear();
	}

	inline auto TaskQueueThreadPool::Resize(const U64 size) -> void
	{
		this->Threads.resize(size);
	}

	inline auto TaskQueueThreadPool::GetSize() const -> U64
	{
		return this->Threads.size();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	inline auto TaskQueueThreadPool::begin() -> StorageType::iterator
	{
		return std::begin(this->Threads);
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	inline auto TaskQueueThreadPool::end() -> StorageType::iterator
	{
		return std::end(this->Threads);
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	inline auto TaskQueueThreadPool::rbegin() -> StorageType::reverse_iterator
	{
		return std::rbegin(this->Threads);
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	inline auto TaskQueueThreadPool::rend() -> StorageType::reverse_iterator
	{
		return std::rend(this->Threads);
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	inline auto TaskQueueThreadPool::cbegin() const -> StorageType::const_iterator
	{
		return std::cbegin(this->Threads);
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	inline auto TaskQueueThreadPool::cend() const -> StorageType::const_iterator
	{
		return std::cend(this->Threads);
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	inline auto TaskQueueThreadPool::crbegin() const -> StorageType::const_reverse_iterator
	{
		return std::crbegin(this->Threads);
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	inline auto TaskQueueThreadPool::crend() const -> StorageType::const_reverse_iterator
	{
		return std::crend(this->Threads);
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto begin(TaskQueueThreadPool& pool) -> auto
	{
		return pool.begin();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto end(TaskQueueThreadPool& pool) -> auto
	{
		return pool.end();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto rbegin(TaskQueueThreadPool& pool) -> auto
	{
		return pool.rbegin();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto rend(TaskQueueThreadPool& pool) -> auto
	{
		return pool.rend();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto cbegin(const TaskQueueThreadPool& pool) -> auto
	{
		return pool.cbegin();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto cend(const TaskQueueThreadPool& pool) -> auto
	{
		return pool.cend();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto crbegin(const TaskQueueThreadPool& pool) -> auto
	{
		return pool.crbegin();
	}

	/// <summary>
	/// STL iterator interface.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto crend(const TaskQueueThreadPool& pool) -> auto
	{
		return pool.crend();
	}
}
