#pragma once

#include <filesystem>

#include "OS.hpp"

namespace Nominax
{
	/* Represents a procedure address inside a dynamic library. */
	struct DynamicProcedure final
	{
		constexpr explicit DynamicProcedure(void* value) noexcept;
		explicit DynamicProcedure(std::nullptr_t) = delete;

		template <typename F> requires std::is_function_v<F>
		auto operator*() const noexcept -> F&;

		template <typename F, typename... Ts> requires std::is_function_v<F> && std::is_invocable_v<F, Ts...>
		auto operator()(Ts&&... args) const noexcept -> decltype(F(std::forward<Ts...>(args...)));

	private:
		void* Ptr{nullptr};
	};

	static_assert(std::is_copy_constructible_v<DynamicProcedure>);
	static_assert(std::is_move_assignable_v<DynamicProcedure>);
	static_assert(std::is_trivially_copy_assignable_v<DynamicProcedure>);
	static_assert(std::is_trivially_move_assignable_v<DynamicProcedure>);

	constexpr DynamicProcedure::DynamicProcedure(void* const value) noexcept : Ptr{value} { }

	template <typename F> requires std::is_function_v<F>
	inline auto DynamicProcedure::operator*() const noexcept -> F&
	{
		return *static_cast<F*>(this->Ptr);
	}

	template <typename F, typename ... Ts> requires std::is_function_v<F> && std::is_invocable_v<F, Ts...>
	auto DynamicProcedure::operator()(Ts&&... args) const noexcept -> decltype(F(std::forward<Ts...>(args...)))
	{
		return (*static_cast<F*>(this->Ptr))(std::forward<Ts...>(args...));
	}

	/* Represents a dynamically linked library. (.dll, .so) */
	struct DynamicLibrary final
	{
		explicit DynamicLibrary(std::string_view filePath);
		explicit DynamicLibrary(const std::filesystem::path& filePath);
		DynamicLibrary(const DynamicLibrary&) = delete;
		DynamicLibrary(DynamicLibrary&&) = delete;
		auto operator =(const DynamicLibrary&) -> DynamicLibrary& = delete;
		auto operator =(DynamicLibrary&&) -> DynamicLibrary& = delete;
		~DynamicLibrary();

		[[nodiscard]] operator bool() const noexcept;
		[[nodiscard]] auto operator [](std::string_view symbolName) const -> DynamicProcedure;

	private:
		void* Handle{nullptr};
	};

	static_assert(!std::is_copy_constructible_v<DynamicLibrary>);
	static_assert(!std::is_move_assignable_v<DynamicLibrary>);
	static_assert(!std::is_trivially_copy_assignable_v<DynamicLibrary>);
	static_assert(!std::is_trivially_move_assignable_v<DynamicLibrary>);

	inline DynamicLibrary::DynamicLibrary(const std::string_view filePath) : Handle{OS::dylib_open(filePath)} { }

	inline DynamicLibrary::DynamicLibrary(const std::filesystem::path& filePath) : Handle{
		OS::dylib_open(filePath.string())
	} { }

	inline DynamicLibrary::~DynamicLibrary()
	{
		OS::dylib_close(this->Handle);
	}

	inline DynamicLibrary::operator bool() const noexcept
	{
		return this->Handle != nullptr;
	}

	inline auto DynamicLibrary::operator[](const std::string_view symbolName) const -> DynamicProcedure
	{
		return DynamicProcedure{OS::dylib_lookup_symbol(this->Handle, symbolName)};
	}
}
