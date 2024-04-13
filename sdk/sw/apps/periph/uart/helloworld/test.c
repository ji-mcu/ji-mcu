#include <stdio.h>
#include <rt/rt_api.h>
#include <stdint.h>

extern void rt_time_wait_us(int time_us);

int main()
{

  unsigned char sbuf[] = "Hello World!\n";

  rt_uart_conf_t conf;

  rt_uart_conf_init(&conf);

  // This will tell the driver to use the uart 0 interface (in case there are several)
  conf.itf = 0;

  rt_uart_t *uart = rt_uart_open(NULL, &conf, NULL);
  if (uart == NULL) return -1;


  rt_uart_write(uart, sbuf, sizeof(sbuf), NULL);

   // wait some time to ensure all date to be transmitted.
  rt_time_wait_us(10);

  rt_uart_close(uart, NULL);

  return 0;
}
