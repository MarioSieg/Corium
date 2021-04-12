#include "../inc/nominax/os.hpp"
#include "../inc/nominax/platform.hpp"

#if NOMINAX_OS_WINDOWS

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Psapi.h>

namespace nominax::os {
	auto query_system_memory_total() -> std::size_t {
		MEMORYSTATUSEX status;
		status.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&status);
		return static_cast<std::size_t>(status.ullTotalPhys);
	}

	auto query_process_memory_used() -> std::size_t {
		PROCESS_MEMORY_COUNTERS pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
		return static_cast<std::size_t>(pmc.WorkingSetSize);
	}

	auto dylib_open(const std::string_view file_) -> void* {
		return static_cast<void*>(::LoadLibraryA(file_.data()));
	}
	
	auto dylib_lookup_symbol(void* const handle_, const std::string_view symbol_) -> void* {
		return reinterpret_cast<void*>(::GetProcAddress(static_cast<HMODULE>(handle_), symbol_.data()));
	}
	
	void dylib_close(void*& handle_) {
		::FreeLibrary(static_cast<HMODULE>(handle_));
		handle_ = nullptr;
	}
}

#endif
