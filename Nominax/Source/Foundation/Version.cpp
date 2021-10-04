#include "../../Include/Nominax/Foundation/Version.hpp"
#include "../../Include/Nominax/Foundation/Print.hpp"

namespace Nominax::Foundation
{
    auto Version::Display(DataStream& stream) const -> void
    {
        Print(stream, SYSTEM_LOGO_TEXT);
        Print(stream, SYSTEM_COPYRIGHT_TEXT);
        Print(stream, "\nNominax Version: v.{}.{}\n", SYSTEM_VERSION.Major, SYSTEM_VERSION.Minor);
        Print(stream, "Platform: {} {}\n", NOX_OS_NAME, NOX_ARCH_SIZE_NAME);
        Print(stream, "Arch: {}\n", NOX_ARCH_NAME);
        Print(stream, "Posix: {}\n", NOX_IS_POSIX);
        Print(stream, "Compiled with: {} - C++ 20\n", NOX_COM_NAME);
    }
}
