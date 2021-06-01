#include "../../Include/Nominax/Common/TextFile.hpp"
#include "../../Include/Nominax/Common/BranchHint.hpp"

#include <algorithm>
#include <execution>
#include <locale>
#include <fstream>

namespace Nominax::Common
{
	[[nodiscard]]
	static inline auto SubstringView
	(
		const std::string& source, 
		const size_t offset = 0,
	    const std::string_view::size_type count = std::numeric_limits<std::string_view::size_type>::max()
	) noexcept(true) -> std::string_view
	{
		if (NOMINAX_LIKELY(offset < source.size())) 
		{
			return
			{
				source.data() + offset,
				std::min(source.size() - offset, 
				count)
			};
		}
		return {};
	}

	static inline auto SubstringView
	(
		std::string&& source,
		const size_t offset = 0,
		const std::string_view::size_type count = std::numeric_limits<std::string_view::size_type>::max()
	) noexcept(true) -> std::string_view = delete;
	
	auto TextFile::WriteToFile(std::filesystem::path&& path) noexcept(false) -> bool
	{
		this->FilePath_ = std::move(path);
		OutputStream stream{ this->FilePath_ };
		if (NOMINAX_UNLIKELY(!stream))
		{
			return false;
		}
		stream << this->Content_;
		return true;
	}

	auto TextFile::ReadFromFile(std::filesystem::path&& path) noexcept(false) -> bool
	{
		this->FilePath_ = std::move(path);
		InputStream stream{ this->FilePath_ };
		if (NOMINAX_UNLIKELY(!stream))
		{
			return false;
		}
		stream.seekg(0, std::ios::end);
		this->Content_.reserve(stream.tellg());
		stream.seekg(0, std::ios::beg);
		this->Content_.assign(std::istreambuf_iterator<CharType>{stream}, std::istreambuf_iterator<CharType>{});
		return true;
	}

	auto TextFile::EraseSpaces() noexcept(false) -> void
	{
		this->Content_.erase
		(
			std::remove_if(std::execution::par_unseq, std::begin(this->Content_), std::end(this->Content_),
				[](const char c) noexcept(true) -> bool
				{
					return c == ' ';
				}),
			std::end(this->Content_)
		);
	}

	auto TextFile::EraseSpacesAndControlChars() noexcept(false) -> void
	{
		this->Content_.erase
		(
			std::remove_if(std::execution::par_unseq, std::begin(this->Content_), std::end(this->Content_),
				[](const char c) noexcept(true) -> bool
				{
					return std::isspace<char>(c, std::locale::classic());
				}),
			std::end(this->Content_)
		);
	}

	auto TextFile::Erase(const char x) noexcept(false) -> void
	{
		this->Content_.erase
		(
			std::remove_if(std::execution::par_unseq, std::begin(this->Content_), std::end(this->Content_),
				[x](const char c) noexcept(true) -> bool
				{
					return c == x;
				}),
			std::end(this->Content_)
		);
	}

	auto TextFile::EraseRange(const char begin, const char end) noexcept(false) -> void
	{
		const std::size_t beginIndex{ this->Content_.find(begin) };
		const std::size_t endIndex{ this->Content_.find(end, beginIndex + 1) };
		[[maybe_unused]]
		const std::string_view substring{ SubstringView(this->Content_, beginIndex, endIndex - beginIndex) };
	}

	auto TextFile::SubString(const std::size_t beginIdx, const std::size_t endIdx) const noexcept(true) -> std::string_view
	{
		return SubstringView(this->Content_, beginIdx, endIdx - beginIdx + 1);
	}

	auto TextFile::SubStringChar(const char beginChar, const char endChar) const noexcept(true) -> std::string_view
	{
		const std::size_t beginIndex{ this->Content_.find_first_of(beginChar) };
		const std::size_t endIndex{ this->Content_.find_first_of(endChar, beginIndex + 1) };
		return SubstringView(this->Content_, beginIndex, endIndex - beginIndex + 1);
	}
}
