#pragma once

#define NOMINAX_OS_WINDOWS	false
#define NOMINAX_OS_MAC		false
#define NOMINAX_OS_LINUX	false
#define NOMINAX_OS_ANDROID	false
#define NOMINAX_OS_IOS		false
#define NOMINAX_ARCH_X86_32	false
#define NOMINAX_ARCH_X86_64	false
#define NOMINAX_ARCH_ARM_64	false
#define NOMINAX_ARCH_ARM_32	false
#define NOMINAX_RELEASE		false
#define NOMINAX_DEBUG		false

#define NOMINAX_32_BIT (NOMINAX_ARCH_X86_32 || NOMINAX_ARCH_ARM_32)
#define NOMINAX_64_BIT (NOMINAX_ARCH_X86_64 || NOMINAX_ARCH_ARM_64)

#define NOMINAX_POSIX (NOMINAX_OS_LINUX || NOMINAX_OS_ANDROID || NOMINAX_OS_MAC || NOMINAX_OS_IOS)

#if NDEBUG
#	undef NOMINAX_RELEASE
#	define NOMINAX_RELEASE true
#else
#	undef NOMINAX_DEBUG
#	define NOMINAX_DEBUG true
#endif

#if defined(_WIN32) || defined(_WIN64)
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

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#	undef NOMINAX_ARCH_X86_64
#	define NOMINAX_ARCH_X86_64 true
#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(_M_IX86) && !(defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64))
#	undef NOMINAX_ARCH_X86_32
#	define NOMINAX_ARCH_X86_32 true
#elif (defined(__arm__) || defined(_M_ARM)) && !defined(__aarch64__)
#	undef NOMINAX_ARCH_ARM_32
#	define NOMINAX_ARCH_ARM_32 true
#elif defined(__aarch64__)
#	undef NOMINAX_ARCH_ARM_64
#	define NOMINAX_ARCH_ARM_64 true
#else
#	error "platform.hpp: Unknown architecture!"
#endif
