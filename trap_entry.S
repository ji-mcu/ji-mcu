#define REGBYTES  4
#define STORE     sw
#define LOAD      lw


.macro reg_save 
    addi sp, sp, -32*REGBYTES
    STORE x1, 1*REGBYTES(sp)
    STORE x2, 2*REGBYTES(sp)
    STORE x3, 3*REGBYTES(sp)
    STORE x4, 4*REGBYTES(sp)
    STORE x5, 5*REGBYTES(sp)
    STORE x6, 6*REGBYTES(sp)
    STORE x7, 7*REGBYTES(sp)
    STORE x8, 8*REGBYTES(sp)
    STORE x9, 9*REGBYTES(sp)
    STORE x10, 10*REGBYTES(sp)
    STORE x11, 11*REGBYTES(sp)
    STORE x12, 12*REGBYTES(sp)
    STORE x13, 13*REGBYTES(sp)
    STORE x14, 14*REGBYTES(sp)
    STORE x15, 15*REGBYTES(sp)
    STORE x16, 16*REGBYTES(sp)
    STORE x17, 17*REGBYTES(sp)
    STORE x18, 18*REGBYTES(sp)
    STORE x19, 19*REGBYTES(sp)
    STORE x20, 20*REGBYTES(sp)
    STORE x21, 21*REGBYTES(sp)
    STORE x22, 22*REGBYTES(sp)
    STORE x23, 23*REGBYTES(sp)
    STORE x24, 24*REGBYTES(sp)
    STORE x25, 25*REGBYTES(sp)
#ifndef SIMULATION
    STORE x26, 26*REGBYTES(sp)
    STORE x27, 27*REGBYTES(sp)
#endif
    STORE x28, 28*REGBYTES(sp)
    STORE x29, 29*REGBYTES(sp)
    STORE x30, 30*REGBYTES(sp)
    STORE x31, 31*REGBYTES(sp)

.endm

.macro reg_restore
    LOAD x1, 1*REGBYTES(sp)
    LOAD x2, 2*REGBYTES(sp)
    LOAD x3, 3*REGBYTES(sp)
    LOAD x4, 4*REGBYTES(sp)
    LOAD x5, 5*REGBYTES(sp)
    LOAD x6, 6*REGBYTES(sp)
    LOAD x7, 7*REGBYTES(sp)
    LOAD x8, 8*REGBYTES(sp)
    LOAD x9, 9*REGBYTES(sp)
    LOAD x10, 10*REGBYTES(sp)
    LOAD x11, 11*REGBYTES(sp)
    LOAD x12, 12*REGBYTES(sp)
    LOAD x13, 13*REGBYTES(sp)
    LOAD x14, 14*REGBYTES(sp)
    LOAD x15, 15*REGBYTES(sp)
    LOAD x16, 16*REGBYTES(sp)
    LOAD x17, 17*REGBYTES(sp)
    LOAD x18, 18*REGBYTES(sp)
    LOAD x19, 19*REGBYTES(sp)
    LOAD x20, 20*REGBYTES(sp)
    LOAD x21, 21*REGBYTES(sp)
    LOAD x22, 22*REGBYTES(sp)
    LOAD x23, 23*REGBYTES(sp)
    LOAD x24, 24*REGBYTES(sp)
    LOAD x25, 25*REGBYTES(sp)
#ifndef SIMULATION
    LOAD x26, 26*REGBYTES(sp)
    LOAD x27, 27*REGBYTES(sp)
#endif
    LOAD x28, 28*REGBYTES(sp)
    LOAD x29, 29*REGBYTES(sp)
    LOAD x30, 30*REGBYTES(sp)
    LOAD x31, 31*REGBYTES(sp)

    addi sp, sp, 32*REGBYTES

.endm

    .section    .vectors,"ax",@progbits
    .align  1
    //.global _vector_base
_vector_base:
    #.option norvc;
        j   timer_handler1_ASM                 //0 00
        j   irq_default_handler        //1b 04
        j   irq_default_handler        //2 08
        j   irq_default_handler        //3: 0c Machne software interupt
        j   irq_default_handler        //4 10
    /* External Interrupts */
        j   irq_default_handler        //5 14
        j   irq_default_handler        //6 18
        j   timer_handler1        //7:Machine timer interrupt 
        j   irq_default_handler        //8
        j   irq_default_handler        //9
        j   irq_default_handler        //10
        j   external_interrupt_handler        //11: Machine external internal
        j   irq_default_handler        //12
        j   irq_default_handler        //13
        j   irq_default_handler        //14
        j   irq_default_handler        //15

  #.org 0x80
  #.option rvc;

    .section    .vectors.vector_handler, "ax", @progbits

    .weak   timer_handler1_ASM                 //0
    .weak   irq_default_handler        //1
    .weak   irq_default_handler        //2
    .weak   irq_default_handler        //3: Machne software interupt
    .weak   irq_default_handler        //4
    /* External Interrupts */
    .weak   irq_default_handler        //5
    .weak   irq_default_handler        //6
    .weak   timer_handler1        //7:Machine timer interrupt 
    .weak   irq_default_handler        //8
    .weak   irq_default_handler        //9
    .weak   irq_default_handler        //10
    .weak   external_interrupt_handler        //11: Machine external internal
    .weak   irq_default_handler        //12
    .weak   irq_default_handler        //13
    .weak   irq_default_handler        //14
    .weak   irq_default_handler        //15

timer_handler1:  
    1:  j 1b
external_interrupt_handler:  
    1:  j 1b
irq_default_handler:
    1:  j 1b

/* ===================================ssd======= [ Timer B Compare handler ] === */
timer_handler1_ASM:
    reg_save 
    #csrr a0, mcause
    #csrr a1, mepc
	#srli a2, a0, 31		                /* MSB of mcause is 1 if handing an asynchronous interrupt - shift to LSB to clear other bits. */
	#beq a2, x0, handle_synchronous		/* Branch past interrupt handing if not asynchronous. */
    call timer_handler1
    //call external_interrupt_handler
    reg_restore
    mret

external_interrupt_handler_ASM:
    reg_save
    call external_interrupt_handler
    reg_restore
    mret
    .section      .text	
    .balign 4
    .global trap_entry
trap_entry:

    reg_save
    csrr a0, mcause
    csrr a1, mepc
//test_if_asynchronous:
//	srli a2, a0, 31		                /* MSB of mcause is 1 if handing an asynchronous interrupt - shift to LSB to clear other bits. */
//	beq a2, x0, handle_synchronous		/* Branch past interrupt handing if not asynchronous. */

    call timer_handler1
   //call external_interrupt_handler
    reg_restore
    mret

handle_synchronous:
    addi a1, a1, 4
    csrw mepc, a1

.weak int_handler
int_handler:
1:
    j 1b
