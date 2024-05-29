/*
 * This example shows how to send a raw SPI bistream
 * through one the SPI master port.
 */

#include <stdio.h>
#include <stdint.h>
#include "pulp.h" // sdk/sw/pulp-rt-spiv2/include/archi/udma/spim/udma_spim_v2.h 

#define CMD_SIZE 7
#define DATA_SIZE 32

int cmd[CMD_SIZE];
int data_buffer[DATA_SIZE];

void send_cmd(int cmd_data)
{
  cmd[0] = 0x1;
  cmd[1] = SPI_CMD_SOT(0);
  cmd[2] = SPI_CMD_SEND_CMD(cmd_data, 8, 0);

  plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), cmd, 3 * 4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);

  while (!plp_udma_canEnqueue(UDMA_SPIM_TX_ADDR(0)))
    ;

  cmd[0] = SPI_CMD_EOT(1);
  plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), cmd, 1 * 4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
}

void write_status(int cmd_data, int data)
{
  cmd[0] = 0x1;
  cmd[1] = SPI_CMD_SOT(0);
  cmd[2] = SPI_CMD_SEND_CMD(cmd_data, 8, 0);
  cmd[3] = SPI_CMD_TX_DATA(16, 0, 0);

  data_buffer[0] = data;

  plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), cmd, 4 * 4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), data_buffer, 2, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);

  while (!plp_udma_canEnqueue(UDMA_SPIM_TX_ADDR(0)))
    ;

  cmd[0] = SPI_CMD_EOT(1);
  plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), cmd, 1 * 4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
}

int spi_test_receive()
{

  printf("spim recieve bigining!\n");
  pulp_write32(0x1a10108c, 0xf);

  send_cmd(0x06);             // write enable
  write_status(0x01, 0x0200); // write status QPI Mode

  int delay;
  while (!(delay >> 11))
  {
    delay++;
    printf("counting!\n");
  }

  cmd[0] = 0x1;
  cmd[1] = SPI_CMD_SOT(0);
  cmd[2] = SPI_CMD_SEND_CMD(0x6b, 8, 0);
  cmd[3] = SPI_CMD_SEND_ADDR(32, 0);
  cmd[4] = SPI_CMD_SEND_ADDR_VALUE(0);
  cmd[5] = SPI_CMD_RX_DATA(DATA_SIZE * 32, 1, SPI_CMD_BYTE_ALIGN_ENA);
  cmd[6] = SPI_CMD_EOT(1);

  plp_udma_enqueue(UDMA_SPIM_TX_ADDR(0), cmd, CMD_SIZE * 4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  plp_udma_enqueue(UDMA_SPIM_RX_ADDR(0), data_buffer, DATA_SIZE * 4, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);

  return 0;
}