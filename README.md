# Nominax Runtime
<h3>Nominax is a high performance, parallel runtime environment.
It can automatically accelerate programs by using the hardware more efficient and distributing the workload across different CPU cores.
Vectorizing, SoA and GPU offloading are included too!</h4>

![image](https://user-images.githubusercontent.com/49988901/111071215-60b04f80-84d5-11eb-9ddb-cfda5fcd8eb7.png)

<h3> Nominax became closed source for further development. Nominax might become open source again, as soon as there is a stable version!</h3>

<h4>Nominax Planned Features:</h3>

- :heavy_check_mark: Parallel virtual register machine
- :heavy_check_mark: Multithreading, Async and Coroutines
- :heavy_check_mark: Auto vectorization
- :heavy_check_mark: JIT compiler
- :heavy_check_mark: Garbage Collector
- :heavy_check_mark: Dynamic Pool Preallocator
- :heavy_check_mark: Intrinsic platform interface
- :heavy_check_mark: GPU Offloading
- :heavy_check_mark: Modern C++ 20 interface
- :heavy_check_mark: Cross platform intermediate representation
- :heavy_check_mark: Runtime support for SSE, AVX and AVX-512
- :heavy_check_mark: x86-64, ARM 64
- :heavy_check_mark: Linux, Windows, Mac, Android, iOS

Nominax is build after a strict specification.
Corium is a fully parallel, high performance scripting language made for AI and gaming, which is running on Nominax.
Nominax is the primary environment for Corium but any Language can be accelerated by Nominax.
The system defines it's own cross platform intermediate representation (NXIR), which can be targeted by any compiler.
Because Nominax can easily execute any bytecode language, converters from Java and Python Bytecode to NXIR are also planned.

![image](https://i.imgur.com/8ED4emK.png)
![image](https://user-images.githubusercontent.com/49988901/111071150-1d55e100-84d5-11eb-8612-9db0de2c8a80.png)
