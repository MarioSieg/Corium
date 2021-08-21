#pragma once

#include <cstdint>

namespace Nominax::Foundation
{
	enum class MemoryPageProtectionFlags : std::uint8_t
	{
		NoAccess,
		Read,
		ReadWrite,
		ReadExecute,
		ReadWriteExecute
	};
}
