#!/bin/bash

PROJECT_DIR=$(pwd)

# install library
sudo apt update
sudo apt upgrade
sudo apt install git python3-pip gawk texinfo libgmp-dev libmpfr-dev libmpc-dev swig3.0 libjpeg-dev lsb-core doxygen sox graphicsmagick-libmagick-dev-compat libsdl2-dev libswitch-perl libftdi1-dev cmake scons libsndfile1-dev
sudo pip3 install twisted prettytable pyelftools openpyxl xlsxwriter pyyaml numpy configparser pyvcd
pip -U install sphinx

# solve the problem of lfs
curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | sudo bash
sudo apt install git-lfs
git lfs install
git lfs fetch

# modify authority
sudo chmod 777 -R ./sdk

# fix local env
cd $PROJECT_DIR
sudo ln -s /usr/lib/x86_64-linux-gnu/libmpfr.so.6 /usr/lib/x86_64-linux-gnu/libmpfr.so.4
echo "has fixed local env"

# fix toolchain
cd $PROJECT_DIR
cd sdk/toolchain/libexec/gcc/riscv32-unknown-elf/7.1.1/
rm liblto_plugin.so
rm liblto_plugin.so.0
ln -s liblto_plugin.so.0.0.0 liblto_plugin.so.0
ln -s liblto_plugin.so.0.0.0 liblto_plugin.so
echo "has fixed toolchain"

# return to project dir
cd $PROJECT_DIR
