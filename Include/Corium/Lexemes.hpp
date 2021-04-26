#pragma once

#include <array>
#include <string_view>

#include "Keywords.hpp"

namespace Corium
{
	enum class Lexeme : std::size_t 
	{
		TypeSeparator,
		Comment,
		Assignment,
		LBracket,
		RBracket,
		LParen,
		RParen,
		Separator,
		Add,
		Sub,
		Mul,
		Div,
		Mod,
		And,
		Or,
		Xor,
		Compl,
		Not,
		Equals,
		NotEquals,
		Less,
		LessEquals,
		Greater,
		GreaterEquals,
		Ellipsis,
		Accessor,
		StringLiteral,
		CharLiteral,

		Count
	};

	constexpr std::array<std::u32string_view, static_cast<std::size_t>(Lexeme::Count)> LEXEMES
	{
		U":",
		U"#",
		U"=",
		U"{",
		U"}",
		U"(",
		U")",
		U",",
		U"+",
		U"-",
		U"*",
		U"/",
		U"%",
		U"&",
		U"|",
		U"^",
		U"~",
		U"!",
		U"==",
		U"!=",
		U"<",
		U"<=",
		U">",
		U">=",
		U"...",
		U".",
		U"\"",
		U"'"
	};
}