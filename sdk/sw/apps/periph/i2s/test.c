#include <stdio.h>
//#include <rt/rt_api.h>
#include <stdint.h>
#include "i2s-0.h"
#include "hal/pulp_io.h"

#define BUFFER_SIZE 3

//RT_L2_DATA uint8_t tx_buffer[BUFFER_SIZE];
//RT_L2_DATA uint8_t rx_buffer[BUFFER_SIZE];


int main()
{
  int i;
  printf("Entering i2s0 test\n");
  pulp_write32(0x1C003000,0x44332211);
  pulp_write32(0x1C003004,0x88776655);
  pulp_write32(0x1C003008,0xCCBBAA99);
  pulp_write32(0x1C00300C,0xFFFFEEDD);
  pulp_write32(0x1C003010,0x55555555);
  pulp_write32(0x1C003014,0x66666666);
  pulp_write32(0x1C003018,0x77777777);
  pulp_write32(0x1C00301C,0x88888888);
 
  // //i2c_reg_test();
  // hal_soc_i2s0_set(0x1c000110,0x8208C102);
  // hal_soc_i2s0_set(0x1c000114,0x44332211);
  // hal_soc_i2s0_set(0x1c000118,0x88776655);
  // hal_soc_i2s0_set(0x1c00011C,0x00000021);
  // hal_soc_i2c0_set(0x1a106004,0xffffff7f);
  // hal_soc_i2c0_set(0x1a109000,1<<26);
  // i2s0_rx_test(0x1C003000,0x20);
  i2s0_tx_test(0x1C003000,0x20);
  // i2s0_rx_test(0x20010,0x20);

  //i2c_reg_test();
  // hal_soc_i2c0_set(0x1c008010,0x63118202);
  // hal_soc_i2c0_set(0x1c008014,0x21112101);
  // hal_soc_i2c0_set(0x1a106004,0xffffff7f);
  // hal_soc_i2c0_set(0x1a109000,1<<26);
  // // i2d_tx_test(0x8010,0x0b);
  // i2d_rx_test(0x8010,0x8080,0x06,0x01);

  while(1);

  return 0;
}
