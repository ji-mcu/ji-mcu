/********************************** (C) COPYRIGHT *******************************
 * File Name          : timer0.c
 * Author             : huanjin
 * Version            : V0.1
 * Date               : 2024/9/12
 * Description
 *********************************************************************************
 * Copyright (c)
 *******************************************************************************/

#include "soc_common.h"

#include "IC_timer.h"

#ifdef timer0_ok


/**
 * @brief  Deinitializes the TIMER peripheral registers to their default reset values..
 * @param  TIMx: select the TIMER peripheral.
 *   This parameter can be TIMER.
 * @param  TIM_InitStruct: Timer parameter structure.
 *   This parameter Contains parameters for TIMER initialization.
 * @retval None
 */
void TMR_TimerInit(TIM_InitTypeDef *TIM_InitStruct, CFG_Selcet cfg_selct)
{
    uint32_t temreg = 0;
    uint32_t prescaler=0;


    if(cfg_selct !=cfg_hi){
    // R32_timer0_cfg_hi = 0x00;
    prescaler = TIM_CLOCK_64M/TIM_InitStruct->TIME_OutputClock -1 ;
    temreg |= (TIM_InitStruct->TIME_Mode | prescaler | TIM_InitStruct->TIME_Start | TIM_InitStruct->TIME_Reset) & (TIM_InitStruct->Clock_Mux & TIM_InitStruct->TIME_INTEN);
    R32_timer0_cmp_hi = TIM_InitStruct->TIME_CMP;
    R32_timer0_cnt_hi = TIM_InitStruct->TIME_CNT;
    SET_BIT(R32_timer0_cfg_hi, temreg);

    // if (TIM_InitStruct->TIME_INTEN)
    // {
    //     SET_BIT(INT_EN, IRQ_TIMER);
    // }
    R32_timer0_start_hi = TIM_START_1;
    }
    else{
    // R32_timer0_cfg_lo = 0x00;
    prescaler = TIM_CLOCK_64M / TIM_InitStruct->TIME_OutputClock - 1;
    temreg |= (TIM_InitStruct->TIME_Mode | prescaler | TIM_InitStruct->TIME_Start | TIM_InitStruct->TIME_Reset) & (TIM_InitStruct->Clock_Mux & TIM_InitStruct->TIME_INTEN);
    R32_timer0_cmp_lo = TIM_InitStruct->TIME_CMP;
    R32_timer0_cnt_lo = TIM_InitStruct->TIME_CNT;
    SET_BIT(R32_timer0_cfg_lo, temreg);

    // if (TIM_InitStruct->TIME_INTEN)
    // {
    //     SET_BIT(INT_EN, IRQ_TIMER);
    // }
    R32_timer0_start_lo = TIM_START_1;
    }
}

/**
 * @brief  Fills each TIMER_InitStruct member with its default value.
 * @param  TIM_InitStruct: pointer to a TIM_InitTypeDef structure
 *         which will be initialized.
 * @retval None
 */
void TIM_StructInit(TIM_InitTypeDef *TIM_InitStruct)
{
    /* Set the default configuration */

    TIM_InitStruct->Clock_Mux = (~REF_CLK_EN_BIT); //0:64M 1:10M
    TIM_InitStruct->TIME_Mode = (uint32_t)(CMP_CLR_BIT);    //连续比较功能
    TIM_InitStruct->TIME_INTEN = (~IRQ_BIT);      // 中断使能禁止
    TIM_InitStruct->TIME_OutputClock = (uint32_t)TIM_CLOCK_16M; // 分频系数配置
    TIM_InitStruct->TIME_CNT = (uint32_t)0;                 // 计数器初始值设为0
    TIM_InitStruct->TIME_CMP = (uint32_t)16000;             // 初始值1ms中断触发
    TIM_InitStruct->TIME_Reset = TIME_START_0;
    TIM_InitStruct->TIME_Start =TIM_START_1;
}

void TIM_ITConfig(FunctionalState NewState)
{
    // if (NewState != DISABLE)
    // {
    //     /* Enable the Interrupt sources */
    //     TIMER_CFG |= 0x02;
    //     SET_BIT(INT_EN, IRQ_TIMER);
    // }
    // else
    // {
    //     /* Disable the Interrupt sources */
    //     TIMER_CFG &= 0xFD;
    //     CLEAR_BIT(INT_EN, IRQ_TIMER);
    // }
}

/**
 * @brief  Gets the TIMx Counter value.
 * @param  TIMx: select the TIMER peripheral.
 *   This parameter can be TIMER.
 * @retval Counter Register value.
 */
uint32_t TIM_GetCounter(CFG_Selcet cfg_selct)
{
    uint32_t data = 0;
    if(cfg_selct!=cfg_hi)
        data = R32_timer0_cnt_hi;
    else
        data = R32_timer0_cnt_lo;

    return data;
}

/**
 * @brief  Sets the TIMx Counter Register value
 * @param  TIMx: select the TIMER peripheral.
 *   This parameter can be TIMER.
 * @param  Counter: specifies the Counter register new value.
 * @retval None
 */
void TIM_SetCounter(uint32_t Counter, CFG_Selcet cfg_selct)
{
    if(cfg_selct !=cfg_hi)
        /* Set the Counter Register value */
        R32_timer0_cnt_hi = Counter;
    else
        /* Set the Counter Register value */
        R32_timer0_cnt_lo = Counter;

}

/**
 * @brief  Sets the TIMx Capture Compare Register value
 * @param  TIMx: select the TIMER peripheral.
 *   This parameter can be TIMER.
 * @param  Compare: specifies the Capture Compare register new value.
 * @retval None
 */
void TIM_SetCompare(uint32_t Compare, CFG_Selcet cfg_selct)
{
    /* Set the Capture Compare1 Register value */
    if(cfg_selct !=cfg_hi)
        R32_timer0_cmp_hi = Compare;
    else 
        R32_timer0_cmp_lo =Compare;
}

/**
 * @brief  Gets the TIMx Capture Compare Register value
 * @param  TIMx: select the TIMER peripheral.
 *   This parameter can be TIMER.
 * @retval Compare register value.
 */
uint32_t TIM_GetCompare(CFG_Selcet cfg_selct)
{
    uint32_t data = 0;
    if(cfg_selct != cfg_lo)
        data = R32_timer0_cmp_hi;
    else
        data = R32_timer0_cmp_lo;
    return data;
}

/**
 * @brief  Checks whether the TIM interrupt has occurred or not.
 * @param  TIMx: select the TIMER peripheral.
 *   This parameter can be TIMER.
 * @param  TIM_FLAG: specifies the TIM interrupt source to check.
 *   This parameter can be TIM_FLAG_Trigger
 * @note
 * @retval The new state of the TIM_IT(SET or RESET).
 */
FlagStatus TIM_GetITStatus(uint32_t TIM_FLAG)
{
    // ITStatus bitstatus = RESET;
    // if ((TIMER_CFG & TIM_FLAG) != (uint32_t)RESET)
    // {
    //     bitstatus = SET;
    // }
    // else
    // {
    //     bitstatus = RESET;
    // }
    // return bitstatus;
}
/**
 * @brief  Clears the TIMx's interrupt pending bits.
 * @param  TIMx: select the TIMER peripheral.
 *   This parameter can be TIMER.
 * @param  TIM_FLAG: specifies the TIM interrupt source to check.
 *   This parameter can be  TIM_FLAG_Trigger
 * @retval None
 */
void TIM_ClearIT(uint32_t TIM_FLAG)
{
    /* Clear the flags */
    // TIMER_CFG |= TIM_FLAG;
    // INT_CLR |= IRQ_TIMER;
}
// void TIM_CtrlPWMOutputs(TIM_TypeDef *TIMx, FunctionalState NewState){

// }
#endif