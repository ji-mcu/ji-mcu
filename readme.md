# jida
### my-ubuntu使用方法
  
  1. 终端执行指令psh 、penv，分别配置编译链和下载环境
     
  3. 进入到文件夹sw/app/vendor路径下，可以用vscode打开文件夹
     
  5. 在vendor路径下有inclue ， src ，等子文件夹，分别放置头文件和源文件，其余没在文件夹里的有如下几个文件：
       1.mian.c：是主程序文件；
       2.irq_asm.S：中断程序汇编部分，用于保存上下文，恢复上下文，跳转中断函数。
       3.crt0.S文件存放的是芯片的起始汇编文件，即boot.S;
       4.link.ld文件存放的连接器脚本，分配代码段地址。
       5.makefiler文件指定了需要编译的头、源、汇编文件，还有编译优化等级等等。
       6.要注意irq_asm.S ct0.S、link的存放路径其实是在：/home/ubuntu/work/ji-mcu/sdk/sw/pulp-rt-spiv2/kernel 内，因为整个sdk太大，所以只上传关键部分。
    
  6. 在vendor里最重要的文件有core_SFR.h、soc_common_.h、soc_event.h,
      分别存放了寄存器和数据地址、外设驱动库头文件、中断与异常函数驱动，
      所有外设驱动的文件风格为IC_XXX,什么外设就命名为什么，比如IC_SPI就是SPI的外设驱动。
     
  7. 在vendor的终端下，编译使用make all生成编译文件， make clean清除编译文件，make kgdb用于停止gdb下载打开的端口，make code 生成反汇编代码并存放在build文件夹，
     make load 用于下载elf文件到芯片中同时打开gdb，gdb可用于调试 ， make restart用于重载芯片boot地址并复位重启。
     退出gdb窗口按q，关闭gdb则在vendor终端按ctrl+c 。
     
 
      

