/********************************** (C) COPYRIGHT *******************************
 * File Name          : SYS.c
 * Author             : huang jin
 * Version            : 
 * Date               : 2024/9/30
 * Description        ：控制系统时钟
 *********************************************************************************
 *******************************************************************************/

// #include "soc_common.h"
#include "core_sys.h"
#include "hal/pulp_io.h"
/*********************************************************************
 * @fn      SetSysClock
 *
 * @brief   配置系统运行时钟
 *
 * @param   sc      - 系统时钟源选择 
 *
 * @return  none
 */
// __attribute__((section(".vectors")))
void SetSysClock(TIMClock_TypeDef sysfreq)
{
    uint32_t tempreg;
    tempreg= sysfreq/1000000 - 2;
   //系统频率计算公式：24*(PLM+2)/(PLN+2)/2
    R8_CMD2 = ((uint8_t)tempreg & D2A_PLL_PLM);
    // R8_CMD3 

}
/*********************************************************************
 * @fn      SystemInit
 *
 * @brief  
 *
 * @param   
 *
 * @return  none
 */
void SystemInit()
{
   SetSysClock(TIM_CLOCK_64M);
    __nop();
    __nop();
    __nop();
    // soc_boorctrl((uint32_t)0x1c020000);
    R32_boot_addr = 0x1c020000;
    SYS_ResetExecute();
}


/*********************************************************************
 * @fn      GetSysClock
 *
 * @brief   获取当前系统时钟
 *
 * @param   none
 *
 * @return  Hz
 */
uint32_t GetSysClock(void)
{
    uint32_t sysfreq=0;
    uint32_t tempreg1=R8_CMD2;
    uint32_t tempreg2=R8_CMD3;
    // tempreg = sysfreq / 1000000 - 2;
    // 系统频率计算公式：24*(PLM+2)/(PLN+2)/2

    sysfreq = 24*(tempreg1+2)/(tempreg2+2)/2;
    // R8_CMD3
}

/*********************************************************************
 * @fn      SYS_GetInfoSta
 *
 * @brief   获取当前系统信息状态
 *
 * @param   i       - refer to SYS_InfoStaTypeDef
 *
 * @return  是否开启
 */
uint32_t SYS_GetInfoSta(SYS_InfoStaTypeDef info)
{

    if(info == n_cores)
        return (uint32_t)R32_info&0xff00;
    else 
        return (uint32_t)R32_info&0x00ff;
}

/*********************************************************************
 * @fn      SYS_ResetExecute
 *
 * @brief   执行系统软件复位
 *
 * @param   none
 *
 * @return  none
 */
// __attribute__((section(".highcode"))) 
void SYS_ResetExecute(void)
{
    // __nop();
    pulp_write32(SOC_RST,3);
    pulp_write32(SOC_Fetchen, 0);
    __nop();
    pulp_write32(SOC_Fetchen, 1);
    pulp_write32(SOC_RST, 0);

}

/*********************************************************************
 * @fn      SYS_DisableAllIrq
 *
 * @brief   关闭所有中断，并保留当前中断值
 *
 * @param   pirqv   - 当前保留中断值
 *
 * @return  none
 */
void SYS_DisableAllIrq(uint32_t *pirqv)
{
    __nop();
}

/*********************************************************************
 * @fn      SYS_RecoverIrq
 *
 * @brief   恢复之前关闭的中断值
 *
 * @param   irq_status  - 当前保留中断值
 *
 * @return  none
 */
void SYS_RecoverIrq(uint32_t irq_status)
{
    __nop();
}




/*********************************************************************
 * @fn      HardFault_Handler
 *
 * @brief   硬件错误中断，进入后执行复位，复位类型为上电复位
 *
 * @param   none
 *
 * @return  none
 */
// __attribute__((interrupt("WCH-Interrupt-fast")))
// __attribute__((section(".highcode")))
// __attribute__((weak)) void
// HardFault_Handler(void)
// {
//     __nop();
// }

/*********************************************************************
 * @fn      mDelayuS
 *
 * @brief   uS 延时 假设执行一个指令周期需要4个时钟周期 则执行16个空指令为1us
 *
 * @param   t       - 时间参数
 *
 * @return  none
 */
// __attribute__((section(".highcode"))) 
void mDelayuS(uint16_t t)
{
    int32_t i;
// #if (FREQ_SYS == 64000000)
//     i = t * 16;
// #elif (FREQ_SYS == 48000000)
//     i = t * 12;
// #elif (FREQ_SYS == 40000000)
//     i = t * 10;
// #elif (FREQ_SYS == 32000000)
//     i = t << 3;
// #elif (FREQ_SYS == 24000000)
//     i = t * 6;
// #elif (FREQ_SYS == 16000000)
//     i = t << 2;
// #elif (FREQ_SYS == 8000000)
//     i = t << 1;
// #elif (FREQ_SYS == 4000000)
//     i = t;
// #elif (FREQ_SYS == 2000000)
//     i = t >> 1;
// #elif (FREQ_SYS == 1000000)
//     i = t >> 2;
// #endif
    i = t * 11;
    do
    {
        __nop();
        // ;
    } while (--i);
}

/*********************************************************************
 * @fn      mDelaymS
 *
 * @brief   mS 延时
 *
 * @param   t       - 时间参数
 *
 * @return  none
 */

void mDelaymS(int32_t t)
{
    int32_t i;

    for (i = 0; i < t; i++)
    {
        mDelayuS(1150);
    }
}

#ifdef DEBUG
int _write(int fd, char *buf, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
#if DEBUG == Debug_UART0
        while (R8_UART0_TFC == UART_FIFO_SIZE)
            ;                  /* 等待数据发送 */
        R8_UART0_THR = *buf++; /* 发送数据 */
#elif DEBUG == Debug_UART1
        while (R8_UART1_TFC == UART_FIFO_SIZE)
            ;                  /* 等待数据发送 */
        R8_UART1_THR = *buf++; /* 发送数据 */
#elif DEBUG == Debug_UART2
        while (R8_UART2_TFC == UART_FIFO_SIZE)
            ;                  /* 等待数据发送 */
        R8_UART2_THR = *buf++; /* 发送数据 */
#elif DEBUG == Debug_UART3
        while (R8_UART3_TFC == UART_FIFO_SIZE)
            ;                  /* 等待数据发送 */
        R8_UART3_THR = *buf++; /* 发送数据 */
#endif
    }
    return size;
}

#endif
