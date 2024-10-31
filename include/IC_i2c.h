/********************************** (C) COPYRIGHT  *******************************
 * File Name          : IC_i2c.h
 * Author             : huang jin
 * Version            : V0.0
 * Date               : 2024/09/21
 * Description        : 包含i2c的所有库函数
 *******************************************************************************/
#ifndef __IC_I2C_H
#define __IC_I2C_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "soc_common.h"

    /* I2C Init structure definition  */
    typedef struct
    {
        uint32_t I2C_ClockSpeed; /* Specifies the clock frequency.
                                    This parameter must be set to a value lower than 400kHz */

        uint16_t I2C_Mode; /* Specifies the I2C mode.
                              This parameter can be a value of @ref I2C_mode */
        uint16_t I2C_OwnAddress1; /* Specifies the first device own address.
                                     This parameter can be a 7-bit or 10-bit address. */
        uint32_t I2C_rx_addr; /* destination address */
        uint32_t I2C_tx_addr; /* destination address */

    } I2C_InitTypeDef;

/* I2C_mode */
#define I2C_Mode_Slave ((uint8_t)0x00)
#define I2C_Mode_Master ((uint8_t)0x20)


/* I2C_acknowledgement */
#define I2C_Ack_Enable ((uint8_t)0x04)
#define I2C_Ack_Disable ((uint8_t)0x00)

/* I2C_transfer_direction */
#define I2C_Direction_Transmitter ((uint8_t)1<<4)
#define I2C_Direction_Receiver ((uint8_t)1<<4)
#define I2C_Clear ((uint8_t)1 << 5)
#define I2C_continous ((uint8_t)1 << 0)

#define  I2C_ACK      					((uint8_t)0x00)
#define  I2C_NACK         				((uint8_t)0x08)

#define I2C_SW_Disable                  ((uint8_t)0x01)
#define I2C_SW_Enable                   ((uint8_t)0x00)

/* I2C_interrupts_definition */
#define I2C_IT_BUF ((uint16_t)0x0400)
#define I2C_IT_EVT ((uint16_t)0x0200)
#define I2C_IT_ERR ((uint16_t)0x0100)

/* I2C_interrupts_definition */

/*I2C status flag*/
#define I2C_FLAG_BUSY ((uint8_t)1<<0)
#define I2C_FLAG_al ((uint8_t)1<<1)
#define I2C_FLAG_ack ((uint8_t)1<<3)
#define I2C_FLAG_data_store_req ((uint8_t)1<<4)


//Udma control
#define I2C_CMD_START       (uint8_t)0x02
#define I2C_CMD_STOP        (uint8_t)0x21
#define I2C_CMD_RD_ACK      (uint8_t)0x41
#define I2C_CMD_RD_NACK     (uint8_t)0x61
#define I2C_CMD_WR          (uint8_t)0x81
#define I2C_CMD_WAIT        (uint8_t)0xA1
#define I2C_CMD_RPT         (uint8_t)0xC1
#define I2C_CMD_CFG         (uint8_t)0xE1
#define I2C_CMD_WAIT_EV     (uint8_t)0x11
/****************I2C Master Events (Events grouped in order of communication)********************/

/******************I2C Slave Events (Events grouped in order of communication)******************/

void I2C_Init(RV_i2c_t *I2Cx, I2C_InitTypeDef *I2C_InitStruct , I2C_Ptr *I2C_px);
void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct);
void I2C_Cmd(RV_i2c_t *I2Cx, uint8_t data_num, uint32_t i2c_addr, Function Newfunction, FunctionalState NewState);
void I2C_GenerateSTART(I2C_Ptr *I2C_px, uint8_t udma_addr_count, FunctionalState NewState);
void I2C_GenerateSTOP(I2C_Ptr *I2C_px, uint8_t udma_addr_count, FunctionalState NewState);
void I2C_AcknowledgeConfig(I2C_Ptr *I2C_px, uint8_t udma_addr_count, FunctionalState NewState);
void I2C_OwnAddress2Config(RV_i2c_t *I2Cx, uint8_t Address);
// void I2C_GeneralCallCmd(RV_i2c_t *I2Cx, FunctionalState NewState);
void I2C_ITConfig(RV_i2c_t *I2Cx, uint16_t I2C_IT, FunctionalState NewState);
uint8_t I2C_SendData(RV_i2c_t *I2Cx, I2C_Ptr *I2C_px, uint8_t udma_addr_count, uint8_t *Data, uint8_t sizeof_data);
uint8_t I2C_ReceiveData(RV_i2c_t *I2Cx, I2C_Ptr *I2C_px, uint8_t udma_addr_count, uint8_t sizeof_data);
void I2C_Send7bitAddress(RV_i2c_t *I2Cx, uint8_t Address, uint8_t I2C_Direction);
uint16_t I2C_ReadRegister(RV_i2c_t *I2Cx, uint8_t I2C_Register);
uint32_t I2C_udma_keyword_reg(uint32_t i2c_addr, uint8_t udma_addr_count);
void I2C_SoftwareResetCmd(RV_i2c_t *I2Cx, FunctionalState NewState);

/*********************************************************
 *
 *  a) Basic state monitoring(First way)
 ********************************************************
 */
ErrorStatus I2C_CheckEvent(RV_i2c_t *I2Cx, uint32_t I2C_EVENT);
/*********************************************************
 *
 *  b) Advanced state monitoring(Second way:)
 ********************************************************
 */
uint32_t I2C_GetLastEvent(RV_i2c_t *I2Cx);
/*********************************************************
 *
 *  c) Flag-based state monitoring(Third way)
 *********************************************************
 */
FlagStatus I2C_GetFlagStatus(RV_i2c_t *I2Cx, uint32_t I2C_FLAG);

void I2C_ClearFlag(RV_i2c_t *I2Cx, uint32_t I2C_FLAG);
ITStatus I2C_GetITStatus(RV_i2c_t *I2Cx, uint32_t I2C_IT);

#ifdef __cplusplus
}
#endif

#endif
