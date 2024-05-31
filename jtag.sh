#!/bin/bash

PROJECT_DIR=$(pwd)
PULP_BRIDGE_DIR=$PROJECT_DIR/sdk/pulp-builder
OUT_SIM_FILE=$PROJECT_DIR/sdk/sw/runner/out.txt
OUT_FLASH_FILE=$PROJECT_DIR/sdk/sw/runner/flash_stim.slm

# set env
cd $PULP_BRIDGE_DIR
source ./set_env.sh

# run 'write_jtag' with different address/size/value, like: './write_jtag 0x1c000010 32 0x15263738'"

# make run show: " Area 0: offset: 0x800, base: 0x1c000004, size: 0x44, nbBlocks: 1 "
#                " Area 1: offset: 0x1000, base: 0x1c020000, size: 0x2ac, nbBlocks: 1 "

# in OUT_SIM_FILE show " Generating boot binary "
#                      " Nb areas: 2 "
#                      " flashOffset: 2048 "
#                      " Area 0: offset: 0x800, base: 0x1c000004, size: 0x44, nbBlocks: 1 "
#                      " Area 1: offset: 0x1000, base: 0x1c020000, size: 0x2ac, nbBlocks: 1 "
#                      " flashOffset: 6144 "
#                      " crc_offset: 144, flashOffset: 0, header_buff len: 48 "
#                      " header_buff: 144 "
#                      " Generating files (header offset: 0x1800) "

# OUT_FLASH_FILE show:
# 00
# 18
# 00
# 00
# 02
# 00
# 00
# 00
# 80
# 00
# 02
# ...

if [ $# == 1 ] && [ $1 == "-f" ]; then # if input "./jtag.sh -f" then flash the bitstream
    python $PROJECT_DIR/jtag.py $OUT_SIM_FILE $OUT_FLASH_FILE
    exit 0
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

# if input "./jtag.sh -h" or "./jtag.sh --help" then show help
if [ $# == 1 ] && ([ $1 == "-h" ] || [ $1 == "--help" ]); then
    echo "Usage: ./jtag.sh [OPTION]"
    echo "  -f, --flash    flash the bitstream"
    echo "  -r, --regs     show the regs"
    echo "  -h, --help     display this help and exit"
    exit 0
fi
