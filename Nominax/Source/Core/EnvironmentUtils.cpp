#include <string_view>
#include <thread>

#include "EnvironmentUtils.hpp"
#include "../../Include/Nominax/Core/Info.hpp"
#include "../../Include/Nominax/Core/Record.hpp"
#include "../../Include/Nominax/Core/Object.hpp"
#include "../../Include/Nominax/Common/Protocol.hpp"
#include "../../Include/Nominax/System/CpuFeatureDetector.hpp"
#include "../../Include/Nominax/System/Platform.hpp"
#include "../../Include/Nominax/System/Os.hpp"
#include "../../Include/Nominax/ByteCode/DynamicSignal.hpp"

namespace
{
	template <typename T>
	inline auto PrintTypeInfo(const std::string_view name) -> void
	{
		Nominax::Print("{0: <14} | {1: <14} | {2: <14}\n", name, sizeof(T), alignof(T));
	}
}

namespace Nominax
{
	auto PrintSystemInfo() -> void
	{
		Print(SYSTEM_LOGO_TEXT);
		Print(SYSTEM_COPYRIGHT_TEXT);
		Print("\nNominax Version: v.{}.{}\n", SYSTEM_VERSION.Major, SYSTEM_VERSION.Minor);
		Print("Platform: {} {}\n", NOMINAX_OS_NAME, NOMINAX_ARCH_SIZE_NAME);
		Print("Arch: {}\n", NOMINAX_ARCH_NAME);
		Print("IsPosix: {}\n", NOMINAX_IS_POSIX);
		Print("Compiled with: {} - C++ 20\n", NOMINAX_COM_NAME);
		Print("\n");
	}

	auto PrintTypeInfoTable() -> void
	{
		Print("{0: <14} | {1: <14} | {2: <14}\n\n", "Type", "Byte Size", "Alignment");
		PrintTypeInfo<Record>("Record");
		PrintTypeInfo<Signal>("Signal");
		PrintTypeInfo<DynamicSignal>("DynamicSignal");
		PrintTypeInfo<Object>("Object");
		PrintTypeInfo<ObjectHeader>("ObjectHeader");
		PrintTypeInfo<I64>("int");
		PrintTypeInfo<U64>("uint");
		PrintTypeInfo<F64>("float");
		PrintTypeInfo<char32_t>("char");
		PrintTypeInfo<bool>("bool");
		PrintTypeInfo<void*>("void*");
	}

	auto PrintMachineInfo(const SystemInfo& sysInfo, const CpuFeatureDetector& cpuInfo) -> void
	{
		sysInfo.Print();
		Print("\n");
		PrintTypeInfoTable();
		Print("\n");
		cpuInfo.Print();
		Print("\n");
	}
}
