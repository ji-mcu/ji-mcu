/** ---------------------------------File Info-------------------------------- 
 ** @file:               soc_common.h                                        
 ** @author:             黄锦  											     “,
 ** @contact			 3056830955@qq.com                                      
 ** @date:               2024-07-30            
 ** @version:            V0.0                                                  
 ** @brief:              all periph common define 
 **                      
 **--------------------------------------------------------------------------- 
 ** @modified:                                                               
 ** @date:               2024-07-30            
 ** @version:            V0.0                                                  
 ** @description:        all periph common define 
 ** @note:               
 ** @copyright:          
 **--------------------------------------------------------------------------- */


#ifndef __SOC_COMMON_H__
#define __SOC_COMMON_H__

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef NULL
#define NULL 0
#endif
#define ALL 0xFFFF

#define Debug_UART0 0
#define Debug_UART1 1
#define Debug_UART2 2
#define Debug_UART3 3

#ifdef DEBUG
#include <stdio.h>
#endif

/**
 * @brief  系统主频时钟（Hz）
 */
#ifndef FREQ_SYS
#define FREQ_SYS 64000000
#endif

/**
 * @brief  32K时钟（Hz）
 */
// #ifdef CLK_OSC24K
// #if (CLK_OSC32K == 1)
// #define CAB_LSIFQ 32000
// #else
// #define CAB_LSIFQ 32768
// #endif
// #else
// #define CAB_LSIFQ 32000
// #endif

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "hal/pulp_io.h"
#include "core_riscv.h"
#include "core_SFR.h"
#include "core_sys.h"
#include "soc_event.h"
#include "IC_gpio.h"
#include "IC_PWM.h"
#include "IC_i2c.h"
#include "IC_uart.h"
#include "IC_RCC.h"
#include "IC_timer.h"
#include "soc_printf.h"

#define DelayMs(x) mDelaymS(x)
#define DelayUs(x) mDelayuS(x)

#define SOC_RST         0x1a1010cc
#define SOC_Fetchen     0x1a101008
#define SOC_boot_addr   0x1a101004

#define SET_BIT(REG, BIT) ((REG) |= (BIT))

#ifdef __cplusplus
}
#endif

#endif