# ji_mcu

请自觉到对应分支开发，已经配置 pull requests，代码会审核，写完代码后记得写 wiki.

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

- 我写了一个 makefile，使用`make all`可以编译 bootcode、runner，添加如`make all APPNAME=vendor`可以编译 APP，并且无需修改`RISCV_RCP_PATH`

- 直接`make all`后默认是`APPNAME=vendor`，同时也会顺便编译 pulp-builder，如果你只想编译 pulp-builder，就输入`make pulp_build`

- 我添加了一个 vendor 目录，所有的代码都可以在这个目录下写，入口函数应该就是 main.c 里的 main 函数，我们可以在 main.c 里调用 src 目录的函数，添加功能就行了，比如我就添加了一个 gpio
- 源文件好像有 bug，它的 printf 好像不能添加变量，一添加就链接不了，还是直接用 uart 吧

## pulp_build issue：

- 如果你的环境配置不同，可能无法正确编译 pulp，这时：

  - 进入这些目录：`sdk/pulp-builder/json-tools`、`sdk/pulp-builder/pulp-configs`
  - 分别执行`cmake CMakeLists.txt`，这样就可以生成对应的 makefile，之后再进行`make pulp_build`就行了
