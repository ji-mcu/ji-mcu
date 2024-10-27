// #include <stdio.h>
// #include <rt/rt_api.h>
// #include <stdint.h>

// #include "hal/pulp_io.h"
#include "soc_common.h"
#include "IC_PWM.h"
#include "core_sys.h"

#define BUFFER_SIZE 3

// RT_L2_DATA uint8_t tx_buffer[BUFFER_SIZE];
// RT_L2_DATA uint8_t rx_buffer[BUFFER_SIZE];

int main()
{
  // int add1;
  // int add2 = 0xff00ff00;
  // int add3;
  // int add4;
  uint16_t pwm_hi=0;
  uint16_t pwm_lo=0;
  for (int i = 0; i < 32; ++i)
  {
    /* code */
    // add1 = pulp_read32(0x1C022000+i*4);
    // add2 = pulp_read32(0x1C022000+(i+1)*4);
    // add3 = add1-add2;
    // add4 = add1+add2;
    pulp_write32(0x1C030000 + i * 4, 0xff00ff00);
  }
  PWMX_CLKCfg(255);//PWM的基准频率
  //
  pwm_hi = PWMX_CycleCfg(PWMX_Cycle_10);
  pwm_lo = pwm_hi/2;
  PWMX_ACTOUT(CH_PWM0 | CH_PWM1 | CH_PWM2 | CH_PWM3, pwm_hi, pwm_lo, ENABLE);
  while (1)
  {
    // mDelaymS(1000);
    mDelaymS(1000);
    // mDelaymS(1000);
    // mDelaymS(1000);
    // mDelaymS(1000);
    // PWM_DISNABLE(CH_PWM3);
    // mDelaymS(1000);
    // mDelaymS(1000);
    // mDelaymS(1000);
    // mDelaymS(1000);
    // mDelaymS(1000);
    // mDelaymS(1000);
    // PWM_ENABLE(CH_PWM3);
    /* code */
  }
  

      return 0;
}