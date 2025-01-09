#include "test_example.h"
// #include "i2s-0.h"


void gpio_test()
{
    PAD_MUX_FUN0( FUN_GPIO3 | FUN_GPIO1, ENABLE);
    // pulp_write32(0x1A101010, 1 << 0 | 1 << 2);
    // pulp_write32(0x1A101014, 0x0);
    // mDelaymS(1000);
    GPIOA_ModeCfg(GPIO_Pin_3 | GPIO_Pin_1, GPIO_ModeOut);
    GPIOA_SetBits(GPIO_Pin_3 | GPIO_Pin_1);

    while (1)
    {
        DelayMs(1);
        GPIOA_ResetBits(GPIO_Pin_3 | GPIO_Pin_1);
        DelayMs(1);
        GPIOA_SetBits(GPIO_Pin_3 | GPIO_Pin_1);
        // DelayUs(100);
        /* code */
    }
}

void pwm_test()
{
    uint16_t pwm_hi = 0;
    uint16_t pwm_lo = 0;
    PWMX_CLKCfg(255); // PWM的基准频率
    //
    pwm_hi = PWMX_CycleCfg(PWMX_Cycle_12);
    pwm_lo = pwm_hi / 8;
    PWMX_ACTOUT(CH_PWM0 , pwm_hi, pwm_lo, ENABLE);
    // while(1);
}

void uart_test()
{
    uint8_t buf[8]={0x11,0x22,0x33,0x44,0x55,0x66,0x77};
    Uart_InitTypeDef uart_InitStruct = {0};
    uart_StructInit(&uart_InitStruct);
    UART0_DefInit(&uart_InitStruct);
    UART0_SendString(buf, 8);
    while (1)
    {

        soc_printf("hello,world\n");
        UART0_SendString(buf,12);
        // UART0_SendByte(0x11);
        soc_printf("8");
    }
}

void timer_test()
{

    uint32_t i;
    uint32_t j;
    TIM_InitTypeDef TIM_InitStructure = {0};
    PAD_MUX_FUN0(FUN_GPIO2 , ENABLE);

    GPIOA_ModeCfg(GPIO_Pin_2, GPIO_ModeOut);

    TIM_StructInit(&TIM_InitStructure);
    TMR_TimerInit(&TIM_InitStructure, cfg_lo);

    while (1)
    {
        i = R32_timer0_cnt_lo;
        // j=TIM_GetCounter(cfg_hi);
        if (i >(16000/2))
        {

            GPIOA_SetBits(GPIO_Pin_2);
        }
        else
        {
            GPIOA_ResetBits(GPIO_Pin_2);
        }

    }
}

void i2c_test()
{
    uint32_t i=0;
    uint8_t send_buf[2] = {0x40,0x55};

    I2C_InitTypeDef I2C_InitStructure = {0};
    I2C_InitStructure.I2C_ClockSpeed = Standard_Mode;
    I2C_InitStructure.I2C_bytes = 0x08;
    I2C_InitStructure.I2C_Direction = I2C_CMD_WR;
    I2C_InitStructure.I2C_Device_addr = 0x70;
    I2C_InitStructure.I2C_OwnAddress1 = 0;
    // mDelayuS(50);
    I2C_Init(&I2C_InitStructure);
    udma_i2c_data->i2c_data[0]=0x78;
    udma_i2c_data->i2c_data[1]=0x40;
    udma_i2c_data->i2c_data[2] = 0x11;
    udma_i2c_data->i2c_data[3] = 0x22;
    udma_i2c_data->i2c_data[4] = 0x33;
    udma_i2c_data->i2c_data[5] = 0x44;
    udma_i2c_data->i2c_data[6] = 0x55;
    udma_i2c_data->i2c_data[7] = 0x66;
    udma_i2c_data->i2c_data[8] = I2C_CMD_STOP;
    while (1)
    {
        // for(;i<100;i++)
            I2C_SendData(RV_PERI_I2C0_ADDR, RV_Udma_I2C_DATA_ADDR,8);

            // mDelaymS(200);
    }
}

void lin_test()
{
    uint8_t send_buf[8] = {0x3d, 0x11, 0x55, 0xef, 0xac, 0x78, 0x31, 0x8a}; // 定义一个无符号字符数组send_buf，并初始化为8个字节的值
    uint32_t i;                                                             // 定义一个无符号长整型变量i
    LIN_init();               // 初始化LIN通信模块

    // LIN_send(0x31, send_buf); // 使用LIN通信发送数据，0x31是标识符，send_buf是要发送的数据

    printf(" point0\n");
    while (1)
    {
        printf(" point0\n");
        LIN_send(0x31, send_buf); // 在无限循环中发送数据，标识符为0x31，数据为send_buf
        // LIN_send_head(0x31);      // 发送LIN通信的头部，标识符为0x31
        // DelayMs(500);
        // printf(" point1\n");
        // while ((Lin_CSR & 0x8)==0); // 等待直到Lin_CSR 寄存器的第3位（从0开始计数）被设置（等待发送缓冲区空）

        // while ((Lin_CSR & 0x10)==0);   // 等待直到Lin_CSR寄存器的第4位被设置（等待发送完成）

        // Lin_CR &= (~(0x1)); // 清除Lin_CR寄存器的第0位（停止发送）
    }
}





// 验证I2S传输和接收
void i2s_test()
{
    // i2s_init1();
    udma_spi_data->spi_data[0] = 0x11223344;
    udma_spi_data->spi_data[1] = 0x55667788;
    udma_spi_data->spi_data[2] = 0x99aabbcc;
    udma_spi_data->spi_data[3] = 0xddeeff11;


    // i2s_init();
    i2s_set_tx_cfg(0b111,1,1,1);
    i2s_set_tx_address(RV_Udma_SPI_DATA_ADDR); // tx saddr
    i2s_set_tx_size(31);                        // tx size
    i2s_set_mode(1);                           // tx mode
    

    i2s_set_tx_cfg0_setup(0b111, 1, 127, 4); // cfg0_setup - clk_en, clk_dev, bits_word
    I2S1->RX_EXT_SETUP = 32;
    i2s_set_chmode__ch_mode_0(0b00); // chmode - ch_mode_0
    I2S1->RX_CHMOD |= (1 << 4);
    i2s_set_tx_address(RV_Udma_SPI_DATA_ADDR); // tx saddr
    i2s_set_tx_size(31);                      // tx size
    // i2s_set_mode(1);                          // tx mode
    // pulp_write32(PERI_I2S0_TX_SADDR_ADDR, RV_Udma_SPI_DATA_ADDR); // 0x10);
    // pulp_write32(PERI_I2S0_TX_SIZE_ADDR, 128);                   // 0x02);
    // pulp_write32(PERI_I2S0_TX_SETUP_ADDR, 1 << 0);
    // pulp_write32(PERI_I2S0_RX_CFG_SETUP_ADDR, (8 << 16) | (1 << 8) | (15 << 0)); // div<<16 div_en<<8
    // pulp_write32(PERI_I2S0_RX_MODE_ADDR, (1 << 4));
    DelayMs(200);

    while (1)
    {
        DelayMs(200);

        i2s_set_tx_address(RV_Udma_SPI_DATA_ADDR); // tx saddr
        // DelayMs(200);
        i2s_set_tx_size(31); // tx size
        // DelayMs(200);
        // i2s_start_tx(); // tx cfg - tx_en
        I2S1->TX0_CFG |= (1 << 4);
        // I2S1->RX0_CFG |= (1 << 4);
        // pulp_write32(PERI_I2S0_TX_SADDR_ADDR, RV_Udma_SPI_DATA_ADDR); // 0x10);
        // pulp_write32(PERI_I2S0_TX_SIZE_ADDR, 128);
        // pulp_write32(PERI_I2S0_TX_CFG_ADDR, 1 << 4);

        // printf(" point0\n");
    }
}



void spi_test()
{

    udma_spi_data->spi_data[0] = 0x11223344;
    udma_spi_data->spi_data[1] = 0x55667788;
    udma_spi_data->spi_data[2] = 0x99aabbcc;
    udma_spi_data->spi_data[3] = 0xddeeff11;

    spim_cmd_init();
   
    while(1){
        spim_send_data(RV_PERI_SPI1_ADDR, RV_Udma_SPI_DATA_ADDR);
    }
}





// void soc_event_test()
// {
//     uint32_t i = 0;

//     TIM_InitTypeDef TIM_InitStructure = {0};

//     TIM_StructInit(&TIM_InitStructure);
//     TMR_TimerInit(&TIM_InitStructure, cfg_lo);

//     // int_init();
//     // hal_itc_enable_set(1 << 10);
//     // hal_itc_enable_set(1 << 8);
//     udma_spi_data->spi_data[0] = 0x11223344;
//     udma_spi_data->spi_data[1] = 0x55667788;
//     udma_spi_data->spi_data[2] = 0x99aabbcc;
//     udma_spi_data->spi_data[3] = 0xddeeff11;

//     spim_cmd_init();
//     // soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_SPIM0_EOT);
//     soc_eu_fcEventMask_setEvent1(6);
//     soc_eu_fcEventMask_setEvent1(9);

//     while (1)
//     {

//         spim_send_data1(RV_PERI_SPI1_ADDR, RV_Udma_SPI_DATA_ADDR);
//     }
// }

// void int_test()
// {
//     uint32_t i=0;
//     __IO uint32_t k;

//     TIM_InitTypeDef TIM_InitStructure = {0};

//     PAD_MUX_FUN0(FUN_GPIO3|FUN_GPIO2 | FUN_GPIO1, ENABLE);
//     GPIOA_ModeCfg(GPIO_Pin_3|GPIO_Pin_2|GPIO_Pin_1, GPIO_ModeOut);


//     // GPIOA_ModeCfg(GPIO_Pin_1, GPIO_ModeIN);

//     // GPIOA_ITModeCfg(GPIO_Pin_1, GPIO_ITMode_FallEdge);
//     (*((PUINT32V)0x1A10000C)) = GPIO_Pin_1;

//     GPIOA_SetBits(GPIO_Pin_2);
//     GPIOA_ResetBits(GPIO_Pin_3);

//     TIM_StructInit(&TIM_InitStructure);
//     TMR_TimerInit(&TIM_InitStructure, cfg_lo);

//     // int_init();
//     // int_enable_set(1 << 10);
//     // int_ack_set(0xf<< 8);

//     int_enable_set(1 << 15);
//     // int_status_set(1<< 15);

//     // int_enable_set(1 << 9);
//     while (1)   
//     {
//         if (flag0 > 0) 
//         {
//              GPIOA_ResetBits(GPIO_Pin_2);
//             flag0=0;

//             // soc_printf("j=%x",j);
//         }
//         else if(flag0==0)
//         {
//             GPIOA_SetBits(GPIO_Pin_2);
//             // soc_printf("j=%x", j);
//             wait_event(15); 
//         }
//         else ;
//     }
// }

