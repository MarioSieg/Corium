#include "../Include/Nominax/Environment.hpp"
#include "../Include/Nominax/Info.hpp"
#include "../Include/Nominax/MemoryUnits.hpp"
#include "../Include/Nominax/Os.hpp"

#include <iostream>
#include <thread>

using std::cout;
using std::cerr;

namespace Nominax {
	auto Environment::BootEnvironment() -> bool {
		try {
			std::ios_base::sync_with_stdio(false);

			this->Logger << logo;
			this->Logger << info_notice;

			this->Logger << "Nominax Version: " << system_version;
			this->Logger << "\nPlatform: " NOMINAX_OS_NAME " " NOMINAX_ARCH_SIZE_NAME;
			this->Logger << "\nArch: " << NOMINAX_ARCH_NAME;
			this->Logger << "\nPosix: " << std::boolalpha << NOMINAX_POSIX;
			this->Logger << "\nCompiler: " << NOMINAX_COM_NAME " - C++ 20";

			this->Logger << "\n\nBooting runtime system...";

			this->ThreadCount= std::thread::hardware_concurrency();
			this->TotalMemory = OS::query_system_memory_total();
			this->AvailableMemory = OS::query_system_memory_total() - OS::query_process_memory_used();
			this->CpuName = OS::cpu_name();

			this->Logger << "\nTID: 0x" << std::hex << std::this_thread::get_id() << std::dec;

			this->Logger << "\nCPU: " << this->CpuName;
			this->Logger << "\nCPU Threads: " << this->ThreadCount;
			this->Logger << "\nCPU Machine class: ";

			if (this->ThreadCount <= 2) {
				this->Logger << 'F';
			}
			else if (this->ThreadCount <= 4) {
				this->Logger << 'E';
			}
			else if (this->ThreadCount <= 8) {
				this->Logger << 'D';
			}
			else if (this->ThreadCount <= 16) {
				this->Logger << 'C';
			}
			else if (this->ThreadCount <= 32) {
				this->Logger << 'B';
			}
			else {
				this->Logger << 'A';
			}

			this->Logger << "\nTotal RAM: " << b2gb(this->TotalMemory) << " GB";
			this->Logger << "\nAvailable RAM: " << b2kb(this->AvailableMemory) << " KB";

			return true;
		}
		catch (const std::exception& ex) {
			this->ErrorLogger << "[!] Fatal system exception: " << ex.what() << std::endl;
			return false;
		}
		catch (...) {
			this->ErrorLogger << "[!] Unknown system error!" << std::endl;
			return false;
		}
	}
}
