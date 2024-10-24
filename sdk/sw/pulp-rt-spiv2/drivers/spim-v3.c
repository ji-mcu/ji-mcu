/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna and GreenWaves Technologies
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/* 
 * Authors: Germain Haugou, ETH (germain.haugou@iis.ee.ethz.ch)
 *          Jie Chen, GreenWaves Technologies (jie.chen@greenwaves-technologies.com)
 */

// #include "rt/rt_api.h"
#include "pulp.h"
#include <stdint.h>

static int __rt_spim_open_count[ARCHI_UDMA_NB_SPIM];

static RT_FC_TINY_DATA rt_periph_spim_t __rt_spim_periph[ARCHI_UDMA_NB_SPIM];

typedef struct {
    unsigned int cmd[4];
} rt_spim_cmd_t;

static inline int __rt_spim_id(int periph_id)
{
  return periph_id - ARCHI_UDMA_SPIM_ID(0);
}

static int __rt_spi_get_div(int spi_freq)
{
  int periph_freq = __rt_freq_periph_get();

  if (spi_freq >= periph_freq)
  {
    return 0;
  }
  else
  {
    // Round-up the divider to obtain an SPI frequency which is below the maximum
    int div = (__rt_freq_periph_get() + spi_freq - 1)/ spi_freq;

    // The SPIM always divide by 2 once we activate the divider, thus increase by 1
    // in case it is even to not go avove the max frequency.
    if (div & 1) div += 1;
    div >>= 1;

    return div;
  }
}

static inline int __rt_spim_get_byte_align(int wordsize, int big_endian)
{
  return wordsize == RT_SPIM_WORDSIZE_32 && big_endian;
}

rt_spim_t *rt_spim_open(char *dev_name, rt_spim_conf_t *conf)
{
  int irq = hal_irq_disable();

  __rt_padframe_init();

  rt_spim_conf_t def_conf;

  if (conf == NULL)
  {
    conf = &def_conf;
    rt_spim_conf_init(conf);
  }

  int channel = -1;

  if (conf->id != -1)
  {  
    rt_trace(RT_TRACE_DEV_CTRL, "[SPIM] Opening spim device (id: %d)\n", conf->id);
    channel = ARCHI_UDMA_SPIM_ID(conf->id);
  }
  else if (dev_name != NULL)
  {
    rt_trace(RT_TRACE_DEV_CTRL, "[SPIM] Opening spim device (name: %s)\n", dev_name);
  
    rt_dev_t *dev = rt_dev_get(dev_name);
    if (dev == NULL) goto error;

    channel = dev->channel;
  }

  if (channel == -1) goto error;

  rt_spim_t *spim = rt_alloc(RT_ALLOC_FC_DATA, sizeof(rt_spim_t));
  if (spim == NULL) goto error;

  spim->channel = channel;

  spim->wordsize = conf->wordsize;
  spim->big_endian = conf->big_endian;
  spim->polarity = conf->polarity;
  spim->phase = conf->phase;
  spim->max_baudrate = conf->max_baudrate;
  spim->cs = conf->cs;
  spim->byte_align = __rt_spim_get_byte_align(conf->wordsize, conf->big_endian);

  int div = __rt_spi_get_div(spim->max_baudrate);
  spim->div = div;

  spim->cfg = SPI_CMD_CFG(div, conf->polarity, conf->phase);

  int id = channel - ARCHI_UDMA_SPIM_ID(0);

  __rt_spim_open_count[id]++;

  if (__rt_spim_open_count[id] == 1)
  {
    plp_udma_cg_set(plp_udma_cg_get() | (1<<channel));
    __rt_udma_callback[channel] = __rt_spim_handle_eot;
    __rt_udma_callback_data[channel] = &__rt_spim_periph[id];
    soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_PERIPH_EVT_BASE(channel) + ARCHI_UDMA_SPIM_EOT_EVT);
  }

  hal_irq_restore(irq);

  return spim;

error:
  rt_warning("[SPIM] Failed to open spim device\n");
  return NULL;
}

void __rt_spim_control(rt_spim_t *handle, rt_spim_control_e cmd, uint32_t arg)
{
  int irq = hal_irq_disable();

  int polarity = (cmd >> __RT_SPIM_CTRL_CPOL_BIT) & 3;
  int phase = (cmd >> __RT_SPIM_CTRL_CPHA_BIT) & 3;
  int set_freq = (cmd >> __RT_SPIM_CTRL_SET_MAX_BAUDRATE_BIT) & 1;
  int wordsize = (cmd >> __RT_SPIM_CTRL_WORDSIZE_BIT) & 3;
  int big_endian = (cmd >> __RT_SPIM_CTRL_ENDIANNESS_BIT) & 3;

  if (set_freq)
  {
    handle->max_baudrate = arg;
    handle->div = __rt_spi_get_div(arg);
  }

  if (polarity) handle->polarity = polarity >> 1;
  if (phase) handle->phase = phase >> 1;
  if (wordsize) handle->wordsize = wordsize >> 1;
  if (big_endian) handle->big_endian = big_endian >> 1;


  handle->cfg = SPI_CMD_CFG(handle->div, handle->polarity, handle->phase);
  handle->byte_align = __rt_spim_get_byte_align(handle->wordsize, handle->big_endian);

  hal_irq_restore(irq);
}

void rt_spim_close(rt_spim_t *handle)
{
  int irq = hal_irq_disable();

  int channel = handle->channel;
  int id = channel - ARCHI_UDMA_SPIM_ID(0);

  __rt_spim_open_count[id]--;

  if (__rt_spim_open_count[id] == 0)
  {
    plp_udma_cg_set(plp_udma_cg_get() & ~(1<<(channel)));

    __rt_udma_callback[channel] = NULL;
    soc_eu_fcEventMask_clearEvent(ARCHI_SOC_EVENT_PERIPH_EVT_BASE(channel) + ARCHI_UDMA_SPIM_EOT_EVT);
  }

  rt_free(RT_ALLOC_FC_DATA, handle, sizeof(handle));

  hal_irq_restore(irq);
}

static inline void __rt_spim_copy(rt_periph_copy_t *copy, int channel_id, unsigned int buffer_addr, int buffer_size, unsigned int cmd_addr, int cmd_size,
  unsigned int cfg)
{
  #if 0
  rt_periph_channel_t *channel = __rt_periph_channel(channel_id);
  unsigned int periph_base = hal_udma_periph_base(channel_id >> 1);
  unsigned int cmd_base = periph_base + ARCHI_SPIM_CMD_OFFSET;
  unsigned int channel_base = periph_base + (channel_id & 1) * UDMA_CHANNEL_SIZE;

  cfg |= UDMA_CHANNEL_CFG_EN;
  copy->size = buffer_size;

  __rt_channel_push(channel, copy);

  if (likely(!channel->firstToEnqueue))
  {
    plp_udma_enqueue(cmd_base, cmd_addr, cmd_size, cfg);
    plp_udma_enqueue(channel_base, buffer_addr, buffer_size, cfg);
  } else {
    //copy->u.dual.rx_addr = rx_addr;
    //copy->u.dual.rx_size = rx_size;
    //copy->enqueue_callback = 0;
    //__rt_channel_enqueue(channel, copy, tx_addr, tx_size, cfg);
  }
#endif
}

static inline void __rt_spim_copy_dual(rt_periph_copy_t *copy, int channel_id, unsigned int tx_buffer_addr, unsigned int rx_buffer_addr, int buffer_size, unsigned int cmd_addr, int cmd_size,
  unsigned int cfg)
{
#if 0
  // Dual copies assumes that more copies are always pushed to the TX channels than
  // to the RX channel, as an RX copy always needs a header in the TX channel.
  // Thus only the TX channel is checked to know if the transfer can be enqueued
  // directly.

  // The copy is enqueued to the RX channel so that the event is notified when the receive
  // is done.
  rt_periph_channel_t *channel = __rt_periph_channel(channel_id);
  unsigned int periph_base = hal_udma_periph_base(channel_id >> 1);
  unsigned int cmd_base = periph_base + ARCHI_SPIM_CMD_OFFSET;
  unsigned int tx_channel_base = periph_base + UDMA_CHANNEL_TX_OFFSET;
  unsigned int rx_channel_base = periph_base + UDMA_CHANNEL_RX_OFFSET;

  cfg |= UDMA_CHANNEL_CFG_EN;
  copy->size = buffer_size;

  __rt_channel_push(channel, copy);

  // If less than 2 transfers are enqueued in the channel, we can directly enqueue it
  // Otherwise enqueue it in the SW queue, it will be handled later on by the interrupt handler
  // We have to check if there is no transfer already waiting as since we masked interrupts, the
  // UDMA could have finished one transfer and we want to keep the transfers in-order
  if (likely(!channel->firstToEnqueue && plp_udma_canEnqueue(cmd_base)))
  {
    plp_udma_enqueue(cmd_base, cmd_addr, cmd_size, cfg);
    plp_udma_enqueue(tx_channel_base, tx_buffer_addr, buffer_size, cfg);
    plp_udma_enqueue(rx_channel_base, rx_buffer_addr, buffer_size, cfg);
  } else {
    //copy->u.dual.rx_addr = rx_addr;
    //copy->u.dual.rx_size = rx_size;
    //copy->enqueue_callback = 0;
    //__rt_channel_enqueue(channel, copy, tx_addr, tx_size, cfg);
  }
#endif
}

static inline int __rt_spim_enqueue_to_channel(rt_periph_channel_t *channel, rt_periph_copy_t *copy)
{
  if (!channel->first)
  {
    channel->first = copy;
    return 1;
  }
  else
  {
    if (channel->firstToEnqueue)
      channel->last->next = copy;
    else
      channel->firstToEnqueue = copy;
    copy->next = NULL;
    channel->last = copy;
    return 0;
  }
}

static inline int __rt_spim_periph_push(rt_periph_spim_t *periph, rt_periph_copy_t *copy)
{
  if (periph->pendings[1] == NULL)
  {
    if (periph->pendings[0] == NULL)
      periph->pendings[0] = copy;
    else
      periph->pendings[1] = copy;
    return 1;
  }
  else
  {
    //__rt_channel_push(channel, copy);
    return 0;
  }
}

void __rt_spim_send_async(rt_spim_t *handle, void *data, size_t len, int qspi, rt_spim_cs_e cs_mode)
{
  int periph_id = handle->channel;
  int periph_base = hal_udma_periph_base(periph_id);
  int cmd_base = periph_base + ARCHI_SPIM_CMD_OFFSET;
  int channel_base = periph_base + UDMA_CHANNEL_TX_OFFSET;
  int buffer_size = len/8;
  rt_periph_copy_t *copy = &event->copy;
  rt_spim_cmd_t *cmd = (rt_spim_cmd_t *)copy->periph_data;
  rt_periph_spim_t *periph = &__rt_spim_periph[periph_id];

  rt_trace(RT_TRACE_SPIM, "[SPIM] Send bitstream (handle: %p, buffer: %p, len: 0x%x, qspi: %d, keep_cs: %d, event: %p)\n", handle, data, len, qspi, cs_mode, event);

  int irq = hal_irq_disable();

  copy->event = event;

  cmd->cmd[0] = handle->cfg;
  cmd->cmd[1] = SPI_CMD_SOT(handle->cs);
  cmd->cmd[2] = SPI_CMD_TX_DATA(len/32, SPI_CMD_1_WORD_PER_TRANSF, 32, qspi, SPI_CMD_MSB_FIRST);
  cmd->cmd[3] = SPI_CMD_EOT(1);

  if (__rt_spim_periph_push(periph, copy))
  {
    int cfg = UDMA_CHANNEL_CFG_SIZE_32 | UDMA_CHANNEL_CFG_EN;
    plp_udma_enqueue(cmd_base, (int)cmd, 4*4, cfg);
    plp_udma_enqueue(channel_base, (int)data, buffer_size, cfg);
  }
  else
  {
    copy->u.raw.val[0] = channel_base;
    copy->u.raw.val[1] = (int)cmd;
    copy->u.raw.val[2] = 4*4;
    copy->u.raw.val[3] = (int)data;
    copy->u.raw.val[4] = buffer_size;
  }

  hal_irq_restore(irq);
}

void __rt_spim_send(rt_spim_t *handle, void *data, size_t len, int qspi, rt_spim_cs_e cs_mode)
{
  int irq = hal_irq_disable();

  rt_event_t *call_event = __rt_wait_event_prepare(event);

  __rt_spim_send_async(handle, data, len, qspi, cs_mode, call_event);

  __rt_wait_event_check(event, call_event);

  hal_irq_restore(irq);
}

void __rt_spim_receive_async(rt_spim_t *handle, void *data, size_t len, int qspi, rt_spim_cs_e cs_mode)
{
  int periph_id = handle->channel;
  int periph_base = hal_udma_periph_base(periph_id);
  int cmd_base = periph_base + ARCHI_SPIM_CMD_OFFSET;
  int channel_base = periph_base + UDMA_CHANNEL_RX_OFFSET;
  int buffer_size = len/8;
  rt_periph_copy_t *copy = &event->copy;
  rt_spim_cmd_t *cmd = (rt_spim_cmd_t *)copy->periph_data;
  rt_periph_spim_t *periph = &__rt_spim_periph[periph_id];

  rt_trace(RT_TRACE_SPIM, "[SPIM] Receive bitstream (handle: %p, buffer: %p, len: 0x%x, qspi: %d, keep_cs: %d, event: %p)\n", handle, data, len, qspi, cs_mode, event);

  int irq = hal_irq_disable();

  copy->event = event;

  cmd->cmd[0] = handle->cfg;
  cmd->cmd[1] = SPI_CMD_SOT(handle->cs);
  cmd->cmd[2] = SPI_CMD_RX_DATA(len/32, SPI_CMD_1_WORD_PER_TRANSF, 32, qspi, SPI_CMD_MSB_FIRST);
  cmd->cmd[3] = SPI_CMD_EOT(1);

  if (__rt_spim_periph_push(periph, copy))
  {
    int cfg = UDMA_CHANNEL_CFG_SIZE_32 | UDMA_CHANNEL_CFG_EN;
    plp_udma_enqueue(channel_base, (int)data, buffer_size, cfg);
    plp_udma_enqueue(cmd_base, (int)cmd, 4*4, cfg);
  }
  else
  {
    copy->u.raw.val[0] = channel_base;
    copy->u.raw.val[1] = (int)cmd;
    copy->u.raw.val[2] = 4*4;
    copy->u.raw.val[3] = (int)data;
    copy->u.raw.val[4] = buffer_size;
  }

  hal_irq_restore(irq);
}

void __rt_spim_receive(rt_spim_t *handle, void *data, size_t len, int qspi, rt_spim_cs_e cs_mode)
{
  int irq = hal_irq_disable();

  rt_event_t *call_event = __rt_wait_event_prepare(event);

  __rt_spim_receive_async(handle, data, len, qspi, cs_mode, call_event);

  __rt_wait_event_check(event, call_event);

  hal_irq_restore(irq);
}

void rt_spim_transfer_async(rt_spim_t *handle, void *tx_data, void *rx_data, size_t len, rt_spim_cs_e mode)
{
  int periph_id = handle->channel;
  int periph_base = hal_udma_periph_base(periph_id);
  int cmd_base = periph_base + ARCHI_SPIM_CMD_OFFSET;
  int rx_channel_base = periph_base + UDMA_CHANNEL_RX_OFFSET;
  int tx_channel_base = periph_base + UDMA_CHANNEL_TX_OFFSET;
  int buffer_size = len/8;
  rt_periph_copy_t *copy = &event->copy;
  rt_spim_cmd_t *cmd = (rt_spim_cmd_t *)copy->periph_data;
  rt_periph_spim_t *periph = &__rt_spim_periph[periph_id];

  rt_trace(RT_TRACE_SPIM, "[SPIM] Transfering bitstream (handle: %p, tx_buffer: %p, rx_buffer: %p, len: 0x%x, keep_cs: %d, event: %p)\n", handle, tx_data, rx_data, len, mode, event);

  int irq = hal_irq_disable();

  copy->event = event;

  cmd->cmd[0] = handle->cfg;
  cmd->cmd[1] = SPI_CMD_SOT(handle->cs);
  cmd->cmd[2] = SPI_CMD_FUL(len/32, SPI_CMD_1_WORD_PER_TRANSF, 32, SPI_CMD_MSB_FIRST);
  cmd->cmd[3] = SPI_CMD_EOT(1);

  if (__rt_spim_periph_push(periph, copy))
  {
    int cfg = UDMA_CHANNEL_CFG_SIZE_32 | UDMA_CHANNEL_CFG_EN;
    plp_udma_enqueue(cmd_base, (int)cmd, 4*4, cfg);
    plp_udma_enqueue(rx_channel_base, (int)rx_data, buffer_size, cfg);
    plp_udma_enqueue(tx_channel_base, (int)tx_data, buffer_size, cfg);
  }
  else
  {
  }

  hal_irq_restore(irq);
}

void rt_spim_transfer(rt_spim_t *handle, void *tx_data, void *rx_data, size_t len, rt_spim_cs_e mode)
{
  int irq = hal_irq_disable();

  rt_event_t *call_event = __rt_wait_event_prepare(event);

  rt_spim_transfer_async(handle, tx_data, rx_data, len, mode, call_event);

  __rt_wait_event_check(event, call_event);

  hal_irq_restore(irq);
}

void rt_spim_conf_init(rt_spim_conf_t *conf)
{
  conf->wordsize = RT_SPIM_WORDSIZE_8;
  conf->big_endian = 0;
  conf->max_baudrate = 10000000;
  conf->cs_gpio = -1;
  conf->cs = -1;
  conf->id = -1;
  conf->polarity = 0;
  conf->phase = 0;
}

RT_FC_BOOT_CODE void __attribute__((constructor)) __rt_spim_init()
{
  for (int i=0; i<ARCHI_UDMA_NB_SPIM; i++)
  {
    __rt_spim_open_count[i] = 0;
  }
}
