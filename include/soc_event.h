/* Define for ji-mcu              */
/* Email:    3056830955@qq.com    */
/* Author:   huangjin 2024/7/4   */
/* V0.1 SOC Event and Interrupt */

#ifndef __H_SOC_EVENT__
#define __H_SOC_EVENT__

#include "soc_common.h"

#define PFIC ((PFIC_Type *)0xE000E000)
#define NVIC PFIC
#define NVIC_KEY1 ((uint32_t)0xFA050000)
#define NVIC_KEY2 ((uint32_t)0xBCAF0000)
#define NVIC_KEY3 ((uint32_t)0xBEEF0000)

#define SysTick ((SysTick_Type *)0xE000F000)



/* Interrupt Number Definition, according to the selected device */
typedef enum IRQn
{
    /******  RISC-V Processor Exceptions Numbers *******************************************************/
    NonMaskableInt_IRQn = 2, /* 2 Non Maskable Interrupt                             */

    /******  RISC-V specific Interrupt Numbers *********************************************************/
    WWDG_IRQn = 16, /* Window WatchDog Interrupt                            */
    PVD_IRQn = 17,  /* PVD through EXTI Line detection Interrupt            */
    s_timer_lo_event = 10,
    s_timer_hi_event = 11,

    s_ref_rise_fall_evnt = 14,
    s_gpio_event = 15,
    periph_event = 26,
    s_fc_err_events = 30 

} IRQn_Type;

/* memory mapped structure for Program Fast Interrupt Controller (PFIC) */
typedef struct
{
    __I uint32_t ISR[8];
    __I uint32_t IPR[8];
    __IO uint32_t ITHRESDR;
    __IO uint32_t RESERVED;
    __IO uint32_t CFGR;
    __I uint32_t GISR;
    __IO uint8_t VTFIDR[4];
    uint8_t RESERVED0[12];
    __IO uint32_t VTFADDR[4];
    uint8_t RESERVED1[0x90];
    __O uint32_t IENR[8];
    uint8_t RESERVED2[0x60];
    __O uint32_t IRER[8];
    uint8_t RESERVED3[0x60];
    __O uint32_t IPSR[8];
    uint8_t RESERVED4[0x60];
    __O uint32_t IPRR[8];
    uint8_t RESERVED5[0x60];
    __IO uint32_t IACTR[8];
    uint8_t RESERVED6[0xE0];
    __IO uint8_t IPRIOR[256];
    uint8_t RESERVED7[0x810];
    __IO uint32_t SCTLR;
} PFIC_Type;

/* memory mapped structure for SysTick */
// typedef struct
// {
//     __IO u32 CTLR;
//     __IO u32 SR;
//     __IO u64 CNT;
//     __IO u64 CMP;
// } SysTick_Type;

#define PFIC ((PFIC_Type *)0xE000E000)
#define NVIC PFIC
#define NVIC_KEY1 ((uint32_t)0xFA050000)
#define NVIC_KEY2 ((uint32_t)0xBCAF0000)
#define NVIC_KEY3 ((uint32_t)0xBEEF0000)


#define SysTick ((SysTick_Type *)0xE000F000)

/*********************************************************************
 * @fn      __enable_irq
 *
 * @brief   Enable Global Interrupt
 *
 * @return  none
 */
RV_STATIC_INLINE void __enable_irq()
{
    __asm volatile("csrw 0x800, %0" : : "r"(0x6088));
}

/*********************************************************************
 * @fn      __disable_irq
 *
 * @brief   Disable Global Interrupt
 *
 * @return  none
 */
RV_STATIC_INLINE void __disable_irq()
{
    __asm volatile("csrw 0x800, %0" : : "r"(0x6000));
}

/*********************************************************************
 * @fn      __NOP
 *
 * @brief   nop
 *
 * @return  none
 */
RV_STATIC_INLINE void __NOP()
{
    __asm volatile("nop");
}

/*********************************************************************
 * @fn       NVIC_EnableIRQ
 *
 * @brief   Disable Interrupt
 *
 * @param   IRQn - Interrupt Numbers
 *
 * @return  none
 */
RV_STATIC_INLINE void NVIC_EnableIRQ(IRQn_Type IRQn)
{
    NVIC->IENR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

/*********************************************************************
 * @fn       NVIC_DisableIRQ
 *
 * @brief   Disable Interrupt
 *
 * @param   IRQn - Interrupt Numbers
 *
 * @return  none
 */
RV_STATIC_INLINE void NVIC_DisableIRQ(IRQn_Type IRQn)
{
    NVIC->IRER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

/*********************************************************************
 * @fn       NVIC_GetStatusIRQ
 *
 * @brief   Get Interrupt Enable State
 *
 * @param   IRQn - Interrupt Numbers
 *
 * @return  1 - 1: Interrupt Pending Enable
 *                0 - Interrupt Pending Disable
 */
RV_STATIC_INLINE uint32_t NVIC_GetStatusIRQ(IRQn_Type IRQn)
{
    return ((uint32_t)((NVIC->ISR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F))) ? 1 : 0));
}

/*********************************************************************
 * @fn      NVIC_GetPendingIRQ
 *
 * @brief   Get Interrupt Pending State
 *
 * @param   IRQn - Interrupt Numbers
 *
 * @return  1 - 1: Interrupt Pending Enable
 *                0 - Interrupt Pending Disable
 */
RV_STATIC_INLINE uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
    return ((uint32_t)((NVIC->IPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F))) ? 1 : 0));
}

/*********************************************************************
 * @fn      NVIC_SetPendingIRQ
 *
 * @brief   Set Interrupt Pending
 *
 * @param   IRQn - Interrupt Numbers
 *
 * @return  none
 */
RV_STATIC_INLINE void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
    NVIC->IPSR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

/*********************************************************************
 * @fn      NVIC_ClearPendingIRQ
 *
 * @brief   Clear Interrupt Pending
 *
 * @param   IRQn - Interrupt Numbers
 *
 * @return  none
 */
RV_STATIC_INLINE void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
    NVIC->IPRR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

/*********************************************************************
 * @fn      NVIC_GetActive
 *
 * @brief   Get Interrupt Active State
 *
 * @param   IRQn - Interrupt Numbers
 *
 * @return  1 - Interrupt Active
 *                0 - Interrupt No Active
 */
RV_STATIC_INLINE uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
    return ((uint32_t)((NVIC->IACTR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F))) ? 1 : 0));
}

/*********************************************************************
 * @fn      NVIC_SetPriority
 *
 * @brief   Set Interrupt Priority
 *
 * @param   IRQn - Interrupt Numbers
 *                  priority: bit7 - pre-emption priority
 *                  bit6-bit4 - subpriority
 *
 * @return  none
 */
RV_STATIC_INLINE void NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority)
{
    NVIC->IPRIOR[(uint32_t)(IRQn)] = priority;
}

/*********************************************************************
 * @fn       __WFI
 *
 * @brief   Wait for Interrupt
 *
 * @return  none
 */
// __attribute__((always_inline)) RV_STATIC_INLINE void __WFI(void)
// {
//     NVIC->SCTLR &= ~(1 << 3); // wfi
//     asm volatile("wfi");
// }

/*********************************************************************
 * @fn       __WFE
 *
 * @brief   Wait for Events
 *
 * @return  none
 */
__attribute__((always_inline)) RV_STATIC_INLINE void __WFE(void)
{
    uint32_t t;

    t = NVIC->SCTLR;
    NVIC->SCTLR |= (1 << 3) | (1 << 5); // (wfi->wfe)+(__sev)
    NVIC->SCTLR = (NVIC->SCTLR & ~(1 << 5)) | (t & (1 << 5));
    asm volatile("wfi");
    asm volatile("wfi");
}

/*********************************************************************
 * @fn      SetVTFIRQ
 *
 * @brief   Set VTF Interrupt
 *
 * @param   addr - VTF interrupt service function base address.
 *                  IRQn - Interrupt Numbers
 *                  num - VTF Interrupt Numbers
 *                  NewState -  DISABLE or ENABLE
 *
 * @return  none
 */
RV_STATIC_INLINE void SetVTFIRQ(uint32_t addr, IRQn_Type IRQn, uint8_t num, FunctionalState NewState)
{
    if (num > 3)
        return;

    if (NewState != DISABLE)
    {
        NVIC->VTFIDR[num] = IRQn;
        NVIC->VTFADDR[num] = ((addr & 0xFFFFFFFE) | 0x1);
    }
    else
    {
        NVIC->VTFIDR[num] = IRQn;
        NVIC->VTFADDR[num] = ((addr & 0xFFFFFFFE) & (~0x1));
    }
}

/*********************************************************************
 * @fn       NVIC_SystemReset
 *
 * @brief   Initiate a system reset request
 *
 * @return  none
 */
RV_STATIC_INLINE void NVIC_SystemReset(void)
{
    NVIC->CFGR = NVIC_KEY3 | (1 << 7);
}

#endif
