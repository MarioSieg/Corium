#include "../inc/nominax/environment.hpp"
#include "../inc/nominax/info.hpp"
#include "../inc/nominax/memunits.hpp"
#include "../inc/nominax/os.hpp"

#include <iostream>
#include <thread>

using std::cout;
using std::cerr;

namespace nominax {
	auto environment::boot() -> bool {
		try {
			std::ios_base::sync_with_stdio(false);

			this->log << logo;
			this->log << info_notice;

			this->log << "Nominax Version: " << system_version;
			this->log << "\nPlatform: " NOMINAX_OS_NAME " " NOMINAX_ARCH_SIZE_NAME;
			this->log << "\nArch: " << NOMINAX_ARCH_NAME;
			this->log << "\nPosix: " << std::boolalpha << NOMINAX_POSIX;
			this->log << "\nCompiler: " << NOMINAX_COM_NAME " - C++ 20";

			this->log << "\n\nBooting runtime system...";

			this->thread_count = std::thread::hardware_concurrency();
			this->total_memory_ = os::query_system_memory_total();
			this->available_memory_ = os::query_system_memory_total() - os::query_process_memory_used();
			this->cpu_name_ = os::cpu_name();

			this->log << "\nTID: 0x" << std::hex << std::this_thread::get_id() << std::dec;

			this->log << "\nCPU: " << this->cpu_name_;
			this->log << "\nCPU Threads: " << this->thread_count;
			this->log << "\nCPU Machine class: ";

			if (this->thread_count <= 2) {
				this->log << 'F';
			}
			else if (this->thread_count <= 4) {
				this->log << 'E';
			}
			else if (this->thread_count <= 8) {
				this->log << 'D';
			}
			else if (this->thread_count <= 16) {
				this->log << 'C';
			}
			else if (this->thread_count <= 32) {
				this->log << 'B';
			}
			else {
				this->log << 'A';
			}

			this->log << "\nTotal RAM: " << b2gb(this->total_memory_) << " GB";
			this->log << "\nAvailable RAM: " << b2kb(this->available_memory_) << " KB";

			return true;
		}
		catch (const std::exception& ex) {
			this->err << "[!] Fatal system exception: " << ex.what() << std::endl;
			return false;
		}
		catch (...) {
			this->err << "[!] Unknown system error!" << std::endl;
			return false;
		}
	}
}
