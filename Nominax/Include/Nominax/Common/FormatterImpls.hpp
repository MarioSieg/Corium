#pragma once

#include <fmt/format.h>

namespace Nominax
{
	enum class ByteCodeValidationResultCode;
	union CharClusterUtf8;
	enum class JumpAddress : std::uint64_t;
	enum class CustomIntrinsicCallId : std::uint64_t;
	enum class SystemIntrinsicCallId : std::uint64_t;
	enum class Instruction : std::uint64_t;
	struct DynamicSignal;
}

using FormatOutput = fmt::format_context::iterator;

template <>
struct fmt::formatter<Nominax::Instruction>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx) noexcept(false) { return ctx.begin(); }

	auto format(const Nominax::Instruction& value, format_context& ctx) noexcept(false)->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::SystemIntrinsicCallId>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx) noexcept(false) { return ctx.begin(); }

	auto format(const Nominax::SystemIntrinsicCallId& value, format_context& ctx) noexcept(false)->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::CustomIntrinsicCallId>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx) noexcept(false) { return ctx.begin(); }

	auto format(const Nominax::CustomIntrinsicCallId& value, format_context& ctx) noexcept(false)->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::JumpAddress>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx) noexcept(false) { return ctx.begin(); }

	auto format(const Nominax::JumpAddress& value, format_context& ctx) noexcept(false)->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::CharClusterUtf8>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx) noexcept(false) { return ctx.begin(); }

	auto format(const Nominax::CharClusterUtf8& value, format_context& ctx) noexcept(false)->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::ByteCodeValidationResultCode>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx) noexcept(false) { return ctx.begin(); }

	auto format(const Nominax::ByteCodeValidationResultCode& value, format_context& ctx) noexcept(false)->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::DynamicSignal>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx) noexcept(false) { return ctx.begin(); }
	
	auto format(const Nominax::DynamicSignal& value, format_context& ctx) noexcept(false) -> FormatOutput;
};
