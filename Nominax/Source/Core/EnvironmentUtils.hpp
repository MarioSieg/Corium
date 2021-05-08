#pragma once

#include <cstddef>

namespace Nominax
{
	struct SystemInfo;
	class CpuFeatureDetector;

	extern auto PrintSystemInfo() -> void;

	extern auto PrintTypeInfoTable() -> void;

	extern auto PrintMachineInfo(const SystemInfo& sysInfo, const CpuFeatureDetector& cpuInfo) -> void;
}