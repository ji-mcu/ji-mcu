#ifndef __ARCHI_PULPISSIMO_MEMORY_MAP_H_I2S0__
#define __ARCHI_PULPISSIMO_MEMORY_MAP_H_I2S0__



/*
 * SOC PERIPHERALS
 */

#define PERI_I2S0_ADDR                      0x1A104380
#define PERI_I2S1_ADDR                      0x1A104400


#define I2S0_RX_SADDR_OFFSET                 0x00
#define I2S0_RX_SIZE_OFFSET                  0x04
#define I2S0_RX_CFG_OFFSET                   0x08
#define I2S0_TX_SADDR_OFFSET                 0x40
#define I2S0_TX_SIZE_OFFSET                  0x44
#define I2S0_TX_CFG_OFFSET                   0x48
#define I2S0_TX_SETUP_OFFSET                 0x4C
//#define I2S0_CMD_SADDR_OFFSET                0x20
//#define I2S0_CMD_SIZE_OFFSET                 0x24
//#define I2S0_CMD_CFG_OFFSET                  0x28
// #define I2S0_STATUS_OFFSET                   0x20
#define I2S0_CFG_SETUP_OFFSET                0x24
#define I2S0_SETUP_OFFSET                    0x4C
#define I2S0_MODE_OFFSET                     0x2C

#define PERI_I2S0_RX_SADDR_ADDR            ( PERI_I2S0_ADDR + I2S0_RX_SADDR_OFFSET )
#define PERI_I2S0_RX_SIZE_ADDR             ( PERI_I2S0_ADDR + I2S0_RX_SIZE_OFFSET  )
#define PERI_I2S0_RX_CFG_ADDR              ( PERI_I2S0_ADDR + I2S0_RX_CFG_OFFSET )
#define PERI_I2S0_TX_SADDR_ADDR            ( PERI_I2S0_ADDR + I2S0_TX_SADDR_OFFSET  )
#define PERI_I2S0_TX_SIZE_ADDR             ( PERI_I2S0_ADDR + I2S0_TX_SIZE_OFFSET )
#define PERI_I2S0_TX_CFG_ADDR              ( PERI_I2S0_ADDR + I2S0_TX_CFG_OFFSET  )
#define PERI_I2S0_TX_SETUP_ADDR            ( PERI_I2S0_ADDR + I2S0_TX_SETUP_OFFSET  )
//#define PERI_I2S0_CMD_SADDR_ADDR           ( PERI_I2S0_ADDR + I2S0_CMD_SADDR_OFFSET )
//#define PERI_I2S0_CMD_SIZE_ADDR            ( PERI_I2S0_ADDR + I2S0_CMD_SIZE_OFFSET  )
//#define PERI_I2S0_CMD_CFG_ADDR             ( PERI_I2S0_ADDR + I2S0_CMD_CFG_OFFSET )
// #define PERI_I2S0_STATUS_ADDR              ( PERI_I2S0_ADDR + I2S0_STATUS_OFFSET )
#define PERI_I2S0_RX_MODE_ADDR             ( PERI_I2S0_ADDR + I2S0_MODE_OFFSET )
#define PERI_I2S0_RX_CFG_SETUP_ADDR        ( PERI_I2S0_ADDR + I2S0_CFG_SETUP_OFFSET )
#define PERI_I2S0_SETUP_ADDR               ( PERI_I2S0_ADDR + I2S0_SETUP_OFFSET )

#define PERI_I2S1_RX_SADDR_ADDR            ( PERI_I2S1_ADDR + I2S0_RX_SADDR_OFFSET )
#define PERI_I2S1_RX_SIZE_ADDR             ( PERI_I2S1_ADDR + I2S0_RX_SIZE_OFFSET  )
#define PERI_I2S1_RX_CFG_ADDR              ( PERI_I2S1_ADDR + I2S0_RX_CFG_OFFSET )
#define PERI_I2S1_TX_SADDR_ADDR            ( PERI_I2S1_ADDR + I2S0_TX_SADDR_OFFSET  )
#define PERI_I2S1_TX_SIZE_ADDR             ( PERI_I2S1_ADDR + I2S0_TX_SIZE_OFFSET )
#define PERI_I2S1_TX_CFG_ADDR              ( PERI_I2S1_ADDR + I2S0_TX_CFG_OFFSET  )
//#define PERI_I2S1_CMD_SADDR_ADDR           ( PERI_I2S1_ADDR + I2S0_CMD_SADDR_OFFSET )
//#define PERI_I2S1_CMD_SIZE_ADDR            ( PERI_I2S1_ADDR + I2S0_CMD_SIZE_OFFSET  )
//#define PERI_I2S1_CMD_CFG_ADDR             ( PERI_I2S1_ADDR + I2S0_CMD_CFG_OFFSET )
// #define PERI_I2S1_STATUS_ADDR              ( PERI_I2S1_ADDR + I2S0_STATUS_OFFSET )
#define PERI_I2S1_SETUP_ADDR               ( PERI_I2S1_ADDR + I2S0_SETUP_OFFSET )


//void uart_basic_function_test();
//void uart_tx_test(int ram_addr,int tx_size,int setup);
//void uart_rx_test(int ram_addr,int rx_size,int setup);
void i2s_reg_test();
void i2s0_tx_test(int ram_addr,int tx_size);
void i2s1_tx_test(int ram_addr,int tx_size);
void i2s0_rx_test(int rx_ram_addr,int rx_size);

void hal_soc_i2s0_set(unsigned int addr,unsigned int value);
int hal_soc_i2s0_read(unsigned int addr);

#endif


