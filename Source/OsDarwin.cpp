#include "../Include/Nominax/Os.hpp"
#include "../Include/Nominax/Platform.hpp"

#if NOMINAX_OS_MAC || NOMINAX_OS_IOS

#include <unistd.h>
#include <mach/mach.h>
#include <mach/mach_host.h>

namespace Nominax::os {
	auto query_system_memory_total() -> std::size_t {
		mach_port_t host_port;
		mach_msg_type_number_t host_size;
		vm_size_t pagesize;
		host_port = mach_host_self();
		host_size = sizeof(vm_statistics_data_t) / sizeof(integer_t);
		host_page_size(host_port, &pagesize);
		vm_statistics_data_t vm_stat;
		if (host_statistics(host_port, HOST_VM_INFO, (host_info_t)&vm_stat, &host_size) != KERN_SUCCESS) [[unlikely]] {
			return 0;
		}
		natural_t mem_used = (vm_stat.active_count + vm_stat.inactive_count + vm_stat.wire_count) * pagesize;
		natural_t mem_free = vm_stat.free_count * pagesize;
		natural_t mem_total = mem_used + mem_free;
		return static_cast<std::size_t>(mem_total);
	}

	auto query_process_memory_used() -> std::size_t {
	#ifdef MACH_TASK_BASIC_INFO
		mach_task_basic_info info;
		mach_msg_type_number_t info_count = MACH_TASK_BASIC_INFO_COUNT;
		const int result = task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info, &info_count);
	#else
		task_basic_info info;
		mach_msg_type_number_t info_count = TASK_BASIC_INFO_COUNT;
		const int result = task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&info, &info_count);
	#endif
		if (result != KERN_SUCCESS) [[unlikely]] {
			return 0;
		}

		return info.resident_size;
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
