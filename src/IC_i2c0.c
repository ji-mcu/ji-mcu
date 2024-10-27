/********************************** (C) COPYRIGHT  *******************************
 * File Name          : IC_i2c.c
 * Author             : haung jin
 * Version            : V0.1
 * Date               : 2024/10/2
 * Description        : This file provides all the I2C firmware functions.
 *********************************************************************************
 *******************************************************************************/
#include "IC_i2c.h"


/* I2C UDAM ADDR*/
#define I2C_START_ADDR (uint32_t)0x1c040000
#define I2C_END_ADDR   (uint32_t)0x1c040100

/* I2C START mask */
#define CTLR1_START_Set ((uint8_t)0x01)
#define CTLR1_START_Reset ((uint8_t)0xFB)

/* I2C STOP mask */
#define CTLR1_STOP_Set ((uint8_t)0x20)
#define CTLR1_STOP_Reset ((uint8_t)0xFB)

/* I2C ACK mask */
#define CTLR1_ACK_Set ((uint8_t)0x40)
#define CTLR1_ACK_Reset ((uint8_t)0xFB)

/* I2C SWRST mask */
#define CTLR1_SWRST_Set ((uint8_t)0x80)
#define CTLR1_SWRST_Reset ((uint8_t)0xFB)

/* I2C registers Masks */
#define CTLR1_CLEAR_Mask ((uint8_t)0xFB)

/* I2C ADD0 mask */
#define OADDR1_ADD0_Set ((uint8_t)0x0001)
#define OADDR1_ADD0_Reset ((uint8_t)0xFFFE)

/* I2C CCR mask */
#define CKCFGR_CCR_Set ((uint16_t)0x0FFF)



/* I2C Interrupt Enable mask */
#define ITEN_Mask ((uint32_t)0x07000000)


/*********************************************************************
 * @fn      I2C_Init
 *
 * @brief   Initializes the I2Cx peripheral according to the specified
 *        parameters in the I2C_InitStruct.
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          I2C_InitStruct - pointer to a I2C_InitTypeDef structure that
 *        contains the configuration information for the specified I2C peripheral.
 *
 * @return  none
 */
void I2C_Init(RV_i2c_t *I2Cx, I2C_InitTypeDef *I2C_InitStruct , I2C_Ptr *I2C_px)
{
    uint16_t tmpreg = 0, freqrange = 0;

    uint16_t i=0;
    uint16_t result = 0x04;
    uint32_t pclk1 = 64000000/2;//nomal is 64M

    RCC_ClocksTypeDef rcc_clocks;

    // if (I2C_InitStruct->I2C_Mode == I2C_Mode_Slave)
    // {
    // I2C_Ptr *udma_rx_ptr1 = (I2C_Ptr *)(I2C_InitStruct->I2C_rx_addr); // select i2c's data base addr in sram
    // }
    // else{
    // I2C_Ptr *udma_tx_ptr2 = (I2C_Ptr *)(I2C_InitStruct->I2C_tx_addr);
    // }
    // RCC_GetClocksFreq(&rcc_clocks);//
    // pclk1 = rcc_clocks.PCLK1_Frequency;
    I2Cx->i2c_rx_addr = I2C_InitStruct->I2C_rx_addr;
    I2Cx->i2c_tx_addr = I2C_InitStruct->I2C_tx_addr;

    I2C_px->i2c_data_reg[0] = (uint8_t)I2C_CMD_START;
    I2C_px->i2c_data_reg[1] = (uint8_t)I2C_CMD_CFG;

    freqrange = (uint16_t)(pclk1 / I2C_InitStruct->I2C_ClockSpeed); // Fsys/2/Baudrate
    // select baudrate as 100KHz
    tmpreg = freqrange >> 8;
    I2C_px->i2c_data_reg[2] = tmpreg;
    tmpreg = freqrange ;
    I2C_px->i2c_data_reg[3] = tmpreg;
    I2C_px->i2c_data_reg[4] = I2C_CMD_RPT;
    // I2C_TX_Ptr =
    tmpreg = I2Cx->i2c_status;

    while (tmpreg!=0)
    {
        tmpreg = I2Cx->i2c_status;
    }
    
    tmpreg = 0;

}

/*********************************************************************
 * @fn      I2C_StructInit
 *
 * @brief   Fills each I2C_InitStruct member with its default value.
 *
 * @param   I2C_InitStruct - pointer to an I2C_InitTypeDef structure which
 *        will be initialized.
 *
 * @return  none
 */
void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct)
{
    I2C_InitStruct->I2C_ClockSpeed = 5000;
    I2C_InitStruct->I2C_Mode = I2C_Mode_Master;
    I2C_InitStruct->I2C_OwnAddress1 = 0;
    I2C_InitStruct->I2C_rx_addr = RV_Udma_I2C_RX_ADDR;
    I2C_InitStruct->I2C_tx_addr = RV_Udma_I2C_TX_ADDR;

}

/*********************************************************************
 * @fn      I2C_Cmd
 *
 * @brief   control I2c read or write funtion and read or write byte numbers
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          NewState - ENABLE or DISABLE.
 *
 * @return  none
 */
void I2C_Cmd(RV_i2c_t *I2Cx, uint8_t data_num, uint32_t i2c_addr, Function Newfunction, FunctionalState NewState)
{
    if (NewState !=DISABLE){
        if (Newfunction == WRITE) // write
        {
            I2Cx->i2c_tx_addr = i2c_addr;
            I2Cx->i2c_tx_szie = data_num;
            I2Cx->i2c_tx_cfg |= I2C_Direction_Transmitter; 
        }
        else if(Newfunction== READ)// read
        {
            I2Cx->i2c_rx_addr = i2c_addr;
            I2Cx->i2c_rx_szie = data_num;
            I2Cx->i2c_rx_cfg  |= I2C_Direction_Receiver;
        }
        else if(Newfunction == Continuous)
        {
            I2Cx->i2c_rx_cfg |= I2C_continous;
            I2Cx->i2c_tx_cfg |= I2C_continous;
        }
    }
    else {
        I2Cx->i2c_tx_cfg = 0 ;
        I2Cx->i2c_rx_cfg = 0 ;

    }

}

/*********************************************************************
 * @fn      I2C_GenerateSTART
 *
 * @brief   Generates I2Cx communication START condition.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          NewState - ENABLE or DISABLE.
 *
 * @return  none
 */
void I2C_GenerateSTART(I2C_Ptr *I2C_px, uint8_t udma_addr_count, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2C_px->i2c_data_reg[udma_addr_count] &= CTLR1_START_Set;//0x01
    }
    else
    {
        I2C_px->i2c_data_reg[udma_addr_count] |= CTLR1_START_Reset;//0xff
    }
}

/*********************************************************************
 * @fn      I2C_GenerateSTOP
 *
 * @brief   Generates I2Cx communication STOP condition.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          NewState - ENABLE or DISABLE.
 *
 * @return  none
 */
void I2C_GenerateSTOP(I2C_Ptr *I2C_px, uint8_t udma_addr_count, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2C_px->i2c_data_reg[udma_addr_count] |= CTLR1_STOP_Set; // 0x20
    }
    else
    {
        I2C_px->i2c_data_reg[udma_addr_count] &= CTLR1_STOP_Reset; // 0xff
    }
}

/*********************************************************************
 * @fn      I2C_AcknowledgeConfig
 *
 * @brief   Enables or disables the specified I2C acknowledge feature.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          NewState - ENABLE or DISABLE.
 *
 * @return  none
 */
void I2C_AcknowledgeConfig(I2C_Ptr *I2C_px, uint8_t udma_addr_count, FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        I2C_px->i2c_data_reg[udma_addr_count] |= CTLR1_ACK_Set; // 0x20
    }
    else
    {
        I2C_px->i2c_data_reg[udma_addr_count] &= CTLR1_ACK_Reset; // 0xff
    }
}

/*********************************************************************
 * @fn      I2C_OwnAddress2Config
 *
 * @brief   Configures the specified I2C own address2.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          Address - specifies the 7bit I2C own address2.
 *
 * @return  none
 */
void I2C_OwnAddress2Config(RV_i2c_t *I2Cx, uint8_t Address)
{
//     uint16_t tmpreg = 0;

//     tmpreg = I2Cx->OADDR2;
//     tmpreg &= OADDR2_ADD2_Reset;
//     tmpreg |= (uint16_t)((uint16_t)Address & (uint16_t)0x00FE);
//     I2Cx->OADDR2 = tmpreg;
}



/*********************************************************************
 * @fn      I2C_ITConfig
 *
 * @brief   Enables or disables the specified I2C interrupts.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          I2C_IT - specifies the I2C interrupts sources to be enabled or disabled.
 *            I2C_IT_BUF - Buffer interrupt mask.
 *            I2C_IT_EVT - Event interrupt mask.
 *            I2C_IT_ERR - Error interrupt mask.
 *          NewState - ENABLE or DISABLE.
 *
 * @return  none
 */
void I2C_ITConfig(RV_i2c_t *I2Cx, uint16_t I2C_IT, FunctionalState NewState)
{
    // if (NewState != DISABLE)
    // {
    //     I2Cx->CTLR2 |= I2C_IT;
    // }
    // else
    // {
    //     I2Cx->CTLR2 &= (uint16_t)~I2C_IT;
    // }
}

/*********************************************************************
 * @fn      I2C_SendData
 *
 * @brief   Sends some data byte through the I2Cx peripheral.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          Data - Byte to be transmitted.
 *
 * @return  none
 */
void I2C_SendData(RV_i2c_t *I2Cx, I2C_Ptr *I2C_px, uint8_t udma_addr_count,uint8_t *Data,uint8_t sizeof_data)
{

    uint8_t i=0;
    uint8_t temp=udma_addr_count+ 3 ;
    I2C_px->i2c_data_reg[udma_addr_count] = I2C_CMD_RPT;
    I2C_px->i2c_data_reg[udma_addr_count + 1] = sizeof_data;
    I2C_px->i2c_data_reg[udma_addr_count + 2] = I2C_CMD_WR;

    for (i = 0; i < sizeof_data ; i++)
    {
        /* code */
        I2C_px->i2c_data_reg[temp+i]=Data[i];
    }
}

/*********************************************************************
 * @fn      I2C_ReceiveData
 *
 * @brief   Returns the most recent received data by the I2Cx peripheral.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *
 * @return  The value of the received data.
 */
uint8_t I2C_ReceiveData(RV_i2c_t *I2Cx, I2C_Ptr *I2C_px, uint8_t udma_addr_count, uint8_t sizeof_data)
{
    uint8_t i = 0;
    uint8_t temp = udma_addr_count + 3;
    uint8_t Data[256-1] = {0};
    I2C_px->i2c_data_reg[udma_addr_count] = I2C_CMD_RPT;
    I2C_px->i2c_data_reg[udma_addr_count + 1] = sizeof_data;
    I2C_px->i2c_data_reg[udma_addr_count + 2] = I2C_CMD_RD_ACK;//in here ack=0 is true state
    for (i = 0; i < sizeof_data; i++)
    {
        /* code */
        Data[i] = I2C_px->i2c_data_reg[temp + i] ;
    }
    return (uint8_t)*Data;
}

/*********************************************************************
 * @fn      I2C_Send7bitAddress
 *
 * @brief   Transmits the address byte to select the slave device.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          Address - specifies the slave address which will be transmitted.
 *          I2C_Direction - specifies whether the I2C device will be a
 *        Transmitter or a Receiver.
 *            I2C_Direction_Transmitter - Transmitter mode.
 *            I2C_Direction_Receiver - Receiver mode.
 *
 * @return  none
 */
void I2C_Send7bitAddress(RV_i2c_t *I2Cx, uint8_t Address, uint8_t I2C_Direction)
{
    // if (I2C_Direction != I2C_Direction_Transmitter)
    // {
    //     Address |= OADDR1_ADD0_Set;
    // }
    // else
    // {
    //     Address &= OADDR1_ADD0_Reset;
    // }

    // I2Cx->DATAR = Address;
}

/*********************************************************************
 * @fn      I2C_ReadRegister
 *
 * @brief   Reads the specified I2C register and returns its value.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          I2C_Register - specifies the register to read.
 *            i2c_rx_addr ;//0x00
 *            i2c_rx_szie;//0x04
 *            i2c_rx_cfg ;//0x08
 *            rx_reserve ;//0x0c
 *            i2c_tx_addr;//0x10
 *            i2c_tx_szie;//0x14
 *            i2c_tx_cfg;//0x18
 *            tx_reserve;//0x1c
 *            i2c_status;//0x20
 *            i2c_setup;//0x24
 *
 * @return  none
 */
uint16_t I2C_ReadRegister(RV_i2c_t *I2Cx, uint8_t I2C_Register)
{
    __IO uint32_t tmp = 0;

    tmp = (uint32_t)I2Cx;
    tmp += I2C_Register;

    return (*(__IO uint16_t *)tmp);
}

/*********************************************************************
 * @fn      I2C_udma_keyword_reg *
 *
 * @brief   Reads the specified I2C_udma_keyword_register and returns its value.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          I2C_Register - specifies the register to read.
 *            I2C_CMD_START       (uint8_t)0x00
 *            I2C_CMD_STOP        (uint8_t)0x20
 *            I2C_CMD_RD_ACK      (uint8_t)0x40
 *            I2C_CMD_RD_NACK     (uint8_t)0x60
 *            I2C_CMD_WR          (uint8_t)0x80
 *            I2C_CMD_WAIT        (uint8_t)0xA0
 *            I2C_CMD_RPT         (uint8_t)0xC0
 *            I2C_CMD_CFG         (uint8_t)0xE0
 *            I2C_CMD_WAIT_EV     (uint8_t)0x10
 *
 * @return  none
 */
uint32_t I2C_udma_keyword_reg(uint32_t i2c_addr, uint8_t udma_addr_count)
{
    __IO uint32_t tmp = 0;

    tmp = (uint32_t)i2c_addr;
    tmp += udma_addr_count;

    return (*(__IO uint32_t *)tmp);
}

/*********************************************************************
 * @fn      I2C_SoftwareResetCmd
 *
 * @brief   Enables or disables the specified I2C software reset.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          NewState - ENABLE or DISABLE.
 *
 * @return  none
 */
void I2C_SoftwareResetCmd(RV_i2c_t *I2Cx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        I2Cx->i2c_setup |= I2C_SW_Enable;
    }
    else
    {
        I2Cx->i2c_setup |= I2C_SW_Disable;
    }
}


/*********************************************************************
 * @fn      I2C_CheckEvent
 *
 * @brief   Checks whether the last I2Cx Event is equal to the one passed
 *        as parameter.
 *
 * @param   I2Cx- where x can be 1 or 2 to select the I2C peripheral.
 *          I2C_EVENT: specifies the event to be checked.

 * @return  ErrorStatus - READY or NoREADY.
 */
ErrorStatus I2C_CheckEvent(RV_i2c_t *I2Cx, uint32_t I2C_EVENT)
{
    uint32_t lastevent = 0;
    uint32_t flag1 = 0, flag2 = 0;
    ErrorStatus status = NoREADY;

    // flag1 = I2Cx->STAR1;
    // flag2 = I2Cx->STAR2;
    // flag2 = flag2 << 16;

    // lastevent = (flag1 | flag2) & FLAG_Mask;

    // if ((lastevent & I2C_EVENT) == I2C_EVENT)
    // {
    //     status = READY;
    // }
    // else
    // {
    //     status = NoREADY;
    // }

    return status;
}

/*********************************************************************
 * @fn      I2C_GetLastEvent
 *
 * @brief   Returns the last I2Cx Event.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *
 * @return  none
 */
uint32_t I2C_GetLastEvent(RV_i2c_t *I2Cx)
{
    uint32_t lastevent = 0;
    uint32_t flag1 = 0, flag2 = 0;

    // flag1 = I2Cx->STAR1;
    // flag2 = I2Cx->STAR2;
    // flag2 = flag2 << 16;
    // lastevent = (flag1 | flag2) & FLAG_Mask;

    return lastevent;
}

/*********************************************************************
 * @fn      I2C_GetFlagStatus
 *
 * @brief   Checks whether the last I2Cx Event is equal to the one passed
 *        as parameter.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          I2C_FLAG - specifies the flag to check.
 *            I2C_FLAG_GENCALL - General call header flag (Slave mode).
 *            I2C_FLAG_BUSY - Bus busy flag.
 *            I2C_FLAG_ADDR - Address sent flag (Master mode) "ADSL" *
 * @return  FlagStatus - SET or RESET.
 */
FlagStatus I2C_GetFlagStatus(RV_i2c_t *I2Cx, uint32_t I2C_FLAG)
{
    FlagStatus bitstatus = RESET;
    __IO uint32_t i2creg = 0, i2cxbase = 0;

    // i2cxbase = (uint32_t)I2Cx;
    // i2creg = I2C_FLAG >> 28;
    // I2C_FLAG &= FLAG_Mask;

    // if (i2creg != 0)
    // {
    //     i2cxbase += 0x14;
    // }
    // else
    // {
    //     I2C_FLAG = (uint32_t)(I2C_FLAG >> 16);
    //     i2cxbase += 0x18;
    // }

    // if (((*(__IO uint32_t *)i2cxbase) & I2C_FLAG) != (uint32_t)RESET)
    // {
    //     bitstatus = SET;
    // }
    // else
    // {
    //     bitstatus = RESET;
    // }

    return bitstatus;
}

/*********************************************************************
 * @fn      I2C_ClearFlag
 *
 * @brief   Clears the I2Cx's pending flags.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          I2C_FLAG - specifies the flag to clear.
 *            I2C_FLAG_TIMEOUT - Timeout or Tlow error flag.
 *          Note-
 *           - ADDR (Address sent) is cleared by software sequence: a read operation to
 *             I2C_SATR1 register (I2C_GetFlagStatus()) followed by a read operation to
 *             I2C_SATR2 register ((void)(I2Cx->SR2)).
 *           - SB (Start Bit) is cleared software sequence: a read operation to I2C_STAR1
 *             register (I2C_GetFlagStatus()) followed by a write operation to I2C_DATAR
 *             register  (I2C_SendData()).
 * @return  none
 */
void I2C_ClearFlag(RV_i2c_t *I2Cx, uint32_t I2C_FLAG)
{
    uint32_t flagpos = 0;

    // flagpos = I2C_FLAG & FLAG_Mask;
    // I2Cx->STAR1 = (uint16_t)~flagpos;
}

/*********************************************************************
 * @fn      I2C_GetITStatus
 *
 * @brief   Checks whether the specified I2C interrupt has occurred or not.
 *
 * @param   I2Cx - where x can be 1 or 2 to select the I2C peripheral.
 *          II2C_IT - specifies the interrupt source to check.
=
 *            I2C_IT_TIMEOUT - Timeout or Tlow error flag.
 *            I2C_IT_TXE - Data register empty flag (Transmitter).
 *            I2C_IT_RXNE - Data register not empty (Receiver) flag.
 *            I2C_IT_STOPF - Stop detection flag (Slave mode).

 *            I2C_IT_ADDR - Address sent flag (Master mode) "ADSL"  Address matched
 * @return  none
 */
ITStatus I2C_GetITStatus(RV_i2c_t *I2Cx, uint32_t I2C_IT)
{
    ITStatus bitstatus = RESET;
    uint32_t enablestatus = 0;

    // enablestatus = (uint32_t)(((I2C_IT & ITEN_Mask) >> 16) & (I2Cx->CTLR2));
    // I2C_IT &= FLAG_Mask;

    // if (((I2Cx->STAR1 & I2C_IT) != (uint32_t)RESET) && enablestatus)
    // {
    //     bitstatus = SET;
    // }
    // else
    // {
    //     bitstatus = RESET;
    // }

    return bitstatus;
}

