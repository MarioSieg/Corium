#pragma once

#include <cstdint>
#include <filesystem>
#include <fstream>

namespace Corium
{
    struct Compiler final
    {
        static constexpr std::string_view FILE_EXTENSION {".cor"};

        auto CompileFile(const std::filesystem::path& file) -> bool;
        auto CompileAllInDir(const std::filesystem::path& dir) -> bool;
        auto CompileAllInCurrentDir() -> bool;
    };
}