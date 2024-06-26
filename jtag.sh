#!/bin/bash

PROJECT_DIR=$(pwd)
PULP_BRIDGE_DIR=$PROJECT_DIR/sdk/pulp-builder
OUT_SIM_FILE=$PROJECT_DIR/sdk/sw/runner/out.txt
OUT_FLASH_FILE=$PROJECT_DIR/sdk/sw/runner/flash_stim.slm

# set env
cd $PROJECT_DIR
source ./env.sh
cd $PULP_BRIDGE_DIR
source ./set_env.sh

ACHITECUTRE=riscv:rv32
PORT=1234
ELF_PATH=$PROJECT_DIR/sdk/sw/apps/$2/build/$2/$2

if [ $# == 2 ] && [ $1 == "-f" ]; then # if input "./jtag.sh -f" then flash the bitstream with gdb
    cd $PROJECT_DIR
    plpbridge --chip=pulpissimo --cable=ftdi@digilent gdb wait --rsp-port=$PORT &
    bash -c " source ./env.sh; riscv32-unknown-elf-gdb --eval-command='set architecture $ACHITECUTRE' --eval-command='target remote localhost:$PORT' --eval-command='file $ELF_PATH' --eval-command='load';exec bash"
fi

# if input "./jtag.sh -r" then show the regs
if [ $# == 1 ] && [ $1 == "-r" ]; then
    echo "JTAG REGS: "
    # 1.BOOT_ADDR 0x1A100_1004 0x1A00_0000 R/W
    echo "BOOT_ADDR addr in 0x1A101004: "
    ./read_jtag 0x1A101004 4

    # 2.MCU 启动使能寄存器：FETCH 0x1A100_1008 0x1 R/W
    echo "MCU FETCH addr in 0x1A101008: "
    ./read_jtag 0x1A101008 1

    exit 0
fi

# if input "./jtag.sh -r xxx" then show the address
if [ $# == 2 ] && [ $1 == "-r" ]; then
    echo "JTAG REGS: "
    echo "$2 addr in 0x1A10xxxx: "
    ./read_jtag $2 32

    exit 0
fi

# if input "./jtag.sh -c"
if [ $# == 1 ] && [ $1 == "-c" ]; then
    echo "write start area "
    ./write_jtag 0x1a101004 4 0x1c040000
    ./read_jtag 0x1a101004 4
    ./write_jtag 0x1a1010cc 4 3

    ./write_jtag 0x1a101008 4 0
    ./write_jtag 0x1a101008 4 1
    ./write_jtag 0x1a1010cc 4 0

    exit 0
fi

# if input "./jtag.sh -h" or "./jtag.sh --help" then show help
if [ $# == 1 ] && ([ $1 == "-h" ] || [ $1 == "--help" ]); then
    echo "Usage: ./jtag.sh [OPTION]"
    echo "  -f, --flash    flash the bitstream"
    echo "  -r <xxx>, --regs     show the regs or address"
    echo "  -h, --help     display this help and exit"
    exit 0
fi
