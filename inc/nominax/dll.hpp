#pragma once

#include <filesystem>

#include "os.hpp"

namespace nominax {
	/* Represents a procedure address inside a dynamic library. */
	struct dylib_proc final {
		constexpr explicit dylib_proc(void* ptr_) noexcept;
		explicit dylib_proc(std::nullptr_t) = delete;

		template <typename F> requires std::is_function_v<F>
		auto operator*() const noexcept -> F&;

		template <typename F, typename... Ts> requires std::is_function_v<F> && std::is_invocable_v<F, Ts...>
		auto operator()(Ts&&... args_) const noexcept -> decltype(F(std::forward<Ts...>(args_...)));

	private:
		void* ptr{nullptr};
	};

	static_assert(std::is_copy_constructible_v<dylib_proc>);
	static_assert(std::is_move_assignable_v<dylib_proc>);
	static_assert(std::is_trivially_copy_assignable_v<dylib_proc>);
	static_assert(std::is_trivially_move_assignable_v<dylib_proc>);

	constexpr dylib_proc::dylib_proc(void* const ptr_) noexcept : ptr{ptr_} {}

	template <typename F> requires std::is_function_v<F>
	inline auto dylib_proc::operator*() const noexcept -> F& {
		return *reinterpret_cast<F*>(this->ptr);
	}

	template <typename F, typename ... Ts> requires std::is_function_v<F> && std::is_invocable_v<F, Ts...>
	inline auto dylib_proc::operator()(Ts&&... args_) const noexcept -> decltype(F(std::forward<Ts...>(args_...))) {
		return (*reinterpret_cast<F*>(this->ptr))(std::forward<Ts...>(args_...));
	}

	/* Represents a dynamically linked library. (.dll, .so) */
	struct dylib final {
		explicit dylib(std::string_view path_);
		explicit dylib(const std::filesystem::path& path_);
		dylib(const dylib&) = delete;
		dylib(dylib&&) = delete;
		auto operator =(const dylib&) -> dylib& = delete;
		auto operator =(dylib&&) -> dylib& = delete;
		~dylib();

		[[nodiscard]] operator bool() const noexcept;
		[[nodiscard]] auto operator [](std::string_view name_) const -> dylib_proc;
	
	private:
		void* handle{nullptr};
	};

	static_assert(!std::is_copy_constructible_v<dylib>);
	static_assert(!std::is_move_assignable_v<dylib>);
	static_assert(!std::is_trivially_copy_assignable_v<dylib>);
	static_assert(!std::is_trivially_move_assignable_v<dylib>);

	inline dylib::dylib(const std::string_view path_) : handle{os::dylib_open(path_)} { }
	inline dylib::dylib(const std::filesystem::path& path_) : handle{os::dylib_open(path_.string())} { }
	
	inline dylib::~dylib() {
		os::dylib_close(this->handle);
	}
	
	inline dylib::operator bool() const noexcept {
		return this->handle != nullptr;
	}

	inline auto dylib::operator[](const std::string_view name_) const -> dylib_proc {
		return dylib_proc{os::dylib_lookup_symbol(this->handle, name_)};
	}
}
