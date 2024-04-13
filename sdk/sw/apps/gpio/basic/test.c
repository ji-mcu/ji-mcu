/*
 * This example shows how to use SPIM driver with asynchronous
 * events.
 */

#include <stdio.h>
#include <stdint.h>
#include "gpio-0.h"
#include "hal/pulp_io.h"

// This callback is called everytime a transfer is finished
// Just reenqueued another transfer in case we didn't reach
// the number of transfers we want to enqueue

int main()
{
  printf("----gpio test begin---- !\n");

  pulp_write32(0x1a100000,0x01);
  pulp_write32(0x1a100000+0x08,0x01);

  pulp_write32(0x1a100000,0x02);
  pulp_write32(0x1a100000+0x08,0x02);

  pulp_write32(0x1a100000,0x04);
  pulp_write32(0x1a100000+0x08,0x04);

  pulp_write32(0x1a100000,0x3);
  pulp_write32(0x1a100000+0x08,0x3);

  pulp_write32(0x1a100000,0x5);
  pulp_write32(0x1a100000+0x08,0x05);

  pulp_write32(0x1a100000,0x6);
  pulp_write32(0x1a100000+0x08,0x06);


  pulp_read32(0x1a100000+0x04);

  //enable gpio
  pulp_write32(0x1a100000+0x1c,0x07);
  pulp_read32(0x1a100000+0x04);

  printf("---- CLKEXT ENABLE--- !\n");
  //clkext
  pulp_write32(0x1a101000+0x10,0x01);

  printf("---- CLKEXT DISABLE--- !\n");
  //clkext
  pulp_write32(0x1a101000+0x10,0x00);

  return 0;
}
