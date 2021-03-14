# Nominax Runtime
Nominax is a high performance, parallel runtime environment.
It can automatically accelerate programs by using the hardware more efficient and distributing the workload across different CPU cores.
Vectorizing, SoA and GPU offloading are used too.
<h3>Nominax Planned Features:</h3>

- Parallel virtual register machine
- Multithreading, Async and Coroutines
- Auto vectorization
- JIT compiler
- Gargabe Collector
- Dynamic Pool Preallocator
- Intrinsic platform interface
- GPU Offloading with OpenCL
- Modern C++ 20 interface

Corium is a fully parallel, high performance scripting language made for AI and gaming, which is running on Nominax.
Nominax is the primary environment for Corium but any Language can be accelerated by Nominax.
The system defines it's own cross plattform intermediate representation (NXIR), which can be targetted by any compiler.
Converters from Java and Python Bytecode to NXIR are also planned.

