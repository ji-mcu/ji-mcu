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

/*
 * This example shows how to receive a raw SPI bistream
 * from one the SPI master port.
 */
// #include "hal/spi/rt_spim.h"
// #include "hal/apb_soc/apb_soc_v3.h"
// #include "hal/soc_eu/soc_eu_v2.h"
// #include "hal/itc/itc_v1.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <hal/pulp.h>
#include "hal/pulp_io.h"
#include "tdc.h"

void set_upload_addr(){
  pulp_write32(0x1A103804,0x80002500);// HGM_BADDR_CFG
  pulp_write32(0x1A103804,0x80002600);
  pulp_write32(0x1A103804,0x80002700);
  pulp_write32(0x1A103804,0x80002800);
  pulp_write32(0x1A103804,0x80002900);
}

void cfg_default(){
  pulp_write32(0x1A10380C,0x00000115);
  pulp_write32(0x1A103824,0x00000a73);
  set_upload_addr();
  pulp_write32(0x1A103808,0xf0007fa3);//shut start
}

void cfg_2ms(){
  pulp_write32(0x1A10380C,0x00000115);// HGM_CNTR_CFG   50*512->2ms
  pulp_write32(0x1A103824,0x00000a73);// HGM_GGCT_TIME
  set_upload_addr();
  pulp_write32(0x1A103808,0xf0007fa3);//shut start
}


void timer_TDC_irq_handler(){
  printf("TDC IRQ HAPPENED !!\n");
  int tdc_data;
  for (int i = 0; i < 320; i++)
  {
    tdc_data = pulp_read32(0x1C006000+4*i);
    pulp_write32(0x1C001a00+4*i,tdc_data);
  }
  set_upload_addr();
  pulp_write32(0x1A103808,0xf0007fa3);//shut start
  hal_spr_write(0x300,0x08);
}

int main()
{
  set_soc_event_enable();
  pulp_write32((ARCHI_SOC_EU_ADDR + 0x04),0xbfffffff);


  printf("SET HISTOGRAM REGS !!\n");
  // cfg_default();
  cfg_2ms();


  wait_soc_event();
  wait_soc_event();
  wait_soc_event();
  wait_soc_event();

  hal_itc_enable_set(0);
  printf("Return 0 !!\n");
  return 0;
}