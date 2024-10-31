// #include <stdio.h>
// #include <rt/rt_api.h>
// #include <stdint.h>

// #include "hal/pulp_io.h"
#include "soc_common.h"
#include "IC_PWM.h"
#include "core_sys.h"
#include "IC_timer.h"
#include "core_SFR.h"
#include "i2c-0.h"
#include "uart.h"

#define BUFFER_SIZE 3
void gpio_test();
void pwm_test();
void uart_test();
void timer_test();
void i2c_test();
void OLED_WR_Byte(uint8_t *dat);
// RT_L2_DATA uint8_t tx_buffer[BUFFER_SIZE];
// RT_L2_DATA uint8_t rx_buffer[BUFFER_SIZE];

int main()
{
  // int add1;
  // int add2 = 0xff00ff00;
  // int add3;
  // int add4;

  for (int i = 0; i < 16; ++i)
  {
    /* code */
    // add1 = pulp_read32(0x1C022000+i*4);
    // add2 = pulp_read32(0x1C022000+(i+1)*4);
    // add3 = add1-add2;
    // add4 = add1+add2;
    pulp_write32(0x1C030000 + i * 4, 0xff00ff00);
  }

  pwm_test();
  // gpio_test();
  uart_test();

  // timer_test();
  // i2c_test();

  return 0;
}



void gpio_test()
{
  PAD_MUX_FUN0(FUN_GPIO0 | FUN_GPIO1, ENABLE);
  // pulp_write32(0x1A101010, 1 << 0 | 1 << 2);
  // pulp_write32(0x1A101014, 0x0);
  // mDelaymS(1000);
  GPIOA_ModeCfg(GPIO_Pin_0 | GPIO_Pin_1, GPIO_ModeOut);
  GPIOA_SetBits(GPIO_Pin_0 | GPIO_Pin_1);

  // pulp_write32(0x1a100000, 0x3);
  // pulp_write32(0x1a100000 + 0x08, 0x3);

  // pulp_read32(0x1a100000 + 0x04);
  // enable gpio
  // pulp_write32(0x1a100000 + 0x1c, 0x07);
  // pulp_read32(0x1a100000 + 0x04);
  // printf("---- CLKEXT ENABLE--- !\n");
  // clkext
  // pulp_write32(0x1a101000 + 0x10, 1<<3|1<<1);
  // printf("---- CLKEXT DISABLE--- !\n");
  // clkext
  // pulp_write32(0x1a101000 + 0x10, 0x00);
  while (1)
  {
    // mDelaymS(1000);
    mDelayuS(100);
    // pulp_write32(0x1a100000, 0x3);
    // pulp_write32(0x1a100000 + 0x08, 0);
    GPIOA_ResetBits(GPIO_Pin_0 | GPIO_Pin_1);
    // mDelaymS(1000);
    mDelayuS(100);
    // pulp_write32(0x1a100000, 0x3);
    // pulp_write32(0x1a100000 + 0x08, 0x3);
    GPIOA_SetBits(GPIO_Pin_0 | GPIO_Pin_1);
    mDelayuS(100);
    /* code */
  }
}


void pwm_test()
{
  uint16_t pwm_hi = 0;
  uint16_t pwm_lo = 0;
  PWMX_CLKCfg(255); // PWM的基准频率
  //
  pwm_hi = PWMX_CycleCfg(PWMX_Cycle_12);
  pwm_lo = pwm_hi / 8;
  PWMX_ACTOUT(CH_PWM2 | CH_PWM3, pwm_hi, pwm_lo, ENABLE);
  // while(1);
}

void uart_test()
{
  uint8_t send_buf[8]={1,2,3,4,5,6,7,8};
  unsigned char sbuf[] = "Hello World!\n";
  UART0_DefInit(115200,1);
  while(1){
    mDelaymS(500);
    // if(UART0_RecvByte()!=0)
      // R32_uart0_tx_cfg |= CFG_en;
    soc_printf("hello,huangjin\n");
    // mDelaymS(100);
    // soc_printf("8");
    printf("hello\n");
    // UART0_SendByte(8);
    // mDelaymS(100);
  }
}

void timer_test()
{

  uint32_t i;
  uint32_t j;
  // R32_timer0_cmp_lo = (uint32_t)255;
  // R32_timer0_cnt_lo = (uint32_t)0;
  // R32_timer0_cfg_lo = (uint32_t)0x00018051;
  // R32_timer0_start_lo=(uint32_t)0x01;


  TIM_InitTypeDef TIM_InitStructure = {0};
  TIM_InitStructure.Clock_Mux = (~REF_CLK_EN_BIT);           // 0:64M 1:10M
  TIM_InitStructure.TIME_Mode = (uint32_t)(CMP_CLR_BIT);        // 连续比较功能
  TIM_InitStructure.TIME_INTEN = (~IRQ_BIT);                    // 中断使能禁止
  TIM_InitStructure.TIME_OutputClock = (uint32_t)500000; // 分频系数配置
  TIM_InitStructure.TIME_CNT = (uint32_t)0;                     // 计数器初始值设为0
  TIM_InitStructure.TIME_CMP = (uint32_t)255;                 // 初始值1ms中断触发
  TIM_InitStructure.TIME_Reset = TIME_START_0;
  TIM_InitStructure.TIME_Start = TIM_START_1;

  // TIM_StructInit(&TIM_InitStructure);
  TMR_TimerInit(&TIM_InitStructure, cfg_lo);
  // TMR_TimerInit(&TIM_InitStructure, cfg_hi);
  // TIM_SetCounter(16000,)
  // TMR0_Enablelo();
  // TMR0_Enablehi();

  // GPIOA_ResetBits(GPIO_Pin_0 | GPIO_Pin_1);

  while(1)
  {
    i = R32_timer0_cnt_lo;
    // j=TIM_GetCounter(cfg_hi);
    if (i > 128)
      for (i = 0; i < 100; i++)
      {
        PWM_DISNABLE(CH_PWM2 | CH_PWM3);
        mDelaymS(500);
        PWM_ENABLE(CH_PWM2 | CH_PWM3);
        mDelaymS(500);
      }
    else 
      ;
    // if (R32_timer0_cmp_lo != 5000)
    // {

    // }
    // else ;

  }
}

void i2c_test()
{
  uint32_t i;
  uint8_t j;
  uint8_t send_buf[2] = {0x78, 0x55};

  I2C_InitTypeDef I2C_InitStructure = {0};
  I2C_InitStructure.I2C_ClockSpeed = 5000;
  I2C_InitStructure.I2C_Mode = I2C_Mode_Master;
  I2C_InitStructure.I2C_OwnAddress1 = 0;
  I2C_InitStructure.I2C_rx_addr = RV_Udma_I2C_RX_ADDR;
  I2C_InitStructure.I2C_tx_addr = RV_Udma_I2C_TX_ADDR;

  I2C_Init(pad_i2c0, &I2C_InitStructure, udma_tx_ptr2);
  // I2C_Cmd(pad_i2c0 , 3, RV_Udma_I2C_TX_ADDR , ENABLE , WRITE);
  j=4;
  I2C_GenerateSTART(udma_tx_ptr2,j,ENABLE);
  j=j+1;
  j=I2C_SendData(pad_i2c0 , udma_tx_ptr2 , j, send_buf, 2);
  j=j+1;
  I2C_GenerateSTOP(udma_tx_ptr2,j,ENABLE);
  I2C_Cmd(pad_i2c0, j, RV_Udma_I2C_TX_ADDR, ENABLE, WRITE);
  while (1)
  {
    // I2C_Cmd(pad_i2c0, 3, RV_Udma_I2C_TX_ADDR, ENABLE, Continuous);
    PWM_DISNABLE(CH_PWM2 | CH_PWM3);
    // OLED_WR_Byte(send_buf);
    mDelayuS(800);
    // OLED_WR_Byte(send_buf);
    // j = I2C_SendData(pad_i2c0, udma_tx_ptr2, j, send_buf, 3);
    // I2C_Cmd(pad_i2c0, j, RV_Udma_I2C_TX_ADDR, ENABLE, WRITE);
    PWM_ENABLE(CH_PWM2 | CH_PWM3);
    mDelayuS(800);


  }
}
void OLED_WR_Byte(uint8_t *dat)
{
  int32_t i32Ret;
  int32_t sram_addr = 0x40110;
  int32_t sram_addr_offset = 0x4;
  // int tx_size = 0x03;

  hal_soc_i2c0_set(0x1c040110, 0x0002E002);
  hal_soc_i2c0_set(0x1c040114, (0x00000080 | (0x78 << 8) | (dat[0] << 16) | (dat[1] << 24)));
  hal_soc_i2c0_set(0x1c040118, 0x00000020);

  // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR, 0x01);
  // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR, 0x00);
  // hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR, 0);
  hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR, 1 << 6);
  // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR, 0);
  hal_soc_i2c0_set(PERI_I2C0_TX_SADDR_ADDR, sram_addr);
  hal_soc_i2c0_set(PERI_I2C0_TX_SIZE_ADDR, 9);
  // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR, (1 << 8 | 1 << 1 | 1 << 2)); // 8bits,no parity,1stopbit
  hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR, (1 << 4) );
  // Delay(10000);
}
