# ji_mcu

## quickly start：

1. 先运行：`source install.sh`

- 这个会更改项目的权限、安装相关库、修复 toolchain

2. 运行`source env.sh`：

- 这个会配置环境变量

3. 进入到`sdk/sw/app/<你的项目目录>`里：
   其中 makefile 配置中，大概是这样的：

   ```
   PULP_APP = test
   PULP_APP_SRCS = test.c
   # PULP_CFLAGS = -c

   PULP_CFLAGS = -O3 -g

   # Configuration

   RISCV_RCP_PATH = <你的 pulp-rt-spiv2 目录的绝对路径>
   include $(RISCV_RCP_SDK_PATH)/rules/pulp.mk
   ```

## build

- 我写了一个 makefile，使用`make all`可以编译 bootcode、runner，添加如`make all APPNAME=temp`可以编译 APP，并且无需修改`RISCV_RCP_PATH`，直接`make all`后默认是`APPNAME=temp`，同时也会编译顺便 pulp-builder，如果你只想编译 pulp-builder，就输入`make pulp_build`
