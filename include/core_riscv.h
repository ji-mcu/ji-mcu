/********************************** (C) COPYRIGHT  *******************************
 * File Name          : core_riscv.h
 * Author             : WCH
 * Version            : V1.0.1
 * Date               : 2021/10/28
 * Description        : CH573 RISC-V Core Peripheral Access Layer Header File
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/
#ifndef __CORE_RV3A_H__
#define __CORE_RV3A_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"

/* IO definitions */
#ifdef __cplusplus
#define __I volatile /*!< defines 'read only' permissions      */
#else
#define __I volatile const /*!< defines 'read only' permissions     */
#endif
#define __IOM volatile
#define __O volatile  /*!< defines 'write only' permissions     */
#define __IO volatile /*!< defines 'read / write' permissions   */
#define RV_STATIC_INLINE static inline

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

    // typedef enum {SUCCESS = 0, ERROR = !SUCCESS} ErrorStatus;

    typedef enum
    {
        DISABLE = 0,
        ENABLE = !DISABLE
    } FunctionalState;

    typedef enum
    {
        READ = 0,
        WRITE = 1,
        Continuous=2
    } Function;

    typedef enum
    {
        RESET = 0,
        SET = !RESET
    } FlagStatus,
        ITStatus;

    typedef enum
    {
        NoREADY = 0,
        READY = !NoREADY
    } ErrorStatus;
    
    /* memory mapped structure for Program Fast Interrupt Controller (PFIC) */
    // typedef struct
    // {
    //     __I uint32_t ISR[8];
    //     __I uint32_t IPR[8];
    //     __IO uint32_t ITHRESDR;
    //     __IO uint32_t FIBADDRR;
    //     __IO uint32_t CFGR;
    //     __I uint32_t GISR;
    //     uint8_t RESERVED0[0x10];
    //     __IO uint32_t FIOFADDRR[4];
    //     uint8_t RESERVED1[0x90];
    //     __O uint32_t IENR[8];
    //     uint8_t RESERVED2[0x60];
    //     __O uint32_t IRER[8];
    //     uint8_t RESERVED3[0x60];
    //     __O uint32_t IPSR[8];
    //     uint8_t RESERVED4[0x60];
    //     __O uint32_t IPRR[8];
    //     uint8_t RESERVED5[0x60];
    //     __IO uint32_t IACTR[8];
    //     uint8_t RESERVED6[0xE0];
    //     __IO uint8_t IPRIOR[256];
    //     uint8_t RESERVED7[0x810];
    //     __IO uint32_t SCTLR;
    // } PFIC_Type;

    /* memory mapped structure for SysTick */
    typedef struct __attribute__((packed))
    {
        __IO uint32_t CTLR;
        __IO uint64_t CNT;
        __IO uint64_t CMP;
        __IO uint32_t CNTFG;
    } SysTick_Type;

#define PFIC ((PFIC_Type *)0xE000E000)
#define SysTick ((SysTick_Type *)0xE000F000)

#define PFIC_KEY1 ((uint32_t)0xFA050000)
#define PFIC_KEY2 ((uint32_t)0xBCAF0000)
#define PFIC_KEY3 ((uint32_t)0xBEEF0000)

/* ##########################   define  #################################### */
#define __nop() __asm__ volatile("nop")

    /*********************************************************************
     * @fn       __WFI
     *
     * @brief   Wait for Interrupt
     *
     * @return  none
     */
    // __attribute__((always_inline)) 
    RV_STATIC_INLINE void __WFI(void)
    {
        // NVIC->SCTLR &= ~(1 << 3); // wfi
        asm volatile("wfi");
    }

#ifdef __cplusplus
}
#endif

#endif /* __CORE_RV3A_H__ */
