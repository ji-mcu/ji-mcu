/********************************** (C) COPYRIGHT *******************************
 * File Name          : SYS.c
 * Author             : huang jin
 * Version            : 
 * Date               : 2024/9/30
 * Description        ：控制系统时钟
 *********************************************************************************
 *******************************************************************************/

#include "soc_common.h"

/*********************************************************************
 * @fn      SetSysClock
 *
 * @brief   配置系统运行时钟
 *
 * @param   sc      - 系统时钟源选择 
 *
 * @return  none
 */
// __attribute__((section(".highcode"))) 
void SetSysClock(uint16_t sc)
{
    __nop();
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
    __nop();
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
uint8_t SYS_GetInfoSta(SYS_InfoStaTypeDef i)
{
    __nop();
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
 * @fn      SYS_GetSysTickCnt
 *
 * @brief   获取当前系统(SYSTICK)计数值
 *
 * @param   none
 *
 * @return  当前计数值
 */
uint32_t SYS_GetSysTickCnt(void)
{
    __nop();
}

/*********************************************************************
 * @fn      WWDG_ITCfg
 *
 * @brief   看门狗定时器溢出中断使能
 *
 * @param   s       - 溢出是否中断
 *
 * @return  none
 */
void WWDG_ITCfg(FunctionalState s)
{
        ;
}

/*********************************************************************
 * @fn      WWDG_ResetCfg
 *
 * @brief   看门狗定时器复位功能
 *
 * @param   s       - 溢出是否复位
 *
 * @return  none
 */
void WWDG_ResetCfg(FunctionalState s)
{
    ;
}

/*********************************************************************
 * @fn      WWDG_ClearFlag
 *
 * @brief   清除看门狗中断标志，重新加载计数值也可清除
 *
 * @param   none
 *
 * @return  none
 */
void WWDG_ClearFlag(void)
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
__attribute__((weak)) void
HardFault_Handler(void)
{
    __nop();
}

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
    uint32_t i;
#if (FREQ_SYS == 64000000)
    i = t * 16;
#elif (FREQ_SYS == 48000000)
    i = t * 12;
#elif (FREQ_SYS == 40000000)
    i = t * 10;
#elif (FREQ_SYS == 32000000)
    i = t << 3;
#elif (FREQ_SYS == 24000000)
    i = t * 6;
#elif (FREQ_SYS == 16000000)
    i = t << 2;
#elif (FREQ_SYS == 8000000)
    i = t << 1;
#elif (FREQ_SYS == 4000000)
    i = t;
#elif (FREQ_SYS == 2000000)
    i = t >> 1;
#elif (FREQ_SYS == 1000000)
    i = t >> 2;
#endif
    do
    {
        __nop();
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
// __attribute__((section(".highcode"))) 
void mDelaymS(uint16_t t)
{
    uint16_t i;

    for (i = 0; i < t; i++)
    {
        mDelayuS(1000);
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
