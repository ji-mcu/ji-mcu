/********************************** (C) COPYRIGHT *******************************
 * File Name          : CH57x_timer.h
 * Author             : WCH
 * Version            : V1.2
 * Date               : 2021/11/17
 * Description
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#ifndef __IC_TIMER_H__
#define __IC_TIMER_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "soc_common.h"
#ifdef timer_ok

    /**
     * @brief  TMR cfg register define
     */
#define ENABLE_BIT              0x00 //unused
#define RESET_BIT               0x02 //bit1 
#define IRQ_BIT                 0x04 //bit 2
#define CMP_CLR_BIT             0x08 // bit 4 
#define ONE_SHOT_BIT            0x10 //bit 5
#define PRESCALER_EN_BIT        0x20 //bit 6
#define REF_CLK_EN_BIT          0x40 //bit 7
#define PRESCALER_START_BIT     0x80 // bit8
#define PRESCALER_STOP_BIT      0x8000//bit 15
#define MODE_64_BIT             0x800000//bit31


/**
 * @brief   定时功能初始化
 *
 * @param   t       - 定时时间，基于当前系统时钟Tsys, 最长定时周期 67108864
 */
void TMR0_TimerInit(uint32_t t);

/**
 * @brief   获取当前定时器值，最大67108864
 *
 * @return  当前定时器值
 */
#define TMR0_GetCurrentTimer() R32_TMR0_COUNT


/**
 * @brief   设置计数统计溢出大小，最大67108862
 *
 * @param   cyc     - 计数统计溢出大小
 */
#define TMR0_CountOverflowCfg(cyc) (R32_TMR0_CNT_END = (cyc + 2))

/**
 * @brief   获取当前计数值，最大67108862
 *
 * @return  当前计数值
 */
#define TMR0_GetCurrentCount() R32_TMR0_COUNT




/**
 * @brief   关闭 TMR0
 */
#define TMR0_Disable() (R8_TMR0_CTRL_MOD &= ~RB_TMR_COUNT_EN)

/**
 * @brief   开启 TMR0
 */
#define TMR0_Enable() (R8_TMR0_CTRL_MOD |= RB_TMR_COUNT_EN)

/**
 * @brief   中断配置
 *
 * @param   s       - 使能/关闭
 * @param   f       - refer to TMR interrupt bit define
 */
#define TMR0_ITCfg(s, f) ((s) ? (R8_TMR0_INTER_EN |= f) : (R8_TMR0_INTER_EN &= ~f))

/**
 * @brief   清除中断标志
 *
 * @param   f       - refer to TMR interrupt bit define
 */
#define TMR0_ClearITFlag(f) (R8_TMR0_INT_FLAG = f)

/**
 * @brief   查询中断标志状态
 *
 * @param   f       - refer to TMR interrupt bit define
 */
#define TMR0_GetITFlag(f) (R8_TMR0_INT_FLAG & f)

// CFG
#define TIM_INT_FLAG 0x100
#define TIM_PERIODIC_FLAG 0x04
// #define TIM_INT_EN     		0x02
#define TIM_START 0x01

#define IRQ_TIMER 1

    typedef struct
    {
        uint32_t Clock_Freq;

        uint32_t TIME_CMP; /* This member configures the UART communication baud rate.
                                   The baud rate is computed using the following formula:
                                   - IntegerDivider = ((PCLKx) / (16 * (UART_InitStruct->UART_BaudRate)))*/

        uint32_t TIME_STP; /* Specifies uart clock freq*/

        uint32_t TIME_CNT;

        uint32_t TIME_PERIODIC; /* Specifies the number of data bits transmitted or received in a frame.
                                        This parameter can be a value of @ref UART_Word_Length */

        uint32_t TIME_INTEN; /* Specifies the number of stop bits transmitted.
                                  This parameter can be a value of @ref UART_Stop_Bits */

        uint32_t TIME_START; /* Specifies the parity mode whether Enable or disable */

    } TIM_InitTypeDef;

#define IS_TIM_CLOCK(CLOCK) (((CLOCK) == TIM_CLOCK_8M) || ((CLOCK) == TIM_CLOCK_11M))
#define IS_TIM_ALL_PERIPH(PERIPH) ((PERIPH) == TIMER)

#define TIME_START_0 ((uint32_t)0x00)
#define TIME_START_1 ((uint32_t)0x01)
#define IS_TIM_START(TIME_START) (((TIME_START) == TIME_START_0) || \
                                  ((TIME_START) == TIME_START_1))

#define TIME_INTEN_0 ((uint32_t)0x00)
#define TIME_INTEN_1 ((uint32_t)0x02)
#define IS_TIM_INTEN(TIME_INTEN) (((TIME_INTEN) == TIME_INTEN_0) || \
                                  ((TIME_INTEN) == TIME_INTEN_1))

#define TIME_PERIODIC_0 ((uint32_t)0x00)
#define TIME_PERIODIC_1 ((uint32_t)0x04)
#define IS_TIM_PERIODIC(TIME_PERIODIC) (((TIME_PERIODIC) == TIME_PERIODIC_0) || \
                                        ((TIME_PERIODIC) == TIME_PERIODIC_1))

#define TIM_FLAG_INT ((uint32_t)0x0100)
#define TIM_FLAG_Trigger ((uint32_t)0x0100)
#define IS_TIM_GET_FLAG(FLAG) ((FLAG) == TIM_FLAG_INT)

#define IS_TIM_CLEAR_FLAG(FLAG) ((FLAG) == TIM_FLAG_INT)

    void TIM_StructInit(TIM_InitTypeDef *TIMER_InitStruct);
    void TIM_Init(TIM_InitTypeDef *TIM_InitStruct);

    void TIM_Cmd(FunctionalState NewState);
    void TIM_ITConfig(FunctionalState NewState);
    void TIM_SetCounter(uint32_t Counter);
    uint32_t TIM_GetCounter(void);
    void TIM_SetCompare(uint32_t Compare);
    uint32_t TIM_GetCompare(void);

    FlagStatus TIM_GetITStatus(uint32_t TIM_FLAG);
    void TIM_ClearIT(uint32_t TIM_FLAG);
#endif
#ifdef __cplusplus
}
#endif

#endif // __CH57x_TIMER_H__
