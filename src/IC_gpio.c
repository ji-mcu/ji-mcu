

#include "IC_gpio.h"

// #include "soc_common.h"

/**
 * @brief config pad_mux fun output for pad0 to pad15
 * @param PADFun
 */
uint8_t PAD_MUX_FUN0(PADFunTypeDef0 PADFun, FunctionalState Newstate)
{
    // 检查是否有冲突的位
    uint8_t conflict = 0;
    if(Newstate !=DISABLE){
        for (int i = 0; i < 32; i++)
        {
            if ((PADFun & (1UL << i)) != 0) // 如果该位不为0,可能为奇数位也可能是偶数位
            {

                // 检查偶数位和奇数位的相邻位
                if (i % 2 == 0 && (i + 1 < 32) && (PADFun & (1UL << (i + 1))) != 0) // 偶数位的时候哦判断偶数位+1是否为是否为1,为1冲突
                {
                    conflict = 1;
                    // printf("have conflict1\n");
                    break;
                }
                if (i % 2 == 1 && (i - 1 >= 0) && (PADFun & (1UL << (i - 1))) != 0) // 如果是奇数位，那么判断奇数位-1是否为1
                {
                    conflict = 1;
                    // printf("have conflict1\n");
                    break;
                }
            }
        }
        // 如果没有冲突，设置位
        if (!conflict)
        {
            PAD_FUN0 = (uint32_t)PADFun;
            // printf("config is ok \n");
            return TRUE;
        }
        else
        {
            PAD_FUN0 = (uint32_t)0;
            // printf("config is fail\n");
            return FALSE; // 表示有冲突
        }
    }
    else {
        PAD_FUN0 = (uint32_t)0;
        // printf("no config \n");
        return FALSE;
    }

    return FALSE;
}

/**
 * @brief config pad_mux fun output for pad16 to pad18
 * @param PADFun
 */
uint8_t PAD_MUX_FUN1(PADFunTypeDef1 PADFun, FunctionalState Newstate)
{
    // 检查是否有冲突的位
    uint8_t conflict = 0;
    if (Newstate != DISABLE)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((PADFun & (1UL << i)) != 0) // 如果该位不为0,可能为奇数位也可能是偶数位
            {

                // 检查偶数位和奇数位的相邻位
                if (i % 2 == 0 && (i + 1 < 32) && (PADFun & (1UL << (i + 1))) != 0) // 偶数位的时候哦判断偶数位+1是否为是否为1,为1冲突
                {
                    conflict = 1;
                    // printf("have conflict1\n");
                    break;
                }
                if (i % 2 == 1 && (i - 1 >= 0) && (PADFun & (1UL << (i - 1))) != 0) // 如果是奇数位，那么判断奇数位-1是否为1
                {
                    conflict = 1;
                    // printf("have conflict1\n");
                    break;
                }
            }
        }
        // 如果没有冲突，设置位
        if (!conflict)
        {
            PAD_FUN1 = (uint32_t)PADFun;
            // printf("config is ok \n");
            return TRUE;
        }
        else
        {
            PAD_FUN1 = (uint32_t)0;
            // printf("config is fail\n");
            return FALSE; // 表示有冲突
        }
    }
    else
    {
        PAD_FUN1 = (uint32_t)0;
        // printf("no config \n");
        return FALSE;
    }

    return FALSE;
}

/*********************************************************************
 * @fn      GPIO_ModeCfg
 *
 * @brief   GPIO端口引脚模式配置
 *
 * @param   pin     - P0-PA8
 * @param   mode    - 输入输出类型
 *
 * @return  none
 */
void GPIOA_ModeCfg(uint32_t pin, GPIOModeTypeDef mode)
{
    switch (mode)
    {
    case GPIO_ModeIN:
        R32_P_PEN |= pin;  //使能寄存器输入
        R32_P_DIR &= ~pin; //保证该引脚一定是0
        break;
    case GPIO_ModeOut:
        R32_P_PEN |= pin;
        R32_P_DIR |= pin; 
        break;

    default:
        break;
    }
}

/*********************************************************************
 * @fn      GPIO_ITModeCfg
 *
 * @brief   GPIO引脚中断模式配置
 *
 * @param   pin     - PA0-P15
 * @param   mode    - 触发类型
 *
 * @return  none
 */
void GPIOA_ITModeCfg(uint32_t pin, GPIOITModeTpDef mode)
{
    uint32_t shifh_pin1 = (pin << 1) + 1 ;
    uint32_t shifh_pin2 = (pin << 1) ;
    uint8_t pin_number = 0;
    pin = pin >> 1;
    while (pin != 0)
    {
        pin = pin >> 1;
        pin_number++;
    }


    switch (mode)
    {
    case GPIO_ITMode_doubleEdge: //双边沿触发
        R32_P_INTTYPE = pin<<(pin_number+1);
        R32_P_CLR |= pin;
        break;
    case GPIO_ITMode_FallEdge: // 下降沿触发

        R32_P_INTTYPE = 0;
        R32_P_CLR |= pin;
        break;

    case GPIO_ITMode_RiseEdge: // 上升沿触发
        R32_P_INTTYPE = pin << (pin_number);
        R32_P_PSET |= pin;
        break;

    default:
        break;
    }
    // R32_P_INTSTATUS = 0;
    // R32_P_INTEN = pin;
    (*((PUINT32V)0x1A10000C))=0x02;
}

/*********************************************************************
 * @fn      GPIOPinRemap
 *
 * @brief   外设功能引脚映射
 *
 * @param   s       - 是否使能映射
 * @param   perph   - RB_PIN_SPI0   -  SPI0:  PA12/PA13/PA14/PA15 -> PB12/PB13/PB14/PB15
 *                    RB_PIN_UART1  -  UART1: PA8/PA9 ->  PB12/PB13
 *                    RB_PIN_UART0  -  UART0: PB4/PB7 ->  PA15/PA14
 *                    RB_PIN_TMR2   -  TMR2:  PA11 ->  PB11
 *                    RB_PIN_TMR1   -  TMR1:  PA10 ->  PB10
 *                    RB_PIN_TMR0   -  TMR0:  PA9 ->  PB23
 *
 * @return  none
 */
void GPIOPinRemap(FunctionalState s, uint16_t perph)
{
    ;
}

/*********************************************************************
 * @fn      GPIO Cfg
 *
 * @brief   模拟外设GPIO引脚功能控制
 *
 * @param   s       -   ENABLE  - 打开模拟外设功能，关闭数字功能
 *                      DISABLE - 启用数字功能，关闭模拟外设功能
 * @param   perph   -   RB_PIN_ADC0_1_IE    -  ADC0-1通道
 *                      RB_PIN_XT32K_IE     -  外部32K引脚
 *
 * @return  none
 */
// void GPIOAGPPCfg(FunctionalState s, uint16_t perph)
// {
//     if (s)
//     {
//         R16_PIN_ANALOG_IE |= perph;
//     }
//     else
//     {
//         R16_PIN_ANALOG_IE &= ~perph;
//     }
// }
