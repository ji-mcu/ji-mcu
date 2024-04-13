#include <stdio.h>
//#include <rt/rt_api.h>
#include <stdint.h>
#include "hal/pulp_io.h"
#include "i2c-0.h"

void hal_soc_i2c0_set(unsigned int addr,unsigned int value)
{
  int intc_val_tmp;
  //printf("i2c0_write_add:%x\n",addr);
  intc_val_tmp = pulp_write32( addr,value);
  //printf("i2c0_write_val:%x\n",intc_val_tmp);
  
  
}


int hal_soc_i2c0_read(unsigned int addr)
{
  int read_val;
  //printf("i2c0_read_add:%x\n",addr);
  read_val = pulp_read( addr );
  //if(read_val==exp_value)
    //printf("data read ok:%x\n",read_val);
  //else 
  //  printf("ERROR,read %x VS exp:%x\n",read_val,exp_value);
  return read_val; 
  
}

void i2c_reg_test()
{
  //printf("test reg accessibility\n");
  hal_soc_i2c0_set(PERI_I2C0_RX_SADDR_ADDR,0x200);
  hal_soc_i2c0_read(PERI_I2C0_RX_SADDR_ADDR);
  
  hal_soc_i2c0_set(PERI_I2C0_RX_SIZE_ADDR,0x02);
  hal_soc_i2c0_read(PERI_I2C0_RX_SIZE_ADDR);

  hal_soc_i2c0_set(PERI_I2C0_RX_CFG_ADDR,0x2a);
  hal_soc_i2c0_read(PERI_I2C0_RX_CFG_ADDR);

  hal_soc_i2c0_set(PERI_I2C0_TX_SADDR_ADDR,0x2a0);
  hal_soc_i2c0_read(PERI_I2C0_TX_SADDR_ADDR);

  hal_soc_i2c0_set(PERI_I2C0_TX_SIZE_ADDR,0x04);
  hal_soc_i2c0_read(PERI_I2C0_TX_SIZE_ADDR);

  hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR,0x32);
  hal_soc_i2c0_read(PERI_I2C0_TX_CFG_ADDR);

  //hal_soc_i2c0_set(PERI_I2C0_CMD_SADDR_ADDR,0xe1);
  //hal_soc_i2c0_read(PERI_I2C0_CMD_SADDR_ADDR);
  hal_soc_i2c0_set(PERI_I2C0_STATUS_ADDR,0xcb);
  hal_soc_i2c0_read(PERI_I2C0_STATUS_ADDR);

  hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x23);
  hal_soc_i2c0_read(PERI_I2C0_SETUP_ADDR);




}


void i2c0_tx_test(int ram_addr,int tx_size)
{
   //printf("i2c tx test...\n");
   // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x01);
   // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x00);
   hal_soc_i2c0_set(PERI_I2C0_TX_SADDR_ADDR,ram_addr);//0x10);
   hal_soc_i2c0_set(PERI_I2C0_TX_SIZE_ADDR,tx_size);//0x02);
   hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR,1<<4);
}

void i2c1_tx_test(int ram_addr,int tx_size)
{
   //printf("i2c tx test...\n");
   // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x01);
   // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x00);
   hal_soc_i2c0_set(PERI_I2C1_TX_SADDR_ADDR,ram_addr);//0x10);
   hal_soc_i2c0_set(PERI_I2C1_TX_SIZE_ADDR,tx_size);//0x02);
   hal_soc_i2c0_set(PERI_I2C1_TX_CFG_ADDR,1<<4);
}

void i2c0_rx_test(int tx_ram_addr,int rx_ram_addr,int tx_size,int rx_size)
{
   //printf("i2c rx test...\n");
   // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x01);
   // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x00);
   hal_soc_i2c0_set(PERI_I2C0_TX_SADDR_ADDR,tx_ram_addr);//0x10);
   hal_soc_i2c0_set(PERI_I2C0_TX_SIZE_ADDR,tx_size);//0x02);
   hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR,1<<4);

   // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x01);
   // hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR,0x00);
   // hal_soc_i2c0_set(PERI_I2C0_RX_CFG_ADDR,1<<6);
   hal_soc_i2c0_set(PERI_I2C0_RX_SADDR_ADDR,rx_ram_addr);//0x10);
   hal_soc_i2c0_set(PERI_I2C0_RX_SIZE_ADDR,rx_size);//0x02);
   hal_soc_i2c0_set(PERI_I2C0_RX_CFG_ADDR,1<<4);
   
   


}


