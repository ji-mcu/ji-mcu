/*
 * This example shows how to use a virtual timer to trigger a function call
 * once.
 */

#include <stdio.h>
#include <stdint.h>
#include "pulp.h"

#define CFG_REG_LO         0x0
#define CFG_REG_HI         0x4
#define TIMER_VAL_LO       0x8
#define TIMER_VAL_HI       0xC
#define TIMER_CMP_LO       0x10
#define TIMER_CMP_HI       0x14
#define TIMER_START_LO     0x18
#define TIMER_START_HI     0x1C
#define TIMER_RESET_LO     0x20
#define TIMER_RESET_HI     0x24


#define ENABLE_BIT          0
#define RESET_BIT           1
#define IRQ_BIT             2
#define IEM_BIT             3
#define CMP_CLR_BIT         4
#define ONE_SHOT_BIT        5
#define PRESCALER_EN_BIT    6
#define REF_CLK_EN_BIT      7
#define PRESCALER_START_BIT 8
#define PRESCALER_STOP_BIT  15
#define MODE_64_BIT         31

#define ARCHI_FC_TIMER2_ADDR        0x1A107800


// void wait_soc_event()
// {
//   hal_itc_enable_set(1 << ARCHI_FC_EVT_TIMER0_LO);
//   while(!((hal_itc_status_value_get() >> ARCHI_FC_EVT_TIMER0_LO) & 1)) {
//     // hal_itc_wait_for_interrupt();
//   }
//   hal_itc_fifo_pop();
//   hal_itc_status_clr(1 << ARCHI_FC_EVT_TIMER0_LO);
//   hal_itc_enable_clr(1 << ARCHI_FC_EVT_TIMER0_LO);

  // pulp_write32((ARCHI_FC_TIMER_ADDR + TIMER_RESET_LO),0x1);

// }

// /** 处理系统异常中断 */
// void __rt_handle_illegal_instr()
// {
//   printf("__rt_handle_illegal_instr\n");
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

int main()
{
  
  // hal_itc_enable_set(1 << ARCHI_FC_EVT_TIMER0_LO);
  // pulp_write32(0x1A100000,0x1000);

  printf("Helloworld !!\n");
  
  //set timer cfg
  pulp_write32((ARCHI_FC_TIMER_ADDR + CFG_REG_LO),0x00);
  pulp_write32((ARCHI_FC_TIMER_ADDR + TIMER_VAL_LO),0x00);
  pulp_write32((ARCHI_FC_TIMER_ADDR + TIMER_CMP_LO),0x1000);
  pulp_write32((ARCHI_FC_TIMER_ADDR + CFG_REG_LO),(1<<0)|(1<<2)|(1<<4)|(1<<6)|(0<<7)|(1<<8));
  pulp_write32((ARCHI_FC_TIMER_ADDR + TIMER_START_LO),0x1);

  //set timer cfg
  pulp_write32((ARCHI_FC_TIMER2_ADDR + CFG_REG_LO),0x00);
  pulp_write32((ARCHI_FC_TIMER2_ADDR + TIMER_VAL_LO),0x00);
  pulp_write32((ARCHI_FC_TIMER2_ADDR + TIMER_CMP_LO),0x1000);
  pulp_write32((ARCHI_FC_TIMER2_ADDR + CFG_REG_LO),(1<<0)|(1<<2)|(1<<4)|(1<<6)|(0<<7)|(1<<8));
  pulp_write32((ARCHI_FC_TIMER2_ADDR + TIMER_START_LO),0x1);

  while(1){}


  // wait_soc_event();

  printf("End!\n");

  return 0;
}
