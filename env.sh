#!/bin/bash

PROJECT_DIR=$(pwd)

# env
# 配置交叉编译链环境
cd sdk/
source set_toolschain_env.sh
export PATH=$PROJECT_DIR/sdk/toolchain/bin:$PATH
# 编译环境
cd sw/
source pulp-rt-spiv2/configs/pulpissimo.sh

cd $PROJECT_DIR
