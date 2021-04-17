#pragma once

#include <iostream>
#include <string>

using log_stream = std::ostream;
using err_stream = std::ostream;

#include "platform.hpp"

namespace nominax {
	/// <summary>
	/// Represents the whole runtime environment.
	/// </summary>
	class environment {
		std::string_view os_name_{NOMINAX_OS_NAME};
		std::string_view arch_name_{NOMINAX_ARCH_NAME};
		std::string_view compiler_name_{NOMINAX_COM_NAME};
		std::string cpu_name_{};
		std::size_t total_memory_{};
		std::size_t available_memory_{};
		std::size_t thread_count{};

	public:
		environment() noexcept = default;
		environment(const environment&) = delete;
		environment(environment&&) = delete;
		auto operator =(const environment&) -> environment& = delete;
		auto operator =(environment&&) -> environment& = delete;
		virtual ~environment() = default;

		log_stream& log{std::cout};
		err_stream& err{std::cerr};

		/// <summary>
		/// Initialize the environment.
		/// </summary>
		/// <returns></returns>
		auto boot() -> bool;
	};	
}