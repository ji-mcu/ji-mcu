
#include "IC_I2S.h"

// void i2s_init()
// {

//     // 将所有配置寄存器初始化

// }



// 设置I2S模式：0为接收模式，1为发送模式
void i2s_set_mode(I2S_TXMODE_TypeDef mode)
{
    if (mode != TX_mode) // RX mode
    {
        REG_I2S_TX_SETUP &= ~1; // 清除第0位，启用接收模式
    }
    else
    {
        REG_I2S_TX_SETUP |= 1; // 设置第0位，启用发送模式
    }
}
void i2s_setup(uint32_t clk_div,I2S_CLK_TypeDef clk_type ,FlagStatus Newstatus, FunctionalState Newstate)
{
    

    if(Newstate!=DISABLE)
    {

        i2s_cfg0_set(31,127,1);
        pulp_write32(0x1A104080 + 0x2c, (1 << 4));
        // pulp_write32(0x1A104080 + 0x24, (8 << 16) | (1 << 8) | (31 << 0));
        i2s_lsb_set(1);
        i2s_chmode_set(clk_type);
        // i2s_set_mode(1);
    }
    else
    {
        i2s_cfg0_set(0, 0, 0);
    }


}

void i2s_send_data(uint32_t Data,uint16_t size,uint8_t cfg,uint8_t tx_mode)
{
    i2s_setup(127,CFG_USE_CLK0,SET,ENABLE);
    i2s_tx_set(Data,size,cfg,tx_mode);
    // while(!i2s_tx_canEn());
    // while(i2s_tx_busy());
}

void i2s_receive_data(uint32_t Data, uint16_t size, uint8_t cfg)
{
    i2s_setup(127,CFG_USE_CLK0,SET,ENABLE);
    i2s_rx_set(Data,size,cfg);
    while(!i2s_rx_canEn());
    while(i2s_rx_busy());
}