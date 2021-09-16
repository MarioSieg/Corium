#include "../../Include/Nominax/Foundation/Version.hpp"
#include "../../Include/Nominax/Foundation/Print.hpp"

namespace Nominax::Foundation
{
    /// <summary>
    /// Print Nominax runtime info.
    /// </summary>
    /// <returns></returns>
    auto PrintSystemInfo() -> void
    {
        Print(SYSTEM_LOGO_TEXT);
        Print(SYSTEM_COPYRIGHT_TEXT);
        Print("\nNominax Version: v.{}.{}\n", SYSTEM_VERSION.Major, SYSTEM_VERSION.Minor);
        Print("Platform: {} {}\n", NOX_OS_NAME, NOX_ARCH_SIZE_NAME);
        Print("Arch: {}\n", NOX_ARCH_NAME);
        Print("Posix: {}\n", NOX_IS_POSIX);
        Print("Compiled with: {} - C++ 20\n", NOX_COM_NAME);
        Print('\n');
    }
}
