### vendor工程开发计划

#### 系统开发日志

1. 中断工程
    
    中断工程目标：

        1. 更改 启动汇编文件和链接器脚本 使之达到不用pulp平台也能正常运行与下载的程度

            bootloader的编写方式 如何在启动阶段就更改


        2. 添加中断号，然后优先测试timer中断和gpio中断

        3. 编写bootloader文件 下载程序时候自动复位并启动
        4. 要记得挪用环境自带的一些文件做操作和指引,EU是关键词
        5. 添加一个systeminit函数，存放时钟配置和复位操作
        6. 添加一个中断init函数 ，配置CSR寄存器关于中断和中断地址
        7. 增加adc采样控制函数




2. 系统时钟获取配置

3. dac和adc功能采样

4. 系统其他功能配置：

    1. 写好I2S 和 SPI 驱动库
    
     ，为了做MP3做准备

        11/9 
            此处可参考pulp平台文
            件
            此外 是否可以获得sdk包

        11/22
            看门狗在哪里？

        11/24 
            sensor_id 这个soc控制寄存器的作用是什么
        
        11/26 
            FC interrupt是什么

        12/3
            根据内核具体设计不同， csr寄存器的配置方法可能不一样

        12/7
            https://github.com/pulp-platform/pulpino/blob/master/sw/ref/crt0.riscv.S
            https://github.com/pulp-platform/pulp-rt-examples/blob/16bae13408e848350189261d4ce6e63a1f2ed33b/time/timer_oneshot/test.c#L28
            https://github.com/GreenWaves-Technologies/gap_sdk/blob/a23026507efe57410b98c5945544cff3150eb996/gap8/rtos/pulp/pulp-os/kernel/events.c#L103
            https://github.com/iis-eth-zurich/hemera/blob/a2e4750f09ce61f7458417dc92b1b381c143c3e2/pulp/pulp-runtime/kernel/init.c#L62

        12/10 
            如何改变main的入口-即切换所使用的core核心
        12/15 
            发现用interrupt关键字实现不了自动保存上下文操作


    2. 优化I2C的驱动库

        11/12
            可以为其在udma结构体新增一个几个字节，用来配置不变的配置，并从那里启动，并判断其是否自增。
            另外，有没有可能做到两个结构体结合，可以用一个结构体或者什么的封装，指向不同地址（是否结构体内可以套回调函数指针的做法）

    3. 对Codec音频模块进行 研究和功能配置 编写驱动库



#### 

#### ----------------------------------------

#### GPIO 开发日志：

GPIO选通只有0-18 位是有效的 ， 虽然是32位总线 但是底层做了限制

    pad_mux描述功能如下：

    寄存器reg0 和 寄存器reg1 
    寄存器reg0配置pin脚0-15
    寄存器reg1配置pin脚16-31（实际上只有16-18）
    配置方式如下：以寄存器reg0为例
    寄存器reg0=32‘b0000-0000-0000-0000-0000-0000-0000-0000
    按位置1，每一个pin分配两位;假如要配置pin0和pin1,
    那么就是配置reg低4位=0x5,即配置0000为01 01(配置的时候从右往左看，配置完毕后从左往右看)，那么pin0的fun会被配置为01,和01,此时功能脚对应为i2c1


#### ----------------------------------------

#### PWM 开发日志

    PWM （PMM脉冲计数时钟）基准时钟频率Fpwm = 系统主频Fsys/((pwm_div+1)*2)

    为了让pwm—div更好控制，令其为2的倍数是最好的

    PWM 输出频率Fpwm-out = Fpwm/(pwm_cfg[31:16]+1) ; 
    若令pwm_cfg[31:16] = 2^n -1 ;
    则Fpwm-out = Fpwm/2^n -1  ;

    PWM占空比Ncyc = pwm_cfg[15:0]/(pwm_cfg[31:16]+1) ;

    想要让占空比为50% 
    若令pwm_cfg[31:16] = 2^n -1 ;
    则pwm_cfg[15:0] = 2^(n -1) ; 

    n为二进制位数

    pwm_div>=0,如果pwm_div=0 , Fpwm=Fsys/2,一般为32M

    当PWM_div=0, cfg必须大于{16‘d1，16'd1} ，等于1时PWM输出高电平

    如果cfg={16‘d3，16'd2}，Fpwm-out =8M，这是占空比=50的最大频率，

    理论上n=2～16,即占空比1/65536 ，但是这种过于极端 ，尽量遵从二进制占空比进行计算会好点。

#### ----------------------------------------

#### timer开发日志

寄存器配置要点

    1. cfg_lo cfg_hi寄存器区别在cfg lo的bit31有64bit mode使能模式
    2. cfg_lo cfg_hi寄存器的bit5是指只比较单次，就停止比较等待下一次使能重启比较的意思；
        bit 4不置为1那么每次只会比较一次并且timer持续计数直到为最大值才停下。
    3. cfg_lo 和cfg_hi 的分频系数只允许0-255,多则无效，公式为Ftimer=Fclk/(1+x);
    4.配置先后顺序：配置先后顺序可如下配置
        apb_write(TIMER_CMP_LO,32'd256);
        apb_write(TIMER_VAL_LO,32'd0);
        apb_write(CFG_REG_LO,32'h00_ff_ff_51);
        apb_write(TIMER_START_LO,32'd1);
    


#### ----------------------------------------

#### ----------------------------------------

#### Uart开发日志：
 
#### 9/21：目前需要知道uart的波特率配置公式。其波特率与系统主频的关系

#### 9/22：
通过源码，uart核心是配置寄存器setup，寄存器setup可以配置波特率，tx/rx起始位使能，uart_bit决定了接收到的串口数据位数（事实上是校验位数），还有停止位和奇偶校验位使能。

波特率的配置也许有两种方式：

1.(64∗10^6/115200 -1)=555.5555，即Fsys/2/555.55……=115200

2.直接填115200波特率

#### 9/24：
uart存储数据和发送数据：在sram中找初始地址，按字节存入数据，按字节丢出数据，存放数据的方式仍然是根据udma,按字节为地址存入数据，有序取出

#### 9/26：
需要知道uart数据在信号线进来之后是如何传输的，要看一下uart的fifo能存多大的数据，能不能每次自动判断传进来的数据字节有多大
假定每次只接收一个字节

#### 9/28 
uart的中断如何配置？

#### 9/29


    uart—CFG寄存器定义：cfg[5]=clr 停止rx并清除临时数据
                        cfg[4]=rxen 使能位
                        cfg[0]=连续传输模式，1有效

    status寄存器用来判断当前接收状况，是否允许接收，
    status[0]=tx_status,status[1]是rx_status，status[2]=err_parity_status

    setup = {uart_div[32:16], 6'h0,
            uart_en_rx[1],uart_en_tx[1], 
            4'h0, uart_stop_bits[1],uart_bits[2],
            uart_parity_en[1]
            };
    // 0x24 setup[31:16]配置波特率 [9]rx使能 [8]tx使能 [3]stopbit-仅对tx有用，0为1个stopbit,1为2个stopbit [2:1]uart_bit [0]parity_en
    uart_bits://11为每次收到数据为8个bit
            2'b00:
                s_target_bits = 3'h4;
            2'b01:
                s_target_bits = 3'h5;
            2'b10:
                s_target_bits = 3'h6;
            2'b11:
                s_target_bits = 3'h7;
    先配置如下：再配置tx en和rx en
    r_uart_div        <= s_uart_div;
    r_uart_parity_en  <=s_uart_parity_en;
    r_uart_bits       <= s_uart_bits;
    r_uart_stop_bits  <=s_uart_stop_bits;

####2024/10/31

    uart的DMA配置设想：
        
        发送数据：制定DMA外设缓冲区首地址以及数据长度 并开启发送
        接收数据:分为接收定长数据和不定长数据，接收定长数据只需要检测dma传输完成标志，不定长数据可以通过串口空闲中断来判断接收是否完成，接收完成后再计算传入多少个数据，为了避免太多数据，设置双缓冲区。

        uart可以固定打开continous配置，使能接收区不断接收，


2024/10/31

    对系统priintf进行了重定向，可以使用soc_printf() 和 pritnf()两个函数进行打印。


#### ----------------------------------------

#### I2C开发日志：

10/2

寄存器与uart名字和偏移量一致，代码实现上有所差别
需要知道status寄存器，ack的作用是什么，

    ADDR寄存器：正常填入地址;
    Size寄存器：正常填入字节数;
    CFG寄存器：{0}为连续传输模式 {4}为传输使能位 {5}为清udma缓存位 ，每次发送的时候都要重新设置一遍，否则发送后自动清零 ，即要在所有前置步骤做完后再配置;
    Setup寄存器：{0}位为全局复位rst ，为1的时候软件复位
    Status寄存器：{3：0}={data_store_req , ack , al, busy} status寄存器位都是1有效，当req=1时，代表可读取数据
    ack=0是ack,ack=1是nack,只写的时候要保持ack位一直为0 读的时候要以ack=1+stop为结尾，sends a NACK  to tell slave device that data transmission shall end
    busy=1表示当前发送一个字节或者一次完整读写操作没有完成
    al=1表示总线仲裁丢失状态

10/4

    udma读写关键字:8'hx0,且x位于低8位的高4位上，以下为关键字指令：

|   关键字  | 作用     | 使用方式  |
| :----:  | :------: | :----   |
| 0x0  | 开始I2C传输命令    | 可以出现在第一个写入在sram中，此项命令完成后I2C会停止，等待下一步配置读、写或者配置波特率、配置字节数 |
| 0x2  | 结束I2C传输命令    | 必须最后一个出现在sram中  |
| 0x4  | 开始I2C读命令    | 一般在出现在接受数据前的sram中|
| 0x6  | 同样是I2C读命令 | 出现在最后一次读取数据，声明不再读数据|
| 0x8  | I2C写命令 |  每次写出1byte数据 直到配置的字节数发完，在写数据前最后发出|
| 0xA  | I2C总线等待| 主动延迟xbit位|
| 0xC  | 配置I2C读写字节数|要在每次读写命令前设置 读写数为num-1|
| 0xE  | 配置I2C波特率| 配置方式是sram里连续填入两个字节a和b, 硬件会将依次赋值给高8位和低八位的div-num寄存器，先配高8位再配置低8位，波特率组合为div=ab,初始的div=100 ，实际波特率计算方式是：Fsys/(div_num*4+div_num/4)
| 0x1  | I2C等待中断|备注：暂时忽略|

11/5：

    I2C的测试要用逻辑分析仪测。

11/9： 
    
    每次在stop之后，I2C一切配置重置，所以需要固定几个字节用来配置波特率和启动波形。
    即要改造i2c-udma的结构体，让出几个字节配置。

2025/1/1:
    1.
    2.rpt指令配置的字节读取地址数是x-1,而寄存器配置的size就是x

#### ----------------------------------------

#### I2S开发日志：
    
    1.先实现基础的函数要求

    2.可以定义一种结构体和联合体
        定义寄存器结构体，在该结构体内使用联合体，对寄存器细分为位，进行位的赋值

    3.需要了解一下I2S的原理

    4.寄存器配置如下：
        REG_I2S_EXT_SETUP：
        
            配置ws的输出频率公式为 fsck_i/(2*(x+1)) //对外无效 对内当cfg-setup有10时配置给内部ws ,最小1最大31 ,sck是外部输入的sck,不是内部产生

        REG_I2S_CHMODE:
            原代码上包含了4个i2s通道配置0-3 理论上有效的应该只有通道0和1
            每一位的定义看IC_I2S.h文件
            choice-sck(bit24:25)：
                00：使用内部sck与ws , set by REG_I2S_CFG0_SETUP
                01: 使用内部sck与ws , set by REG_I2S_CFG1_SETUP
                10: 使用外部sck和内部ws , ws set by REG_I2S_EXT_SETUP
                11: 使用外部sck和ws
        TX通道的一切配置只与它本身和Rx-cfg0相关





#### ----------------------------------------




#### udma开发日志

每次根据传递进来的地址，对地址指针进行地址定位;
udma存储数据和发送数据，应该要以一个字节为基础的偏移地址
需要更改udma结构体长度就更改其结构体长度。

udma要构造一个结构体，可以赋一个地址给它，进行配置。

    1.udma的外设统一有读忙的标志，即读取cfg位。
        读取bit5,判断是否使能;读取bit4使能或者判断是否处于busy

    2.udma外设可以有统一的接口方式：

    3.新建一个udma头文件，为所有的udma提供统一外设
        

#### ----------------------------------------

#### Lin  开发日志：

    波特率计算方式为Fsys/16/baudrate -1 ;

    LIN测试方式：回环接

#### ----------------------------------------

#### ----------------------------------------

#### Codec 开发日志：

    目前暂未开发

#### ----------------------------------------


#### ----------------------------------------

#### ADC——DAC 开发日志：

    正在开发
    1.VCM是多少？
    
    1.SAR—ADC输入时钟为16M,采样率默认750K,最大采样率为1MHz，默认单端模式，双通道adc

    2.工作频率计算公式为Fadc=Fsys/(x+1)/2，Vrefn=0.9v,Vrefp=1.8v

    3. adc为12bit（0-0xfff）,VIN = VCM=1.7V,Vid= VIP-VIN ，VIP=VIN,电压转换公式为Vout=4096*(1.2+Vid)/(2*1.2)

    4.电压允许范围为0-1.8V

    5.差分怎么设置? 怎么判断adc读取完毕？直接从寄存器得到的数据是不是就是电压数值了


    1.DAC配置方法：DAC12-n=1,输入数值 

    2.计算公式是什么？






#### ----------------------------------------


#### ----------------------------------------

#### 中断开发日志：

    1.中断需要修改的有起始汇编文件和链接脚本，附带的头文件和原文件命名为soc-event
    2.汇编要修改的是初始化入口，对栈区和特殊寄存器进行初始化，并且重设入口地址，并添加各设备的中断函数，中断函数需要有保存和恢复上下文并返回现场的汇编
    3.soc-event文件负责初始化中断，可手动注册各中断函数或者保持默认的中断函数，构建中断函数需要对中断标志进行清除和重建等的操作，
    4.简述硬件底层soc-event和int-ctrl两个模块的关系：

        1.各外设模块将中断信号集中到s-event和fc-event
            s-event（47位）进入到soc-event，
            fc-event发送到int-ctrl
            soc-event模块输出fc-event-fifo-data/vali/ready三个信号，最终输出到int-ctrl

        2.fc-event直接作为中断号/线引发core的中断（32位中断），fc-event-data只能由apb总线读取，用来识别引发异常中断的是哪一个外设。

        3.soc-event还有一个功能，当int-ctrl读取fifo发现异常号时候，可以将该异常号配置回soc-event的的定时器异常设置，引发定时开始计时，引发定时器中断
    5.中断配置顺序：
        void wait_soc_event(){
            hal_itc_enable_set(1 << FC_EVT_SOC_EVT);
            while(!((itc_status_get() >> FC_EVT_SOC_EVT) & 1))
            {
            hal_itc_wait_for_interrupt();
            }
            itc_fifo_pop();
            itc_status_clr(1 << FC_EVT_SOC_EVT);
            itc_enable_clr(1 << FC_EVT_SOC_EVT);
            }
        4.中断和异常是两部分模块，需要通过不同的函数进行配置

#### ----------------------------------------


#### ----------------------------------------

#### SPI 开发日志：

    1. spi有三种模式：qspi、dspi、spi
        默认单线spi模式
        

    2.  关键字定义如下：关键字在32位数据的bit28-bit31,共4位 ，RPT是配置读写字节数 ；可以定义一个结构体，命令数据的结构体，定义不同位的功能
    
| 关键字           | 大小     |作用   | 使用方式  |
| :----           | :------:| :---- |:----   |
| SPI_STD          | 2'b00  |       |   |
| SPI_CMD_CFG      |4'b0000 |配置波特率/时钟极性/相位  |波特率公式：Fspi=Fsys/(x*2);clk_civ=bit[0:7],cpol=bit9,pha=bit8 |
| SPI_CMD_SOT      |4'b0001 | 使能cs，如果prt命令使用过还会进入rpt|cs=bit[1:0],cs=00=csn0_o cs=2'b01=spi_csn1_o cs=2'b10=spi_csn2_o cs=2'b11=spi_csn3_o |
| SPI_CMD_SEND_CMD |4'b0010 |发送指令数据，RPT启动过的情况下会进入rpt分支| cfg_qpi=bit[27];cfg_dpi=bit[23]; cmd_data=bit[15:0];size=bit[20:16] |
| SPI_CMD_SEND_ADDR|4'b0011 | 发送指令地址 |   |
| SPI_CMD_DUMMY    |4'b0100 | 确保接收操作完整  |   |
| SPI_CMD_WAIT     |4'b0101 | 进入等待异常状态| 异常通道evt_sel=bit[1:0]  |
| SPI_CMD_TX_DATA  |4'b0110 | 发送数据 | s_cfg_custom=·bit[26],s_size_long=bit[15:0]|
| SPI_CMD_RX_DATA  |4'b0111 | 接收数据 |   |
| SPI_CMD_RPT      |4'b1000 |使能RPT，重读命令，配置读写字节数 |num=size_long-1;如果使用这个命令spi会返回空闲状态，即它需要在最早的时候使用，并且会导致其他命令会进入rpt的分支  |
| SPI_CMD_EOT      |4'b1001 | 异常输出 | eot=bit[0]  |
| SPI_CMD_RPT_END  |4'b1010 | 同rpt |   |
| SPI_CMD_RX_CHECK |4'b1011 | 检查接收  | 仅在rpt使能的前提下有效  |
| SPI_CMD_FULL_DUPL|4'b1100 | 全双工指令|   |
| SPI_CMD_WAIT_CYC |4'b1101 |  延时等待  |  等待周期cyc=bit[7:0] |


    3.SPI库函数所需要素：
        1.配置并发送命令://可以包含一个cmd结构体，其地址不需要与数据地址相接
            1. 配置cfg：包含波特率、时钟极性、时钟相位
            2. 配置cs启动/或GPIO代替
            3. 配置结束标志
            4.其他命令

        2.配置寄存器：
            0.配置引脚功能
            1.同时配置spi 发送/接收地址、发送/接收字节数、使能位
            2.判断是否处于忙状态
            3.判断是否允许使能
            4.
    4.SPI所需要函数：
        1.引脚功能初始化
        2.初始化函数：初始化CMD结构体 --该函数不应该用在main的init里
        3.发送CMD命令函数
        4.判断忙函数
        3.发送函数：发送多字节
        4.接收函数：接收多字节
        5.中断函数：
        5.等待中断函数、、
        6.读取cmd内容 ，判断波特率和cs、qpi、dpi等内容
    5.初始化结构体所需要素：
        1.波特率；2.时钟极性;3.时钟相位；
        4.字节长度；5.字节对齐；6.qpi;7.dpi;
        8.cs选择




#### ----------------------------------------
