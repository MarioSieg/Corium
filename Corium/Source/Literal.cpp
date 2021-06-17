#include "Literal.hpp"

namespace Corium
{
	auto ConvertFloatLiteral(const std::u8string_view text) -> std::optional<F64>
	{
		static_assert(sizeof(char) == sizeof(char8_t));
		const char* const begin{ reinterpret_cast<const char*>(std::data(text)) };
		const char* const end{ reinterpret_cast<const char*>(std::data(text) + std::size(text)) };
		F64 output {};		
		const auto [ptr, ec] { std::from_chars(begin, end, output, FLOAT_FORMAT) };
		return ec == std::errc() && ptr == end ? std::optional{ output } : std::optional<F64>{ std::nullopt };
	}
	
	auto ConvertIntLiteral(const std::u8string_view text, const Radix radix) -> std::optional<I64>
	{
		static_assert(sizeof(char) == sizeof(char8_t));
		const char* const begin{ reinterpret_cast<const char*>(std::data(text)) };
		const char* const end{ reinterpret_cast<const char*>(std::data(text) + std::size(text)) };
		I64 output{};
		const auto [ptr, ec] { std::from_chars(begin, end, output, static_cast<std::underlying_type_t<Radix>>(radix)) };
		return ec == std::errc() && ptr == end ? std::optional{ output } : std::optional<I64>{ std::nullopt };
	}
}
