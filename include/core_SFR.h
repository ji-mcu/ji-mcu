/* Define for ji-mcu              */
/* Email:    3056830955@qq.com    */
/* Author:   huangjin 2024/7/30   */
/* V0.1 SpecialFunctionRegister */

#ifndef __H_CORE_SFR__
#define __H_CORE_SFR__



#ifdef __cplusplus
extern "C"
{
#endif
    /* ********************************************************************************************************************* */
    /* Base types & constants */

// #include "soc_common.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "core_sys.h"

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif
#ifndef NULL
#define NULL 0
#endif

#ifndef VOID
#define VOID void
#endif
#ifndef CONST
#define CONST const
#endif
#ifndef BOOL
typedef unsigned char BOOL;
#endif
#ifndef BOOLEAN
typedef unsigned char BOOLEAN;
#endif
#ifndef CHAR
typedef char CHAR;
#endif
#ifndef INT8
typedef char INT8;
#endif
#ifndef INT16
typedef short INT16;
#endif
#ifndef INT32
typedef long INT32;
#endif
#ifndef UINT8
typedef unsigned char UINT8;
#endif
#ifndef UINT16
typedef unsigned short UINT16;
#endif
#ifndef UINT32
typedef unsigned long UINT32;
#endif
#ifndef UINT64
typedef unsigned long long UINT64;
#endif
#ifndef UINT8V
typedef unsigned char volatile UINT8V;
#endif
#ifndef UINT16V
typedef unsigned short volatile UINT16V;
#endif
#ifndef UINT32V
typedef unsigned long volatile UINT32V;
#endif
#ifndef UINT64V
typedef unsigned long long volatile UINT64V;
#endif

#ifndef PVOID
typedef void *PVOID;
#endif
#ifndef PCHAR
typedef char *PCHAR;
#endif
#ifndef PCHAR
typedef const char *PCCHAR;
#endif
#ifndef PINT8
typedef char *PINT8;
#endif
#ifndef PINT16
typedef short *PINT16;
#endif
#ifndef PINT32
typedef long *PINT32;
#endif
#ifndef PUINT8
typedef unsigned char *PUINT8;
#endif
#ifndef PUINT16
typedef unsigned short *PUINT16;
#endif
#ifndef PUINT32
typedef unsigned long *PUINT32;
#endif
#ifndef PUINT8V
typedef volatile unsigned char *PUINT8V;
#endif
#ifndef PUINT16V
typedef volatile unsigned short *PUINT16V;
#endif
#ifndef PUINT32V
typedef volatile unsigned long *PUINT32V;
#endif
#ifndef PUINT64V
typedef volatile unsigned long long *PUINT64V;
#endif

/* ********************************************************************************************************************* */
/* Base macros */

#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif
#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifdef DEBUG
#define PRINT(X...) printf(X)
#else
#define PRINT(X...)
#endif

/* Calculate the byte offset of a field in a structure of type */
#define FIELD_OFFSET(Type, Field) ((UINT16) & (((Type *)0)->Field))

/* Calculate the size of a field in a structure of type */
#define FIELD_SIZE(Type, Field) (sizeof(((Type *)0)->Field))

/* An expression that yields the type of a field in a struct */
#define FIELD_TYPE(Type, Field) (((Type *)0)->Field)

/* Return the number of elements in a statically sized array */
#define NUMBER_OF(Array) (sizeof(Array) / sizeof((Array)[0]))
#define NUMBER_OF_FIELD(Type, Field) (NUMBER_OF(FIELD_TYPE(Type, Field)))

#ifdef __cplusplus
}
#endif

#endif // __BASE_TYPE__

#ifndef __CORE_SFR_H__
#define __CORE_SFR_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* ********************************************************************************************************************* */
// Address Space
//    ROM        :   1A00_0000 - 1A01_0000   4  KB
//    DATA_CACHE :   1C00_0000 - 1C01_FFFF   128KB
//    INSTR_CACHE:   1C02_0000 - 1C03_FFFF   128KB
//    SHARE_CACHE:   1C04_0000 - 1C04_7FFF   32 KB //udma 
//    SFR        :   1A10_0000 - 1A11_FFFF
//
//    SFR        :   1A10_0000 - 1A11_FFFF
//      GPIO     :    +0000H - 03FF
//      PWM      :   0x1a100400 - 0x1a100430
//      timer    :   0x1A107000 - 0x1a107FFF
// Register Bit Attribute / Bit Access Type
//   RF:    Read only for Fixed value
//   RO:    Read Only (internal change)
//   RZ:    Read only with auto clear Zero
//   WO:    Write Only (read zero or different)
//   WA:    Write only under safe Accessing mode (read zero or different)
//   WZ:    Write only with auto clear Zero
//   RW:    Read / Write
//   RWA:   Read / Write under safe Accessing mode
//   RW1:   Read / Write 1 to Clear
/* Register name rule:
   R32_* for 32 bits register (UINT32,ULONG)
   R16_* for 16 bits register (UINT16,USHORT)
   R8_*  for  8 bits register (UINT8,UCHAR)
   RB_*  for bit or bit mask of 8 bit register
   BA_*  for base address point
   b*    for GPIO bit mask
   Others for register address offset */
/* ********************************************************************************************************************* */

#define R32_SOC_EU_EVENT     (*((volatile uint32_t *)0x1a102000))
#define R32_SOC_FC_MASK_MSB  (*((volatile uint32_t *)0x1a102004))
#define R32_SOC_FC_MASK_LSB  (*((volatile uint32_t *)0x1a102008))
#define R32_SOC_ERR_MSB      (*((volatile uint32_t *)0x1a10201c))
#define R32_SOC_ERR_LSB      (*((volatile uint32_t *)0x1a102020))
#define R32_SOC_TIMER_SEL_HI (*((volatile uint32_t *)0x1a102024))
#define R32_SOC_TIMER_SEL_LO (*((volatile uint32_t *)0x1a102028))

#define Interrupt_ADDR        0x1a105000
#define ITC_MASK              (*((volatile uint32_t *)0x1a105000))
#define ITC_MASK_SET          (*((volatile uint32_t *)0x1a105004))
#define ITC_MASK_CLR          (*((volatile uint32_t *)0x1a105008))
#define ITC                   (*((volatile uint32_t *)0x1a10500c))
#define ITC_SET               (*((volatile uint32_t *)0x1a105010))
#define ITC_CLR               (*((volatile uint32_t *)0x1a105014))
#define ITC_ACK               (*((volatile uint32_t *)0x1a105018))
#define ITC_ACK_SET           (*((volatile uint32_t *)0x1a10501c))
#define ITC_ACK_CLR           (*((volatile uint32_t *)0x1a105020))
#define ITC_FIFO              (*((volatile uint32_t *)0x1a105024))

#define R32_info (*((PUINT8V)0x1a101000)) //mcu and clusters info
#define R32_boot_addr (*((PUINT32V)0x1a101004)) //程序启动地址配置寄存器
#define R32_fect (*((PUINT8V)0x1a101008)) //取指使能 1使能
#define PAD_FUN0 (*((PUINT32V)0x1a101010)) // RW, Config fun for pad0 to pad 15
#define PAD_FUN1 (*((PUINT32V)0x1a101014)) // RW, Config fun for pad16 to pad 18
#define R32_mbist_cfg (*((PUINT8V)0x1a101080))    //
#define R32_mbist_status (*((PUINT8V)0x1a101084)) //
#define R32_sensor_id (*((PUINT8V)0x1a101088))    //
#define R32_spim_cfg (*((PUINT8V)0x1a10108c))     //cfg[1]=d2d_wp cdf[0]=d2p_hold
#define R32_ram_clkgate_en (*((PUINT8V)0x1a1090)) //
#define R32_ip_clkgate_en (*((PUINT8V)0x1a1094)) //
#define R32_core_status (*((PUINT8V)0x1a1010a0))    //core状态寄存器 程序运行完毕返回值0x8000—0000
#define R32_core_rstn (*((PUINT8V)0x1a1010cc)) //软件复位 cfg[0]=core reset cfg[1]=udmareset. cfg[3]=mbis reset

#define R8_CMD0 (*((volatile uint8_t *)0x1a100800)) // 配置PD 、PDMCK PLBYP 、PLL_ITVCO 默认分别为0、0、0、0010
#define R8_CMD1 (*((volatile uint8_t *)0x1a100804)) // 配置PLL_RC 、PLL_PLCC，默认位1、 01000
#define R8_CMD2 (*((volatile uint8_t *)0x1a100808)) // 配置PLM,默认7'b0111110
#define R8_CMD3 (*((volatile uint8_t *)0x1a10080c)) // 配置PLN,默认6'b001010
#define R8_CMD4 (*((volatile uint8_t *)0x1a100810)) // 配置PLL_Test_en、PLL_RSTB、PLLR，默认分别为'b0,'b1,'b1000
#define R8_CMD5 (*((volatile uint8_t *)0x1a100814)) // BGR_TRIM 默认'b100， ICELL_TRIM,默认5‘b01000
#define R8_CMD6 (*((volatile uint8_t *)0x1a100818)) // LDO18_EN,默认1‘b0,DAC12_EN 默认1’b0,SARADC_PD ，默认1'b1 , D2A_ADC_Chanelsel 默认1‘b0
#define R8_ADC_CLK (*((volatile uint8_t *)0x1a10081c)) // ADC_CLK_12M 默认为1
#define R8_CMD8 (*((volatile uint8_t *)0x1a100820)) // DAC12_SEL[7:0]=8'b00000001
#define R8_CMD9 (*((volatile uint8_t *)0x1a100824)) // DAC12_SEL[11:8]=4'b0000
#define R8_CMD10_ADC (*((volatile uint8_t *)0x1a100828)) // get adc value
#define R8_CMD11 (*((volatile uint8_t *)0x1a10082c))     // eeror 1'b0

/* Udma controler & share cache*/
#define I2C_data_byte 3
#define Uart_data_byte 1
#define R8_I2C_RX_data (*((PUINT8V)0x1c040000))//允许最多一次256字节
#define R8_I2C_TX_data (*((PUINT8V)0x1c040100)) // 允许最多一次256字节

#define R8_uart_tx_data (*((PUINT8V)(0x1c040200)))//允许最多一次256字节
#define R8_uart_rx_data (*((PUINT8V)(0x1c040300)))//允许最多一次256字节

#define R8_i2s_tx_data (*((PUINT8V)(0x1c040400))) // 允许最多一次256字节
#define R8_i2s_rx_data (*((PUINT8V)(0x1c040500))) // 允许最多一次256字节

#define R8_spi_tx_data (*((PUINT8V)(0x1c040600))) // 允许最多一次256字节
#define R8_spi_rx_data (*((PUINT8V)(0x1c040700))) // 允许最多一次256字节

/* GPIO register */

#define R32_P_DIR       (*((PUINT32V)0x1A100000)) // RW, GPIO  I/O direction: 0=in, 1=out
#define R32_P_PIN       (*((PUINT32V)0x1A100004)) // RO, GPIO input when use it , need enable gpio
#define R32_P_POUT      (*((PUINT32V)0x1A100008)) // RW, GPIO output
#define R32_P_INTEN     (*((PUINT32V)0x1A10000C)) // RO, GPIO enable int
#define R32_P_INTTYPE   (*((PUINT32V)0x1A100010)) // RW, GPIO int type
#define R32_P_INTSTATUS (*((PUINT32V)0x1A100018)) // RW, GPIO if bit[i]=1 soc can clear flag
#define R32_P_PEN       (*((PUINT32V)0x1A10001C)) // RW, GPIO enable gpio 
#define R32_P_CLR       (*((PUINT32V)0x1A100040)) // WZ, GPIO clear output: 0=keep, 1=clear
#define R32_P_PSET      (*((PUINT32V)0x1A100044)) // RW, GPIO  pullup resistance enable


/*PWM register*/
/* PWM0/1/2/3/4/5/6/7 register */
#define R8_PWM_EN          (*((PUINT8V)0x1a100400))           // RW, PWM output enable control

#define R32_PWM0_CONFIG (*((PUINT32V)0x1a100404))                // RW, PWM configuration
#define R32_PWM1_CONFIG (*((PUINT32V)0x1a100408))                     // RW, PWM configuration
#define R32_PWM2_CONFIG (*((PUINT32V)0x1a10040c))                     // RW, PWM configuration
#define R32_PWM3_CONFIG (*((PUINT32V)0x1a100410))                     // RW, PWM configuration
#define R32_PWM4_CONFIG (*((PUINT32V)0x1a100414))                     // RW, PWM configuration
#define R32_PWM5_CONFIG (*((PUINT32V)0x1a100418))                     // RW, PWM configuration
#define R32_PWM6_CONFIG (*((PUINT32V)0x1a10041c))                     // RW, PWM configuration
#define R32_PWM7_CONFIG (*((PUINT32V)0x1a100420))                     // RW, PWM configuration
// #define R32_PWM_CLOCK_DIV (*((PUINT32V)0x1a10042c))                   // RW, PWM clock divisor
#define R32_PWM_CLOCK_DIV (*((PUINT32V)0x1a100430))                   // RW, PWM clock divisor

/*uart 0/1 register*/
#define R32_uart0_rx_addr (*((PUINT32V)0x1A104080))     
#define R32_uart0_rx_size (*((PUINT32V)0x1a104084))     
#define R32_uart0_rx_cfg  (*((PUINT32V)0x1a104088))     
#define R32_uart0_rx_int  (*((PUINT32V)0x1a10408c))     
#define R32_uart0_tx_addr (*((PUINT32V)0x1A104090))     
#define R32_uart0_tx_size (*((PUINT32V)0x1a104094))     
#define R32_uart0_tx_cfg  (*((PUINT32V)0x1a104098))     
#define R32_uart0_tx_int  (*((PUINT32V)0x1a10409c))     
#define R32_uart0_status  (*((PUINT32V)0x1a1040a0))     
#define R32_uart0_setup   (*((PUINT32V)0x1a1040a4))     

#define R32_uart1_rx_addr (*((PUINT32V)0x1A104100))         
#define R32_uart1_rx_size (*((PUINT32V)0x1a104104))         
#define R32_uart1_rx_cfg  (*((PUINT32V)0x1a104108))         
#define R32_uart1_rx_int  (*((PUINT32V)0x1a10410c))         
#define R32_uart1_tx_addr (*((PUINT32V)0x1A104110))         
#define R32_uart1_tx_size (*((PUINT32V)0x1a104114))         
#define R32_uart1_tx_cfg  (*((PUINT32V)0x1a104118))         
#define R32_uart1_tx_int  (*((PUINT32V)0x1a10411c))         
#define R32_uart1_status  (*((PUINT32V)0x1a104120))         
#define R32_uart1_setup   (*((PUINT32V)0x1a104124))         


/*timer register*/
#define R32_timer0_cfg_lo (*((PUINT32V)0x1a107000))
#define R32_timer0_cfg_hi (*((PUINT32V)0x1a107004))
#define R32_timer0_cnt_lo (*((PUINT32V)0x1a107008))
#define R32_timer0_cnt_hi (*((PUINT32V)0x1a10700c))
#define R32_timer0_cmp_lo (*((PUINT32V)0x1a107010))
#define R32_timer0_cmp_hi (*((PUINT32V)0x1a107014))
#define R32_timer0_start_lo (*((PUINT32V)0x1a107018))
#define R32_timer0_start_hi (*((PUINT32V)0x1a10701c))
#define R32_timer0_reset_lo (*((PUINT32V)0x1a107020))
#define R32_timer0_reset_hi (*((PUINT32V)0x1a107024))

#define R32_timer1_cfg_lo   (*((PUINT32V)0x1a107800))
#define R32_timer1_cfg_hi   (*((PUINT32V)0x1a107804))
#define R32_timer1_cnt_lo   (*((PUINT32V)0x1a107808))
#define R32_timer1_cnt_hi   (*((PUINT32V)0x1a10780c))
#define R32_timer1_cmp_lo   (*((PUINT32V)0x1a107810))
#define R32_timer1_cmp_hi   (*((PUINT32V)0x1a107814))
#define R32_timer1_start_lo (*((PUINT32V)0x1a107818))
#define R32_timer1_start_hi (*((PUINT32V)0x1a10781c))
#define R32_timer1_reset_lo (*((PUINT32V)0x1a107820))
#define R32_timer1_reset_hi (*((PUINT32V)0x1a107824))

// LIN addresss
#define Lin_CR (*((PUINT32V)0x1a103800))
#define Lin_CSR (*((PUINT32V)0x1a103804))
#define Lin_IER (*((PUINT32V)0x1a103808))
#define Lin_ISR (*((PUINT32V)0x1a10380c))
#define Lin_ID (*((PUINT32V)0x1a103810))
#define Lin_DATA (*((PUINT32V)0x1a103814))
#define Lin_DIV (*((PUINT32V)0x1a103818))


/*spi 0/1 register*/
#define R32_spi1_rx_addr (*((PUINT32V)0x1A104280))     
#define R32_spi1_rx_size (*((PUINT32V)0x1a104284))     
#define R32_spi1_rx_cfg  (*((PUINT32V)0x1a104288))     

#define R32_spi1_tx_addr (*((PUINT32V)0x1A104290))     
#define R32_spi1_tx_size (*((PUINT32V)0x1a104294))     
#define R32_spi1_tx_cfg  (*((PUINT32V)0x1a104298))     

#define R32_spi2_rx_addr (*((PUINT32V)0x1A104300))         
#define R32_spi2_rx_size (*((PUINT32V)0x1a104304))         
#define R32_spi2_rx_cfg  (*((PUINT32V)0x1a104308))         

#define R32_spi2_tx_addr (*((PUINT32V)0x1A104310))         
#define R32_spi2_tx_size (*((PUINT32V)0x1a104314))         
#define R32_spi2_tx_cfg  (*((PUINT32V)0x1a104318))         


// ================================================================
// ================================================================

// 结构体指针定义寻址寄存器
/*SOC GPIO PERIPHERALS*/
// #define PERI_GPIO_ADDR 0x1A101000
#define RV_PERI_GPIO_ADDR 0x1A100000
    // gpio共 18个 寄存器单元
    typedef struct
    {
        __IO u32 pad_dir;       // 0x00
        __IO u32 pad_in;        // 0x04
        __IO u32 pad_out;       // 0x08
        __IO u32 pad_inten;     // 0x0c
        __IO u32 pad_inttype0;  // 0x10
        __IO u32 pad_inttype1;  // 0x14
        __IO u32 pad_intstatus; // 0x18
        __IO u32 pad_gpioen;    // 0x1c

        __IO u32 pad_cfg0; // 0x20
        __IO u32 pad_cfg1; // 0x24
        __IO u32 pad_cfg2; // 0x28
        __IO u32 pad_cfg3; // 0x2c
        __IO u32 pad_cfg4; // 0x30
        __IO u32 pad_cfg5; // 0x34
        __IO u32 pad_cfg6; // 0x38
        __IO u32 pad_cfg7; // 0x3c

        __IO unsigned int pad_outset; // 0x40
        __IO unsigned int pad_outclr; // 0x44 
} RV_GPIO_t;

#define pad_gpio ((RV_GPIO_t *)RV_PERI_GPIO_ADDR)
// ================================================================
/*SOC PWM PERIPHERALS*/
#define RV_PERI_PWM_ADDR 0x1a100400
    // gpio共 18个 寄存器单元
    typedef struct
    {
        __IO u32 pad_pwm_en;       // 0x00
        __IO u32 pad_pwm_cfg0;        // 0x04
        __IO u32 pad_pwm_cfg1;        // 0x08
        __IO u32 pad_pwm_cfg2;        // 0x0c
        __IO u32 pad_pwm_cfg3;        // 0x10
        __IO u32 pad_pwm_cfg4;        // 0x14
        __IO u32 pad_pwm_cfg5;        // 0x18
        __IO u32 pad_pwm_cfg6;        // 0x1c

        __IO u32 pad_pwm_cfg7;     // 0x20
         u32 pad_pwm_reserve1; // 0x24
         u32 pad_pwm_reserve2; // 0x28
         u32 pad_pwm_reserve3; // 0x2c
        __IO u32 pad_pwm_div; // 0x30

    } RV_PWM_t;

#define pad_pwm ((RV_PWM_t *)RV_PERI_PWM_ADDR)

// ================================================================
#define RV_PERI_TIMER0_ADDR 0x1A107000 // 定时器寄存器基地址
#define RV_PERI_TIMER1_ADDR 0x1A107800 // 定时器寄存器基地址
    typedef struct
    {
        __IO u32 cfg_lo;               // 0x00 配置寄存器
        __IO u32 cfg_hi;               // 0x04 配置寄存器
        __IO u32 cnt_lo;               // 0x08 计数值寄存器
        __IO u32 cnt_hi;               // 0x0c 计数值寄存器
        __IO u32 cmp_lo;               // 0x10 比较值寄存器
        __IO u32 cmp_hi;               // 0x14 比较值寄存器
        __IO u32 start_lo;             // 0x18 启动定时器寄存器
        __IO u32 start_hi;             // 0x1c 启动定时器寄存器
        __IO u32 reset_lo;             // 0x20 复位定时器寄存器
        __IO u32 reset_hi;             // 0x24 复位定时器寄存器
    } RV_timer_t;

#define pad_timer0 ((RV_timer_t *)RV_PERI_TIMER0_ADDR) // 获取定时器寄存器
#define pad_timer1 ((RV_timer_t *)RV_PERI_TIMER1_ADDR) // 获取定时器寄存器

// ================================================================
#define RV_Udma_CMD_ADDR    0x1C040000
// #define RV_Udma_I2C_RX_ADDR 0x1c040000 // can not over 0x1c04_7FFF ,32KB
#define RV_Udma_I2C_DATA_ADDR 0x1c040100 // can not over 0x1c04_7FFF ,32KB

#define RV_Udma_uart_RX_ADDR 0x1c040300 // can not over 0x1c04_7FFF ,32KB
#define RV_Udma_uart_TX_ADDR 0x1c040200 // can not over 0x1c04_7FFF ,32KB
#define RV_Udma_i2s_RX_ADDR 0x1c040500 // can not over 0x1c04_7FFF ,32KB
#define RV_Udma_i2s_TX_ADDR 0x1c040400 // can not over 0x1c04_7FFF ,32KB
#define RV_Udma_SPI_DATA_ADDR 0x1c041000 // can not over 0x1c04_7FFF ,32KB
#define RV_Udma_spi_TX_ADDR 0x1c040600 // can not over 0x1c04_7FFF ,32KB

    typedef struct
    {
        __IO u8 cmd[32];
    } udma_cmd_t;
    /**
     * @brief udam control
     *
     */
    typedef struct
    {
        __IO u8 cmd[7];
        __IO u8 i2c_data[256-1];
    } udma_i2c_data_t;
    /**
     * @brief udam control
     *
     */
    typedef struct
    {
        __IO u8 uart_data_reg[256-1];
    } udma_uart_data_t;

    /**
     * @brief udam control
     *
     */
    typedef struct
    {   
        __IO u32 spi_data[256-1];
    } udma_spi_data_t;

    /**
     * @brief udam control
     *
     */
    typedef struct
    {
        __IO u32 spi_cmd[7];
    } udma_spi_cmd_t;

#define udma_i2c_data ((udma_i2c_data_t *)RV_Udma_I2C_DATA_ADDR) //
#define udma_i2c_cmd ((udma_cmd_t *)RV_Udma_CMD_ADDR)            //
#define udma_spi_cmd ((udma_spi_cmd_t *)RV_Udma_CMD_ADDR)
#define udma_rx_ptr3 ((udma_uart_data_t *)RV_Udma_uart_RX_ADDR) //
#define udma_tx_ptr4 ((udma_uart_data_t *)RV_Udma_uart_TX_ADDR) //
#define udma_spi_data ((udma_spi_data_t *)RV_Udma_SPI_DATA_ADDR) //

// ================================================================
#define RV_PERI_Uart0_ADDR 0x1A104080
#define RV_PERI_Uart1_ADDR 0x1A104100

/**
 * @brief uart struct
 *
*/
typedef struct 
{
    __IO u32 pad_rx_addr;//0x00 接收起始地址 低12位有效
    __IO u32 pad_rx_size;//0x04 接收字节长度 低16为有效
    __IO u32 pad_rx_cfg; //0x08 cfg[4]=udma启动位
     u32 pad_rx_int_reserve;//0x0c 保留

    __IO u32 pad_tx_addr;//同rx
    __IO u32 pad_tx_size;
    __IO u32 pad_tx_cfg;
     u32 pad_tx_int_reserve;//0x1c 保留

    __IO u32 pad_uart_status;//0x20
    __IO u32 pad_uart_setup; // 0x24
    __IO u8 pad_uart_tx_data_reg[Uart_data_byte-1];//为了数据连贯性在次数设置数据
    __IO u8 pad_uart_rx_data_reg[Uart_data_byte - 1];
    // 0x24 setup[31:16]配置波特率 [9]rx使能 [8]tx使能 [3]stopbit-仅对tx有用
}RV_uart_t;
#define pad_uart0 ((RV_uart_t)*RV_PERI_Uart0_ADDR)//
#define pad_uart1 ((RV_uart_t)*RV_PERI_Uart1_ADDR) //


// ================================================================
#define RV_PERI_I2C0_ADDR 0x1A104180
#define RV_PERI_I2C1_ADDR 0x1A104200
/**
 * @brief i2c struct def
*/
typedef struct 
{
    __IO u32 i2c_rx_addr ;//0x00
    __IO u32 i2c_rx_szie;//0x04
    __IO u32 i2c_rx_cfg ;//0x08
    u32  i2c_rx_reserve ;//0x0c
    __IO u32 i2c_tx_addr;//0x10
    __IO u32 i2c_tx_szie;//0x14
    __IO u32 i2c_tx_cfg;//0x18
    u32  i2c_tx_reserve;//0x1c
    __IO u32 i2c_status;//0x20
    __IO u32 i2c_setup;//0x24
}RV_i2c_t;

#define pad_i2c0 ((RV_i2c_t *)RV_PERI_I2C0_ADDR)
#define pad_i2c1 ((RV_i2c_t *)RV_PERI_I2C1_ADDR)
// ================================================================

#define RV_PERI_SPI1_ADDR 0x1A104280
#define RV_PERI_SPI2_ADDR 0x1A104300
#define RV_PERI_SPI1_TX_ADDR (RV_PERI_SPI1_ADDR+0x10)
#define RV_PERI_SPI2_TX_ADDR (RV_PERI_SPI2_ADDR+0x10)
/**
 * @brief i2c struct def
 */
typedef struct
{
    __IO u32 spi_rx_addr; // 0x00
    __IO u32 spi_rx_szie; // 0x04
    __IO u32 spi_rx_cfg;  // 0x08
    u32 spi_rx_reserve;   // 0x0c
    __IO u32 spi_tx_addr; // 0x10
    __IO u32 spi_tx_szie; // 0x14
    __IO u32 spi_tx_cfg;  // 0x18
    u32 spi_tx_reserve;   // 0x1c
} RV_spi_t;

#define pad_spi0 ((RV_spi_t *)RV_PERI_SPI0_ADDR)
#define pad_spi1 ((RV_spi_t *)RV_PERI_SPI1_ADDR)
    // ================================================================

#ifdef __cplusplus
}
#endif

#endif // 