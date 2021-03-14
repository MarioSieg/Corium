# Nominax Runtime
<h3>Nominax is a high performance, parallel runtime environment.
It can automatically accelerate programs by using the hardware more efficient and distributing the workload across different CPU cores.
Vectorizing, SoA and GPU offloading are included too!</h4>

![image](https://user-images.githubusercontent.com/49988901/111071215-60b04f80-84d5-11eb-9ddb-cfda5fcd8eb7.png)


<h4>Nominax Planned Features:</h3>

- Parallel virtual register machine
- Multithreading, Async and Coroutines
- Auto vectorization
- JIT compiler
- Gargabe Collector
- Dynamic Pool Preallocator
- Intrinsic platform interface
- GPU Offloading with OpenCL
- Modern C++ 20 interface

Nominax is build after a strict specification, which resides in the "specification" Branch.
Corium is a fully parallel, high performance scripting language made for AI and gaming, which is running on Nominax.
Nominax is the primary environment for Corium but any Language can be accelerated by Nominax.
The system defines it's own cross plattform intermediate representation (NXIR), which can be targetted by any compiler.
Converters from Java and Python Bytecode to NXIR are also planned.

<h3> Branches </h3>
The master branch contains releases.
The redux branch is the development branch.
The legacy branch contains the old version written in Rust.
The specification branch contains the specification documents.

<h3> Data Types <h3>
Nominax supports multiple primitive and advanced data types:

![image](https://i.imgur.com/8ED4emK.png)
![image](https://user-images.githubusercontent.com/49988901/111071150-1d55e100-84d5-11eb-8612-9db0de2c8a80.png)
