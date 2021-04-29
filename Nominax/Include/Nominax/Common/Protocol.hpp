#pragma once

/* 
* Currently (29.04.2012) only the MSVC standard library for
* C++ 20 contains the <format> implementation. Since we use Clang and GCC
* we use the format libary until the standart implementations are available.
* For that we have custom prin functions below, do not use fmt::* directly,
* because then if the standard library is ready, we can just replace the calls
* inside our custom print function below and remove the fmt library.
*/

#include <fmt/format.h>
#include <fmt/chrono.h>

namespace Nominax
{
	/// <summary>
	/// Prints out the formating string and
	/// formats the arguments into the string if format
	/// arguments are given.
	/// The formatting rules follow the C++ 20 <format> convention.
	/// All printing inside Nominax should be done via this functions
	/// and friends because it also allows different configurations.
	/// </summary>
	/// <typeparam name="Str">The string type.</typeparam>
	/// <typeparam name="...Args">The argument types.</typeparam>
	/// <param name="formatString">The format string.</param>
	/// <param name="...args">The arguments to format.</param>
	template <typename Str, typename... Args>
	inline auto Print(const Str& formatString, Args&&... args) -> void 
	{
		fmt::print(formatString, std::forward<Args>(args)...);
	}
}
