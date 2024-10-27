
#include "soc_common.h"

// /*********************************************************************
//  * @fn      SysTick_Handler
//  *
//  * @brief   This function handles SysTick exception.
//  *
//  * @return  none
//  */
// void SysTick_Handler(void)
// {
//     time = SysTick->CNT;
//     SysTick->CTLR = 0;
//     SysTick->SR = 0;
//     printf("delta time:%d\r\n", time - 0x20);
// }

// /*********************************************************************
//  * @fn      Systick_Init
//  *
//  * @brief   Initializes Systick.
//  *
//  * @return  none
//  */
// void Systick_Init(void)
// {
//     SysTick->SR = 0;
//     SysTick->CNT = 0;
//     SysTick->CMP = 0x20;
//     SysTick->CTLR = 0x7;
// }
