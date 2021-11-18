#include "../TestBase.hpp"
#include "../../../Nominax/Include/Nominax/FFI/NominaxFFI.h"

static_assert(sizeof(NOX_Signal) == sizeof(Signal));
static_assert(alignof(NOX_Signal) == alignof(Signal));
static_assert(std::is_trivial_v<NOX_Signal>);

static_assert(sizeof(NOX_Record) == sizeof(Record));
static_assert(alignof(NOX_Record) == alignof(Record));
static_assert(std::is_trivial_v<NOX_Record>);

NOX_FFI_NATIVE_CALL_DECL(Test, sp);

NOX_FFI_NATIVE_CALL_IMPL(Test, sp)
{
	const union NOX_Record x { NOX_LDA(sp, 1) };
	Print("{}\n", x.AsF32);
	return sp;
}
