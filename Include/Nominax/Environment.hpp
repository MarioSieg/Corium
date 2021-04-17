#pragma once

#include <iostream>
#include <string>

#include "Platform.hpp"

namespace Nominax {
	using LogStream = std::ostream;
	using ErrStream = std::ostream;
	
	/// <summary>
	/// Represents the whole runtime environment.
	/// </summary>
	class Environment {
		std::string_view OsName{NOMINAX_OS_NAME};
		std::string_view ArchitectureName{NOMINAX_ARCH_NAME};
		std::string_view CompilerName{NOMINAX_COM_NAME};
		std::string CpuName{};
		std::size_t TotalMemory{};
		std::size_t AvailableMemory{};
		std::size_t ThreadCount{};

	public:
		Environment() noexcept = default;
		Environment(const Environment&) = delete;
		Environment(Environment&&) = delete;
		auto operator =(const Environment&) -> Environment& = delete;
		auto operator =(Environment&&) -> Environment& = delete;
		virtual ~Environment() = default;

		LogStream& Logger{std::cout};
		ErrStream& ErrorLogger{std::cerr};

		/// <summary>
		/// Initialize the environment.
		/// </summary>
		/// <returns></returns>
		auto BootEnvironment() -> bool;
	};	
}