#include "IC_SPI.h"

void spim_Deinit(SPI_InitTypeDef *SPI_InitStruct)
{
  SPI_InitStruct->baudrate_div  = TIM_CLOCK_64M/(TIM_CLOCK_8M<<1);
  SPI_InitStruct->cs            = SPI_CMD_SOT_CS0;
  SPI_InitStruct->cpol          = SPI_CMD_CFG_CPOL_POS;
  SPI_InitStruct->cpha          = SPI_CMD_CFG_CPHA_STD;
  SPI_InitStruct->byte_align    = SPI_CMD_BYTE_ALIGN_DIS;
  SPI_InitStruct->data_size     = UDMA_CFG_SIZE_32;
  SPI_InitStruct->qpi           = SPI_CMD_QPI_DIS ;
  SPI_InitStruct->dpi           = SPI_CMD_DPI_DIS ;
  SPI_InitStruct->bit_size     = 128   ;
}

void spim_init(SPI_InitTypeDef *SPI_InitStruct)
{
  
  udma_spi_cmd->spi_cmd[0] = SPI_CMD_CFG(SPI_InitStruct->baudrate_div,SPI_InitStruct->cpol,SPI_InitStruct->cpha);
  udma_spi_cmd->spi_cmd[1] = SPI_CMD_SOT(SPI_InitStruct->cs);
  udma_spi_cmd->spi_cmd[2] = SPI_CMD_TX_DATA(SPI_InitStruct->bit_size,SPI_InitStruct->dpi,SPI_InitStruct->qpi,SPI_InitStruct->byte_align);
  udma_spi_cmd->spi_cmd[3] = SPI_CMD_EOT(SPI_CMD_EOT_EVENT_ENA);
  udma_spi_cmd->spi_cmd[4] = SPI_CMD_TX_DATA(SPI_InitStruct->bit_size, SPI_InitStruct->dpi, SPI_InitStruct->qpi, SPI_InitStruct->byte_align);
  udma_spi_cmd->spi_cmd[5] = SPI_CMD_RX_DATA(SPI_InitStruct->bit_size, SPI_InitStruct->dpi, SPI_InitStruct->qpi, SPI_InitStruct->byte_align);
  udma_spi_cmd->spi_cmd[6] = SPI_CMD_FUL(SPI_InitStruct->bit_size, SPI_InitStruct->byte_align);
}

void spim_send_cmd(uint32_t spibase,uint32_t cmdbase, uint8_t cfg, FunctionalState NewState)
{


  if (NewState!=DISABLE)//ENABLE
  {
    udma_en(spibase, cmdbase, 3 * 4, cfg);
  }
  else
  {
    udma_en(spibase, cmdbase, 1 * 4, cfg);
  }
}
void spim_cmd_init()
{
  SPI_InitTypeDef SPI_InitStruct = {0};
  spim_Deinit(&SPI_InitStruct);
  spim_init(&SPI_InitStruct);
}
void spim_send_data(uint32_t spibase, uint32_t u32Data)
{
  uint8_t cfg = UDMA_CFG_SIZE_32 | UDMA_CFG_EN;
  uint32_t  spibase_tx  = spibase  + UDMA_TX_OFFSET;
  uint16_t bit_size = (udma_spi_cmd->spi_cmd[4] & 0xffff) >> 3; // useful value=cmd/8

  udma_spi_cmd->spi_cmd[2] = udma_spi_cmd->spi_cmd[4];
  spim_send_cmd(spibase_tx, RV_Udma_CMD_ADDR, cfg, ENABLE);
  udma_en(spibase_tx, u32Data, bit_size, cfg);
  while (!udma_canEn(spibase_tx));
  // udma_spi_cmd->spi_cmd[0] = udma_spi_cmd->spi_cmd[3];
  spim_send_cmd(spibase_tx, (RV_Udma_CMD_ADDR + SPI_EOT_Base_OFFSET), cfg, DISABLE);
  spim_wait_tx_done(spibase_tx);
}

void spim_receive_data(uint32_t spibase, uint32_t u32Data)
{
  uint8_t cfg =UDMA_CFG_SIZE_32 | UDMA_CFG_EN;
  uint32_t  spibase_rx  = spibase  + UDMA_RX_OFFSET;
  uint16_t bit_size = (udma_spi_cmd->spi_cmd[4] & 0xffff) >> 3; // useful value=cmd/8
  udma_spi_cmd->spi_cmd[2] = udma_spi_cmd->spi_cmd[4];
  spim_send_cmd(spibase_rx, RV_Udma_CMD_ADDR, cfg, ENABLE);
  udma_en(spibase_rx, u32Data, bit_size, cfg);
  while (!udma_canEn(spibase_rx));
  udma_spi_cmd->spi_cmd[0] = udma_spi_cmd->spi_cmd[3];
  spim_send_cmd(spibase_rx, (RV_Udma_CMD_ADDR + SPI_EOT_Base_OFFSET), cfg, DISABLE);
  spim_wait_rx_done(spibase_rx);
}

void spim_dual_transfer( uint32_t spibase, uint32_t u32Data_tx, uint32_t u32Data_rx)
{
  uint8_t cfg = UDMA_CFG_SIZE_32 | UDMA_CFG_EN;
  uint32_t  spibase_tx  = spibase  + UDMA_TX_OFFSET;
  uint16_t bit_size = (udma_spi_cmd->spi_cmd[6] & 0xffff) >> 3; // useful value=cmd/8

  udma_spi_cmd->spi_cmd[2] = udma_spi_cmd->spi_cmd[4];
  // spim_send_cmd(spibase, RV_Udma_CMD_ADDR, cfg, ENABLE);
  spim_send_cmd(spibase_tx, RV_Udma_CMD_ADDR, cfg, ENABLE);

  udma_en(spibase, u32Data_rx, bit_size, cfg);
  udma_en(spibase_tx, u32Data_tx, bit_size, cfg);

  while (!udma_canEn(spibase_tx));
  while (!udma_canEn(spibase));

  udma_spi_cmd->spi_cmd[0] = udma_spi_cmd->spi_cmd[3];
  spim_send_cmd(spibase, RV_Udma_CMD_ADDR, cfg, DISABLE);
  spim_send_cmd(spibase_tx, (RV_Udma_CMD_ADDR + SPI_EOT_Base_OFFSET), cfg, DISABLE);
  
  spim_wait_tx_done(spibase);
  spim_wait_tx_done(spibase_tx);
}

void spim_get_cmd(SPI_CMD_ID CMD_ID)
{
  uint32_t cmd_value=0;
  switch (CMD_ID)
  {
    case SPI_CMD_CFG_ID      : 
    break;
    case SPI_CMD_SOT_ID      : 
    break;
    case SPI_CMD_SEND_CMD_ID : 
    break;
    case SPI_CMD_SEND_ADDR_ID: 
    break;
    case SPI_CMD_DUMMY_ID    : 
    break;
    case SPI_CMD_WAIT_ID     : 
    break;  
    case SPI_CMD_TX_DATA_ID  :  
    break;  
    case SPI_CMD_RX_DATA_ID  : 
    break;  
    case SPI_CMD_RPT_ID      : 
    break;
    case SPI_CMD_EOT_ID      : 
    break;
    case SPI_CMD_RPT_END_ID  : 
    break;  
    case SPI_CMD_RX_CHECK_ID : 
    break;  
    case SPI_CMD_FUL_ID      : 
    break;  
    case SPI_CMD_WAIT_CYC_ID :
    break;  

  default:
    break;
  }
}

void spim_wait_tx_done(uint32_t spi_txbase)
{
  while (udma_busy(spi_txbase));
}
void spim_wait_rx_done(uint32_t spi_rxbase)
{
  while (udma_busy(spi_rxbase));
}
void spim_handler(){
  ;
}