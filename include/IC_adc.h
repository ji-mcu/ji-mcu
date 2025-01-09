/********************************** (C) COPYRIGHT *******************************
 * File Name          : IC_adc.h
 * Author             : haungjin
 * Version            : V0.1
 * Date               : 2024/12/8
 * Description
 *******************************************************************************/

#ifndef __IC_ADC__H__
#define __IC_ADC__H__

#ifdef __cplusplus
extern "C" {
#endif

// #include "soc_common.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "hal/pulp_io.h"
#include "core_riscv.h"
#include "core_SFR.h"


/**
 * @brief  adc single channel define
 */
typedef enum
{
    CH_EXTIN_0 = 0,   // ADC 外部模拟通道 0
    CH_EXTIN_1,       // ADC 外部模拟通道 1

} ADC_SingleChannelTypeDef;

/**
 * @brief  adc differential channel define
 */
typedef enum
{
    CH_DIFF_0_2 = 0, // ADC 差分通道 #0-#2
    CH_DIFF_1_3,     // ADC 差分通道 #1-#3

} ADC_DiffChannelTypeDef;

/**
 * @brief  Configuration DMA mode
 */
typedef enum
{
    ADC_Mode_Single = 0, // 单次模式
    ADC_Mode_LOOP,       // 循环模式
} ADC_DMAModeTypeDef;


/**
 * @brief   设置 ADC 采样通道
 *
 * @param   0:默认通道0
 *          1：
 */
#define ADC_Channel0(d) (R8_CMD6 = ((R8_CMD6 & ~(1UL << D2A_ADC_CHANELSEL)) | (d ? (1UL << D2A_ADC_CHANELSEL) : 0)))


/**
 * @brief   设置 ADC 时钟
 *
 * @param   d   - form 1-255,defult is 1
 */
#define ADC_SampClkCfg(d) (R8_ADC_CLK = d)

/**
 * @brief   设置 ADC 时钟使能 
 *
 * @param  1:close ; 0 :open
 */
#define ADC_SampClk_EN(d) (R8_CMD6 = ((R8_CMD6 & ~(1UL << D2A_SARADC_PD)) | (d ? (1UL << D2A_SARADC_PD) : 0)))


/**
 * @brief   外部信号单通道采样初始化
 *
 * @param   sp  - refer to ADC_SampClkTypeDef
 * @param   ga  - refer to ADC_SignalPGATypeDef
 */
void ADC_ExtSingleChSampInit(uint8_t sp );

/**
 * @brief   外部信号差分通道采样初始化
 *
 * @param   sp  - refer to ADC_SampClkTypeDef
 * @param   ga  - refer to ADC_SignalPGATypeDef
 */
void ADC_ExtDiffChSampInit(uint8_t sp);

/**
 * @brief   ADC执行单次转换
 *
 * @return  ADC转换后的数据
 */
uint16_t ADC_ExcutSingleConver(void);


/**
 * @brief   配置DMA功能
 *
 * @param   s           - 是否打开DMA功能
 * @param   startAddr   - DMA 起始地址
 * @param   endAddr     - DMA 结束地址
 */
void ADC_DMACfg(uint8_t s, uint32_t startAddr,uint32_t data_len);


/**
 * @brief   获取ADC转换值
 *
 * @return  ADC转换值
 */
#define ADC_ReadConverValue()     (R16_ADC_DATA)

/**
 * @brief   ADC执行单次转换
 */
#define ADC_StartUp()             (R8_ADC_CONVERT = RB_ADC_START)

/**
 * @brief   获取ADC中断状态
 */
#define ADC_GetITStatus()         (R8_ADC_INT_FLAG & RB_ADC_IF_EOC)

/**
 * @brief   清除ADC中断标志
 */
#define ADC_ClearITFlag()         (R8_ADC_CONVERT = 0)

/**
 * @brief   获取ADC DMA完成状态
 */
#define ADC_GetDMAStatus()        (R8_ADC_DMA_IF & RB_ADC_IF_DMA_END)

/**
 * @brief   清除ADC DMA完成标志
 */
#define ADC_ClearDMAFlag()        (R8_ADC_DMA_IF |= RB_ADC_IF_DMA_END)

/**
 * @brief   开启自动连续 ADC
 */
#define ADC_StartDMA()            (R8_ADC_CTRL_DMA |= RB_ADC_AUTO_EN)

/**
 * @brief   停止自动连续 ADC
 */
#define ADC_StopDMA()            (R8_ADC_CTRL_DMA &= ~RB_ADC_AUTO_EN)


#ifdef __cplusplus
}
#endif

#endif  // __IC_ADC_H__	

