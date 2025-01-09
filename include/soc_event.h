/* Define for ji-mcu              */
/* Email:    3056830955@qq.com    */
/* Author:   huangjin 2024/7/4   */
/* V0.1 SOC Event and Interrupt */

#ifndef __H_SOC_EVENT__
#define __H_SOC_EVENT__

// #include "soc_common.h"

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "core_sys.h"
// #include "IC_udma.h"
#include "hal/pulp_io.h"
#include <stdio.h>
#include "hal/riscv/riscv_v5.h"
// #include <rt/rt_api.h>
#include <stdint.h>
#include "soc_printf.h"

typedef struct
{
  __IO u32 mask;
  __IO u32 mask_set;
  __IO u32 mask_clr;
  __IO u32 intc;
  __IO u32 int_set;
  __IO u32 int_clr;
  __IO u32 ack;
  __IO u32 ack_set;
  __IO u32 ack_clr;
  __IO u32 fifo;
}itc_t;

#define  pad_itc    ((itc_t*)Interrupt_ADDR)



#define SOC_TIMER_SEL_ENABLE_SHIFT 31
#define SOC_TIMER_SEL_EVT_SHIFT    0
#define SOC_TIMER_SEL_EVT_WIDTH    8
#define SOC_TIMER_SEL_EVT_MASK    ((~0U) >> (32 - SOC_TIMER_SEL_EVT_WIDTH))
//  #define SOC_TIMER_SEL_EVT_MASK    0xff
#define SOC_TIMER_SEL_ENABLE_DISABLED   	0
#define SOC_TIMER_SEL_ENABLE_ENABLED   	1
#define SOC_TIMER_SEL_ENABLE_DIS   	(0   << SOC_TIMER_SEL_ENABLE_SHIFT)
#define SOC_TIMER_SEL_ENABLE_ENA   	(1   << SOC_TIMER_SEL_ENABLE_SHIFT)
#define SOC_TIMER_SEL_EVT_VAL(val) 	((val) << SOC_TIMER_SEL_EVT_SHIFT)

// // related to XX_FIRST_MASK registers
#define SOC_NB_EVENT_REGS        2

 #define SOC_FC_MASK(x)    (SOC_FC_FIRST_MASK + (x)*4)
// #define SOC_CL_MASK(x)    (SOC_CL_FIRST_MASK + (x)*4)
// #define SOC_PR_MASK(x)    (SOC_PR_FIRST_MASK + (x)*4)


/* Interrupt Number Definition, according to the selected device */
typedef enum IRQn
{
  /******  RISC-V Processor Exceptions Numbers *******************************************************/

  /******  RISC-V specific Interrupt Numbers *********************************************************/
  s_timer0_lo_event = 8,
  s_timer0_hi_event = 9,
  s_timer1_lo_event = 10,
  s_timer1_hi_event = 11,

  s_ref_rise_fall_evnt = 14,
  s_gpio_event = 15,
  periph_event = 26,
  s_fc_err_events = 29

} IRQn_Type;

/*********************************************************************
 * @fn      __enable_irq
 *
 * @brief   Enable Global Interrupt
 *
 * @return  none
 */
RV_STATIC_INLINE void __enable_irq()
{
  __asm volatile("csrw mstatus, %0" : : "r"(0x6088));
}

/*********************************************************************
 * @fn      __disable_irq
 *
 * @brief   Disable Global Interrupt
 *
 * @return  none
 */
RV_STATIC_INLINE void __disable_irq()
{
  __asm volatile("csrw mstatus, %0" : : "r"(0x6000));
}

/*********************************************************************
 * @fn      __NOP
 *
 * @brief   nop
 *
 * @return  none
 */
RV_STATIC_INLINE void __NOP()
{
    __asm volatile("nop");
}

/*********************************************************************
 * @fn       __WFI
 *
 * @brief   Wait for Interrupt
 *
 * @return  none
 */
__attribute__((always_inline)) 
RV_STATIC_INLINE void __WFI(void)
{
//     NVIC->SCTLR &= ~(1 << 3); // wfi
    asm volatile("wfi");
}



RV_STATIC_INLINE void int_enable_value_set(uint32_t mask) { ITC_MASK  = mask ; }
RV_STATIC_INLINE u32 int_enable_value_get()               { uint32_t temp=ITC_MASK;return  temp ;}
RV_STATIC_INLINE void int_enable_set(uint32_t mask)       { ITC_MASK_SET = mask ;}
RV_STATIC_INLINE void int_enable_clr(uint32_t mask)       { ITC_MASK_CLR = mask ;}

RV_STATIC_INLINE void int_ack_value_set(uint32_t mask)    { ITC_ACK = mask ;}
RV_STATIC_INLINE u32 int_ack_value_get()                  { uint32_t temp = ITC_ACK ;  return temp;}
RV_STATIC_INLINE void int_ack_set(uint32_t mask)          { ITC_ACK_SET = mask ;}
RV_STATIC_INLINE void int_ack_clr(uint32_t mask)          { ITC_ACK_CLR = mask ;}

RV_STATIC_INLINE void int_status_value_set(uint32_t mask) { ITC = mask ;}
RV_STATIC_INLINE uint32_t int_status_value_get()          {  uint32_t temp = ITC ;  return temp;}
RV_STATIC_INLINE void int_status_set(uint32_t mask)       { ITC_SET = mask ;}
RV_STATIC_INLINE void int_status_clr(uint32_t mask)       {  ITC_CLR = mask ;}

RV_STATIC_INLINE uint32_t int_fifo_pop()                  { uint32_t temp = ITC_FIFO ;  return temp;}

RV_STATIC_INLINE void int_wait_for_interrupt()            {  asm volatile ("wfi");}


RV_STATIC_INLINE void int_wait_for_event_noirq(uint32_t mask) {

  int end = 0;
  do {

    uint32_t state = hal_irq_disable();
    if ((int_status_value_get() & mask) == 0) {
      int_enable_set(mask);
      asm volatile ("wfi");
      int_enable_clr(mask);
    } else {
      int_status_clr(mask);
      end = 1;
    }
    hal_irq_restore(state);
  } while (!end);
}
void soc_event_init();



RV_STATIC_INLINE void int_wait_for_event(uint32_t mask) {int_wait_for_event_noirq(mask);}

void interrupt_init();

void int_set_handler(int irq, void (*handler)());

RV_STATIC_INLINE void int_mask_set(uint32_t mask){
#if defined(__RISCV_GENERIC__)
  // Generic riscv case, e.g. Ibex
  hal_spr_read_then_set_from_reg(0x304, mask);

#elif defined(ITC_VERSION) && defined(EU_VERSION)
  // Case with ITC on FC and event unit on cluster, e.g. Wolfe
  if (hal_is_fc())
    int_enable_set(mask);
  else
    eu_irq_maskSet(mask);

#elif defined(ITC_VERSION)
  // Case with only ITC, e.g. Pulpissimo
  int_enable_set(mask);

#elif defined(EU_VERSION)
  // Case with only event unit, e.g. Gap
  eu_irq_maskSet(mask);
  // This is needed on architectures where the FC is using an event unit as we
  // use an elw instead of a wfi with interrupts disabled. The fact that the event
  // is active will make the core goes out of elw and the interrupt handler
  // will be called as soon as interrupts are enabled.
  if (hal_is_fc())
    eu_evt_maskSet(mask);
#endif
  int_enable_set(mask);
}

RV_STATIC_INLINE void int_mask_clr(uint32_t mask)
{
#if defined(__RISCV_GENERIC__)//通用risv
  hal_spr_read_then_clr_from_reg(0x304, mask);

#elif defined(ITC_VERSION) && defined(EU_VERSION)//itc版本和eu版本
  if (hal_is_fc())
    int_enable_clr(mask);
  else
    eu_irq_maskClr(mask);
#endif
  int_enable_clr(mask);
  
}

RV_STATIC_INLINE void int_clr(uint32_t mask)
{
#if defined(__RISCV_GENERIC__)
  // TODO

#elif defined(ITC_VERSION) && defined(EU_VERSION)
  if (hal_is_fc())
    int_status_clr(mask);
  else
    eu_evt_clr(mask);

#elif defined(ITC_VERSION)
  int_status_clr(mask);

#elif defined(EU_VERSION) && EU_VERSION >= 3
  eu_evt_clr(mask);
#endif
  int_status_clr(mask);
}

RV_STATIC_INLINE uint32_t int_get_fc_vector_base()
{

  return hal_spr_read(0x305) & ~1;
  // return hal_spr_read(0x305) ;

  // return 0;
}

RV_STATIC_INLINE void int_set_fc_vector_base(uint32_t base)
{
  hal_spr_write(0x305, base);

}

extern unsigned char _vector_base;

static inline uint32_t int_vector_base()
{
  return (uint32_t)&_vector_base;
}
#endif
