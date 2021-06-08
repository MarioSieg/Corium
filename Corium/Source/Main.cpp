#include "Parser.hpp"

auto main([[maybe_unused]] const signed argc, [[maybe_unused]] const char* const* const argv) -> signed
{
	const char* const path{ "../../../Corium/Docs/ParseTest.cor" };

	Nominax::Common::TextFile file{};
	file.ReadFromFileOrPanic(path);
	Corium::ParseFile(std::move(file));
	
	return 0;
}
