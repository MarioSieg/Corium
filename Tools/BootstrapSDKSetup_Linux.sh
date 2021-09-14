#!/bin/bash 

# Install C++ tools
sudo apt update
sudo apt install cmake
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
sudo apt install gcc-11 -y
sudo apt install g++-11 -y
sudo apt install libtbb-dev
sh LinuxSetupPstlNoexcept.sh

# Install Rust:
sudo apt install curl
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
source $HOME/.cargo/env

# Install Python:
sudo apt install python3

echo -n "\nDo you want to compile the Corium compiler and the Nominax runtime now? (y/n)?"
read answer

if [ "$answer" != "${answer#[Yy]}" ] ; then
    echo "Invoking SDK production build script: ProductionBuild.py"
    python3 ./ProductionBuild.py
else
    echo "No build action required. Done!"
fi
