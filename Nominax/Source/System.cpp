#include "../Include/Nominax/System/System.hpp"
#include "../Include/Nominax/Common/Common.hpp"

namespace Nominax::System
{
	CpuFeatureDetector::CpuFeatureDetector() : Features_{}
	{
	}

	void CpuFeatureDetector::Print() const
	{
		this->Features_.PrintFeatures();
	}

	static char MachineRating(const std::size_t threads)
	{
		if (threads <= 2)
		{
			return 'F';
		}
		if (threads <= 4)
		{
			return 'E';
		}
		if (threads <= 8)
		{
			return 'D';
		}
		if (threads <= 16)
		{
			return 'C';
		}
		if (threads <= 32)
		{
			return 'B';
		}
		return 'A';
	}

	Snapshot::Snapshot()
	{
		this->QueryAll();
	}

	void Snapshot::QueryAll()
	{
		this->ThreadCount = std::thread::hardware_concurrency();
		this->ThreadId = std::this_thread::get_id();
		this->CpuName = Os::QueryCpuName();
		this->TotalSystemMemory = Os::QuerySystemMemoryTotal();
		this->ProcessMemory = Os::QueryProcessMemoryUsed();
		this->PageSize = Os::QueryPageSize();
	}

	void Snapshot::Print() const
	{
		using namespace Common;

		const auto&
		[
			ThreadId,
			OperatingSystemName,
			ArchitectureName,
			CompilerName,
			ThreadCount,
			CpuName,
			TotalSystemMemory,
			UsedSystemMemory,
			PageSize
		] = *this;

		Common::Print("Boot date: {:%A %c}\n", SafeLocalTime(std::time(nullptr)));
		Common::Print("TID: {:#X}\n", std::hash<std::thread::id>()(ThreadId));
		Common::Print("CPU: {}\n", CpuName);
		Common::Print("CPU Hardware threads: {}\n", ThreadCount);
		Common::Print("CPU Machine class: {}\n", MachineRating(ThreadCount));
		Common::Print("System memory: {}MB\n", Bytes2Megabytes(TotalSystemMemory));
		Common::Print("Process memory: {}MB\n", Bytes2Megabytes(UsedSystemMemory));
		Common::Print("Page size: {}B\n", PageSize);
	}

#if NOX_OS_LINUX

#include <cstdio>
#include <fstream>
#include <string>

#include <dlfcn.h>
#include <unistd.h>

	namespace Os
	{
		auto QuerySystemMemoryTotal()  -> std::size_t
		{
			const long pages = sysconf(_SC_PHYS_PAGES);
			const long page_size = sysconf(_SC_PAGE_SIZE);
			return static_cast<std::size_t>(pages * page_size);
		}

		auto QueryProcessMemoryUsed()  -> std::size_t {
			auto* const file = fopen("/proc/self/statm", "r");
			if (file == nullptr)
			{
				return 0;
			}
			long pages = 0;
			const auto items = fscanf(file, "%*s%ld", &pages);
			fclose(file);
			return static_cast<std::size_t>(items == 1 ? pages * sysconf(_SC_PAGESIZE) : 0);
		}

		auto QueryCpuName()  -> std::string
		{
			std::ifstream cpuinfo("/proc/cpuinfo");

			if (!cpuinfo.is_open() || !cpuinfo)
			{
				return "Unknown";
			}

			for (std::string line; std::getline(cpuinfo, line); )
			{
				if (line.find("model name") == 0)
				{
					const auto colon_id = line.find_first_of(':');
					const auto nonspace_id = line.find_first_not_of(" \t", colon_id + 1);
					return line.c_str() + nonspace_id;
				}
			}

			return {};
		}

		auto QueryPageSize() ->std::size_t
		{
			return static_cast<std::size_t>(sysconf(_SC_PAGE_SIZE));
		}

		auto DylibOpen(const std::string_view file_)  -> void*
		{
			return ::dlopen(file_.data(), RTLD_LOCAL | RTLD_LAZY);
		}

		auto DylibLookupSymbol(void* const handle_, const std::string_view symbol_)  -> void*
		{
			return ::dlsym(handle_, symbol_.data());
		}

		auto DylibClose(void*& handle_)  -> void
		{
			::dlclose(handle_);
			handle_ = nullptr;
		}
	}

#endif

#if NOX_OS_WINDOWS

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinUser.h>
#include <Psapi.h>

	namespace Os
	{
		std::size_t QuerySystemMemoryTotal()
		{
			MEMORYSTATUSEX status;
			status.dwLength = sizeof(MEMORYSTATUSEX);
			GlobalMemoryStatusEx(&status);
			return status.ullTotalPhys;
		}

		std::size_t QueryProcessMemoryUsed()
		{
			PROCESS_MEMORY_COUNTERS pmc;
			GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof pmc);
			return pmc.WorkingSetSize;
		}

		std::string QueryCpuName()
		{
			HKEY key;
			if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, R"(HARDWARE\DESCRIPTION\System\CentralProcessor\0)", 0, KEY_READ,
			                  &key))
			{
				return "Unknown";
			}
			TCHAR id[64 + 1];
			DWORD idLen = sizeof id;
			if (const auto data = static_cast<LPBYTE>(static_cast<void*>(id)); RegQueryValueExA(
				key, "ProcessorNameString", nullptr, nullptr, data, &idLen))
			{
				return "Unknown";
			}
			return id;
		}

		std::size_t QueryPageSize()
		{
			SYSTEM_INFO sysInfo;
			GetSystemInfo(&sysInfo);
			return static_cast<std::size_t>(sysInfo.dwPageSize);
		}

		void* DylibOpen(const std::string_view filePath)
		{
			return LoadLibraryA(filePath.data());
		}

		void* DylibLookupSymbol(void* const handle, const std::string_view symbolName)
		{
			// ReSharper disable once CppRedundantCastExpression
			return reinterpret_cast<void*>(GetProcAddress(static_cast<HMODULE>(handle), symbolName.data()));
		}

		void DylibClose(void*& handle)
		{
			FreeLibrary(static_cast<HMODULE>(handle));
			handle = nullptr;
		}
	}

#endif
}
