PULP_APP = vendor # 最终文件

# 当前目录
MAKEFILE_APP_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

# 查找src/下的所有.c文件和main.c文件
EXCLUDE_SRCS = src/oled.c src/IC_timer1.c 
PULP_APP_SRCS = $(filter-out $(EXCLUDE_SRCS), $(wildcard src/*.c))
# PULP_APP_SRCS = $(wildcard src/*.c)

EXCLUDE_HDRS = src/oled.h
PULP_APP_HDRS = $(filter-out $(EXCLUDE_HDRS), $(wildcard src/*.h))
# PULP_APP_HDRS += $(wildcard include/*.h)
PULP_APP_SRCS += main.c

# 添加头文件路径
PULP_CFLAGS = -O3 -g -I$(join $(MAKEFILE_APP_DIR),include)
PULP_LDFLAGS = -Wl,-Map=build/output.map

# Configuration
# RISCV_RCP_SDK_PATH = /home/adminuser/my_work/ji_mcu/work/ji-mcu/sdk/sw/pulp-rt-spiv2
RISCV_RCP_SDK_PATH = /home/ubuntu/work/ji-mcu/sdk/sw/pulp-rt-spiv2
include $(RISCV_RCP_SDK_PATH)/rules/pulp.mk





