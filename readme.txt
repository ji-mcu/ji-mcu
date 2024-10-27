# jida
### my-ubuntu使用方法

1. 终端执行指令psh 、penv2，分别配置编译链和下载环境
2. 进入到文件夹sw/app/vendor路径下，可以用vscode打开文件夹
3. 在vendor路劲下有inclue ， src ，等子文件夹，分别放置头文件和源文件，main.c放置main，
4. 编译使用make all生成编译文件， make clean清除编译文件，make kgdb用于停止gdb下载打开的端口。
5. 执行penv2后会自动进入builder文件夹，，要把jtag下载器接好，然后执行./read_jtag看看接好了没
6. 接下来执行./flash.sh,进入gdb下载界面后用按y下载elf文件，然后按q退出（退出后记得在vendor那个路径下执行make kgb）
7. 可能需要拔插一下jtag，然后再执行read_jtag看看接没接好，再执行./cfg.sh,然后才是真正下载进去了代码。

