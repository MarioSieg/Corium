#include "Compiler.hpp"

#include "antlr4-runtime.h"
#include "../Parser/CoriumParser.h"
#include "../Parser/CoriumLexer.h"

#include <Nominax/Nominax.hpp>

using Nominax::Foundation::LogLevel;
using Nominax::Foundation::Print;

namespace Corium
{
    auto Compiler::CompileFile(const std::filesystem::path &file) -> bool
    try
    {
        std::ifstream stream{file};
        if (!stream)
        {
            [[nodiscard]]
            return false;
        }
        antlr4::ANTLRInputStream input{stream};
        CoriumLexer lexer{&input};
        antlr4::CommonTokenStream tokens{&lexer};
        tokens.fill();
        CoriumParser parser{&tokens};
        auto* output{parser.compilationUnit()};
        if (!output->isEmpty())
        {
            std::cout << output->toString() << '\n';
        }
        return true;
    }
    catch(...)
    {
        return false;
    }

    auto Compiler::CompileAllInCurrentDir() -> bool
    {
        return this->CompileAllInDir(std::filesystem::current_path());
    }

    auto Compiler::CompileAllInDir(const std::filesystem::path& dir) -> bool
    {
        if (!std::filesystem::exists(dir))
        {
            Print(LogLevel::Error, "No Corium ({}) files found in dir: {}\n", FILE_EXTENSION, dir.string());
            [[nodiscard]]
            return false;
        }
        std::uint32_t compiledFiles {};
        for (const auto& file : std::filesystem::recursive_directory_iterator{dir})
        {
            const auto& path{file.path()};
            if (!path.has_extension() || path.extension() != FILE_EXTENSION)
            {
                continue;
            }
            Print(LogLevel::Warning, "Compiling: {}\n", path.string());
            if (!this->CompileFile(path))
            {
                return false;
            }
            ++compiledFiles;
        }

        if (compiledFiles)
        {
            Print(LogLevel::Success, "Compiled {} files!\n", compiledFiles);
        }
        else
        {
            Print(LogLevel::Error, "No Corium ({}) files found in dir: {}\n", FILE_EXTENSION, dir.string());
        }

        return true;
    }
}
