#include <algorithm>
#include <fstream>
#include <filesystem>

#include "../../Include/Nominax/Assembler/_Assembler.hpp"
#include "../../Include/Nominax/Foundation/PanicDump.hpp"
#include "../../Include/Nominax/Foundation/PanicAssertions.hpp"
#include "../../Include/Nominax/Foundation/Stopwatch.hpp"
#include "../../Include/Nominax/Foundation/EmbeddedHTML.hpp"
#include "../../Include/Nominax/Foundation/IOStream.hpp"

namespace Nominax::Foundation
{
	using NOX_ARCH_PROXY::RegisterCache;

	auto GetPanicDumpDirName() -> std::string
	{
		std::string time { Format("{}/NominaxPanic {:%A %c}/", PANIC_OUTPUT_DIR, SafeLocalTime(std::time(nullptr))) };
		std::replace(std::begin(time), std::end(time), ':', ' ');
		return time;
	}

	// <div class="registers">%rax = 10</div>
	auto CreatePanicDump
	(
		const std::string_view message,
		const Foundation::SourceLocation& srcLoc,
		const void* const regCache,
		const std::string& directory
	) -> void
	{
		if constexpr (!ENABLE_PANIC_DUMPS)
		{
			return;
		}

		if (!std::filesystem::create_directory(PANIC_OUTPUT_DIR) || !std::filesystem::create_directory(directory))
		{
			[[unlikely]]
			return;
		}

		namespace HTML = EmbeddedHTML::Panic;

		{
			[[maybe_unused]]
			const auto& regs { *static_cast<const NOX_ARCH_PROXY::RegisterCache*>(regCache) };
		}

		{
			std::ofstream htmlFile { directory + "index.html" };
			if (!htmlFile)
			{
				[[unlikely]]
				return;
			}

			std::string html { HTML::HTML };
			html.replace(html.find(HTML::FMT_FILE), std::size(HTML::FMT_FILE), srcLoc.GetFileName());
			html.replace(html.find(HTML::FMT_LINE), std::size(HTML::FMT_LINE), Format("{}", srcLoc.GetLine()));
			html.replace(html.find(HTML::FMT_ROUTINE), std::size(HTML::FMT_ROUTINE), srcLoc.GetFunctionName());
			html.replace(html.find(HTML::FMT_MESSAGE), std::size(HTML::FMT_MESSAGE), message);

			htmlFile << html;
		}
		{
			std::ofstream cssFile { directory + "style.css" };
			if (!cssFile)
			{
				[[unlikely]]
				return;
			}
			cssFile << HTML::CSS;
		}
	}
}
