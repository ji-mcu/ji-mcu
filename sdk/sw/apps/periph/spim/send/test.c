/*
 * This example shows how to send a raw SPI bistream
 * through one the SPI master port.
 */

#include <stdio.h>
#include <stdint.h>
#include "pulp.h"

#define CMD_SIZE  16
#define DATA_SIZE 256 //byte
#define ARCHI_SPITX_BUF0_ADDR 0x1C040100
#define ARCHI_SPITX_BUF1_ADDR 0x1C002700
#define ARCHI_SPITX_BUF2_ADDR 0x1C002800

#define ARCHI_SPIRX_BUF0_ADDR 0x1C002a00
#define ARCHI_SPIRX_BUF1_ADDR 0x1C002b00
#define ARCHI_SPIRX_BUF2_ADDR 0x1C002c00

#define ARCHI_STATUS_ADDR 0x1C002d00

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

void wait_soc_event()
{
  hal_itc_enable_set(1 << ARCHI_FC_EVT_SOC_EVT);
  while(!((hal_itc_status_value_get() >> ARCHI_FC_EVT_SOC_EVT) & 1)) {
    // hal_itc_wait_for_interrupt();
  }
  hal_itc_fifo_pop();
  hal_itc_status_clr(1 << ARCHI_FC_EVT_SOC_EVT);
  hal_itc_enable_clr(1 << ARCHI_FC_EVT_SOC_EVT);
}

// void itof_run()
// {
//   int itof_status;
//   pulp_write32((ARCHI_ITOF_ADDR + 0x42*4) , 0x000000ff); //enable phs_setting 4 DCS
//   pulp_write32((ARCHI_ITOF_ADDR + 0x4d*4) , 0x00000002);
//   pulp_write32((ARCHI_ITOF_ADDR + 0xff*4) , 0x000000f4);
//   printf("ITOF wakeup\n");
//   pulp_write32((ARCHI_ITOF_ADDR + 0xff*4) , 0x000000f2);
//   printf("ITOF run\n");
//   pulp_write32((ARCHI_ITOF_ADDR + 0xff*4) , 0x000000f3);
//   itof_status = pulp_read32(ARCHI_ITOF_ADDR + 0x46*4);
//   while(itof_status!=0x00000012){
//     itof_status = pulp_read32(ARCHI_ITOF_ADDR + 0x46*4);
//     if(0x00000001==pulp_read32(ARCHI_ITOF_ADDR + 0x4f*4)){
//     pulp_write32((ARCHI_ITOF_ADDR + 0x4f*4) , 0x00000001); //clear pixel_storage bit
//     }
//   }
// }

// void spi_test_finish()
// {
//   printf("SPI TEST FINISH!!\n");
//   pulp_write32(ARCHI_GPIO_ADDR+0x00, 2); //set gpio0 dir out
//   pulp_write32(ARCHI_GPIO_ADDR+0x08, 2); //set gpio0 out 1
//   pulp_write32(ARCHI_GPIO_ADDR+0x08, 0); //set gpio0 out 0
// }

void erase_delay()
{
    int status = 1;

    while(status&0x1)
    {
        cmd[0] = SPI_CMD_CFG(1,0,0);
        cmd[1] = SPI_CMD_SOT(0);
        cmd[2] = SPI_CMD_SEND_CMD(0x05,8,0);
        cmd[3] = SPI_CMD_RX_DATA(8, 0, 0, SPI_CMD_BYTE_ALIGN_ENA);
        cmd[4] = SPI_CMD_EOT(1);

        plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), cmd, 5*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
        plp_udma_enqueue(UDMA_SPIM_RX_ADDR(0), &status, 1, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
        wait_soc_event();
    }
}

int main()
{

  int spi_wr_data;
  int spi_rd_data;

  printf("SPI TRANSFER TESTING!\n");

  for (int i=0; i<DATA_SIZE/4; i++)
  {
      pulp_write32((ARCHI_SPITX_BUF0_ADDR + i*4) , i);
  }

  for (int i=0; i<DATA_SIZE/4; i++)
  {
      pulp_write32((ARCHI_SPITX_BUF1_ADDR + i*4) , 353+i);
  }

  for (int i=0; i<DATA_SIZE/4; i++)
  {
      pulp_write32((ARCHI_SPITX_BUF2_ADDR + i*4) , 681+i);
  }

  // soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_SPIM0_EOT);

  // // // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // // // // SPI STD WRITE
  // // // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // cmd[0] = SPI_CMD_CFG(1,0,0);
  // cmd[1] = SPI_CMD_SOT(0);
  // cmd[2] = SPI_CMD_SEND_CMD(0x06,8,0);//set command WriteEnable
  // cmd[3] = SPI_CMD_EOT(1);
  // plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), cmd, 4*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  // wait_soc_event();

  // printf("STARTING ERASING FLASH!\n");
  // cmd[0] = SPI_CMD_CFG(1,0,0);
  // cmd[1] = SPI_CMD_SOT(0);
  // cmd[2] = SPI_CMD_SEND_CMD(0x81,8,0);//page erase
  // cmd[3] = SPI_CMD_SEND_ADDR      (24, 0);
  // cmd[4] = SPI_CMD_SEND_ADDR_VALUE(0x0<<8);
  // cmd[5] = SPI_CMD_EOT(1);
  // plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), cmd, 6*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  // wait_soc_event();
  // erase_delay();
  // printf("DONE ERASING FLASH!\n");

  // cmd[0] = SPI_CMD_CFG(1,0,0);
  // cmd[1] = SPI_CMD_SOT(0);
  // cmd[2] = SPI_CMD_SEND_CMD(0x06,8,0);//set command WriteEnable
  // cmd[3] = SPI_CMD_EOT(1);
  // plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), cmd, 4*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  // wait_soc_event();
  pulp_write32(0x1A101010,1<<16|1<<18|1<<20|1<<22);
  pulp_write32(0x1A101014,0x0);

  printf("SPI STD WRITE TESTING!\n");
  cmd[0] = SPI_CMD_CFG            (1,0,0);
  cmd[1] = SPI_CMD_SOT            (0);
  // cmd[2] = SPI_CMD_SEND_CMD       (0x02, 8, 0); //page program
  // cmd[2] = SPI_CMD_SEND_ADDR      (24, 0);
  // cmd[3] = SPI_CMD_SEND_ADDR_VALUE(0x0<<8);
  cmd[2] = SPI_CMD_TX_DATA        (DATA_SIZE*8, 0, 0, 0);
  // cmd[2] = SPI_CMD_RX_DATA        (DATA_SIZE*8, 0, 0, 0);
  //SPI1
  plp_udma_enqueue(0x1A104280+0x10, cmd, 3*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  plp_udma_enqueue(0x1A104280+0x10, ARCHI_SPITX_BUF0_ADDR, DATA_SIZE, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  //SPI2
  plp_udma_enqueue(0x1A104300+0x10, cmd, 3*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  plp_udma_enqueue(0x1A104300+0x10, ARCHI_SPITX_BUF0_ADDR, DATA_SIZE, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  while(!plp_udma_canEnqueue(0x1A104300+0x10));
  cmd[0] = SPI_CMD_EOT(1);
  plp_udma_enqueue(0x1A104300+0x10, cmd, 1*4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  // wait_soc_event();
  printf("TEST TX End!\n");
  // erase_delay();



  return 0;
}

