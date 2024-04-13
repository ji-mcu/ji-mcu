#include <stdio.h>
#include <stdint.h>
#include "timer-0.h"
#include "hal/pulp_io.h"
#include "hal/itc/itc_v1.h"

#define BUFFER_SIZE 3


int main()
{
  int i;
  printf("Entering timer0 test!~\n");

  hal_itc_enable_set(1 << 10);
 
  timer0_function_test();
  while(1);

  return 0;
}
