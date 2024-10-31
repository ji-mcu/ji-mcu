/********************************** (C) COPYRIGHT *******************************
 * File Name          : IC_timer.h
 * Author             : huang jin
 * Version            : V0.1
 * Date               : 2024/10/28
 * Description
 *********************************************************************************

 *******************************************************************************/

#ifndef __IC_TIMER_H__
#define __IC_TIMER_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <string.h>
#include <stdint.h>
#include "hal/pulp_io.h"
#include "core_riscv.h"
#include "core_SFR.h"
#include "core_sys.h"
#include "soc_event.h"

#define timer0_ok
#define timer1_ok

#ifdef timer0_ok

typedef struct 
{
    uint32_t     Clock_Mux;
    uint32_t     TIME_Mode;
    uint32_t TIME_INTEN;
    // uint8_t     TIME_ContinuousEN;
    // uint8_t     TIME_once_EN;
    uint32_t    TIME_OutputClock;
    uint32_t    TIME_CNT;
    uint32_t    TIME_CMP;
    uint32_t     TIME_Reset;
    uint32_t     TIME_Start;
} TIM_InitTypeDef;

typedef enum
{
    cfg_lo = 0,
    cfg_hi = !cfg_lo
} CFG_Selcet;

/**
 * @brief  TMR cfg register define
 */
#define ENABLE_BIT              (uint32_t)1<<0 //bit0
#define RESET_BIT               (uint32_t)1<<1//bit1 
#define IRQ_BIT                 (uint32_t)1<<2//bit 2
#define CMP_CLR_BIT             (uint32_t)1<<4// bit 4 
#define ONE_SHOT_BIT            (uint32_t)1<<5//bit 5
#define PRESCALER_EN_BIT        (uint32_t)1<<6//bit 6
#define REF_CLK_EN_BIT          (uint32_t)1<<7//bit 7
#define PRESCALER_START_BIT     (uint32_t)1<<8// bit8
#define PRESCALER_STOP_BIT      (uint32_t)1<<15// bit 15
#define MODE_64_BIT             (uint32_t)1<<31//bit31
// CFG
#define TIME_START_0 ((uint32_t)0x00)
#define TIM_START_1  ((uint32_t)0x01)

#define TIME_INTEN_0 ((uint32_t)0x00)
#define TIME_INTEN_1 ((uint32_t)0x04)
#define IRQ_TIMER 1


/**
 * @brief   获取当前timer lo定时器值，最大4294967295
 *
 * @return  当前定时器值
 */
#define TMR0_GetCurrentTimerlo() R32_timer0_cnt_lo

/**
 * @brief   获取当前timer hi定时器值，最大4294967295
 *
 * @return  当前定时器值
 */
#define TMR0_GetCurrentTimerhi() R32_timer0_cnt_hi

/**
 * @brief   关闭 TMR0-lo
 */
#define TMR0_Disablelo() (R32_timer0_cfg_lo &= ~TIM_START_1)

/**
 * @brief   开启 TMR0-lo
 */
#define TMR0_Enablelo() (R32_timer0_cfg_lo |= TIM_START_1)

/**
 * @brief   中断配置 Timer lo
 *
 */
#define TMR0_ITEnablelo() (R32_timer0_cfg_lo &= ~TIME_INTEN_1)

/**
 * @brief   中断配置 Timer lo
 *
 */
#define TMR0_ITDisablelo() (R32_timer0_cfg_lo |= TIME_INTEN_1)


/**
 * @brief   关闭 TMR0-hi
 */
#define TMR0_Disablehi() (R32_timer0_cfg_hi &= ~TIM_START_1)

/**
 * @brief   开启 TMR0-hi
 */
#define TMR0_Enablehi() (R32_timer0_cfg_hi |= TIM_START_1)

/**
 * @brief   中断配置 Timer hi
 *
 */
#define TMR0_ITEnablehi() (R32_timer0_cfg_hi &= ~TIME_INTEN_1)

/**
 * @brief   中断配置 Timer hi
 *
 */
#define TMR0_ITDisablehi() (R32_timer0_cfg_hi |= TIME_INTEN_1)

/**
 * @brief   清除中断标志
 *
 * @param   f       - refer to TMR interrupt bit define
 */
// #define TMR0_ClearITFlag(f) (R8_TMR0_INT_FLAG = f)

/**
 * @brief   查询中断标志状态
 *
 * @param   f       - refer to TMR interrupt bit define
 */
// #define TMR0_GetITFlag(f) (R8_TMR0_INT_FLAG & f)


//==========================================================================//
//==========================================================================//
/**
 * @brief   定时功能初始化
 *
 * @param   t       - 定时时间，基于当前系统时钟Tsys, 最长定时周期
 */
void TMR_TimerInit(TIM_InitTypeDef *TIM_InitStruct, CFG_Selcet cfg_selct);

// void TMR0_StructInit(Timer_InitTypeDef *Timer_InitStruct);

void TIM_StructInit(TIM_InitTypeDef *TIMER_InitStruct);
// void TIM_Init(TIM_InitTypeDef *TIM_InitStruct);

// void TIM_Cmd_lo(FunctionalState NewState);
// void TIM_Cmd_hi(FunctionalState NewState);

void TIM_ITConfig(FunctionalState NewState);

void TIM_SetCounter(uint32_t Counter, CFG_Selcet cfg_selct);

uint32_t TIM_GetCounter(CFG_Selcet cfg_selct);

void TIM_SetCompare(uint32_t Compare, CFG_Selcet cfg_selct);
uint32_t TIM_GetCompare( CFG_Selcet cfg_selct);

FlagStatus TIM_GetITStatus(uint32_t TIM_FLAG);
void TIM_ClearIT(uint32_t TIM_FLAG);


#endif
#ifdef __cplusplus
}
#endif

#endif // __CH57x_TIMER_H__
