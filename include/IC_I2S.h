
/********************************** (C) COPYRIGHT  *******************************
 * File Name          : IC_i2s.h
 * Author             : huang jin
 * Version            : V0.0
 * Date               : 2024/12/08
 * Description        : 包含i2s的所有库函数
 *******************************************************************************/
#define I2S_H
#ifdef I2S_H

#ifdef __cplusplus
extern "C"
{
#endif

// #include "soc_common.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "core_sys.h"
#include "IC_udma.h"
#include "soc_event.h"
#include "core_riscv.h"

#define I2S_BASE_ADDR 0x1A104080


// SPI Master Registers
#define REG_RX_CH0_SADDR     (*((volatile uint32_t *)(0x1A104080+0x00)))    //低12位有效
#define REG_RX_CH0_SIZE      (*((volatile uint32_t *)(0x1A104080+0x04)))    //低16位有效 
#define REG_RX_CH0_CFG       (*((volatile uint32_t *)(0x1A104080+0x08)))    
#define REG_RX_CH0_INTCFG    (*((volatile uint32_t *)(0x1A104080+0x0C)))    

#define REG_RX_CH1_SADDR     (*((volatile uint32_t *)(0x1A104080+0x10)))    
#define REG_RX_CH1_SIZE      (*((volatile uint32_t *)(0x1A104080+0x14)))    
#define REG_RX_CH1_CFG       (*((volatile uint32_t *)(0x1A104080+0x18)))    
#define REG_RX_CH1_INTCFG    (*((volatile uint32_t *)(0x1A104080+0x1C)))    

#define REG_I2S_EXT_SETUP    (*((volatile uint32_t *)(0x1A104080+0x20)))  //   仅能配置低5位
#define REG_I2S_CFG0_SETUP   (*((volatile uint32_t *)(0x1A104080+0x24)))      
#define REG_I2S_CFG1_SETUP   (*((volatile uint32_t *)(0x1A104080+0x28)))      
#define REG_I2S_CHMODE       (*((volatile uint32_t *)(0x1A104080+0x2C)))    
#define REG_I2S_FILT_CH0     (*((volatile uint32_t *)(0x1A104080+0x30)))//当访问FILT的时候update-en自动置为1
#define REG_I2S_FILT_CH1     (*((volatile uint32_t *)(0x1A104080+0x34)))    

#define REG_I2S_TX_SADDR     (*((volatile uint32_t *)(0x1A104080+0x40)))    
#define REG_I2S_TX_SIZE      (*((volatile uint32_t *)(0x1A104080+0x44)))    
#define REG_I2S_TX_CFG       (*((volatile uint32_t *)(0x1A104080+0x48)))    
#define REG_I2S_TX_SETUP     (*((volatile uint32_t *)(0x1A104080+0x4C)))    //最低位有效] 1- Enable TX Mode (Rx Mode Disable)  0- Enable RX Mode (Tx Mode Disable)




  typedef enum
  {
    CFG_USE_CLK0 = 0b00,
    CFG_USE_CLK1 = 0b01,
    CFG_USE_EXTCLK_INTWS = 0b10,
    CFG_USE_EXTCLK_EXTWS = 0b11,

  } I2S_CLK_TypeDef;

  typedef enum
  {
    RX_mode = 0,
    TX_mode = !RX_mode,
  } I2S_TXMODE_TypeDef;
  /**
   * @brief  Configuration data_size
   */
  typedef enum
  {
    size00= 0b00,
    size01= 0b01,
    size10 = 0b10,
    size11 = 0b11,
  } Data_size_TypeDef;
/*
 * I2S
 */
#define _UDMA_HAS_I2S
#ifdef _UDMA_HAS_I2S


// 定义位字段结构体，用于访问REG_RX_CH0_CFG的每一位
typedef struct
{
    __IO u32 r_rx_continuous : 1; // 第0位
    __IO u32 r_rx_datasize : 2;   // 第2:1位
    __IO u32 reserved1 : 1;          // 第3位（保留）
    __IO u32 r_rx_en : 1;         // 第4位
    __IO u32 r_rx_clr : 5;        // 第5位
    __IO u32 reserved2 : 26;         // 剩余位（保留）
} Udma_I2S_RX_CFG;



typedef struct
{
    __IO u32 r_i2s_snap_cam0      :1;   //cfg_data_i[0];
    __IO u32 r_i2s_snap_cam1      :1;   //cfg_data_i[1];
    __IO u32 r_i2s_snap_cam2      :1;   //cfg_data_i[2];
    __IO u32 r_i2s_snap_cam3      :1;   //cfg_data_i[3];

    __IO u32 r_i2s_lsb_first0     :1;   //cfg_data_i[4]; //if 0 : SDI 输入低位到高位存储；1：SDI输入从高位到低位存储
    __IO u32 r_i2s_lsb_first1     :1;   //cfg_data_i[5]; //if 0 : SDI 输入低位到高位存储；1：SDI输入从高位到低位存储
    __IO u32 r_i2s_lsb_first2     :1;   //cfg_data_i[6]; //if 0 : SDI 输入低位到高位存储；1：SDI输入从高位到低位存储
    __IO u32 r_i2s_lsb_first3     :1;   //cfg_data_i[7]; //if 0 : SDI 输入低位到高位存储；1：SDI输入从高位到低位存储
    __IO u32 r_i2s_pdm_usefilter0 :1;   //cfg_data_i[8]; // 指定PDM（脉冲密度调制）是否使用滤波器

    __IO u32 r_i2s_pdm_usefilter1 :1;   //cfg_data_i[9];
    __IO u32 r_i2s_pdm_usefilter2 :1;   //cfg_data_i[10];
    __IO u32 r_i2s_pdm_usefilter3 :1;   //cfg_data_i[11];

    __IO u32 r_i2s_pdm_en0        :1;   //cfg_data_i[12]; // PDM模式使能
    __IO u32 r_i2s_pdm_en1        :1;   //cfg_data_i[13];
    __IO u32 r_i2s_pdm_en2        :1;   //cfg_data_i[14];
    __IO u32 r_i2s_pdm_en3        :1;   //cfg_data_i[15];

    __IO u32 r_i2s_useddr0        :1;   //cfg_data_i[16]; // 指定是否使用DDR（双数据速率）模式
    __IO u32 r_i2s_useddr1        :1;   //cfg_data_i[17];
    __IO u32 r_i2s_useddr2        :1;   //cfg_data_i[18];
    __IO u32 r_i2s_useddr3        :1;   //cfg_data_i[19];
    u32 reserve1                  :4;
    __IO u32 r_i2s_ch_mode0       :2;//cfg_data_i[25:24];//choice sck
    __IO u32 r_i2s_ch_mode1       :2;//cfg_data_i[27:26];//choice sck
    __IO u32 r_i2s_ch_mode2       :2;//cfg_data_i[29:28];//choice sck
    __IO u32 r_i2s_ch_mode3       :2;//cfg_data_i[31:30];//choice sck
} Udma_I2S_CHMOD;

#define CH_MODE_WIDTH         2
#define CH_MODE0_OFFSET       24
#define CH_USEDDR0_WIDTH      1
#define CH_USEDDR0_OFFSET     16
#define CH_PDM_EN_WIDTH       1
#define CH_PDM_EN0_OFFSET     12
#define CH_USEFILTER_WIDTH    1
#define CH_USEFILTER_OFFSET   9
#define CH_LSB_FIRST_WIDTH    1
#define CH_LSB_FIRST_OFFSET   4
#define CH_CAM_WIDTH          1
#define CH_CAM_OFFSET         0


// 定义位字段结构体，用于访问I2S_CHMOD的每一位
typedef struct
{
    // __IO u32 r_i2s_update0 = 1'b1;
    __IO u32 r_i2s_decimation : 10 ;//cfg_data_i [9:0];
    u32 reserve1               : 6  ;
    __IO u32 r_i2s_shift    : 3  ;//cfg_data_i [18:16];
    u32 reserve2               : 13  ;
} Udma_I2S_FILT_CH;


typedef struct
{
    __IO u32 r_i2s_cfg_bits_word : 5; //cfg_data_i [4:0];
    u32 reserve1               : 3  ;
    __IO u32 r_i2s_cfg_clk_en   : 1;  //cfg_data_i[8];
    u32 reserve2               : 7  ;
    __IO u32 r_i2s_cfg_clk_div  :16 ;// cfg_data_i[31:16];

} Udma_I2S_CFG_SETUP;

#define CFG_CLK_EN_WIDTH    1
#define CFG_CLK_EN_OFFSET   8
#define CFG_CLK_DIV_WIDTH   16
#define CFG_CLK_DIV_OFFSET  16
#define CFG_BIT_WORD_WIDTH  5
#define CFG_BIT_WORD_OFFSET 0


// 定义位字段结构体，用于访问REG_RX_CH0_CFG的每一位
typedef struct
{
    __IO u32 r_tx_continuous : 1;     // 第0位
    __IO u32 reserved1 : 3;          //
    __IO u32 r_tx_en : 1;            // 第4位
    __IO u32 r_tx_clr : 5;           // 第5位
    __IO u32 reserved2 : 26;         // 剩余位（保留）
} Udma_I2S_TX_CFG;

typedef struct
{
  __IO u32 RX0_SADDR; // 接收数据内存起始地址
  __IO u32 RX0_SIZE;  // 接收数据长度
  union
  {
    volatile uint32_t RX0_CFG;        // 通道模式选择，原始32位寄存器访问
    Udma_I2S_RX_CFG udma_i2s_rx0_cfg; // 位字段访问
  };
  uint32_t RESERVED1; // 保留 REG_RX_CH0_INTCFG
  __IO u32 RX1_SADDR; // 第二个接收通道的内存起始地址（保留/备用）
  __IO u32 RX1_SIZE;  // 第二个接收通道的数据长度（保留/备用）
  union
  {
    volatile uint32_t RX1_CFG;        // 通道模式选择，原始32位寄存器访问
    Udma_I2S_RX_CFG udma_i2s_rx1_cfg; // 位字段访问
  };
  uint32_t RESERVED2;     // 保留 REG_RX_CH1_INTCFG
  __IO u32 I2S_EXT_SETUP; // 外部输出设置 仅能配置低5位
  union
  {
    volatile uint32_t I2S_CFG0_SETUP;      // // RX通道0配置
    Udma_I2S_CFG_SETUP udma_i2s_rx0_setup; // 位字段访问
  };
  union
  {
    volatile uint32_t I2S_CFG1_SETUP;      // // RX通道1配置
    Udma_I2S_CFG_SETUP udma_i2s_rx1_setup; // 位字段访问
  };
  union
  {
    volatile uint32_t I2S_CHMOD;   // 通道模式选择，原始32位寄存器访问
    Udma_I2S_CHMOD udma_i2s_chmod; // 位字段访问
  };
  union
  {
    volatile uint32_t I2S_FILT_CH0;     //// 通道0滤波配置（保留/备用）
    Udma_I2S_FILT_CH udma_i2s_ch0_filt; // 位字段访问
  };
  union
  {
    volatile uint32_t I2S_FILT_CH1;     // 通道1滤波配置（保留/备用）
    Udma_I2S_FILT_CH udma_i2s_ch1_filt; // 位字段访问
  };

  uint32_t RESERVED3[1]; // 保留
  __IO u32 TX0_SADDR;    // 发送数据内存起始地址
  __IO u32 TX0_SIZE;     // 发送数据长度
  union
  {
    volatile uint32_t TX0_CFG;        //
    Udma_I2S_TX_CFG udma_i2s_tx0_cfg; // 位字段访问
  };
  __IO u32 TX0_SETUP; // TX模式设置

} I2S_Registers;

#define I2S ((I2S_Registers *)I2S_BASE_ADDR)

///////////////////////////////////////////////////

#endif



// void i2s_init();
void i2s_set_mode(I2S_TXMODE_TypeDef mode); // 0为接收模式，1为发送模式
void i2s_setup(uint32_t clk_div, I2S_CLK_TypeDef clk_type, FlagStatus Newstatus, FunctionalState Newstate);
void i2s_send_data(uint32_t Data,uint16_t size,uint8_t cfg,uint8_t tx_mode);
void i2s_receive_data(uint32_t Data, uint16_t size, uint8_t cfg);

    //======================I2S0_RX_CFG0 Start=====================================//

    static inline void i2s_rx_set(uint32_t addr, uint16_t size, uint8_t cfg)
{ 
  REG_RX_CH0_SADDR = addr;
  REG_RX_CH0_SIZE = size;
  REG_RX_CH0_CFG  = cfg|UDMA_CFG_EN;
}
static inline uint8_t i2s_rx_canEn() { return !(REG_RX_CH0_CFG & UDMA_CFG_PENDING); }
static inline uint8_t i2s_rx_busy() { return (REG_RX_CH0_CFG & UDMA_CFG_EN); }
static inline uint8_t i2s_rx_clr() { REG_RX_CH0_CFG |= UDMA_CFG_CLEAR; }

// 开始接收数据传输
static inline void i2s_cfg_rx_en() { I2S->udma_i2s_rx0_cfg.r_rx_en |= SET; } // 设置RX0_CFG寄存器的第4位为1，开始传输 最后再使能
static inline void i2s_rx_cfg_continuous_set(void){  I2S->udma_i2s_rx0_cfg.r_rx_continuous |= SET; }
static inline void i2s_rx_cfg_datasize_set(Data_size_TypeDef d){  I2S->udma_i2s_rx0_cfg.r_rx_datasize = d; }

static inline uint32_t i2s_rx_cfg_get(void){  uint32_t temp = REG_RX_CH0_CFG;return temp;}
//======================I2S0_RX_CFG0 END =====================================//

//======================I2S0_TX_CFG0 Start=====================================//

static inline void i2s_tx_set(uint32_t addr,uint16_t size,uint8_t cfg,uint8_t tx_mode)
{  
  REG_I2S_TX_SADDR = addr;
  REG_I2S_TX_SIZE  = size;
  REG_I2S_TX_CFG   = cfg|UDMA_CFG_EN;
  REG_I2S_TX_SETUP = tx_mode;

}
static inline uint8_t i2s_tx_canEn(){ return !(REG_I2S_TX_CFG & UDMA_CFG_PENDING);}
static inline uint8_t i2s_tx_busy() { return (REG_I2S_TX_CFG & UDMA_CFG_EN); }
static inline uint8_t i2s_tx_clr() { REG_I2S_TX_CFG |= UDMA_CFG_CLEAR; }

//======================I2S0_TX_CFG0 End =====================================//

//======================I2S0_RX_EXT Start=====================================//
static inline void i2s_ext_clk_set(uint8_t value) { I2S->I2S_EXT_SETUP = value; } // 1<=value<=31  ext_ws_clk= Fsck_i/(2*(value +1))

static inline uint8_t hal_i2s_ext_clk_get(void){  uint8_t temp = REG_I2S_EXT_SETUP;return temp;}
//======================I2S0_RX_EXT END========================================//

//======================I2S0_RX_CFG0_SETUP Start=====================================//
static inline void i2s_cfg0_set(uint8_t bit_words,uint32_t div,uint8_t clk_en){  
    // I2S->udma_i2s_rx0_setup.r_i2s_cfg_bits_word = value;
    // REG_I2S_CFG0_SETUP |= (value&0x1F)<<CFG_BIT_WORD_OFFSET;
    REG_I2S_CFG0_SETUP = (bit_words << CFG_BIT_WORD_OFFSET| div<<CFG_CLK_DIV_OFFSET|clk_en<<CFG_CLK_EN_OFFSET);

    } // 1<=value<=31  ws_clk= Fsck_i/(2*(value +1))
// 1<=value<=31  sck= Fsys/(2*(value +1))

static inline uint32_t i2s_cfg0_get(void){  uint32_t temp = REG_I2S_CFG0_SETUP;  return temp;}
//======================I2S0_RX_CFG0_SETUP END=======================================//

//======================I2S0_RX_CFG1_SETUP Start=====================================//
// static inline void i2s_cfg1_ws_clk_set(uint32_t value){  I2S->udma_i2s_rx1_setup = value;} // 1<=value<=31  ws_clk= Fsck_i/(2*(value +1))
// static inline void i2s_cfg1_sck_set(uint32_t value){  I2S->udma_i2s_rx1_setup = value;} // 1<=value<=31  sck= Fsys/(2*(value +1))
// static inline void i2s_cfg1_clkgen_set(uint32_t value){  I2S->udma_i2s_rx1_setup = value;}
// static inline uint32_t i2s_cfg1_get(void){  uint32_t temp = REG_I2S_CFG1_SETUP;  return temp;}
//======================I2S0_RX_CFG1_SETUP END=======================================//

//======================I2S0_RX_chmode Start=======================================//
static inline void i2s_lsb_set(uint8_t value){  
  // I2S->udma_i2s_chmod.r_i2s_lsb_first0 = value;
  REG_I2S_CHMODE |= 1<<CH_LSB_FIRST_OFFSET;
  } // 选择发送从LSB开始还是MSB开始
static inline void i2s_chmode_set(I2S_CLK_TypeDef c){  
  // I2S->udma_i2s_chmod.r_i2s_ch_mode0 = c ;
  REG_I2S_CHMODE |=0<<CH_MODE0_OFFSET ;

  }
static inline uint32_t i2s_chmode_get(){  uint32_t temp = REG_I2S_CHMODE;  return temp;}

//======================I2S0_RX_chmode END========================================//

//======================I2S0_RX_Filt0 Start=======================================//
// static inline void i2s_filt0_decimation_set(uint16_t value){  I2S->udma_i2s_ch0_filt.r_i2s_decimation= value;} // 抽取率控制，用于调整采样率
// static inline void i2s_filt0_shift_set(uint16_t value){  I2S->udma_i2s_ch0_filt.r_i2s_shift = value;} // 数据移位控制
// static inline void i2s_clkgen_en_update(){  ;}
// static inline uint32_t i2s_filt0_ch_get(){  uint32_t temp= REG_I2S_FILT_CH0;  return temp;}
//======================I2S0_RX_Filt0 END =======================================//

//======================I2S0_RX_Filt1 Start=======================================//
// static inline void i2s_filt1_decimation_set(uint16_t value){  I2S->udma_i2s_ch1_filt.r_i2s_decimation = value;} // 抽取率控制，用于调整采样率 value<2^10
// static inline void i2s_filt1_shift_set(uint16_t value){  I2S->udma_i2s_ch1_filt.r_i2s_shift = value;} // 数据移位控制 value<2^3
// static inline void i2s_clkgen_en_update(){  ;}
// static inline uint32_t i2s_filt1_ch_get(){  uint32_t temp = REG_I2S_FILT_CH1;  return temp;}
//======================I2S0_RX_Filt1 END =======================================//

#ifdef __cplusplus
}
#endif



#endif // I2S_H
