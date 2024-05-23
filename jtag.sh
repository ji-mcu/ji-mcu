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
    echo "search for $OUT_SIM_FILE"
    # flash data area
    echo "JTAG FLASH data..."                                                                      # search and find Area 0: offset: 0x800, base: 0x1c000004, size: 0x44, nbBlocks: 1
    data_area=$(grep -n "Area 0:" $OUT_SIM_FILE)                                                   # get the line number of "Area 0:"
    data_offset=$(echo $data_area | awk -F "offset: " '{print $2}' | awk -F ", base" '{print $1}') # get the offset of "Area 0:"
    data_offset_decimal=$(printf "%d" $data_offset)                                                # convert hex to decimal
    data_base=$(echo $data_area | awk -F "base: " '{print $2}' | awk -F ", size" '{print $1}')     # get the base of "Area 0:"
    data_size=$(echo $data_area | awk -F "size: " '{print $2}' | awk -F ", nbBlocks" '{print $1}') # get the size of "Area 0:"
    data_size_decimal=$(printf "%d" $data_size)                                                    # convert hex to decimal
    echo "data_offset: $data_offset, data_base: $data_base, data_size: $data_size_decimal"

    # flash instruction area
    echo "JTAG FLASH instruction..."                                                               # search and find Area 1: offset: 0x1000, base: 0x1c020000, size: 0x2ac, nbBlocks: 1
    inst_area=$(grep -n "Area 1:" $OUT_SIM_FILE)                                                   # get the line number of "Area 1:"
    inst_offset=$(echo $inst_area | awk -F "offset: " '{print $2}' | awk -F ", base" '{print $1}') # get the offset of "Area 1:"
    inst_offset_decimal=$(printf "%d" $inst_offset)                                                # convert hex to decimal
    inst_base=$(echo $inst_area | awk -F "base: " '{print $2}' | awk -F ", size" '{print $1}')     # get the base of "Area 1:"
    inst_size=$(echo $inst_area | awk -F "size: " '{print $2}' | awk -F ", nbBlocks" '{print $1}') # get the size of "Area 1:"
    inst_size_decimal=$(printf "%d" $inst_size)                                                    # convert hex to decimal
    echo "inst_offset: $inst_offset, inst_base: $inst_base, inst_size: $inst_size_decimal"

    # flash bitstream hex file
    echo "search for $OUT_FLASH_FILE"
    # offset 1: search from offset decimal line to the size decimal，and joint together
    data0=$(sed -n "$((data_offset_decimal + 1)),$((data_offset_decimal + data_size_decimal))p" $OUT_FLASH_FILE | tr -d '\n')
    # at the top add "0x"
    data0="0x$data0"
    echo "data0: $data0"

    # offset 2: search from offset decimal line to the size decimal，and joint together
    data1=$(sed -n "$((inst_offset_decimal + 1)),$((inst_offset_decimal + inst_size_decimal))p" $OUT_FLASH_FILE | tr -d '\n')
    # at the top add "0x"
    data1="0x$data1"
    echo "data1: $data1"

    # jtag write
    ./write_jtag $data_base $data_size_decimal $data0
    ./write_jtag $inst_base $inst_size_decimal $data1

    exit 0
fi

# if input "./jtag.sh -r" then show the regs
if [ $# == 1 ] && [ $1 == "-r" ]; then
    echo "JTAG REGS"
    exit 0
fi
