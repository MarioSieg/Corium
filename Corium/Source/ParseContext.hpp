// File: ParseContext.hpp
// Author: Mario
// Created: 27.06.2021 7:44 PM
// Project: NominaxRuntime
// 
//                                  Apache License
//                            Version 2.0, January 2004
//                         http://www.apache.org/licenses/
// 
//    TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
// 
//    1. Definitions.
// 
//       "License" shall mean the terms and conditions for use, reproduction,
//       and distribution as defined by Sections 1 through 9 of this document.
// 
//       "Licensor" shall mean the copyright owner or entity authorized by
//       the copyright owner that is granting the License.
// 
//       "Legal Entity" shall mean the union of the acting entity and all
//       other entities that control, are controlled by, or are under common
//       control with that entity. For the purposes of this definition,
//       "control" means (i) the power, direct or indirect, to cause the
//       direction or management of such entity, whether by contract or
//       otherwise, or (ii) ownership of fifty percent (50%) or more of the
//       outstanding shares, or (iii) beneficial ownership of such entity.
// 
//       "You" (or "Your") shall mean an individual or Legal Entity
//       exercising permissions granted by this License.
// 
//       "Source" form shall mean the preferred form for making modifications,
//       including but not limited to software source code, documentation
//       source, and configuration files.
// 
//       "Object" form shall mean any form resulting from mechanical
//       transformation or translation of a Source form, including but
//       not limited to compiled object code, generated documentation,
//       and conversions to other media types.
// 
//       "Work" shall mean the work of authorship, whether in Source or
//       Object form, made available under the License, as indicated by a
//       copyright notice that is included in or attached to the work
//       (an example is provided in the Appendix below).
// 
//       "Derivative Works" shall mean any work, whether in Source or Object
//       form, that is based on (or derived from) the Work and for which the
//       editorial revisions, annotations, elaborations, or other modifications
//       represent, as a whole, an original work of authorship. For the purposes
//       of this License, Derivative Works shall not include works that remain
//       separable from, or merely link (or bind by name) to the interfaces of,
//       the Work and Derivative Works thereof.
// 
//       "Contribution" shall mean any work of authorship, including
//       the original version of the Work and any modifications or additions
//       to that Work or Derivative Works thereof, that is intentionally
//       submitted to Licensor for inclusion in the Work by the copyright owner
//       or by an individual or Legal Entity authorized to submit on behalf of
//       the copyright owner. For the purposes of this definition, "submitted"
//       means any form of electronic, verbal, or written communication sent
//       to the Licensor or its representatives, including but not limited to
//       communication on electronic mailing lists, source code control systems,
//       and issue tracking systems that are managed by, or on behalf of, the
//       Licensor for the purpose of discussing and improving the Work, but
//       excluding communication that is conspicuously marked or otherwise
//       designated in writing by the copyright owner as "Not a Contribution."
// 
//       "Contributor" shall mean Licensor and any individual or Legal Entity
//       on behalf of whom a Contribution has been received by Licensor and
//       subsequently incorporated within the Work.
// 
//    2. Grant of Copyright License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       copyright license to reproduce, prepare Derivative Works of,
//       publicly display, publicly perform, sublicense, and distribute the
//       Work and such Derivative Works in Source or Object form.
// 
//    3. Grant of Patent License. Subject to the terms and conditions of
//       this License, each Contributor hereby grants to You a perpetual,
//       worldwide, non-exclusive, no-charge, royalty-free, irrevocable
//       (except as stated in this section) patent license to make, have made,
//       use, offer to sell, sell, import, and otherwise transfer the Work,
//       where such license applies only to those patent claims licensable
//       by such Contributor that are necessarily infringed by their
//       Contribution(s) alone or by combination of their Contribution(s)
//       with the Work to which such Contribution(s) was submitted. If You
//       institute patent litigation against any entity (including a
//       cross-claim or counterclaim in a lawsuit) alleging that the Work
//       or a Contribution incorporated within the Work constitutes direct
//       or contributory patent infringement, then any patent licenses
//       granted to You under this License for that Work shall terminate
//       as of the date such litigation is filed.
// 
//    4. Redistribution. You may reproduce and distribute copies of the
//       Work or Derivative Works thereof in any medium, with or without
//       modifications, and in Source or Object form, provided that You
//       meet the following conditions:
// 
//       (a) You must give any other recipients of the Work or
//           Derivative Works a copy of this License; and
// 
//       (b) You must cause any modified files to carry prominent notices
//           stating that You changed the files; and
// 
//       (c) You must retain, in the Source form of any Derivative Works
//           that You distribute, all copyright, patent, trademark, and
//           attribution notices from the Source form of the Work,
//           excluding those notices that do not pertain to any part of
//           the Derivative Works; and
// 
//       (d) If the Work includes a "NOTICE" text file as part of its
//           distribution, then any Derivative Works that You distribute must
//           include a readable copy of the attribution notices contained
//           within such NOTICE file, excluding those notices that do not
//           pertain to any part of the Derivative Works, in at least one
//           of the following places: within a NOTICE text file distributed
//           as part of the Derivative Works; within the Source form or
//           documentation, if provided along with the Derivative Works; or,
//           within a display generated by the Derivative Works, if and
//           wherever such third-party notices normally appear. The contents
//           of the NOTICE file are for informational purposes only and
//           do not modify the License. You may add Your own attribution
//           notices within Derivative Works that You distribute, alongside
//           or as an addendum to the NOTICE text from the Work, provided
//           that such additional attribution notices cannot be construed
//           as modifying the License.
// 
//       You may add Your own copyright statement to Your modifications and
//       may provide additional or different license terms and conditions
//       for use, reproduction, or distribution of Your modifications, or
//       for any such Derivative Works as a whole, provided Your use,
//       reproduction, and distribution of the Work otherwise complies with
//       the conditions stated in this License.
// 
//    5. Submission of Contributions. Unless You explicitly state otherwise,
//       any Contribution intentionally submitted for inclusion in the Work
//       by You to the Licensor shall be under the terms and conditions of
//       this License, without any additional terms or conditions.
//       Notwithstanding the above, nothing herein shall supersede or modify
//       the terms of any separate license agreement you may have executed
//       with Licensor regarding such Contributions.
// 
//    6. Trademarks. This License does not grant permission to use the trade
//       names, trademarks, service marks, or product names of the Licensor,
//       except as required for reasonable and customary use in describing the
//       origin of the Work and reproducing the content of the NOTICE file.
// 
//    7. Disclaimer of Warranty. Unless required by applicable law or
//       agreed to in writing, Licensor provides the Work (and each
//       Contributor provides its Contributions) on an "AS IS" BASIS,
//       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
//       implied, including, without limitation, any warranties or conditions
//       of TITLE, NON-INFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A
//       PARTICULAR PURPOSE. You are solely responsible for determining the
//       appropriateness of using or redistributing the Work and assume any
//       risks associated with Your exercise of permissions under this License.
// 
//    8. Limitation of Liability. In no event and under no legal theory,
//       whether in tort (including negligence), contract, or otherwise,
//       unless required by applicable law (such as deliberate and grossly
//       negligent acts) or agreed to in writing, shall any Contributor be
//       liable to You for damages, including any direct, indirect, special,
//       incidental, or consequential damages of any character arising as a
//       result of this License or out of the use or inability to use the
//       Work (including but not limited to damages for loss of goodwill,
//       work stoppage, computer failure or malfunction, or any and all
//       other commercial damages or losses), even if such Contributor
//       has been advised of the possibility of such damages.
// 
//    9. Accepting Warranty or Additional Liability. While redistributing
//       the Work or Derivative Works thereof, You may choose to offer,
//       and charge a fee for, acceptance of support, warranty, indemnity,
//       or other liability obligations and/or rights consistent with this
//       License. However, in accepting such obligations, You may act only
//       on Your own behalf and on Your sole responsibility, not on behalf
//       of any other Contributor, and only if You agree to indemnify,
//       defend, and hold each Contributor harmless for any liability
//       incurred by, or claims asserted against, such Contributor by reason
//       of your accepting any such warranty or additional liability.
// 
//    END OF TERMS AND CONDITIONS
// 
//    APPENDIX: How to apply the Apache License to your work.
// 
//       To apply the Apache License to your work, attach the following
//       boilerplate notice, with the fields enclosed by brackets "[]"
//       replaced with your own identifying information. (Don't include
//       the brackets!)  The text should be enclosed in the appropriate
//       comment syntax for the file format. We also recommend that a
//       file or class name and description of purpose be included on the
//       same "printed page" as the copyright notice for easier
//       identification within third-party archives.
// 
//    Copyright 2021 Mario Sieg "pinsrq" <mt3000@gmx.de>
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#pragma once

#include "Token.hpp"
#include "Function.hpp"
#include "ParseError.hpp"
#include "Scope.hpp"

namespace Corium
{
	class LexContext;

	/// <summary>
	/// Contains all states for token stream parsing.
	/// </summary>
	class ParseContext final
	{
		/// <summary>
		/// The current error state. If .first is != Ok then parsing will stop.
		/// </summary>
		ParseError ErrorState_ {ParseErrorCode::Ok, { }};

		/// <summary>
		/// The whole read only token stream.
		/// </summary>
		TokenStreamView TokenStreamView_ { };

		/// <summary>
		/// The current iteration needle.
		/// </summary>
		TokenStreamView::iterator Needle_ {nullptr};

		/// <summary>
		/// The end needle of the whole token stream.
		/// </summary>
		TokenStreamView::iterator End_ {nullptr};

		/// <summary>
		/// The whole read only source code.
		/// </summary>
		SourceCode SourceText_ { };

		/// <summary>
		/// The current line index (one based).
		/// </summary>
		U32 CurrentLine_ { };

		/// <summary>
		/// A table containing all currently defined functions.
		/// </summary>
		FunctionTable FunctionTable_ { };

		/// <summary>
		/// Used to check scopes.
		/// </summary>
		ScopeChecker ScopeChecker_{ };

	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		ParseContext() = default;

		/// <summary>
		/// Construct with data views from a lex context.
		/// </summary>
		/// <param name="lexContext"></param>
		explicit ParseContext(const LexContext& lexContext);

		/// <summary>
		/// Construct with data views.
		/// </summary>
		/// <param name="tokenView"></param>
		/// <param name="sourceText"></param>
		ParseContext(TokenStreamView tokenView, SourceCode sourceText);

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		ParseContext(ParseContext&& other) = default;

		/// <summary>
		/// No copying.
		/// </summary>
		/// <param name="other"></param>
		ParseContext(const ParseContext& other) = delete;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(ParseContext&& other) -> ParseContext& = default;

		/// <summary>
		/// No copying.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const ParseContext& other) -> ParseContext& = delete;

		/// <summary>
		/// Destructor.
		/// </summary>
		~ParseContext() = default;

		/// <summary>
		/// Get the next token at the offset relative to the current needle.
		/// </summary>
		/// <param name="offset"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto GetNextAt(std::size_t offset) const -> const Token&;

		/// <summary>
		/// Checks if there is a next token at the offset relative to the current needle.
		/// </summary>
		/// <param name="amount"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto HasNext(std::size_t amount) const -> bool;

		/// <summary>
		/// Get the next token at the offset relative to the current needle if any, else nullptr.
		/// </summary>
		/// <param name="offset"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto GetNextAtOrNull(std::size_t offset) const -> const Token*;

		/// <summary>
		/// The count of remaining tokens from the current needle offset.
		/// </summary>
		/// <returns>The count of remaining tokens from the current needle offset.</returns>
		[[nodiscard]]
		auto GetNextCount() const -> std::size_t;

		/// <summary>
		/// Gets the token data if types are matching, else nullptr.
		/// </summary>
		/// <param name="offset">The offset to get from.</param>
		/// <returns>Pointer to token data if valid, else nullptr.</returns>
		template <typename T>
		[[nodiscard]]
		auto GetNextIf(std::size_t offset) const -> const T*;

        /// <summary>
        /// Searches for the next char and returns the needle, else null.
        /// </summary>
        /// <param name="what">The token to find the next of.</param>
        /// <returns>Pointer to token data if found, else nullptr.</returns>
        [[nodiscard]]
		auto FindNextOrNull(const Token& what) const -> const Token*;

		/// <summary>
		/// Skips n tokens by advancing the needle.
		/// </summary>
		/// <param name="count">The amount of tokens to skip.</param>
		auto Skip(std::size_t count) -> void;

		/// <summary>
		/// Resets all the states and data views.
		/// </summary>
		/// <param name="tokenView"></param>
		/// <param name="sourceText"></param>
		/// <returns></returns>
		auto Reset(TokenStreamView tokenView, SourceCode sourceText) -> void;

		/// <summary>
		/// Returns the line at index (one based), if any, else nullopt.
		/// </summary>
		/// <param name="lineNumber"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto GetNthLineOfSource(std::size_t lineNumber) const -> std::optional<std::string>;

		/// <summary>
		/// Parses the token stream view and set's all states.
		/// </summary>
		/// <returns></returns>
		auto Parse() -> const ParseError&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current error state.</returns>
		[[nodiscard]]
		auto GetErrorState() const -> const ParseError&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current token stream data view.</returns>
		[[nodiscard]]
		auto GetTokenStreamView() const -> const TokenStreamView&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current iteration needle.</returns>
		[[nodiscard]]
		auto GetNeedle() const -> TokenStreamView::iterator;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current iteration end needle.</returns>
		[[nodiscard]]
		auto GetNeedleEnd() const -> TokenStreamView::iterator;

		/// <summary>
		///
		/// </summary>
		/// <returns>The current source text for the token stream.</returns>
		[[nodiscard]]
		auto GetSourceText() const -> std::string_view;

		/// <summary>
		///
		/// </summary>
		/// <returns>The current function table.</returns>
		[[nodiscard]]
		auto GetFunctionTable() const -> const FunctionTable&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current line index (one based).</returns>
		[[nodiscard]]
		auto GetCurrentLine() const -> U32;

		/// <summary>
		///
		/// </summary>
		/// <returns>True if there is an error in the state, else false.</returns>
		[[nodiscard]]
		auto HasError() const -> bool;

		/// <summary>
		/// Format and set's the current error state with custom message.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <typeparam name="...Ts"></typeparam>
		/// <param name="code"></param>
		/// <param name="format"></param>
		/// <param name="args"></param>
		/// <returns></returns>
		template <typename T, typename... Ts>
		auto MakeParseError(ParseErrorCode code, T&& format, Ts&&...args) -> const ParseError&;

		/// <summary>
		/// Format user message with line info and error indicator.
		/// </summary>
		/// <param name="code"></param>
		/// <param name="userMessage"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto FormatAndSetParseError(ParseErrorCode code, std::string&& userMessage) -> const ParseError&;

		/// <summary>
		/// Parse proxy.
		/// </summary>
		/// <param name="monoLexeme"></param>
		/// <returns></returns>
		auto ParseProxy_MonoLexeme(MonoLexeme monoLexeme) -> void;

		/// <summary>
		/// Parse proxy.
		/// </summary>
		/// <param name="identifier"></param>
		/// <returns></returns>
		auto ParseProxy_Identifier(const Identifier& identifier) -> void;

		/// <summary>
		/// Parse proxy.
		/// </summary>
		/// <param name="keyword"></param>
		/// <returns></returns>
		auto ParseProxy_Keyword(Keyword keyword) -> void;

		/// <summary>
		/// Parse proxy.
		/// </summary>
		/// <param name="operateur"></param>
		/// <returns></returns>
		auto ParseProxy_Operator(Operator operateur) -> void;

		/// <summary>
		/// Parse proxy.
		/// </summary>
		/// <param name="literal"></param>
		/// <returns></returns>
		auto ParseProxy_Literal(const Literal& literal) -> void;

		/// <summary>
		/// Parses a function from the current needle state.
		/// </summary>
		auto ParseFunction() -> void;

		/// <summary>
		/// Parses a let variable declaration from the current needle state.
		/// </summary>
		auto ParseLet() -> void;

		/// <summary>
		/// Sets the error state to a well formatted argument.
		/// </summary>
		/// <param name="expected">The mono lexeme which was expected..</param>
		/// <param name="gotInstead">The mono lexeme we got instead.</param>
		auto MakeSpecializedError(MonoLexeme expected, const MonoLexeme* const gotInstead = nullptr) -> void;

		/// <summary>
		/// Prints the function and type tables.
		/// </summary>
		auto PrintParseStates() const -> void;
	};

	inline auto ParseContext::GetErrorState() const -> const ParseError&
	{
		return this->ErrorState_;
	}

	inline auto ParseContext::GetTokenStreamView() const -> const TokenStreamView&
	{
		return this->TokenStreamView_;
	}

	inline auto ParseContext::GetNeedle() const -> TokenStreamView::iterator
	{
		return this->Needle_;
	}

	inline auto ParseContext::GetNeedleEnd() const -> TokenStreamView::iterator
	{
		return this->End_;
	}

	inline auto ParseContext::Skip(const std::size_t count) -> void
	{
		std::advance(this->Needle_, count);
	}

	inline auto ParseContext::GetNextAt(const std::size_t offset) const -> const Token&
	{
		return this->Needle_[offset];
	}

	inline auto ParseContext::HasNext(const std::size_t amount) const -> bool
	{
		return this->Needle_ + amount < this->End_;
	}

	inline auto ParseContext::GetNextAtOrNull(const std::size_t offset) const -> const Token*
	{
		return this->HasNext(offset) ? &this->GetNextAt(offset) : nullptr;
	}

	inline auto ParseContext::GetNextCount() const -> std::size_t
	{
		return std::distance(this->Needle_, this->End_);
	}

	inline auto ParseContext::HasError() const -> bool
	{
		return this->ErrorState_.first != ParseErrorCode::Ok;
	}

	template <typename T>
	inline auto ParseContext::GetNextIf(const std::size_t offset) const -> const T*
	{
		return std::get_if<T>(&this->GetNextAt(offset));
	}

	template <typename T, typename... Ts>
	inline auto ParseContext::MakeParseError(const ParseErrorCode code, T&& format, Ts&&...args) -> const ParseError&
	{
		std::string formattedMessage {Common::Format(std::forward<T>(format), std::forward<Ts>(args)...)};
		return this->FormatAndSetParseError(code, std::move(formattedMessage));
	}

	inline auto ParseContext::GetSourceText() const -> std::string_view
	{
		return this->SourceText_;
	}

	inline auto ParseContext::GetCurrentLine() const -> U32
	{
		return this->CurrentLine_;
	}

	inline auto ParseContext::GetFunctionTable() const -> const FunctionTable&
	{
		return this->FunctionTable_;
	}

    inline auto ParseContext::FindNextOrNull(const Token& what) const -> const Token*
    {
        const auto found{std::find(this->Needle_, this->End_, what)};
        return found == this->End_ ? nullptr : &*found;
    }

	extern auto Parse(std::span<const Token> tokenStreamView, std::span<const U16> lines) -> ParseError;
}
