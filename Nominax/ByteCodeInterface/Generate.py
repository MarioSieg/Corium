import os

def read_txt(path: str) -> str:
    if os.path.isfile(path):
        with open(path, 'r') as file:
            print("Reading: " + path)
            return file.read()
    else:
        print("File not found: " + path)
        exit(-1)

def read_txt_clean(path: str) -> str:
    if os.path.isfile(path):
        with open(path) as file:
            lines = file.readlines()
            lines = [line.rstrip() for line in lines]
            out = ""
            for line in lines:
                if not line.startswith("//"):
                    out += f"\t\t{line}\n"
            return out
    else:
        print("File not found: " + path)
        exit(-1)

print("Nominax bytecode interface generator for Rust")
print("Copyright 2021 Mario Sieg \"pinsrq\" <mt3000@gmx.de>")

def generate(template_file, output, useDots = False):
    template = read_txt(template_file)
    nox_dir = "../Include/Nominax/ByteCode/"

    instruction_enum = read_txt_clean(nox_dir + "ExportInstructionEnum.hpp")
    category_enum = read_txt_clean(nox_dir + "ExportInstructionCategoryEnum.hpp")
    syscall_enum = read_txt_clean(nox_dir + "ExportSysCallEnum.hpp")
    mnemonic_table = read_txt_clean(nox_dir + "ExportInstructionMnemonicTable.hpp")
    category_table = read_txt_clean(nox_dir + "ExportInstructionCategoryTable.hpp")
    push_record_table = read_txt_clean(nox_dir + "ExportInstructionPushRecordTable.hpp")
    pop_record_table = read_txt_clean(nox_dir + "ExportInstructionPopRecordTable.hpp")
    immediate_table = read_txt_clean(nox_dir + "ExportInstructiontImmediateTable.hpp")
    descriptor_table = read_txt_clean(nox_dir + "ExportInstructionDescriptorTable.hpp")
        
    template = template.replace("$INSTRUCTION$", instruction_enum)
    template = template.replace("$INSTRUCTION_CATEGORY$", category_enum)
    template = template.replace("$MNEMONIC_TABLE$", mnemonic_table)
    template = template.replace("$CATEGORY_TABLE$", category_table)
    template = template.replace("$PUSH_RECORD_TABLE$", push_record_table)
    template = template.replace("$POP_RECORD_TABLE$", pop_record_table)
    template = template.replace("$IMMEDIATE_TABLE$", immediate_table)
    template = template.replace("$DESCRIPTOR_TABLE$", descriptor_table)
    template = template.replace("$SYSCALL$", syscall_enum)

    # if language uses . instead of :: as scope operator:
    if useDots:
        template = template.replace("::", ".")

    print("Writing generated code: " + output)
    with open(output, "wt") as text_file:
        text_file.write(template)

generate("NominaxByteCodeInterfaceTemplate.rs", "NominaxByteCodeInterface/src/lib.rs")
