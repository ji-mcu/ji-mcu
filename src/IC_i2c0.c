/********************************** (C) COPYRIGHT  *******************************
 * File Name          : IC_i2c.c
 * Author             : haung jin
 * Version            : V0.1
 * Date               : 2024/10/2
 * Description        : This file provides all the I2C firmware functions.
 *********************************************************************************
 *******************************************************************************/
#include "IC_i2c.h"
#include "soc_printf.h"
#include "IC_udma.h"

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
 * @brief   
 * @param   
 * @return  none
 */
void I2C_Init(I2C_InitTypeDef *I2C_InitStruct)
{
    uint16_t tmpreg = 0, freqrange = 0;

    uint16_t i=0;
    uint32_t pclk1 = (u32)TIM_CLOCK_64M*4/18;//nomal is 64M
    freqrange = (uint16_t)(pclk1 / I2C_InitStruct->I2C_ClockSpeed); // Fsys/2/Baudrate

    udma_i2c_cmd->cmd[0] = (uint8_t)I2C_CMD_START;
    udma_i2c_cmd->cmd[1] = (uint8_t)I2C_CMD_CFG;

    // freqrange = (uint32_t)0x0095 ; // Fsys/2/Baudrate
    // select baudrate as 100KHz
    tmpreg = freqrange >> 8;
    udma_i2c_cmd->cmd[2] = tmpreg;
    tmpreg = freqrange ;
    udma_i2c_cmd->cmd[3] = tmpreg;
    udma_i2c_cmd->cmd[4] = (uint8_t)I2C_CMD_RPT;
    udma_i2c_cmd->cmd[5] = I2C_InitStruct->I2C_bytes;
    
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
    I2C_InitStruct->I2C_ClockSpeed = Standard_Mode;
    I2C_InitStruct->I2C_bytes = 0x08;
    I2C_InitStruct->I2C_Direction = I2C_CMD_WR;
    I2C_InitStruct->I2C_Device_addr = 0x70;
    I2C_InitStruct->I2C_OwnAddress1 = 0;
}


void i2c_send_cmd(uint32_t baudrate, uint8_t data_num, uint32_t i2cbase, Function Newfunction)
{
    uint16_t tmpreg = 0, freqrange = 0;

    uint16_t cmd_num = 8;
    uint32_t addr = i2cbase + UDMA_TX_OFFSET;
    uint32_t pclk1 = (u32)TIM_CLOCK_64M * 4 / 18;                   // nomal is 64M
    freqrange = (uint16_t)(pclk1 / baudrate);                       // Fsys/2/Baudrate
    if (Newfunction == WRITE)
    {
        udma_i2c_data->cmd[0] = (uint8_t)I2C_CMD_START;
        udma_i2c_data->cmd[1] = (uint8_t)I2C_CMD_CFG;

        // freqrange = (uint32_t)0x0095 ; // Fsys/2/Baudrate
        // select baudrate as 100KHz
        tmpreg = freqrange >> 8;
        udma_i2c_data->cmd[2] = tmpreg;
        tmpreg = freqrange;
        udma_i2c_data->cmd[3] = tmpreg;
        udma_i2c_data->cmd[4] = I2C_CMD_RPT;
        udma_i2c_data->cmd[5] = data_num;
        udma_i2c_data->cmd[6] = I2C_CMD_WR;
        // udma_i2c_data->cmd[7] = 0;
    }
    else{
        udma_i2c_data->cmd[6] = I2C_CMD_RD_NACK;
        // udma_i2c_data->cmd[7] = I2C_CMD_STOP;
    }
    // udma_en(addr, RV_Udma_CMD_ADDR, cmd_num, UDMA_CFG_EN);

    // return cmd_num;
}
/*********************************************************************
 * @fn      I2C_get_status
 * @brief
 * @param   
 * @return  none
 */

uint8_t I2C_get_status(RV_i2c_t *I2Cx)
{
    uint8_t temp = 0;
    temp = I2Cx->i2c_status;

    return temp;
}

/*********************************************************************
 * @fn      I2C_busy
 * @brief
 * @param
 * @return  none
 */

uint8_t I2C_busy(RV_i2c_t *I2Cx)
{
    uint8_t temp = 0;
    temp = ((I2C_get_status(pad_i2c0) & I2C_FLAG_BUSY)==I2C_FLAG_BUSY)?1:0;

    return temp;
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
void I2C_SendData(uint32_t i2cbase, uint32_t u8Data, uint8_t data_num)
{
    uint8_t cmd_num=8;
    I2C_SoftwareResetCmd(pad_i2c0,ENABLE);
    // I2C_SoftwareResetCmd(pad_i2c0,DISABLE);
    uint32_t i2c_tx_addr = i2cbase + UDMA_TX_OFFSET;
    uint32_t badurate=Standard_Mode;
    i2c_send_cmd(badurate, data_num, i2cbase,WRITE);
    udma_en(i2c_tx_addr, u8Data, data_num+cmd_num, UDMA_CFG_EN);
    // while(!udma_canEn(i2c_tx_addr));
    // while (!(I2C_get_status(pad_i2c0) && I2C_FLAG_ack));
    // i2c_send_cmd(badurate, data_num, i2cbase, I2C_CMD_WR, DISABLE);
    // while(I2C_busy(pad_i2c0));



    // pulp_write(0x1a1041a4, 0);

    // pulp_write(0x1C040110, 0x0002E002);
    // pulp_write(0x1C040114, 0x448208C1);
    // pulp_write(0x1C040118, 0x88776655);
    // pulp_write(0x1C04011c, 0x21bbaa99);
    // pulp_write(0x1a104190, 0x1C040110);
    // pulp_write(0x1a104194, 0x10);
    // pulp_write(0x1a104198, 1 << 4);
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
void I2C_ReceiveData(uint32_t i2cbase,  uint32_t u8Data, uint8_t data_num)
{

    I2C_SoftwareResetCmd(pad_i2c0,ENABLE);
    I2C_SoftwareResetCmd(pad_i2c0,DISABLE);
    uint32_t i2c_rx_addr = i2cbase + UDMA_RX_OFFSET;
    uint32_t badurate=Standard_Mode;
    i2c_send_cmd(badurate, data_num, i2cbase, READ);
    udma_en(i2c_rx_addr, u8Data, data_num, UDMA_CFG_EN);
    // while(!udma_canEn(i2c_rx_addr));
    while ((I2C_get_status(pad_i2c0) &I2C_FLAG_data_store_req));
    i2c_send_cmd(badurate, data_num, i2cbase,READ);
    while(I2C_busy(pad_i2c0));

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
        I2Cx->i2c_setup = I2C_SW_Enable;
    }
    else
    {
        I2Cx->i2c_setup = I2C_SW_Disable;
    }
}

void i2c_handler()
{
    ;
}
