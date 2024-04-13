#include <stdio.h>
//#include <rt/rt_api.h>
#include <stdint.h>
#include "hal/pulp_io.h"

#include "uart.h"

void rt_uart_conf_init(rt_uart_conf_t *conf)
{
  conf->baudrate = __RT_UART_BAUDRATE;
  conf->itf = -1;
}


rt_event_t *rt_event_get_blocking(rt_event_sched_t *sched)
{
  //int irq = rt_irq_disable();
  //if (!sched) sched = __rt_thread_current->sched;
  //rt_event_t *event = __rt_get_event(sched, NULL, NULL);
  //if (event) {
  //  event->sched = sched;
  //  event->pending = 1;
  //}
  //rt_irq_restore(irq);
  //return event;
}

void rt_time_wait_us(int time_us)
{
  rt_event_t *event = NULL;//rt_event_get_blocking(NULL);
  //rt_event_push_delayed(event, time_us);
  //rt_event_wait(event);
}

void hal_soc_uart0_set(unsigned int addr,unsigned int value)
{
  int intc_val_tmp;
  //printf("uart0_write_add:%x\n",addr);
  intc_val_tmp = pulp_write32( addr,value);
  //printf("uart0_write_val:%x\n",intc_val_tmp);
  
  
}

int hal_soc_uart0_read(unsigned int addr)
{
  int read_val;
  //printf("uart0_read_add:%x\n",addr);
  read_val = pulp_read( addr );
  //if(read_val==exp_value)
    //printf("data read ok:%x\n",read_val);
  //else 
  //  printf("ERROR,read %x VS exp:%x\n",read_val,exp_value);
  return read_val; 
  
}


void uart_basic_function_test()
{
  hal_soc_uart0_set(PERI_UART0_RX_SADDR_ADDR,0x3e80);
  hal_soc_uart0_read(PERI_UART0_RX_SADDR_ADDR);

  hal_soc_uart0_set(PERI_UART0_RX_SIZE_ADDR,0x32);
  hal_soc_uart0_read(PERI_UART0_RX_SIZE_ADDR);

  hal_soc_uart0_set(PERI_UART0_RX_CFG_ADDR,0x57);
  hal_soc_uart0_read(PERI_UART0_RX_CFG_ADDR);
 
  hal_soc_uart0_set(PERI_UART0_TX_SADDR_ADDR,0x20);
  hal_soc_uart0_read(PERI_UART0_TX_SADDR_ADDR);

  hal_soc_uart0_set(PERI_UART0_TX_SIZE_ADDR,0x02);
  hal_soc_uart0_read(PERI_UART0_TX_SIZE_ADDR);

  hal_soc_uart0_set(PERI_UART0_TX_CFG_ADDR,0xe6);
  hal_soc_uart0_read(PERI_UART0_TX_CFG_ADDR);
 
  hal_soc_uart0_set(PERI_UART0_STATUS_ADDR,0xe6);
  hal_soc_uart0_read(PERI_UART0_STATUS_ADDR);
  
  hal_soc_uart0_set(PERI_UART0_SETUP_ADDR,0xf2);
  hal_soc_uart0_read(PERI_UART0_SETUP_ADDR);
 
  hal_soc_uart0_set(PERI_UART0_ERROR_ADDR,0x29);
  hal_soc_uart0_read(PERI_UART0_ERROR_ADDR);

  //printf("start send data by uart...\n");
  hal_soc_uart0_set(PERI_UART0_SETUP_ADDR,0x100);
  hal_soc_uart0_set(PERI_UART0_TX_CFG_ADDR,0x10);
  //hal_soc_uart0_read(PERI_UART0_TX_CFG_ADDR);
  //
  hal_soc_uart0_set(PERI_UART0_TX_SADDR_ADDR,0x1a102080);
  hal_soc_uart0_set(PERI_UART0_TX_CFG_ADDR,0x10);

  hal_soc_uart0_set(PERI_UART0_SETUP_ADDR,0x200);

}

void uart0_tx_test(int ram_addr,int tx_size,int setup)
{
  // printf("uart tx test...\n");
  hal_soc_uart0_set(PERI_UART0_SETUP_ADDR,0);
  hal_soc_uart0_set(PERI_UART0_TX_CFG_ADDR,1<<6);//clear transfer
  hal_soc_uart0_set(PERI_UART0_TX_SADDR_ADDR,ram_addr);//0x1770);//ram addr:d1500
  hal_soc_uart0_set(PERI_UART0_TX_SIZE_ADDR,tx_size);//0x0b);//transfer num:'d11
  hal_soc_uart0_set(PERI_UART0_SETUP_ADDR,setup);//1<<8|1<<1|1<<2);//uart tx,8bits,no parity,1stopbit
  hal_soc_uart0_set(PERI_UART0_TX_CFG_ADDR,1<<4);//enable transfer

}

void uart1_tx_test(int ram_addr,int tx_size,int setup)
{
  // printf("uart tx test...\n");
  hal_soc_uart0_set(PERI_UART1_SETUP_ADDR,0);
  hal_soc_uart0_set(PERI_UART1_TX_CFG_ADDR,1<<6);//clear transfer
  hal_soc_uart0_set(PERI_UART1_TX_SADDR_ADDR,ram_addr);//0x1770);//ram addr:d1500
  hal_soc_uart0_set(PERI_UART1_TX_SIZE_ADDR,tx_size);//0x0b);//transfer num:'d11
  hal_soc_uart0_set(PERI_UART1_SETUP_ADDR,setup);//1<<8|1<<1|1<<2);//uart tx,8bits,no parity,1stopbit
  hal_soc_uart0_set(PERI_UART1_TX_CFG_ADDR,1<<4);//enable transfer

}


void uart0_rx_test(int ram_addr,int rx_size,int setup)
{
  printf("uart rx test...\n");
  hal_soc_uart0_set(PERI_UART0_SETUP_ADDR,1<<5);
  hal_soc_uart0_set(PERI_UART0_RX_CFG_ADDR,1<<6);//clear transfer
  hal_soc_uart0_set(PERI_UART0_RX_SADDR_ADDR,ram_addr);//0x1770);//ram addr:d1500
  hal_soc_uart0_set(PERI_UART0_RX_SIZE_ADDR,rx_size);//0x0b);//transfer num:'d11
  hal_soc_uart0_set(PERI_UART0_SETUP_ADDR,setup);//1<<8|1<<1|1<<2);//uart tx,8bits,no parity,1stopbit
  hal_soc_uart0_set(PERI_UART0_RX_CFG_ADDR,1<<4);//enable transfer

}

void uart1_rx_test(int ram_addr,int rx_size,int setup)
{
  printf("uart rx test...\n");
  hal_soc_uart0_set(PERI_UART1_SETUP_ADDR,1<<5);
  hal_soc_uart0_set(PERI_UART1_RX_CFG_ADDR,1<<6);//clear transfer
  hal_soc_uart0_set(PERI_UART1_RX_SADDR_ADDR,ram_addr);//0x1770);//ram addr:d1500
  hal_soc_uart0_set(PERI_UART1_RX_SIZE_ADDR,rx_size);//0x0b);//transfer num:'d11
  hal_soc_uart0_set(PERI_UART1_SETUP_ADDR,setup);//1<<8|1<<1|1<<2);//uart tx,8bits,no parity,1stopbit
  hal_soc_uart0_set(PERI_UART1_RX_CFG_ADDR,1<<4);//enable transfer

}

