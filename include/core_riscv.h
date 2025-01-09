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
    

/* ##########################   define  #################################### */
#define __nop() __asm__ volatile("nop")

#ifdef __cplusplus
}
#endif

#endif /* __CORE_RV3A_H__ */
