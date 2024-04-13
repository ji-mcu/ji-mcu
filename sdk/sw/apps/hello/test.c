/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*+

+
 * This example shows how to receive a raw SPI bistream
 * from one the SPI master port.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <hal/pulp.h>
#include "hal/pulp_io.h"

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

void timer_TDC_irq_handler(){
  printf("IRQ HAPPENED !!\n");
  // hal_spr_write(0x300,0x08);
}

int main()
{
  int add1;
  // int add2 = 0xff00ff00;
  // int add3;
  // int add4;
  for (int i = 0; i < 2048; ++i)
  {
    /* code */
    // add1 = pulp_read32(0x1C022000+i*4);
    // add2 = pulp_read32(0x1C022000+(i+1)*4);
    // add3 = add1-add2;
    // add4 = add1+add2;
    pulp_write32(0x1C010000+i*4,0xff00ff00);
  }

  for (int i = 0; i < 2048; ++i)
  {
    /* code */
    // add1 = pulp_read32(0x1C022000+i*4);
    // add2 = pulp_read32(0x1C022000+(i+1)*4);
    // add3 = add1-add2;
    // add4 = add1+add2;
    add1 = pulp_read32(0x1C010000+i*4);
    pulp_write32(0x1C010000+i*4,add1+add1);
  }

  return 0;
}

// int main()
// {
//   int add1 = 0xff;
//   int add2 = 0xff;
//   int add3;
//   // int add4;
//   add3 = add1+add2;
//   pulp_write32(0x1A100000,add3);
//   // for (int i = 0; i < 2048; ++i)
//   // {
//   //   /* code */
//   //   // add1 = add1<<1;
//   //   // add2 = add2<<1;
//   //   // add3 = add1-add2;
//   //   add1 = pulp_read32(0x1C022000+i*4);
//   //   add2 = pulp_read32(0x1C022000+(i+1)*4);
//   //   add3 = add1-add2;
//   //   add4 = add1+add2;
//   //   pulp_write32(0x1C028000+(i+2)*4,add3);
//   //   pulp_write32(0x1C028FFF+(i+2)*4,add4);
//   //   pulp_write32(0x1A100000,0xFFFFFFFF);
//   // }

//   return 0;
// }


// ////////////////////////////////instr_data_13_ instr_data_16_ instr_data_19_
// int main()
// {
//   int add1;
//   int add2;
//   int add3;

//   for (int i = 0; i < 512; ++i)
//   {
//     /* code */
//     // add1 = add1<<1;
//     // add2 = add2<<1;
//     // add3 = add1-add2;
//     add1 = pulp_read32(0x1C00000+i*4);
//     add2 = pulp_read32(0x1C00000+(i+1)*4);
//     add3 = add1-add2;
//     pulp_write32(0x1C00000+(i+2)*4,add3);
//   }

//   return 0;
// }