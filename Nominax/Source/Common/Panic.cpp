#include "../../Include/Nominax/Common/PanicRoutine.hpp"
#include "../../Include/Nominax/System/Os.hpp"

namespace Nominax
{
	auto Panic(const std::string_view message) -> void
	{
		Os::ShowMessageBox(message, "Nominax Runtime Error", MessageBoxStyle::Error, MessageBoxButtons::Ok);
		std::abort();
	}
}