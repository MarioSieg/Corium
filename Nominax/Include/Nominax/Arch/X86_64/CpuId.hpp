#pragma once

#include <type_traits>

#include "../MachInterface.hpp"

namespace Nominax::X86_64
{
	struct CpuFeatureBits final
	{
		// DWORD LO
		
		bool Fpu : 1 {false};
		bool Vme : 1 {false};
		bool De : 1 {false};
		bool Pse : 1 {false};
		bool Tsc : 1 {false};
		bool Msr : 1 {false};
		bool Pae : 1 {false};
		bool Mce : 1 {false};
		bool Cx8 : 1 {false};
		bool Apic : 1 {false};

	private:
		[[maybe_unused]]
		bool Reserved0_ : 1 {false};

	public:
		bool Sep : 1 {false};
		bool Mtrr : 1 {false};
		bool Pge : 1 {false};
		bool Mca : 1 {false};
		bool CMov : 1 {false};
		bool Pat : 1 {false};
		bool Pse36 : 1 {false};
		bool Psn : 1 {false};
		bool Clfsh : 1 {false};

	private:
		[[maybe_unused]]
		bool Reserved1_ : 1 {false};

	public:
		bool Ds : 1 {false};
		bool Acpi : 1 {false};
		bool Mmx : 1 {false};
		bool Fxsr : 1 {false};
		bool Sse : 1 {false};
		bool Sse2 : 1 {false};
		bool Ss : 1 {false};
		bool Htt : 1 {false};
		bool Tm : 1 {false};
		bool Ia64 : 1 {false};
		bool Pbe : 1 {false};

		// DWORD HI
		
		bool Sse3 : 1 {false};
		bool PclMulDqd : 1 {false};
		bool DTes64 : 1 {false};
		bool Monitor : 1 {false};
		bool DsCpl : 1 {false};
		bool Vmx : 1 {false};
		bool Smx : 1 {false};
		bool Est : 1 {false};
		bool Tm2 : 1 {false};
		bool Ssse3 : 1 {false};
		bool CnxtId : 1 {false};
		bool Sdbg : 1 {false};
		bool Fma : 1 {false};
		bool Cx16 : 1 {false};
		bool Xtpr : 1 {false};
		bool Pdcm : 1 {false};

	private:
		[[maybe_unused]]
		bool Reserved3_ : 1 {false};

	public:
		bool Pcid : 1 {false};
		bool Dca : 1 {false};
		bool Sse41 : 1 {false};
		bool Sse42 : 1 {false};
		bool X2Apic : 1 {false};
		bool MovBe : 1 {false};
		bool PopCnt : 1 {false};
		bool TscDeadline : 1 {false};
		bool Aes : 1 {false};
		bool XSave : 1 {false};
		bool OsXSave : 1 {false};
		bool Avx : 1 {false};
		bool F16C : 1 {false};
		bool RdRnd : 1 {false};
		bool Hypervisor : 1 {false};

		auto PrintFeatures() const -> void;
	};
	
	static_assert(sizeof(CpuFeatureBits) == sizeof(QUADWORD));
	static_assert(std::is_trivially_copyable_v<CpuFeatureBits>);
	
	extern "C" auto __CPUID__() -> QUADWORD;
}
