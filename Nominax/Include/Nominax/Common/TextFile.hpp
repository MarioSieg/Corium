#pragma once

#include <filesystem>
#include <string>
#include <string_view>

namespace Nominax::Common
{
	/// <summary>
	/// Helper to work with text files.
	/// </summary>
	class TextFile final
	{
		/// <summary>
		/// The content of the file.
		/// </summary>
		std::string Content_{};

		/// <summary>
		/// The path of the file.
		/// </summary>
		std::filesystem::path FilePath_{};

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
		TextFile() noexcept(true) = default;

		/// <summary>
		/// Construct with content.
		/// </summary>
		/// <param name="content">Content of the file.</param>
		/// <returns></returns>
		explicit TextFile(std::string&& content) noexcept(true);

		/// <summary>
		/// Construct with path and content.
		/// </summary>
		/// <param name="path"></param>
		/// <param name="content"></param>
		/// <returns></returns>
		TextFile(std::filesystem::path&& path, std::string&& content) noexcept(true);

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
		auto operator =(const TextFile& other)->TextFile & = delete;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other"></param>
		/// <returns></returns>
		auto operator =(TextFile&& other)->TextFile & = default;

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
		auto WriteToFile(std::filesystem::path&& path) noexcept(false) -> bool;

		/// <summary>
		/// Reads the content of the path into this class instance content.
		/// </summary>
		/// <param name="path"></param>
		/// <returns>True on success, else false.</returns>
		[[nodiscard]]
		auto ReadFromFile(std::filesystem::path&& path) noexcept(false) -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current text file content.</returns>
		[[nodiscard]]
		auto GetContentText() const & noexcept(true) -> const std::string&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current text file content.</returns>
		[[nodiscard]]
		auto GetContentText() && noexcept(true) -> std::string&&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current file path.</returns>
		[[nodiscard]]
		auto GetFilePath() const & noexcept(true) -> const std::filesystem::path&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The current file path.</returns>
		[[nodiscard]]
		auto GetFilePath() && noexcept(true) -> std::filesystem::path&&;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>True if the content is empty, else false.</returns>
		[[nodiscard]]
		auto IsEmpty() const noexcept(true) -> bool;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The capacity of the content.</returns>
		[[nodiscard]]
		auto GetCapacity() const noexcept(true) -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the content - the number of characters.</returns>
		[[nodiscard]]
		auto GetSize() const noexcept(true) -> std::size_t;

		/// <summary>
		/// 
		/// </summary>
		/// <returns>The size of the content in bytes (capacity * charSize)</returns>
		[[nodiscard]]
		auto GetSizeInBytes() const noexcept(true) -> std::size_t;

		/// <summary>
		/// Removes all the spaces (' ') from the content in parallel.
		/// </summary>
		/// <returns></returns>
		auto EraseSpaces() noexcept(false) -> void;

		/// <summary>
		/// Removes all spaces and control characters from the content in parallel.
		/// </summary>
		/// <returns></returns>
		auto EraseSpacesAndControlChars() noexcept(false) -> void;

		/// <summary>
		/// Removes all the occurrences of the character in parallel.
		/// </summary>
		/// <param name="x"></param>
		/// <returns></returns>
		auto Erase(char x) noexcept(false) -> void;

		/// <summary>
		/// Searches all the ranges between the two chars and removes the text between them and themselves.
		/// </summary>
		/// <param name="begin"></param>
		/// <param name="end"></param>
		/// <returns></returns>
		auto EraseRange(char begin, char end) noexcept(false) -> void;

		/// <summary>
		/// Get a substring string view to the
		/// content between the two indices (both inclusive).
		/// </summary>
		/// <param name="beginIdx"></param>
		/// <param name="endIdx"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto SubString(std::size_t beginIdx, std::size_t endIdx) const noexcept(true) -> std::string_view;

		/// <summary>
		/// Get a substring string view to the
		/// content between the two first chars found (both inclusive).
		/// </summary>
		/// <param name="beginChar"></param>
		/// <param name="endChar"></param>
		/// <returns></returns>
		[[nodiscard]]
		auto SubStringChar(char beginChar, char endChar) const noexcept(true) -> std::string_view;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto begin() noexcept(true) -> std::string::iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto end() noexcept(true) -> std::string::iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto rbegin() noexcept(true) -> std::string::reverse_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto rend() noexcept(true) -> std::string::reverse_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto cbegin() const noexcept(true) -> std::string::const_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto cend() const noexcept(true) -> std::string::const_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto crbegin() const noexcept(true) -> std::string::const_reverse_iterator;

		/// <summary>
		/// STL iterator compat.
		/// </summary>
		/// <returns></returns>
		[[nodiscard]]
		auto crend() const noexcept(true) -> std::string::const_reverse_iterator;
	};

	inline TextFile::TextFile(std::string&& content) noexcept(true)
		: Content_{ std::move(content) }
	{
		
	}

	inline TextFile::TextFile(std::filesystem::path&& path, std::string&& content) noexcept(true)
		: Content_{ std::move(content) },
		FilePath_{ std::move(path) }
	{

	}

	inline auto TextFile::GetContentText() const & noexcept(true) -> const std::string&
	{
		return this->Content_;
	}

	inline auto TextFile::GetContentText() && noexcept(true) -> std::string&&
	{
		return std::move(this->Content_);
	}

	inline auto TextFile::GetFilePath() const & noexcept(true) -> const std::filesystem::path&
	{
		return this->FilePath_;
	}

	inline auto TextFile::GetFilePath() && noexcept(true) -> std::filesystem::path&&
	{
		return std::move(this->FilePath_);
	}

	inline auto TextFile::IsEmpty() const noexcept(true) -> bool
	{
		return this->Content_.empty();
	}

	inline auto TextFile::GetCapacity() const noexcept(true) -> std::size_t
	{
		return this->Content_.capacity();
	}

	inline auto TextFile::GetSize() const noexcept(true) -> std::size_t
	{
		return this->Content_.size();
	}

	inline auto TextFile::GetSizeInBytes() const noexcept(true) -> std::size_t
	{
		return this->Content_.capacity() * sizeof(char8_t);
	}

	inline auto TextFile::begin() noexcept(true) -> std::string::iterator
	{
		return std::begin(this->Content_);
	}

	inline auto TextFile::end() noexcept(true) -> std::string::iterator
	{
		return std::end(this->Content_);
	}

	inline auto TextFile::rbegin() noexcept(true) -> std::string::reverse_iterator
	{
		return std::rbegin(this->Content_);
	}

	inline auto TextFile::rend() noexcept(true) -> std::string::reverse_iterator
	{
		return std::rend(this->Content_);
	}

	inline auto TextFile::cbegin() const noexcept(true) -> std::string::const_iterator
	{
		return std::cbegin(this->Content_);
	}

	inline auto TextFile::cend() const noexcept(true) -> std::string::const_iterator
	{
		return std::cend(this->Content_);
	}

	inline auto TextFile::crbegin() const noexcept(true) -> std::string::const_reverse_iterator
	{
		return std::crbegin(this->Content_);
	}

	inline auto TextFile::crend() const noexcept(true) -> std::string::const_reverse_iterator
	{
		return std::crend(this->Content_);
	}
}
