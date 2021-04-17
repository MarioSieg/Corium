#pragma once

#include <cstddef>
#include <string_view>

namespace Nominax::OS {
	[[nodiscard]]
	extern auto query_system_memory_total() -> std::size_t;
	
	[[nodiscard]]
	extern auto query_process_memory_used() -> std::size_t;

	[[nodiscard]]
	extern auto cpu_name() -> std::string;

	[[nodiscard]]
	extern auto dylib_open(std::string_view file_) -> void*;

	[[nodiscard]]
	extern auto dylib_lookup_symbol(void* handle_, std::string_view symbol_) -> void*;
	
	extern void dylib_close(void*& handle_);
}
