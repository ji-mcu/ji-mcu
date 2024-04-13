#ifndef __ARCHI_PULPISSIMO_MEMORY_MAP_H_I2C0__
#define __ARCHI_PULPISSIMO_MEMORY_MAP_H_I2C0__



/*
 * SOC PERIPHERALS
 */

#define PERI_I2C0_ADDR                      0x1A104180
#define PERI_I2C1_ADDR                      0x1A104200


#define I2C0_RX_SADDR_OFFSET                 0x00
#define I2C0_RX_SIZE_OFFSET                  0x04
#define I2C0_RX_CFG_OFFSET                   0x08
#define I2C0_TX_SADDR_OFFSET                 0x10
#define I2C0_TX_SIZE_OFFSET                  0x14
#define I2C0_TX_CFG_OFFSET                   0x18
//#define I2C0_CMD_SADDR_OFFSET                0x20
//#define I2C0_CMD_SIZE_OFFSET                 0x24
//#define I2C0_CMD_CFG_OFFSET                  0x28
#define I2C0_STATUS_OFFSET                   0x20
#define I2C0_SETUP_OFFSET                    0x24

#define PERI_I2C0_RX_SADDR_ADDR            ( PERI_I2C0_ADDR + I2C0_RX_SADDR_OFFSET )
#define PERI_I2C0_RX_SIZE_ADDR             ( PERI_I2C0_ADDR + I2C0_RX_SIZE_OFFSET  )
#define PERI_I2C0_RX_CFG_ADDR              ( PERI_I2C0_ADDR + I2C0_RX_CFG_OFFSET )
#define PERI_I2C0_TX_SADDR_ADDR            ( PERI_I2C0_ADDR + I2C0_TX_SADDR_OFFSET  )
#define PERI_I2C0_TX_SIZE_ADDR             ( PERI_I2C0_ADDR + I2C0_TX_SIZE_OFFSET )
#define PERI_I2C0_TX_CFG_ADDR              ( PERI_I2C0_ADDR + I2C0_TX_CFG_OFFSET  )
//#define PERI_I2C0_CMD_SADDR_ADDR           ( PERI_I2C0_ADDR + I2C0_CMD_SADDR_OFFSET )
//#define PERI_I2C0_CMD_SIZE_ADDR            ( PERI_I2C0_ADDR + I2C0_CMD_SIZE_OFFSET  )
//#define PERI_I2C0_CMD_CFG_ADDR             ( PERI_I2C0_ADDR + I2C0_CMD_CFG_OFFSET )
#define PERI_I2C0_STATUS_ADDR              ( PERI_I2C0_ADDR + I2C0_STATUS_OFFSET )
#define PERI_I2C0_SETUP_ADDR               ( PERI_I2C0_ADDR + I2C0_SETUP_OFFSET )

#define PERI_I2C1_RX_SADDR_ADDR            ( PERI_I2C1_ADDR + I2C0_RX_SADDR_OFFSET )
#define PERI_I2C1_RX_SIZE_ADDR             ( PERI_I2C1_ADDR + I2C0_RX_SIZE_OFFSET  )
#define PERI_I2C1_RX_CFG_ADDR              ( PERI_I2C1_ADDR + I2C0_RX_CFG_OFFSET )
#define PERI_I2C1_TX_SADDR_ADDR            ( PERI_I2C1_ADDR + I2C0_TX_SADDR_OFFSET  )
#define PERI_I2C1_TX_SIZE_ADDR             ( PERI_I2C1_ADDR + I2C0_TX_SIZE_OFFSET )
#define PERI_I2C1_TX_CFG_ADDR              ( PERI_I2C1_ADDR + I2C0_TX_CFG_OFFSET  )
//#define PERI_I2C1_CMD_SADDR_ADDR           ( PERI_I2C1_ADDR + I2C0_CMD_SADDR_OFFSET )
//#define PERI_I2C1_CMD_SIZE_ADDR            ( PERI_I2C1_ADDR + I2C0_CMD_SIZE_OFFSET  )
//#define PERI_I2C1_CMD_CFG_ADDR             ( PERI_I2C1_ADDR + I2C0_CMD_CFG_OFFSET )
#define PERI_I2C1_STATUS_ADDR              ( PERI_I2C1_ADDR + I2C0_STATUS_OFFSET )
#define PERI_I2C1_SETUP_ADDR               ( PERI_I2C1_ADDR + I2C0_SETUP_OFFSET )


//void uart_basic_function_test();
//void uart_tx_test(int ram_addr,int tx_size,int setup);
//void uart_rx_test(int ram_addr,int rx_size,int setup);
void i2c_reg_test();
void i2c0_tx_test(int ram_addr,int tx_size);
void i2c1_tx_test(int ram_addr,int tx_size);
void i2c0_rx_test(int tx_ram_addr,int rx_ram_addr,int tx_size,int rx_size);

void hal_soc_i2c0_set(unsigned int addr,unsigned int value);
int hal_soc_i2c0_read(unsigned int addr);

#endif


