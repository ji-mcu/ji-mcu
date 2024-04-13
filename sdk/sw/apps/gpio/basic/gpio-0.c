#include <stdio.h>
//#include <rt/rt_api.h>
#include <stdint.h>

#include "gpio-0.h"
#include "hal/pulp_io.h"
void hal_soc_gpio_set(unsigned int addr,unsigned int value)
{
  int intc_val_tmp;
  printf("gpio0_write_add:%x\n",addr);
  intc_val_tmp = pulp_write32( addr,value);
  printf("gpio0_write_val:%x\n",intc_val_tmp);
  
  
}

void hal_soc_gpio0_read(unsigned int addr)
{
  int read_val;
  printf("gpio0_read_add:%x\n",addr);
  read_val = pulp_read( addr );
  //if(read_val==exp_value)
    printf("data read ok:%x\n",read_val);
  //else 
  //  printf("ERROR,read %x VS exp:%x\n",read_val,exp_value);
  //return read_val; 
  
}

void gpio_reg_test()
{
  printf("gpio0 reg test...\n");
  hal_soc_gpio_set(PERI_GPIO0_PADDIR_ADDR,0x01);
  hal_soc_gpio0_read(PERI_GPIO0_PADDIR_ADDR);
  
  hal_soc_gpio_set(PERI_GPIO0_PADIN_ADDR,0x12);
  hal_soc_gpio0_read(PERI_GPIO0_PADIN_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADOUT_ADDR,0x23);
  hal_soc_gpio0_read(PERI_GPIO0_PADOUT_ADDR);
 
  hal_soc_gpio_set(PERI_GPIO0_INTEN_ADDR,0x34);
  hal_soc_gpio0_read(PERI_GPIO0_INTEN_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_INTTYPE0_ADDR,0x45);
  hal_soc_gpio0_read(PERI_GPIO0_INTTYPE0_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_INTTYPE1_ADDR,0x56);
  hal_soc_gpio0_read(PERI_GPIO0_INTTYPE1_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_INTSTATUS_ADDR,0x67);
  hal_soc_gpio0_read(PERI_GPIO0_INTSTATUS_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_EN_ADDR,0x78);
  hal_soc_gpio0_read(PERI_GPIO0_EN_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADCFG0_ADDR,0x89);
  hal_soc_gpio0_read(PERI_GPIO0_PADCFG0_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADCFG1_ADDR,0x9a);
  hal_soc_gpio0_read(PERI_GPIO0_PADCFG1_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADCFG2_ADDR,0xab);
  hal_soc_gpio0_read(PERI_GPIO0_PADCFG2_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADCFG3_ADDR,0xbc);
  hal_soc_gpio0_read(PERI_GPIO0_PADCFG3_ADDR);
 
  hal_soc_gpio_set(PERI_GPIO0_PADCFG4_ADDR,0xcd);
  hal_soc_gpio0_read(PERI_GPIO0_PADCFG4_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADCFG5_ADDR,0xde);
  hal_soc_gpio0_read(PERI_GPIO0_PADCFG5_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADCFG6_ADDR,0xef);
  hal_soc_gpio0_read(PERI_GPIO0_PADCFG6_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADCFG7_ADDR,0xf0);
  hal_soc_gpio0_read(PERI_GPIO0_PADCFG7_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADOUTSET_ADDR,0x3e);
  hal_soc_gpio0_read(PERI_GPIO0_PADOUTSET_ADDR);

  hal_soc_gpio_set(PERI_GPIO0_PADOUTCLR_ADDR,0x2A);
  hal_soc_gpio0_read(PERI_GPIO0_PADOUTCLR_ADDR);


}

void gpio_input_test()
{
  printf("gpio0 input test...\n");
  hal_soc_gpio_set(PERI_GPIO0_PADDIR_ADDR,0x00f);
  hal_soc_gpio_set(PERI_GPIO0_EN_ADDR,0x0fff);
  hal_soc_gpio0_read(PERI_GPIO0_PADIN_ADDR);


}

void gpio_output_test()
{
   printf("gpio0 output test...\n");
   hal_soc_gpio_set(PERI_GPIO0_PADDIR_ADDR,0x1f0);
   hal_soc_gpio_set(PERI_GPIO0_PADOUT_ADDR,0x00);
   hal_soc_gpio0_read(PERI_GPIO0_PADOUT_ADDR);
   hal_soc_gpio_set(PERI_GPIO0_PADOUT_ADDR,0x01);
   hal_soc_gpio0_read(PERI_GPIO0_PADOUT_ADDR);
   hal_soc_gpio_set(PERI_GPIO0_PADOUT_ADDR,0x02);
   hal_soc_gpio0_read(PERI_GPIO0_PADOUT_ADDR);
   hal_soc_gpio_set(PERI_GPIO0_PADOUT_ADDR,0x03);
   hal_soc_gpio0_read(PERI_GPIO0_PADOUT_ADDR);
}

void gpio_interrupt_set()
{
  printf("gpio0 output test...\n");
  hal_soc_gpio_set(0x1a104010,0x01<<15|0x01<<17);
  hal_soc_gpio_set(PERI_GPIO0_INTEN_ADDR,0xffff);
  hal_soc_gpio_set(PERI_GPIO0_EN_ADDR,0xffff);
  hal_soc_gpio_set(PERI_GPIO0_PADDIR_ADDR,0x1f0);
  hal_soc_gpio_set(PERI_GPIO0_PADDIR_ADDR,0x00f);
}
