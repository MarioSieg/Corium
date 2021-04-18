#pragma once

#include <cstddef>
#include <stdexcept>

namespace Nominax 
{
	/// <summary>
	/// Represents a UTF-32 string.
	/// It uses malloc/calloc/realloc/free from C for faster buffer reallocation,
	/// explicit SIMD vectorization using intrinsics and more optimizations.
	/// This is a custom implementation, which aims to be faster than std::u32string.
	/// </summary>
	class Utf32String final 
	{
		char32_t* Buffer { nullptr };
		std::size_t Size { 0 };
		std::size_t Capacity { 0 };

	public:
		/// <summary>
		/// Construct empty string.
		/// </summary>
		/// <returns></returns>
		constexpr Utf32String() noexcept = default;

		/// <summary>
		/// Construct with capacity.
		/// </summary>
		/// <param name="capacity">The amount of characters to allocate for.</param>
		explicit Utf32String(std::size_t capacity);

		/// <summary>
		/// Copy construct from u32 string view.
		/// </summary>
		/// <param name="view">The view to copy source data from.</param>
		explicit Utf32String(std::u32string_view view);

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="other">The string to copy.</param>
		Utf32String(const Utf32String& other);

		/// <summary>
		/// Move constructor.
		/// </summary>
		/// <param name="other">The string to move into self..</param>
		Utf32String(Utf32String&& other);

		/// <summary>
		/// Copy assignment operator.
		/// </summary>
		/// <param name="other">The string to copy into self.</param>
		/// <returns>Self</returns>
		auto operator =(const Utf32String& other) -> Utf32String&;

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="other">The string to move into self.</param>
		/// <returns>Self</returns>
		auto operator =(Utf32String&& other) -> Utf32String&;

		/// <summary>
		/// Deallocate and set everything to 0.
		/// </summary>
		~Utf32String();

		/// <summary>
		/// Clears buffer and sets size to 0 but does not deallocate any memory.
		/// Capacity stays the same.
		/// </summary>
		/// <returns></returns>
		auto Clear() -> void;

		/// <summary>
		/// Get the underlying buffer pointer.
		/// </summary>
		/// <returns>The underlying buffer pointer.</returns>
		[[nodiscard]] auto GetCStr() const noexcept -> const char32_t*;

		/// <summary>
		/// Get the number of characters in the string.
		/// </summary>
		/// <returns>The number of characters in the string.</returns>
		[[nodiscard]] auto GetSize() const noexcept -> std::size_t;

		/// <summary>
		/// Get the number of character allocated in the buffer.
		/// </summary>
		/// <returns>The number of character allocated in the buffer.</returns>
		[[nodiscard]] auto GetCapacity() const noexcept -> std::size_t;

		/// <summary>
		/// Unchecked lookup at index.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns>char32_t reference at index.</returns>
		[[nodiscard]] 
		auto operator [](std::size_t idx) noexcept -> char32_t&;

		/// <summary>
		/// Unchecked lookup at index.
		/// </summary>
		/// <param name="idx"></param>
		/// <returns>char32_t value at index.</returns>
		[[nodiscard]] 
		auto operator [](std::size_t idx) const noexcept -> char32_t;
 	};

	inline auto Utf32String::GetCStr() const noexcept -> const char32_t*
	{
		return this->Buffer;
	}

	inline auto Utf32String::GetSize() const noexcept -> std::size_t
	{
		return this->Size;
	}

	inline auto Utf32String::GetCapacity() const noexcept -> std::size_t
	{
		return this->Capacity;
	}

	inline auto Utf32String::operator [](const std::size_t idx) noexcept -> char32_t&
	{
		return *(this->Buffer + idx);
	}

	inline auto Utf32String::operator [](const std::size_t idx) const noexcept -> char32_t
	{
		return *(this->Buffer + idx);
	}
}
