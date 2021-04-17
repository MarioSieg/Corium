#include "../Include/Nominax/Os.hpp"
#include "../Include/Nominax/Platform.hpp"

#if NOMINAX_OS_WINDOWS

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Psapi.h>

namespace Nominax::Os {
	auto QuerySystemMemoryTotal() -> std::size_t {
		MEMORYSTATUSEX status;
		status.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&status);
		return static_cast<std::size_t>(status.ullTotalPhys);
	}

	auto QueryProcessMemoryUsed() -> std::size_t {
		PROCESS_MEMORY_COUNTERS pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
		return static_cast<std::size_t>(pmc.WorkingSetSize);
	}

	auto QueryCpuName() -> std::string {
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

	auto DylibOpen(const std::string_view filePath) -> void* {
		return static_cast<void*>(::LoadLibraryA(filePath.data()));
	}
	
	auto DylibLookupSymbol(void* const handle, const std::string_view symbolName) -> void* {
		return reinterpret_cast<void*>(::GetProcAddress(static_cast<HMODULE>(handle), symbolName.data()));
	}
	
	void DylibClose(void*& handle) {
		::FreeLibrary(static_cast<HMODULE>(handle));
		handle = nullptr;
	}
}

#endif
