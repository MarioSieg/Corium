Changelog for the development of the Corium programming language
and all sub-components:<br>
Corium Compiler, Nominax Runtime<br>
developed by Mario Sieg "pinsrq" mt3000@gmx.de!<br>
See LICENSE for licensing information!

*8/23/2021*<br>
Created Changelog.md. The project is almost half a year old and
now finally the changelog is here. Much has changed in this half year and it's very late
for a changelog but better late than never.
Implemented virtual memory allocation on Linux using mmap/munmap.
Now we have the implementation read on Windows (with irtualAlloc) and Linux.
Now I can write the virtual memory allocator and implement the executable
machine code buffer for the JIT compiler.

*8/28/2021*<br>
Added a lock to the virtual allocation header,
which allows the locking of the protection flags. 
Once locked, you can no longer change the protection of the memory pages
via the VMM.

*8/29/2021*<br>
Added documentation for the VMM.
Also refractored the code.
