// Nominax Runtime System
// Copyright (c) 2021 Mario Sieg <mt3000@gmx.de>, Germany
// See README and LICENSE!

#pragma once

#include <csignal>

namespace Nominax {
	extern auto SignalStatus(volatile std::sig_atomic_t& out) noexcept -> bool;
	extern void DefaultSignalHandler(int signal);
	extern void InstallHandlers(void (*handler)(int));
}