#include "Literal.hpp"

namespace Corium
{
	auto ConvertFloatLiteral(const std::string_view text) -> std::optional<F64>
	{
		F64 output {};		
		const auto [ptr, ec] { std::from_chars(std::begin(text), std::end(text), output, FLOAT_FORMAT) };
		return ec == std::errc() && ptr == std::end(text) ? std::optional{ output } : std::optional<F64>{ std::nullopt };
	}
	
	auto ConvertIntLiteral(const std::string_view text, const Radix radix) -> std::optional<I64>
	{
		I64 output{};
		const auto [ptr, ec] { std::from_chars(std::begin(text), std::end(text), output, static_cast<std::underlying_type_t<Radix>>(radix)) };
		return ec == std::errc() && ptr == std::end(text) ? std::optional{ output } : std::optional<I64>{ std::nullopt };
	}
}
