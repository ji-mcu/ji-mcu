#include <stdio.h>
//#include <rt/rt_api.h>
#include <stdint.h>
#include "uart.h"
#include "hal/pulp_io.h"

// extern void rt_time_wait_us(int time_us);

int main()
{
  //printf("uart function test1....\n");
  //printf("mult:%f\n",c);
  //printf("size c:%d\n",sizeof(int));
  //a=c; 

  int tx_cur_addr;

  // unsigned char sbuf[] = "Hello World!\n";
  // hal_soc_uart0_set(0x1a120000,25);
  // hal_soc_uart0_set(0x1a109000,1<<26);
  // hal_soc_uart0_set(0x1a106004,0xfffffffe);
  pulp_write32(0x1A101010,1<<12|1<<14);
  pulp_write32(0x1A101014,0x0);

  //set uart1 mux output
  pulp_write32(0x1A101010,0x5000);

  //uart_basic_function_test();
  hal_soc_uart0_set(0x1c000100,0x12345678);
  hal_soc_uart0_set(0x1c000104,0xf0f1f2f3);
  hal_soc_uart0_set(0x1c000108,0xc1c2c3c4);
  hal_soc_uart0_set(0x1c00010c,0xa6a7a8a9);
  hal_soc_uart0_set(0x1c000110,0xb6b7b8b9);
  hal_soc_uart0_set(0x1c000114,0xffffffff);
  hal_soc_uart0_set(0x1c000118,0x55555555);
  
  // while(1)
  // {
  //------------------------------------------
  //ram 1500,tx 11,8bit mode, no parity,1stop bit 
  // uart0_tx_test(0x100,0x1C,1<<8|1<<1|1<<2);
  // uart1_tx_test(0x100,0x1C,1<<8|1<<1|1<<2);
  uart0_rx_test(0x400 ,0x06,8<<16|1<<9|1<<1|1<<2);
  uart1_rx_test(0x400 ,0x06,8<<16|1<<9|1<<1|1<<2);

  // tx_cur_addr = pulp_read32(PERI_UART0_TX_SADDR_ADDR);
  // pulp_write32(0x1A101000,tx_cur_addr);
  //while(hal_soc_uart0_read(PERI_UART0_STATUS_ADDR));
  //ram 1600,tx 39,8bit mode, no parity,2stop bit
  //uart_tx_test(0x1900,0x36,1<<8|1<<1|1<<2|1<<3);
  //ram 1700,tx 39,8bit mode, parity en,2stop bit
  //uart_tx_test(0x1a90,0x6,1<<8|1<<0|1<<1|1<<2|1<<3);
  // ram 4000,rx 6,8bit mode,no parity,1stop bit
  //ram pr2,rx 6,8bit mode,no parity,1stop bit
  //uart_rx_test(0x8000,0x04,1000<<16|1<<9|1<<1|1<<2);
  //rt_uart_conf_t conf;
  // }
  //rt_uart_conf_init(&conf);

  // This will tell the driver to use the uart 0 interface (in case there are several)
  //conf.itf = 0;

  //rt_uart_t *uart = rt_uart_open(NULL, &conf, NULL);
  //if (uart == NULL) return -1;


  //rt_uart_write(uart, sbuf, sizeof(sbuf), NULL);

   // wait some time to ensure all date to be transmitted.
  //rt_time_wait_us(10);

  //rt_uart_close(uart, NULL);
  while(1);
  return 0;
}
