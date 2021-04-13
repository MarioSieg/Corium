#pragma once

#include "bytecode.hpp"

namespace nominax {
	enum class alignas(alignof(opcode)) intrinsic: opcode {
		cos			= 0x00'00'00'00'00'00'00'00,
		sin			= 0x00'00'00'00'00'00'00'01,
		tan			= 0x00'00'00'00'00'00'00'02,
		acos		= 0x00'00'00'00'00'00'00'03,
		asin		= 0x00'00'00'00'00'00'00'04,
		atan		= 0x00'00'00'00'00'00'00'05,
		atan2		= 0x00'00'00'00'00'00'00'06,
		cosh		= 0x00'00'00'00'00'00'00'07,
		sinh		= 0x00'00'00'00'00'00'00'08,
		tanh		= 0x00'00'00'00'00'00'00'09,
		acosh		= 0x00'00'00'00'00'00'00'0A,
		asinh		= 0x00'00'00'00'00'00'00'0B,
		atanh		= 0x00'00'00'00'00'00'00'0C,
		exp			= 0x00'00'00'00'00'00'00'0D,
		log			= 0x00'00'00'00'00'00'00'0E,
		log10		= 0x00'00'00'00'00'00'00'0F,
		exp2		= 0x00'00'00'00'00'00'00'10,
		ilogb		= 0x00'00'00'00'00'00'00'11,
		log2		= 0x00'00'00'00'00'00'00'12,
		pow			= 0x00'00'00'00'00'00'00'13,
		sqrt		= 0x00'00'00'00'00'00'00'14,
		cbrt		= 0x00'00'00'00'00'00'00'15,
		hypot		= 0x00'00'00'00'00'00'00'16,
		ceil		= 0x00'00'00'00'00'00'00'17,
		floor		= 0x00'00'00'00'00'00'00'18,
		round		= 0x00'00'00'00'00'00'00'19,
		rint		= 0x00'00'00'00'00'00'00'1A,
		max			= 0x00'00'00'00'00'00'00'1B,
		min			= 0x00'00'00'00'00'00'00'1C,
		fmax		= 0x00'00'00'00'00'00'00'1D,
		fmin		= 0x00'00'00'00'00'00'00'1E,
		fdim		= 0x00'00'00'00'00'00'00'1F,
		abs			= 0x00'00'00'00'00'00'00'20,
		fabs		= 0x00'00'00'00'00'00'00'21,

		/* !no intrinsic routine - count of total intrinsic routines! */
		count_
	};
}