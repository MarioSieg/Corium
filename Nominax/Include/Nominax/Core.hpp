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
		ByteCode::Signal* CodeChunk {nullptr};

		/// <summary>
		/// Instruction map data pointer.
		/// </summary>
		const bool* CodeChunkInstructionMap {nullptr};

		/// <summary>
		/// Code chunk and instruction map length.
		/// </summary>
		std::size_t CodeChunkSize {0};

		/// <summary>
		/// Intrinsic routine registry data pointer.
		/// </summary>
		ByteCode::IntrinsicRoutine* const* IntrinsicTable {nullptr};

		/// <summary>
		/// Intrinsic routine registry length.
		/// </summary>
		std::size_t IntrinsicTableSize {0};

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
		std::size_t StackSize {0};

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
		std::span<ByteCode::Signal> CodeChunk;

		/// <summary>
		/// Instruction mapping view.
		/// </summary>
		std::span<const bool> CodeChunkInstructionMap;

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
		static constexpr std::size_t SIZE_SMALL {1_mb / sizeof(Foundation::Record)};

		/// <summary>
		/// Medium sizes 4 MB stack.
		/// Contains the size in records, not bytes.
		/// </summary>
		static constexpr std::size_t SIZE_MEDIUM {4_mb / sizeof(Foundation::Record)};

		/// <summary>
		/// Medium sizes 8 MB stack.
		/// Contains the size in records, not bytes.
		/// </summary>
		static constexpr std::size_t SIZE_LARGE {8_mb / sizeof(Foundation::Record)};
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
		auto Size() const -> std::size_t;

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
		explicit FixedStack(std::pmr::memory_resource& allocator, std::size_t sizeInRecords);

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

	inline auto FixedStack::Size() const -> std::size_t
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
		std::size_t StackSize {FixedStack::SIZE_LARGE};

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
		static constexpr auto Default(std::size_t stackSize = FixedStack::SIZE_LARGE) -> ReactorSpawnDescriptor;
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
	constexpr auto ReactorSpawnDescriptor::Default(const std::size_t stackSize) -> ReactorSpawnDescriptor
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
		std::size_t BootPoolSize {128_kb};

		/// <summary>
		/// The size of the system memory pool size.
		/// </summary>
		std::size_t SystemPoolSize {512_kb};

		/// <summary>
		/// The count of reactors.
		/// If 0, the system will use the number of CPU threads.
		/// </summary>
		std::size_t ReactorCount {0};

		/// <summary>
		/// The reactor stack size in bytes.
		/// Must be divisible by 8!
		/// </summary>
		std::size_t StackSize {8_mb};

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
		virtual auto OnPreExecutionHook(const ByteCode::CodeImageBundle& appCodeBundle) -> bool;

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
		static constexpr std::size_t FALLBACK_SYSTEM_POOL_SIZE {256_kb};
		static_assert(FALLBACK_SYSTEM_POOL_SIZE);

		/// <summary>
		/// The min size of the boot pool.
		/// </summary>
		static constexpr std::size_t BOOT_POOL_SIZE_MIN {32_kb};
		static_assert(BOOT_POOL_SIZE_MIN);

		/// <summary>
		/// The max size of the boot pool.
		/// </summary>
		static constexpr std::size_t BOOT_POOL_SIZE_MAX {256_kb};
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
		auto Execute(ByteCode::CodeImageBundle& image) -> ExecutionResult;

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
		auto operator()(ByteCode::CodeImageBundle& image) -> ExecutionResult;

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
		auto GetMonotonicSystemPoolSize() const -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The count of reactor executions so far.</returns>
		[[nodiscard]]
		auto GetExecutionCount() const -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The history of execution times.</returns>
		[[nodiscard]]
		auto GetExecutionTimeHistory() const -> const std::pmr::vector<std::chrono::duration<F64, std::micro>>&;
	};

	inline auto Environment::operator()(ByteCode::CodeImageBundle& image) -> ExecutionResult
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
	/// Compute relative jump address.
	/// </summary>
	NOX_FLATTEN inline auto ComputeRelativeJumpAddress(const ByteCode::Signal* const base, const ByteCode::JumpAddress address) -> const void*
	{
		return base + static_cast<std::underlying_type_t<decltype(address)>>(address) - 1;
	}

	/// <summary>
	/// Replaces the op-codes in the bucket with the pointers to the labels.
	/// This improves performance because no array lookup is needed.
	/// The jump assembly generated on my machine (x86-64, clang):
	/// With jump table mapping:
	/// jmpq	*(%r14)
	/// Without jump table mapping:
	/// jmpq	*(%rcx,%rax,8)
	/// This easily gives some 300-500 milliseconds performance improvement on my machine.
	/// Important: The signal bucket is modified.
	/// After mapping, each signal which was an instruction now contains a void* to the jump label.
	/// That means, that the original instructions/opcodes are gone.
	/// For example, let's say the first instruction was push 32, so the signal was:
	/// [1] -> 7	[type: instruction]
	/// [2] -> 32	[type: i64]
	/// After mapping the content will be:
	/// [1] -> 0x00D273F27A	[type: void*]
	/// [2] -> 32			[type: i64]
	/// Because all opcodes are gone, accessing the bucket and using the opcode values after mapping is not allowed!
	/// Because the Signal type is not discriminated (like DynamicSignal), we do not know which signal contains an instruction.
	/// For that we have the instruction map, which must have the same size as the bucket.
	/// For each bucket entry there is a signal map entry, which is true if the bucket entry at the same index is an instruction else false.
	/// Example:
	/// bucket[1] = push	| instructionMap[1] = true
	/// bucket[2] = 3		| instructionMap[2] = false
	/// bucket[3] = pushz	| instructionMap[3] = true
	/// bucket[4] = nop		| instructionMap[4] = true
	///
	/// ** Update 10.05.2021 **
	/// For further optimization jump target addresses are not also converted to pointers.
	/// When you specify a branch like
	/// jz 3
	/// the byte code position of 3 will be replaced by the real pointer value,
	/// to avoid more calculation.
	/// But this mapping is done in the byte code builder, not here because it does not require the jump table.
	/// </summary>
	/// <param name="bucket">The byte code bucket to use as mapping target.</param>
	/// <param name="bucketEnd">The incremented end pointer of the byte code bucket, calculated as: bucket + bucketLength</param>
	/// <param name="jumpAddressMap">The instruction map. Must have the same size as the byte code bucket.</param>
	/// <param name="jumpTable">The jump table. Must contain an address for each instruction.</param>
	/// <returns>true on success, else false.</returns>
	[[maybe_unused]]
	[[nodiscard]]
	extern auto PerformJumpTableMapping
	(
		ByteCode::Signal* NOX_RESTRICT                     bucket,
		const ByteCode::Signal* NOX_RESTRICT               bucketEnd,
		const bool*                                        jumpAddressMap,
		const void* NOX_RESTRICT const* NOX_RESTRICT const jumpTable
	) -> bool;

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
		const std::size_t                                  jumpTableSize
	) -> bool
	{
		if (!jumpTable || !jumpTableSize)
		{
			return false;
		}

		for (const auto *current {jumpTable}, *const end {jumpTable + jumpTableSize}; current < end; ++current)
		{
			if (!*current)
			{
				return false;
			}
		}

		return true;
	}

	/// <summary>
	/// Contains all flags in the flag vector field in the object header.
	/// </summary>
	union ObjectFlagVector final
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

		U32 Merged;
	};

	static_assert(sizeof(ObjectFlagVector) == sizeof(U32));

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
		U32 StrongRefCount {0};

		/// <summary>
		/// Object size in records.
		/// </summary>
		U32 Size {0};

		/// <summary>
		/// Type index for type DB.
		/// </summary>
		U32 TypeId {0};

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
		auto MapToRegionUnchecked(Foundation::Record* region) const -> void;

		/// <summary>
		/// Maps this record into the specified memory region.
		/// ! The region must have at least 2 record entries to write to !
		/// </summary>
		/// <param name="region"></param>
		/// <returns>true if the size of the region was correct and the mapping succeeded, else false.</returns>
		[[nodiscard]]
		auto MapToRegionChecked(std::span<Foundation::Record> region) const -> bool;

		/// <summary>
		/// Maps this record from the specified memory region.
		/// ! The region must have at least 2 record entries to read from!
		/// Safe alternative is the overload using std::span.
		/// </summary>
		/// <param name="region"></param>
		/// <returns></returns>
		auto MapFromRegionUnchecked(const Foundation::Record* region) -> void;

		/// <summary>
		/// Maps this record from the specified memory region.
		/// ! The region must have at least 2 record entries to read from!
		/// </summary>
		/// <param name="region"></param>
		/// <returns>true if the size of the region was correct and the mapping succeeded, else false.</returns>
		[[nodiscard]]
		auto MapFromRegionChecked(std::span<const Foundation::Record> region) -> bool;

		/// <summary>
		/// Map an object header to the region and return the current value of the strong ref count.
		/// </summary>
		/// <param name="region"></param>
		/// <returns>The current value of the strong ref count.</returns>
		[[nodiscard]]
		static constexpr auto ReadMapping_StrongRefCount(const Foundation::Record* region) -> U32;

		/// <summary>
		/// Map an object header to the region and return the current value of the size.
		/// </summary>
		/// <param name="region"></param>
		/// <returns>The current value of the size field.</returns>
		[[nodiscard]]
		static constexpr auto ReadMapping_Size(const Foundation::Record* region) -> U32;

		/// <summary>
		/// Map an object header to the region and return the current value of the type id.
		/// </summary>
		/// <param name="region"></param>
		/// <returns>The current value of the type id.</returns>
		[[nodiscard]]
		static constexpr auto ReadMapping_TypeId(const Foundation::Record* region) -> U32;

		/// <summary>
		/// Map an object header to the region and return the current value of the flag vector.
		/// </summary>
		/// <param name="region"></param>
		/// <returns>The current value of the flag vector.</returns>
		[[nodiscard ]]
		static constexpr auto ReadMapping_FlagVector(const Foundation::Record* region) -> ObjectFlagVector;

		/// <summary>
		/// Map an object header to the region and writes the value into the strong ref count field.
		/// </summary>
		/// <param name="region"></param>
		/// <param name="strongRefCount">The value to write.</param>
		/// <returns></returns>
		static constexpr auto WriteMapping_StrongRefCount(Foundation::Record* region, U32 strongRefCount) -> void;

		/// <summary>
		/// Implicit map the region to an object header and increment the strong reference counter by one.
		/// The region must have at least 2 record entries to read from!
		/// </summary>
		/// <param name="region"></param>
		/// <returns></returns>
		static constexpr auto WriteMapping_IncrementStrongRefCount(Foundation::Record* region) -> void;

		/// <summary>
		/// Implicit map the region to an object header and decrement the strong reference counter by one.
		/// The region must have at least 2 record entries to read from!
		/// </summary>
		/// <param name="region"></param>
		/// <returns></returns>
		static constexpr auto WriteMapping_DecrementStrongRefCount(Foundation::Record* region) -> void;

		/// <summary>
		/// Map an object header to the region and writes the value into the size field.
		/// </summary>
		/// <param name="region"></param>
		/// <param name="size">The value to write.</param>
		/// <returns></returns>
		static constexpr auto WriteMapping_Size(Foundation::Record* region, U32 size) -> void;

		/// <summary>
		/// Map an object header to the region and writes the value into the type id field.
		/// </summary>
		/// <param name="region"></param>
		/// <param name="typeId">The value to write.</param>
		/// <returns></returns>
		static constexpr auto WriteMapping_TypeId(Foundation::Record* region, U32 typeId) -> void;

		/// <summary>
		/// Map an object header to the region and writes the value into the flag vector field.
		/// </summary>
		/// <param name="region"></param>
		/// <param name="flagVector">The value to write.</param>
		/// <returns></returns>
		static constexpr auto WriteMapping_FlagVector(Foundation::Record* region, ObjectFlagVector flagVector) -> void;

		/// <summary>
		/// Type-pun a region to an object header
		/// using reinterpret_cast. This is bug prone and unsafe.
		/// </summary>
		/// <param name="region"></param>
		/// <returns></returns>
		[[nodiscard]]
		static auto RawQueryTypePun(Foundation::Record* region) -> ObjectHeader&;

		/// <summary>
		/// The size of each header block field.
		/// </summary>
		static constexpr auto STRIDE {sizeof(U32)};

		/// <summary>
		/// The count of header field blocks => 4 (StrongRefCount, Size, TypeId, FlagVector)
		/// </summary>
		static constexpr std::size_t BLOCKS {4};

		/// <summary>
		/// The offset in records from the blob base pointer.
		/// </summary>
		static constexpr std::uintptr_t RECORD_OFFSET {STRIDE * BLOCKS / sizeof(Foundation::Record)};

		/// <summary>
		/// The amount of records required to store the header.
		/// </summary>
		static constexpr U32 RECORD_CHUNKS {RECORD_OFFSET};

		static_assert(STRIDE == 4);
		static_assert(BLOCKS == 4);
	};

	static_assert(sizeof(ObjectHeader) == ObjectHeader::BLOCKS * ObjectHeader::STRIDE);
	static_assert(sizeof(ObjectHeader) == 16);
	static_assert(sizeof(ObjectHeader) % ObjectHeader::BLOCKS == 0); // Ok, ok we know the size must be 16 bytes!
	static_assert(std::is_standard_layout_v<ObjectHeader>);
	static_assert(std::is_trivially_copyable_v<ObjectHeader>);

	NOX_FLATTEN inline auto ObjectHeader::MapToRegionUnchecked(Foundation::Record* const region) const -> void
	{
		std::memcpy(region, this, sizeof(ObjectHeader));
	}

	NOX_FLATTEN inline auto ObjectHeader::MapToRegionChecked(const std::span<Foundation::Record> region) const -> bool
	{
		if (region.size() < 2)
		[[unlikely]]
		{
			return false;
		}
		return std::memcpy(region.data(), this, sizeof(ObjectHeader));
	}

	NOX_FLATTEN inline auto ObjectHeader::MapFromRegionUnchecked(const Foundation::Record* const region) -> void
	{
		std::memcpy(this, region, sizeof(ObjectHeader));
	}

	NOX_FLATTEN inline auto ObjectHeader::MapFromRegionChecked(const std::span<const Foundation::Record> region) -> bool
	{
		if (region.size() < 2)
		[[unlikely]]
		{
			return false;
		}
		return std::memcpy(this, region.data(), sizeof(ObjectHeader));
	}

	NOX_FLATTEN constexpr auto ObjectHeader::ReadMapping_StrongRefCount(const Foundation::Record* const region) -> U32
	{
		return (*region).AsU32S[0];
	}

	NOX_FLATTEN constexpr auto ObjectHeader::ReadMapping_Size(const Foundation::Record* const region) -> U32
	{
		return (*region).AsU32S[1];
	}

	NOX_FLATTEN constexpr auto ObjectHeader::ReadMapping_TypeId(const Foundation::Record* const region) -> U32
	{
		return region[1].AsU32S[0];
	}

	NOX_FLATTEN constexpr auto ObjectHeader::ReadMapping_FlagVector(const Foundation::Record* const region) -> ObjectFlagVector
	{
		const auto flags = ObjectFlagVector
		{
			.Merged = region[1].AsU32S[1]
		};
		return flags;
	}

	NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_StrongRefCount(Foundation::Record* const region, const U32 strongRefCount) -> void
	{
		(*region).AsU32S[0] = strongRefCount;
	}

	NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_IncrementStrongRefCount(Foundation::Record* const region) -> void
	{
		++(*region).AsU32S[0];
	}

	NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_DecrementStrongRefCount(Foundation::Record* const region) -> void
	{
		--(*region).AsU32S[0];
	}

	NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_Size(Foundation::Record* const region, const U32 size) -> void
	{
		(*region).AsU32S[1] = size;
	}

	NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_TypeId(Foundation::Record* const region, const U32 typeId) -> void
	{
		region[1].AsU32S[0] = typeId;
	}

	NOX_FLATTEN constexpr auto ObjectHeader::WriteMapping_FlagVector(Foundation::Record* const region, const ObjectFlagVector flagVector) -> void
	{
		region[1].AsU32S[1] = flagVector.Merged;
	}

	NOX_FLATTEN inline auto ObjectHeader::RawQueryTypePun(Foundation::Record* const region) -> ObjectHeader&
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
		using BlobBlockType = Foundation::Record;

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
		/// This size must be written into the header field "Size"!
		/// </summary>
		BlobBlockType* Blob_ {nullptr};

	public:
		explicit Object(BlobBlockType* blob);

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The strong reference count field from the object header.</returns>
		[[nodiscard]]
		auto IMMUTATOR HeaderRead_StrongReferenceCount() const -> U32;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the object in records. The size field from the object header.</returns>
		[[nodiscard]]
		auto IMMUTATOR HeaderRead_BlockSize() const -> U32;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The type id field from the object header.</returns>
		[[nodiscard]]
		auto IMMUTATOR HeaderRead_TypeId() const -> U32;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The flag vector field from the object header.</returns>
		[[nodiscard]]
		auto IMMUTATOR Header_ReadFlagVector() const -> ObjectFlagVector;

		/// <summary>
		/// Writes the value into the strong ref count header field.
		/// </summary>
		/// <param name="strongRefCount">The new value to write.</param>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_StrongRefCount(U32 strongRefCount) const -> void;

		/// <summary>
		/// Increments the object header strong reference counter by one.
		/// </summary>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_IncrementStrongRefCount() const -> void;

		/// <summary>
		/// Decrements the object header strong reference counter by one.
		/// </summary>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_DecrementStrongRefCount() const -> void;

		/// <summary>
		/// Same as HeaderWrite_IncrementStrongRefCount()
		/// </summary>
		/// <returns></returns>
		auto MUTATOR operator ++() const -> void;

		/// <summary>
		/// Same as HeaderWrite_DecrementStrongRefCount()
		/// </summary>
		/// <returns></returns>
		auto MUTATOR operator --() const -> void;

		/// <summary>
		/// Same as HeaderWrite_IncrementStrongRefCount()
		/// </summary>
		/// <returns></returns>
		auto MUTATOR operator ++(int) const -> void;

		/// <summary>
		/// Same as HeaderWrite_DecrementStrongRefCount()
		/// </summary>
		/// <returns></returns>
		auto MUTATOR operator --(int) const -> void;

		/// <summary>
		/// Writes the value of size into the Size object header field.
		/// </summary>
		/// <param name="size">The new value to write.</param>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_Size(U32 size) const -> void;

		/// <summary>
		/// Writes the value of typeId into the TypeId object header field.
		/// </summary>
		/// <param name="typeId">The new value to write.</param>
		/// <returns></returns>
		auto MUTATOR HeaderWrite_TypeId(U32 typeId) const -> void;

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
		auto IMMUTATOR BlobSize() const -> std::size_t;

		/// <summary>
		/// The size in bytes of the whole data blob:
		/// header + object
		/// </summary>
		/// <returns>The size in bytes of the whole object header plus the whole size of object it self.</returns>
		[[nodiscard]]
		auto IMMUTATOR BlobSizeInBytes() const -> std::size_t;

		/// <summary>
		/// Returns the size of the object block in bytes.
		/// Same as HeaderRead_BlockSize() * sizeof(Common::Record) 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto IMMUTATOR ObjectBlockSizeInBytes() const -> std::size_t;

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
		auto IMMUTATOR operator [](std::size_t idx) -> BlobBlockType&;

		/// <summary>
		/// Unchecked subscript in object block.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		auto IMMUTATOR operator [](std::size_t idx) const -> BlobBlockType;

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
	inline auto Object::DeepValueCmp_NotEqual([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) -> bool
	{
		assert(false);
		return false;
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
	inline auto Object::DeepValueCmp_Less([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) -> bool
	{
		assert(false);
		return false;
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
	inline auto Object::DeepValueCmp_LessEqual([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) -> bool
	{
		assert(false);
		return false;
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
	inline auto Object::DeepValueCmp_Greater([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) -> bool
	{
		assert(false);
		return false;
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
	inline auto Object::DeepValueCmp_GreaterEqual([[maybe_unused]] const Object a, [[maybe_unused]] const Object b) -> bool
	{
		assert(false);
		return false;
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
		assert(this->Blob_ != nullptr);
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
		assert(this->Blob_ != nullptr);
		return this->Blob_ + ObjectHeader::RECORD_OFFSET;
	}

	NOX_FLATTEN inline auto IMMUTATOR Object::LookupObjectBlockEnd() const -> BlobBlockType*
	{
		assert(this->HeaderRead_BlockSize() > 0);
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

	NOX_FLATTEN inline auto IMMUTATOR Object::BlobSize() const -> std::size_t
	{
		return ObjectHeader::RECORD_CHUNKS + ObjectHeader::ReadMapping_Size(this->QueryRawHeader());
	}

	NOX_FLATTEN inline auto IMMUTATOR Object::BlobSizeInBytes() const -> std::size_t
	{
		return BlobSize() * sizeof(Foundation::Record);
	}

	NOX_FLATTEN inline auto IMMUTATOR Object::ObjectBlockSizeInBytes() const -> std::size_t
	{
		return this->HeaderRead_BlockSize() * sizeof(Foundation::Record);
	}

	NOX_FLATTEN inline auto IMMUTATOR Object::HeaderRead_StrongReferenceCount() const -> U32
	{
		return ObjectHeader::ReadMapping_StrongRefCount(this->QueryRawHeader());
	}

	NOX_FLATTEN inline auto IMMUTATOR Object::HeaderRead_BlockSize() const -> U32
	{
		return ObjectHeader::ReadMapping_Size(this->QueryRawHeader());
	}

	NOX_FLATTEN inline auto IMMUTATOR Object::HeaderRead_TypeId() const -> U32
	{
		return ObjectHeader::ReadMapping_TypeId(this->QueryRawHeader());
	}

	NOX_FLATTEN inline auto IMMUTATOR Object::Header_ReadFlagVector() const -> ObjectFlagVector
	{
		return ObjectHeader::ReadMapping_FlagVector(this->QueryRawHeader());
	}

	NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_IncrementStrongRefCount() const -> void
	{
		ObjectHeader::WriteMapping_IncrementStrongRefCount(this->QueryRawHeader());
	}

	NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_DecrementStrongRefCount() const -> void
	{
		ObjectHeader::WriteMapping_DecrementStrongRefCount(this->QueryRawHeader());
	}

	NOX_FLATTEN inline auto MUTATOR Object::operator++() const -> void
	{
		this->HeaderWrite_IncrementStrongRefCount();
	}

	NOX_FLATTEN inline auto MUTATOR Object::operator--() const -> void
	{
		this->HeaderWrite_DecrementStrongRefCount();
	}

	NOX_FLATTEN inline auto MUTATOR Object::operator++(int) const -> void
	{
		this->HeaderWrite_IncrementStrongRefCount();
	}

	NOX_FLATTEN inline auto MUTATOR Object::operator--(int) const -> void
	{
		this->HeaderWrite_DecrementStrongRefCount();
	}

	NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_StrongRefCount(const U32 strongRefCount) const -> void
	{
		ObjectHeader::WriteMapping_StrongRefCount(this->QueryRawHeader(), strongRefCount);
	}

	NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_Size(const U32 size) const -> void
	{
		ObjectHeader::WriteMapping_Size(this->QueryRawHeader(), size);
	}

	NOX_FLATTEN inline auto MUTATOR Object::HeaderWrite_TypeId(const U32 typeId) const -> void
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

	NOX_FLATTEN inline auto IMMUTATOR Object::operator[](const std::size_t idx) -> BlobBlockType&
	{
		return *(this->LookupObjectBlock() + idx);
	}

	NOX_FLATTEN inline auto IMMUTATOR Object::operator[](const std::size_t idx) const -> BlobBlockType
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

	/// <summary>
	/// Contains all sub implementations for the reactor core.
	/// </summary>
	enum class ReactorCoreSpecialization : std::size_t
	{
		Fallback,

		#if NOX_ARCH_X86_64

		/// <summary>
		/// Advanced vector extensions -> 256-bit (YMM* registers) -> VEX
		/// </summary>
		X86_64_AVX,

		/// <summary>
		/// Advanced vector extensions 512 -> 512-bit (ZMM* registers, K* mask registers) -> EVEX
		/// </summary>
		X86_64_AVX512F,

		#endif

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
				#if NOX_ARCH_X86_64

			case ReactorCoreSpecialization::X86_64_AVX:
				return "X86-64 AVX";

			case ReactorCoreSpecialization::X86_64_AVX512F:
				return "X86-64 AVX512F";
				#endif

			default:
				return "Generic Fallback";
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
	using ReactorRegistry = std::array<ReactorCoreExecutionRoutine*, static_cast<std::size_t>(ReactorCoreSpecialization::Count)>;

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
		/// Returns the fallback reactor routine with no platform specific optimizations,
		/// available on all platforms and all CPUs.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		static auto GetFallbackRoutineLink() -> ReactorRoutineLink;

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
		std::size_t PoolIndex_;

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
			std::size_t                              poolIdx     = 0
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
		auto Execute(ByteCode::CodeImageBundle& bundle) -> std::pair<ReactorShutdownReason, const ReactorState&>;

		/// <summary>
		/// Execute reactor with specified application code bundle.
		/// </summary>
		/// <param name="bundle"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto operator ()(ByteCode::CodeImageBundle& bundle) -> std::pair<ReactorShutdownReason, const ReactorState&>;

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
		auto GetPoolIndex() const -> std::size_t;

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

	inline auto Reactor::GetPoolIndex() const -> std::size_t
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

	inline auto Reactor::operator()(ByteCode::CodeImageBundle& bundle) -> std::pair<ReactorShutdownReason, const ReactorState&>
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
		static auto SmartQueryReactorCount(std::size_t desired = 0) -> std::size_t;

		/// <summary>
		/// Minimal one reactor is required.
		/// </summary>
		static constexpr std::size_t MIN_REACTOR_COUNT {1};

		/// <summary>
		/// Fallback reactor count.
		/// </summary>
		static constexpr std::size_t FALLBACK_REACTOR_COUNT {MIN_REACTOR_COUNT};

		/// <summary>
		/// Construct and initialize all new reactors.
		/// If the reactor count is zero, panic!
		/// </summary>
		ReactorPool
		(
			std::pmr::memory_resource&               resource,
			std::size_t                              reactorCount,
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
		auto GetSize() const -> std::size_t;

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
		auto GetReactor(std::size_t idx) const -> const Reactor&;


		/// <summary>
		/// Returns the reactor at index.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto operator [](std::size_t idx) const -> const Reactor&;

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

	inline auto ReactorPool::GetSize() const -> std::size_t
	{
		return this->Pool_.size();
	}

	inline auto ReactorPool::GetSpawnConfig() const -> const ReactorSpawnDescriptor&
	{
		return this->ReactorConfig_;
	}

	inline auto ReactorPool::GetReactor(const std::size_t idx) const -> const Reactor&
	{
		return this->Pool_[idx];
	}

	inline auto ReactorPool::operator[](const std::size_t idx) const -> const Reactor&
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
		auto GetRemainingTaskCount() const -> std::size_t;

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

	inline auto TaskQueueThread::GetRemainingTaskCount() const -> std::size_t
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
		explicit TaskQueueThreadPool(std::size_t threadCount);

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
		TaskQueueThreadPool(std::pmr::monotonic_buffer_resource& allocator, std::size_t threadCount);

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
		auto Resize(std::size_t size) -> void;

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
		auto GetSize() const -> std::size_t;

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

	inline auto TaskQueueThreadPool::Resize(const std::size_t size) -> void
	{
		this->Threads.resize(size);
	}

	inline auto TaskQueueThreadPool::GetSize() const -> std::size_t
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
