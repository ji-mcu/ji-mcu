#include <stdio.h>
#include <stdint.h>
#include "i2s_1.h"

void i2s_init1()
{
    // 将所有配置寄存器初始化为0
    I2S1->RX0_SADDR = 0x00;
    I2S1->RX0_SIZE = 0x00;
    I2S1->RX0_CFG = 0x00;
    I2S1->RX1_SADDR = 0x00;
    I2S1->RX1_SIZE = 0x04;
    I2S1->RX1_CFG = 0x00;
    I2S1->TX0_SADDR = 0x00;
    I2S1->TX0_SIZE = 0x04;
    I2S1->TX0_CFG = 0x00;
    I2S1->TX0_SETUP = 0x00;
}

// 设置接收数据的起始地址
void i2s_set_rx_address(uint32_t addr)
{
    I2S1->RX0_SADDR = addr;
}

// 设置接收数据的长度
void i2s_set_rx_size(uint32_t size)
{
    I2S1->RX0_SIZE = size;
}

// 开始接收数据传输
void i2s_start_rx()
{
    I2S1->RX0_CFG |= (1 << 4); // 设置RX0_CFG寄存器的第4位为1，开始传输
}

// 设置发送数据的起始地址
void i2s_set_tx_address(uint32_t addr)
{
    I2S1->TX0_SADDR = addr;
}

// 设置发送数据的长度
void i2s_set_tx_size(uint32_t size)
{
    I2S1->TX0_SIZE = size;
}

// 开始发送数据传输
void i2s_start_tx()
{   
    uint32_t tmp = 0;
    while (1)
    {
        tmp = I2S1->TX0_CFG;
        if ((tmp << 5 )& 0b1)
        {   
            // 如果pending为1，则设置发送位
            I2S1->TX0_CFG |= (1 << 4); // 设置TX0_CFG寄存器的第4位为1，开始传输
            break;
        }
        else break;
    }
}

// 设置I2S模式：0为接收模式，1为发送模式
void i2s_set_mode1(int mode)
{
    if (mode == 0)
    {
        I2S1->TX0_SETUP &= ~1; // 清除第0位，启用接收模式
    }
    else
    {
        I2S1->TX0_SETUP |= 1; // 设置第0位，启用发送模式
    }
}

void i2s_set_tx_cfg0_setup(int sel, int clk_en, uint16_t clk_dev, uint8_t bits_word)
{
    uint32_t wdata = 0;
    if (sel & 0b001)
    {
        if (clk_en) wdata |= (1 << 8);
        else        wdata &= ~(1 << 8);
    }
    if (sel & 0b010)
    {
        wdata &= 0x0000FFFF;
        wdata |= (clk_dev << 16);
    }
    if (sel & 0b100)
    {
        wdata &= 0xFFFFFFE0;
        wdata |= (bits_word & 0x1F);
    }

    I2S1->RX_CFG0_SETUP |= wdata;
}

void i2s_set_chmode__ch_mode_0(int ch_mode_0)
{
    switch (ch_mode_0) {
        // case 0: I2S->RX_CHMOD &= (~(3 << 24) | (1 << 4)); break;
        // case 1: I2S->RX_CHMOD |= ((1 << 24) | (1 << 4)); break;
        // case 2: I2S->RX_CHMOD |= ((2 << 24) | (1 << 4)); break;
        // case 3: I2S->RX_CHMOD |= ((3 << 24) | (1 << 4)); break;
        case 0: I2S1->RX_CHMOD &= (~(3 << 24)); break;
        case 1: I2S1->RX_CHMOD |= (1 << 24); break;
        case 2: I2S1->RX_CHMOD |= (2 << 24); break;
        case 3: I2S1->RX_CHMOD |= (3 << 24); break;
    }
}

void i2s_set_tx_cfg(int sel, int tx_clr, int tx_en, int tx_continuous)
{
    uint32_t wdata = 0;
    if (sel & 0b001)
    {
        if (tx_clr) wdata |= (1 << 5);
        else        wdata &= ~(1 << 5);
    }
    if (sel & 0b010)
    {
        if (tx_en) wdata |= (1 << 4);
        else       wdata &= ~(1 << 4);
    }
    if (sel & 0b100)
    {
        if (tx_continuous) wdata |= (1 << 0);
        else              wdata &= ~(1 << 0);
    }
    I2S1->TX0_CFG |= wdata;
}


