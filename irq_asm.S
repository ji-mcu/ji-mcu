#
# Copyright (C) 2019 ETH Zurich, University of Bologna
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
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

  .section .text
  .global pos_irq_call_external_c_function
pos_irq_call_external_c_function:
    reg_save
    jalr ra, x12 // jump to x2,x2 had save timer_handler1's address 
    reg_restore
    jr   x9   // jum to x9 ,x9 had save timer_handler1_asm_ret's address ,use to leave handler

  .global pos_irq_call_external_c_function_full
pos_irq_call_external_c_function_full:
    reg_save //save all register
    jalr ra, x12 // jump to x2,x2 had save timer_handler1's address 
    reg_restore // restore all register
    jr   x9   // jum to x9 ,x9 had save timer_handler1_asm_ret's address ,use to leave handler

    .section .text
    .global timer_handler1_asm
  timer_handler1_asm:
    add sp, sp, -8
    sw  x12, 0(sp)
    sw  x9, 4(sp)
    la   x12,timer_handler1
    la   x9 ,timer_handler1_asm_ret
    j    pos_irq_call_external_c_function_full

timer_handler1_asm_ret:
    lw  x9, 4(sp)
    lw  x12, 0(sp)
    add sp, sp, 8
    mret
