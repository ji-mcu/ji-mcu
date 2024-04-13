#!/bin/bash

PROJECT_DIR=$(pwd)

# install library
sudo apt update
sudo apt upgrade
sudo apt install git python3-pip gawk texinfo libgmp-dev libmpfr-dev libmpc-dev swig3.0 libjpeg-dev lsb-core doxygen sox graphicsmagick-libmagick-dev-compat libsdl2-dev libswitch-perl libftdi1-dev cmake scons libsndfile1-dev
sudo pip3 install twisted prettytable pyelftools openpyxl xlsxwriter pyyaml numpy configparser pyvcd
pip -U install sphinx

# modify authority
sudo chmod 777 -R ./sdk

# env
# 配置交叉编译链环境
cd sdk/
source set_toolschain_env.sh
# 编译环境
cd sw/
source pulp-rt-spiv2/configs/pulpissimo.sh

# fix local env
cd $PROJECT_DIR
sudo ln -s /usr/lib/x86_64-linux-gnu/libmpfr.so.6 /usr/lib/x86_64-linux-gnu/libmpfr.so.4

# fix toolchain
cd $PROJECT_DIR
cd sdk/toolchain/libexec/gcc/riscv32-unknown-elf/7.1.1/
rm liblto_plugin.so
rm liblto_plugin.so.0
ln -s liblto_plugin.so.0.0.0 liblto_plugin.so.0
ln -s liblto_plugin.so.0.0.0 liblto_plugin.so
