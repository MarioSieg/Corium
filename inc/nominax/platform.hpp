#pragma once

#define NOMINAX_OS_WINDOWS	false
#define NOMINAX_OS_MAC		false
#define NOMINAX_OS_LINUX	false
#define NOMINAX_OS_ANDROID	false
#define NOMINAX_OS_IOS		false
#define NOMINAX_POSIX (NOMINAX_OS_LINUX || NOMINAX_OS_ANDROID || NOMINAX_OS_MAC || NOMINAX_OS_IOS)
#define NOMINAX_ARCH_X86_64	false
#define NOMINAX_ARCH_ARM_64	false

#ifdef _WIN64
#	undef NOMINAX_OS_WINDOWS
#	define NOMINAX_OS_WINDOWS true
#elif defined(__APPLE__)
#	include <TargetConditionals.h>
#	if TARGET_OS_MAC
#		undef NOMINAX_OS_MAC
#		define NOMINAX_OS_MAC true
#	elif defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR)
#		undef NOMINAX_OS_IOS
#		define NOMINAX_OS_IOS true
#	else
#		error "platform.hpp: Unknown Apple OS!"
#	endif
#elif defined(__linux__)
#	ifdef __ANDROID__
#		undef NOMINAX_OS_ANDROID
#		define NOMINAX_OS_ANDROID true
#	endif
#	undef NOMINAX_OS_LINUX
#	define NOMINAX_OS_LINUX true
#else
#	error "platform.hpp: Unknown operating system!"
#endif

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64)
#	undef NOMINAX_ARCH_X86_64
#	define NOMINAX_ARCH_X86_64 true
#elif defined(__aarch64__)
#	undef NOMINAX_ARCH_ARM_64
#	define NOMINAX_ARCH_ARM_64 true
#else
#	error "platform.hpp: Unknown architecture!"
#endif
