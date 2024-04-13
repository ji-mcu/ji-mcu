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

void TDC_setting(int hgm_mode, int test_mode, int shut_mode)
{
  int reg_data;
  reg_data = pulp_read32(ARCHI_HGM_ADDR + REG_HGM_STATUS*4);
  pulp_write32((ARCHI_HGM_ADDR + REG_HGM_STATUS*4),(hgm_mode<<30)|(reg_data&0x3fffffff));
  reg_data = pulp_read32(ARCHI_HGM_ADDR + REG_HGM_TEST_CFG*4);
  pulp_write32((ARCHI_HGM_ADDR + REG_HGM_TEST_CFG*4),(test_mode<<30)|(reg_data&0x3fffffff));
  reg_data = pulp_read32(ARCHI_HGM_ADDR + REG_HGM_GENERAL*4);
  pulp_write32((ARCHI_HGM_ADDR + REG_HGM_GENERAL*4),(shut_mode|(reg_data&0xfffffffc)));
  pulp_write32((ARCHI_HGM_ADDR + REG_HGM_GENERAL*4),(shut_mode&0x00000002)|(reg_data&0xfffffffc));
}

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

void set_soc_event_enable()
{
  hal_itc_enable_set(1 << ARCHI_FC_EVT_SOC_EVT);
}