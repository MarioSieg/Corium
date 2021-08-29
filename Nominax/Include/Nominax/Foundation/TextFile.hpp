// File: TextFile.hpp
// Author: Mario
// Created: 20.08.2021 2:40 PM
// Project: Corium
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

#include <filesystem>
#include <string>
#include <string_view>

#include <cstdint>

namespace Nominax::Foundation
{
	/// <summary>
		/// Helper to work with text files.
		/// </summary>
	class TextFile final
	{
	public:
		/// <summary>
		/// String type alias.
		/// </summary>
		using StringType = std::string;

		/// <summary>
		/// String view type.
		/// </summary>
		using ViewType = std::string_view;

	private:
		/// <summary>
		/// The content of the file.
		/// </summary>
		StringType Content_ { };

		/// <summary>
		/// The path of the file.
		/// </summary>
		std::filesystem::path FilePath_ { };

	public:
		/// <summary>
		/// The character type.
		/// </summary>
		using CharType = decltype(Content_)::value_type;

		/// <summary>
		/// The type for the file input stream.
		/// </summary>
		using InputStream = std::basic_ifstream<CharType, std::char_traits<CharType>>;

		/// <summary>
		/// The type for the file output stream.
		/// </summary>
		using OutputStream = std::basic_ofstream<CharType, std::char_traits<CharType>>;

		/// <summary>
		/// Construct empty.
		/// </summary>
		/// <returns></returns>
		TextFile() = default;

		/// <summary>
		/// Construct with content.
		/// </summary>
		/// <param name="content">Content of the file.</param>
		/// <returns></returns>
		explicit TextFile(StringType&& content);

		/// <summary>
		/// Construct with path and content.
		/// </summary>
		/// <param name="path"></param>
		/// <param name="content"></param>
		/// <returns></returns>
		TextFile(std::filesystem::path&& path, StringType&& content);

		/// <summary>
		/// No copy.
		/// </summary>
		/// <param name="other"></param>
		TextFile(const TextFile& other) = delete;

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other"></param>
		TextFile(TextFile&& other) = default;

		/// <summary>
		/// No copy.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(const TextFile& other) -> TextFile& = delete;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(TextFile&& other) -> TextFile& = default;

		/// <summary>
		/// Destructor.
		/// </summary>
		~TextFile() = default;

		/// <summary>
		/// Writes the content into the specified path
		/// and saves the path argument into this class instance content.
		/// </summary>
		/// <param name="path"></param>
		/// <returns>True on success, else false.</returns>
		[[nodiscard]]
		auto WriteToFile(std::filesystem::path&& path) -> bool;

		/// <summary>
		/// Reads the content of the file into this class instance content.
		/// </summary>
		/// <param name="path"></param>
		/// <returns>True on success, else false.</returns>
		[[nodiscard]]
		auto ReadFromFile(std::filesystem::path&& path) -> bool;

		/// <summary>
		/// Reads the content of the stream into this class instance.
		/// </summary>
		/// <param name="stream"></param>
		/// <returns></returns>
		auto ReadFromStream(std::ifstream& stream) -> void;

		/// <summary>
		/// Reads the content of the file into this class instance and panics on any fail.
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		auto ReadFromFileOrPanic(std::filesystem::path&& path) -> void;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current text file content.</returns>
		[[nodiscard]]
		auto GetContentText() const & -> const StringType&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current text file content.</returns>
		[[nodiscard]]
		auto GetContentText() & -> StringType&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current text file content.</returns>
		[[nodiscard]]
		auto GetContentText() && -> StringType&&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current file path.</returns>
		[[nodiscard]]
		auto GetFilePath() const & -> const std::filesystem::path&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current file path.</returns>
		[[nodiscard]]
		auto GetFilePath() && -> std::filesystem::path&&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the content is empty, else false.</returns>
		[[nodiscard]]
		auto IsEmpty() const -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The capacity of the content.</returns>
		[[nodiscard]]
		auto GetCapacity() const -> std::uint64_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the content - the number of characters.</returns>
		[[nodiscard]]
		auto GetSize() const -> std::uint64_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the content in bytes (capacity * charSize)</returns>
		[[nodiscard]]
		auto GetSizeInBytes() const -> std::uint64_t;

		/// <summary>
		/// Removes all the spaces (' ') from the content in parallel.
		/// </summary>
		/// <returns></returns>
		auto ParallelEraseSpaces() -> void;

		/// <summary>
		/// Removes all spaces and control characters from the content in parallel.
		/// </summary>
		/// <returns></returns>
		auto ParallelEraseSpacesAndControlChars() -> void;

		/// <summary>
		/// Removes all the occurrences of the character in parallel.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		auto ParallelErase(CharType x) -> void;

		/// <summary>
		/// Searches all the ranges between the two chars and removes the text between them and themselves.
		/// </summary>
		/// <param name="begin"></param>
		/// <param name="end"></param>
		/// <returns></returns>
		auto EraseRange(CharType begin, CharType end) -> void;

		/// <summary>
		/// Get a substring string view to the
		/// content between the two indices (both inclusive).
		/// </summary>
		/// <param name="beginIdx"></param>
		/// <param name="endIdx"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto SubString(std::uint64_t beginIdx, std::uint64_t endIdx) const -> ViewType;

		/// <summary>
		/// Get a substring string view to the
		/// content between the two first chars found (both inclusive).
		/// </summary>
		/// <param name="beginChar"></param>
		/// <param name="endChar"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto SubStringChar(CharType beginChar, CharType endChar) const -> ViewType;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto begin() -> StringType::iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto end() -> StringType::iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto rbegin() -> StringType::reverse_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto rend() -> StringType::reverse_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto cbegin() const -> StringType::const_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto cend() const -> StringType::const_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto crbegin() const -> StringType::const_reverse_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto crend() const -> StringType::const_reverse_iterator;
	};

	inline TextFile::TextFile(StringType&& content) : Content_ { std::move(content) } { }

	inline TextFile::TextFile(std::filesystem::path&& path, StringType&& content) : Content_ { std::move(content) },
	                                                                                FilePath_ { std::move(path) } { }

	inline auto TextFile::GetContentText() const & -> const StringType&
	{
		return this->Content_;
	}

	inline auto TextFile::GetContentText() & -> StringType&
	{
		return this->Content_;
	}

	inline auto TextFile::GetContentText() && -> StringType&&
	{
		return std::move(this->Content_);
	}

	inline auto TextFile::GetFilePath() const & -> const std::filesystem::path&
	{
		return this->FilePath_;
	}

	inline auto TextFile::GetFilePath() && -> std::filesystem::path&&
	{
		return std::move(this->FilePath_);
	}

	inline auto TextFile::IsEmpty() const -> bool
	{
		return this->Content_.empty();
	}

	inline auto TextFile::GetCapacity() const -> std::uint64_t
	{
		return this->Content_.capacity();
	}

	inline auto TextFile::GetSize() const -> std::uint64_t
	{
		return this->Content_.size();
	}

	inline auto TextFile::GetSizeInBytes() const -> std::uint64_t
	{
		return this->Content_.capacity() * sizeof(CharType);
	}

	inline auto TextFile::begin() -> StringType::iterator
	{
		return std::begin(this->Content_);
	}

	inline auto TextFile::end() -> StringType::iterator
	{
		return std::end(this->Content_);
	}

	inline auto TextFile::rbegin() -> StringType::reverse_iterator
	{
		return std::rbegin(this->Content_);
	}

	inline auto TextFile::rend() -> StringType::reverse_iterator
	{
		return std::rend(this->Content_);
	}

	inline auto TextFile::cbegin() const -> StringType::const_iterator
	{
		return std::cbegin(this->Content_);
	}

	inline auto TextFile::cend() const -> StringType::const_iterator
	{
		return std::cend(this->Content_);
	}

	inline auto TextFile::crbegin() const -> StringType::const_reverse_iterator
	{
		return std::crbegin(this->Content_);
	}

	inline auto TextFile::crend() const -> StringType::const_reverse_iterator
	{
		return std::crend(this->Content_);
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto begin(TextFile& file) -> TextFile::StringType::iterator
	{
		return file.begin();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto end(TextFile& file) -> TextFile::StringType::iterator
	{
		return file.end();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto rbegin(TextFile& file) -> TextFile::StringType::reverse_iterator
	{
		return file.rbegin();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto rend(TextFile& file) -> TextFile::StringType::reverse_iterator
	{
		return file.rend();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto cbegin(const TextFile& file) -> TextFile::StringType::const_iterator
	{
		return file.cbegin();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto cend(const TextFile& file) -> TextFile::StringType::const_iterator
	{
		return file.cend();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto crbegin(const TextFile& file) -> TextFile::StringType::const_reverse_iterator
	{
		return file.crbegin();
	}

	/// <summary>
	/// STL iterator compat.
	/// </summary>
	/// <returns></returns>
	[[nodiscard]]
	inline auto crend(const TextFile& file) -> TextFile::StringType::const_reverse_iterator
	{
		return file.crend();
	}
}
