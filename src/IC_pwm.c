/********************************** (C) COPYRIGHT *******************************
 * File Name          : pwm.c
 * Author             : huanjin
 * Version            : V0.1
 * Date               : 2024/8/4
 * Description
 *********************************************************************************
 * Copyright (c) 
 *******************************************************************************/

#include "soc_common.h"

/*********************************************************************
 * @fn      PWMX_CycleCfg
 *
 * @brief   PWM0-PWM7基准时钟配置
 *
 * @param   cyc     - 输入n=2~16 则PWM周期计数为2^n ;
 *
 * @return  uint16 PWM_cfg_cyc from 1-65536
 */

uint16_t PWMX_CycleCfg(PWMX_CycleTypeDef cyc)
{
    uint16_t PWM_cfg_cyc = 0; // PWM周期计数默认为 0 ；
    switch (cyc)
    {
    case PWMX_Cycle_16:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_16];
        break;

    case PWMX_Cycle_15:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_15];
        break;

    case PWMX_Cycle_14:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_14];
        break;

    case PWMX_Cycle_13:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_13];
        break;

    case PWMX_Cycle_12:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_12];
        break;

    case PWMX_Cycle_11:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_11];
        break;

    case PWMX_Cycle_10:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_10];
        break;

    case PWMX_Cycle_9:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_9];
        break;
    case PWMX_Cycle_8:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_8];
        break;
    case PWMX_Cycle_7:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_7];
        break;
    case PWMX_Cycle_6:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_6];
        break;
    case PWMX_Cycle_5:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_5];
        break;
    case PWMX_Cycle_4:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_4];
        break;
    case PWMX_Cycle_3:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_3];
        break;
    case PWMX_Cycle_2:
        PWM_cfg_cyc = PWMX_cycle_table[PWMX_Cycle_2];
        break;

    default:
        break;
    }
    return PWM_cfg_cyc;
}

/*********************************************************************
 * @fn      PWMX_ACTOUT
 *
 * @brief   PWM0-PWM11通道输出波形配置
 *
 * @param   ch      - 输入0-7 选择PWM 通道 0-8
 * @param   da      - effective pulse width
 * @param   pr      - select wave polar, refer to PWMX_PolarTypeDef
 * @param   s       - control pwmx function, ENABLE or DISABLE
 *
 * @return  none
 */
void PWMX_ACTOUT(uint8_t ch, uint16_t hi,uint16_t lo, FunctionalState s)
{
    uint8_t i;

    if (s == DISABLE)
    {
        R8_PWM_EN &= ~(ch);
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            if ((ch >> i) & 1)
            {
                *((volatile uint32_t *)((&R32_PWM0_CONFIG) + i)) |= ((hi-1) << 16 | lo);
            }
        }
        R8_PWM_EN |= (ch);
    }
}


//*****************************************************//
// void PWMX_ACTOUT(uint8_t ch, uint16_t da, FunctionalState s)
// {
//     uint8_t i;

//     RV_PWM_t *p = malloc(sizeof(RV_PWM_t));

//     RV_PWM_t *q = malloc(sizeof(RV_PWM_t));

//     uint32_t *k = &p->pad_pwm_en;
//     for (i = 0; i < 8; i++)
//     {
//         if ((ch >> i) & 1)
//         {

//             *(k + i) = (uint32_t)(i);
//             // k=k+i;
//             printf("i=%d,k=%x,(*k+i)=%d\n", i, k, *(k + i));
//         }
//     }

//     // RV_PWM_t *k = PWMADDR;
//     printf("i=%d,k=%x\n", i, k);
//     RV_PWM_t m;
//     k = &m;
//     // pad_pwm=&m;
//     for (i = 0; i < 8; i++)
//     {
//         if ((ch >> i) & 1)
//         {

//             *(&k->pad_pwm_en + i) = (unsigned int)(i);
//             // k->pad_pwm_en = i;
//             // printf("i=%d\n", i);
//             printf("i=%d,k=%x,(*k+i)=%d\n", i, k, *(k + i));
//         }
//     }

//     q->pad_pwm_en = ch;

//     printf("%x\n", (q->pad_pwm_en));
// }
//**************************************************************//

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
void pwm_steering_engine_init(uint8_t ch, FunctionalState s)
{
    /*
        g_pwm->pad_pwm_cfg0 =  1250;// duty = 1/40 0 degree
        g_pwm->pad_pwm_cfg0 =  2500;// duty = 2/40 45 degree
        g_pwm->pad_pwm_cfg0 =  3750;// duty = 3/40 90 degree
        g_pwm->pad_pwm_cfg0 =  5000;// duty = 4/40 145 degree
        g_pwm->pad_pwm_cfg0 =  6250;// duty = 5/40 180 degree, actually, it turns back to 0 degrees
    */
    uint8_t i;
    uint16_t h_cfg = 50000-1 ;
    uint16_t l_cfg = 1250 ;
    if (s == DISABLE)
    {
        pad_pwm->pad_pwm_en &= ~(ch);
    }
    else
    {
        pad_pwm->pad_pwm_div = (uint16_t)63;
        for (i = 1; i <(8+1); i++)
        {
            if ((ch >> i) & 1)
            {
                *((volatile unsigned int *)(&pad_pwm->pad_pwm_cfg0) + i) = (h_cfg << 16 | l_cfg);
            }
        }
        pad_pwm->pad_pwm_en |= (ch);
    }
}

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
void pwm_steering_engine_set(uint8_t ch,int angle)
{
    uint8_t i;
    uint16_t h_cfg = 50000 - 1;
    uint16_t l_cfg = 1250 + 250 * angle / 9;
    for (i = 1; i < (8 + 1); i++)
    {
        if ((ch >> i) & 1)
        {
            *((volatile unsigned int *)(&pad_pwm->pad_pwm_cfg0) + i) = (h_cfg << 16 | l_cfg);
        }
    }
}
