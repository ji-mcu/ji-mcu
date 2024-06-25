# base set
export make_cmd = $(MAKE)
export CORES := $(shell nproc) # get core nums
export V
export VERBOSE

# make V= 可以看见Makefile运转的细节，VERBOSE=1 可以看见每个命令的输出
V ?=@ 

# 当V为空时，VERBOSE=1
ifeq ($(V),)
	VERBOSE=1
endif

# local set
makefile_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST)))) # this makefile dir, $(MAKEFILE_LIST) is a special variable to get the path of the current makefile

boot_build_dir := $(join $(makefile_dir),sdk/sw/boot-code-rt) # boot build dir
runner_build_dir := $(join $(makefile_dir),sdk/sw/runner) # runner build dir

app_build_dir := $(join $(makefile_dir),sdk/sw/apps/) # app build dir, you need add an app name to the end of this path
APPNAME := vendor # app name

pulp_build_dir := $(join $(makefile_dir),sdk/pulp-builder) # pulp build dir

SHELL := /bin/bash

# make all
all: build

build: app_build

# APP env
RISCV_RCP_SDK_PATH_ENV := $(join $(makefile_dir),sdk/sw/pulp-rt-spiv2)

# add an app name to the end of this path, such as make all APPNAME=vendor
app_build:
	@echo "Building app code..."
	source env.sh && $(make_cmd) -e -C $(join $(app_build_dir),$(APPNAME)) RISCV_RCP_SDK_PATH=$(RISCV_RCP_SDK_PATH_ENV) all

build_other: boot_build runner_build pulp_build

boot_build:
	@echo "Building boot code..."
	source env.sh && $(make_cmd) -e -C $(boot_build_dir)
	
runner_build:
	@echo "Building runner code..."
	source env.sh && $(make_cmd) -e -C $(runner_build_dir)

pulp_build:
	@echo "Building pulp ..."
	cd $(pulp_build_dir) && source configs/pulp.sh && sudo chmod 777 scripts/build-debug-bridge && sudo ./scripts/build-debug-bridge

clean:
	@echo "Cleaning..."
	source env.sh && $(make_cmd) -e -C $(join $(app_build_dir),$(APPNAME)) RISCV_RCP_SDK_PATH=$(RISCV_RCP_SDK_PATH_ENV) clean


PULP_APP_NAME := $(APPNAME)
run:
	@echo "Running flash making..., dir is $(runner_build_dir)"
	source env.sh && cd $(runner_build_dir) && python bin/plp_mkflash --flash-boot-binary=$(join $(join $(join $(app_build_dir),$(APPNAME)),/build/$(PULP_APP_NAME)),/$(PULP_APP_NAME))  --stimuli=flash_stim.slm --flash-type=spi --qpi --archi=pulpissimo --raw flash.bin --verbose | tee out.txt
	@echo "flash..."
	./jtag.sh -f $(PULP_APP_NAME)
	./jtag.sh -r 0x1c020000


.PHONY: all build app_build build_other boot_build runner_build pulp_build run