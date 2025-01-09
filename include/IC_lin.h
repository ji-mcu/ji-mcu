/********************************** (C) COPYRIGHT *******************************
 * File Name          : IC_lin.h
 * Author             : chen min li
 * Version            : V0.1
 * Date               : 2024/9/27
 * Description
 *********************************************************************************

 *******************************************************************************/
#ifndef __IC_LIN_H__
#define __IC_LIN_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "core_SFR.h"


    // typedef enum IRQn
    // {
    //     LIN_IRQn = 5
    // } IRQn_Type;

void LIN_init(void);
void LIN_send(unsigned char ID, unsigned char *buf);
void LIN_send_head(unsigned char ID);

#ifdef __cplusplus
}
#endif



#endif // __IC_LIN_H__