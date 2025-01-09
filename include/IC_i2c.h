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

// #include "soc_common.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "core_sys.h"
// #include "IC_udma.h"
#include "soc_event.h"
#include "core_riscv.h"

 /* I2C Init structure definition  */
 typedef struct
 {
     uint32_t I2C_ClockSpeed; /*This parameter must be set to a value lower than 3.4MHz */
     uint8_t  I2C_bytes     ; /* higher than 0 but lower than 256*/
     uint8_t  I2C_Direction ;  /* can be set as read= 0x60 or wirte= 0x80*/
     uint8_t  I2C_Device_addr   ;
     uint16_t I2C_OwnAddress1; /* Specifies the first device own address.   This parameter can be a 7-bit or 10-bit address. */
    //  uint32_t I2C_addr;        /* destination address */
     // uint32_t I2C_tx_addr; /* destination address */
 } I2C_InitTypeDef;
 /* I2C Init structure definition  */
 typedef enum
 {
    Standard_Mode=100000,
    Fast_Mode    =400000,
    High_speed_mode=3400000,
 } I2C_Baudrate_TypeDef;

#define I2C_Baudrate    Standard_Mode
#define I2C_BYTES       8
/* I2C_mode */
#define I2C_Mode_Slave ((uint8_t)0x00)
#define I2C_Mode_Master ((uint8_t)0x20)

#define TIME_OUT        (uint32_t)0x64 
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
#define I2C_FLAG_BUSY               ((uint8_t)1<<0)
#define I2C_FLAG_al                 ((uint8_t)1<<1)
#define I2C_FLAG_ack                ((uint8_t)1 << 3)
#define I2C_FLAG_data_store_req     ((uint8_t)1 << 4)

#define I2C_CMD_OFFSET       4
//Udma control
#define I2C_CMD_START       (0x0<< I2C_CMD_OFFSET)
#define I2C_CMD_STOP        (0x2<< I2C_CMD_OFFSET)
#define I2C_CMD_RD_ACK      (0x4<< I2C_CMD_OFFSET)
#define I2C_CMD_RD_NACK     (0x6<< I2C_CMD_OFFSET)
#define I2C_CMD_WR          (0x8<< I2C_CMD_OFFSET)
#define I2C_CMD_WAIT        (0xA<< I2C_CMD_OFFSET)
#define I2C_CMD_RPT         (0xC<< I2C_CMD_OFFSET)
#define I2C_CMD_CFG         (0xE<< I2C_CMD_OFFSET)
#define I2C_CMD_WAIT_EV     (0x1<< I2C_CMD_OFFSET)




     /****************I2C Master Events (Events grouped in order of communication)********************/

     /******************I2C Slave Events (Events grouped in order of communication)******************/

void I2C_Init(I2C_InitTypeDef *I2C_InitStruct);
void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct);
void i2c_send_cmd(uint32_t baudrate, uint8_t data_num, uint32_t i2cbase, Function Newfunction);
uint8_t I2C_get_status(RV_i2c_t *I2Cx);
uint8_t I2C_busy(RV_i2c_t *I2Cx);
void I2C_SendData(uint32_t i2cbase, uint32_t u8Data, uint8_t data_num);
void I2C_ReceiveData(uint32_t i2cbase, uint32_t u8Data, uint8_t data_num);
uint16_t I2C_ReadRegister(RV_i2c_t *I2Cx, uint8_t I2C_Register);
uint32_t I2C_udma_keyword_reg(uint32_t i2c_addr, uint8_t udma_addr_count);
void I2C_SoftwareResetCmd(RV_i2c_t *I2Cx, FunctionalState NewState);
void i2c_handler();

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
