#include "../Include/Nominax/Utf32String.hpp"

namespace Nominax
{
	Utf32String::Utf32String(const std::size_t capacity) : Capacity { capacity }
	{
		this->Buffer = static_cast<char32_t*>(calloc(capacity, sizeof(char32_t)));
		if (!this->Buffer) [[unlikely]]
		{
			throw std::bad_alloc{};
		}
	}

	Utf32String::Utf32String(const std::u32string_view view) : Size{view.size()}, Capacity{view.size()}
	{
		this->Buffer = static_cast<char32_t*>(malloc(sizeof(char32_t) * this->Size));
		if (!this->Buffer) [[unlikely]]
		{
			throw std::bad_alloc{};
		}
		memcpy(this->Buffer, view.data(), sizeof(char32_t) * this->Size);
	}

	Utf32String::Utf32String(const Utf32String& other)
	{
		// Allocate buffer:
		this->Buffer = static_cast<char32_t*>(malloc(other.Size * sizeof(char32_t)));
		if (!this->Buffer) [[unlikely]]
		{
			throw std::bad_alloc{};
		}

		// Copy the string data:
		memcpy(this->Buffer, other.Buffer, sizeof(char32_t) * other.Size);

		this->Capacity = this->Size =  other.Size;
	}

	Utf32String::Utf32String(Utf32String&& other)
	{
		this->Buffer = other.Buffer;
		this->Size = other.Size;
		this->Capacity = other.Capacity;

		other.Buffer = nullptr;
		other.Size = other.Capacity = 0;
	}

	auto Utf32String::operator=(const Utf32String& other) -> Utf32String&
	{
		// If the other string is larger or smaller, we want the exact same size.
		if (this->Capacity != other.Size) [[likely]]
		{
			auto* __restrict__ const buffer = static_cast<char32_t*>(realloc(this->Buffer, sizeof(char32_t) * other.Size));
			if (!buffer)
			{
				throw std::bad_alloc{};
			}
			this->Buffer = buffer;
		}

		// Copy the string data:
		memcpy(this->Buffer, other.Buffer, sizeof(char32_t) * other.Size);

		this->Capacity = this->Size = other.Size;

		return *this;
	}

	auto Utf32String::operator=(Utf32String&& other) -> Utf32String&
	{
		if (this->Buffer) [[unlikely]]
		{
			free(this->Buffer);
		}

		this->Buffer = other.Buffer;
		this->Size = other.Size;
		this->Capacity = other.Capacity;

		other.Buffer = nullptr;
		other.Size = other.Capacity = 0;

		return *this;
	}

	Utf32String::~Utf32String()
	{
		if (this->Buffer) [[likely]]
		{
			free(this->Buffer);
		}
		this->Buffer = nullptr;
		this->Size = 0;
		this->Capacity = 0;
	}

	auto Utf32String::Clear() -> void
	{
		memset(this->Buffer, 0, sizeof(char32_t) * this->Size);
		this->Size = 0;
	}
}
