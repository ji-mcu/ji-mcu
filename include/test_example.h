#include "soc_common.h"
#include "IC_PWM.h"
#include "core_sys.h"
#include "IC_timer.h"
#include "core_SFR.h"
#include "i2s_1.h"
// #include "i2c-0.h"
// #include "uart.h"
// #include "IC_I2S.h"
#include "soc_printf.h"
void gpio_test();
void pwm_test();
void uart_test();
void timer_test();
void i2c_test();
void OLED_WR_Byte(uint8_t *dat);
void lin_test();
// void i2c_test();
void i2s_test();
void int_test();
void spi_test();
void soc_event_test();

static inline void soc_eu_eventMask_set1(unsigned int reg, unsigned int value)
{
    pulp_write32(0x1a102000 + reg, value);
}

static inline unsigned int soc_eu_eventMask_get1(unsigned int reg)
{
    return pulp_read32(0x1a102000 + reg);
}

static inline void soc_eu_eventMask_setEvent1(int evt, unsigned int first_reg)
{
    unsigned int reg = first_reg + (evt / 32 * 4);
    evt = evt % 32;
    soc_eu_eventMask_set1(reg, soc_eu_eventMask_get1(reg) & ~(1 << evt));
}

static inline void soc_eu_fcEventMask_setEvent1(int evt)
{
    soc_eu_eventMask_setEvent1(evt, 0x04);
}

static inline void wait_event(uint8_t mask)
{
    int_enable_set(1 << mask);

    while (!((int_status_value_get() >> mask) & 1));
    // {;
    //     // int_wait_for_interrupt();
    // }
    // int_fifo_pop();
    // int_status_set(1 << 15);
    // int_status_clr(1 << mask);
    // int_enable_clr(1 << mask);
    // int_ack_clr(1 << mask);
    // int_ack_clr(1 << 15);

    // TMR0_Resetlo();
}

static inline void spim_send_data1(uint32_t spibase, uint32_t u32Data)
{
    uint8_t cfg = UDMA_CFG_SIZE_32 | UDMA_CFG_EN;
    uint32_t spibase_tx = spibase + UDMA_TX_OFFSET;
    uint16_t bit_size = (udma_spi_cmd->spi_cmd[4] & 0xffff) >> 3; // useful value=cmd/8

    udma_spi_cmd->spi_cmd[2] = udma_spi_cmd->spi_cmd[4];
    spim_send_cmd(spibase_tx, RV_Udma_CMD_ADDR, cfg, ENABLE);
    udma_en(spibase_tx, u32Data, bit_size, cfg);
    while (!udma_canEn(spibase_tx));
    wait_event(26);
    // udma_spi_cmd->spi_cmd[0] = udma_spi_cmd->spi_cmd[3];
    spim_send_cmd(spibase_tx, (RV_Udma_CMD_ADDR + SPI_EOT_Base_OFFSET), cfg, DISABLE);
    spim_wait_tx_done(spibase_tx);
}

