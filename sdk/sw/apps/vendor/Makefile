PULP_APP = vendor # 最终文件

# 当前目录
MAKEFILE_APP_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# 查找src/下的所有.c文件和main.c文件
PULP_APP_SRCS = $(wildcard src/*.c)
PULP_APP_SRCS += main.c

# 添加头文件路径
PULP_CFLAGS = -O3 -g -I$(join $(MAKEFILE_APP_DIR),include)
PULP_LDFLAGS = -Wl,-Map=build/output.map

# Configuration
RISCV_RCP_SDK_PATH = /home/adminuser/my_work/ji_mcu/work/ji-mcu/sdk/sw/pulp-rt-spiv2
include $(RISCV_RCP_SDK_PATH)/rules/pulp.mk



