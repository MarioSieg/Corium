#include "../inc/nominax/os.hpp"
#include "../inc/nominax/platform.hpp"

#if NOMINAX_OS_ANDROID

#include <malloc.h>
#include <unistd.h>

namespace nominax::os {
	auto query_system_memory_total() -> std::size_t {
		const long pages = sysconf(_SC_PHYS_PAGES);
		const long page_size = sysconf(_SC_PAGE_SIZE);
		return static_cast<std::size_t>(pages * page_size);
	}

	auto query_process_memory_used() -> std::size_t {
		const struct mallinfo mi = mallinfo();
		return mi.uordblks;
	}

	auto dylib_open(const std::string_view file_) -> void* {
		return ::dlopen(file_.data(), RTLD_LOCAL | RTLD_LAZY);
	}

	auto dylib_lookup_symbol(void* const handle_, const std::string_view symbol_) -> void* {
		return ::dlsym(handle_, symbol_);
	}

	void dylib_close(void*& handle_) {
		::dlclose(handle_);
		handle_ = nullptr;
	}
}

#endif
