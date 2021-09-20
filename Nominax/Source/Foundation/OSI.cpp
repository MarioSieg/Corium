#include <thread>

#include "../../../Include/Nominax/Foundation/OSInterface.hpp"

namespace Nominax::Foundation
{
    auto OSI::QueryLogicalCPUCount() -> std::uint32_t
    {
        static std::uint64_t THREADS { std::thread::hardware_concurrency() };
        return THREADS;
    }
}