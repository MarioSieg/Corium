#pragma once

#include <fmt/format.h>

#include "BaseTypes.hpp"

namespace Nominax {
	namespace Core {
		enum class ReactorValidationResult : std::uint8_t;
	}
}

namespace Nominax {
	namespace ByteCode {
		struct DiscriminatedSignal;
		enum class ValidationResultCode;
		union CharClusterUtf32;
		union CharClusterUtf16;
		union CharClusterUtf8;
		enum class JumpAddress : U64;
		enum class UserIntrinsicInvocationID : U64;
		enum class SystemIntrinsicInvocationID : U64;
		enum class Instruction : U64;
	}
}

using FormatOutput = fmt::format_context::iterator;

template <>
struct fmt::formatter<Nominax::ByteCode::Instruction>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::ByteCode::Instruction& value, format_context& ctx) const->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::ByteCode::SystemIntrinsicInvocationID>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::ByteCode::SystemIntrinsicInvocationID& value, format_context& ctx) const->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::ByteCode::UserIntrinsicInvocationID>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::ByteCode::UserIntrinsicInvocationID& value, format_context& ctx) const->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::ByteCode::JumpAddress>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::ByteCode::JumpAddress& value, format_context& ctx) const->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::ByteCode::CharClusterUtf8>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::ByteCode::CharClusterUtf8& value, format_context& ctx) const->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::ByteCode::CharClusterUtf16>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::ByteCode::CharClusterUtf16& value, format_context& ctx) const->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::ByteCode::CharClusterUtf32>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::ByteCode::CharClusterUtf32& value, format_context& ctx) const->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::ByteCode::ValidationResultCode>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::ByteCode::ValidationResultCode& value, format_context& ctx) const->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::Core::ReactorValidationResult>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::Core::ReactorValidationResult& value, format_context& ctx) const->FormatOutput;
};

template <>
struct fmt::formatter<Nominax::ByteCode::DiscriminatedSignal>
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const Nominax::ByteCode::DiscriminatedSignal& value, format_context& ctx) const->FormatOutput;
};
