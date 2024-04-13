/* 
  File : core_portme.c
*/
/*
  Author : Shay Gal-On, EEMBC
  Legal : TODO!
*/ 
#include <stdio.h>
#include <stdlib.h>
#include "core_portme.h"

/* Porting : Timing functions
  How to capture time and convert to seconds must be ported to whatever is supported by the platform.
  e.g. Read value from on board RTC, read value from cpu clock cycles performance counter etc. 
  Sample implementation for standard time.h and windows.h definitions included.
*/
/* Define : TIMER_RES_DIVIDER
  Divider to trade off timer resolution and total time that can be measured.

  Use lower values to increase resolution, but make sure that overflow does not occur.
  If there are issues with the return value overflowing, increase this value.
  */

long time()
{
#ifdef CFG_MCYCLE
  return rt_perf_read(RT_PERF_ACTIVE_CYCLES);   
#else
  return rt_time_get_us();
#endif
}

/* Function : portable_init
  Target specific initialization code
  Test for some common mistakes.
*/
rt_perf_t pulp_perf;

void portable_init(void)
{
#ifdef CFG_MCYCLE
  rt_perf_init(&pulp_perf);
  rt_perf_conf(&pulp_perf, 1<<RT_PERF_ACTIVE_CYCLES);
  rt_perf_reset(&pulp_perf);
  rt_perf_start(&pulp_perf);
#endif

  if (sizeof(ee_ptr_int) != sizeof(ee_u8 *)) {
    ee_printf("ERROR! Please define ee_ptr_int to a type that holds a pointer!\n");
  }
  if (sizeof(ee_u32) != 4) {
    ee_printf("ERROR! Please define ee_u32 to a 32b unsigned type!\n");
  }
  //p->portable_id=1;
}
/* Function : portable_fini
  Target specific final code
*/
void portable_fini(void)
{
  //p->portable_id=0;
}
