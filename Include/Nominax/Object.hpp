#pragma once

#include <cstdint>

namespace Nominax
{
	/* 
	* Every heap allocated object has an object header.
	* The object header contains various meta data about the object.
	* Each object header field is 32-bits wide.
	* 
	* Offset	   Description			Size
	*		+---------------------+
	*	0	|	 Strong Ref Count |		32 Bit
	*		+---------------------+
	*	1	|    Weak Ref Count   |		32 Bit
	*		+---------------------+
	*	2	|      Type ID        |		32 Bit
	*		+---------------------+
	*	3	|     Flag Vector     |		32 Bit
	*		+---------------------+
	* Total size: 128 Bit (16 Bytes)
	*/

	struct ObjectFlagsCompound final
	{
		bool Flag0 : 1;
		bool Flag1 : 1;
		bool Flag2 : 1;
		bool Flag3 : 1;
		bool Flag4 : 1;
		bool Flag5 : 1;
		bool Flag6 : 1;
		bool Flag7 : 1;
		bool Flag8 : 1;
		bool Flag9 : 1;
		bool Flag10 : 1;
		bool Flag11 : 1;
		bool Flag12 : 1;
		bool Flag13 : 1;
		bool Flag14 : 1;
		bool Flag15 : 1;
		bool Flag16 : 1;
		bool Flag17 : 1;
		bool Flag18 : 1;
		bool Flag19 : 1;
		bool Flag20 : 1;
		bool Flag21 : 1;
		bool Flag22 : 1;
		bool Flag23 : 1;
		bool Flag24 : 1;
		bool Flag25 : 1;
		bool Flag26 : 1;
		bool Flag27 : 1;
		bool Flag28 : 1;
		bool Flag29 : 1;
		bool Flag30 : 1;
		bool Flag31 : 1;
	};

	static_assert(sizeof(FlagVector) == sizeof(std::uint32_t);

	struct ObjectHeader final 
	{
		std::uint32_t StrongRefCount {0};
		std::uint32_t WeakRefCount {0};
		std::uint32_t TypeId {0};
		ObjectFlagsCompound FlagVector {0};
	};
}