#pragma once

#include "Token.hpp"

namespace Corium
{	
	/// <summary>
	/// Core lexer context.
	/// </summary>
	class LexContext final
	{
		Identifier IdentifierBuffer_{};
		TokenStream Output_{};

		auto GetRawIdentifierBuffer() -> char8_t*;
		auto GetRawIdentifierBufferLossy() -> char*;
		auto GetRawIdentifierBufferBlob() -> U8*;
		auto GetRawIdentifierBuffer() const -> const char8_t*;
		auto GetRawIdentifierBufferLossy() const -> const char*;
		auto GetRawIdentifierBufferBlob() const -> const U8*;

	public:
		/// <summary>
		/// Construct new and empty instance.
		/// </summary>
		LexContext() = default;

		/// <summary>
		/// Construct and reserve buffers.
		/// </summary>
		/// <param name="expectedOutputSize">The reserved output buffer size.</param>
		/// <param name="expectedIdentSize">The reserved identifier size.</param>
		LexContext(std::size_t expectedOutputSize, std::size_t expectedIdentSize);

		/// <summary>
		/// No copying.
		/// </summary>
		/// <param name="other"></param>
		LexContext(const LexContext& other) = delete;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		LexContext(LexContext&& other) = default;

		/// <summary>
		/// No copying.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const LexContext& other) -> LexContext& = delete;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(LexContext&& other) -> LexContext& = delete;

		/// <summary>
		/// Destructor.
		/// </summary>
		~LexContext() = default;

		/// <summary>
		/// Parses the identifier buffer and submits it to the stream.
		/// </summary>
		/// <returns></returns>
		auto ParseAndSubmitIdentifier() -> void;

		/// <summary>
		/// Evaluate single character.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		auto EvalChar(char8_t x) -> void;

		/// <summary>
		/// Evaluate each character in source text view.
		/// </summary>
		/// <param name="sourceText"></param>
		/// <returns></returns>
		auto EvaluateString(std::u8string_view sourceText) -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current identifier buffer.</returns>
		[[nodiscard]]
		auto GetIdentifierBuffer() const -> const Identifier&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current lex tree result.</returns>
		[[nodiscard]]
		auto GetLexTreeOutput() const & -> const TokenStream&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current lex tree result.</returns>
		[[nodiscard]]
		auto GetLexTreeOutput() & -> TokenStream&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current lex tree result.</returns>
		[[nodiscard]]
		auto GetLexTreeOutput() const && -> const TokenStream&&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current lex tree result.</returns>
		[[nodiscard]]
		auto GetLexTreeOutput() && -> TokenStream&&;
	};

	inline auto LexContext::GetIdentifierBuffer() const -> const Identifier&
	{
		return this->IdentifierBuffer_;
	}

	inline auto LexContext::GetRawIdentifierBuffer() -> char8_t*
	{
		return std::data(this->IdentifierBuffer_);
	}
	
	inline auto LexContext::GetRawIdentifierBufferLossy() -> char*
	{
		return reinterpret_cast<char*>(std::data(this->IdentifierBuffer_));
	}
	
	inline auto LexContext::GetRawIdentifierBufferBlob() -> U8*
	{
		return reinterpret_cast<U8*>(std::data(this->IdentifierBuffer_));
	}
	
	inline auto LexContext::GetRawIdentifierBuffer() const -> const char8_t*
	{
		return std::data(this->IdentifierBuffer_);
	}
	
	inline auto LexContext::GetRawIdentifierBufferLossy() const -> const char*
	{
		return reinterpret_cast<const char*>(std::data(this->IdentifierBuffer_));
	}
	
	inline auto LexContext::GetRawIdentifierBufferBlob() const -> const U8*
	{
		return reinterpret_cast<const U8*>(std::data(this->IdentifierBuffer_));
	}

	inline auto LexContext::GetLexTreeOutput() const & -> const TokenStream&
	{
		return this->Output_;
	}

	inline auto LexContext::GetLexTreeOutput() & -> TokenStream&
	{
		return this->Output_;
	}

	inline auto LexContext::GetLexTreeOutput() const && -> const TokenStream&&
	{
		return std::move(this->Output_);
	}

	inline auto LexContext::GetLexTreeOutput() && -> TokenStream&&
	{
		return std::move(this->Output_);
	}
}
