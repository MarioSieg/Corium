// Nominax Runtime System
// Copyright (c) 2021 Mario Sieg <mt3000@gmx.de>, Germany
// See README.md and LICENSE!

#include <array>
#include <chrono>
#include <iostream>
#include <string_view>
#include <thread>
#include <vector>

using namespace std;

constexpr array<array<string_view, 2>, 2> Commands = {
	array<string_view, 2>{"-silent", "Disables any logging messages from Nominax"},
	array<string_view, 2>{"-nosplash", "Disables the splash logo"}
};

constexpr string_view Logo = R"(
 _        _______  _______ _________ _        _______          
( (    /|(  ___  )(       )\__   __/( (    /|(  ___  )|\     /|
|  \  ( || (   ) || () () |   ) (   |  \  ( || (   ) |( \   / )
|   \ | || |   | || || || |   | |   |   \ | || (___) | \ (_) / 
| (\ \) || |   | || |(_)| |   | |   | (\ \) ||  ___  |  ) _ (  
| | \   || |   | || |   | |   | |   | | \   || (   ) | / ( ) \ 
| )  \  || (___) || )   ( |___) (___| )  \  || )   ( |( /   \ )
|/    )_)(_______)|/     \|\_______/|/    )_)|/     \||/     \|
)";

auto main(const signed argc, const char* const* const argv) -> signed {

	vector<string_view> args(argv + 1, argv + argc);

	auto isArgSet = [&args](const std::string_view arg) -> bool {
		return std::find(args.begin(), args.end(), arg) != args.end();
	};

	ios_base::sync_with_stdio(false);

	// -nosplash
	if (!isArgSet(Commands[1][0])) [[unlikely]]
		cout << Logo;

	// -silent
	if (!isArgSet(Commands[0][0])) [[unlikely]] {
		cout << "Nominax Runtime\n";
		cout << "(c) Copyright Mario Sieg <mt3000@gmx.de>, Germany 2019-2021!\n";

		auto time = chrono::system_clock::to_time_t(chrono::system_clock::now());
		cout << ctime(&time);

		const auto threads = thread::hardware_concurrency();
		cout << "Hardware Concurrency: " << threads << '\n';
		cout << "Machine Class: ";
		if (threads <= 2)		cout << 'F';
		else if (threads <= 4)	cout << 'E';
		else if (threads <= 8)	cout << 'D';
		else if (threads <= 16) cout << 'C';
		else if (threads <= 32) cout << 'B';
		else					cout << 'A';

		if (threads <= 8) [[unlikely]]
			cout << "Warning! Low end machine, performance might suffer!\n";

		cout << '\n';

		cout << "Executing...\n";
		cout << "================================================================\n\n";
	}
	
	return 0;
}