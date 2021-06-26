#pragma once

#include <charconv>
#include <string_view>
#include <variant>

#include "Base.hpp"

namespace Corium
{
	/// <summary>
	/// Represents a literal such as 10 or 3.14
	/// </summary>
	using Literal = std::variant<I64, F64>;

	/// <summary>
	/// Separator used for floats.
	/// </summary>
	constexpr char FLOAT_SEPARATOR{ '.' };

	/// <summary>
	/// Contains all radix for supported number systems.
	/// </summary>
	enum class Radix: I32
	{
		Bin = 2,
		Oct = 8,
		Dec = 10,
		Hex = 16,
	};

	/// <summary>
	/// Formatting flags for string to float conversion.
	/// </summary>
	constexpr std::chars_format FLOAT_FORMAT
	{
		std::chars_format::fixed
		| std::chars_format::general
		| std::chars_format::scientific
	};

	/// <summary>
	/// Contains all types which can be estimated from a literal.
	/// </summary>
	enum class EstimatedLiteralType
	{
		Int,
		Float
	};

	/// <summary>
	/// Determines the literal type of the text.
	/// </summary>
	/// <param name="text"></param>
	/// <returns></returns>
	inline auto DetermineLiteralType(const std::string_view text) -> EstimatedLiteralType
	{
		return
			text.find(FLOAT_SEPARATOR)
			== std::string_view::npos
			? EstimatedLiteralType::Int
			: EstimatedLiteralType::Float;
	}
	
	/// <summary>
	/// Tries to convert the text to a valid float.
	/// </summary>
	/// <param name="text">The text representing the number.</param>
	/// <returns>The float value on success, else nullopt.</returns>
	extern auto ConvertFloatLiteral(std::string_view text) -> std::optional<F64>;

	/// <summary>
	/// Tries to convert the text to a valid integer.
	/// </summary>
	/// <param name="text">The text representing the number.</param>
	/// <param name="radix">The radix (base) of the number to be used for conversion.</param>
	/// <returns>The integer value on success, else nullopt.</returns>
	extern auto ConvertIntLiteral(std::string_view text, Radix radix = Radix::Dec) -> std::optional<I64>;
}
