#include "../../Include/Nominax/Foundation/DataStream.hpp"
#include "../../Include/Nominax/Foundation/PanicAssertions.hpp"

#define NOX_VALIDATE_HANDLE()                                                               \
	do                                                                                      \
	{                                                                                       \
	    NOX_DBG_PAS_NOT_NULL(this->Handle_, "Data stream handle is not initialized!");      \
	}                                                                                       \
	while(false)

namespace Nominax::Foundation
{
    auto DataStream::Write(const void* const buffer, const std::uint64_t size) const -> void
    {
        NOX_PAS(WriteUnchecked(buffer, size), "Data stream write failed!");
    }

    auto DataStream::Read(void* const buffer, const std::uint64_t size) const -> void
    {
        NOX_PAS(ReadUnchecked(buffer, size), "Data stream read failed!");
    }

    auto DataStream::WriteUnchecked(const void* const buffer, const std::uint64_t size) const -> bool
    {
        NOX_VALIDATE_HANDLE();
        return NOX_EXPECT_VALUE(std::fwrite(buffer, sizeof(std::uint8_t), size, this->Handle_) == size, true);
    }

    auto DataStream::ReadUnchecked(void* const buffer, const std::uint64_t size) const -> bool
    {
        NOX_VALIDATE_HANDLE();
        return NOX_EXPECT_VALUE(std::fread(buffer, sizeof(std::uint8_t), size, this->Handle_) == size, true);
    }

    auto DataStream::Flush() const -> void
    {
        NOX_VALIDATE_HANDLE();
        const bool status { std::fflush(this->Handle_) == 0 };
        NOX_PAS(status, "Data stream flush failed!");
    }

    auto DataStream::PutChar(const char x) const -> void
    {
        NOX_PAS(PutCharUnchecked(x), "Data stream write failed!");
    }

    auto DataStream::PutCharUnchecked(const char x) const -> bool
    {
        NOX_VALIDATE_HANDLE();
        return NOX_EXPECT_VALUE(std::putc(static_cast<int>(x), this->Handle_) != EOF, true);
    }

    auto DataStream::ReadLine(const std::span<char> span, std::uint64_t& size) const -> bool
    {
        NOX_VALIDATE_HANDLE();
        const char* const status { std::fgets(std::data(span), static_cast<int>(std::size(span)), this->Handle_) };
        const std::uint64_t len { std::strlen(std::data(span)) };
        size = len - 1;
        return status;
    }
}

#undef NOX_VALIDATE_HANDLE
