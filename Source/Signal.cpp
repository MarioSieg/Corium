// Nominax Runtime System
// Copyright (c) 2021 Mario Sieg <mt3000@gmx.de>, Germany
// See README and LICENSE!

#include "../Include/Nominax/Signal.hpp"

namespace {
	volatile std::sig_atomic_t SignalStatus = 0;
}

namespace Nominax {
	auto SignalStatus(volatile std::sig_atomic_t& out) noexcept -> bool {
		out = ::SignalStatus;
		return out != 0;
	}

	void DefaultSignalHandler(const int signal) {
		::SignalStatus = signal;
	}

	void InstallHandlers(void (*const handler)(int)) {
		std::signal(SIGINT, handler);
		std::signal(SIGILL, handler);
		std::signal(SIGFPE, handler);
		std::signal(SIGSEGV, handler);
		std::signal(SIGTERM, handler);
		std::signal(SIGBREAK, handler);
		std::signal(SIGABRT_COMPAT, handler);
	}
}
