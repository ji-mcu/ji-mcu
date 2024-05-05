#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <hal/pulp.h>
#include "hal/pulp_io.h"
#include "gpio-0.h"

static void hal_soc_gpio_set(unsigned int addr, unsigned int value)
{
  int intc_val_tmp;
  // printf("gpio0_write_add:%x\n", addr);
  intc_val_tmp = pulp_write32(addr, value);
  // printf("gpio0_write_val:%x\n", intc_val_tmp);
}

static void hal_soc_gpio0_read(unsigned int addr)
{
  int read_val;
  printf("gpio0_read_add:%x\n", addr);
  read_val = pulp_read(addr);
  // printf("data read ok:%x\n", read_val);
}

void gpio_output_test()
{
  printf("gpio0 output test...\n");
  hal_soc_gpio_set(PERI_GPIO0_PADDIR_ADDR, 0x1f0);
  hal_soc_gpio_set(PERI_GPIO0_PADOUT_ADDR, 0x00);
  hal_soc_gpio0_read(PERI_GPIO0_PADOUT_ADDR);
  hal_soc_gpio_set(PERI_GPIO0_PADOUT_ADDR, 0x01);
  hal_soc_gpio0_read(PERI_GPIO0_PADOUT_ADDR);
  hal_soc_gpio_set(PERI_GPIO0_PADOUT_ADDR, 0x02);
  hal_soc_gpio0_read(PERI_GPIO0_PADOUT_ADDR);
  hal_soc_gpio_set(PERI_GPIO0_PADOUT_ADDR, 0x03);
  hal_soc_gpio0_read(PERI_GPIO0_PADOUT_ADDR);
}
