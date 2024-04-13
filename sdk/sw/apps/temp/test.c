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


// /** 处理系统异常中断 */
// void __rt_handle_illegal_instr()
// {
//   printf("__rt_handle_illegal_instr\n");
// }
// void spim_irq_handler()
// {
//   printf("spim_irq_handler\n");
// }
// /** 处理定时器 low 中断 */
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
#define ARCHI_SOC_TEMP_ADDR 0x1A1010D8
#define ARCHI_SOC_TEMP_ADDR 0x1A1010D8

void temp_irq_handler(){
  printf("Temp Interrupt Happen!!\n");
  int temp_data;
  temp_data = pulp_read32(0x1C001000+4*i);
  pulp_write32(0x1C001500+4*i,tdc_data);
}


int main()
{
  // 
  pulp_write32((ARCHI_SOC_EU_ADDR + 0x04),0xffff7fff);
  pulp_write32((ARCHI_APB_SOC_CTRL_ADDR + 0xD8),0x1);

  printf("wating temp interrupt!!\n");
  wait_soc_event();

  return 0;
  
}
