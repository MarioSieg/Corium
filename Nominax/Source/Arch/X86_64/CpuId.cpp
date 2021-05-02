#include "../../../Include/Nominax/Arch/X86_64/CpuId.hpp"
#include "../../../Include/Nominax/Common/Protocol.hpp"

namespace Nominax::X86_64
{
	auto CpuFeatureBits::PrintFeatures() const -> void
	{
		Print("FPU? {}\n", this->Fpu);
		Print("VME? {}\n", this->Vme);
		Print("DE? {}\n", this->De);
		Print("PSE? {}\n", this->Pse);
		Print("TSC? {}\n", this->Tsc);
		Print("MSR? {}\n", this->Msr);
		Print("PAE? {}\n", this->Pae);
		Print("MCE? {}\n", this->Mce);
		Print("CMPXCHG8? {}\n", this->Cx8);
		Print("APIC? {}\n", this->Apic);
		
		Print("SEP? {}\n", this->Sep);
		Print("MTRR? {}\n", this->Mtrr);
		Print("PGE? {}\n", this->Pge);
		Print("MCA? {}\n", this->Mca);
		Print("CMOV? {}\n", this->CMov);
		Print("PAT? {}\n", this->Pat);
		Print("PSE36? {}\n", this->Pse36);
		Print("PSN? {}\n", this->Psn);
		Print("CLFSH? {}\n", this->Clfsh);

		Print("DS? {}\n", this->Ds);
		Print("ACPI? {}\n", this->Acpi);
		Print("MMX? {}\n", this->Mmx);
		Print("FXSR? {}\n", this->Fxsr);
		Print("SSE? {}\n", this->Sse);
		Print("SSE2? {}\n", this->Sse2);
		Print("SS? {}\n", this->Ss);
		Print("HTT? {}\n", this->Htt);
		Print("TM? {}\n", this->Tm);
		Print("IA64? {}\n", this->Ia64);
		Print("PBE? {}\n", this->Pbe);

		Print("SSE3? {}\n", this->Sse3);
		Print("PCLMULDQD? {}\n", this->PclMulDqd);
		Print("DTES64? {}\n", this->DTes64);
		Print("Monitor? {}\n", this->Monitor);
		Print("DSCPL? {}\n", this->DsCpl);
		Print("SSE3? {}\n", this->Sse3);
		Print("CNXTID? {}\n", this->CnxtId);
		Print("SDBG? {}\n", this->Sdbg);
		Print("FMA? {}\n", this->Fma);
		Print("CMPXCHG16? {}\n", this->Cx16);
		Print("XPTR? {}\n", this->Xtpr);
		Print("PDCM? {}\n", this->Pdcm);

		Print("PCID? {}\n", this->Pcid);
		Print("DCA? {}\n", this->Dca);
		Print("SSE4.1? {}\n", this->Sse41);
		Print("SSE4.2? {}\n", this->Sse42);
		Print("X2APIC? {}\n", this->X2Apic);
		Print("MOVBE? {}\n", this->MovBe);
		Print("POPCNT? {}\n", this->PopCnt);
		Print("TSCDeadline? {}\n", this->TscDeadline);
		Print("AES? {}\n", this->Aes);
		Print("XSave? {}\n", this->XSave);
		Print("OsXSave? {}\n", this->OsXSave);
		Print("AVX? {}\n", this->Avx);
		Print("F16C? {}\n", this->F16C);
		Print("RDRND? {}\n", this->RdRnd);
		Print("Hypervisor? {}\n", this->Hypervisor);
	}
}
