#include "../Include/Nominax/Os.hpp"
#include "../Include/Nominax/Platform.hpp"

#if NOMINAX_OS_LINUX

#include <cstdio>
#include <fstream>
#include <dlfcn.h>
#include <unistd.h>

namespace Nominax::os {
	auto query_system_memory_total() -> std::size_t {
		const long pages = sysconf(_SC_PHYS_PAGES);
		const long page_size = sysconf(_SC_PAGE_SIZE);
		return static_cast<std::size_t>(pages * page_size);
	}

	auto query_process_memory_used() -> std::size_t {
		auto* const file = fopen("/proc/self/statm", "r");
		if (file == nullptr) [[unlikely]] {
			return 0;
		}
		long pages = 0;
		const auto items = fscanf(file, "%*s%ld", &pages);
		fclose(file);
		return static_cast<std::size_t>(items == 1 ? pages * sysconf(_SC_PAGESIZE) : 0);
	}

	auto cpu_name() -> std::string {
		std::ifstream cpuinfo("/proc/cpuinfo");

		if (!cpuinfo.is_open() || !cpuinfo) [[unlikely]] {
			return "Unknown";
		}

		for (std::string line; std::getline(cpuinfo, line); ) [[likely]] {
			if (line.find("model name") == 0) [[likely]] {
				const auto colon_id = line.find_first_of(':');
				const auto nonspace_id = line.find_first_not_of(" \t", colon_id + 1);
				return line.c_str() + nonspace_id;
			}
		}

		return {};
	}

	auto dylib_open(const std::string_view file_) -> void* {
		return ::dlopen(file_.data(), RTLD_LOCAL | RTLD_LAZY);
	}

	auto dylib_lookup_symbol(void* const handle_, const std::string_view symbol_) -> void* {
        return ::dlsym(handle_, symbol_.data());
	}

	void dylib_close(void*& handle_) {
		::dlclose(handle_);
		handle_ = nullptr;
	}
}

#endif
