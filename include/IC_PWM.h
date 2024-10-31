/********************************** (C) COPYRIGHT *******************************
 * File Name          : pwm.c
 * Author             : huanjin
 * Version            : V0.1
 * Date               : 2024/8/4
 * Description
 *********************************************************************************
 * Copyright (c)
 *******************************************************************************/

#ifndef __IC_PWM_H__
#define __IC_PWM_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief  channel of PWM define
 */
#define CH_PWM0 0x01  // PWM0 通道
#define CH_PWM1 0x02  // PWM1 通道
#define CH_PWM2 0x04  // PWM2 通道
#define CH_PWM3 0x08  // PWM3 通道
#define CH_PWM4 0x10  // PWM4 通道
#define CH_PWM5 0x20  // PWM5 通道
#define CH_PWM6 0x40  // PWM6 通道
#define CH_PWM7 0x80  // PWM7 通道

// /**
//  * @brief  channel of PWM define
//  */
// typedef enum
// {
//     High_Level = 0, // 默认低电平，高电平有效
//     Low_Level,      // 默认高电平，低电平有效
// } PWMX_PolarTypeDef;
/**
 * @brief  Configuration PWM0_7 Cycle size
 */
typedef enum
{
    // PWMX_Cycle_1,      // 1 个PWMX周期---无效 (注释掉的，因为不需要)
    PWMX_Cycle_2=0,  // 2^2个PWMX周期
    PWMX_Cycle_3,  // 2^3PWMX周期
    PWMX_Cycle_4,  // 2^4个PWMX周期
    PWMX_Cycle_5,  // 2^5个PWMX周期
    PWMX_Cycle_6,  // 2^6个PWMX周期
    PWMX_Cycle_7,  // 2^7个PWMX周期
    PWMX_Cycle_8,  // 2^8个PWMX周期
    PWMX_Cycle_9,  // 2^9个PWMX周期
    PWMX_Cycle_10, // 2^10个PWMX周期
    PWMX_Cycle_11, // 2^11个PWMX周期
    PWMX_Cycle_12, // 2^12个PWMX周期
    PWMX_Cycle_13, // 2^13个PWMX周期
    PWMX_Cycle_14, // 2^14个PWMX周期
    PWMX_Cycle_15, // 2^15个PWMX周期
    PWMX_Cycle_16  // 2^16 个PWMX周期
} PWMX_CycleTypeDef;

static uint16_t PWMX_cycle_table[16] = {
    4 , 8 , 16 , 32 , 64 , 128 ,
    256 , 512 , 1024 , 2048 , 4096 , 8192 ,
    16384 , 32768 , 65535 };
/**
 * @brief   PWM0-PWM7 通道基准时钟配置
 *
 * @param   d   - 通道基准时钟 = 2*(d+1)*Tsys，或者 Fpwm=Fsys/（（d+1）*2）
 * form 1 to 255 
 */
#define PWMX_CLKCfg(d) (R32_PWM_CLOCK_DIV = d)

    /**
     * @brief   PWM0-PWM7基准时钟配置
     *
     * @param   cyc - refer to PWMX_CycleTypeDef
     */
    uint16_t PWMX_CycleCfg(PWMX_CycleTypeDef cyc);

/**
 * @brief 配置PWM通道使能
 * @param ch select channel 
*/
#define PWM_ENABLE(ch) (R8_PWM_EN &= ~(ch))
/**
 * @brief 配置PWM通道使能
 * @param ch select channel
 */
#define PWM_DISNABLE(ch) (R8_PWM_EN |= (ch))

/**
 * @brief   设置 PWM0 有效数据脉宽
 *
 * @param   d   - 有效数据脉宽
 */
#define PWM0_ActDataWidth(d) (R32_PWM0_CONFIG |= (uint16_t)PWMX_cycle_table[d])

/**
 * @brief   设置 PWM1 有效数据脉宽
 *
 * @param   d   - 有效数据脉宽
 */
#define PWM1_ActDataWidth(d) (R32_PWM1_CONFIG |= (uint16_t)PWMX_cycle_table[d])

/**
 * @brief   设置 PWM2 有效数据脉宽
 *
 * @param   d   - 有效数据脉宽
 */
#define PWM2_ActDataWidth(d) (R32_PWM2_CONFIG |= (uint16_t)PWMX_cycle_table[d])

/**
 * @brief   设置 PWM3 有效数据脉宽
 *
 * @param   d   - 有效数据脉宽
 */
#define PWM3_ActDataWidth(d) (R32_PWM3_CONFIG |= (uint16_t)PWMX_cycle_table[d])

/**
 * @brief   设置 PWM4 有效数据脉宽
 *
 * @param   d   - 有效数据脉宽
 */
#define PWM4_ActDataWidth(d) (R32_PWM4_CONFIG |= (uint16_t)PWMX_cycle_table[d])

/**
 * @brief   设置 PWM5 有效数据脉宽
 *
 * @param   d   - 有效数据脉宽
 */
#define PWM5_ActDataWidth(d) (R32_PWM5_CONFIG |= (uint16_t)PWMX_cycle_table[d])

/**
 * @brief   设置 PWM6 有效数据脉宽
 *
 * @param   d   - 有效数据脉宽
 */
#define PWM6_ActDataWidth(d) (R32_PWM6_CONFIG |= (uint16_t)PWMX_cycle_table[d])

/**
 * @brief   设置 PWM7 有效数据脉宽
 *
 * @param   d   - 有效数据脉宽
 */
#define PWM7_ActDataWidth(d) (R32_PWM7_CONFIG |= (uint16_t)PWMX_cycle_table[d])

/*********************************************************************
 * @fn      PWMX_ACTOUT
 *
 * @brief   PWM0-PWM11通道输出波形配置
 *
 * @param   ch      - 输入0-7 选择PWM 通道 0-8
 * @param   lo      - 配置占空比，lo/（hi+1） from 4 to 65536
 * @param   hi      - 配置PWM输频率，Fout=Fpwm/（hi+1）,from 3 to 65535
 * @param   s       - control pwmx function, ENABLE or DISABLE
 *
 * @return  none
 */
void PWMX_ACTOUT(uint8_t ch, uint16_t hi, uint16_t lo, FunctionalState s);

    /*********************************************************************
     * @fn      pwm_steering_engine_init
     *
     * @brief   舵机驱动初始化
     *
     * @param   ch      - 输入0-7 选择PWM 通道 0-8
     * @param   s       - control pwmx function, ENABLE or DISABLE
     *
     * @return  none
     */
    void pwm_steering_engine_init(uint8_t ch, FunctionalState s);

/*********************************************************************
 * @fn      pwm_steering_engine_set
 *
 * @brief   舵机驱动 角度旋转
 *
 * @param   ch      - 输入0-7 选择PWM 通道 0-8
 * @param   angle   - 输入角度 
 *
 * @return  none
 */
void pwm_steering_engine_set(uint8_t ch,int angle) ;
#ifdef __cplusplus
}
#endif

#endif // __CH57x_PWM_H__
