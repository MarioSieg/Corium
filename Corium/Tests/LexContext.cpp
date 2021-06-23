#include "TestBase.hpp"

TEST(LexContext, EvalChar)
{
	LexContext ctx{};
	ctx.EvalChar(u8'h');
	ctx.EvalChar(u8'e');
	ctx.EvalChar(u8'l');
	ctx.EvalChar(u8'l');
	ctx.EvalChar(u8'o');
	ASSERT_EQ(ctx.GetIdentifierBuffer(), u8"hello");
}

TEST(LexContext, EvalString)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"hello");
	ASSERT_EQ(ctx.GetIdentifierBuffer(), u8"hello");
}

TEST(LexContext, Parenthesis)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"()");
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 2);
	ASSERT_EQ(std::get<MonoLexeme>(ctx.GetLexTreeOutput()[0]), MonoLexeme::ParenthesisLeft);
	ASSERT_EQ(std::get<MonoLexeme>(ctx.GetLexTreeOutput()[1]), MonoLexeme::ParenthesisRight);
}

TEST(LexContext, Braces)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"{}=");
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 3);
	ASSERT_EQ(std::get<MonoLexeme>(ctx.GetLexTreeOutput()[0]), MonoLexeme::CurlyBracesLeft);
	ASSERT_EQ(std::get<MonoLexeme>(ctx.GetLexTreeOutput()[1]), MonoLexeme::CurlyBracesRight);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[2]), Operator::Equals);
}

TEST(LexContext, Control)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"\n\t\v\f\r");
	ASSERT_TRUE(ctx.GetLexTreeOutput().empty());
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
}

TEST(LexContext, ParseIdent)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"hello");
	ASSERT_EQ(ctx.GetIdentifierBuffer(), u8"hello");
	ctx.ParseAndSubmitIdentifier();
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 1);
	ASSERT_TRUE(std::holds_alternative<Identifier>(ctx.GetLexTreeOutput()[0]));
	ASSERT_EQ(std::get<Identifier>(ctx.GetLexTreeOutput()[0]), u8"hello");
}

TEST(LexContext, ParseIdentKeyWord)
{
	LexContext ctx{};
	ctx.EvaluateString(KEYWORD_TABLE[static_cast<std::size_t>(Keyword::Let)]);
	ASSERT_EQ(ctx.GetIdentifierBuffer(), KEYWORD_TABLE[static_cast<std::size_t>(Keyword::Let)]);
	ctx.ParseAndSubmitIdentifier();
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 1);
	ASSERT_TRUE(std::holds_alternative<Keyword>(ctx.GetLexTreeOutput()[0]));
	ASSERT_EQ(std::get<Keyword>(ctx.GetLexTreeOutput()[0]), Keyword::Let); 
}

TEST(LexContext, ParseIdentFloat)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"3.1415");
	ASSERT_EQ(ctx.GetIdentifierBuffer(), u8"3.1415");
	ctx.ParseAndSubmitIdentifier();
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 1);
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[0]));
	ASSERT_TRUE(std::holds_alternative<F64>(std::get<Literal>(ctx.GetLexTreeOutput()[0])));
	ASSERT_DOUBLE_EQ(std::get<F64>(std::get<Literal>(ctx.GetLexTreeOutput()[0])), 3.1415);
}

TEST(LexContext, ParseIdentInt)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"12345");
	ASSERT_EQ(ctx.GetIdentifierBuffer(), u8"12345");
	ASSERT_FALSE(ctx.GetIdentifierBuffer().empty());
	ctx.ParseAndSubmitIdentifier();
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 1);
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[0]));
	ASSERT_TRUE(std::holds_alternative<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[0])));
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[0])), 12345);
}

TEST(LexContext, ParseIdentIntSpace)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"12345 ");
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 1);
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[0]));
	ASSERT_TRUE(std::holds_alternative<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[0])));
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[0])), 12345);
}

TEST(LexContext, LexLet)
{
	LexContext ctx{};
	ctx.EvaluateString(std::u8string{ KEYWORD_TABLE[static_cast<std::size_t>(Keyword::Let)] } + u8" noel\n");
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 2);
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
	ASSERT_TRUE(std::holds_alternative<Keyword>(ctx.GetLexTreeOutput()[0]));
	ASSERT_EQ(std::get<Keyword>(ctx.GetLexTreeOutput()[0]), Keyword::Let);
	ASSERT_TRUE(std::holds_alternative<Identifier>(ctx.GetLexTreeOutput()[1]));
	ASSERT_EQ(std::get<Identifier>(ctx.GetLexTreeOutput()[1]), u8"noel");
}

TEST(LexContext, LexIdentifiers)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"one two\nthree\tfour ");
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 4);
	ASSERT_TRUE(ctx.GetIdentifierBuffer().empty());
	ASSERT_TRUE(std::holds_alternative<Identifier>(ctx.GetLexTreeOutput()[0]));
	ASSERT_TRUE(std::holds_alternative<Identifier>(ctx.GetLexTreeOutput()[1]));
	ASSERT_TRUE(std::holds_alternative<Identifier>(ctx.GetLexTreeOutput()[2]));
	ASSERT_TRUE(std::holds_alternative<Identifier>(ctx.GetLexTreeOutput()[3]));
	ASSERT_EQ(std::get<Identifier>(ctx.GetLexTreeOutput()[0]), u8"one");
	ASSERT_EQ(std::get<Identifier>(ctx.GetLexTreeOutput()[1]), u8"two");
	ASSERT_EQ(std::get<Identifier>(ctx.GetLexTreeOutput()[2]), u8"three");
	ASSERT_EQ(std::get<Identifier>(ctx.GetLexTreeOutput()[3]), u8"four");
}

TEST(LexContext, LexArithmeticOperators)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"let x = 10 + 11 - 3 % 1 * 3 / 2\n");
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 14);
	ASSERT_TRUE(std::holds_alternative<Keyword>(ctx.GetLexTreeOutput()[0]));
	ASSERT_TRUE(std::holds_alternative<Identifier>(ctx.GetLexTreeOutput()[1]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[2]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[3]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[4]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[5]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[6]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[7]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[8]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[9]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[10]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[11]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[12]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[13]));
	
	ASSERT_EQ(std::get<Keyword>(ctx.GetLexTreeOutput()[0]), Keyword::Let);
	ASSERT_EQ(std::get<Identifier>(ctx.GetLexTreeOutput()[1]), u8"x");
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[2]), Operator::Equals);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[3])), 10);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[4]), Operator::Addition);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[5])), 11);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[6]), Operator::Subtraction);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[7])), 3);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[8]), Operator::Modulo);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[9])), 1);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[10]), Operator::Multiplication);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[11])), 3);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[12]), Operator::Division);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[13])), 2);
}

TEST(LexContext, LexBitOperators)
{
	LexContext ctx{};
	ctx.EvaluateString(u8"let x = 10 ^ 11 & 3 | 1 ^ ~3\n");
	ASSERT_EQ(ctx.GetLexTreeOutput().size(), 13);
	ASSERT_TRUE(std::holds_alternative<Keyword>(ctx.GetLexTreeOutput()[0]));
	ASSERT_TRUE(std::holds_alternative<Identifier>(ctx.GetLexTreeOutput()[1]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[2]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[3]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[4]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[5]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[6]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[7]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[8]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[9]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[10]));
	ASSERT_TRUE(std::holds_alternative<Operator>(ctx.GetLexTreeOutput()[11]));
	ASSERT_TRUE(std::holds_alternative<Literal>(ctx.GetLexTreeOutput()[12]));

	ASSERT_EQ(std::get<Keyword>(ctx.GetLexTreeOutput()[0]), Keyword::Let);
	ASSERT_EQ(std::get<Identifier>(ctx.GetLexTreeOutput()[1]), u8"x");
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[2]), Operator::Equals);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[3])), 10);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[4]), Operator::Xor);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[5])), 11);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[6]), Operator::And);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[7])), 3);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[8]), Operator::Or);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[9])), 1);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[10]), Operator::Xor);
	ASSERT_EQ(std::get<Operator>(ctx.GetLexTreeOutput()[11]), Operator::Complement);
	ASSERT_EQ(std::get<I64>(std::get<Literal>(ctx.GetLexTreeOutput()[12])), 3);
}
