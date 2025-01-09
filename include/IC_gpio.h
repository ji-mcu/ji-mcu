/** ---------------------------------File Info-------------------------------- 
 ** @file:               IC_gpio.h                                        
 ** @author:             黄锦  											     “,
 ** @contact			 3056830955@qq.com                                      
 ** @date:               2024-07-30            
 ** @version:            V0.0                                                  
 ** @brief:              技大mcu的gpio基础驱动库函数
 **                      
 **--------------------------------------------------------------------------- 
 ** @modified:                                                               
 ** @date:               2024-07-30            
 ** @version:            V0.0                                                  
 ** @description:        技大mcu的gpio基础驱动库函数
 ** @note:       
 ** @copyright:               
 **--------------------------------------------------------------------------- */

#ifndef __ARCHI_PULPISSIMO_MEMORY_MAP_IC_GPIO_H__
#define __ARCHI_PULPISSIMO_MEMORY_MAP_IC_GPIO_H__

#include "core_riscv.h"
#include "core_SFR.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "hal/pulp_io.h"


/**
 * @brief	GPIO_pins_define
 */
#define GPIO_Pin_0   (0x00000001)   /*!< Pin 0 selected */
#define GPIO_Pin_1   (0x00000002)   /*!< Pin 1 selected */
#define GPIO_Pin_2   (0x00000004)   /*!< Pin 2 selected */
#define GPIO_Pin_3   (0x00000008)   /*!< Pin 3 selected */
#define GPIO_Pin_4   (0x00000010)   /*!< Pin 4 selected */
#define GPIO_Pin_5   (0x00000020)   /*!< Pin 5 selected */
#define GPIO_Pin_6   (0x00000040)   /*!< Pin 6 selected */
#define GPIO_Pin_7   (0x00000080)   /*!< Pin 7 selected */
#define GPIO_Pin_8   (0x00000100)   /*!< Pin 8 selected */
#define GPIO_Pin_9   (0x00000200)   /*!< Pin 9 selected */
#define GPIO_Pin_10  (0x00000400)  /*!< Pin 10 selected */
#define GPIO_Pin_11  (0x00000800)  /*!< Pin 11 selected */
#define GPIO_Pin_12  (0x00001000)  /*!< Pin 12 selected */
#define GPIO_Pin_13  (0x00002000)  /*!< Pin 13 selected */
#define GPIO_Pin_14  (0x00004000)  /*!< Pin 14 selected */
#define GPIO_Pin_15  (0x00008000)  /*!< Pin 15 selected */
#define GPIO_Pin_16  (0x00010000)  /*!< Pin 16 selected */
#define GPIO_Pin_17  (0x00020000)  /*!< Pin 17 selected */
#define GPIO_Pin_18  (0x00040000)  /*!< Pin 18 selected */

#define GPIO_Pin_All (0x000FFFFF) /*!< All pins selected */

// reg0 0x1a101010  for pin0 to pin 15
// ================================================================

//default function
// #define PWM0            
// #define PWM1
// #define PWM2
// #define PWM3
// #define UART0_RX
// #define UART0_TX
// #define CAN0_RX
// #define CAN0_TX
// #define LIN0_RX
// #define LIN0_TX
// #define I2C0_SCL
// #define I2C0_SDA
// #define SPI1_SCLK
// #define SPI1_CS
// #define SPI1_MOSI
// #define SPI1_MISO



//pad_mux = 'b10='d2 
// #define FUN_GPIO0       (uint32_t)1<<1
// #define FUN_GPIO1       (uint32_t)1<<3
// #define FUN_GPIO2       (uint32_t)1<<5
// #define FUN_GPIO3       (uint32_t)1<<7
// #define FUN_GPIO4       (uint32_t)1<<9
// #define FUN_GPIO5       (uint32_t)1<<11
// #define FUN_GPIO6       (uint32_t)1<<13
// #define FUN_GPIO7       (uint32_t)1<<15
// #define FUN_GPIO8       (uint32_t)1<<17
// #define FUN_GPIO9       (uint32_t)1<<19
// #define FUN_GPIO10       (uint32_t)1<<21
// #define FUN_GPIO11       (uint32_t)1<<23
// #define FUN_GPIO12       (uint32_t)1<<25
// #define FUN_GPIO13       (uint32_t)1<<27
// #define FUN_GPIO14       (uint32_t)1<<29
// #define FUN_GPIO15       (uint32_t)1<<31

// pad_mux = 2'b01=2'd1
// #define I2C1_SCL        (uint32_t)1<<0
// #define I2C1_SDA        (uint32_t)1<<2
// #define LIN1_RX         (uint32_t)1<<4
// #define LIN1_TX         (uint32_t)1<<6
// #define CAN1_RX         (uint32_t)1<<8
// #define CAN1_TX         (uint32_t)1<<10
// #define UART1_RX        (uint32_t)1<<12
// #define UART1_TX        (uint32_t)1<<14
// #define SPI2_CS	        (uint32_t)1<<16
// #define SPI2_SCLK       (uint32_t)1<<18
// #define SPI2_MOSI       (uint32_t)1<<20
// #define SPI2_MISO	    (uint32_t)1<<22
// #define I2S1_SCK	    (uint32_t)1<<24
// #define I2S1_WS	        (uint32_t)1<<26
// #define I2S1_SDI	    (uint32_t)1<<28
// #define PWM4	        (uint32_t)1<<30



//reg1 0x1a101014 for pin16 to pin18 
// ================================================================
// #define FUN_GPIO16       (uint32_t)1<<1
// #define FUN_GPIO17       (uint32_t)1<<3
// #define FUN_GPIO18       (uint32_t)1<<5

// #define PWM5       (uint32_t)1<<0
// #define PWM6       (uint32_t)1<<2
// #define PWM7       (uint32_t)1<<4

// #define I2S0_SCK
// #define I2S0_WS
// #define I2S0_SDI

/**
 * Configuration PAD Fun ,pad0-16
*/
typedef enum
{
    FUN_GPIO0 = (uint32_t)1<<1,
    FUN_GPIO1 = (uint32_t)1<<3,
    FUN_GPIO2 = (uint32_t)1<<5,
    FUN_GPIO3 = (uint32_t)1<<7,
    FUN_GPIO4 = (uint32_t)1<<9,
    FUN_GPIO5 = (uint32_t)1<<11,
    FUN_GPIO6 = (uint32_t)1<<13,
    FUN_GPIO7 = (uint32_t)1<<15,
    FUN_GPIO8 = (uint32_t)1<<17,
    FUN_GPIO9 = (uint32_t)1<<19,
    FUN_GPIO10=  (uint32_t)1<<21,
    FUN_GPIO11=  (uint32_t)1<<23,
    FUN_GPIO12=  (uint32_t)1<<25,
    FUN_GPIO13=  (uint32_t)1<<27,
    FUN_GPIO14=  (uint32_t)1<<29,
    FUN_GPIO15=  (uint32_t)1<<31,
    FUN_I2C1_SCL  = (uint32_t)1<<0,
    FUN_I2C1_SDA  = (uint32_t)1<<2,
    FUN_LIN1_RX   = (uint32_t)1<<4,
    FUN_LIN1_TX   = (uint32_t)1<<6,
    FUN_CAN1_RX   = (uint32_t)1<<8,
    FUN_CAN1_TX   = (uint32_t)1<<10,
    FUN_UART1_RX  = (uint32_t)1<<12,
    FUN_UART1_TX  = (uint32_t)1<<14,
    FUN_SPI2_CS	  = (uint32_t)1<<16,
    FUN_SPI2_SCLK = (uint32_t)1<<18,
    FUN_SPI2_MOSI = (uint32_t)1<<20,
    FUN_SPI2_MISO= (uint32_t)1<<22,
    FUN_I2S1_SCK= (uint32_t)1<<24,
    FUN_I2S1_WS	  = (uint32_t)1<<26,
    FUN_I2S1_SDI= (uint32_t)1<<28,
    FUN_PWM4	  = (uint32_t)1<<30

}PADFunTypeDef0;


/**
 * Configuration PAD1 Fun pad 16-18
*/
typedef enum
{
    FUN_GPIO16 =(uint32_t)1 << 1,
    FUN_GPIO17 =(uint32_t)1 << 3,
    FUN_GPIO18 =(uint32_t)1 << 5 ,
    FUN_PWM5 =(uint32_t)1 << 0,
    FUN_PWM6 =(uint32_t)1 << 2,
    FUN_PWM7 =(uint32_t)1 << 4
} PADFunTypeDef1;
/**
 * @brief  Configuration GPIO Mode
 */
typedef enum
{
    GPIO_ModeIN , // 浮空输入
    GPIO_ModeOut, // 输出
} GPIOModeTypeDef;

/**
 * @brief  Configuration GPIO IT Mode
 */
typedef enum
{
    GPIO_ITMode_doubleEdge,  // 双边沿触发
    GPIO_ITMode_FallEdge,  // 下降沿触发
    GPIO_ITMode_RiseEdge,  // 上升沿触发

} GPIOITModeTpDef;

/**
 * @brief config pad_mux fun output for pad0 to pad15
 * @param PADFun 
 */
uint8_t PAD_MUX_FUN0(PADFunTypeDef0 PADFun , FunctionalState Newstate);

/**
 * @brief config pad_mux fun output for pad16 to pad18
 * @param PADFun
 */
uint8_t PAD_MUX_FUN1(PADFunTypeDef1 PADFun, FunctionalState Newstate);

/**
 * @brief   pPAD引脚配置输出功能
 *
 * @param   FUN
 * @param   mode    - 输入输出类型
 */
void GPIOA_ModeCfg(uint32_t pin, GPIOModeTypeDef mode);

/**
 * @brief   GPIO端口引脚模式配置
 *
 * @param   pin     - P0-PA18
 * @param   mode    - 输入输出类型
 */
void GPIOA_ModeCfg(uint32_t pin, GPIOModeTypeDef mode);


/**
 * @brief   GPIO端口引脚输出置低
 *
 * @param   pin     - PA0-PA18
 */
#define GPIOA_SetBits(pin) (R32_P_CLR |= pin)

/**
 * @brief   GPIO端口引脚输出置高
 *
 * @param   pin     - P0-P18
 */
#define GPIOA_ResetBits(pin) (R32_P_PSET |= pin)


/**
 * @brief   GPIO端口32位数据返回，低19位有效
 *
 * @return  GPIO端口32位数据
 */
#define GPIOA_ReadPort() (R32_P_PIN)

/**
 * @brief   GPIO端口引脚状态，0-引脚低电平，(!0)-引脚高电平
 *
 * @param   pin     - P0-P15
 *
 * @return  GPIO端口引脚状态
 */
#define GPIOA_ReadPortPin(pin) (R32_P_PIN & (pin))

/**
 * @brief   GPIO引脚中断模式配置
 *
 * @param   pin     - P0-P18
 * @param   mode    - 触发类型
 */
void GPIOA_ITModeCfg(uint32_t pin, GPIOITModeTpDef mode);

/**
 * @brief   读取GPIO端口中断标志状态
 *
 * @return  GPIO端口中断标志状态
 */
#define GPIOA_ReadITFlagPort() (R32_P_INTSTATUS)

/**
 * @brief   读取GPIO端口引脚中断标志状态
 *
 * @param   pin     - P0-P18
 *
 * @return  GPIO端口引脚中断标志状态
 */
#define GPIOA_ReadITFlagBit(pin) (R32_P_INTSTATUS & (pin))

/**
 * @brief   清除GPIO端口引脚中断标志状态
 *
 * @param   pin     - PA0-PA15
 */
#define GPIOA_ClearITFlagBit(pin) (R32_P_INTSTATUS = pin)

/**
 * @brief   外设功能引脚映射
 *
 * @param   s       - 是否使能映射
 * @param   perph   - RB_PIN_SPI0   -  SPI0:  PA12/PA13/PA14/PA15 -> PB12/PB13/PB14/PB15
 *                    RB_PIN_UART1  -  UART1: PA8/PA9 ->  PB12/PB13
 *                    RB_PIN_UART0  -  UART0: PB4/PB7 ->  PA15/PA14
 *                    RB_PIN_TMR2   -  TMR2:  PA11 ->  PB11
 *                    RB_PIN_TMR1   -  TMR1:  PA10 ->  PB10
 *                    RB_PIN_TMR0   -  TMR0:  PA9 ->  PB23
 */
void GPIOPinRemap(FunctionalState s, uint16_t perph);

/**
 * @brief   模拟外设GPIO引脚功能控制
 *
 * @param   s       - 是否启用模拟外设功能
 * @param   perph   - RB_PIN_ADC0_1_IE      -  ADC0-1通道
 *                    RB_PIN_XT32K_IE       -  外部32K引脚
 *                    RB_PIN_USB_IE         -  USB功能信号引脚
 */
void GPIOAGPPCfg(FunctionalState s, uint16_t perph);

#endif

   

 
 