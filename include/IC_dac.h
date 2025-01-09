/********************************** (C) COPYRIGHT *******************************
 * File Name          : IC_dac.h
 * Author             : haungjin
 * Version            : V0.1
 * Date               : 2024/12/8
 * Description
 *******************************************************************************/

#ifndef __IC_DAC_H__
#define __IC_DAC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "core_SFR.h"
/**
 * @brief   设置 DAC 使能
 *
 * @param  1:open ; 0 :close
 */
#define DAC_EN(d) (R8_CMD6 = ((R8_CMD6 & ~(1UL << D2A_DAC12_EN)) | (d ? (1UL << D2A_DAC12_EN) : 0)))

/**
 * @brief   设置 DAC_Value
 *
 * @param d
 */
RV_STATIC_INLINE void DAC_Value_IN(uint16_t data){
    uint16_t temp1=data&D2A_DAC12_SEL_1;
    uint16_t temp2=data&D2A_DAC12_SEL_2;
    R8_CMD8 =(uint8_t)temp1;
    R8_CMD9 =(uint8_t)temp2;

}

RV_STATIC_INLINE void DAC_deInit(void)
{
    DAC_Value_IN(0x0ff);
    DAC_EN(1);
}

#ifdef __cplusplus
}
#endif

#endif // __IC_DAC_H__
