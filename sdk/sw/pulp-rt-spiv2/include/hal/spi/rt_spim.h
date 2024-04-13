/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
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
 * Copyright (C) 2018 GreenWaves Technologies
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

#ifndef __RT__RT_SPIM_H__
#define __RT__RT_SPIM_H__

// #include "rt/rt_api.h"
#include "archi/pulp.h"
#include <stdint.h>


#define PULP_SPI_OFFSET       0xA102000

#define PULP_SPI_FIFO_SIZE 8

#define PULP_SPI_QPI    1
#define PULP_SPI_NO_QPI 0

#define PULP_SPI_CMD_RD    0
#define PULP_SPI_CMD_WR    1
#define PULP_SPI_CMD_QRD   2
#define PULP_SPI_CMD_QWR   3
#define PULP_SPI_CMD_SWRST 4

#define PULP_SPI_CSN0 0
#define PULP_SPI_CSN1 1
#define PULP_SPI_CSN2 2
#define PULP_SPI_CSN3 3

#define PULP_SPI_REG_STATUS                ( 0x00 )
#define PULP_SPI_REG_CLKDIV                ( 0x04 )
#define PULP_SPI_REG_SPICMD                ( 0x08 )
#define PULP_SPI_REG_SPIADR                ( 0x0C )
#define PULP_SPI_REG_SPILEN                ( 0x10 )
#define PULP_SPI_REG_SPIDUM                ( 0x14 )
#define PULP_SPI_REG_TXFIFO                ( 0x18 )
#define PULP_SPI_REG_RXFIFO                ( 0x20 )
#define PULP_SPI_REG_INTCFG                ( 0x24 )
#define PULP_SPI_REG_INTSTA                ( 0x28 )




/// @cond IMPLEM

#define __RT_SPIM_CTRL_CPOL_BIT 0
#define __RT_SPIM_CTRL_CPHA_BIT 2
#define __RT_SPIM_CTRL_WORDSIZE_BIT 4
#define __RT_SPIM_CTRL_ENDIANNESS_BIT 6
#define __RT_SPIM_CTRL_SET_MAX_BAUDRATE_BIT 8

/// @endcond



typedef struct __rt_spim_s rt_spim_t;

typedef struct __rt_spim_s {
  int max_baudrate;
#if defined(UDMA_VERSION) && UDMA_VERSION >= 1
  unsigned int cfg;
  char cs;
#endif
  char wordsize;
  char big_endian;
  signed char cs_gpio;
  char channel;

#if !defined(UDMA_VERSION)

  int div;
  rt_spim_t *next;

#elif defined(UDMA_VERSION) && UDMA_VERSION >= 2

  char byte_align;
  unsigned char div;
  char polarity;
  char phase;

#elif defined(UDMA_VERSION) && UDMA_VERSION == 1

  unsigned char div;
  char polarity;
  char phase;

#endif

} rt_spim_t;



/**
* @ingroup groupDrivers
*/



/**
 * @defgroup SPIM SPIM
 *
 * The SPIM driver provides support for transferring data between an external SPIM device
 * and the chip running this driver.
 *
 */

/**
 * @addtogroup SPIM
 * @{
 */

/**@{*/




/** \enum rt_spim_wordsize_e
 * \brief Wordsize of the SPI bitstream elements.
 *
 * This is used to know how the endianness must be applied.
 */
typedef enum {
  RT_SPIM_WORDSIZE_8 = 0,     /*!< Each element is 8 bits. Thus the endianness has no effect. */
  RT_SPIM_WORDSIZE_32 = 1     /*!< Each element is 32 bits. The way each element is stored in memory can then be specified with the endianness. */
} rt_spim_wordsize_e;



/** \struct rt_spim_conf_t
 * \brief SPI master configuration structure.
 *
 * This structure is used to pass the desired SPI master configuration to the runtime when opening a device.
 */
typedef struct __rt_spim_conf_s {
  int max_baudrate;       /*!< Maximum baudrate for the SPI bitstream which can be used with the opened device . */
  char wordsize;          /*!< Wordsize of the elements in the bitstream. Can be RT_SPIM_WORDSIZE_8 for 8 bits data or RT_SPIM_WORDSIZE_32 for 32 bits data. This is used to interpret the endianness. */
  char big_endian;        /*!< If 1, the elements are stored in memory in a big-endian way, i.e. the most significant byte is stored at the lowest address. This is taken into account only if the wordsize is 32 bits. */
  char polarity;          /*!< Polarity of the clock. */
  char phase;             /*!< Phase of the clock. */
  signed char cs_gpio;    /*!< If it is different from -1, the specified number is used to drive a GPIO which is used as a chip select for the SPI device. The cs field is then ignored. */
  signed char cs;         /*!< If cs_gpio is -1, the normal chip select pins are used and this field specifies which one to use for the device. */
  signed char id;         /*!< If it is different from -1, this specifies on which SPI interface the device is connected. */
} rt_spim_conf_t;



/** \enum rt_spim_control_e
 * \brief Possible parameters which can be set through the rt_spim_control API function.
 *
 * This is used to reconfigure dynamically some of the parameters of an opened device.
 */
typedef enum {
  RT_SPIM_CTRL_CPOL0             = 1 << __RT_SPIM_CTRL_CPOL_BIT,             /*!< Set the clock polarity to 0. */
  RT_SPIM_CTRL_CPOL1             = 2 << __RT_SPIM_CTRL_CPOL_BIT,             /*!< Set the clock polarity to 1. */
  RT_SPIM_CTRL_CPHA0             = 1 << __RT_SPIM_CTRL_CPHA_BIT,             /*!< Set the clock phase to 0. */
  RT_SPIM_CTRL_CPHA1             = 2 << __RT_SPIM_CTRL_CPHA_BIT,             /*!< Set the clock phase to 1. */
  RT_SPIM_CTRL_WORDSIZE_8        = 1 << __RT_SPIM_CTRL_WORDSIZE_BIT,         /*!< Set the wordsize to 8 bits. */
  RT_SPIM_CTRL_WORDSIZE_32       = 2 << __RT_SPIM_CTRL_WORDSIZE_BIT,         /*!< Set the wordsize to 32 bits. */
  RT_SPIM_CTRL_BIG_ENDIAN        = 1 << __RT_SPIM_CTRL_ENDIANNESS_BIT,       /*!< Handle the elements in memory in a big-endian way. */
  RT_SPIM_CTRL_LITTLE_ENDIAN     = 2 << __RT_SPIM_CTRL_ENDIANNESS_BIT,       /*!< Handle the elements in memory in a little-endian way. */
  RT_SPIM_CTRL_SET_MAX_BAUDRATE  = 1 << __RT_SPIM_CTRL_SET_MAX_BAUDRATE_BIT, /*!< Change maximum baudrate. */
} rt_spim_control_e;



/** \enum rt_spim_cs_e
 * \brief Specifies chip select mode.
 *
 * 
 */
typedef enum {
  RT_SPIM_CS_AUTO     = 0,    /*!< Handles the chip select automatically. It is set low just before the transfer is started and set back high when the transfer is finished. */
  RT_SPIM_CS_KEEP     = 1,    /*!< Handle the chip select manually. It is set low just before the transfer is started and is kept low until the next transfer. */
  RT_SPIM_CS_NONE     = 2,    /*!< Don't do anything with the chip select. */
} rt_spim_cs_e;


typedef enum {
  RT_GPIO_IS_OUT = 1,   /*!< The GPIO is an output, the chip can transmit a value. */
  RT_GPIO_IS_IN  = 0    /*!< The GPIO is an input, the chip can receive a value. */
} rt_gpio_dir_e;


/** \brief Initialize an SPI master configuration with default values.
 *
 * This function can be called to get default values for all parameters before setting some of them.
 * The structure containing the configuration must be kept alive until the SPI device is opened.
 *
 * \param conf A pointer to the SPI master configuration.
 */
void rt_spim_conf_init(rt_spim_conf_t *conf);



/** \brief Open an SPI device.
 *
 * This function must be called before the SPI device can be used. It will do all the needed configuration to make it
 * usable and also return a handle used to refer to this opened device when calling other functions.
 * This operation is asynchronous and its termination can be managed through an event.
 *
 * \param dev_name  The device name in case the connection must be configured automatically. This name should correspond to the one used to configure the devices managed by the runtime. If it is NULL, all connection information must be provided in the configuration structure (interface id and chip select).
 * \param conf      A pointer to the SPI configuration. Can be NULL to take default configuration.
 * \param event     The event used for managing termination.
 * \return          NULL if the device is not found, or a handle identifying the device and which can be used with other functions.
 */
void rt_spim_open(char *dev_name, rt_spim_conf_t *conf, rt_spim_t *spim);



/** \brief Close an opened SPI device.
 *
 * This function can be called to close an opened SPI device once it is not needed anymore, in order to free
 * all allocated resources. Once this function is called, the device is not accessible anymore and must be opened
 * again before being used.
 * This operation is asynchronous and its termination can be managed through an event.
 *
 * \param handle    The handler of the device which was returned when the device was opened.
 * \param event     The event used for managing termination.
 */
void rt_spim_close(rt_spim_t *handle);



/** \brief Dynamically change the device configuration.
 *
 * This function can be called to change part of the device configuration after it has been opened.
 *
 * \param handle    The handle of the SPI device which was returned when the device was opened.
 * \param cmd       The command which specifies which parameters of the driver to modify and for some of them also their values.
 * \param arg       An additional value which is required for some parameters when they are set.
 */
static inline void rt_spim_control(rt_spim_t *handle, rt_spim_control_e cmd, uint32_t arg);



/** \brief Enqueue a write copy to the SPI (from Chip to SPI device).
 *
 * This function can be used to send data to the SPI device.
 * The copy will make an asynchronous transfer between the SPI and one of the chip memory.
 * An event can be specified in order to be notified when the transfer is finished.
 * This is using classic SPI transfer with MOSI and MISO lines.
 * Note that the event attached to this call is triggered when the chip is ready to send another spi stream 
 * not when the spi stream has been fully sent. There can be some buffering effects which
 * make the chip send a few bits after the event is triggered.
 * Due to hardware constraints, the address of the buffer must be aligned on 4 bytes and the size must be a multiple of 4.
 *
 * \param handle      The handle of the SPI device which was returned when the device was opened.
 * \param data     The address in the chip where the data to be sent must be read.
 * \param len         The size in bits of the copy.
 * \param cs_mode     The mode for managing the chip select.
 * \param event       The event used to notify the end of transfer. See the documentation of rt_event_t for more details.
 */
static inline void rt_spim_send(rt_spim_t *handle, void *data, int len, rt_spim_cs_e cs_mode);



/** \brief Enqueue a read copy to the SPI (from Chip to SPI device).
 *
 * This function can be used to receive data from the SPI device.
 * The copy will make an asynchronous transfer between the SPI and one of the chip memory.
 * An event can be specified in order to be notified when the transfer is finished.
 * This is using classic SPI transfer with MOSI and MISO lines.
 * Due to hardware constraints, the address of the buffer must be aligned on 4 bytes and the size must be a multiple of 4.
 *
 * \param handle      The handle of the SPI device which was returned when the device was opened.
 * \param data        The address in the chip where the received data must be written.
 * \param len         The size in bits of the copy.
 * \param cs_mode     The mode for managing the chip select.
 * \param event       The event used to notify the end of transfer. See the documentation of rt_event_t for more details.
 */
static inline void rt_spim_receive(rt_spim_t *handle, void *data, int len, rt_spim_cs_e cs_mode);



/** \brief Enqueue a read and write copy to the SPI (using full duplex mode).
 *
 * This function can be used to send and receive data with the SPI device using full duplex mode.
 * The copy will make an asynchronous transfer between the SPI and one of the chip memory.
 * An event can be specified in order to be notified when the transfer is finished.
 * This is using classic SPI transfer with MOSI and MISO lines.
 * Due to hardware constraints, the address of the buffer must be aligned on 4 bytes and the size must be a multiple of 4.
 *
 * \param handle      The handle of the SPI device which was returned when the device was opened.
 * \param tx_data     The address in the chip where the data to be sent must be read.
 * \param rx_data     The address in the chip where the received data must be written.
 * \param len         The size in bits of the copy.
 * \param cs_mode     The mode for managing the chip select.
 * \param event       The event used to notify the end of transfer. See the documentation of rt_event_t for more details.
 */
void rt_spim_transfer(rt_spim_t *handle, void *tx_data, void *rx_data, int len, rt_spim_cs_e cs_mode);



/** \brief Enqueue a write copy to the SPI using quad spi (from Chip to SPI device).
 *
 * This function can be used to send data to the SPI device using quad SPI.
 * The copy will make an asynchronous transfer between the SPI and one of the chip memory.
 * An event can be specified in order to be notified when the transfer is finished.
 * This is using quad SPI transfer with 4 data lines.
 * Due to hardware constraints, the address of the buffer must be aligned on 4 bytes and the size must be a multiple of 4.
 *
 * \param handle      The handle of the SPI device which was returned when the device was opened.
 * \param data        The address in the chip where the data to be sent must be read.
 * \param len         The size in bits of the copy.
 * \param cs_mode     The mode for managing the chip select.
 * \param event       The event used to notify the end of transfer. See the documentation of rt_event_t for more details.
 */
static inline void rt_spim_send_qspi(rt_spim_t *handle, void *data, int len, rt_spim_cs_e cs_mode);



/** \brief Enqueue a read copy to the SPI using quad SPI (from Chip to SPI device).
 *
 * This function can be used to receive data from the SPI device using quad SPI.
 * The copy will make an asynchronous transfer between the SPI and one of the chip memory.
 * An event can be specified in order to be notified when the transfer is finished.
 * This is using quad SPI transfer with 4 data lines.
 * Due to hardware constraints, the address of the buffer must be aligned on 4 bytes and the size must be a multiple of 4.
 *
 * \param handle      The handle of the SPI device which was returned when the device was opened.
 * \param data        The address in the chip where the received data must be written.
 * \param len         The size in bits of the copy.
 * \param cs_mode     The mode for managing the chip select.
 * \param event       The event used to notify the end of transfer. See the documentation of rt_event_t for more details.
 */
static inline void rt_spim_receive_qspi(rt_spim_t *handle, void *data, int len, rt_spim_cs_e cs_mode);


#if 0

/** \brief Flush all pending SPI transfers 
 *
 * This blocks the calling core until all transfers enqueued for sending
 * (e.g. with rt_spim_send or rt_spim_transfer) are finished and fully
 * sent to the device.
 * The core is clock-gated until this happens.
 */
static inline void rt_spim_flush(rt_spim_t *handle);

#endif


//!@}

/**
 * @} end of SPI master
 */







/// @cond IMPLEM

#if !defined(UDMA_VERSION)

void __rt_spim_v0_send(
  rt_spim_t *handle, void *buffer, int len, int qspi, rt_spim_cs_e mode);

void __rt_spim_v0_receive(
  rt_spim_t *handle, void *buffer, int len, int qspi, rt_spim_cs_e mode);

static inline void rt_spim_send(rt_spim_t *handle, void *data, int len, rt_spim_cs_e mode)
{
  __rt_spim_v0_send(handle, data, len, 0, mode);
}

static inline void rt_spim_receive(rt_spim_t *handle, void *data, int len, rt_spim_cs_e mode)
{
  __rt_spim_v0_receive(handle, data, len, 0, mode);
}

void __rt_spim_control(rt_spim_t *handle, rt_spim_control_e cmd, uint32_t arg);

static inline void rt_spim_control(rt_spim_t *handle, rt_spim_control_e cmd, uint32_t arg)
{
  __rt_spim_control(handle, cmd, arg);
}

#else

void __rt_spim_send(rt_spim_t *handle, void *data, int len, int qspi, rt_spim_cs_e mode);

void __rt_spim_receive(rt_spim_t *handle, void *data, int len, int qspi, rt_spim_cs_e mode);

static inline void rt_spim_send(rt_spim_t *handle, void *data, int len, rt_spim_cs_e mode)
{
  __rt_spim_send(handle, data, len, 0, mode );
}

static inline void rt_spim_receive(rt_spim_t *handle, void *data, int len, rt_spim_cs_e mode)
{
  __rt_spim_receive(handle, data, len, 0, mode );
}

static inline void rt_spim_send_qspi(rt_spim_t *handle, void *data, int len, rt_spim_cs_e mode)
{
  __rt_spim_send(handle, data, len, 1, mode );
}

static inline void rt_spim_receive_qspi(rt_spim_t *handle, void *data, int len, rt_spim_cs_e mode)
{
  __rt_spim_receive(handle, data, len, 1, mode );
}

void __rt_spim_control(rt_spim_t *handle, rt_spim_control_e cmd, uint32_t arg);

static inline void rt_spim_control(rt_spim_t *handle, rt_spim_control_e cmd, uint32_t arg)
{
  __rt_spim_control(handle, cmd, arg);
}

// static inline void rt_spim_flush(rt_spim_t *handle)
// {
//   while (plp_udma_busy(handle->channel + 1))
//   {
//     // rt_wait_for_interrupt();
//     hal_itc_wait_for_interrupt();
//   }
// }

#endif







/// @endcond


#endif
