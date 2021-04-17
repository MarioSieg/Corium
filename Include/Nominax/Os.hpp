#pragma once

#include <cstddef>
#include <string_view>

namespace Nominax::Os {
	[[nodiscard]]
	extern auto QuerySystemMemoryTotal() -> std::size_t;
	
	[[nodiscard]]
	extern auto QueryProcessMemoryUsed() -> std::size_t;

	[[nodiscard]]
	extern auto QueryCpuName() -> std::string;

	[[nodiscard]]
	extern auto DylibOpen(std::string_view filePath) -> void*;

	[[nodiscard]]
	extern auto DylibLookupSymbol(void* handle, std::string_view symbolName) -> void*;
	
	extern void DylibClose(void*& handle);
}
