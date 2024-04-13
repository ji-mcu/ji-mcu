/*
 * This example shows how to send a raw SPI bistream
 * through one the SPI master port.
 */

#include <stdio.h>
#include <stdint.h>
#include "pulp.h"

#define CMD_SIZE  16
#define DATA_SIZE 256 //byte
#define ARCHI_SPITX_BUF0_ADDR 0x1C002600
#define ARCHI_SPITX_BUF1_ADDR 0x1C002700
#define ARCHI_SPITX_BUF2_ADDR 0x1C002800

#define ARCHI_SPIRX_BUF0_ADDR 0x1C002a00
#define ARCHI_SPIRX_BUF1_ADDR 0x1C002b00
#define ARCHI_SPIRX_BUF2_ADDR 0x1C002c00

#define UDMA_SPIM0_TX_ADDR 0x1A104000 + 0x10
#define UDMA_SPIM1_TX_ADDR 0x1A104280 + 0x10
#define UDMA_SPIM2_TX_ADDR 0x1A104300 + 0x10

/** 处理系统异常中断 */
// void __rt_handle_illegal_instr()
// {
//   printf("__rt_handle_illegal_instr\n");
// }
// void spim_irq_handler()
// {
//   printf("spim_irq_handler\n");
// }
/** 处理定时器 low 中断 */
// void timer_lo_irq_handler()
// {
//   printf("Timer Lo irq enter!\n");
//   // hal_spr_write(0x300,0x08);
// }
// /** 处理定时器 high 中断 */
// void timer_hi_irq_handler()
// {
//   printf("Timer Hi irq enter!\n");
// }

int cmd[CMD_SIZE];

int main()
{

  int spi_wr_data;
  int spi_rd_data;

  // int add1 = 0x1;
  // int add2 = 0x1;
  // int add3;

  // add3 = add1+add2;

  // printf("SPI TRANSFER TESTING!\n");

  for (int i=0; i<DATA_SIZE/4; i++)
  {
      pulp_write32((ARCHI_SPITX_BUF0_ADDR + i*4) , i);
  }

  // soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_SPIM0_EOT);


  // // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // // // SPI STD SEND
  // // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  printf("SPI STD WRITE TESTING!\n");
  cmd[0] = SPI_CMD_CFG            (1,0,0);
  cmd[1] = SPI_CMD_SOT            (0);
  // cmd[2] = SPI_CMD_SEND_CMD       (0x02, 8, 0); //page program
  // cmd[3] = SPI_CMD_SEND_ADDR      (24, 0);
  // cmd[4] = SPI_CMD_SEND_ADDR_VALUE(0x0<<8);
  cmd[2] = SPI_CMD_TX_DATA        (DATA_SIZE*8, 0, 0, 0);

  plp_udma_enqueue(UDMA_SPIM0_TX_ADDR, cmd, 3*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  plp_udma_enqueue(UDMA_SPIM0_TX_ADDR, ARCHI_SPITX_BUF0_ADDR, DATA_SIZE, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  while(!plp_udma_canEnqueue(UDMA_SPIM0_TX_ADDR));
  cmd[0] = SPI_CMD_EOT(1);
  plp_udma_enqueue(UDMA_SPIM0_TX_ADDR, cmd, 1*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  printf("TEST RX End!\n");


  // // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // // // SPI STD SEND
  // // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  printf("SPI STD WRITE TESTING!\n");
  cmd[0] = SPI_CMD_CFG            (1,0,0);
  cmd[1] = SPI_CMD_SOT            (0);
  // cmd[2] = SPI_CMD_SEND_CMD       (0x02, 8, 0); //page program
  // cmd[3] = SPI_CMD_SEND_ADDR      (24, 0);
  // cmd[4] = SPI_CMD_SEND_ADDR_VALUE(0x0<<8);
  cmd[2] = SPI_CMD_TX_DATA        (DATA_SIZE*8, 0, 0, 0);

  plp_udma_enqueue(UDMA_SPIM2_TX_ADDR, cmd, 3*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  plp_udma_enqueue(UDMA_SPIM2_TX_ADDR, ARCHI_SPITX_BUF0_ADDR, DATA_SIZE, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  while(!plp_udma_canEnqueue(UDMA_SPIM2_TX_ADDR));
  cmd[0] = SPI_CMD_EOT(1);
  plp_udma_enqueue(UDMA_SPIM2_TX_ADDR, cmd, 1*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  printf("TEST RX End!\n");


  // spi_test_finish();

  return 0;
}

