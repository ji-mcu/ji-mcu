/********************************** (C) COPYRIGHT *******************************
 * File Name          : uart0.c
 * Author             : huangjin
 * Version            : V0.1
 * Date               : 2024/10/1
 * Description
 *********************************************************************************
 *******************************************************************************/

#include "soc_common.h"

/*********************************************************************
 * @fn      UART0_DefInit
 *
 * @brief   串口默认初始化配置
 *
 * @param   none
 *
 * @return  none
 */
void UART0_DefInit(uint32_t baudrate , uint32_t byte_num)
{
    UART0_BaudRateCfg(115200);

    // R32_uart0_setup |= (uint16_t)Setup_parity_en;
    R32_uart0_setup |= (uint16_t)UART_7BYTE_TRIG<<1;
    R32_uart0_setup |= (uint16_t)UART_STOP_BIT_1<<3;//小心此处uin16类型转换出错
    R32_uart0_setup |= (uint16_t)Setup_uart_en_rx;
    R32_uart0_setup |= (uint16_t)Setup_uart_en_tx;

    R32_uart0_rx_addr= R8_uart_rx_data;
    R32_uart0_tx_addr= R8_uart_tx_data;
    if(byte_num !=0 )
    {
        R32_uart0_rxsize = (uint16_t)byte_num;
        R32_uart0_tx_size= (uint16_t)byte_num;
    }
    else
    {
        R32_uart0_rxsize = 1;
        R32_uart0_tx_size= 1;
    }
}

/*********************************************************************
 * @fn      UART0_BaudRateCfg
 *
 * @brief   串口波特率配置
 *
 * @param   baudrate    - 波特率
 *
 * @return  none
 */
void UART0_BaudRateCfg(uint32_t baudrate)
{
    uint32_t x;

    x = TIM_CLOCK_64M / baudrate;

    R32_uart0_setup |= (uint16_t)x<<16;
}

/*********************************************************************
 * @fn      UART0_ByteTrigCfg
 *
 * @brief   串口 中断配置
 *
 * @param   
 *
 * @return  none
 */
// void UART0_ByteTrigCfg(UARTByteTRIGTypeDef b)
// {
    
// }

/*********************************************************************
 * @fn      UART0_INTCfg
 *
 * @brief   串口中断配置
 *
 * @param   s       - 中断控制状态，是否使能相应中断
 * @param   i       - 中断类型
 *                  
 *
 * @return  none
 */
void UART0_INTCfg(FunctionalState s, uint8_t i)
{

}

/*********************************************************************
 * @fn      UART0_Reset
 *
 * @brief   串口软件复位
 *
 * @param   none
 *
 * @return  none
 */
void UART0_Reset(void)
{

    
}

/*********************************************************************
 * @fn      UART0_SendByte
 *
 * @brief   串口单字节发送
 *
 * @param   data       待发送的字节
 *
 * @return  none
 */

void UART0_SendByte(uint8_t data)
{
    
    R8_uart_tx_data = data ;
    // pad_uart0->pad_uart_tx_data_reg[0] = data;
    R32_uart0_tx_cfg |= CFG_en;
}

/*********************************************************************
 * @fn      UART0_SendString
 *
 * @brief   串口多字节发送
 *
 * @param   buf     - 待发送的数据内容首地址
 * @param   l       - 待发送的数据长度
 *
 * @return  none
 */
void UART0_SendString(uint8_t *buf, uint16_t l)
{
    uint16_t len = l;
    R32_uart0_tx_size=len;
    while (len)
    {
        R32_uart0_tx_cfg |= CFG_en;
        if (!(R32_uart0_status && TX_FIFO_EMP))
        {
            R8_uart_tx_data = *buf++;
            len--;
        }
    }
}
/*********************************************************************
/**
 * @brief   串口读取单字节
 *
 * @return  读取到的单字节
 */
uint8_t UART0_RecvByte()
{

    // uint8_t data=pad_uart0->pad_uart_rx_data_reg[0];
    uint8_t data = R8_uart_rx_data ;
    R32_uart0_rx_cfg |= CFG_en;
    return data;
}

/*********************************************************************
 * @fn      UART0_RecvString
 *
 * @brief   串口读取多字节
 *
 * @param   buf     - 读取数据存放缓存区首地址
 * @param   l       - 待发送的数据长度
 * @return  读取数据长度
 */
uint16_t UART0_RecvString(uint16_t l)
{
    // uint16_t len = 0;
    uint8_t buf[l];

    uint16_t len = l;
    R32_uart0_tx_size = len;
    while (len<=l)
    {
        R32_uart0_rx_cfg |= CFG_en;
        if (!(R32_uart0_status && RX_DATA_RDY))
        {
            buf[len] = R8_uart_rx_data;

            len++;
        }
    }
    return *buf;
}
