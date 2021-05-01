#pragma once

#include <string_view>

namespace Nominax
{
	/// <summary>
	/// Shows a message error box with the specified message and calls std::abort.
	/// This function never returns because the program will be terminated.
	/// </summary>
	/// <param name="message"></param>
	/// <returns></returns>
	[[noreturn]]
	extern auto Panic(std::string_view message) -> void;
}

#define NOMINAX_PANIC_ASSERT_TRUE(x, msg)			\
	do												\
	{												\
		if (__builtin_expect(!( x ), 0))			\
		{											\
			Panic(( msg ));							\
		}											\
	}												\
	while(false)

#define NOMINAX_PANIC_ASSERT_FALSE(x, msg)			\
	do												\
	{												\
		if (__builtin_expect(( x ), 0))				\
		{											\
			Panic(( msg ));							\
		}											\
	}												\
	while(false)

#define NOMINAX_PANIC_ASSERT_NULL(x, msg)			\
	NOMINAX_PANIC_ASSERT_FALSE(x, msg)

#define NOMINAX_PANIC_ASSERT_NOT_NULL(x, msg)		\
	NOMINAX_PANIC_ASSERT_TRUE(x, msg)

#define NOMINAX_PANIC_ASSERT_EQ(x, y, msg)			\
	do												\
	{												\
		if (__builtin_expect(( x ) != ( y ), 0))	\
		{											\
			Panic(( msg ));							\
		}											\
	}												\
	while(false)


#define NOMINAX_PANIC_ASSERT_NE(x, y, msg)			\
	do												\
	{												\
		if (__builtin_expect(( x ) == ( y ), 0))	\
		{											\
			Panic(( msg ));							\
		}											\
	}												\
	while(false)

#define NOMINAX_PANIC_ASSERT_L(x, y, msg)			\
	do												\
	{												\
		if (__builtin_expect(!(( x ) < ( y )), 0))	\
		{											\
			Panic(( msg ));							\
		}											\
	}												\
	while(false)

#define NOMINAX_PANIC_ASSERT_LE(x, y, msg)			\
	do												\
	{												\
		if (__builtin_expect(!(( x ) <= ( y )), 0))	\
		{											\
			Panic(( msg ));							\
		}											\
	}												\
	while(false)

#define NOMINAX_PANIC_ASSERT_G(x, y, msg)			\
	do												\
	{												\
		if (__builtin_expect(!(( x ) > ( y )), 0))	\
		{											\
			Panic(( msg ));							\
		}											\
	}												\
	while(false)

#define NOMINAX_PANIC_ASSERT_GE(x, y, msg)			\
	do												\
	{												\
		if (__builtin_expect(!(( x ) >= ( y )), 0))	\
		{											\
			Panic(( msg ));							\
		}											\
	}												\
	while(false)
