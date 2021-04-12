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
	cout << "\nBooting runtime system...";
}
catch (const std::exception& ex) {
	cerr << "[!] Fatal system exception: " << ex.what() << endl;
}
catch (...) {
	cerr << "[!] Unknown system error!" << endl;
}