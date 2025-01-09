// #include <stdio.h>
// #include <rt/rt_api.h>
// #include <stdint.h>

// #include "hal/pulp_io.h"
#include "soc_common.h"

#include "test_example.h"

uint8_t flag0 = 0;
uint8_t flag1 = 0;

extern void timer_handler1_asm();
void timer_handler1();

void int_init()
{

  int_mask_clr(-1);

  int_set_fc_vector_base(int_vector_base());

  hal_irq_enable();

  int_set_handler(8, timer_handler1_asm);
  int_mask_set(1 << 8);
}


// void main()
// {
//   // int add1;
//   // int add2 = 0xff00ff00;
//   // int add3;
//   // int add4;

//   Uart_InitTypeDef uart_InitStruct = {0};
//   uart_StructInit(&uart_InitStruct);
//   UART0_DefInit(&uart_InitStruct);

//   pwm_test();
//   // gpio_test();
//   // uart_test();

//   // timer_test();
//   // i2c_test();
//   // i2s_test();
//   // spi_test();
//   // int_test();

//   // return 0;
// }

void main()
{
  uint32_t i ;
  TIM_InitTypeDef TIM_InitStructure = {0};

  int_init();
  // pwm_test();
  PAD_MUX_FUN0(FUN_GPIO3 | FUN_GPIO2 | FUN_GPIO1, ENABLE);
  GPIOA_ModeCfg(GPIO_Pin_3 | GPIO_Pin_2, GPIO_ModeOut);
  // GPIOA_ModeCfg(GPIO_Pin_1, GPIO_ModeIN);
  // GPIOA_ITModeCfg(GPIO_Pin_1, GPIO_ITMode_FallEdge);
  // (*((PUINT32V)0x1A10000C)) = GPIO_Pin_1;
  GPIOA_SetBits(GPIO_Pin_2);
  GPIOA_ResetBits(GPIO_Pin_3);
  TIM_StructInit(&TIM_InitStructure);
  TMR_TimerInit(&TIM_InitStructure, cfg_lo);
  // TMR_TimerInit(&TIM_InitStructure, cfg_hi);
  while (1)
  {
    // wait_event(10);
    if (flag0 == 1)
    {
      if(flag1==128)
      {
        GPIOA_ResetBits(GPIO_Pin_2);
        flag0 = 0;
        flag1 = 0;
        // DelayMs(200);
        R32_timer0_cfg_lo |= (ENABLE_BIT | 1<< 1 | IRQ_BIT | CMP_CLR_BIT | ONE_SHOT_BIT | REF_CLK_EN_BIT | REF_CLK_MUX);
        }
      else{
        flag1++;
        // GPIOA_SetBits(GPIO_Pin_2);s
      }
    }
    else 
    {
      GPIOA_SetBits(GPIO_Pin_2);
      // GPIOA_SetBits(GPIO_Pin_2);
      // soc_printf("j=%x", j);
      int_mask_set(1 << 8);
      i = R32_timer0_cnt_lo;
    }
  }
}

// __attribute__((interrupt))
 void timer_handler1()
{

  flag0=1;
  // R32_P_INTSTATUS = 0;
  R32_timer0_reset_lo = 1;
  // int_fifo_pop();
  ITC_CLR = 1 << 8;
  ITC_MASK_CLR = 1 << 8;
  ITC_ACK_CLR = 1 << 8;
  
  // int_status_clr(1 << 9);
  // int_enable_clr(1 << 9);
  // int_clr(1<<9);
}
