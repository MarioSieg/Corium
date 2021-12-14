#include "../../Include/Nominax/Foundation/DataStream.hpp"
#include "../../Include/Nominax/Foundation/Panic/Assertions.hpp"

namespace Nominax::Foundation
{
    auto DataStream::Write(const void* const buffer, const std::uint64_t size) const -> void
    {
        Foundation::Assert(WriteUnchecked(buffer, size), "Data stream write failed!");
    }

    auto DataStream::Write(const std::string_view str) const -> void
    {
        Foundation::Assert(WriteUnchecked(str), "Data stream write failed!");
    }

    auto DataStream::Read(void* const buffer, const std::uint64_t size) const -> void
    {
        Foundation::Assert(ReadUnchecked(buffer, size), "Data stream read failed!");
    }

    auto DataStream::WriteUnchecked(const void* const buffer, const std::uint64_t size) const -> bool
    {
        Foundation::Assert(this->Handle_, "Data stream handle is not initialized!");
        return NOX_EXPECT_VALUE(std::fwrite(buffer, sizeof(std::uint8_t), size, this->Handle_) == size, true);
    }

    auto DataStream::WriteUnchecked(const std::string_view str) const -> bool
    {
        Foundation::Assert(this->Handle_, "Data stream handle is not initialized!");
        return NOX_EXPECT_VALUE(std::fwrite(std::data(str), sizeof(std::string_view::value_type), std::size(str), this->Handle_) == std::size(str), true);
    }

    auto DataStream::ReadUnchecked(void* const buffer, const std::uint64_t size) const -> bool
    {
        Foundation::Assert(this->Handle_, "Data stream handle is not initialized!");
        return NOX_EXPECT_VALUE(std::fread(buffer, sizeof(std::uint8_t), size, this->Handle_) == size, true);
    }

    auto DataStream::Flush() const -> void
    {
        Foundation::Assert(this->Handle_, "Data stream handle is not initialized!");
        const bool status { std::fflush(this->Handle_) == 0 };
        Foundation::Assert(status, "Data stream flush failed!");
    }

    auto DataStream::PutChar(const char x) const -> void
    {
        Foundation::Assert(PutCharUnchecked(x), "Data stream write failed!");
    }

    auto DataStream::PutCharUnchecked(const char x) const -> bool
    {
        Foundation::Assert(this->Handle_, "Data stream handle is not initialized!");
        return NOX_EXPECT_VALUE(std::putc(static_cast<int>(x), this->Handle_) != EOF, true);
    }

    auto DataStream::ReadLine(const std::span<char> span, std::uint64_t& size) const -> bool
    {
        Foundation::Assert(this->Handle_, "Data stream handle is not initialized!");
        const char* const status { std::fgets(std::data(span), static_cast<int>(std::size(span)), this->Handle_) };
        const std::uint64_t len { std::strlen(std::data(span)) };
        size = len - 1;
        return status;
    }
}

#undef NOX_VALIDATE_HANDLE
