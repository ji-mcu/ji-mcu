#ifndef __ARCHI_PULPISSIMO_MEMORY_MAP_H_UART0__
#define __ARCHI_PULPISSIMO_MEMORY_MAP_H_UART0__



/*
 * SOC PERIPHERALS
 */

#define PERI_UDMA_ADDR                      0x1A104000


#define UART0_RX_SADDR_OFFSET                 0x80
#define UART0_RX_SIZE_OFFSET                  0x84
#define UART0_RX_CFG_OFFSET                   0x88
#define UART0_TX_SADDR_OFFSET                 0x90
#define UART0_TX_SIZE_OFFSET                  0x94
#define UART0_TX_CFG_OFFSET                   0x98
#define UART0_STATUS_OFFSET                   0xA0
#define UART0_SETUP_OFFSET                    0xA4
#define UART0_ERROR_OFFSET                    0xA8
#define UART0_IRQ_EN_OFFSET                   0xAC
#define UART0_VALID_OFFSET                    0xB0
#define UART0_DATA_OFFSET                     0xB4

#define UART1_RX_SADDR_OFFSET                 0x100
#define UART1_RX_SIZE_OFFSET                  0x104
#define UART1_RX_CFG_OFFSET                   0x108
#define UART1_TX_SADDR_OFFSET                 0x110
#define UART1_TX_SIZE_OFFSET                  0x114
#define UART1_TX_CFG_OFFSET                   0x118
#define UART1_STATUS_OFFSET                   0x120
#define UART1_SETUP_OFFSET                    0x124
#define UART1_ERROR_OFFSET                    0x128
#define UART1_IRQ_EN_OFFSET                   0x12C
#define UART1_VALID_OFFSET                    0x130
#define UART1_DATA_OFFSET                     0x134

#define PERI_UART0_RX_SADDR_ADDR            ( PERI_UDMA_ADDR + UART0_RX_SADDR_OFFSET )
#define PERI_UART0_RX_SIZE_ADDR             ( PERI_UDMA_ADDR + UART0_RX_SIZE_OFFSET  )
#define PERI_UART0_RX_CFG_ADDR              ( PERI_UDMA_ADDR + UART0_RX_CFG_OFFSET )
#define PERI_UART0_TX_SADDR_ADDR            ( PERI_UDMA_ADDR + UART0_TX_SADDR_OFFSET  )
#define PERI_UART0_TX_SIZE_ADDR             ( PERI_UDMA_ADDR + UART0_TX_SIZE_OFFSET )
#define PERI_UART0_TX_CFG_ADDR              ( PERI_UDMA_ADDR + UART0_TX_CFG_OFFSET  )
#define PERI_UART0_STATUS_ADDR              ( PERI_UDMA_ADDR + UART0_STATUS_OFFSET )
#define PERI_UART0_SETUP_ADDR               ( PERI_UDMA_ADDR + UART0_SETUP_OFFSET  )
#define PERI_UART0_ERROR_ADDR               ( PERI_UDMA_ADDR + UART0_ERROR_OFFSET )
#define PERI_UART0_IRQ_EN_ADDR              ( PERI_UDMA_ADDR + UART0_IRQ_EN_OFFSET )
#define PERI_UART0_VALID_ADDR               ( PERI_UDMA_ADDR + UART0_VALID_OFFSET )
#define PERI_UART0_DATA_ADDR                ( PERI_UDMA_ADDR + UART0_DATA_OFFSET )

#define PERI_UART1_RX_SADDR_ADDR            ( PERI_UDMA_ADDR + UART1_RX_SADDR_OFFSET )
#define PERI_UART1_RX_SIZE_ADDR             ( PERI_UDMA_ADDR + UART1_RX_SIZE_OFFSET  )
#define PERI_UART1_RX_CFG_ADDR              ( PERI_UDMA_ADDR + UART1_RX_CFG_OFFSET )
#define PERI_UART1_TX_SADDR_ADDR            ( PERI_UDMA_ADDR + UART1_TX_SADDR_OFFSET  )
#define PERI_UART1_TX_SIZE_ADDR             ( PERI_UDMA_ADDR + UART1_TX_SIZE_OFFSET )
#define PERI_UART1_TX_CFG_ADDR              ( PERI_UDMA_ADDR + UART1_TX_CFG_OFFSET  )
#define PERI_UART1_STATUS_ADDR              ( PERI_UDMA_ADDR + UART1_STATUS_OFFSET )
#define PERI_UART1_SETUP_ADDR               ( PERI_UDMA_ADDR + UART1_SETUP_OFFSET  )
#define PERI_UART1_ERROR_ADDR               ( PERI_UDMA_ADDR + UART1_ERROR_OFFSET )
#define PERI_UART1_IRQ_EN_ADDR              ( PERI_UDMA_ADDR + UART1_IRQ_EN_OFFSET )
#define PERI_UART1_VALID_ADDR               ( PERI_UDMA_ADDR + UART1_VALID_OFFSET )
#define PERI_UART1_DATA_ADDR                ( PERI_UDMA_ADDR + UART1_DATA_OFFSET )


void uart_basic_function_test();
void uart0_tx_test(int ram_addr,int tx_size,int setup);
void uart0_rx_test(int ram_addr,int rx_size,int setup);
void uart1_tx_test(int ram_addr,int tx_size,int setup);
void uart1_rx_test(int ram_addr,int rx_size,int setup);

#endif


#ifndef __RT_UART_BAUDRATE
#define __RT_UART_BAUDRATE 625000
#endif

#define NULL ((void *)0)

typedef struct rt_uart_conf_s {
  unsigned int baudrate;         /*!< Required baudrate. */
  int itf;                       /*!< Interface ID on which the uart is connected. */
} rt_uart_conf_t;
typedef struct rt_event_s rt_event_t;


struct rt_event_sched_s;

typedef struct rt_event_sched_s {
  struct rt_event_s *first;
  struct rt_event_s *last;
  struct rt_event_s *first_free;
  struct rt_thread_s *waiting;
  //rt_error_callback_t error_cb;
  void *error_arg;
} rt_event_sched_t;

typedef struct hal_bridge_req_s {
  uint32_t next;
  uint32_t size;
  uint32_t type;
  uint32_t done;
  uint32_t popped;
  uint32_t padding;
  union {
    struct {
      uint32_t name_len;
      uint32_t name;
      uint32_t flags;
      uint32_t mode;
      uint32_t retval;
    } open;
    struct {
      uint32_t file;
      uint32_t retval;
    } close;
    struct {
      uint32_t file;
      uint32_t ptr;
      uint32_t len;
      uint32_t retval;
    } read;
    struct {
      uint32_t file;
      uint32_t ptr;
      uint32_t len;
      uint32_t retval;
    } write;
    struct {
      uint64_t screen;
      uint32_t name_len;
      uint32_t name;
      uint32_t width;
      uint32_t height;
      uint32_t format;
    } fb_open;
    struct {
      uint64_t screen;
      uint32_t addr;
      uint32_t posx;
      uint32_t posy;
      uint32_t width;
      uint32_t height;
    } fb_update;
  };
} hal_bridge_req_t;

typedef struct rt_bridge_req_s {
  hal_bridge_req_t header;
  rt_event_t *event;
} rt_bridge_req_t;


typedef struct rt_periph_copy_s {
  unsigned int addr;
  unsigned int size;
  unsigned int cfg;
  unsigned int ctrl;
  unsigned int enqueue_callback;
#if defined(UDMA_VERSION) && UDMA_VERSION == 1
  unsigned int end_callback;
#endif
  struct rt_periph_copy_s *next;
  struct rt_event_s *event;
  unsigned int repeat;
  unsigned int repeat_size;
  union {
    struct {
      unsigned int rx_addr;
      unsigned int rx_size;
    } dual;
    struct {
      unsigned int hyper_addr;
      unsigned int pending_hyper_addr;
      unsigned int pending_addr;
      unsigned int pending_size;
      char mbr;
      char channel;
      char async;
      char memcpy;
      short stride;
      short length;
      int size_2d;
    } hyper;
    struct {
      unsigned int val[8];
    } raw;
#if defined(UDMA_VERSION) && UDMA_VERSION == 1
    struct {
      unsigned char *data;
      int size;
      uint32_t base;
      short div;
      short xfer_pending;
    } i2c;
#endif
  } u;
#if PULP_CHIP == CHIP_GAP || !defined(ARCHI_HAS_FC)
  char *periph_data;
#else
  char periph_data[RT_PERIPH_COPY_PERIPH_DATA_SIZE];
#endif
} rt_periph_copy_t;





typedef struct rt_event_s {
  void (*callback)(void *);
  void *arg;
  struct rt_event_s *next;
  struct rt_event_sched_s *sched;
  struct rt_thread_s *thread;
  int pending;
  void (*saved_callback)(void *);
  void *saved_arg;
  int saved_pending;

  union {
    rt_periph_copy_t copy;
    struct {
      unsigned int data[3];
    };
    struct {
      unsigned int time;
    };
    rt_bridge_req_t bridge_req;
  };
} rt_event_t;



rt_event_t *rt_event_get_blocking(rt_event_sched_t *sched);


void rt_uart_conf_init(rt_uart_conf_t *conf);

void rt_time_wait_us(int time_us);

/*#ifdef __riscv__

static inline int rt_irq_disable()
{
  return hal_irq_disable();
}

static inline void rt_irq_restore(int irq)
{
  hal_irq_restore(irq);
}

static inline void rt_irq_enable()
{
  hal_irq_enable();
}

static inline void rt_irq_mask_set(unsigned int mask)
{
#if defined(ITC_VERSION) && defined(EU_VERSION)
  if (hal_is_fc()) hal_itc_enable_set(mask);
  else eu_irq_maskSet(mask);
#elif defined(ITC_VERSION)
  hal_itc_enable_set(mask);
#elif defined(EU_VERSION)
  eu_irq_maskSet(mask);
  // This is needed on architectures where the FC is using an event unit as we
  // use an elw instead of a wfi with interrupts disabled. The fact that the event
  // is active will make the core goes out of elw and the interrupt handler
  // will be called as soon as interrupts are enabled.
  eu_evt_maskSet(mask);
#endif
}

static inline void rt_irq_mask_clr(unsigned int mask)
{
#if defined(ITC_VERSION) && defined(EU_VERSION)
  if (hal_is_fc()) hal_itc_enable_clr(mask);
  else eu_irq_maskClr(mask);
#elif defined(ITC_VERSION)
  hal_itc_enable_clr(mask);
#elif defined(EU_VERSION)
  eu_irq_maskClr(mask);
  if (hal_is_fc()) eu_evt_maskClr(mask);
#endif
}

static inline void rt_irq_clr(unsigned int mask)
{
#if defined(ITC_VERSION)
  hal_itc_status_clr(mask);
#elif defined(EU_VERSION) && EU_VERSION >= 3
  eu_evt_clr(mask);
#endif
}

#else

int rt_irq_disable();

void rt_irq_restore(int irq);

void rt_irq_enable();

void rt_irq_mask_set(unsigned int mask);

void rt_irq_mask_clr(unsigned int mask);

#endif*/

void hal_soc_uart0_set(unsigned int addr,unsigned int value);
int hal_soc_uart0_read(unsigned int addr);


