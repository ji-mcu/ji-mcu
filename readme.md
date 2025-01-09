# jida
### my-ubuntu使用方法
  
  1. 终端执行指令psh 、penv，分别配置编译链和下载环境
     
  3. 进入到文件夹sw/app/vendor路径下，可以用vscode打开文件夹
     
  5. 在vendor路径下有inclue ， src ，等子文件夹，分别放置头文件和源文件，其余没在文件夹里的有如下几个文件：
       1.mian.c：是主程序文件；
       2.irq_asm.S：中断程序汇编部分，用于保存上下文，恢复上下文，跳转中断函数。
       3.crt0.S文件存放的是芯片的起始汇编文件，即boot.S;
       4.link.ld文件存放的连接器脚本，分配代码段地址。
       5.要注意irq_asm.S ct0.S、link的存放路径其实是在：/home/ubuntu/work/ji-mcu/sdk/sw/pulp-rt-spiv2/kernel 内，因为整个sdk太大，所以只上传关键部分。
     
  7. 编译使用make all生成编译文件， make clean清除编译文件，make kgdb用于停止gdb下载打开的端口。
     
  9. 执行penv2后会自动进入builder文件夹，，要把jtag下载器接好，然后执行./read_jtag看看接好了没
      
  11. 接下来执行./flash.sh,进入gdb下载界面后用按y下载elf文件，然后按q退出（退出后记得在vendor那个路径下执行make kgb）
      
  13. 可能需要拔插一下jtag，然后再执行read_jtag看看接没接好，再执行./cfg.sh,然后才是真正下载进去了代码。
      

