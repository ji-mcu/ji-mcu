/********************************** (C) COPYRIGHT *******************************
 * File Name          : uart1.c
 * Author             : huangjin
 * Version            : V0.2
 * Date               : 2024/10/31
 * Description
 *********************************************************************************
 *******************************************************************************/

#include "soc_common.h"

/*********************************************************************
 * @fn      UART1_DefInit
 *
 * @brief   串口默认初始化配置
 *
 * @param   none
 *
 * @return  none
 */
void UART1_DefInit(Uart_InitTypeDef *uart_InitStruct)
{
    // UART1_BaudRateCfg(baudrate);
    uint32_t baudrate = 0;
    baudrate = TIM_CLOCK_64M / uart_InitStruct->uart_ClockSpeed - 1;
    R32_uart1_setup |= (uint32_t)(baudrate << 16);
    R32_uart1_setup |= (uint32_t)uart_InitStruct->uart_StopBit;
    R32_uart1_setup |= (uint32_t)(uart_InitStruct->uart_ByeCFG << 1);
    // R32_uart1_setup |= (uint16_t)UART_STOP_BIT_1<<3;//小心此处uin16类型转换出错
    R32_uart1_setup |= (uint32_t)uart_InitStruct->uart_Rxen;
    R32_uart1_setup |= (uint32_t)uart_InitStruct->uart_Txen;

    R32_uart1_rx_addr = uart_InitStruct->uart_rx_addr;
    R32_uart1_tx_addr = uart_InitStruct->uart_tx_addr;
    // R32_uart1_tx_addr = RV_Udma_uart_RX_ADDR;

    R32_uart1_rx_size = (uint32_t)uart_InitStruct->uart_rx_size;
    R32_uart1_tx_size = (uint32_t)uart_InitStruct->uart_tx_size;
}

// void uart_StructInit(Uart_InitTypeDef *uart_InitStruct)
// {
//     uart_InitStruct->uart_ClockSpeed = 115200;
//     uart_InitStruct->uart_ByeCFG = UART_7BYTE_TRIG;
//     uart_InitStruct->uart_StopBit = UART_STOP_BIT_1;
//     uart_InitStruct->uart_Txen = Setup_uart_en_tx;
//     uart_InitStruct->uart_Rxen = Setup_uart_en_rx;
//     uart_InitStruct->uart_rx_size = 1;
//     uart_InitStruct->uart_tx_size = 1;
//     uart_InitStruct->uart_rx_addr = RV_Udma_uart_RX_ADDR;
//     uart_InitStruct->uart_tx_addr = RV_Udma_uart_TX_ADDR;
// }

/*********************************************************************
 * @fn      UART1_BaudRateCfg
 *
 * @brief   串口波特率配置
 *
 * @param   baudrate    - 波特率
 *
 * @return  none
 */
void UART1_BaudRateCfg(uint32_t baudrate)
{
    uint32_t x;

    x = TIM_CLOCK_64M / baudrate - 1;
    // x=baudrate;

    R32_uart1_setup |= (uint32_t)x << 16;
}

/*********************************************************************
 * @fn      UART1_ByteTrigCfg
 *
 * @brief   串口 中断配置
 *
 * @param
 *
 * @return  none
 */
// void UART1_ByteTrigCfg(UARTByteTRIGTypeDef b)
// {

// }

/*********************************************************************
 * @fn      UART1_INTCfg
 *
 * @brief   串口中断配置
 *
 * @param   s       - 中断控制状态，是否使能相应中断
 * @param   i       - 中断类型
 *
 *
 * @return  none
 */
void UART1_INTCfg(FunctionalState s, uint8_t i)
{
}

/*********************************************************************
 * @fn      UART1_Reset
 *
 * @brief   串口软件复位
 *
 * @param   none
 *
 * @return  none
 */
void UART1_Reset(void)
{
}

/*********************************************************************
 * @fn      UART1_SendByte
 *
 * @brief   串口单字节发送
 *
 * @param   data       待发送的字节
 *
 * @return  none
 */

void UART1_SendByte(uint8_t data)
{
    while ((R32_uart1_status & TX_FIFO_EMP) == 1)
    {
        ;
    }
    R8_uart_tx_data = data;
    R32_uart1_tx_cfg |= CFG_en;
}

/*********************************************************************
 * @fn      UART1_SendString
 *
 * @brief   串口多字节发送
 *
 * @param   buf     - 待发送的数据内容首地址
 * @param   l       - 待发送的数据长度
 *
 * @return  none
 */
void UART1_SendString(uint8_t *buf, uint16_t l)
{
    uint16_t len = 0;
    // R32_uart1_tx_size=len;
    for (len = 0; len < l; len++)
    {
        // R32_uart1_tx_cfg |= CFG_Clr;
        if ((R32_uart1_status & TX_FIFO_EMP) == 1)
        {
            // UART1_SendByte(buf[len]);
            // *((volatile uint32_t *)((&R8_uart_tx_data) + len)) = buf[len];
            udma_tx_ptr4->uart_data_reg[len] = buf[len];
            // R8_uart_tx_data = buf[len];
            // DelayUs(100);
        }
    }
    R32_uart1_tx_cfg |= CFG_en;
}
/*********************************************************************
/**
 * @brief   串口读取单字节
 *
 * @return  读取到的单字节
 */
uint8_t UART1_RecvByte()
{
    // uint8_t data=0;
    uint8_t flag = 0;
    R32_uart1_rx_cfg |= CFG_en;
    while ((R32_uart1_status & RX_DATA_RDY) == 0)
    {

        // data = R8_uart_rx_data;
        flag = 1;
    }
    // uint8_t data=pad_uart1->pad_uart_rx_data_reg[0];

    return flag;
}

/*********************************************************************
 * @fn      UART1_RecvString
 *
 * @brief   串口读取多字节
 *
 * @param   buf     - 读取数据存放缓存区首地址
 * @param   l       - 待发送的数据长度
 * @return  读取数据长度
 */
uint16_t UART1_RecvString(uint16_t l)
{

    uint8_t len = 0;
    R32_uart1_rx_cfg |= CFG_en;
    while ((R32_uart1_status & RX_DATA_RDY) == 0)
    {

        // data = R8_uart_rx_data;
        len++;
    }
    // uint8_t data=pad_uart1->pad_uart_rx_data_reg[0];
    R32_uart1_tx_size = len;

    return len;
}
