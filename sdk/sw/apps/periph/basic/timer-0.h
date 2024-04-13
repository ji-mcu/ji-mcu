#ifndef __ARCHI_PULPISSIMO_MEMORY_MAP_H_TIMER0__
#define __ARCHI_PULPISSIMO_MEMORY_MAP_H_TIMER0__



/*
 * SOC PERIPHERALS
 */

#define PERI_TIMER0_ADDR                      0x1A107000


#define TIMER0_CFG_LO_OFFSET                   0x00
#define TIMER0_CFG_HI_OFFSET                   0x04
#define TIMER0_CNT_LO_OFFSET                   0x08
#define TIMER0_CNT_HI_OFFSET                   0x0C
#define TIMER0_CMP_LO_OFFSET                   0x10
#define TIMER0_CMP_HI_OFFSET                   0x14
#define TIMER0_START_LO_OFFSET                 0x18
#define TIMER0_START_HI_OFFSET                 0x1C
#define TIMER0_RESET_LO_OFFSET                 0x20
#define TIMER0_RESET_HI_OFFSET                 0x24



#define PERI_TIMER0_CFG_LO_ADDR              ( PERI_TIMER0_ADDR + TIMER0_CFG_LO_OFFSET )
#define PERI_TIMER0_CFG_HI_ADDR              ( PERI_TIMER0_ADDR + TIMER0_CFG_HI_OFFSET )
#define PERI_TIMER0_CNT_LO_ADDR              ( PERI_TIMER0_ADDR + TIMER0_CNT_LO_OFFSET )
#define PERI_TIMER0_CNT_HI_ADDR              ( PERI_TIMER0_ADDR + TIMER0_CNT_HI_OFFSET )
#define PERI_TIMER0_CMP_LO_ADDR              ( PERI_TIMER0_ADDR + TIMER0_CMP_LO_OFFSET )
#define PERI_TIMER0_CMP_HI_ADDR              ( PERI_TIMER0_ADDR + TIMER0_CMP_HI_OFFSET )
#define PERI_TIMER0_START_LO_ADDR            ( PERI_TIMER0_ADDR + TIMER0_START_LO_OFFSET )
#define PERI_TIMER0_START_HI_ADDR            ( PERI_TIMER0_ADDR + TIMER0_START_HI_OFFSET )
#define PERI_TIMER0_RESET_LO_ADDR            ( PERI_TIMER0_ADDR + TIMER0_RESET_LO_OFFSET )
#define PERI_TIMER0_RESET_HI_ADDR            ( PERI_TIMER0_ADDR + TIMER0_RESET_HI_OFFSET )






//void uart_basic_function_test();
//void uart_tx_test(int ram_addr,int tx_size,int setup);
//void uart_rx_test(int ram_addr,int rx_size,int setup);
void timer0_reg_test();
void reg_access(unsigned int addr,unsigned int value);
void timer0_function_test();
void i2d_tx_test(int ram_addr,int tx_size);
void i2d_rx_test(int tx_ram_addr,int rx_ram_addr,int tx_size,int rx_size);

void hal_soc_i2c0_set(unsigned int addr,unsigned int value);
int hal_soc_i2c0_read(unsigned int addr);

#endif


