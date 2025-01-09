
#include "soc_event.h"

#define ARCHI_SOC_EVENT_NB_TOTAL 256
#define FC_EVT_SOC_EVT 26
volatile uint32_t pos_soc_event_status[ARCHI_SOC_EVENT_NB_TOTAL / 32];
volatile uint32_t vector_handler[32];

extern void pos_soc_event_handler_asm();
void pos_irq_no_handler();
extern void timer_handler1_asm();

void soc_event_init()
{

    // Activate soc events handler
     int_set_handler(FC_EVT_SOC_EVT, pos_soc_event_handler_asm);
     int_mask_set(1<<FC_EVT_SOC_EVT);

}

static uint32_t int_get_itvec(uint32_t ItBaseAddr, uint32_t ItIndex, uint32_t ItHandler)
{
    /* Prepare 32bit container to be stored at
     *(ItBaseAddr+ItIndex) containing a relative jump from
      (ItBaseAddr+ItIndex) to Handler */

    uint32_t S = ((uint32_t)ItHandler - (ItBaseAddr + ItIndex * 4));
    uint32_t R = 0x6F; /* Jal opcode with x0 as target, eg no return */

    /* Forge JAL x0, Address: with Address = S => Bin[31:0] = [S20
    | S10:1 | S11 | S19:12 | 00000 01101111] */

    R = __BITINSERT(R, __BITEXTRACT(S, 1, 20), 1, 31);
    R = __BITINSERT(R, __BITEXTRACT(S, 10, 1), 10, 21);
    R = __BITINSERT(R, __BITEXTRACT(S, 1, 11), 1, 20);
    R = __BITINSERT(R, __BITEXTRACT(S, 8, 12), 8, 12);

    return R;
}

void int_set_handler(int irq, void (*handler)())
{
#if defined(__RISCV_GENERIC__)
    if (irq < 16)
        return;

    irq -= 16;
#endif

    uint32_t base = int_get_fc_vector_base();

    uint32_t jmpAddr = base + 0x4 * irq;

    *(volatile uint32_t *)jmpAddr = int_get_itvec(base, irq, (uint32_t)handler);

    // selective_flush_icache_addr(jmpAddr & ~(ICACHE_LINE_SIZE-1));

    // if (!rt_is_fc() || plp_pmu_cluster_isOn(0)) flush_all_icache_banks_common(plp_icache_cluster_remote_base(0));

#if defined(PLP_FC_HAS_ICACHE)
    flush_all_icache_banks_common(plp_icache_fc_base());
#endif
}

void interrupt_init()
{
    // We may enter the runtime with some interrupts active for example
    // if we force the boot to jump to the runtime through jtag.
    int_mask_clr(-1);

    // As the FC code may not be at the beginning of the L2, set the
    // vector base to get proper interrupt handlers

    int_set_fc_vector_base(int_vector_base());

    // for (int i = 0; i < 32; i++)
    // {
    //     vector_handler[i] = (uint32_t)pos_irq_no_handler;
    // }
    int_set_handler(s_timer0_lo_event, timer_handler1_asm);
    int_mask_set(1 << s_timer0_lo_event);
    
}
// pos_irq_set_c_handler
void int_set_c_handler(int irq, void (*handler)())
{
    // pos_irq_c_handlers[irq] = (uint32_t)handler;
    vector_handler[irq] = (uint32_t)handler;
}


 /** 处理定时器 low 中断 */
 void timer_lo_irq_handler()
 {
    //  soc_printf("Timer Lo irq enter!\n");
    //  return;
 }
/* 处理定时器 high 中断 */
void timer_hi_irq_handler()
 {
    //  soc_printf("Timer Hi irq enter!\n");
    //  return;
 }
uint8_t flag =0;

void timer_handler()
{
    flag =1 ;

}

void external_interrupt_handler()
{
    // 读取中断号，清楚中断标志
    int irq=0;
    uint8_t flag =0;
    if(irq){
        flag =1 ;
    }
    else ;
	return ;
}


uint32_t int_handler(uint32_t epc, uint32_t cause)
{
	uint32_t return_pc = epc;
    uint32_t cause_code = cause & 0x7FFFFFFF; // 屏蔽除最高位外的其余位 判断是否处于中断

    if (cause && 0x80000000) {//如果处于中断则进入if
		/* Asynchronous trap - interrupt */
		switch (cause_code) {
		case 3:
            soc_printf("software interruption!\n");
            break;
		case 7:
            soc_printf("timer interruption!\n");
            // mDelaymS(200);
			timer_handler();
			break;
		case 11:
            soc_printf("external interruption!\n");
            external_interrupt_handler();
			break;
		default:
            soc_printf("Unknown async exception! Code = 1\n");
            break;
		}
	} 
	else {
		/* Synchronous trap - exception  同步类型错误*/
        soc_printf("Sync exceptions! Code = 1\n");
        soc_printf("OOPS! What can I do!");
        return_pc += 4;
	}

	return return_pc;
}

// void wait_soc_event()
// {
//     hal_itc_enable_set(1 << ARCHI_FC_EVT_SOC_EVT);
//     while (!((hal_itc_status_value_get() >> ARCHI_FC_EVT_SOC_EVT) & 1))
//     {
//         // hal_itc_wait_for_interrupt();
//     }
//     hal_itc_fifo_pop();
//     hal_itc_status_clr(1 << ARCHI_FC_EVT_SOC_EVT);
//     hal_itc_enable_clr(1 << ARCHI_FC_EVT_SOC_EVT);
// }
