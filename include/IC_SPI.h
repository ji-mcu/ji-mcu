/********************************** (C) COPYRIGHT  *******************************
 * File Name          : IC_SPI.h
 * Author             : huang jin
 * Version            : V0.0
 * Date               : 2024/09/21
 * Description        : 包含i2c的所有库函数
 *******************************************************************************/
#ifndef __IC_SPI_H
#define __IC_SPI_H

#ifdef __cplusplus
extern "C"
{
#endif

// #include "soc_common.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "core_sys.h"
#include "IC_udma.h"
// #include "soc_event.h"
#include "core_riscv.h"
#include "archi/riscv/builtins_v2_emu.h"

// SPI commands IDS definition
typedef enum
{

  SPI_CMD_CFG_ID      = 0   ,  
  SPI_CMD_SOT_ID      = 1   ,  
  SPI_CMD_SEND_CMD_ID = 2   ,  
  SPI_CMD_SEND_ADDR_ID= 3   ,  
  SPI_CMD_DUMMY_ID    = 4   ,  
  SPI_CMD_WAIT_ID     = 5   ,  
  SPI_CMD_TX_DATA_ID  = 6   ,  
  SPI_CMD_RX_DATA_ID  = 7   ,  
  SPI_CMD_RPT_ID      = 8   ,  
  SPI_CMD_EOT_ID      = 9   ,  
  SPI_CMD_RPT_END_ID  = 10  ,
  SPI_CMD_RX_CHECK_ID = 11  ,
  SPI_CMD_FUL_ID      = 12  ,
  SPI_CMD_WAIT_CYC_ID = 13  ,

} SPI_CMD_ID;


 //同时收发 双工工作



// SPI command fields offset, mask, value definition
// SPI commands fields offsets
#define SPI_CMD_ID_OFFSET       28
#define SPI_CMD_ID_WIDTH         4

// COMMON definitions
#define SPI_CMD_QPI_ENA           1
#define SPI_CMD_QPI_DIS           0
#define SPI_CMD_DPI_ENA           1
#define SPI_CMD_DPI_DIS           0
#define SPI_CMD_BYTE_ALIGN_DIS    1
#define SPI_CMD_BYTE_ALIGN_ENA    0
#define SPI_CMD_DATA_WITDH(val)   (val)
#define SPI_CMD_CMD_SIZE(val)     (val)
#define SPI_CMD_BALIGN_OFFSET     26
#define SPI_CMD_DATA_SIZE_OFFSET  0
#define SPI_CMD_QPI_OFFSET        27
#define SPI_CMD_QPI_WIDTH         1
#define SPI_CMD_DATA_SIZE_WIDTH   16
#define SPI_CMD_BALIGN_WIDTH      1
#define SPI_CMD_DPI_OFFSET        23
#define SPI_CMD_DPI_WIDTH         1



// CFG
#define SPI_CMD_CFG_CLK_DIV_OFFSET      0
#define SPI_CMD_CFG_CLK_DIV_WIDTH       8
#define SPI_CMD_CFG_CPHA_OFFSET         8
#define SPI_CMD_CFG_CPOL_OFFSET         9

#define SPI_CMD_CFG_CLKDIV(val) (val) //计算公式：baudrate=Fsys/(N*2)
#define SPI_CMD_CFG_CPOL_POS  1
#define SPI_CMD_CFG_CPOL_NEG  0
#define SPI_CMD_CFG_CPHA_STD  1
#define SPI_CMD_CFG_CPHA_OPP  0

// SOT
#define SPI_CMD_SOT_CS_OFFSET    0
#define SPI_CMD_SOT_CS_WIDTH     2

#define SPI_CMD_SOT_CS0   0
#define SPI_CMD_SOT_CS1   1
#define SPI_CMD_SOT_CS2   2
#define SPI_CMD_SOT_CS3   3

// SEND_CMD
#define SPI_CMD_SEND_CMD_CMD_OFFSET     0
#define SPI_CMD_SEND_CMD_CMD_WIDTH      16
#define SPI_CMD_SEND_CMD_SIZE_OFFSET    16
#define SPI_CMD_SEND_CMD_SIZE_WIDTH     4
// #define SPI_CMD_SEND_CMD_QPI_OFFSET     27

// SEND_ADDR
#define SPI_CMD_SEND_ADDR_SIZE_OFFSET       16
#define SPI_CMD_SEND_ADDR_SIZE_WIDTH        5
// #define SPI_CMD_SEND_ADDR_QPI_OFFSET        27

//#define SPI_CMD_SEND_ADDR_VALUE(value)  ((((value) & 0xff000000) >> 24) | (((value) & 0xff0000) >> 8) | (((value) & 0xff00) << 8) | (((value) & 0xff) << 24))
#define SPI_CMD_SEND_ADDR_VALUE(value)  (value)
//使用了cmd_rpt+cmd_send_addr命令后 会更新rpt_addr,
//分先后两次拼接配置,高6bit为send_addr发送的qpi、szie[4:0],低32位为紧接着发送的data
// rpt_addr = {cfg_qpi, size [4:0], tx_data};

// SEND_DUMMY dummy是屏蔽的意思，屏蔽数据输入
#define SPI_CMD_DUMMY_CYCLE_OFFSET          16
#define SPI_CMD_DUMMY_CYCLE_WIDTH           5

// TX_DATA
// #define SPI_CMD_TX_DATA_SIZE_OFFSET         0
// #define SPI_CMD_TX_DATA_SIZE_WIDTH          16
// #define SPI_CMD_TX_DATA_BYTE_ALIGN_OFFSET   26
// #define SPI_CMD_TX_DATA_QPI_OFFSET          27
// #define SPI_CMD_TX_DATA_QPI_WIDTH           1

// RX_DATA
// #define SPI_CMD_RX_DATA_SIZE_OFFSET         0
// #define SPI_CMD_RX_DATA_SIZE_WIDTH          16
// #define SPI_CMD_RX_DATA_BYTE_ALIGN_OFFSET   26
// #define SPI_CMD_RX_DATA_BYTE_ALIGN_WIDTH    1
// #define SPI_CMD_RX_DATA_QPI_OFFSET          27
// #define SPI_CMD_RX_DATA_QPI_WIDTH           1
// #define SPI_CMD_RX_DATA_DPI_WIDTH           1

// RPT
#define SPI_CMD_RPT_NB_OFFSET               0
#define SPI_CMD_RPT_NB_WIDTH                16

// EOT end of transform,发送异常信号同时拉高所有cs结束传输
#define SPI_EOT_Base_OFFSET                 0xc
#define SPI_CMD_EOT_GEN_EVT_OFFSET          0
#define SPI_CMD_EOT_GEN_EVT_WIDTH          0
#define SPI_CMD_EOT_EVENT_ENA               1
#define SPI_CMD_EOT_EVENT_DIS               0

// WAIT 选择等待触发的通道
#define SPI_CMD_WAIT_EVENT_OFFSET           0
#define SPI_CMD_WAIT_EVENT_WIDTH            2

// RX_CHECK 校对数据输入 如果校验失败，那么就进入等待异常状态
#define SPI_CMD_RX_CHECK_VALUE_OFFSET       0
#define SPI_CMD_RX_CHECK_VALUE_WIDTH        16

#define SPI_CMD_RX_CHECK_SIZE_OFFSET        16
#define SPI_CMD_RX_CHECK_SIZE_WIDTH         4

#define SPI_CMD_RX_CHECK_MODE_OFFSET        24
#define SPI_CMD_RX_CHECK_MODE_WIDTH         2
// #define SPI_CMD_RX_CHECK_BALIGN_OFFSET      26
// #define SPI_CMD_RX_CHECK_QPI_OFFSET         27
#define SPI_CMD_RX_CHECK_MODE_MATCH         0 //全匹配
#define SPI_CMD_RX_CHECK_MODE_ONES          1
#define SPI_CMD_RX_CHECK_MODE_ZEROS         2
#define SPI_CMD_RX_CHECK_MODE_MASK          3

// FULL DUPLEX
#define SPI_CMD_FUL_SIZE_OFFSET           0
#define SPI_CMD_FUL_SIZE_WIDTH            16
// #define SPI_CMD_FUL_BYTE_ALIGN_OFFSET     26
// #define SPI_CMD_FUL_BYTE_ALIGN_WIDTH      1

//WAIT CYC
#define SPI_WAIT_CYC_OFFSET             0
#define SPI_WAIT_CYC_WIDTH              8


// SPI CMD encoding
#define SPI_CMD_CFG(clockDiv,cpol,cpha)           ((SPI_CMD_CFG_ID      <<SPI_CMD_ID_OFFSET) | ((cpol)<<SPI_CMD_CFG_CPOL_OFFSET)  | ((cpha)   <<SPI_CMD_CFG_CPHA_OFFSET)      | ((clockDiv)<<SPI_CMD_CFG_CLK_DIV_OFFSET))
#define SPI_CMD_SOT(cs)                           ((SPI_CMD_SOT_ID      <<SPI_CMD_ID_OFFSET) | ((cs)  << SPI_CMD_SOT_CS_OFFSET))
#define SPI_CMD_SEND_CMD(cmd,bits,qpi)            ((SPI_CMD_SEND_CMD_ID <<SPI_CMD_ID_OFFSET) | ((qpi) <<SPI_CMD_QPI_OFFSET)       | (((bits)-1)<<SPI_CMD_SEND_CMD_SIZE_OFFSET)| (((cmd)>>8)<<SPI_CMD_SEND_CMD_CMD_OFFSET) | (((cmd)&0xff)<<(SPI_CMD_SEND_CMD_CMD_OFFSET+8)))
#define SPI_CMD_SEND_ADDR(bits,qpi)               ((SPI_CMD_SEND_ADDR_ID<<SPI_CMD_ID_OFFSET) | ((qpi) <<SPI_CMD_QPI_OFFSET)       | (((bits)-1)<<SPI_CMD_SEND_ADDR_SIZE_OFFSET))
#define SPI_CMD_DUMMY(cycles)                     ((SPI_CMD_DUMMY_ID    <<SPI_CMD_ID_OFFSET) | (((cycles)-1)<<SPI_CMD_DUMMY_CYCLE_OFFSET))
#define SPI_CMD_TX_DATA(bits,dpi,qpi,byte_align)  ((SPI_CMD_TX_DATA_ID  <<SPI_CMD_ID_OFFSET) | ((dpi)<<SPI_CMD_DPI_OFFSET)        | (((bits)-1) << SPI_CMD_DATA_SIZE_OFFSET)| ((qpi)<<SPI_CMD_QPI_OFFSET)  | ((byte_align)<<SPI_CMD_BALIGN_OFFSET))
#define SPI_CMD_RX_DATA(bits,dpi,qpi,byte_align) \
({ \
  unsigned int result = __BITINSERT(0, SPI_CMD_RX_DATA_ID, SPI_CMD_ID_WIDTH, SPI_CMD_ID_OFFSET); \
  result = __BITINSERT_R(result, dpi, SPI_CMD_DPI_WIDTH, SPI_CMD_DPI_OFFSET); \
  result = __BITINSERT_R(result, qpi, SPI_CMD_QPI_WIDTH, SPI_CMD_QPI_OFFSET); \
  result = __BITINSERT_R(result, (bits)-1, SPI_CMD_DATA_SIZE_WIDTH, SPI_CMD_DATA_SIZE_OFFSET); \
  result = __BITINSERT_R(result, (byte_align), SPI_CMD_BALIGN_WIDTH, SPI_CMD_BALIGN_OFFSET); \
  result; \
})

#define SPI_CMD_RPT(iter)                 ((SPI_CMD_RPT_ID<<SPI_CMD_ID_OFFSET) | ((iter)<<SPI_CMD_RPT_NB_OFFSET))
#define SPI_CMD_EOT(evt)                  ((SPI_CMD_EOT_ID<<SPI_CMD_ID_OFFSET) | ((evt)<<SPI_CMD_EOT_GEN_EVT_OFFSET))

#define SPI_CMD_RX_CHECK(mode,bits,value,qpi,byte_align) \
  ((SPI_CMD_RX_CHECK_ID<<SPI_CMD_ID_OFFSET) | \
  ((value) << SPI_CMD_RX_CHECK_VALUE_OFFSET) | \
  ((mode) << SPI_CMD_RX_CHECK_MODE_OFFSET) | \
  (((bits)-1) << SPI_CMD_RX_CHECK_SIZE_OFFSET) | \
  ((byte_align)<<SPI_CMD_BALIGN_OFFSET) | \
  ((qpi)<<SPI_CMD_QPI_OFFSET))

#define SPI_CMD_WAIT(event)               ((SPI_CMD_WAIT_ID     <<SPI_CMD_ID_OFFSET) | ((event) << SPI_CMD_WAIT_EVENT_OFFSET))
#define SPI_CMD_RPT_END()                 ((SPI_CMD_RPT_END_ID  <<SPI_CMD_ID_OFFSET))
#define SPI_CMD_FUL(bits,byte_align)      ((SPI_CMD_FUL_ID      <<SPI_CMD_ID_OFFSET) | (((bits)-1) << SPI_CMD_FUL_SIZE_OFFSET) | ((byte_align)<<SPI_CMD_BALIGN_OFFSET))
#define SPI_CMD_WAIT_CYCLE(cycle)         ((SPI_CMD_WAIT_CYC_ID <<SPI_WAIT_CYC_OFFSET)) 


typedef struct  {
  uint8_t baudrate_div;//baudrate
  uint8_t  cs;
  // uint8_t  cs_gpio;//use gpio as cs
  uint8_t cpol;
  uint8_t cpha;
  uint8_t byte_align;
  uint8_t data_size;
  uint8_t qpi;
  uint8_t dpi;
  uint16_t bit_size;
} SPI_InitTypeDef;

void spim_Deinit(SPI_InitTypeDef *SPI_InitStruct);
void spim_init(SPI_InitTypeDef *SPI_InitStruct);
void spim_cmd_init();
void spim_send_cmd(uint32_t spibase, uint32_t cmdbase, uint8_t cfg, FunctionalState NewState);

void spim_send_data(uint32_t spibase, uint32_t u32Data);

void spim_receive_data(uint32_t spibase, uint32_t u32Data);

void spim_dual_transfer(uint32_t spibase, uint32_t u32Data_tx, uint32_t u32Data_rx);

void spim_get_cmd(SPI_CMD_ID CMD_ID);

void spim_wait_tx_done(uint32_t spi_txbase);
void spim_wait_rx_done(uint32_t spi_rxbase);
void spim_handler();

// spim_send(SPI_InitTypeDef *handle, void *data, int len, rt_spim_cs_e mode)
// spim_receive(SPI_InitTypeDef *handle, void *data, int len, rt_spim_cs_e mode)
// spim_send_qspi(SPI_InitTypeDef *handle, void *data, int len, rt_spim_cs_e mode)
// spim_receive_qspi(SPI_InitTypeDef *handle, void *data, int len, rt_spim_cs_e mode)
// __rt_spim_control(SPI_InitTypeDef *handle, rt_spim_control_e cmd, uint32_t arg);

// static inline void spim_control(SPI_InitTypeDef *handle, rt_spim_control_e cmd, uint32_t arg)

// static inline void spim_wait_for_event(SPI_InitTypeDef *handle)
// {
//   while (udma_busy(handle->channel + 1))
//   {
//     // rt_wait_for_interrupt();
//     int_wait_for_interrupt();
//   }
// }

#ifdef __cplusplus
}
#endif

#endif
