/********************************** (C) COPYRIGHT  *******************************
 * File Name          : IC_udma.h
 * Author             : huang jin
 * Version            : V0.0
 * Date               : 2024/09/21
 * Description        : 为udma外设提供统一接口
 *******************************************************************************/
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "core_sys.h"


#define UDMA_DATA_OFFSET_32 0x20
#define UDMA_CMD_OFFSET_32  0x00
#define UDMA_CMD_OFFSET     0x10

#define UDMA_RX_OFFSET      0x00
#define UDMA_TX_OFFSET      0x10
#define UDMA_CUSTOM_OFFSET  0x20
#define UDMA_SADDR_OFFSET   0x0

#define UDMA_SIZE_OFFSET    0x4
#define UDMA_CFG_OFFSET     0x8
#define UDMA_INTCFG_OFFSET  0xC

#define UDMA_STASUS_OFFSET  0x24
#define UDMA_SETUP_OFFSET   0x20

// Channel area size in log2
#define UDMA_SIZE_LOG2      4
#define UDMA_CFG_SHADOW_BIT (5)
#define UDMA_CFG_CLEAR_BIT  (5)
#define UDMA_CFG_EN_BIT     (4)
#define UDMA_CFG_SIZE_BIT   (1)
#define UDMA_CFG_CONT_BIT   (0)
#define UDMA_CFG_PENDING    (1 << UDMA_CFG_SHADOW_BIT) // Indicates if a shadow transfer is there
#define UDMA_CFG_CLEAR      (1 << UDMA_CFG_CLEAR_BIT)   // Stop and clear all pending transfers
#define UDMA_CFG_EN         (1 << UDMA_CFG_EN_BIT   )         // Start a transfer
#define UDMA_CFG_SIZE_8     (0 << UDMA_CFG_SIZE_BIT)   // Configure for 8-bits transfer
#define UDMA_CFG_SIZE_16    (1 << UDMA_CFG_SIZE_BIT)  // Configure for 16-bits transfer
#define UDMA_CFG_SIZE_32    (2 << UDMA_CFG_SIZE_BIT)  // Configure for 32-bits transfer
#define UDMA_CFG_CONT       (1 << UDMA_CFG_CONT_BIT)     // Configure for continuous mode

    // UDMA RX/TX Channels HAL Registers Structure
// typedef struct
// {
//     uint32_t rx_ch_saddr;
//     uint32_t rx_ch_size;
//     uint32_t rx_ch_cfg;
//     uint32_t rx_ch_initcfg_unused;
//     uint32_t tx_ch_saddr;
//     uint32_t tx_ch_size;
//     uint32_t tx_ch_cfg;
//     uint32_t tx_ch_initcfg_unused;
// } udma_periph_t;//定义了通用的udma外设结构

// static inline unsigned int hal_udma_channel_isTx(unsigned int addr)
// {
//     return (addr >> UDMA_SIZE_LOG2) & 1;
// }

// static inline int udma_canEn(uint32_t channelBase)
// {
//     //读取bit5是否为1,if((cfg&pending)==1 ）cycle ;else if((cfg&pending)==0)break;
//     //即当pengding== 0 允许使能 ；pending==1 不允许使能
//     //can use as while(!udma_canEn(base));
//     return !((*(__IO u32*)(channelBase+UDMA_CFG_OFFSET)) & UDMA_CFG_PENDING);
// }


// static inline void udma_en(uint32_t channelBase, uint32_t Addr, uint32_t size, uint8_t cfg)
// {
//     (*(__IO u32*)(channelBase+UDMA_SADDR_OFFSET))=Addr;
//     (*(__IO u32*)(channelBase+UDMA_SIZE_OFFSET)) =size;
//     (*(__IO u32*)(channelBase+UDMA_CFG_OFFSET))  =cfg | UDMA_CFG_EN;
// }

// static inline int udma_busy(uint32_t channelBase)
// {
//     return ((*(__IO u32 *)(channelBase + UDMA_CFG_OFFSET)) & UDMA_CFG_EN);
// }

// static inline void udma_clr(uint32_t channelBase, uint8_t cfg)
// {
//     (*(__IO u32 *)(channelBase + UDMA_CFG_OFFSET)) = cfg | UDMA_CFG_CLEAR;
// }

int udma_canEn(uint32_t channelBase);
void udma_en(uint32_t channelBase, uint32_t Addr, uint32_t size, uint8_t cfg);
int udma_busy(uint32_t channelBase);
void udma_clr(uint32_t channelBase, uint8_t cfg);
