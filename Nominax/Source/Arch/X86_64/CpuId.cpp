#include "../../../Include/Nominax/Arch/X86_64/CpuId.hpp"
#include "../../../Include/Nominax/Common/Protocol.hpp"

#define PRINT_CPU_FEATURE(name, has) Print(( has ) ? TextColor::BrightGreen : TextColor::Red, "{0: <12} ", name)

namespace Nominax::X86_64
{	
	auto CpuFeatureBits::PrintFeatures() const -> void
	{
		PRINT_CPU_FEATURE("FPU", this->Fpu);
		PRINT_CPU_FEATURE("VME", this->Vme);
		PRINT_CPU_FEATURE("DE", this->De);
		PRINT_CPU_FEATURE("PSE", this->Pse);
		PRINT_CPU_FEATURE("TSC", this->Tsc);
		PRINT_CPU_FEATURE("MSR", this->Msr);
		PRINT_CPU_FEATURE("PAE", this->Pae);
		PRINT_CPU_FEATURE("MCE", this->Mce);

		Print("\n");
		
		PRINT_CPU_FEATURE("CMPXCHG8", this->Cx8);
		PRINT_CPU_FEATURE("APIC", this->Apic);	
		PRINT_CPU_FEATURE("SEP", this->Sep);
		PRINT_CPU_FEATURE("MTRR", this->Mtrr);
		PRINT_CPU_FEATURE("PGE", this->Pge);
		PRINT_CPU_FEATURE("MCA", this->Mca);
		PRINT_CPU_FEATURE("CMOV", this->CMov);
		PRINT_CPU_FEATURE("PAT", this->Pat);

		Print("\n");

		PRINT_CPU_FEATURE("PSE36", this->Pse36);
		PRINT_CPU_FEATURE("PSN", this->Psn);
		PRINT_CPU_FEATURE("CLFSH", this->Clfsh);
		PRINT_CPU_FEATURE("DS", this->Ds);
		PRINT_CPU_FEATURE("ACPI", this->Acpi);
		PRINT_CPU_FEATURE("MMX", this->Mmx);
		PRINT_CPU_FEATURE("FXSR", this->Fxsr);
		PRINT_CPU_FEATURE("SSE", this->Sse);

		Print("\n");

		PRINT_CPU_FEATURE("SSE2", this->Sse2);
		PRINT_CPU_FEATURE("SS", this->Ss);
		PRINT_CPU_FEATURE("HTT", this->Htt);
		PRINT_CPU_FEATURE("TM", this->Tm);
		PRINT_CPU_FEATURE("IA64", this->Ia64);
		PRINT_CPU_FEATURE("PBE", this->Pbe);
		PRINT_CPU_FEATURE("SSE3", this->Sse3);
		PRINT_CPU_FEATURE("PCLMULDQD", this->PclMulDqd);

		Print("\n");

		PRINT_CPU_FEATURE("DTES64", this->DTes64);
		PRINT_CPU_FEATURE("Monitor", this->Monitor);
		PRINT_CPU_FEATURE("DSCPL", this->DsCpl);
		PRINT_CPU_FEATURE("SSE3", this->Sse3);
		PRINT_CPU_FEATURE("CNXTID", this->CnxtId);
		PRINT_CPU_FEATURE("SDBG", this->Sdbg);
		PRINT_CPU_FEATURE("FMA", this->Fma);
		PRINT_CPU_FEATURE("CMPXCHG16", this->Cx16);

		Print("\n");

		PRINT_CPU_FEATURE("XPTR", this->Xtpr);
		PRINT_CPU_FEATURE("PDCM", this->Pdcm);
		PRINT_CPU_FEATURE("PCID", this->Pcid);
		PRINT_CPU_FEATURE("DCA", this->Dca);
		PRINT_CPU_FEATURE("SSE4.1", this->Sse41);
		PRINT_CPU_FEATURE("SSE4.2", this->Sse42);
		PRINT_CPU_FEATURE("X2APIC", this->X2Apic);
		PRINT_CPU_FEATURE("MOVBE", this->MovBe);

		Print("\n");

		PRINT_CPU_FEATURE("POPCNT", this->PopCnt);
		PRINT_CPU_FEATURE("TSCDeadline", this->TscDeadline);
		PRINT_CPU_FEATURE("AES?", this->Aes);
		PRINT_CPU_FEATURE("XSave", this->XSave);
		PRINT_CPU_FEATURE("OsXSave", this->OsXSave);
		PRINT_CPU_FEATURE("AVX", this->Avx);
		PRINT_CPU_FEATURE("F16C", this->F16C);
		PRINT_CPU_FEATURE("RDRND", this->RdRnd);
		PRINT_CPU_FEATURE("Hypervisor", this->Hypervisor);

		Print("\n");
	}
}

#undef PRINT_CPU_FEATURE
