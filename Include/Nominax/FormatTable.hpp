// File: FormatTable.hpp
// Author: Mario
// Created: 19.04.2021 11:01
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

#include <iomanip>
#include <ios>
#include <vector>
#include <tuple>
#include <type_traits>
#include <cassert>
#include <cmath>

namespace Nominax
{
	/// <summary>
	/// Used to specify the column format
	/// </summary>
	enum class VariadicTableColumnFormat
	{
		Auto,
		Scientific,
		Fixed,
		Percent
	};

	/// <summary>
	/// Helper for pretty printing tables.
	/// </summary>
	/// <typeparam name="...Ts">The content types for each row.</typeparam>
	template <typename... Ts>
	class VariadicTable
	{
	public:
		/// <summary>
		/// The type stored for each row
		/// </summary>
		using DataTuple = std::tuple<Ts...>;

		/// <summary>
		/// Construct table from headers.
		/// </summary>
		/// <param name="headers"></param>
		/// <param name="staticColumnSize"></param>
		/// <param name="cellPadding"></param>
		explicit VariadicTable(std::vector<std::string>&& headers,
		                       std::size_t                staticColumnSize = 0,
		                       std::size_t                cellPadding      = 1);

		/// <summary>
		/// Add a row of data
		/// </summary>
		/// <param name="entries">The data tuple to add.</param>
		/// <returns></returns>
		auto AddRow(Ts&&...entries) -> void;

		/// <summary>
		/// Pretty print the table of data.
		/// </summary>
		/// <typeparam name="StreamType">The stream type to print into.</typeparam>
		/// <param name="stream">The stream to print into.</param>
		/// <returns></returns>
		template <typename StreamType>
		auto Print(StreamType& stream) -> void;

		/// <summary>
		/// Set how to format numbers for each column
		///	Note: this is ignored for std::string columns
		///	The format for each column: MUST be the same length as the number of columns.
		/// </summary>
		/// <param name="columnFormat">The precision for each column: MUST be the same length as the number of columns.</param>
		/// <returns></returns>
		auto SetColumnFormat(const std::vector<VariadicTableColumnFormat>& columnFormat) -> void;

		/// <summary>
		///  Set how many digits of precision to show for floating point numbers
		///	Note: this is ignored for std::string columns
		/// </summary>
		/// <param name="precision">The precision for each column: MUST be the same length as the number of columns.</param>
		/// <returns></returns>
		auto SetColumnPrecision(const std::vector<std::size_t>& precision) -> void;

	protected:
		using RightType = decltype(&std::right);
		using LeftType = decltype(&std::left);

		/// <summary>
		/// Attempts to figure out the correct justification for the data
		/// If it's a floating point value
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <typeparam name=""></typeparam>
		/// <param name="x"></param>
		/// <returns></returns>
		template <typename T,
		          typename = typename std::enable_if<
			          std::is_arithmetic<typename std::remove_reference<T>::type>::value>::type>
		static auto Justify(std::int32_t x) -> RightType;

		/// <summary>
		/// Otherwise.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="x"></param>
		/// <returns></returns>
		template <typename T>
		static auto Justify(std::int64_t x) -> LeftType;

		/// <summary>
		/// This ends the recursion
		/// </summary>
		/// <typeparam name="TupleType"></typeparam>
		/// <typeparam name="StreamType"></typeparam>
		/// <param name="tuple"></param>
		/// <param name="stream"></param>
		/// <param name="constant"></param>
		/// <returns></returns>
		template <typename TupleType, typename StreamType>
		auto PrintEach(TupleType&& tuple,
		               StreamType& stream,
		               std::integral_constant<
			               size_t,
			               std::tuple_size<typename std::remove_reference<TupleType>::type>::value> constant) -> void;
		/// <summary>
		/// This gets called on each item
		/// </summary>
		/// <typeparam name="TupleType"></typeparam>
		/// <typeparam name="StreamType"></typeparam>
		/// <typeparam name=""></typeparam>
		/// <param name="t"></param>
		/// <param name="stream"></param>
		/// <param name="constant"></param>
		/// <returns></returns>
		template <std::size_t I,
		          typename TupleType,
		          typename StreamType,
		          typename = typename std::enable_if<
			          I != std::tuple_size<typename std::remove_reference<TupleType>::type>::value>::type>
		auto PrintEach(TupleType&& t, StreamType& stream, std::integral_constant<size_t, I> constant) -> void;

		/// <summary>
		/// This is what gets called first
		/// </summary>
		/// <typeparam name="TupleType"></typeparam>
		/// <typeparam name="StreamType"></typeparam>
		/// <param name="t"></param>
		/// <param name="stream"></param>
		/// <returns></returns>
		template <typename TupleType, typename StreamType>
		auto PrintEach(TupleType&& t, StreamType& stream) -> void;

		/// <summary>
		/// Try to find the size the column will take up
		/// If the data type has a size() member... let's call it
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="data"></param>
		/// <param name="dummy"></param>
		/// <returns></returns>
		template <class T>
		static auto SizeOfData(const T& data, decltype(static_cast<T*>(nullptr)->size())* dummy = nullptr) -> size_t;

		/// <summary>
		///  Try to find the size the column will take up
		///  If the data type is an integer - let's get it's length
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="data"></param>
		/// <param name="restrictor"></param>
		/// <returns></returns>
		template <class T>
		auto SizeOfData(const T&                                                   data,
		                typename std::enable_if<std::is_integral<T>::value>::type* restrictor = nullptr) -> size_t;

		/// <summary>
		/// If it does not... let's just use a statically set size
		/// </summary>
		/// <returns></returns>
		auto SizeOfData(...) const -> size_t;

		/// <summary>
		/// End the recursion
		/// </summary>
		/// <typeparam name="TupleType"></typeparam>
		/// <param name="tuple"></param>
		/// <param name="sizes"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		template <typename TupleType>
		auto SizeEach(TupleType&&               tuple,
		              std::vector<std::size_t>& sizes,
		              std::integral_constant<
			              size_t,
			              std::tuple_size<typename std::remove_reference<TupleType>::type>::value> size) -> void;

		/// <summary>
		/// Recursively called for each element
		/// </summary>
		/// <typeparam name="TupleType"></typeparam>
		/// <typeparam name=""></typeparam>
		/// <param name="t"></param>
		/// <param name="sizes"></param>
		/// <param name="constant"></param>
		/// <returns></returns>
		template <std::size_t I,
		          typename TupleType,
		          typename = typename std::enable_if<
			          I != std::tuple_size<typename std::remove_reference<TupleType>::type>::value>::type>
		auto
		SizeEach(TupleType&& t, std::vector<std::size_t>& sizes, std::integral_constant<size_t, I> constant) -> void;

		/// <summary>
		/// The function that is actually called that starts the recursion
		/// </summary>
		/// <typeparam name="TupleType"></typeparam>
		/// <param name="tuple"></param>
		/// <param name="sizes"></param>
		/// <returns></returns>
		template <typename TupleType>
		auto SizeEach(TupleType&& tuple, std::vector<std::size_t>& sizes) -> void;

		/// <summary>
		///  Finds the size each column should be and set it in ColumnSizes
		/// </summary>
		/// <returns></returns>
		auto SizeColumns() -> void;

		/// The column headers
		std::vector<std::string> Headers { };

		/// Number of columns in the table
		std::size_t NumColumns { };

		/// Size of columns that we can't get the size of
		std::size_t StaticColumnSize { };

		/// Size of the cell padding
		std::size_t CellPadding { };

		/// The actual data
		std::vector<DataTuple> Data { };

		/// Holds the printable width of each column
		std::vector<std::size_t> ColumnSizes { };

		/// Column Format
		std::vector<VariadicTableColumnFormat> ColumnFormat { };

		/// Precision For each column
		std::vector<std::size_t> Precision { };
	};

	template <typename ... Ts>
	VariadicTable<Ts...>::VariadicTable(std::vector<std::string>&& headers, const std::size_t staticColumnSize, const std::size_t cellPadding): Headers(std::move(headers)),
		NumColumns(std::tuple_size<DataTuple>::value),
		StaticColumnSize(staticColumnSize),
		CellPadding(cellPadding) { }

	template <typename ... Ts>
	template <typename StreamType>
	inline auto VariadicTable<Ts...>::Print(StreamType& stream) -> void
	{
		SizeColumns();

		// Start computing the total width
		// First - we will have _num_columns + 1 "|" characters
		std::size_t totalWidth = NumColumns + 1;

		// Now add in the size of each column
		for (auto& colSize : ColumnSizes)
		{
			totalWidth += colSize + 2 * CellPadding;
		}

		// Print out the top line
		stream << std::string(totalWidth, '-') << "\n";

		// Print out the headers
		stream << "|";
		for (std::size_t i = 0; i < NumColumns; i++)
		{
			// Must find the center of the column
			auto half = ColumnSizes[i] / 2;
			half -= Headers[i].size() / 2;

			stream << std::string(CellPadding, ' ') << std::setw(ColumnSizes[i]) << std::left
				<< std::string(half, ' ') + Headers[i] << std::string(CellPadding, ' ') << "|";
		}

		stream << "\n";

		// Print out the line below the header
		stream << std::string(totalWidth, '-') << "\n";

		// Now print the rows of the table
		for (auto& row : Data)
		{
			stream << "|";
			PrintEach(row, stream);
			stream << "\n";
		}

		// Print out the line below the header
		stream << std::string(totalWidth, '-') << "\n";
	}

	template <typename ... Ts>
	inline auto VariadicTable<Ts...>::SetColumnFormat(const std::vector<VariadicTableColumnFormat>& columnFormat) -> void
	{
		if (columnFormat.size() == std::tuple_size<DataTuple>::value)
		[[likely]]
		{
			ColumnFormat = columnFormat;
		}
	}

	template <typename ... Ts>
	inline auto VariadicTable<Ts...>::SetColumnPrecision(const std::vector<std::size_t>& precision) -> void
	{
		if (precision.size() == std::tuple_size<DataTuple>::value)
		[[unlikely]]
		{
			this->Precision = precision;
		}
	}

	template <typename ... Ts>
	template <typename T, typename>
	inline auto VariadicTable<Ts...>::Justify(std::int32_t) -> RightType
	{
		return std::right;
	}

	template <typename ... Ts>
	template <typename T>
	inline auto VariadicTable<Ts...>::Justify(std::int64_t) -> LeftType
	{
		return std::left;
	}

	template <typename ... Ts>
	template <typename TupleType, typename StreamType>
	inline auto VariadicTable<Ts...>::PrintEach(TupleType&&, StreamType&, std::integral_constant<size_t, std::tuple_size<typename std::remove_reference<TupleType>::type>::value>) -> void { }

	template <typename ... Ts>
	template <std::size_t I, typename TupleType, typename StreamType, typename>
	inline auto VariadicTable<Ts...>::PrintEach(TupleType&& t, StreamType& stream, std::integral_constant<size_t, I>) -> void
	{
		auto& val = std::get<I>(t);

		// Set the precision
		if (!Precision.empty()) [[unlikely]]
		{
			stream << std::setprecision(Precision[I]);
		}

		// Set the format
		if (!ColumnFormat.empty()) [[unlikely]]
		{
			if (ColumnFormat[I] == VariadicTableColumnFormat::Scientific) [[unlikely]]
			{
				stream << std::scientific;
			}

			if (ColumnFormat[I] == VariadicTableColumnFormat::Fixed) [[likely]]
			{
				stream << std::fixed;
			}

			if (ColumnFormat[I] == VariadicTableColumnFormat::Percent) [[unlikely]]
			{
				stream << std::fixed << std::setprecision(2);
			}
		}

		stream << std::string(CellPadding, ' ') << std::setw(ColumnSizes[I])
			<< Justify<decltype(val)>(0) << val << std::string(CellPadding, ' ') << "|";

		// Unset the format
		if (!ColumnFormat.empty())
		{
			stream.unsetf(std::ios_base::floatfield);
		}

		// Recursive call to print the next item
		PrintEach(std::forward<TupleType>(t), stream, std::integral_constant<size_t, I + 1>());
	}

	template <typename ... Ts>
	template <typename TupleType, typename StreamType>
	inline auto VariadicTable<Ts...>::PrintEach(TupleType&& t, StreamType& stream) -> void
	{
		PrintEach(std::forward<TupleType>(t), stream, std::integral_constant<size_t, 0>());
	}

	template <typename ... Ts>
	template <class T>
	inline auto VariadicTable<Ts...>::SizeOfData(const T& data, typename std::enable_if<std::is_integral<T>::value>::type*) -> size_t
	{
		if (data == 0)
		[[unlikely]]
		{
			return 1;
		}

		return std::log10(data) + 1;
	}

	template <typename ... Ts>
	inline auto VariadicTable<Ts...>::SizeOfData(...) const -> size_t { return StaticColumnSize; }

	template <typename ... Ts>
	template <typename TupleType>
	inline auto VariadicTable<Ts...>::SizeEach(TupleType&&                                                                                            , std::vector<std::size_t>&,
	                                           std::integral_constant<size_t, std::tuple_size<typename std::remove_reference<TupleType>::type>::value>) -> void { }

	template <typename ... Ts>
	template <std::size_t I, typename TupleType, typename>
	inline auto VariadicTable<Ts...>::SizeEach(TupleType&& t, std::vector<std::size_t>& sizes, std::integral_constant<size_t, I>) -> void
	{
		sizes[I] = SizeOfData(std::get<I>(t));

		// Override for Percent
		if (!ColumnFormat.empty())
		[[unlikely]]
		{
			if (ColumnFormat[I] == VariadicTableColumnFormat::Percent)
			{
				sizes[I] = 6; // 100.00
			}
		}

		// Continue the recursion
		SizeEach(std::forward<TupleType>(t), sizes, std::integral_constant<size_t, I + 1>());
	}

	template <typename ... Ts>
	template <typename TupleType>
	inline auto VariadicTable<Ts...>::SizeEach(TupleType&& tuple, std::vector<std::size_t>& sizes) -> void
	{
		SizeEach(std::forward<TupleType>(tuple), sizes, std::integral_constant<size_t, 0>());
	}

	template <typename ... Ts>
	inline auto VariadicTable<Ts...>::SizeColumns() -> void
	{
		ColumnSizes.resize(NumColumns);

		// Temporary for querying each row
		std::vector columnSizes {NumColumns};

		// Start with the size of the headers
		for (std::size_t i {0}; i < NumColumns; i++)
		{
			ColumnSizes[i] = Headers[i].size();
		}

		// Grab the size of each entry of each row and see if it's bigger
		for (auto& row : Data)
		{
			SizeEach(row, columnSizes);

			for (std::size_t i {0}; i < NumColumns; i++)
			{
				ColumnSizes[i] = std::max(ColumnSizes[i], columnSizes[i]);
			}
		}
	}

	template <typename ... Ts>
	template <class T>
	inline auto VariadicTable<Ts...>::SizeOfData(const T& data, decltype(static_cast<T*>(nullptr)->size())*) -> size_t
	{
		return data.size();
	}

	template <typename ... Ts>
	inline auto VariadicTable<Ts...>::AddRow(Ts&&...entries) -> void
	{
		Data.emplace_back(std::make_tuple(entries...));
	}
}
