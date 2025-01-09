/********************************** (C) COPYRIGHT *******************************
 * File Name          : SYS.h
 * Author             : huangjin
 * Version            : V0.0
 * Date               : 2021/11/17
 * Description        : ctrl sys_clock and wdg and delay function
 *********************************************************************************

 *******************************************************************************/

#ifndef __SYS_H__
#define __SYS_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "hal/pulp_io.h"
#include "core_riscv.h"
#include "core_SFR.h"

#define     D2A_DAC12_EN    2 
#define     D2A_DAC12_SEL_1   (uint16_t)0x00ff
#define     D2A_DAC12_SEL_2   (uint16_t)0x0f00
#define     D2A_PLL_ITVCO   (uint8_t)0xf
#define     D2A_PLL_PD      (uint8_t)1<<6
#define     D2A_PLL_PDMCK   (uint8_t)1<<5
#define     D2A_PLL_PLBYP   (uint8_t)1<<4
#define     D2A_PLL_PLCC    (uint8_t)0xf
#define     D2A_PLL_PLLR    (uint8_t)0x1f
#define     D2A_PLL_PLLRC   (uint8_t)1<<4
#define     D2A_PLL_PLM     (uint8_t)0x7f
#define     D2A_PLL_PLN     (uint8_t)0x3f
#define     D2A_PLL_RSTB    (uint8_t)1<<5
#define     D2A_PLL_TESTEN  (uint8_t)1<<6
#define     D2A_ICELL_TRIM  (uint8_t)0x1f
#define     D2A_BGR_TRIM    (uint8_t)0xe0
// #define     D2A_ADCCLK_12M  (uint8_t)0xff
#define     D2A_ADC_CHANELSEL   0
#define     D2A_SARADC_PD       1//adc的时钟使能，默认为1
#define     D2A_LDO18_ENB   (uint8_t)1<<3
// #define     A2D_ADC_EOC     (uint8_t)1<<
// #define     A2D_ADOUT

#define SOC_RST         0x1a1010cc
#define SOC_Fetchen     0x1a101008
#define SOC_boot_addr   0x1a101004

#define SET_BIT(REG, BIT) ((REG) |= (BIT))
    typedef enum
    {
        TIM_CLOCK_1M = 1000000,
        TIM_CLOCK_8M = 8000000,
        TIM_CLOCK_10M = 10000000,
        TIM_CLOCK_11M = 11000000,
        TIM_CLOCK_16M = 16000000,
        TIM_CLOCK_24M = 24000000,
        TIM_CLOCK_32M = 32000000,
        TIM_CLOCK_48M = 48000000,
        TIM_CLOCK_64M = 64000000,

    } TIMClock_TypeDef;

    /**
     * @brief  rtc interrupt event define
     */
    typedef enum
    {
        RST_STATUS_SW = 0, // 软件复位
        RST_STATUS_RPOR,   // 上电复位
        RST_STATUS_WTR,    // 看门狗超时复位
        RST_STATUS_MR,     // 外部手动复位
        RST_STATUS_LRM0,   // 唤醒复位-软复位引起
        RST_STATUS_GPWSM,  // 下电模式唤醒复位
        RST_STATUS_LRM1,   //	唤醒复位-看门狗引起
        RST_STATUS_LRM2,   //	唤醒复位-手动复位引起

    } SYS_ResetStaTypeDef;

    /**
     * @brief  rtc interrupt event define
     */
    typedef enum
    {
        n_cores , 
        n_clusters , 
    } SYS_InfoStaTypeDef;

#define soc_boorctrl(boot_addr) (R32_boot_addr = boot_addr)


/**
 * @brief   配置系统运行时钟
 *
 * @param   sc      - 系统时钟源选择 refer to SYS_CLKTypeDef
 */
void SetSysClock(TIMClock_TypeDef sysfreq);
/**
 * @brief   获取当前系统时钟
 *
 * @return  Hz
 */
uint32_t GetSysClock(void);
/**
 * @brief   获取当前系统信息状态
 *
 * @param   i       - refer to SYS_InfoStaTypeDef
 *
 * @return  是否开启
 */
uint32_t SYS_GetInfoSta(SYS_InfoStaTypeDef info);

/**
 * @brief   执行系统软件复位
 */
void SYS_ResetExecute(void);

/**
 * @brief   
 */
void SystemInit(void);

/**
 * @brief   关闭所有中断，并保留当前中断值
 *
 * @param   pirqv   - 当前保留中断值
 */
void SYS_DisableAllIrq(uint32_t *pirqv);

/**
 * @brief   恢复之前关闭的中断值
 *
 * @param   irq_status  - 当前保留中断值
 */
void SYS_RecoverIrq(uint32_t irq_status);

    /**
     * @brief   获取当前系统(SYSTICK)计数值
     *
     * @return  当前计数值
     */
    uint32_t SYS_GetSysTickCnt(void);

/**
 * @brief   加载看门狗计数初值，递增型
 *
 * @param   c       - 看门狗计数初值
 */
#define WWDG_SetCounter(c) (R8_WDOG_COUNT = c)

    /**
     * @brief   看门狗定时器溢出中断使能
     *
     * @param   s       - 溢出是否中断
     */
    void WWDG_ITCfg(FunctionalState s);

    /**
     * @brief   看门狗定时器复位功能
     *
     * @param   s       - 溢出是否复位
     */
    void WWDG_ResetCfg(FunctionalState s);

/**
 * @brief   获取当前看门狗定时器溢出标志
 *
 * @return  看门狗定时器溢出标志
 */
#define WWDG_GetFlowFlag() (R8_RST_WDOG_CTRL & RB_WDOG_INT_FLAG)

    /**
     * @brief   清除看门狗中断标志，重新加载计数值也可清除
     */
    void WWDG_ClearFlag(void);

    /**
     * @brief   uS 延时
     *
     * @param   t       - 时间参数
     */
    void mDelayuS(uint16_t t);

    /**
     * @brief   mS 延时
     *
     * @param   t       - 时间参数
     */
    void mDelaymS(int32_t t);

    // /**
    //  * @brief 进入安全访问模式.
    //  *
    //  * @NOTE: 进入安全访问模式后约16个系统主频周期都处于安全模式下，
    //  * 该有效期内可以改写一个或多个安全类寄存器，超出上述有效期后将自动终止安全模式。
    //  */
    // __attribute__((always_inline)) static inline void sys_safe_access_enable(void)
    // {
    //     R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG1;
    //     R8_SAFE_ACCESS_SIG = SAFE_ACCESS_SIG2;
    // }

    // __attribute__((always_inline)) static inline void sys_safe_access_disable(void)
    // {
    //     R8_SAFE_ACCESS_SIG = 0;
    // }

#ifdef __cplusplus
}
#endif

#endif // __SYS_H__
