operand_lookup = {
    "1":              "ScalarOne",
    "3":              "ScalarThree",
    "al":             "Al",
    "ax":             "Ax",
    "eax":            "Eax",
    "rax":            "Rax",
    "cl":             "Cl",
    "xmm0":           "Xmm0",
    "rel8":           "Rel8",
    "rel32":          "Rel32",
    "imm4":           "Imm4",
    "imm8":           "Imm8",
    "imm16":          "Imm16",
    "imm32":          "Imm32",
    "imm64":          "Imm64",
    "r8":             "R8",
    "r16":            "R16",
    "r32":            "R32",
    "r64":            "R64",
    "mm":             "Mm",
    "xmm":            "Xmm",
    "xmm{k}":         "XmmK",
    "xmm{k}{z}":      "XmmKz",
    "ymm":            "Ymm",
    "ymm{k}":         "YmmK",
    "ymm{k}{z}":      "YmmKz",
    "zmm":            "Zmm",
    "zmm{k}":         "ZmmK",
    "zmm{k}{z}":      "ZmmKz",
    "k":              "K",
    "k{k}":           "Kk",
    "m":              "M",
    "m8":             "M8",
    "m16":            "M16",
    "m16{k}{z}":      "M16Kz",
    "m32":            "M32",
    "m32{k}":         "M32k",
    "m32{k}{z}":      "M32Kz",
    "m64":            "M64",
    "m64{k}":         "M64k",
    "m64{k}{z}":      "M64Kz",
    "m80":            "M80",
    "m128":           "M128",
    "m128{k}{z}":     "M128Kz",
    "m256":           "M256",
    "m256{k}{z}":     "M256Kz",
    "m512":           "M512",
    "m512{k}{z}":     "M512Kz",
    "m64/m32bcst":    "M64M32Bcst",
    "m128/m32bcst":   "M128M32Bcst",
    "m256/m32bcst":   "M256M32Bcst",
    "m512/m32bcst":   "M512M32Bcst",
    "m128/m64bcst":   "M128M64Bcst",
    "m256/m64bcst":   "M256M64Bcst",
    "m512/m64bcst":   "M512M64Bcst",
    "vm32x":          "Vm32x",
    "vm32x{k}":       "Vm32xk",
    "vm32y":          "Vm32y",
    "vm32y{k}":       "Vm32yk",
    "vm32z":          "Vm32z",
    "vm32z{k}":       "Vm32zk",
    "vm64x":          "Vm64x",
    "vm64x{k}":       "Vm64xk",
    "vm64y":          "Vm64y",
    "vm64y{k}":       "Vm64yk",
    "vm64z":          "Vm64z",
    "vm64z{k}":       "Vm64zk",
    "{sae}":          "Sae",
    "{er}":           "Er",
    "moffs32":        "Moffs32",
    "moffs64":        "Moffs64",
}

def mko(x):
    return "UINT64_C(" + hex(x if x is not None else 0) + ")" if type(x) is int or x is None else "OperandType::" + operand_lookup[x.type]

def generate_insertion_fun(range, idx):
    output = "NOX_NEVER_INLINE NOX_COLD auto GetVariationTable_" + str(idx) + "(std::pmr::monotonic_buffer_resource& allocator, std::pmr::vector<InstructionVariationPool>& out) -> void\n{\n"
    output += "\tstd::pmr::vector<InstructionVariation> instruction{&allocator};\n"
    for instr in range:
        output += "\tinstruction = \n"
        output += "\t{\n"
        for form in instr.forms:
            output += "\t\tInstructionVariation\n"
            output += "\t\t{\n"
            output += "\t\t\t.IntelMnemonic = \"" + form.name.lower() + "\",\n"
            output += "\t\t\t.GasMnemonic = \"" + form.gas_name + "\",\n"
            output += "\t\t\t.Description = \"" + str(form) + "\",\n"
            output += "\t\t\t.MmxMode = MmxModeType::" + (form.mmx_mode.capitalize() if form.mmx_mode else "None") + ",\n"
            output += "\t\t\t.XmmMode = XmmModeType::" + (form.xmm_mode.capitalize() if form.xmm_mode else "None") + ",\n"
            output += "\t\t\t.IsCancellingInputs = " + ("true" if form.cancelling_inputs else "false") + ",\n"
            output += "\t\t\t.OperandList =\n"
            output += "\t\t\t{\n"
            for operand in form.operands:
                output += "\t\t\t\tOperand\n"
                output += "\t\t\t\t{\n"
                output += "\t\t\t\t\t.Type = " + mko(operand) + ",\n"
                output += "\t\t\t\t\t.IsInput = " + ("true" if operand.is_input else "false") + ",\n"
                output += "\t\t\t\t\t.IsOutput = " + ("true" if operand.is_output else "false") + ",\n"
                output += "\t\t\t\t\t.ExtendedSize = " + str((operand.extended_size if operand.extended_size else 0)) + "\n"
                output += "\t\t\t\t},\n"
            output += "\t\t\t},\n"
            output += "\t\t\t.ImplicitInputs =\n"
            output += "\t\t\t{\n"
            for input in form.implicit_inputs:
                output += "\t\t\t\tImplicitRegisterOperand::" + input.capitalize() + ",\n"
            output += "\t\t\t},\n"
            output += "\t\t\t.ImplicitOutputs =\n"
            output += "\t\t\t{\n"
            for input in form.implicit_outputs:
                output += "\t\t\t\tImplicitRegisterOperand::" + input.capitalize() + ",\n"
            output += "\t\t\t},\n"
            output += "\t\t\t.IsaFeatureExtensions =\n"
            output += "\t\t\t{\n"
            for ext in form.isa_extensions:
                lookup = {
                    "RDTSC"          : "Rdtsc",
                    "RDTSCP"         : "Rdtscp",
                    "CPUID"          : "Cpuid",
                    "FEMMS"          : "Femms",
                    "MOVBE"          : "Movbe",
                    "POPCNT"         : "Popcnt",
                    "LZCNT"          : "Lzcnt",
                    "PCLMULQDQ"      : "Pclmulqdq",
                    "RDRAND"         : "Rdrand",
                    "RDSEED"         : "Rdseed",
                    "CLFLUSH"        : "Clflush",
                    "CLFLUSHOPT"     : "Clflushopt",
                    "CLWB"           : "Clwb",
                    "CLZERO"         : "Clzero",
                    "PREFETCH"       : "Prefetch",
                    "PREFETCHW"      : "Prefetchw",
                    "PREFETCHWT1"    : "Prefetchwt1",
                    "MONITOR"        : "Monitor",
                    "MONITORX"       : "Monitorx",
                    "CMOV"           : "Cmov",
                    "MMX"            : "Mmx",
                    "MMX+"           : "MmxExt",
                    "3dnow!"         : "D3Now",
                    "3dnow!+"        : "D3NowExt",
                    "SSE"            : "Sse",
                    "SSE2"           : "Sse2",
                    "SSE3"           : "Sse3",
                    "SSSE3"          : "Ssse3",
                    "SSE4.1"         : "Sse41",
                    "SSE4.2"         : "Sse42",
                    "SSE4A"          : "Sse4A",
                    "AVX"            : "Avx",
                    "AVX2"           : "Avx2",
                    "AVX512F"        : "Avx512F",
                    "AVX512BW"       : "Avx512Bw",
                    "AVX512DQ"       : "Avx512Dq",
                    "AVX512VL"       : "Avx512Vl",
                    "AVX512PF"       : "Avx512Pf",
                    "AVX512ER"       : "Avx512Er",
                    "AVX512CD"       : "Avx512Cd",
                    "AVX512VBMI"     : "Avx512Vbmi",
                    "AVX512IFMA"     : "Avx512Ifma",
                    "AVX512VPOPCNTDQ": "Avx512Vpopcntd",
                    "XOP"            : "Xop",
                    "F16C"           : "F16C",
                    "FMA3"           : "Fma3",
                    "FMA4"           : "Fma4",
                    "BMI"            : "Bmi",
                    "BMI2"           : "Bmi2",
                    "TBM"            : "Tbm",
                    "ADX"            : "Adx",
                    "AES"            : "Aes",
                    "SHA"            : "Sha",
                }
                output += "\t\t\t\tIsaExtension::" + lookup[str(ext)]  + ",\n"
            output += "\t\t\t},\n"
            output += "\t\t\t.EncodingScheme =\n"
            output += "\t\t\t{\n"
            for enc in form.encodings:
                output += "\t\t\t\tEncoding\n"
                output += "\t\t\t\t{\n"
                for com in enc.components:
                    if type(com) is Prefix:
                        output += "\t\t\t\t\tPrefix\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.Value = " + hex(com.byte) + ",\n"
                        output += "\t\t\t\t\t\t.IsMandatory = " + ("true" if com.is_mandatory else "false") + ",\n"
                        output += "\t\t\t\t\t},\n"
                    elif type(com) is REX:
                        output += "\t\t\t\t\tRex\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.W = " + ("true" if com.W else "false") + ",\n"
                        output += "\t\t\t\t\t\t.R = {" + mko(com.R) + "},\n"
                        output += "\t\t\t\t\t\t.X = {" + mko(com.X) + "},\n"
                        output += "\t\t\t\t\t\t.B = {" + mko(com.B) + "},\n"
                        output += "\t\t\t\t\t\t.IsMandatory = " + ("true" if com.is_mandatory else "false") + ",\n"
                        output += "\t\t\t\t\t},\n"
                    elif type(com) is VEX:
                        output += "\t\t\t\t\tVex\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.Type = " + ("VexPrefixType::Vex" if com.type == "VEX" else "VexPrefixType::Xop") + ",\n"
                        output += "\t\t\t\t\t\t.Mmmmm = " + bin(com.mmmmm) + ",\n"
                        output += "\t\t\t\t\t\t.Pp = " + bin(com.pp) + ",\n"
                        output += "\t\t\t\t\t\t.W = " + ("true" if com.W else "false") + ",\n"
                        output += "\t\t\t\t\t\t.L = " + ("true" if com.L else "false") + ",\n"
                        output += "\t\t\t\t\t\t.R = {" + mko(com.R) + "},\n"
                        output += "\t\t\t\t\t\t.X = {" + mko(com.X) + "},\n"
                        output += "\t\t\t\t\t\t.B = {" + mko(com.B) + "},\n"
                        output += "\t\t\t\t\t\t.Vvvv = {" + mko(com.vvvv) + "},\n"
                        output += "\t\t\t\t\t},\n"
                    elif type(com) is EVEX:
                        output += "\t\t\t\t\tEvex\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.Mm = " + bin(com.mm) + ",\n"
                        output += "\t\t\t\t\t\t.Pp = " + bin(com.pp) + ",\n"
                        output += "\t\t\t\t\t\t.W = " + ("true" if com.W else "false") + ",\n"
                        output += "\t\t\t\t\t\t.Ll = " + mko(com.LL) + ",\n"
                        output += "\t\t\t\t\t\t.Rr = {" + mko(com.RR) + "},\n"
                        output += "\t\t\t\t\t\t.Bb = {" + mko(com.B) + "},\n"
                        output += "\t\t\t\t\t\t.X = {" + (mko(com.X)) + "},\n"
                        output += "\t\t\t\t\t\t.Vvvv = {" + mko(com.vvvv) + "},\n"
                        output += "\t\t\t\t\t\t.V = {" + mko(com.V) + "},\n"
                        output += "\t\t\t\t\t\t.B = {" + mko(com.B) + "},\n"
                        output += "\t\t\t\t\t\t.Aaa = {" + mko(com.aaa) + "},\n"
                        output += "\t\t\t\t\t\t.Z = {" + mko(com.z) + "},\n"
                        output += "\t\t\t\t\t\t.Disp8xN = " + str(com.disp8xN if com.disp8xN else 0) + ",\n"
                        output += "\t\t\t\t\t},\n"
                    elif type(com) is Opcode:
                        output += "\t\t\t\t\tOpCode\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.Value = " + hex(com.byte) + ",\n"
                        output += "\t\t\t\t\t\t.Addend = {" + mko(com.addend) + "},\n"
                        output += "\t\t\t\t\t},\n"
                    elif type(com) is ModRM:
                        output += "\t\t\t\t\tModRm\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.Mode = {" + mko(com.mode) + "},\n"
                        output += "\t\t\t\t\t\t.Rm = {" + mko(com.rm) + "},\n"
                        output += "\t\t\t\t\t\t.Reg = {" + mko(com.reg) + "},\n"
                        output += "\t\t\t\t\t},\n"
                    elif type(com) is Immediate:
                        output += "\t\t\t\t\tImmediateScalar\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.Size = " + str(com.size if com.size else 0) + ",\n"
                        output += "\t\t\t\t\t\t.Value = {" + mko(com.value) + "},\n"
                        output += "\t\t\t\t\t},\n"
                    elif type(com) is RegisterByte:
                        output += "\t\t\t\t\tRegisterByte\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.Register = " + mko(com.register) + ",\n"
                        output += "\t\t\t\t\t\t.Payload = {" + mko(com.payload) + "},\n"
                        output += "\t\t\t\t\t},\n"
                    elif type(com) is CodeOffset:
                        output += "\t\t\t\t\tCodeOffset\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.Size = " + str(com.size) + ",\n"
                        output += "\t\t\t\t\t\t.Value = " + mko(com.value) + ",\n"
                        output += "\t\t\t\t\t},\n"
                    elif type(com) is DataOffset:
                        output += "\t\t\t\t\tDataOffset\n"
                        output += "\t\t\t\t\t{\n"
                        output += "\t\t\t\t\t\t.Size = " + str(com.size) + ",\n"
                        output += "\t\t\t\t\t\t.Value = " + mko(com.value) + ",\n"
                        output += "\t\t\t\t\t},\n"
                output += "\t\t\t\t},\n"
            output += "\t\t\t}\n"
            output += "\t\t},\n"
        output += "\t};\n"
        output += "\tout.emplace_back(std::move(instruction));\n\n"
    output += "};\n"
    print(output)

def divide_chunks(l, n):
    for i in range(0, len(l), n): 
        yield l[i:i + n]

instrset = read_instruction_set("x86_64.xml")
chunk_size = 32
i = 0
for l in list(divide_chunks(instrset, chunk_size)):
    generate_insertion_fun(l, i)
    i += 1