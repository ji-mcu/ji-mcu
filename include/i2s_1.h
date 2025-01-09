

#include <stdint.h>

// #define I2S_BASE_ADDR 0x1A104080
#define I2S_BASE_ADDR1 0x1A104380

typedef struct
{
    volatile uint32_t RX0_SADDR;     // 接收数据内存起始地址
    volatile uint32_t RX0_SIZE;      // 接收数据长度
    volatile uint32_t RX0_CFG;       // 接收配置寄存器
    uint32_t RESERVED1[1];           // 保留
    volatile uint32_t RX1_SADDR;     // 第二个接收通道的内存起始地址（保留/备用）
    volatile uint32_t RX1_SIZE;      // 第二个接收通道的数据长度（保留/备用）
    volatile uint32_t RX1_CFG;       // 第二个接收通道的配置（保留/备用）
    uint32_t RESERVED2[1];           // 保留
    volatile uint32_t RX_EXT_SETUP;  // 外部输出设置
    volatile uint32_t RX_CFG0_SETUP; // RX通道0配置
    volatile uint32_t RX_CFG1_SETUP; // RX通道1配置
    volatile uint32_t RX_CHMOD;      // 通道模式选择
    volatile uint32_t RX_FILT_CH0;   // 通道0滤波配置（保留/备用）
    volatile uint32_t RX_FILT_CH1;   // 通道1滤波配置（保留/备用）
    uint32_t RESERVED3[2];           // 保留
    volatile uint32_t TX0_SADDR;     // 发送数据内存起始地址
    volatile uint32_t TX0_SIZE;      // 发送数据长度
    volatile uint32_t TX0_CFG;       // 发送配置寄存器
    volatile uint32_t TX0_SETUP;     // TX模式设置
} I2S_Registers1;

#define I2S1 ((I2S_Registers1 *)I2S_BASE_ADDR1)

#define PERI_I2S0_ADDR 0x1A104380
#define PERI_I2S1_ADDR 0x1A104400

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


void i2s_init1();
void i2s_set_rx_address(uint32_t addr);
void i2s_set_rx_size(uint32_t size);
void i2s_start_rx();
void i2s_set_tx_address(uint32_t addr);
void i2s_set_tx_size(uint32_t size);
void i2s_start_tx();
void i2s_set_mode1(int mode); // 0为接收模式，1为发送模式

void i2s_set_tx_cfg0_setup(int sel, int clk_en, uint16_t clk_dev, uint8_t bits_word);
void i2s_set_chmode__ch_mode_0(int ch_mode_0);
void i2s_set_tx_cfg(int sel, int tx_clr, int tx_en, int tx_continuous);

