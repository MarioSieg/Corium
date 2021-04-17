#include "../Include/Nominax/Os.hpp"
#include "../Include/Nominax/Platform.hpp"

#if NOMINAX_OS_WINDOWS

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Psapi.h>

namespace Nominax::OS {
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

	auto cpu_name() -> std::string {
		HKEY key;
		if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, R"(HARDWARE\DESCRIPTION\System\CentralProcessor\0)", 0, KEY_READ, &key)) [[unlikely]] {
			return "Unknown";
		}
		char id[64 + 1];
		DWORD id_len = sizeof id;
		LPBYTE data = static_cast<LPBYTE>(static_cast<void*>(id));
		if (RegQueryValueExA(key, "ProcessorNameString", nullptr, nullptr, data, &id_len)) [[unlikely]] {
			return "Unknown";
		}
		return id;
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
