#include "../../Include/Nominax/Foundation/DataStream.hpp"

namespace Nominax::Foundation
{
    auto DataStream::Write(const void* const buffer, const std::uint64_t size) -> void
    {
        const bool status { std::fwrite(buffer, sizeof(std::byte), size, this->Handle_) == size };
        NOX_PAS(status, "Data stream write failed!");
    }

    auto DataStream::Read(void* const buffer, const std::uint64_t size) -> void
    {
        const bool status { std::fread(buffer, sizeof(std::byte), size, this->Handle_) == size };
        NOX_PAS(status, "Data stream read failed!");
    }

    auto DataStream::WriteUnchecked(const void* const buffer, const std::uint64_t size) -> bool
    {
        return NOX_EXPECT_VALUE(std::fwrite(buffer, sizeof(std::byte), size, this->Handle_) == size, true);
    }

    auto DataStream::ReadUnchecked(void* const buffer, const std::uint64_t size) -> bool
    {
        return NOX_EXPECT_VALUE(std::fread(buffer, sizeof(std::byte), size, this->Handle_) == size, true);
    }

    auto DataStream::Flush() -> void
    {
        const bool status { std::fflush(this->Handle_) == 0 };
        NOX_PAS(status, "Data stream flush failed!");
    }

    auto DataStream::PutChar(const char x) -> void
    {
        const bool status { std::putc(static_cast<int>(x), this->Handle_) != EOF };
        NOX_PAS(status, "Data stream write failed!");
    }

    auto DataStream::PutCharUnchecked(const char x) -> bool
    {
        return NOX_EXPECT_VALUE(std::putc(static_cast<int>(x), this->Handle_) != EOF, true);
    }
}
