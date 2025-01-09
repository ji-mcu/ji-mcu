PULP_APP = vendor # 最终文件

# Configuration
RISCV_RCP_SDK_PATH = ~/work/ji-mcu/sdk/sw/pulp-rt-spiv2

# 当前目录
MAKEFILE_APP_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
PULP_APP_HDRS += $(RISCV_RCP_SDK_PATH)/include/hal/riscv/riscv_v5.h
# 查找src/下的所有.c文件和main.c文件
EXCLUDE_SRCS = src/oled.c src/IC_timer1.c 
# src/IC_I2S.c
PULP_APP_SRCS = $(filter-out $(EXCLUDE_SRCS), $(wildcard src/*.c))
# PULP_APP_SRCS = $(wildcard src/*.c)

EXCLUDE_HDRS += src/oled.h 
# EXCLUDE_HDRS += include/IC_I2S.h
# EXCLUDE_HDRS += include/spi_v1.h
EXCLUDE_HDRS += include/uart.h
PULP_APP_HDRS = $(filter-out $(EXCLUDE_HDRS), $(wildcard src/*.h))
# PULP_APP_HDRS += $(wildcard include/*.h)
PULP_APP_SRCS += main.c

# 添加头文件路径
# PULP_CFLAGS += -O3 -g 
PULP_CFLAGS += -g -I$(join $(MAKEFILE_APP_DIR),include)
PULP_LDFLAGS = -Wl,-Map=build/output.map



PULP_APP_SRCS += $(RISCV_RCP_SDK_PATH)/kernel/irq.c kernel/init.c $(RISCV_RCP_SDK_PATH)/lib/libc/minimal/io.c

# PULP_ASM_SRCS += trap_entry.S $(RISCV_RCP_SDK_PATH)/kernel/crt0.S 
PULP_ASM_SRCS += $(RISCV_RCP_SDK_PATH)/kernel/crt0.S  $(RISCV_RCP_SDK_PATH)/kernel/irq_asm.S

PULP_LDFLAGS      += 
PULP_CFLAGS       +=  -D__riscv__
# PULP_ARCH_CFLAGS ?=  -march=rv32imcxpulpslim
# PULP_ARCH_LDFLAGS ?=  -march=rv32imcxpulpslim
# PULP_ARCH_OBJDFLAGS ?= -Mmarch=rv32imcxpulpslim
PULP_ARCH_CFLAGS ?=  -march=rv32imcxpulpslim
PULP_ARCH_LDFLAGS ?=  -march=rv32imcxpulpslim
PULP_ARCH_OBJDFLAGS ?= -Mmarch=rv32imcxpulpslim
# PULP_CFLAGS    += -fdata-sections -ffunction-sections -include $(RISCV_RCP_SDK_PATH)/include/chips/pulpissimo/config.h -I$(RISCV_RCP_SDK_PATH)/include/chips/pulpissimo
PULP_OMP_CFLAGS    += -fopenmp -mnativeomp
PULP_LDFLAGS += -nostartfiles -nostdlib -Wl,--gc-sections -L$(RISCV_RCP_SDK_PATH)/kernel -T $(RISCV_RCP_SDK_PATH)/kernel/chips/pulpissimo/link.ld -lgcc


include $(RISCV_RCP_SDK_PATH)/rules/pulp.mk

