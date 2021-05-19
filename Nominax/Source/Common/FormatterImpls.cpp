#include "../../Include/Nominax/Common/FormatterImpls.hpp"
#include "../../Include/Nominax/ByteCode/ByteCode.hpp"

using namespace fmt;
using namespace Nominax;

auto formatter<Instruction, char, void>::format(const Instruction& value,
	format_context& ctx) noexcept(false) -> FormatOutput
{
	return format_to
	(
		ctx.out(),
		"{}",
		INSTRUCTION_MNEMONICS[static_cast<std::underlying_type_t<std::remove_reference_t<decltype(value)>>>(value)]
	);
}

auto formatter<SystemIntrinsicCallId, char, void>::format(const Nominax::SystemIntrinsicCallId& value,
	format_context& ctx) noexcept(false) -> FormatOutput
{
	return format_to
	(
		ctx.out(),
		"{}{}{:#X}",
		Lexemes::INTRINSIC_CALL_IMMEDIATE,
		Lexemes::IMMEDIATE,
		static_cast<std::underlying_type_t<std::remove_reference_t<decltype(value)>>>(value)
	);
}

auto formatter<CustomIntrinsicCallId, char, void>::format(const Nominax::CustomIntrinsicCallId& value,
	format_context& ctx) noexcept(false) -> FormatOutput
{
	return format_to
	(
		ctx.out(),
		"{}{}{:#X}",
		Lexemes::INTRINSIC_CALL_IMMEDIATE,
		Lexemes::IMMEDIATE,
		static_cast<std::underlying_type_t<std::remove_reference_t<decltype(value)>>>(value)
	);
}

auto formatter<JumpAddress, char, void>::format(const Nominax::JumpAddress& value,
	format_context& ctx) noexcept(false) -> FormatOutput
{
	return format_to
	(
		ctx.out(), "{}{}{:#X}",
		Lexemes::JUMP_ADDRESS,
		Lexemes::IMMEDIATE,
		static_cast<std::underlying_type_t<std::remove_reference_t<decltype(value)>>>(value)
	);
}

auto formatter<CharClusterUtf8, char, void>::format(const Nominax::CharClusterUtf8& value,
	format_context& ctx) noexcept(false) -> FormatOutput
{
	const auto begin{ reinterpret_cast<const char*>(&*std::begin(value.Chars)) };
	const auto end{ reinterpret_cast<const char*>(&*std::end(value.Chars)) };
	std::array<char, sizeof(CharClusterUtf8)> copy{};
	std::copy(begin, end, std::begin(copy));
	for (auto& c : copy)
	{
		if (NOMINAX_UNLIKELY(std::iscntrl(c)))
		{
			c = '?';
		}
	}
	const std::string_view chars{std::begin(copy), std::end(copy)};
	return format_to
	(
		ctx.out(),
		"{}",
		chars,
		Lexemes::IMMEDIATE,
		Lexemes::LITERAL_SUFFIX_CHAR
	);
}

static constexpr std::array<std::string_view, static_cast<std::size_t>(ByteCodeValidationResultCode::Count)> BYTE_CODE_VALIDATION_RESULT_CODE_MESSAGES
{
	"Ok",
	"Too many arguments!",
	"Not enough arguments!",
	"Invalid argument type!",
	"Empty byte code!",
	"Missing code prologue!",
	"Missing code epilogue!"
};

static_assert(BYTE_CODE_VALIDATION_RESULT_CODE_MESSAGES.size() == static_cast<std::size_t>(ByteCodeValidationResultCode::Count));

auto formatter<ByteCodeValidationResultCode, char, void>::format(const Nominax::ByteCodeValidationResultCode& value,
	format_context& ctx) noexcept(false) -> FormatOutput
{
	const auto idx{ static_cast<std::underlying_type_t<std::remove_reference_t<decltype(value)>>>(value) };
	return format_to(ctx.out(), "{}", BYTE_CODE_VALIDATION_RESULT_CODE_MESSAGES[idx]);
}

auto formatter<DynamicSignal>::format(const DynamicSignal& value, format_context& ctx) noexcept(false) -> FormatOutput
{
	if (const auto* const x = std::get_if<Instruction>(&value.Storage))
	{
		return format_to(ctx.out(), "{}", *x);
	}
	
	if (const auto* const x = std::get_if<SystemIntrinsicCallId>(&value.Storage))
	{
		return format_to(ctx.out(), "{}", *x);
	}
	
	if (const auto* const x = std::get_if<CustomIntrinsicCallId>(&value.Storage))
	{
		return format_to(ctx.out(), "{}", *x);
	}
	
	if (const auto* const x = std::get_if<JumpAddress>(&value.Storage))
	{
		return format_to(ctx.out(), "{}", *x);
	}
	
	if (const auto* const x = std::get_if<U64>(&value.Storage))
	{
		return format_to(ctx.out(), "{}{}{}",Lexemes::IMMEDIATE, *x, Lexemes::LITERAL_SUFFIX_UINT);
	}

	if (const auto* const x = std::get_if<I64>(&value.Storage))
	{
		return format_to(ctx.out(), "{}{}{}", Lexemes::IMMEDIATE, *x, Lexemes::LITERAL_SUFFIX_INT);
	}

	if (const auto* const x = std::get_if<F64>(&value.Storage))
	{
		return format_to(ctx.out(), "{}{}{}", Lexemes::IMMEDIATE, *x, Lexemes::LITERAL_SUFFIX_FLOAT);
	}
	
	if (const auto* const x = std::get_if<CharClusterUtf8>(&value.Storage))
	{
		return format_to(ctx.out(), "{}", *x);
	}

	return format_to(ctx.out(), "index: {}", Lexemes::IMMEDIATE, value.Storage.index(), Lexemes::LITERAL_SUFFIX_UINT);
}
