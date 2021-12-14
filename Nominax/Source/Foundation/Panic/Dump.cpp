#include <algorithm>
#include <fstream>
#include <filesystem>

#include "../../../Include/Nominax/Assembler/_Assembler.hpp"
#include "../../../Include/Nominax/Foundation/Panic/Dump.hpp"
#include "../../../Include/Nominax/Foundation/Stopwatch.hpp"
#include "../../../Include/Nominax/Foundation/EmbeddedHTML.hpp"

namespace Nominax::Foundation::Panic
{
	using NOX_ARCH_PROXY::RegisterCache;

	auto GetPanicDumpDirName() -> std::string
	{
		std::string time { Format("{}/NominaxPanic {:%A %c}/", PANIC_OUTPUT_DIR, SafeLocalTime(std::time(nullptr))) };
		std::ranges::replace(time, ':', ' ');
		return time;
	}

	auto CreatePanicDump
	(
		const std::string_view message,
		const SourceLocation& srcLoc,
		const void* const regCache,
		const std::string& directory
	) -> void
	{
		if constexpr (!ENABLE_PANIC_DUMPS)
		{
			return;
		}

		std::filesystem::create_directory(PANIC_OUTPUT_DIR);

		if (!std::filesystem::create_directory(directory))
		{
			[[unlikely]]
			return;
		}

		namespace HTML = EmbeddedHTML::Panic;

		std::vector<std::pair<std::string, std::string>> registers { };

		if (regCache) [[likely]]
		{
			{
				const auto& regs { *static_cast<const NOX_ARCH_PROXY::RegisterCache*>(regCache) };
				std::ofstream regFile { directory + "RegisterDump.txt" };
				if (regFile) [[likely]]
				{
					regs.Display(regFile);
				}
			}
			std::ifstream i { directory + "RegisterDump.txt" };
			std::vector<std::string> lines { };
			for (std::string tmp { }; std::getline(i, tmp); )
			{
				lines.emplace_back(std::move(tmp));
			}
			registers.reserve(std::size(lines));

			for (const std::string& line : lines)
			{
				std::string registerName { }, registerValue { };
				constexpr char delim { '=' };
				std::stringstream lineStream { line };
				std::getline(lineStream, registerName, delim);
				std::getline(lineStream, registerValue, delim);
				registers.emplace_back(std::make_pair(std::move(registerName), std::move(registerValue)));
			}
		}
		
		{
			std::ofstream htmlFile { directory + "index.html" };
			if (!htmlFile)
			{
				[[unlikely]]
				return;
			}

			std::stringstream registerHTML { };
			for (const auto& [reg, val] : registers)
			{
				registerHTML << R"(<tr><td class="bold">)" << reg << "</td><td>" << val << "</td></tr>";
			}

			std::string html { HTML::HTML };
			html.replace(html.find(HTML::FMT_FILE), std::size(HTML::FMT_FILE), srcLoc.GetFileName());
			html.replace(html.find(HTML::FMT_LINE), std::size(HTML::FMT_LINE), Format("{}", srcLoc.GetLine()));
			html.replace(html.find(HTML::FMT_ROUTINE), std::size(HTML::FMT_ROUTINE), srcLoc.GetFunctionName());
			html.replace(html.find(HTML::FMT_MESSAGE), std::size(HTML::FMT_MESSAGE), message);
			html.replace(html.find(HTML::FMT_REGISTERS), std::size(HTML::FMT_REGISTERS), registerHTML.str());

			htmlFile << html;
		}
	}
}
