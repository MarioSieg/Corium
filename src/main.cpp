#include <iostream>
#include <string_view>
#include <thread>

#include "../inc/nominax/info.hpp"
#include "../inc/nominax/platform.hpp"

using std::cout;
using std::cerr;
using std::endl;

auto main() -> int
try {

	std::ios_base::sync_with_stdio(false);

	cout << nominax::logo;
	cout << nominax::info_notice;

	cout << "Nominax Version: " << nominax::system_version;
	cout << "\nPlatform: " NOMINAX_OS_NAME " " NOMINAX_ARCH_SIZE_NAME;
	cout << "\nArch: " << NOMINAX_ARCH_NAME;
	cout << "\nPosix: " << std::boolalpha << NOMINAX_POSIX;
	cout << "\nCompiler: " << NOMINAX_COM_NAME " - C++ 20";
	
	cout << "\n\nBooting runtime system...";
	cout << "\nTID: 0x" << std::hex << std::this_thread::get_id() << std::dec;

	const auto threads = std::thread::hardware_concurrency();
	cout << "\nThreads: " << threads;
	cout << "\nMachine class: ";

	if (threads <= 2) [[unlikely]] {
		cout << 'F';
	} else if (threads <= 4) [[unlikely]] {
		cout << 'E';
	} else if (threads <= 8) [[likely]] {
		cout << 'D';
	} else if (threads <= 16) [[likely]] {
		cout << 'C';
	} else if (threads <= 32) [[likely]] {
		cout << 'B';
	} else [[likely]] {
		cout << 'A';
	}
	cout << '\n';
}
catch (const std::exception& ex) {
	cerr << "[!] Fatal system exception: " << ex.what() << endl;
}
catch (...) {
	cerr << "[!] Unknown system error!" << endl;
}