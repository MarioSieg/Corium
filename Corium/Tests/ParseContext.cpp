#include "TestBase.hpp"

static constexpr std::string_view EXAMPLE_SOURCE_TEXT
{
    "let x = 10 + 11 - 3 % 1 * 3 / 2\n"
};

static constexpr std::array<const Token, 14> EXAMPLE_TOKENS
{
    Keyword::Let,
    Identifier{"x"},
    Operator::Equals,
    Literal{10},
    Operator::Addition,
    11,
    Operator::Subtraction,
    3,
    Operator::Modulo,
    1,
    Operator::Multiplication,
    3,
    Operator::Division,
    2
};

TEST(ParseContext, Construct)
{
    ParseContext context{EXAMPLE_TOKENS, EXAMPLE_SOURCE_TEXT};
    ASSERT_EQ(std::size(context.GetTokenStreamView()), std::size(EXAMPLE_TOKENS));
    ASSERT_EQ(context.GetSourceText(), EXAMPLE_SOURCE_TEXT);
    ASSERT_EQ(*context.GetNeedle(), *std::begin(EXAMPLE_TOKENS));
    ASSERT_EQ(context.GetNeedleEnd()[-1], std::end(EXAMPLE_TOKENS)[-1]);
    ASSERT_FALSE(context.GetErrorState().has_value());
}

TEST(ParseContext, ConstructEmpty)
{
    ParseContext context{};
    ASSERT_EQ(&*context.GetNeedle(), nullptr);
    ASSERT_EQ(&*context.GetNeedleEnd(), nullptr);
    ASSERT_TRUE(std::empty(context.GetTokenStreamView()));
    ASSERT_TRUE(std::empty(context.GetSourceText()));
    ASSERT_FALSE(context.GetErrorState().has_value());
}

TEST(ParseContext, GetNextAt)
{
    ParseContext context{EXAMPLE_TOKENS, EXAMPLE_SOURCE_TEXT};
    for (std::size_t i {0}; i < std::size(EXAMPLE_TOKENS); ++i)
    {
        ASSERT_EQ(context.GetNextAt(i), EXAMPLE_TOKENS[i]);
    }
}

TEST(ParseContext, HasNext)
{
    ParseContext context{EXAMPLE_TOKENS, EXAMPLE_SOURCE_TEXT};
    for (std::size_t i {0}; i < std::size(EXAMPLE_TOKENS); ++i)
    {
        ASSERT_TRUE(context.HasNext(i));
    }
    ASSERT_FALSE(context.HasNext(std::size(EXAMPLE_TOKENS) + 1));
    ASSERT_FALSE(context.HasNext(std::size(EXAMPLE_TOKENS) + 2));
}

TEST(ParseContext, GetNextAtOrNull)
{
    ParseContext context{EXAMPLE_TOKENS, EXAMPLE_SOURCE_TEXT};
    for (std::size_t i {0}; i < std::size(EXAMPLE_TOKENS); ++i)
    {
        ASSERT_NE(context.GetNextAtOrNull(i), nullptr);
    }
    ASSERT_EQ(context.GetNextAtOrNull(std::size(EXAMPLE_TOKENS) + 1), nullptr);
    ASSERT_EQ(context.GetNextAtOrNull(std::size(EXAMPLE_TOKENS) + 2), nullptr);
}

TEST(ParseContext, Reset)
{
    ParseContext context{};
    ASSERT_EQ(&*context.GetNeedle(), nullptr);
    ASSERT_EQ(&*context.GetNeedleEnd(), nullptr);
    ASSERT_TRUE(std::empty(context.GetTokenStreamView()));
    ASSERT_TRUE(std::empty(context.GetSourceText()));
    ASSERT_FALSE(context.GetErrorState().has_value());
    context.Reset(EXAMPLE_TOKENS, EXAMPLE_SOURCE_TEXT);
    ASSERT_FALSE(context.GetErrorState().has_value());
    ASSERT_EQ(std::size(context.GetTokenStreamView()), std::size(EXAMPLE_TOKENS));
    ASSERT_EQ(context.GetSourceText(), EXAMPLE_SOURCE_TEXT);
    ASSERT_EQ(*context.GetNeedle(), *std::begin(EXAMPLE_TOKENS));
    ASSERT_EQ(context.GetNeedleEnd()[-1], std::end(EXAMPLE_TOKENS)[-1]);
}

TEST(ParseContext, GetNthLineOfSource)
{
    constexpr std::string_view source {"Line1\nLine2\nLine3\nLine4"};
    ParseContext context{EXAMPLE_TOKENS, source};
    ASSERT_EQ(context.GetSourceText(), source);
    ASSERT_FALSE(context.GetNthLineOfSource(0).has_value());
    ASSERT_EQ(context.GetNthLineOfSource(1).value_or("?"), "Line1");
    ASSERT_EQ(context.GetNthLineOfSource(2).value_or("?"), "Line2");
    ASSERT_EQ(context.GetNthLineOfSource(3).value_or("?"), "Line3");
    ASSERT_EQ(context.GetNthLineOfSource(4).value_or("?"), "Line4");
    ASSERT_FALSE(context.GetNthLineOfSource(5).has_value());
}

TEST(ParseContext, ParseFunctionValid)
{
    const std::string_view source{"fun test () {\n}\n"};
    const std::array<const Token, 8> tokens
    {
        Keyword::Fun,
        Identifier{"test"},
        MonoLexeme::ParenthesisLeft,
        MonoLexeme::ParenthesisRight,
        MonoLexeme::CurlyBracesLeft,
        MonoLexeme::NewLine,
        MonoLexeme::CurlyBracesRight,
        MonoLexeme::NewLine
    };
    ParseContext context{tokens, source};
    ASSERT_EQ(context.GetCurrentLine(), 1);
    ASSERT_NO_FATAL_FAILURE(context.Parse());
    ASSERT_FALSE(context.GetErrorState().has_value());
    ASSERT_EQ(context.GetSourceText(), source);
    ASSERT_EQ(context.GetNeedle()[-1], std::end(tokens)[-1]);
    ASSERT_EQ(context.GetNeedle(), context.GetNeedleEnd());
    ASSERT_EQ(context.GetCurrentLine(), 3);
    context.Reset(tokens, source);
    ASSERT_FALSE(context.Parse().has_value());
}

TEST(ParseContext, ParseFunctionInvalid)
{
    const std::string_view source{"fun () {\n}\n"};
    const std::array<const Token, 8> tokens
    {
        Keyword::Fun,
        MonoLexeme::ParenthesisLeft,
        MonoLexeme::ParenthesisRight,
        MonoLexeme::CurlyBracesLeft,
        MonoLexeme::NewLine,
        MonoLexeme::CurlyBracesRight,
        MonoLexeme::NewLine
    };
    ParseContext context{tokens, source};
    ASSERT_EQ(context.GetCurrentLine(), 1);
    ASSERT_NO_FATAL_FAILURE(context.Parse());
    ASSERT_TRUE(context.GetErrorState().has_value());
    ASSERT_FALSE(std::empty(*context.GetErrorState()));
    ASSERT_EQ(context.GetCurrentLine(), 1);
}