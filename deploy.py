# (C) Copyright Mario Sieg <alias Kerbo, Pinsrq> <mt3000@gmx.de> 2021! All rights reserved!
# See LICENSE file for license information!

import os
import sys
import shutil

def exec_ex() -> str:
    platform = sys.platform
    return ".exe" if platform == "win32" else ""

output_dir: str = os.getcwd() + "/retail/"
output_file: str = output_dir + "nominax" + exec_ex()
target: str = os.getcwd() + "/target/release/exec" + exec_ex()

print("Working dir: \"%s\n\"" % os.getcwd())
print("Preparing retail deployment...\n")

if not os.path.isfile(target):
    print("Target binary \"%s\" not found, compiling...\n" % target)
    os.system("cargo build --release --all-features")

print("Creating output dir: \"%s\"...\n" % output_dir)
os.mkdir(output_dir)

print("Copying target file: \"%s\"...\n" % output_file)
shutil.copyfile(target, output_file)
