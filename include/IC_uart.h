/********************************** (C) COPYRIGHT *******************************
 * File Name          : IC_uart.h
 * Author             : huan jin
 * Version            : V0.1
 * Date               : 2024/9/27
 * Description
 *********************************************************************************

 *******************************************************************************/

#ifndef __IC_UART_H__
#define __IC_UART_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "core_SFR.h"
/**
 * @brief	LINE error and status define
 */

#define PARITY_status_ERR   (0x0001 <<2 )       // 奇偶校验位出错
#define TX_FIFO_EMP         (0x0001 << 0)           // 当前不允许发送数据
#define RX_DATA_RDY         (0x0001 << 1)           // 当前不可接收数据
#define CFG_Clr             (0x0001 << 5)           //清除rx和tx的数据
#define CFG_en              (0x0001 << 4)           //启动udma，tx使能和rx使能位
#define CGG_continuous      (0x0001 <<0 )          //启动连续传输模式
#define Setup_parity_en     (0x0001 <<0 )
#define Setup_uart_byte_num (UART_7BYTE_TRIG << 1)
#define Setup_uart_stop_bit (UART_STOP_BIT_1 << 3)
#define Setup_uart_en_rx    (0x0001 <<8 )
#define Setup_uart_en_tx    (0x0001 <<9 )

/**
 * @brief  Configuration UART Byte num
 */
typedef enum
{
    UART_5BYTE_TRIG = 0, // 5字节
    UART_6BYTE_TRIG,     // 6字节
    UART_7BYTE_TRIG,     // 7字节
    UART_8BYTE_TRIG,     // 8字节
} UARTByteTypeDef;



/**
 * @brief Config Uart stop bit num
 */
typedef enum uart_stop_bit
{
    UART_STOP_BIT_1 = 0,
    UART_STOP_BIT_2 = 1
} UART_STOP_BIT; // 停止位

/* Uart Init structure definition  */
typedef struct
{
    uint32_t uart_ClockSpeed;

    uint8_t uart_ByeCFG;//choose 7
    uint8_t uart_StopBit;//cho0se 0
    uint16_t uart_Txen;
    uint16_t uart_Rxen;

    uint8_t uart_rx_size ;//can not max 256
    uint8_t uart_tx_size; // can not max 256

    uint32_t uart_rx_addr;

    uint32_t uart_tx_addr;

} Uart_InitTypeDef;


/**
 * @brief   串口默认初始化配置
 */
void UART0_DefInit(Uart_InitTypeDef *uart_InitStruct);

/**
 * @brief   串口波特率配置
 *
 * @param   baudrate    - 波特率
 */
void UART0_BaudRateCfg(uint32_t baudrate);

void uart_StructInit(Uart_InitTypeDef *uart_InitStruct);
    /**
     * @brief   串口字节触发中断配置
     *
     * @param   b       - 触发字节数 refer to UARTByteTRIGTypeDef
     */
    // void UART0_ByteTrigCfg(UARTByteTypeDef b);

    /**
     * @brief   串口中断配置
     *
     * @param   s       - 中断控制状态，是否使能相应中断
     * @param   i       - 中断类型
     *
     */
    // void UART0_INTCfg(FunctionalState s, uint8_t i);

    /**
     * @brief   串口软件复位
     */
    void UART0_Reset(void);

/**
 * @brief   清除当前rx准备发送数据
 */
#define UART0_CLR_RXFIFO() (R32_uart0_rx_cfg |= CFG_Clr)
/**
 * @brief   设置接收byte长度
 */
#define UART0_recv_byte_num(d) (R32_uart0_rxsize = (uint16_t)d)
/**
 * @brief   设置发送byte长度
 */
#define UART0_tx_byte_num(d) (R32_uart0_tx_size = (uint16_t)d)
/**
 * @brief   设置奇偶校验使能
 */
#define UART0_parity_en() (R32_uart0_setup |= (uint16_t)Setup_parity_en)
/**
 * @brief   设置奇偶校验关闭
 */
#define UART0_parity_close() (R32_uart0_setup &= (uint16_t)(~Setup_parity_en))

/**
 * @brief   清除当前tx准备发送数据
 */
#define UART0_CLR_TXFIFO() (R32_uart0_tx_cfg |= CFG_Clr)

/**
 * @brief   获取当前中断标志
 *
 * @return  当前中断标志
 */
// #define UART0_GetITFlag() ()

/**
 * @brief   获取当前通讯状态
 *
 * @return  refer to LINE error and status define
 */
#define UART0_GetLinSTA() (R32_uart0_status)

/**
 * @brief   串口单字节发送
 *
 * @param   data       待发送的字节
 */
void UART0_SendByte(uint8_t data) ;

/**
 * @brief   串口多字节发送
 *
 * @param   buf     - 待发送的数据内容首地址
 * @param   l       - 待发送的数据长度
 */
void UART0_SendString(uint8_t *buf, uint16_t l);

/**
 * @brief   串口读取单字节
 *
 * @return  读取到的单字节
 */
uint8_t UART0_RecvByte() ;

/**
 * @brief   串口读取多字节
 *
 * @param
 * @param   l       - 待发送的数据长度
 * @return  buf     - 读取数据存放缓存区首地址
 */
uint16_t UART0_RecvString(uint16_t l);


/********************************************************/


/**
 * @brief   串口默认初始化配置
 */
void UART0_DefInit(Uart_InitTypeDef *uart_InitStruct);

/**
 * @brief   串口波特率配置
 *
 * @param   baudrate    - 波特率
 */
void UART1_BaudRateCfg(uint32_t baudrate);

/**
 * @brief   串口字节触发中断配置
 *
 * @param   b       - 触发字节数 refer to UARTByteTRIGTypeDef
 */
// void UART1_ByteTrigCfg(UARTByteTypeDef b);

/**
 * @brief   串口中断配置
 *
 * @param   s       - 中断控制状态，是否使能相应中断
 * @param   i       - 中断类型
 *
 */
// void UART1_INTCfg(FunctionalState s, uint8_t i);

/**
 * @brief   串口软件复位
 */
void UART1_Reset(void);

/**
 * @brief   清除当前rx准备发送数据
 */
#define UART1_CLR_RXFIFO() (R32_uart1_rx_cfg |= CFG_Clr)

/**
 * @brief   清除当前tx准备发送数据
 */
#define UART1_CLR_TXFIFO() (R32_uart1_tx_cfg |= CFG_Clr)

/**
 * @brief   获取当前中断标志
 *
 * @return  当前中断标志
 */
// #define UART1_GetITFlag() ()

/**
 * @brief   获取当前通讯状态
 *
 * @return  refer to LINE error and status define
 */
#define UART1_GetLinSTA() (R32_uart1_status)

/**
 * @brief   串口单字节发送
 *
 * @param   data       待发送的字节
 */
void UART1_SendByte(uint8_t data) ;

/**
 * @brief   串口多字节发送
 *
 * @param   buf     - 待发送的数据内容首地址
 * @param   l       - 待发送的数据长度
 */
void UART1_SendString(uint8_t *buf, uint16_t l);

/**
 * @brief   串口读取单字节
 *
 * @return  读取到的单字节
 */
uint8_t UART1_RecvByte() ;

/**
 * @brief   串口读取多字节
 *
 * @param
 * @param   l       - 待发送的数据长度
 * @return  buf     - 读取数据存放缓存区首地址
 */
uint16_t UART1_RecvString(uint16_t l);

#ifdef __cplusplus
}
#endif

#endif // __IC_UART_H__
