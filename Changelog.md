Changelog for the development of the Corium programming language
and all sub-components:<br>
Corium Compiler, Nominax Runtime<br>
developed by Mario Sieg "pinsrq" mt3000@gmx.de!<br>
See LICENSE for licensing information!

*8/23/2021*<br>
Created Changelog.md. The project is almost half a year old and<br>
now finally the changelog is here. Much has changed in this half year and it's very late<br>
for a changelog but better late than never.<br>

**Nominax**<br>
Implemented virtual memory allocation on Linux using mmap/munmap.<br>
Now we have the implementation read on Windows (with irtualAlloc) and Linux.<br>
Now I can write the virtual memory allocator and implement the executable<br>
machine code buffer for the JIT compiler.<br>

*8/28/2021*<br>
**Nominax**<br>
A lock to the virtual allocation header,<br>
which allows the locking of the protection flags.<br>
Once locked, you can no longer change the protection of the memory pages<br>
via the VMM.<br>

*8/29/2021*<br>
**Nominax**<br>
Documentation for the VMM.<br>
Refractored the code.<br>

*8/30/2021*<br>
**Compiler**<br>
Compilation units, improved the parser.<br>
Return types and printing of AST structures.<br>

*9/2/2021*<br>
**Compiler**<br>
Support for function parameters.<br>
**Nominax**<br>
A RAII wrapper for virtual allocated memory: "MappedMemory".<br>

*9/3/2021*<br>
**Nominax**<br>
Unit tests for MappedMemory class.<br>

*9/7/2021*<br>
**Nominax**<br>
Refractored the bytecode validator into a static class.<br>
The instruction operand type descriptors are now stored inside a bit vector using bitflags<br>
instead of a list.<br>
Instruction operand types are now stored inside a constexpr std::initializer list instead of a std::vector.<br>
Access and validation functions for the operand types are now all constexpr.<br>
All instruction metadata and the operand types now reside in a static class inside "InstructionMetaDataRegistry.hpp"<br>

*9/11/2021*<br>
**Nominax**<br>
Implemented deferred reactor booting into the reactor pool.<br>
Unlocked death tests for all configs and fixed some.<br>
