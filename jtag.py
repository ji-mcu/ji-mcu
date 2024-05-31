# -*- coding: UTF-8 -*-

# the file in order to find area data in the file <OUT_FLASH_FILE>

import os
import sys
import re

# input "python jtag.py <OUT_SIM_FILE> <OUT_FLASH_FILE>"
if len(sys.argv) != 3:
    print("Usage: python jtag.py <OUT_SIM_FILE> <OUT_FLASH_FILE>")
    sys.exit(1)

# open the file <OUT_SIM_FILE>
try:
    with open(sys.argv[1], "r") as f:
        out_sim = f.read()
except IOError:
    print("Error: Cannot open file %s" % sys.argv[1])
    sys.exit(1)

# open the file <OUT_FLASH_FILE>
try:
    with open(sys.argv[2], "r") as f:
        out_flash = f.read()
except IOError:
    print("Error: Cannot open file %s" % sys.argv[2])
    sys.exit(1)

# find the line number of "Area 0:"
data_area = re.search(r"Area 0:", out_sim)
if data_area is None:
    print("Error: Cannot find Area 0 in %s" % sys.argv[1])
    sys.exit(1)
data_offset = re.search(r"offset: 0x([0-9a-fA-F]+),", out_sim)
if data_offset is None:
    print("Error: Cannot find offset in %s" % sys.argv[1])
    sys.exit(1)
data_offset_decimal = int(data_offset.group(1), 16)
data_base = re.search(r"base: 0x([0-9a-fA-F]+),", out_sim)
if data_base is None:
    print("Error: Cannot find base in %s" % sys.argv[1])
    sys.exit(1)
data_size = re.search(r"size: 0x([0-9a-fA-F]+),", out_sim)
if data_size is None:
    print("Error: Cannot find size in %s" % sys.argv[1])
    sys.exit(1)
data_size_decimal = int(data_size.group(1), 16)
data_size_bits = data_size_decimal * 8
print("data_offset: %d, data_base: %s, data_size: %dB" % (data_offset_decimal, data_base.group(1), data_size_decimal))

# find the line number of "Area 1:"
inst_area = re.search(r"Area 1:", out_sim)
if inst_area is None:
    print("Error: Cannot find Area 1 in %s" % sys.argv[1])
    sys.exit(1)
# at the Area 1: next
inst_offset = re.search(r"offset: 0x([0-9a-fA-F]+),", out_sim[inst_area.end():])
if inst_offset is None:
    print("Error: Cannot find offset in %s" % sys.argv[1])
    sys.exit(1)
inst_offset_decimal = int(inst_offset.group(1), 16)
inst_base = re.search(r"base: 0x([0-9a-fA-F]+),", out_sim[inst_area.end():])
if inst_base is None:
    print("Error: Cannot find base in %s" % sys.argv[1])
    sys.exit(1)
inst_size = re.search(r"size: 0x([0-9a-fA-F]+),", out_sim[inst_area.end():])
if inst_size is None:
    print("Error: Cannot find size in %s" % sys.argv[1])
    sys.exit(1)
inst_size_decimal = int(inst_size.group(1), 16)
inst_size_bits = inst_size_decimal * 8
print("inst_offset: %d, inst_base: %s, inst_size: %dB" % (inst_offset_decimal, inst_base.group(1), inst_size_decimal))

# find area in <OUT_FLASH_FILE>, because the system difference, need read the two hex at the front of \n
# system1:
# such @00000000 00
#      @00000002 00
# system2:
# or 00
#    01

# you need ignore @00000000, such as del @[0-9a-fA-F]
all = re.sub(r"@([0-9a-fA-F]+)", "", out_flash)
# del only space
all = re.sub(r" ", "", all)

# find area in <OUT_FLASH_FILE>
data0 = all.split("\n")[data_offset_decimal : data_offset_decimal + data_size_decimal]
data0 = "".join(data0)
data0 = "0x" + data0
data0 = re.sub(r"\s+", "", data0)
print("data0: %s" % data0)
# because the jtag is fifo to write, so need to write the data0 reverse
data0 = re.sub(r"0x", "", data0)
# such as origin is "0x0102", change to "0x0201", data[::-1] is "2010"
data0 = data0[::-1] # reverse every two hex
for i in range(0, len(data0), 2):
    data0 = data0[:i] + data0[i+1] + data0[i] + data0[i+2:]
data0 = "0x" + data0

data1 = all.split("\n")[inst_offset_decimal : inst_offset_decimal + inst_size_decimal]
data1 = "".join(data1)
data1 = "0x" + data1
data1 = re.sub(r"\s+", "", data1)
print("data1: %s" % data1)
# because the jtag is fifo to write, so need to write the data1 reverse
data1 = re.sub(r"0x", "", data1)
data1 = data1[::-1] # reverse every two hex
for i in range(0, len(data1), 2):
    data1 = data1[:i] + data1[i+1] + data1[i] + data1[i+2:]
data1 = "0x" + data1

# jtag write
    #./write_jtag $data_base $data_size_bits $data0
    #./write_jtag $inst_base $inst_size_bits $data1
# run 'write_jtag' with different address/size/value, like: './write_jtag 0x1c000010 32 0x15263738'"
print("jtag write")

# write data0
os.system("./write_jtag %s %d %s" % ('0x'+ data_base.group(1), data_size_bits, data0))
# write data1
os.system("./write_jtag %s %d %s" % ('0x'+ inst_base.group(1), inst_size_bits, data1))

# wirte start
os.system("./write_jtag %s %d %s" % ('0x1A101004' , 32, '0x'+ inst_base.group(1)))
os.system("./write_jtag %s %d %s" % ('0x1A101008' , 8, '0x00'))
os.system("./write_jtag %s %d %s" % ('0x1A101008' , 8, '0x01'))

