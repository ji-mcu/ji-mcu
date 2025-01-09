#include "IC_udma.h"

int udma_canEn(uint32_t channelBase)
{
    // 读取bit5是否为1,if((cfg&pending)==1 ）cycle ;else if((cfg&pending)==0)break;
    // 即当pengding== 0 允许使能 ；pending==1 不允许使能
    // can use as while(!udma_canEn(base));
    return !((*(__IO u32 *)(channelBase + UDMA_CFG_OFFSET)) & UDMA_CFG_PENDING);
}

void udma_en(uint32_t channelBase, uint32_t Addr, uint32_t size, uint8_t cfg)
{
    (*(__IO u32 *)(channelBase + UDMA_SADDR_OFFSET)) = Addr;
    (*(__IO u32 *)(channelBase + UDMA_SIZE_OFFSET)) = size;
    (*(__IO u32 *)(channelBase + UDMA_CFG_OFFSET)) = cfg | UDMA_CFG_EN;
}

int udma_busy(uint32_t channelBase)
{
    return ((*(__IO u32 *)(channelBase + UDMA_CFG_OFFSET)) & UDMA_CFG_EN);
}

void udma_clr(uint32_t channelBase, uint8_t cfg)
{
    (*(__IO u32 *)(channelBase + UDMA_CFG_OFFSET)) = cfg | UDMA_CFG_CLEAR;
}