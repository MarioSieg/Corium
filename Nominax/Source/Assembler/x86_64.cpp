#include "../../Include/Nominax/Assembler/x86_64.hpp"
#include "../../Include/Nominax/Common/PanicRoutine.hpp"

namespace Nominax::Assembler::X86_64
{
	auto InjectNopChain(U8* n, const U8 size) -> void
	{
		NOMINAX_PANIC_ASSERT_NOT_NULL(n, "Null needle!");
		NOMINAX_PANIC_ASSERT_LE(size, 15, "Invalid nop chain size!");
		NOMINAX_PANIC_ASSERT_GE(size, 1, "Invalid nop chain size!");
		
		static constexpr std::array<const void* NOX_RESTRICT const, 15> JUMP_TABLE
		{
			&&inject_1,
			&&inject_2,
			&&inject_3,
			&&inject_4,
			&&inject_5,
			&&inject_6,
			&&inject_7,
			&&inject_8,
			&&inject_9,
			&&inject_10,
			&&inject_11,
			&&inject_12,
			&&inject_13,
			&&inject_14,
			&&inject_15
		};

		goto *JUMP_TABLE[size - 1];
		
		inject_1:
			*n = 0x90;
			return;

		inject_2:
			*n = 0x40;
			*++n = 0x90;
			return;

		inject_3:
			*n = 0x0F;
			*++n = 0x1F;
			*++n = 0x00;
			return;

		inject_4:
			*n = 0x0F;
			*++n = 0x1F;
			*++n = 0x40;
			*++n = 0x00;
			return;

		inject_5:
			*n = 0x0F;
			*++n = 0x1F;
			*++n = 0x44;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_6:
			*n = 0x66;
			*++n = 0x0F;
			*++n = 0x1F;
			*++n = 0x44;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_7:
			*n = 0x0F;
			*++n = 0x1F;
			*++n = 0x80;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_8:
			*n = 0x0F;
			*++n = 0x1F;
			*++n = 0x84;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_9:
			*n = 0x66;
			*++n = 0x0F;
			*++n = 0x1F;
			*++n = 0x84;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_10:
			*n = 0x66;
			*++n = 0x2E;
			*++n = 0x0F;
			*++n = 0x1F;
			*++n = 0x84;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_11:
			*n = 0x66;
			*++n = 0x66;
			*++n = 0x2E;
			*++n = 0x0F;
			*++n = 0x1F;
			*++n = 0x84;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_12:
			*n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x2E;
			*++n = 0x0F;
			*++n = 0x1F;
			*++n = 0x84;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_13:
			*n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x2E;
			*++n = 0x0F;
			*++n = 0x1F;
			*++n = 0x84;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_14:
			*n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x2E;
			*++n = 0x0F;
			*++n = 0x1F;
			*++n = 0x84;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			return;

		inject_15:
			*n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x66;
			*++n = 0x2E;
			*++n = 0x0F;
			*++n = 0x1F;
			*++n = 0x84;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			*++n = 0x00;
			return;
	}
}
