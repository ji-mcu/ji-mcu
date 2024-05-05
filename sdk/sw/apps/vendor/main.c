/**
 * @file main.c
 * @brief Main file for the vendor example
 * @version 0.1
 * @date 2020-06-30
 *
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <hal/pulp.h>
#include "hal/pulp_io.h"

int main()
{
  pulp_write32((ARCHI_SOC_EU_ADDR + 0x04), 0xffff7fff);
  pulp_write32((ARCHI_APB_SOC_CTRL_ADDR + 0xD8), 0x1);

  printf("wating temp interrupt!!\n");

  return 0;
}
