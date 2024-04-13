#include <stdio.h>
//#include <rt/rt_api.h>
#include <stdint.h>
#include "i2c-0.h"
#include "hal/pulp_io.h"

#define BUFFER_SIZE 3

//RT_L2_DATA uint8_t tx_buffer[BUFFER_SIZE];
//RT_L2_DATA uint8_t rx_buffer[BUFFER_SIZE];


int main()
{
  int i;
  printf("Entering i2c0 test\n");
  pulp_write32(0x1A101010,1<<0|1<<2);
  pulp_write32(0x1A101014,0x0);
 
  //set i2c1 mux output
  pulp_write32(0x1A101010,0x5);

  // //i2c_reg_test();
  hal_soc_i2c0_set(0x1c040110,0x6363C102);
  hal_soc_i2c0_set(0x1c040114,0x44332211);
  hal_soc_i2c0_set(0x1c040118,0x88776655);
  hal_soc_i2c0_set(0x1c04011C,0x00000021);

  hal_soc_i2c0_set(0x1c040140,0x8208C102);
  hal_soc_i2c0_set(0x1c040144,0x88776655);
  hal_soc_i2c0_set(0x1c040148,0xddccbbaa);
  hal_soc_i2c0_set(0x1c04014C,0x00000021);
  // hal_soc_i2c0_set(0x1a106004,0xffffff7f);
  // hal_soc_i2c0_set(0x1a109000,1<<26);
  // i2c0_tx_test(0x40110,0x0D);
  // i2c1_tx_test(0x40140,0x0D);
  i2c0_rx_test(0x40110,0x40200,0x0D,0x20);

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
