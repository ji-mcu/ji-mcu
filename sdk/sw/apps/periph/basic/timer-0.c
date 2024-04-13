#include <stdio.h>
//#include <rt/rt_api.h>
#include <stdint.h>
#include "hal/pulp_io.h"
#include "timer-0.h"

void hal_soc_timer0_set(unsigned int addr,unsigned int value)
{
  int intc_val_tmp;
  printf("timer0_write_add:%x\n",addr);
  intc_val_tmp = pulp_write32( addr,value);
  printf("timer0_write_val:%x\n",intc_val_tmp);
  
  
}


int hal_soc_timer0_read(unsigned int addr)
{
  int read_val;
  printf("timer0_read_add:%x\n",addr);
  read_val = pulp_read( addr );
  //if(read_val==exp_value)
    printf("data read ok:%x\n",read_val);
  //else 
  //  printf("ERROR,read %x VS exp:%x\n",read_val,exp_value);
  return read_val; 
  
}
void reg_access(unsigned int addr,unsigned int value)
{
  hal_soc_timer0_set(addr,value);
  hal_soc_timer0_read(addr);
}
void timer0_reg_test()
{
  printf("test reg accessibility\n");
  reg_access(PERI_TIMER0_CFG_LO_ADDR,0x20A);
  reg_access(PERI_TIMER0_CFG_HI_ADDR,0x142f);
  reg_access(PERI_TIMER0_CNT_LO_ADDR,0x3a27);
  reg_access(PERI_TIMER0_CNT_HI_ADDR,0x792a);
  reg_access(PERI_TIMER0_CMP_LO_ADDR,0x2233);
  reg_access(PERI_TIMER0_CMP_LO_ADDR,0x5566);
  reg_access(PERI_TIMER0_START_LO_ADDR,0x5a12);
  reg_access(PERI_TIMER0_START_HI_ADDR,0x1000);
  reg_access(PERI_TIMER0_RESET_LO_ADDR,0x1234);
  reg_access(PERI_TIMER0_RESET_HI_ADDR,0x0231);


  


}


void timer0_function_test(int ram_addr,int tx_size)
{
   printf("timer0 function test...\n");
   

   hal_soc_timer0_set(PERI_TIMER0_RESET_LO_ADDR,0x0);
   hal_soc_timer0_set(PERI_TIMER0_RESET_HI_ADDR,0x0);
   hal_soc_timer0_set(PERI_TIMER0_CMP_LO_ADDR,0x20000);
   hal_soc_timer0_set(PERI_TIMER0_CFG_LO_ADDR,0x0607);
   
}

/*void i2d_rx_test(int tx_ram_addr,int rx_ram_addr,int tx_size,int rx_size)
{
   printf("i2c rx test...\n");
   hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x01);
   hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x00);
   hal_soc_i2c0_set(PERI_I2C0_TX_SADDR_ADDR,tx_ram_addr);//0x10);
   hal_soc_i2c0_set(PERI_I2C0_TX_SIZE_ADDR,tx_size);//0x02);
   hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR,1<<4);

   hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x01);
   hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x00);
   hal_soc_i2c0_set(PERI_I2C0_RX_CFG_ADDR,1<<6);
   hal_soc_i2c0_set(PERI_I2C0_RX_SADDR_ADDR,rx_ram_addr);//0x10);
   hal_soc_i2c0_set(PERI_I2C0_RX_SIZE_ADDR,rx_size);//0x02);
   hal_soc_i2c0_set(PERI_I2C0_RX_CFG_ADDR,1<<4);
   
   


}*/


