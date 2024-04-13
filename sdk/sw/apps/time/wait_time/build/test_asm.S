
build/test:     file format elf32-littleriscv


Disassembly of section .vectors:

1c008000 <__irq_vector_base>:
1c008000:	0940006f          	j	1c008094 <__rt_no_irq_handler>
1c008004:	0900006f          	j	1c008094 <__rt_no_irq_handler>
1c008008:	08c0006f          	j	1c008094 <__rt_no_irq_handler>
1c00800c:	0880006f          	j	1c008094 <__rt_no_irq_handler>
1c008010:	0840006f          	j	1c008094 <__rt_no_irq_handler>
1c008014:	0800006f          	j	1c008094 <__rt_no_irq_handler>
1c008018:	07c0006f          	j	1c008094 <__rt_no_irq_handler>
1c00801c:	0780006f          	j	1c008094 <__rt_no_irq_handler>
1c008020:	0740006f          	j	1c008094 <__rt_no_irq_handler>
1c008024:	0700006f          	j	1c008094 <__rt_no_irq_handler>
1c008028:	06c0006f          	j	1c008094 <__rt_no_irq_handler>
1c00802c:	0680006f          	j	1c008094 <__rt_no_irq_handler>
1c008030:	0640006f          	j	1c008094 <__rt_no_irq_handler>
1c008034:	0600006f          	j	1c008094 <__rt_no_irq_handler>
1c008038:	05c0006f          	j	1c008094 <__rt_no_irq_handler>
1c00803c:	0580006f          	j	1c008094 <__rt_no_irq_handler>
1c008040:	0540006f          	j	1c008094 <__rt_no_irq_handler>
1c008044:	0500006f          	j	1c008094 <__rt_no_irq_handler>
1c008048:	04c0006f          	j	1c008094 <__rt_no_irq_handler>
1c00804c:	0480006f          	j	1c008094 <__rt_no_irq_handler>
1c008050:	0440006f          	j	1c008094 <__rt_no_irq_handler>
1c008054:	0400006f          	j	1c008094 <__rt_no_irq_handler>
1c008058:	03c0006f          	j	1c008094 <__rt_no_irq_handler>
1c00805c:	0380006f          	j	1c008094 <__rt_no_irq_handler>
1c008060:	0340006f          	j	1c008094 <__rt_no_irq_handler>
1c008064:	0300006f          	j	1c008094 <__rt_no_irq_handler>
1c008068:	02c0006f          	j	1c008094 <__rt_no_irq_handler>
1c00806c:	0280006f          	j	1c008094 <__rt_no_irq_handler>
1c008070:	0240006f          	j	1c008094 <__rt_no_irq_handler>
1c008074:	0200006f          	j	1c008094 <__rt_no_irq_handler>
1c008078:	01c0006f          	j	1c008094 <__rt_no_irq_handler>
1c00807c:	0180006f          	j	1c008094 <__rt_no_irq_handler>

1c008080 <_start>:
1c008080:	0180006f          	j	1c008098 <_stext>
1c008084:	0cc0006f          	j	1c008150 <__rt_illegal_instr>
	...

1c008090 <__rt_debug_struct_ptr>:
1c008090:	0e88                	addi	a0,sp,848
1c008092:	1c00                	addi	s0,sp,560

1c008094 <__rt_no_irq_handler>:
1c008094:	0000006f          	j	1c008094 <__rt_no_irq_handler>

Disassembly of section .text:

1c008098 <_stext>:
1c008098:	ffff9297          	auipc	t0,0xffff9
1c00809c:	ea028293          	addi	t0,t0,-352 # 1c000f38 <_edata>
1c0080a0:	ffff9317          	auipc	t1,0xffff9
1c0080a4:	f4830313          	addi	t1,t1,-184 # 1c000fe8 <__L2_priv0_end>
1c0080a8:	0002a023          	sw	zero,0(t0)
1c0080ac:	0291                	addi	t0,t0,4
1c0080ae:	fe62ede3          	bltu	t0,t1,1c0080a8 <_stext+0x10>
1c0080b2:	ffff9117          	auipc	sp,0xffff9
1c0080b6:	cce10113          	addi	sp,sp,-818 # 1c000d80 <stack>
1c0080ba:	3b4010ef          	jal	ra,1c00946e <__rt_init>
1c0080be:	00000513          	li	a0,0
1c0080c2:	00000593          	li	a1,0
1c0080c6:	00001397          	auipc	t2,0x1
1c0080ca:	9de38393          	addi	t2,t2,-1570 # 1c008aa4 <main>
1c0080ce:	000380e7          	jalr	t2
1c0080d2:	842a                	mv	s0,a0
1c0080d4:	412010ef          	jal	ra,1c0094e6 <__rt_deinit>
1c0080d8:	8522                	mv	a0,s0
1c0080da:	437000ef          	jal	ra,1c008d10 <exit>

1c0080de <_fini>:
1c0080de:	8082                	ret

1c0080e0 <__rt_thread_start>:
1c0080e0:	8526                	mv	a0,s1
1c0080e2:	80ca                	mv	ra,s2
1c0080e4:	8402                	jr	s0

1c0080e6 <__rt_thread_switch>:
1c0080e6:	00152023          	sw	ra,0(a0)
1c0080ea:	c140                	sw	s0,4(a0)
1c0080ec:	c504                	sw	s1,8(a0)
1c0080ee:	01252623          	sw	s2,12(a0)
1c0080f2:	01352823          	sw	s3,16(a0)
1c0080f6:	01452a23          	sw	s4,20(a0)
1c0080fa:	01552c23          	sw	s5,24(a0)
1c0080fe:	01652e23          	sw	s6,28(a0)
1c008102:	03752023          	sw	s7,32(a0)
1c008106:	03852223          	sw	s8,36(a0)
1c00810a:	03952423          	sw	s9,40(a0)
1c00810e:	03a52623          	sw	s10,44(a0)
1c008112:	03b52823          	sw	s11,48(a0)
1c008116:	02252a23          	sw	sp,52(a0)
1c00811a:	0005a083          	lw	ra,0(a1)
1c00811e:	41c0                	lw	s0,4(a1)
1c008120:	4584                	lw	s1,8(a1)
1c008122:	00c5a903          	lw	s2,12(a1)
1c008126:	0105a983          	lw	s3,16(a1)
1c00812a:	0145aa03          	lw	s4,20(a1)
1c00812e:	0185aa83          	lw	s5,24(a1)
1c008132:	01c5ab03          	lw	s6,28(a1)
1c008136:	0205ab83          	lw	s7,32(a1)
1c00813a:	0245ac03          	lw	s8,36(a1)
1c00813e:	0285ac83          	lw	s9,40(a1)
1c008142:	02c5ad03          	lw	s10,44(a1)
1c008146:	0305ad83          	lw	s11,48(a1)
1c00814a:	0345a103          	lw	sp,52(a1)
1c00814e:	8082                	ret

1c008150 <__rt_illegal_instr>:
1c008150:	fe112e23          	sw	ra,-4(sp)
1c008154:	fea12c23          	sw	a0,-8(sp)
1c008158:	00001517          	auipc	a0,0x1
1c00815c:	3fa50513          	addi	a0,a0,1018 # 1c009552 <__rt_handle_illegal_instr>
1c008160:	010000ef          	jal	ra,1c008170 <__rt_call_c_function>
1c008164:	ffc12083          	lw	ra,-4(sp)
1c008168:	ff812503          	lw	a0,-8(sp)
1c00816c:	30200073          	mret

1c008170 <__rt_call_c_function>:
1c008170:	7119                	addi	sp,sp,-128
1c008172:	c006                	sw	ra,0(sp)
1c008174:	c20e                	sw	gp,4(sp)
1c008176:	c412                	sw	tp,8(sp)
1c008178:	c616                	sw	t0,12(sp)
1c00817a:	c81a                	sw	t1,16(sp)
1c00817c:	ca1e                	sw	t2,20(sp)
1c00817e:	ce2e                	sw	a1,28(sp)
1c008180:	d032                	sw	a2,32(sp)
1c008182:	d236                	sw	a3,36(sp)
1c008184:	d43a                	sw	a4,40(sp)
1c008186:	d63e                	sw	a5,44(sp)
1c008188:	d842                	sw	a6,48(sp)
1c00818a:	da46                	sw	a7,52(sp)
1c00818c:	dc72                	sw	t3,56(sp)
1c00818e:	de76                	sw	t4,60(sp)
1c008190:	c0fa                	sw	t5,64(sp)
1c008192:	c6fe                	sw	t6,76(sp)
1c008194:	000500e7          	jalr	a0
1c008198:	4082                	lw	ra,0(sp)
1c00819a:	4192                	lw	gp,4(sp)
1c00819c:	4222                	lw	tp,8(sp)
1c00819e:	42b2                	lw	t0,12(sp)
1c0081a0:	4342                	lw	t1,16(sp)
1c0081a2:	43d2                	lw	t2,20(sp)
1c0081a4:	45f2                	lw	a1,28(sp)
1c0081a6:	5602                	lw	a2,32(sp)
1c0081a8:	5692                	lw	a3,36(sp)
1c0081aa:	5722                	lw	a4,40(sp)
1c0081ac:	57b2                	lw	a5,44(sp)
1c0081ae:	5842                	lw	a6,48(sp)
1c0081b0:	58d2                	lw	a7,52(sp)
1c0081b2:	5e62                	lw	t3,56(sp)
1c0081b4:	5ef2                	lw	t4,60(sp)
1c0081b6:	4f06                	lw	t5,64(sp)
1c0081b8:	4fb6                	lw	t6,76(sp)
1c0081ba:	6109                	addi	sp,sp,128
1c0081bc:	8082                	ret

1c0081be <udma_event_handler>:
1c0081be:	4080                	lw	s0,0(s1)
1c0081c0:	448c                	lw	a1,8(s1)
1c0081c2:	06040163          	beqz	s0,1c008224 <__rt_udma_no_copy>
1c0081c6:	4c50                	lw	a2,28(s0)
1c0081c8:	4848                	lw	a0,20(s0)
1c0081ca:	04061b63          	bnez	a2,1c008220 <dmaCmd>
1c0081ce:	c088                	sw	a0,0(s1)
1c0081d0:	4448                	lw	a0,12(s0)
1c0081d2:	e52d                	bnez	a0,1c00823c <handle_special_end>

1c0081d4 <resume_after_special_end>:
1c0081d4:	02058b63          	beqz	a1,1c00820a <checkTask>
1c0081d8:	4990                	lw	a2,16(a1)
1c0081da:	49c8                	lw	a0,20(a1)
1c0081dc:	c611                	beqz	a2,1c0081e8 <__rt_udma_call_enqueue_callback_resume>
1c0081de:	00000497          	auipc	s1,0x0
1c0081e2:	00a48493          	addi	s1,s1,10 # 1c0081e8 <__rt_udma_call_enqueue_callback_resume>
1c0081e6:	8602                	jr	a2

1c0081e8 <__rt_udma_call_enqueue_callback_resume>:
1c0081e8:	44d0                	lw	a2,12(s1)
1c0081ea:	c488                	sw	a0,8(s1)
1c0081ec:	4188                	lw	a0,0(a1)
1c0081ee:	41c4                	lw	s1,4(a1)
1c0081f0:	c208                	sw	a0,0(a2)
1c0081f2:	c244                	sw	s1,4(a2)
1c0081f4:	45c4                	lw	s1,12(a1)
1c0081f6:	88bd                	andi	s1,s1,15
1c0081f8:	4515                	li	a0,5
1c0081fa:	00a4c663          	blt	s1,a0,1c008206 <dual>
1c0081fe:	0064a463          	p.beqimm	s1,6,1c008206 <dual>
1c008202:	0074a263          	p.beqimm	s1,7,1c008206 <dual>

1c008206 <dual>:
1c008206:	4588                	lw	a0,8(a1)
1c008208:	c608                	sw	a0,8(a2)

1c00820a <checkTask>:
1c00820a:	4c0c                	lw	a1,24(s0)
1c00820c:	00000497          	auipc	s1,0x0
1c008210:	11848493          	addi	s1,s1,280 # 1c008324 <udma_event_handler_end>
1c008214:	00058463          	beqz	a1,1c00821c <checkTask+0x12>
1c008218:	11c0006f          	j	1c008334 <__rt_event_enqueue>
1c00821c:	1080006f          	j	1c008324 <udma_event_handler_end>

1c008220 <dmaCmd>:
1c008220:	1040006f          	j	1c008324 <udma_event_handler_end>

1c008224 <__rt_udma_no_copy>:
1c008224:	e3ff8497          	auipc	s1,0xe3ff8
1c008228:	04848493          	addi	s1,s1,72 # 26c <__rt_socevents_status>
1c00822c:	4080                	lw	s0,0(s1)
1c00822e:	4585                	li	a1,1
1c008230:	00a59533          	sll	a0,a1,a0
1c008234:	8c49                	or	s0,s0,a0
1c008236:	c080                	sw	s0,0(s1)
1c008238:	0ec0006f          	j	1c008324 <udma_event_handler_end>

1c00823c <handle_special_end>:
1c00823c:	04352563          	p.beqimm	a0,3,1c008286 <i2c_step1>
1c008240:	06452163          	p.beqimm	a0,4,1c0082a2 <i2c_step2>
1c008244:	bf41                	j	1c0081d4 <resume_after_special_end>

1c008246 <spim_step3>:
1c008246:	5408                	lw	a0,40(s0)
1c008248:	c448                	sw	a0,12(s0)
1c00824a:	4088                	lw	a0,0(s1)
1c00824c:	c848                	sw	a0,20(s0)
1c00824e:	c080                	sw	s0,0(s1)
1c008250:	44d0                	lw	a2,12(s1)
1c008252:	5448                	lw	a0,44(s0)
1c008254:	c208                	sw	a0,0(a2)
1c008256:	5048                	lw	a0,36(s0)
1c008258:	c248                	sw	a0,4(a2)
1c00825a:	4408                	lw	a0,8(s0)
1c00825c:	c608                	sw	a0,8(a2)
1c00825e:	0c60006f          	j	1c008324 <udma_event_handler_end>

1c008262 <spim_step2>:
1c008262:	00042623          	sw	zero,12(s0)
1c008266:	4088                	lw	a0,0(s1)
1c008268:	c848                	sw	a0,20(s0)
1c00826a:	c080                	sw	s0,0(s1)
1c00826c:	90000637          	lui	a2,0x90000
1c008270:	c070                	sw	a2,68(s0)
1c008272:	44d0                	lw	a2,12(s1)
1c008274:	04440513          	addi	a0,s0,68
1c008278:	c208                	sw	a0,0(a2)
1c00827a:	4511                	li	a0,4
1c00827c:	c248                	sw	a0,4(a2)
1c00827e:	4541                	li	a0,16
1c008280:	c608                	sw	a0,8(a2)
1c008282:	0a20006f          	j	1c008324 <udma_event_handler_end>

1c008286 <i2c_step1>:
1c008286:	5408                	lw	a0,40(s0)
1c008288:	c448                	sw	a0,12(s0)
1c00828a:	4088                	lw	a0,0(s1)
1c00828c:	c848                	sw	a0,20(s0)
1c00828e:	c080                	sw	s0,0(s1)
1c008290:	44d0                	lw	a2,12(s1)
1c008292:	4008                	lw	a0,0(s0)
1c008294:	c208                	sw	a0,0(a2)
1c008296:	5048                	lw	a0,36(s0)
1c008298:	c248                	sw	a0,4(a2)
1c00829a:	4408                	lw	a0,8(s0)
1c00829c:	c608                	sw	a0,8(a2)
1c00829e:	0860006f          	j	1c008324 <udma_event_handler_end>

1c0082a2 <i2c_step2>:
1c0082a2:	00042623          	sw	zero,12(s0)
1c0082a6:	4088                	lw	a0,0(s1)
1c0082a8:	c848                	sw	a0,20(s0)
1c0082aa:	c080                	sw	s0,0(s1)
1c0082ac:	02000613          	li	a2,32
1c0082b0:	c070                	sw	a2,68(s0)
1c0082b2:	44d0                	lw	a2,12(s1)
1c0082b4:	04440513          	addi	a0,s0,68
1c0082b8:	c208                	sw	a0,0(a2)
1c0082ba:	4505                	li	a0,1
1c0082bc:	c248                	sw	a0,4(a2)
1c0082be:	4541                	li	a0,16
1c0082c0:	c608                	sw	a0,8(a2)
1c0082c2:	0620006f          	j	1c008324 <udma_event_handler_end>

1c0082c6 <__rt_fc_socevents_handler>:
1c0082c6:	7119                	addi	sp,sp,-128
1c0082c8:	c022                	sw	s0,0(sp)
1c0082ca:	c226                	sw	s1,4(sp)
1c0082cc:	c42a                	sw	a0,8(sp)
1c0082ce:	c62e                	sw	a1,12(sp)
1c0082d0:	c832                	sw	a2,16(sp)
1c0082d2:	1a10a437          	lui	s0,0x1a10a
1c0082d6:	80040413          	addi	s0,s0,-2048 # 1a109800 <__rt_iodev_uart_baudrate+0x1a070e98>
1c0082da:	5048                	lw	a0,36(s0)
1c0082dc:	44bd                	li	s1,15
1c0082de:	00955c63          	ble	s1,a0,1c0082f6 <__rt_soc_evt_no_udma_channel>
1c0082e2:	e3ff8417          	auipc	s0,0xe3ff8
1c0082e6:	d4a40413          	addi	s0,s0,-694 # 2c <periph_channels>
1c0082ea:	00551493          	slli	s1,a0,0x5
1c0082ee:	94a2                	add	s1,s1,s0
1c0082f0:	4ccc                	lw	a1,28(s1)
1c0082f2:	4080                	lw	s0,0(s1)
1c0082f4:	8582                	jr	a1

1c0082f6 <__rt_soc_evt_no_udma_channel>:
1c0082f6:	44f5                	li	s1,29
1c0082f8:	00955863          	ble	s1,a0,1c008308 <__rt_soc_evt_no_udma>
1c0082fc:	fea50593          	addi	a1,a0,-22
1c008300:	058a                	slli	a1,a1,0x2
1c008302:	2745a583          	lw	a1,628(a1)
1c008306:	8582                	jr	a1

1c008308 <__rt_soc_evt_no_udma>:
1c008308:	e3ff8497          	auipc	s1,0xe3ff8
1c00830c:	f6448493          	addi	s1,s1,-156 # 26c <__rt_socevents_status>
1c008310:	02000593          	li	a1,32
1c008314:	00b54463          	blt	a0,a1,1c00831c <socevents_set>
1c008318:	0491                	addi	s1,s1,4
1c00831a:	1501                	addi	a0,a0,-32

1c00831c <socevents_set>:
1c00831c:	408c                	lw	a1,0(s1)
1c00831e:	80a5c633          	p.bsetr	a2,a1,a0
1c008322:	c090                	sw	a2,0(s1)

1c008324 <udma_event_handler_end>:
1c008324:	4402                	lw	s0,0(sp)
1c008326:	4492                	lw	s1,4(sp)
1c008328:	4522                	lw	a0,8(sp)
1c00832a:	45b2                	lw	a1,12(sp)
1c00832c:	4642                	lw	a2,16(sp)
1c00832e:	6109                	addi	sp,sp,128
1c008330:	30200073          	mret

1c008334 <__rt_event_enqueue>:
1c008334:	0035f513          	andi	a0,a1,3
1c008338:	02051963          	bnez	a0,1c00836a <__rt_handle_special_event>
1c00833c:	45c8                	lw	a0,12(a1)
1c00833e:	0005a423          	sw	zero,8(a1)
1c008342:	4110                	lw	a2,0(a0)
1c008344:	c601                	beqz	a2,1c00834c <__rt_no_first>
1c008346:	4150                	lw	a2,4(a0)
1c008348:	c60c                	sw	a1,8(a2)
1c00834a:	a011                	j	1c00834e <__rt_common>

1c00834c <__rt_no_first>:
1c00834c:	c10c                	sw	a1,0(a0)

1c00834e <__rt_common>:
1c00834e:	c14c                	sw	a1,4(a0)
1c008350:	4550                	lw	a2,12(a0)
1c008352:	00052623          	sw	zero,12(a0)
1c008356:	ca01                	beqz	a2,1c008366 <enqueue_end>
1c008358:	e3ff8517          	auipc	a0,0xe3ff8
1c00835c:	cb450513          	addi	a0,a0,-844 # c <__rt_thread_current>
1c008360:	4108                	lw	a0,0(a0)
1c008362:	00c51363          	bne	a0,a2,1c008368 <thread_enqueue>

1c008366 <enqueue_end>:
1c008366:	8482                	jr	s1

1c008368 <thread_enqueue>:
1c008368:	8482                	jr	s1

1c00836a <__rt_handle_special_event>:
1c00836a:	5571                	li	a0,-4
1c00836c:	8de9                	and	a1,a1,a0
1c00836e:	4190                	lw	a2,0(a1)
1c008370:	41c8                	lw	a0,4(a1)
1c008372:	a82d                	j	1c0083ac <__rt_call_external_c_function>

1c008374 <__rt_bridge_enqueue_event>:
1c008374:	fe812e23          	sw	s0,-4(sp)
1c008378:	fe912c23          	sw	s1,-8(sp)
1c00837c:	fea12a23          	sw	a0,-12(sp)
1c008380:	feb12823          	sw	a1,-16(sp)
1c008384:	fec12623          	sw	a2,-20(sp)
1c008388:	00002617          	auipc	a2,0x2
1c00838c:	ca660613          	addi	a2,a2,-858 # 1c00a02e <__rt_bridge_handle_notif>
1c008390:	01c004ef          	jal	s1,1c0083ac <__rt_call_external_c_function>
1c008394:	ffc12403          	lw	s0,-4(sp)
1c008398:	ff812483          	lw	s1,-8(sp)
1c00839c:	ff412503          	lw	a0,-12(sp)
1c0083a0:	ff012583          	lw	a1,-16(sp)
1c0083a4:	fec12603          	lw	a2,-20(sp)
1c0083a8:	30200073          	mret

1c0083ac <__rt_call_external_c_function>:
1c0083ac:	7119                	addi	sp,sp,-128
1c0083ae:	c006                	sw	ra,0(sp)
1c0083b0:	c20e                	sw	gp,4(sp)
1c0083b2:	c412                	sw	tp,8(sp)
1c0083b4:	c616                	sw	t0,12(sp)
1c0083b6:	c81a                	sw	t1,16(sp)
1c0083b8:	ca1e                	sw	t2,20(sp)
1c0083ba:	d236                	sw	a3,36(sp)
1c0083bc:	d43a                	sw	a4,40(sp)
1c0083be:	d63e                	sw	a5,44(sp)
1c0083c0:	d842                	sw	a6,48(sp)
1c0083c2:	da46                	sw	a7,52(sp)
1c0083c4:	dc72                	sw	t3,56(sp)
1c0083c6:	de76                	sw	t4,60(sp)
1c0083c8:	c0fa                	sw	t5,64(sp)
1c0083ca:	c6fe                	sw	t6,76(sp)
1c0083cc:	000600e7          	jalr	a2
1c0083d0:	4082                	lw	ra,0(sp)
1c0083d2:	4192                	lw	gp,4(sp)
1c0083d4:	4222                	lw	tp,8(sp)
1c0083d6:	42b2                	lw	t0,12(sp)
1c0083d8:	4342                	lw	t1,16(sp)
1c0083da:	43d2                	lw	t2,20(sp)
1c0083dc:	5692                	lw	a3,36(sp)
1c0083de:	5722                	lw	a4,40(sp)
1c0083e0:	57b2                	lw	a5,44(sp)
1c0083e2:	5842                	lw	a6,48(sp)
1c0083e4:	58d2                	lw	a7,52(sp)
1c0083e6:	5e62                	lw	t3,56(sp)
1c0083e8:	5ef2                	lw	t4,60(sp)
1c0083ea:	4f06                	lw	t5,64(sp)
1c0083ec:	4fb6                	lw	t6,76(sp)
1c0083ee:	6109                	addi	sp,sp,128
1c0083f0:	8482                	jr	s1

1c0083f2 <__udivdi3>:
1c0083f2:	87ae                	mv	a5,a1
1c0083f4:	8832                	mv	a6,a2
1c0083f6:	88b6                	mv	a7,a3
1c0083f8:	832a                	mv	t1,a0
1c0083fa:	20069663          	bnez	a3,1c008606 <__udivdi3+0x214>
1c0083fe:	1c000737          	lui	a4,0x1c000
1c008402:	2c470713          	addi	a4,a4,708 # 1c0002c4 <__DTOR_END__>
1c008406:	0ac5fe63          	bleu	a2,a1,1c0084c2 <__udivdi3+0xd0>
1c00840a:	66c1                	lui	a3,0x10
1c00840c:	0ad67463          	bleu	a3,a2,1c0084b4 <__udivdi3+0xc2>
1c008410:	0ff00693          	li	a3,255
1c008414:	00c6b6b3          	sltu	a3,a3,a2
1c008418:	068e                	slli	a3,a3,0x3
1c00841a:	00d658b3          	srl	a7,a2,a3
1c00841e:	9746                	add	a4,a4,a7
1c008420:	00074703          	lbu	a4,0(a4)
1c008424:	96ba                	add	a3,a3,a4
1c008426:	02000713          	li	a4,32
1c00842a:	8f15                	sub	a4,a4,a3
1c00842c:	cb19                	beqz	a4,1c008442 <__udivdi3+0x50>
1c00842e:	00e797b3          	sll	a5,a5,a4
1c008432:	00d556b3          	srl	a3,a0,a3
1c008436:	00e61833          	sll	a6,a2,a4
1c00843a:	00f6e5b3          	or	a1,a3,a5
1c00843e:	00e51333          	sll	t1,a0,a4
1c008442:	01085513          	srli	a0,a6,0x10
1c008446:	02a5d7b3          	divu	a5,a1,a0
1c00844a:	01081613          	slli	a2,a6,0x10
1c00844e:	8241                	srli	a2,a2,0x10
1c008450:	01035693          	srli	a3,t1,0x10
1c008454:	02a5f733          	remu	a4,a1,a0
1c008458:	02f605b3          	mul	a1,a2,a5
1c00845c:	0742                	slli	a4,a4,0x10
1c00845e:	8ed9                	or	a3,a3,a4
1c008460:	873e                	mv	a4,a5
1c008462:	00b6fc63          	bleu	a1,a3,1c00847a <__udivdi3+0x88>
1c008466:	96c2                	add	a3,a3,a6
1c008468:	fff78713          	addi	a4,a5,-1
1c00846c:	0106e763          	bltu	a3,a6,1c00847a <__udivdi3+0x88>
1c008470:	00b6f563          	bleu	a1,a3,1c00847a <__udivdi3+0x88>
1c008474:	ffe78713          	addi	a4,a5,-2
1c008478:	96c2                	add	a3,a3,a6
1c00847a:	8e8d                	sub	a3,a3,a1
1c00847c:	02a6f7b3          	remu	a5,a3,a0
1c008480:	0342                	slli	t1,t1,0x10
1c008482:	01035313          	srli	t1,t1,0x10
1c008486:	02a6d6b3          	divu	a3,a3,a0
1c00848a:	07c2                	slli	a5,a5,0x10
1c00848c:	0067e333          	or	t1,a5,t1
1c008490:	02d605b3          	mul	a1,a2,a3
1c008494:	8536                	mv	a0,a3
1c008496:	00b37b63          	bleu	a1,t1,1c0084ac <__udivdi3+0xba>
1c00849a:	9342                	add	t1,t1,a6
1c00849c:	fff68513          	addi	a0,a3,-1 # ffff <__l2_priv0_heap_size+0x8fe7>
1c0084a0:	01036663          	bltu	t1,a6,1c0084ac <__udivdi3+0xba>
1c0084a4:	00b37463          	bleu	a1,t1,1c0084ac <__udivdi3+0xba>
1c0084a8:	ffe68513          	addi	a0,a3,-2
1c0084ac:	0742                	slli	a4,a4,0x10
1c0084ae:	8f49                	or	a4,a4,a0
1c0084b0:	4581                	li	a1,0
1c0084b2:	a84d                	j	1c008564 <__udivdi3+0x172>
1c0084b4:	010008b7          	lui	a7,0x1000
1c0084b8:	46c1                	li	a3,16
1c0084ba:	f71660e3          	bltu	a2,a7,1c00841a <__udivdi3+0x28>
1c0084be:	46e1                	li	a3,24
1c0084c0:	bfa9                	j	1c00841a <__udivdi3+0x28>
1c0084c2:	e601                	bnez	a2,1c0084ca <__udivdi3+0xd8>
1c0084c4:	4685                	li	a3,1
1c0084c6:	02c6d833          	divu	a6,a3,a2
1c0084ca:	66c1                	lui	a3,0x10
1c0084cc:	08d87e63          	bleu	a3,a6,1c008568 <__udivdi3+0x176>
1c0084d0:	0ff00693          	li	a3,255
1c0084d4:	0106f363          	bleu	a6,a3,1c0084da <__udivdi3+0xe8>
1c0084d8:	48a1                	li	a7,8
1c0084da:	011856b3          	srl	a3,a6,a7
1c0084de:	9736                	add	a4,a4,a3
1c0084e0:	00074683          	lbu	a3,0(a4)
1c0084e4:	02000713          	li	a4,32
1c0084e8:	96c6                	add	a3,a3,a7
1c0084ea:	8f15                	sub	a4,a4,a3
1c0084ec:	e749                	bnez	a4,1c008576 <__udivdi3+0x184>
1c0084ee:	410787b3          	sub	a5,a5,a6
1c0084f2:	4585                	li	a1,1
1c0084f4:	01085613          	srli	a2,a6,0x10
1c0084f8:	01081893          	slli	a7,a6,0x10
1c0084fc:	0108d893          	srli	a7,a7,0x10
1c008500:	01035693          	srli	a3,t1,0x10
1c008504:	02c7f733          	remu	a4,a5,a2
1c008508:	02c7d7b3          	divu	a5,a5,a2
1c00850c:	0742                	slli	a4,a4,0x10
1c00850e:	8ed9                	or	a3,a3,a4
1c008510:	02f88533          	mul	a0,a7,a5
1c008514:	873e                	mv	a4,a5
1c008516:	00a6fc63          	bleu	a0,a3,1c00852e <__udivdi3+0x13c>
1c00851a:	96c2                	add	a3,a3,a6
1c00851c:	fff78713          	addi	a4,a5,-1
1c008520:	0106e763          	bltu	a3,a6,1c00852e <__udivdi3+0x13c>
1c008524:	00a6f563          	bleu	a0,a3,1c00852e <__udivdi3+0x13c>
1c008528:	ffe78713          	addi	a4,a5,-2
1c00852c:	96c2                	add	a3,a3,a6
1c00852e:	8e89                	sub	a3,a3,a0
1c008530:	02c6f7b3          	remu	a5,a3,a2
1c008534:	0342                	slli	t1,t1,0x10
1c008536:	01035313          	srli	t1,t1,0x10
1c00853a:	02c6d6b3          	divu	a3,a3,a2
1c00853e:	07c2                	slli	a5,a5,0x10
1c008540:	0067e333          	or	t1,a5,t1
1c008544:	02d888b3          	mul	a7,a7,a3
1c008548:	8536                	mv	a0,a3
1c00854a:	01137b63          	bleu	a7,t1,1c008560 <__udivdi3+0x16e>
1c00854e:	9342                	add	t1,t1,a6
1c008550:	fff68513          	addi	a0,a3,-1 # ffff <__l2_priv0_heap_size+0x8fe7>
1c008554:	01036663          	bltu	t1,a6,1c008560 <__udivdi3+0x16e>
1c008558:	01137463          	bleu	a7,t1,1c008560 <__udivdi3+0x16e>
1c00855c:	ffe68513          	addi	a0,a3,-2
1c008560:	0742                	slli	a4,a4,0x10
1c008562:	8f49                	or	a4,a4,a0
1c008564:	853a                	mv	a0,a4
1c008566:	8082                	ret
1c008568:	010006b7          	lui	a3,0x1000
1c00856c:	48c1                	li	a7,16
1c00856e:	f6d866e3          	bltu	a6,a3,1c0084da <__udivdi3+0xe8>
1c008572:	48e1                	li	a7,24
1c008574:	b79d                	j	1c0084da <__udivdi3+0xe8>
1c008576:	00e81833          	sll	a6,a6,a4
1c00857a:	00d7d5b3          	srl	a1,a5,a3
1c00857e:	00e51333          	sll	t1,a0,a4
1c008582:	00d556b3          	srl	a3,a0,a3
1c008586:	01085513          	srli	a0,a6,0x10
1c00858a:	00e797b3          	sll	a5,a5,a4
1c00858e:	02a5f733          	remu	a4,a1,a0
1c008592:	00f6e8b3          	or	a7,a3,a5
1c008596:	01081793          	slli	a5,a6,0x10
1c00859a:	83c1                	srli	a5,a5,0x10
1c00859c:	0108d613          	srli	a2,a7,0x10
1c0085a0:	02a5d5b3          	divu	a1,a1,a0
1c0085a4:	0742                	slli	a4,a4,0x10
1c0085a6:	8f51                	or	a4,a4,a2
1c0085a8:	02b786b3          	mul	a3,a5,a1
1c0085ac:	862e                	mv	a2,a1
1c0085ae:	00d77c63          	bleu	a3,a4,1c0085c6 <__udivdi3+0x1d4>
1c0085b2:	9742                	add	a4,a4,a6
1c0085b4:	fff58613          	addi	a2,a1,-1
1c0085b8:	01076763          	bltu	a4,a6,1c0085c6 <__udivdi3+0x1d4>
1c0085bc:	00d77563          	bleu	a3,a4,1c0085c6 <__udivdi3+0x1d4>
1c0085c0:	ffe58613          	addi	a2,a1,-2
1c0085c4:	9742                	add	a4,a4,a6
1c0085c6:	40d706b3          	sub	a3,a4,a3
1c0085ca:	02a6f733          	remu	a4,a3,a0
1c0085ce:	08c2                	slli	a7,a7,0x10
1c0085d0:	0108d893          	srli	a7,a7,0x10
1c0085d4:	02a6d6b3          	divu	a3,a3,a0
1c0085d8:	0742                	slli	a4,a4,0x10
1c0085da:	02d785b3          	mul	a1,a5,a3
1c0085de:	011767b3          	or	a5,a4,a7
1c0085e2:	8736                	mv	a4,a3
1c0085e4:	00b7fc63          	bleu	a1,a5,1c0085fc <__udivdi3+0x20a>
1c0085e8:	97c2                	add	a5,a5,a6
1c0085ea:	fff68713          	addi	a4,a3,-1 # ffffff <__rt_iodev_uart_baudrate+0xf67697>
1c0085ee:	0107e763          	bltu	a5,a6,1c0085fc <__udivdi3+0x20a>
1c0085f2:	00b7f563          	bleu	a1,a5,1c0085fc <__udivdi3+0x20a>
1c0085f6:	ffe68713          	addi	a4,a3,-2
1c0085fa:	97c2                	add	a5,a5,a6
1c0085fc:	8f8d                	sub	a5,a5,a1
1c0085fe:	01061593          	slli	a1,a2,0x10
1c008602:	8dd9                	or	a1,a1,a4
1c008604:	bdc5                	j	1c0084f4 <__udivdi3+0x102>
1c008606:	14d5e263          	bltu	a1,a3,1c00874a <__udivdi3+0x358>
1c00860a:	6741                	lui	a4,0x10
1c00860c:	02e6fe63          	bleu	a4,a3,1c008648 <__udivdi3+0x256>
1c008610:	0ff00813          	li	a6,255
1c008614:	00d83733          	sltu	a4,a6,a3
1c008618:	070e                	slli	a4,a4,0x3
1c00861a:	1c000837          	lui	a6,0x1c000
1c00861e:	2c480813          	addi	a6,a6,708 # 1c0002c4 <__DTOR_END__>
1c008622:	00e6d5b3          	srl	a1,a3,a4
1c008626:	95c2                	add	a1,a1,a6
1c008628:	0005c803          	lbu	a6,0(a1)
1c00862c:	02000593          	li	a1,32
1c008630:	983a                	add	a6,a6,a4
1c008632:	410585b3          	sub	a1,a1,a6
1c008636:	e185                	bnez	a1,1c008656 <__udivdi3+0x264>
1c008638:	4705                	li	a4,1
1c00863a:	f2f6e5e3          	bltu	a3,a5,1c008564 <__udivdi3+0x172>
1c00863e:	00c53533          	sltu	a0,a0,a2
1c008642:	00154713          	xori	a4,a0,1
1c008646:	bf39                	j	1c008564 <__udivdi3+0x172>
1c008648:	010005b7          	lui	a1,0x1000
1c00864c:	4741                	li	a4,16
1c00864e:	fcb6e6e3          	bltu	a3,a1,1c00861a <__udivdi3+0x228>
1c008652:	4761                	li	a4,24
1c008654:	b7d9                	j	1c00861a <__udivdi3+0x228>
1c008656:	01065733          	srl	a4,a2,a6
1c00865a:	00b696b3          	sll	a3,a3,a1
1c00865e:	8ed9                	or	a3,a3,a4
1c008660:	0106de93          	srli	t4,a3,0x10
1c008664:	0107d733          	srl	a4,a5,a6
1c008668:	03d778b3          	remu	a7,a4,t4
1c00866c:	00b797b3          	sll	a5,a5,a1
1c008670:	01055833          	srl	a6,a0,a6
1c008674:	00f86333          	or	t1,a6,a5
1c008678:	01069793          	slli	a5,a3,0x10
1c00867c:	83c1                	srli	a5,a5,0x10
1c00867e:	01035813          	srli	a6,t1,0x10
1c008682:	00b61633          	sll	a2,a2,a1
1c008686:	03d75733          	divu	a4,a4,t4
1c00868a:	08c2                	slli	a7,a7,0x10
1c00868c:	0108e833          	or	a6,a7,a6
1c008690:	02e78f33          	mul	t5,a5,a4
1c008694:	8e3a                	mv	t3,a4
1c008696:	01e87c63          	bleu	t5,a6,1c0086ae <__udivdi3+0x2bc>
1c00869a:	9836                	add	a6,a6,a3
1c00869c:	fff70e13          	addi	t3,a4,-1 # ffff <__l2_priv0_heap_size+0x8fe7>
1c0086a0:	00d86763          	bltu	a6,a3,1c0086ae <__udivdi3+0x2bc>
1c0086a4:	01e87563          	bleu	t5,a6,1c0086ae <__udivdi3+0x2bc>
1c0086a8:	ffe70e13          	addi	t3,a4,-2
1c0086ac:	9836                	add	a6,a6,a3
1c0086ae:	41e80833          	sub	a6,a6,t5
1c0086b2:	03d878b3          	remu	a7,a6,t4
1c0086b6:	03d85833          	divu	a6,a6,t4
1c0086ba:	08c2                	slli	a7,a7,0x10
1c0086bc:	03078eb3          	mul	t4,a5,a6
1c0086c0:	01031793          	slli	a5,t1,0x10
1c0086c4:	83c1                	srli	a5,a5,0x10
1c0086c6:	00f8e7b3          	or	a5,a7,a5
1c0086ca:	8742                	mv	a4,a6
1c0086cc:	01d7fc63          	bleu	t4,a5,1c0086e4 <__udivdi3+0x2f2>
1c0086d0:	97b6                	add	a5,a5,a3
1c0086d2:	fff80713          	addi	a4,a6,-1
1c0086d6:	00d7e763          	bltu	a5,a3,1c0086e4 <__udivdi3+0x2f2>
1c0086da:	01d7f563          	bleu	t4,a5,1c0086e4 <__udivdi3+0x2f2>
1c0086de:	ffe80713          	addi	a4,a6,-2
1c0086e2:	97b6                	add	a5,a5,a3
1c0086e4:	0e42                	slli	t3,t3,0x10
1c0086e6:	41d787b3          	sub	a5,a5,t4
1c0086ea:	6ec1                	lui	t4,0x10
1c0086ec:	00ee6733          	or	a4,t3,a4
1c0086f0:	fffe8813          	addi	a6,t4,-1 # ffff <__l2_priv0_heap_size+0x8fe7>
1c0086f4:	01077333          	and	t1,a4,a6
1c0086f8:	01075893          	srli	a7,a4,0x10
1c0086fc:	01067833          	and	a6,a2,a6
1c008700:	8241                	srli	a2,a2,0x10
1c008702:	03030e33          	mul	t3,t1,a6
1c008706:	03088833          	mul	a6,a7,a6
1c00870a:	010e5693          	srli	a3,t3,0x10
1c00870e:	02c30333          	mul	t1,t1,a2
1c008712:	9342                	add	t1,t1,a6
1c008714:	969a                	add	a3,a3,t1
1c008716:	02c888b3          	mul	a7,a7,a2
1c00871a:	0106f363          	bleu	a6,a3,1c008720 <__udivdi3+0x32e>
1c00871e:	98f6                	add	a7,a7,t4
1c008720:	0106d613          	srli	a2,a3,0x10
1c008724:	98b2                	add	a7,a7,a2
1c008726:	0317e063          	bltu	a5,a7,1c008746 <__udivdi3+0x354>
1c00872a:	d91793e3          	bne	a5,a7,1c0084b0 <__udivdi3+0xbe>
1c00872e:	67c1                	lui	a5,0x10
1c008730:	17fd                	addi	a5,a5,-1
1c008732:	8efd                	and	a3,a3,a5
1c008734:	06c2                	slli	a3,a3,0x10
1c008736:	00fe7e33          	and	t3,t3,a5
1c00873a:	00b51533          	sll	a0,a0,a1
1c00873e:	96f2                	add	a3,a3,t3
1c008740:	4581                	li	a1,0
1c008742:	e2d571e3          	bleu	a3,a0,1c008564 <__udivdi3+0x172>
1c008746:	177d                	addi	a4,a4,-1
1c008748:	b3a5                	j	1c0084b0 <__udivdi3+0xbe>
1c00874a:	4581                	li	a1,0
1c00874c:	4701                	li	a4,0
1c00874e:	bd19                	j	1c008564 <__udivdi3+0x172>

1c008750 <__umoddi3>:
1c008750:	88b2                	mv	a7,a2
1c008752:	8736                	mv	a4,a3
1c008754:	87aa                	mv	a5,a0
1c008756:	882e                	mv	a6,a1
1c008758:	1c069863          	bnez	a3,1c008928 <__umoddi3+0x1d8>
1c00875c:	1c0006b7          	lui	a3,0x1c000
1c008760:	2c468693          	addi	a3,a3,708 # 1c0002c4 <__DTOR_END__>
1c008764:	0ac5f863          	bleu	a2,a1,1c008814 <__umoddi3+0xc4>
1c008768:	6341                	lui	t1,0x10
1c00876a:	08667e63          	bleu	t1,a2,1c008806 <__umoddi3+0xb6>
1c00876e:	0ff00313          	li	t1,255
1c008772:	00c37363          	bleu	a2,t1,1c008778 <__umoddi3+0x28>
1c008776:	4721                	li	a4,8
1c008778:	00e65333          	srl	t1,a2,a4
1c00877c:	969a                	add	a3,a3,t1
1c00877e:	0006ce03          	lbu	t3,0(a3)
1c008782:	02000313          	li	t1,32
1c008786:	9e3a                	add	t3,t3,a4
1c008788:	41c30333          	sub	t1,t1,t3
1c00878c:	00030c63          	beqz	t1,1c0087a4 <__umoddi3+0x54>
1c008790:	006595b3          	sll	a1,a1,t1
1c008794:	01c55e33          	srl	t3,a0,t3
1c008798:	006618b3          	sll	a7,a2,t1
1c00879c:	00be6833          	or	a6,t3,a1
1c0087a0:	006517b3          	sll	a5,a0,t1
1c0087a4:	0108d613          	srli	a2,a7,0x10
1c0087a8:	02c87733          	remu	a4,a6,a2
1c0087ac:	01089513          	slli	a0,a7,0x10
1c0087b0:	8141                	srli	a0,a0,0x10
1c0087b2:	0107d693          	srli	a3,a5,0x10
1c0087b6:	02c85833          	divu	a6,a6,a2
1c0087ba:	0742                	slli	a4,a4,0x10
1c0087bc:	8ed9                	or	a3,a3,a4
1c0087be:	03050833          	mul	a6,a0,a6
1c0087c2:	0106f863          	bleu	a6,a3,1c0087d2 <__umoddi3+0x82>
1c0087c6:	96c6                	add	a3,a3,a7
1c0087c8:	0116e563          	bltu	a3,a7,1c0087d2 <__umoddi3+0x82>
1c0087cc:	0106f363          	bleu	a6,a3,1c0087d2 <__umoddi3+0x82>
1c0087d0:	96c6                	add	a3,a3,a7
1c0087d2:	410686b3          	sub	a3,a3,a6
1c0087d6:	02c6f733          	remu	a4,a3,a2
1c0087da:	07c2                	slli	a5,a5,0x10
1c0087dc:	83c1                	srli	a5,a5,0x10
1c0087de:	02c6d6b3          	divu	a3,a3,a2
1c0087e2:	02d506b3          	mul	a3,a0,a3
1c0087e6:	01071513          	slli	a0,a4,0x10
1c0087ea:	8fc9                	or	a5,a5,a0
1c0087ec:	00d7f863          	bleu	a3,a5,1c0087fc <__umoddi3+0xac>
1c0087f0:	97c6                	add	a5,a5,a7
1c0087f2:	0117e563          	bltu	a5,a7,1c0087fc <__umoddi3+0xac>
1c0087f6:	00d7f363          	bleu	a3,a5,1c0087fc <__umoddi3+0xac>
1c0087fa:	97c6                	add	a5,a5,a7
1c0087fc:	8f95                	sub	a5,a5,a3
1c0087fe:	0067d533          	srl	a0,a5,t1
1c008802:	4581                	li	a1,0
1c008804:	8082                	ret
1c008806:	01000337          	lui	t1,0x1000
1c00880a:	4741                	li	a4,16
1c00880c:	f66666e3          	bltu	a2,t1,1c008778 <__umoddi3+0x28>
1c008810:	4761                	li	a4,24
1c008812:	b79d                	j	1c008778 <__umoddi3+0x28>
1c008814:	e601                	bnez	a2,1c00881c <__umoddi3+0xcc>
1c008816:	4605                	li	a2,1
1c008818:	031658b3          	divu	a7,a2,a7
1c00881c:	6641                	lui	a2,0x10
1c00881e:	08c8f363          	bleu	a2,a7,1c0088a4 <__umoddi3+0x154>
1c008822:	0ff00613          	li	a2,255
1c008826:	01167363          	bleu	a7,a2,1c00882c <__umoddi3+0xdc>
1c00882a:	4721                	li	a4,8
1c00882c:	00e8d633          	srl	a2,a7,a4
1c008830:	96b2                	add	a3,a3,a2
1c008832:	0006ce03          	lbu	t3,0(a3)
1c008836:	02000313          	li	t1,32
1c00883a:	9e3a                	add	t3,t3,a4
1c00883c:	41c30333          	sub	t1,t1,t3
1c008840:	06031963          	bnez	t1,1c0088b2 <__umoddi3+0x162>
1c008844:	411585b3          	sub	a1,a1,a7
1c008848:	0108d713          	srli	a4,a7,0x10
1c00884c:	01089513          	slli	a0,a7,0x10
1c008850:	8141                	srli	a0,a0,0x10
1c008852:	0107d613          	srli	a2,a5,0x10
1c008856:	02e5f6b3          	remu	a3,a1,a4
1c00885a:	02e5d5b3          	divu	a1,a1,a4
1c00885e:	06c2                	slli	a3,a3,0x10
1c008860:	8ed1                	or	a3,a3,a2
1c008862:	02b505b3          	mul	a1,a0,a1
1c008866:	00b6f863          	bleu	a1,a3,1c008876 <__umoddi3+0x126>
1c00886a:	96c6                	add	a3,a3,a7
1c00886c:	0116e563          	bltu	a3,a7,1c008876 <__umoddi3+0x126>
1c008870:	00b6f363          	bleu	a1,a3,1c008876 <__umoddi3+0x126>
1c008874:	96c6                	add	a3,a3,a7
1c008876:	40b685b3          	sub	a1,a3,a1
1c00887a:	02e5f6b3          	remu	a3,a1,a4
1c00887e:	07c2                	slli	a5,a5,0x10
1c008880:	83c1                	srli	a5,a5,0x10
1c008882:	02e5d5b3          	divu	a1,a1,a4
1c008886:	02b505b3          	mul	a1,a0,a1
1c00888a:	01069513          	slli	a0,a3,0x10
1c00888e:	8fc9                	or	a5,a5,a0
1c008890:	00b7f863          	bleu	a1,a5,1c0088a0 <__umoddi3+0x150>
1c008894:	97c6                	add	a5,a5,a7
1c008896:	0117e563          	bltu	a5,a7,1c0088a0 <__umoddi3+0x150>
1c00889a:	00b7f363          	bleu	a1,a5,1c0088a0 <__umoddi3+0x150>
1c00889e:	97c6                	add	a5,a5,a7
1c0088a0:	8f8d                	sub	a5,a5,a1
1c0088a2:	bfb1                	j	1c0087fe <__umoddi3+0xae>
1c0088a4:	01000637          	lui	a2,0x1000
1c0088a8:	4741                	li	a4,16
1c0088aa:	f8c8e1e3          	bltu	a7,a2,1c00882c <__umoddi3+0xdc>
1c0088ae:	4761                	li	a4,24
1c0088b0:	bfb5                	j	1c00882c <__umoddi3+0xdc>
1c0088b2:	006898b3          	sll	a7,a7,t1
1c0088b6:	01c5d733          	srl	a4,a1,t3
1c0088ba:	006517b3          	sll	a5,a0,t1
1c0088be:	01c55e33          	srl	t3,a0,t3
1c0088c2:	0108d513          	srli	a0,a7,0x10
1c0088c6:	02a776b3          	remu	a3,a4,a0
1c0088ca:	006595b3          	sll	a1,a1,t1
1c0088ce:	00be6e33          	or	t3,t3,a1
1c0088d2:	01089593          	slli	a1,a7,0x10
1c0088d6:	81c1                	srli	a1,a1,0x10
1c0088d8:	010e5613          	srli	a2,t3,0x10
1c0088dc:	02a75733          	divu	a4,a4,a0
1c0088e0:	06c2                	slli	a3,a3,0x10
1c0088e2:	8ed1                	or	a3,a3,a2
1c0088e4:	02e58733          	mul	a4,a1,a4
1c0088e8:	00e6f863          	bleu	a4,a3,1c0088f8 <__umoddi3+0x1a8>
1c0088ec:	96c6                	add	a3,a3,a7
1c0088ee:	0116e563          	bltu	a3,a7,1c0088f8 <__umoddi3+0x1a8>
1c0088f2:	00e6f363          	bleu	a4,a3,1c0088f8 <__umoddi3+0x1a8>
1c0088f6:	96c6                	add	a3,a3,a7
1c0088f8:	40e68633          	sub	a2,a3,a4
1c0088fc:	02a676b3          	remu	a3,a2,a0
1c008900:	0e42                	slli	t3,t3,0x10
1c008902:	010e5e13          	srli	t3,t3,0x10
1c008906:	02a65633          	divu	a2,a2,a0
1c00890a:	06c2                	slli	a3,a3,0x10
1c00890c:	02c58633          	mul	a2,a1,a2
1c008910:	01c6e5b3          	or	a1,a3,t3
1c008914:	00c5f863          	bleu	a2,a1,1c008924 <__umoddi3+0x1d4>
1c008918:	95c6                	add	a1,a1,a7
1c00891a:	0115e563          	bltu	a1,a7,1c008924 <__umoddi3+0x1d4>
1c00891e:	00c5f363          	bleu	a2,a1,1c008924 <__umoddi3+0x1d4>
1c008922:	95c6                	add	a1,a1,a7
1c008924:	8d91                	sub	a1,a1,a2
1c008926:	b70d                	j	1c008848 <__umoddi3+0xf8>
1c008928:	ecd5eee3          	bltu	a1,a3,1c008804 <__umoddi3+0xb4>
1c00892c:	6741                	lui	a4,0x10
1c00892e:	04e6f563          	bleu	a4,a3,1c008978 <__umoddi3+0x228>
1c008932:	0ff00e93          	li	t4,255
1c008936:	00deb733          	sltu	a4,t4,a3
1c00893a:	070e                	slli	a4,a4,0x3
1c00893c:	1c000337          	lui	t1,0x1c000
1c008940:	00e6d8b3          	srl	a7,a3,a4
1c008944:	2c430313          	addi	t1,t1,708 # 1c0002c4 <__DTOR_END__>
1c008948:	989a                	add	a7,a7,t1
1c00894a:	0008ce83          	lbu	t4,0(a7) # 1000000 <__rt_iodev_uart_baudrate+0xf67698>
1c00894e:	02000e13          	li	t3,32
1c008952:	9eba                	add	t4,t4,a4
1c008954:	41de0e33          	sub	t3,t3,t4
1c008958:	020e1763          	bnez	t3,1c008986 <__umoddi3+0x236>
1c00895c:	00b6e463          	bltu	a3,a1,1c008964 <__umoddi3+0x214>
1c008960:	00c56963          	bltu	a0,a2,1c008972 <__umoddi3+0x222>
1c008964:	40c507b3          	sub	a5,a0,a2
1c008968:	8d95                	sub	a1,a1,a3
1c00896a:	00f53533          	sltu	a0,a0,a5
1c00896e:	40a58833          	sub	a6,a1,a0
1c008972:	853e                	mv	a0,a5
1c008974:	85c2                	mv	a1,a6
1c008976:	b579                	j	1c008804 <__umoddi3+0xb4>
1c008978:	010008b7          	lui	a7,0x1000
1c00897c:	4741                	li	a4,16
1c00897e:	fb16efe3          	bltu	a3,a7,1c00893c <__umoddi3+0x1ec>
1c008982:	4761                	li	a4,24
1c008984:	bf65                	j	1c00893c <__umoddi3+0x1ec>
1c008986:	01d65733          	srl	a4,a2,t4
1c00898a:	01c696b3          	sll	a3,a3,t3
1c00898e:	8ed9                	or	a3,a3,a4
1c008990:	01d557b3          	srl	a5,a0,t4
1c008994:	01d5d733          	srl	a4,a1,t4
1c008998:	01c595b3          	sll	a1,a1,t3
1c00899c:	8fcd                	or	a5,a5,a1
1c00899e:	0106d593          	srli	a1,a3,0x10
1c0089a2:	02b77333          	remu	t1,a4,a1
1c0089a6:	01069f13          	slli	t5,a3,0x10
1c0089aa:	010f5f13          	srli	t5,t5,0x10
1c0089ae:	0107d893          	srli	a7,a5,0x10
1c0089b2:	01c61633          	sll	a2,a2,t3
1c0089b6:	01c51533          	sll	a0,a0,t3
1c0089ba:	02b75733          	divu	a4,a4,a1
1c0089be:	0342                	slli	t1,t1,0x10
1c0089c0:	011368b3          	or	a7,t1,a7
1c0089c4:	02ef0833          	mul	a6,t5,a4
1c0089c8:	833a                	mv	t1,a4
1c0089ca:	0108fc63          	bleu	a6,a7,1c0089e2 <__umoddi3+0x292>
1c0089ce:	98b6                	add	a7,a7,a3
1c0089d0:	fff70313          	addi	t1,a4,-1 # ffff <__l2_priv0_heap_size+0x8fe7>
1c0089d4:	00d8e763          	bltu	a7,a3,1c0089e2 <__umoddi3+0x292>
1c0089d8:	0108f563          	bleu	a6,a7,1c0089e2 <__umoddi3+0x292>
1c0089dc:	ffe70313          	addi	t1,a4,-2
1c0089e0:	98b6                	add	a7,a7,a3
1c0089e2:	410888b3          	sub	a7,a7,a6
1c0089e6:	02b8ffb3          	remu	t6,a7,a1
1c0089ea:	02b8d8b3          	divu	a7,a7,a1
1c0089ee:	0fc2                	slli	t6,t6,0x10
1c0089f0:	031f05b3          	mul	a1,t5,a7
1c0089f4:	01079f13          	slli	t5,a5,0x10
1c0089f8:	010f5f13          	srli	t5,t5,0x10
1c0089fc:	01efef33          	or	t5,t6,t5
1c008a00:	8746                	mv	a4,a7
1c008a02:	00bf7c63          	bleu	a1,t5,1c008a1a <__umoddi3+0x2ca>
1c008a06:	9f36                	add	t5,t5,a3
1c008a08:	fff88713          	addi	a4,a7,-1 # ffffff <__rt_iodev_uart_baudrate+0xf67697>
1c008a0c:	00df6763          	bltu	t5,a3,1c008a1a <__umoddi3+0x2ca>
1c008a10:	00bf7563          	bleu	a1,t5,1c008a1a <__umoddi3+0x2ca>
1c008a14:	ffe88713          	addi	a4,a7,-2
1c008a18:	9f36                	add	t5,t5,a3
1c008a1a:	0342                	slli	t1,t1,0x10
1c008a1c:	68c1                	lui	a7,0x10
1c008a1e:	00e36333          	or	t1,t1,a4
1c008a22:	fff88793          	addi	a5,a7,-1 # ffff <__l2_priv0_heap_size+0x8fe7>
1c008a26:	01065813          	srli	a6,a2,0x10
1c008a2a:	40bf0f33          	sub	t5,t5,a1
1c008a2e:	00f375b3          	and	a1,t1,a5
1c008a32:	01035313          	srli	t1,t1,0x10
1c008a36:	8ff1                	and	a5,a5,a2
1c008a38:	02f58733          	mul	a4,a1,a5
1c008a3c:	02f307b3          	mul	a5,t1,a5
1c008a40:	030585b3          	mul	a1,a1,a6
1c008a44:	03030333          	mul	t1,t1,a6
1c008a48:	95be                	add	a1,a1,a5
1c008a4a:	01075813          	srli	a6,a4,0x10
1c008a4e:	982e                	add	a6,a6,a1
1c008a50:	00f87363          	bleu	a5,a6,1c008a56 <__umoddi3+0x306>
1c008a54:	9346                	add	t1,t1,a7
1c008a56:	67c1                	lui	a5,0x10
1c008a58:	17fd                	addi	a5,a5,-1
1c008a5a:	01085593          	srli	a1,a6,0x10
1c008a5e:	00f87833          	and	a6,a6,a5
1c008a62:	0842                	slli	a6,a6,0x10
1c008a64:	8f7d                	and	a4,a4,a5
1c008a66:	959a                	add	a1,a1,t1
1c008a68:	9742                	add	a4,a4,a6
1c008a6a:	00bf6663          	bltu	t5,a1,1c008a76 <__umoddi3+0x326>
1c008a6e:	00bf1b63          	bne	t5,a1,1c008a84 <__umoddi3+0x334>
1c008a72:	00e57963          	bleu	a4,a0,1c008a84 <__umoddi3+0x334>
1c008a76:	40c70633          	sub	a2,a4,a2
1c008a7a:	00c73733          	sltu	a4,a4,a2
1c008a7e:	8d95                	sub	a1,a1,a3
1c008a80:	8d99                	sub	a1,a1,a4
1c008a82:	8732                	mv	a4,a2
1c008a84:	40e50733          	sub	a4,a0,a4
1c008a88:	00e53533          	sltu	a0,a0,a4
1c008a8c:	40bf05b3          	sub	a1,t5,a1
1c008a90:	8d89                	sub	a1,a1,a0
1c008a92:	01d597b3          	sll	a5,a1,t4
1c008a96:	01c75733          	srl	a4,a4,t3
1c008a9a:	00e7e533          	or	a0,a5,a4
1c008a9e:	01c5d5b3          	srl	a1,a1,t3
1c008aa2:	b38d                	j	1c008804 <__umoddi3+0xb4>

1c008aa4 <main>:
#include "rt/rt_api.h"

#define WAIT_TIME 1200

int main()
{
1c008aa4:	1141                	addi	sp,sp,-16
1c008aa6:	c606                	sw	ra,12(sp)
1c008aa8:	c422                	sw	s0,8(sp)
1c008aaa:	c226                	sw	s1,4(sp)
  unsigned long long start_time, end_time;

  start_time = rt_time_get_us();
1c008aac:	7cd000ef          	jal	ra,1c009a78 <rt_time_get_us>
1c008ab0:	84aa                	mv	s1,a0

  // The time we specify here is in microseconds and is a minimum amount of time
  // where the core will sleep. Due to timer resolution, it may wait a bit more.
  rt_time_wait_us(WAIT_TIME);
1c008ab2:	4b000513          	li	a0,1200
1c008ab6:	05e010ef          	jal	ra,1c009b14 <rt_time_wait_us>

  end_time = rt_time_get_us();
1c008aba:	7bf000ef          	jal	ra,1c009a78 <rt_time_get_us>
1c008abe:	842a                	mv	s0,a0

  printf("Start time %lld\n", start_time);
1c008ac0:	1c000537          	lui	a0,0x1c000
1c008ac4:	8626                	mv	a2,s1
1c008ac6:	4681                	li	a3,0
1c008ac8:	3c450513          	addi	a0,a0,964 # 1c0003c4 <__DTOR_END__+0x100>
1c008acc:	2c01                	jal	1c008cdc <printf>
  printf("End time %lld\n", end_time);
1c008ace:	1c000537          	lui	a0,0x1c000
1c008ad2:	8622                	mv	a2,s0
1c008ad4:	4681                	li	a3,0
1c008ad6:	3d850513          	addi	a0,a0,984 # 1c0003d8 <__DTOR_END__+0x114>
1c008ada:	2409                	jal	1c008cdc <printf>

  return 0;
}
1c008adc:	40b2                	lw	ra,12(sp)
1c008ade:	4422                	lw	s0,8(sp)
1c008ae0:	4492                	lw	s1,4(sp)
1c008ae2:	4501                	li	a0,0
1c008ae4:	0141                	addi	sp,sp,16
1c008ae6:	8082                	ret

1c008ae8 <rt_is_fc>:
1c008ae8:	f1402573          	csrr	a0,mhartid
1c008aec:	8515                	srai	a0,a0,0x5
1c008aee:	f2653533          	p.bclr	a0,a0,25,6
1c008af2:	1505                	addi	a0,a0,-31
1c008af4:	00153513          	seqz	a0,a0
1c008af8:	8082                	ret

1c008afa <__rt_io_uart_wait_pending>:
1c008afa:	1141                	addi	sp,sp,-16
1c008afc:	c422                	sw	s0,8(sp)
1c008afe:	1c001437          	lui	s0,0x1c001
1c008b02:	fc840413          	addi	s0,s0,-56 # 1c000fc8 <__rt_padframe_profiles>
1c008b06:	c226                	sw	s1,4(sp)
1c008b08:	4004                	lw	s1,0(s0)
1c008b0a:	c606                	sw	ra,12(sp)
1c008b0c:	c881                	beqz	s1,1c008b1c <__rt_io_uart_wait_pending+0x22>
1c008b0e:	3fe9                	jal	1c008ae8 <rt_is_fc>
1c008b10:	c511                	beqz	a0,1c008b1c <__rt_io_uart_wait_pending+0x22>
1c008b12:	8526                	mv	a0,s1
1c008b14:	62f000ef          	jal	ra,1c009942 <rt_event_wait>
1c008b18:	00042023          	sw	zero,0(s0)
1c008b1c:	40b2                	lw	ra,12(sp)
1c008b1e:	4422                	lw	s0,8(sp)
1c008b20:	4492                	lw	s1,4(sp)
1c008b22:	0141                	addi	sp,sp,16
1c008b24:	8082                	ret

1c008b26 <__rt_io_lock>:
1c008b26:	1c0017b7          	lui	a5,0x1c001
1c008b2a:	e8c7a783          	lw	a5,-372(a5) # 1c000e8c <__hal_debug_struct+0x4>
1c008b2e:	c791                	beqz	a5,1c008b3a <__rt_io_lock+0x14>
1c008b30:	1c0017b7          	lui	a5,0x1c001
1c008b34:	fcc7a783          	lw	a5,-52(a5) # 1c000fcc <_rt_io_uart>
1c008b38:	c385                	beqz	a5,1c008b58 <__rt_io_lock+0x32>
1c008b3a:	1141                	addi	sp,sp,-16
1c008b3c:	c606                	sw	ra,12(sp)
1c008b3e:	376d                	jal	1c008ae8 <rt_is_fc>
1c008b40:	c909                	beqz	a0,1c008b52 <__rt_io_lock+0x2c>
1c008b42:	40b2                	lw	ra,12(sp)
1c008b44:	1c001537          	lui	a0,0x1c001
1c008b48:	d8050513          	addi	a0,a0,-640 # 1c000d80 <stack>
1c008b4c:	0141                	addi	sp,sp,16
1c008b4e:	30d0006f          	j	1c00965a <__rt_fc_lock>
1c008b52:	40b2                	lw	ra,12(sp)
1c008b54:	0141                	addi	sp,sp,16
1c008b56:	8082                	ret
1c008b58:	8082                	ret

1c008b5a <__rt_io_unlock>:
1c008b5a:	1c0017b7          	lui	a5,0x1c001
1c008b5e:	e8c7a783          	lw	a5,-372(a5) # 1c000e8c <__hal_debug_struct+0x4>
1c008b62:	c791                	beqz	a5,1c008b6e <__rt_io_unlock+0x14>
1c008b64:	1c0017b7          	lui	a5,0x1c001
1c008b68:	fcc7a783          	lw	a5,-52(a5) # 1c000fcc <_rt_io_uart>
1c008b6c:	c385                	beqz	a5,1c008b8c <__rt_io_unlock+0x32>
1c008b6e:	1141                	addi	sp,sp,-16
1c008b70:	c606                	sw	ra,12(sp)
1c008b72:	3f9d                	jal	1c008ae8 <rt_is_fc>
1c008b74:	c909                	beqz	a0,1c008b86 <__rt_io_unlock+0x2c>
1c008b76:	40b2                	lw	ra,12(sp)
1c008b78:	1c001537          	lui	a0,0x1c001
1c008b7c:	d8050513          	addi	a0,a0,-640 # 1c000d80 <stack>
1c008b80:	0141                	addi	sp,sp,16
1c008b82:	3110006f          	j	1c009692 <__rt_fc_unlock>
1c008b86:	40b2                	lw	ra,12(sp)
1c008b88:	0141                	addi	sp,sp,16
1c008b8a:	8082                	ret
1c008b8c:	8082                	ret

1c008b8e <__rt_io_stop>:
1c008b8e:	1141                	addi	sp,sp,-16
1c008b90:	c606                	sw	ra,12(sp)
1c008b92:	37a5                	jal	1c008afa <__rt_io_uart_wait_pending>
1c008b94:	1c0017b7          	lui	a5,0x1c001
1c008b98:	fcc7a503          	lw	a0,-52(a5) # 1c000fcc <_rt_io_uart>
1c008b9c:	4581                	li	a1,0
1c008b9e:	38a010ef          	jal	ra,1c009f28 <rt_uart_close>
1c008ba2:	40b2                	lw	ra,12(sp)
1c008ba4:	4501                	li	a0,0
1c008ba6:	0141                	addi	sp,sp,16
1c008ba8:	8082                	ret

1c008baa <__rt_io_start>:
1c008baa:	1101                	addi	sp,sp,-32
1c008bac:	0028                	addi	a0,sp,8
1c008bae:	ce06                	sw	ra,28(sp)
1c008bb0:	2c2010ef          	jal	ra,1c009e72 <rt_uart_conf_init>
1c008bb4:	000997b7          	lui	a5,0x99
1c008bb8:	96878793          	addi	a5,a5,-1688 # 98968 <__rt_iodev_uart_baudrate>
1c008bbc:	c43e                	sw	a5,8(sp)
1c008bbe:	00c02783          	lw	a5,12(zero) # c <__rt_thread_current>
1c008bc2:	1c001537          	lui	a0,0x1c001
1c008bc6:	f3850513          	addi	a0,a0,-200 # 1c000f38 <_edata>
1c008bca:	0c87a583          	lw	a1,200(a5)
1c008bce:	3df000ef          	jal	ra,1c0097ac <__rt_event_init>
1c008bd2:	002c                	addi	a1,sp,8
1c008bd4:	4681                	li	a3,0
1c008bd6:	4601                	li	a2,0
1c008bd8:	00000513          	li	a0,0
1c008bdc:	2a4010ef          	jal	ra,1c009e80 <__rt_uart_open>
1c008be0:	40f2                	lw	ra,28(sp)
1c008be2:	1c0017b7          	lui	a5,0x1c001
1c008be6:	fca7a623          	sw	a0,-52(a5) # 1c000fcc <_rt_io_uart>
1c008bea:	4501                	li	a0,0
1c008bec:	6105                	addi	sp,sp,32
1c008bee:	8082                	ret

1c008bf0 <__rt_io_uart_flush.constprop.2>:
1c008bf0:	1101                	addi	sp,sp,-32
1c008bf2:	cc22                	sw	s0,24(sp)
1c008bf4:	1c001437          	lui	s0,0x1c001
1c008bf8:	e8840793          	addi	a5,s0,-376 # 1c000e88 <__hal_debug_struct>
1c008bfc:	47d4                	lw	a3,12(a5)
1c008bfe:	ce06                	sw	ra,28(sp)
1c008c00:	c69d                	beqz	a3,1c008c2e <__rt_io_uart_flush.constprop.2+0x3e>
1c008c02:	c636                	sw	a3,12(sp)
1c008c04:	35d5                	jal	1c008ae8 <rt_is_fc>
1c008c06:	e8840413          	addi	s0,s0,-376
1c008c0a:	46b2                	lw	a3,12(sp)
1c008c0c:	cd19                	beqz	a0,1c008c2a <__rt_io_uart_flush.constprop.2+0x3a>
1c008c0e:	1c0017b7          	lui	a5,0x1c001
1c008c12:	fcc7a783          	lw	a5,-52(a5) # 1c000fcc <_rt_io_uart>
1c008c16:	4701                	li	a4,0
1c008c18:	01040613          	addi	a2,s0,16
1c008c1c:	43cc                	lw	a1,4(a5)
1c008c1e:	4501                	li	a0,0
1c008c20:	4781                	li	a5,0
1c008c22:	0586                	slli	a1,a1,0x1
1c008c24:	0585                	addi	a1,a1,1
1c008c26:	096010ef          	jal	ra,1c009cbc <rt_periph_copy>
1c008c2a:	00042623          	sw	zero,12(s0)
1c008c2e:	40f2                	lw	ra,28(sp)
1c008c30:	4462                	lw	s0,24(sp)
1c008c32:	6105                	addi	sp,sp,32
1c008c34:	8082                	ret

1c008c36 <__rt_putc_debug_bridge>:
1c008c36:	1c0017b7          	lui	a5,0x1c001
1c008c3a:	e8878793          	addi	a5,a5,-376 # 1c000e88 <__hal_debug_struct>
1c008c3e:	4798                	lw	a4,8(a5)
1c008c40:	ff7d                	bnez	a4,1c008c3e <__rt_putc_debug_bridge+0x8>
1c008c42:	47d8                	lw	a4,12(a5)
1c008c44:	00170693          	addi	a3,a4,1
1c008c48:	973e                	add	a4,a4,a5
1c008c4a:	00a70823          	sb	a0,16(a4)
1c008c4e:	c7d4                	sw	a3,12(a5)
1c008c50:	47d0                	lw	a2,12(a5)
1c008c52:	08000713          	li	a4,128
1c008c56:	00e60463          	beq	a2,a4,1c008c5e <__rt_putc_debug_bridge+0x28>
1c008c5a:	00a53663          	p.bneimm	a0,10,1c008c66 <__rt_putc_debug_bridge+0x30>
1c008c5e:	c681                	beqz	a3,1c008c66 <__rt_putc_debug_bridge+0x30>
1c008c60:	c794                	sw	a3,8(a5)
1c008c62:	0007a623          	sw	zero,12(a5)
1c008c66:	8082                	ret

1c008c68 <__rt_putc_uart>:
1c008c68:	1101                	addi	sp,sp,-32
1c008c6a:	c62a                	sw	a0,12(sp)
1c008c6c:	ce06                	sw	ra,28(sp)
1c008c6e:	3571                	jal	1c008afa <__rt_io_uart_wait_pending>
1c008c70:	1c0017b7          	lui	a5,0x1c001
1c008c74:	e8878793          	addi	a5,a5,-376 # 1c000e88 <__hal_debug_struct>
1c008c78:	47d4                	lw	a3,12(a5)
1c008c7a:	4532                	lw	a0,12(sp)
1c008c7c:	00168713          	addi	a4,a3,1
1c008c80:	c7d8                	sw	a4,12(a5)
1c008c82:	97b6                	add	a5,a5,a3
1c008c84:	00a78823          	sb	a0,16(a5)
1c008c88:	08000793          	li	a5,128
1c008c8c:	00f70463          	beq	a4,a5,1c008c94 <__rt_putc_uart+0x2c>
1c008c90:	00a53563          	p.bneimm	a0,10,1c008c9a <__rt_putc_uart+0x32>
1c008c94:	40f2                	lw	ra,28(sp)
1c008c96:	6105                	addi	sp,sp,32
1c008c98:	bfa1                	j	1c008bf0 <__rt_io_uart_flush.constprop.2>
1c008c9a:	40f2                	lw	ra,28(sp)
1c008c9c:	6105                	addi	sp,sp,32
1c008c9e:	8082                	ret

1c008ca0 <tfp_putc>:
1c008ca0:	1c0017b7          	lui	a5,0x1c001
1c008ca4:	e8c7a783          	lw	a5,-372(a5) # 1c000e8c <__hal_debug_struct+0x4>
1c008ca8:	852e                	mv	a0,a1
1c008caa:	cb85                	beqz	a5,1c008cda <tfp_putc+0x3a>
1c008cac:	1c0017b7          	lui	a5,0x1c001
1c008cb0:	fcc7a783          	lw	a5,-52(a5) # 1c000fcc <_rt_io_uart>
1c008cb4:	c391                	beqz	a5,1c008cb8 <tfp_putc+0x18>
1c008cb6:	bf4d                	j	1c008c68 <__rt_putc_uart>
1c008cb8:	6689                	lui	a3,0x2
1c008cba:	f14027f3          	csrr	a5,mhartid
1c008cbe:	f8068693          	addi	a3,a3,-128 # 1f80 <__rt_stack_size+0x1780>
1c008cc2:	00379713          	slli	a4,a5,0x3
1c008cc6:	078a                	slli	a5,a5,0x2
1c008cc8:	ee873733          	p.bclr	a4,a4,23,8
1c008ccc:	8ff5                	and	a5,a5,a3
1c008cce:	97ba                	add	a5,a5,a4
1c008cd0:	1a10f737          	lui	a4,0x1a10f
1c008cd4:	00b767a3          	p.sw	a1,a5(a4)
1c008cd8:	8082                	ret
1c008cda:	bfb1                	j	1c008c36 <__rt_putc_debug_bridge>

1c008cdc <printf>:
1c008cdc:	715d                	addi	sp,sp,-80
1c008cde:	d606                	sw	ra,44(sp)
1c008ce0:	c0ba                	sw	a4,64(sp)
1c008ce2:	c2be                	sw	a5,68(sp)
1c008ce4:	c4c2                	sw	a6,72(sp)
1c008ce6:	c6c6                	sw	a7,76(sp)
1c008ce8:	da2e                	sw	a1,52(sp)
1c008cea:	dc32                	sw	a2,56(sp)
1c008cec:	de36                	sw	a3,60(sp)
1c008cee:	c62a                	sw	a0,12(sp)
1c008cf0:	3d1d                	jal	1c008b26 <__rt_io_lock>
1c008cf2:	4532                	lw	a0,12(sp)
1c008cf4:	1c0095b7          	lui	a1,0x1c009
1c008cf8:	1854                	addi	a3,sp,52
1c008cfa:	862a                	mv	a2,a0
1c008cfc:	ca058593          	addi	a1,a1,-864 # 1c008ca0 <tfp_putc>
1c008d00:	4501                	li	a0,0
1c008d02:	ce36                	sw	a3,28(sp)
1c008d04:	26b1                	jal	1c009050 <tfp_format>
1c008d06:	3d91                	jal	1c008b5a <__rt_io_unlock>
1c008d08:	50b2                	lw	ra,44(sp)
1c008d0a:	4501                	li	a0,0
1c008d0c:	6161                	addi	sp,sp,80
1c008d0e:	8082                	ret

1c008d10 <exit>:
1c008d10:	1c0017b7          	lui	a5,0x1c001
1c008d14:	e8878793          	addi	a5,a5,-376 # 1c000e88 <__hal_debug_struct>
1c008d18:	4798                	lw	a4,8(a5)
1c008d1a:	ff7d                	bnez	a4,1c008d18 <exit+0x8>
1c008d1c:	c1f54533          	p.bset	a0,a0,0,31
1c008d20:	c388                	sw	a0,0(a5)
1c008d22:	1a1047b7          	lui	a5,0x1a104
1c008d26:	0aa7a023          	sw	a0,160(a5) # 1a1040a0 <__rt_iodev_uart_baudrate+0x1a06b738>
1c008d2a:	577d                	li	a4,-1
1c008d2c:	1a10a7b7          	lui	a5,0x1a10a
1c008d30:	80e7a423          	sw	a4,-2040(a5) # 1a109808 <__rt_iodev_uart_baudrate+0x1a070ea0>
1c008d34:	10500073          	wfi
1c008d38:	bff5                	j	1c008d34 <exit+0x24>

1c008d3a <abort>:
1c008d3a:	1141                	addi	sp,sp,-16
1c008d3c:	557d                	li	a0,-1
1c008d3e:	c606                	sw	ra,12(sp)
1c008d40:	3fc1                	jal	1c008d10 <exit>

1c008d42 <__rt_io_init>:
1c008d42:	1c0017b7          	lui	a5,0x1c001
1c008d46:	d8078793          	addi	a5,a5,-640 # 1c000d80 <stack>
1c008d4a:	0007a223          	sw	zero,4(a5)
1c008d4e:	0007a023          	sw	zero,0(a5)
1c008d52:	0007a623          	sw	zero,12(a5)
1c008d56:	1c0017b7          	lui	a5,0x1c001
1c008d5a:	fc07a623          	sw	zero,-52(a5) # 1c000fcc <_rt_io_uart>
1c008d5e:	1c0017b7          	lui	a5,0x1c001
1c008d62:	fc07a423          	sw	zero,-56(a5) # 1c000fc8 <__rt_padframe_profiles>
1c008d66:	00000793          	li	a5,0
1c008d6a:	0217b663          	p.bneimm	a5,1,1c008d96 <__rt_io_init+0x54>
1c008d6e:	1c0095b7          	lui	a1,0x1c009
1c008d72:	1141                	addi	sp,sp,-16
1c008d74:	4601                	li	a2,0
1c008d76:	baa58593          	addi	a1,a1,-1110 # 1c008baa <__rt_io_start>
1c008d7a:	4501                	li	a0,0
1c008d7c:	c606                	sw	ra,12(sp)
1c008d7e:	04d000ef          	jal	ra,1c0095ca <__rt_cbsys_add>
1c008d82:	40b2                	lw	ra,12(sp)
1c008d84:	1c0095b7          	lui	a1,0x1c009
1c008d88:	4601                	li	a2,0
1c008d8a:	b8e58593          	addi	a1,a1,-1138 # 1c008b8e <__rt_io_stop>
1c008d8e:	4505                	li	a0,1
1c008d90:	0141                	addi	sp,sp,16
1c008d92:	0390006f          	j	1c0095ca <__rt_cbsys_add>
1c008d96:	8082                	ret

1c008d98 <ulli2a>:
1c008d98:	7179                	addi	sp,sp,-48
1c008d9a:	d04a                	sw	s2,32(sp)
1c008d9c:	c85a                	sw	s6,16(sp)
1c008d9e:	01062903          	lw	s2,16(a2) # 1000010 <__rt_iodev_uart_baudrate+0xf676a8>
1c008da2:	00c62b03          	lw	s6,12(a2)
1c008da6:	d422                	sw	s0,40(sp)
1c008da8:	d226                	sw	s1,36(sp)
1c008daa:	ce4e                	sw	s3,28(sp)
1c008dac:	cc52                	sw	s4,24(sp)
1c008dae:	ca56                	sw	s5,20(sp)
1c008db0:	c65e                	sw	s7,12(sp)
1c008db2:	d606                	sw	ra,44(sp)
1c008db4:	c462                	sw	s8,8(sp)
1c008db6:	c266                	sw	s9,4(sp)
1c008db8:	c06a                	sw	s10,0(sp)
1c008dba:	8a2a                	mv	s4,a0
1c008dbc:	8aae                	mv	s5,a1
1c008dbe:	89b2                	mv	s3,a2
1c008dc0:	4b81                	li	s7,0
1c008dc2:	4485                	li	s1,1
1c008dc4:	4401                	li	s0,0
1c008dc6:	8626                	mv	a2,s1
1c008dc8:	86a2                	mv	a3,s0
1c008dca:	8552                	mv	a0,s4
1c008dcc:	85d6                	mv	a1,s5
1c008dce:	e24ff0ef          	jal	ra,1c0083f2 <__udivdi3>
1c008dd2:	02bb9963          	bne	s7,a1,1c008e04 <ulli2a+0x6c>
1c008dd6:	03657763          	bleu	s6,a0,1c008e04 <ulli2a+0x6c>
1c008dda:	4b01                	li	s6,0
1c008ddc:	4c25                	li	s8,9
1c008dde:	0084e7b3          	or	a5,s1,s0
1c008de2:	eb8d                	bnez	a5,1c008e14 <ulli2a+0x7c>
1c008de4:	00090023          	sb	zero,0(s2)
1c008de8:	50b2                	lw	ra,44(sp)
1c008dea:	5422                	lw	s0,40(sp)
1c008dec:	5492                	lw	s1,36(sp)
1c008dee:	5902                	lw	s2,32(sp)
1c008df0:	49f2                	lw	s3,28(sp)
1c008df2:	4a62                	lw	s4,24(sp)
1c008df4:	4ad2                	lw	s5,20(sp)
1c008df6:	4b42                	lw	s6,16(sp)
1c008df8:	4bb2                	lw	s7,12(sp)
1c008dfa:	4c22                	lw	s8,8(sp)
1c008dfc:	4c92                	lw	s9,4(sp)
1c008dfe:	4d02                	lw	s10,0(sp)
1c008e00:	6145                	addi	sp,sp,48
1c008e02:	8082                	ret
1c008e04:	036407b3          	mul	a5,s0,s6
1c008e08:	0364b433          	mulhu	s0,s1,s6
1c008e0c:	036484b3          	mul	s1,s1,s6
1c008e10:	943e                	add	s0,s0,a5
1c008e12:	bf55                	j	1c008dc6 <ulli2a+0x2e>
1c008e14:	8626                	mv	a2,s1
1c008e16:	86a2                	mv	a3,s0
1c008e18:	8552                	mv	a0,s4
1c008e1a:	85d6                	mv	a1,s5
1c008e1c:	dd6ff0ef          	jal	ra,1c0083f2 <__udivdi3>
1c008e20:	8626                	mv	a2,s1
1c008e22:	86a2                	mv	a3,s0
1c008e24:	85d6                	mv	a1,s5
1c008e26:	8baa                	mv	s7,a0
1c008e28:	8caa                	mv	s9,a0
1c008e2a:	8552                	mv	a0,s4
1c008e2c:	3215                	jal	1c008750 <__umoddi3>
1c008e2e:	00c9a603          	lw	a2,12(s3)
1c008e32:	8a2a                	mv	s4,a0
1c008e34:	8aae                	mv	s5,a1
1c008e36:	8526                	mv	a0,s1
1c008e38:	85a2                	mv	a1,s0
1c008e3a:	4681                	li	a3,0
1c008e3c:	db6ff0ef          	jal	ra,1c0083f2 <__udivdi3>
1c008e40:	84aa                	mv	s1,a0
1c008e42:	842e                	mv	s0,a1
1c008e44:	000b1963          	bnez	s6,1c008e56 <ulli2a+0xbe>
1c008e48:	01704763          	bgtz	s7,1c008e56 <ulli2a+0xbe>
1c008e4c:	8dc9                	or	a1,a1,a0
1c008e4e:	f9c1                	bnez	a1,1c008dde <ulli2a+0x46>
1c008e50:	03000513          	li	a0,48
1c008e54:	a829                	j	1c008e6e <ulli2a+0xd6>
1c008e56:	03000513          	li	a0,48
1c008e5a:	019c5a63          	ble	s9,s8,1c008e6e <ulli2a+0xd6>
1c008e5e:	0009c783          	lbu	a5,0(s3)
1c008e62:	03700513          	li	a0,55
1c008e66:	8b91                	andi	a5,a5,4
1c008e68:	e399                	bnez	a5,1c008e6e <ulli2a+0xd6>
1c008e6a:	05700513          	li	a0,87
1c008e6e:	955e                	add	a0,a0,s7
1c008e70:	00a90023          	sb	a0,0(s2)
1c008e74:	0b05                	addi	s6,s6,1
1c008e76:	0905                	addi	s2,s2,1
1c008e78:	b79d                	j	1c008dde <ulli2a+0x46>

1c008e7a <uli2a>:
1c008e7a:	4994                	lw	a3,16(a1)
1c008e7c:	45d8                	lw	a4,12(a1)
1c008e7e:	4785                	li	a5,1
1c008e80:	02f55633          	divu	a2,a0,a5
1c008e84:	00e67863          	bleu	a4,a2,1c008e94 <uli2a+0x1a>
1c008e88:	4601                	li	a2,0
1c008e8a:	4325                	li	t1,9
1c008e8c:	e799                	bnez	a5,1c008e9a <uli2a+0x20>
1c008e8e:	00068023          	sb	zero,0(a3)
1c008e92:	8082                	ret
1c008e94:	02e787b3          	mul	a5,a5,a4
1c008e98:	b7e5                	j	1c008e80 <uli2a+0x6>
1c008e9a:	45d8                	lw	a4,12(a1)
1c008e9c:	02f55833          	divu	a6,a0,a5
1c008ea0:	02f57533          	remu	a0,a0,a5
1c008ea4:	02e7d7b3          	divu	a5,a5,a4
1c008ea8:	e619                	bnez	a2,1c008eb6 <uli2a+0x3c>
1c008eaa:	01004663          	bgtz	a6,1c008eb6 <uli2a+0x3c>
1c008eae:	fff9                	bnez	a5,1c008e8c <uli2a+0x12>
1c008eb0:	03000713          	li	a4,48
1c008eb4:	a839                	j	1c008ed2 <uli2a+0x58>
1c008eb6:	03000713          	li	a4,48
1c008eba:	01035c63          	ble	a6,t1,1c008ed2 <uli2a+0x58>
1c008ebe:	0005c883          	lbu	a7,0(a1)
1c008ec2:	03700713          	li	a4,55
1c008ec6:	0048f893          	andi	a7,a7,4
1c008eca:	00089463          	bnez	a7,1c008ed2 <uli2a+0x58>
1c008ece:	05700713          	li	a4,87
1c008ed2:	9742                	add	a4,a4,a6
1c008ed4:	00e68023          	sb	a4,0(a3)
1c008ed8:	0605                	addi	a2,a2,1
1c008eda:	0685                	addi	a3,a3,1
1c008edc:	bf45                	j	1c008e8c <uli2a+0x12>

1c008ede <ui2a>:
1c008ede:	4994                	lw	a3,16(a1)
1c008ee0:	45d8                	lw	a4,12(a1)
1c008ee2:	4785                	li	a5,1
1c008ee4:	02f55633          	divu	a2,a0,a5
1c008ee8:	00e67863          	bleu	a4,a2,1c008ef8 <ui2a+0x1a>
1c008eec:	4601                	li	a2,0
1c008eee:	4325                	li	t1,9
1c008ef0:	e799                	bnez	a5,1c008efe <ui2a+0x20>
1c008ef2:	00068023          	sb	zero,0(a3)
1c008ef6:	8082                	ret
1c008ef8:	02e787b3          	mul	a5,a5,a4
1c008efc:	b7e5                	j	1c008ee4 <ui2a+0x6>
1c008efe:	45d8                	lw	a4,12(a1)
1c008f00:	02f55833          	divu	a6,a0,a5
1c008f04:	02f57533          	remu	a0,a0,a5
1c008f08:	02e7d7b3          	divu	a5,a5,a4
1c008f0c:	e619                	bnez	a2,1c008f1a <ui2a+0x3c>
1c008f0e:	01004663          	bgtz	a6,1c008f1a <ui2a+0x3c>
1c008f12:	fff9                	bnez	a5,1c008ef0 <ui2a+0x12>
1c008f14:	03000713          	li	a4,48
1c008f18:	a839                	j	1c008f36 <ui2a+0x58>
1c008f1a:	03000713          	li	a4,48
1c008f1e:	01035c63          	ble	a6,t1,1c008f36 <ui2a+0x58>
1c008f22:	0005c883          	lbu	a7,0(a1)
1c008f26:	03700713          	li	a4,55
1c008f2a:	0048f893          	andi	a7,a7,4
1c008f2e:	00089463          	bnez	a7,1c008f36 <ui2a+0x58>
1c008f32:	05700713          	li	a4,87
1c008f36:	9742                	add	a4,a4,a6
1c008f38:	00e68023          	sb	a4,0(a3)
1c008f3c:	0605                	addi	a2,a2,1
1c008f3e:	0685                	addi	a3,a3,1
1c008f40:	bf45                	j	1c008ef0 <ui2a+0x12>

1c008f42 <putchw>:
1c008f42:	1101                	addi	sp,sp,-32
1c008f44:	cc22                	sw	s0,24(sp)
1c008f46:	4a1c                	lw	a5,16(a2)
1c008f48:	4240                	lw	s0,4(a2)
1c008f4a:	ca26                	sw	s1,20(sp)
1c008f4c:	c84a                	sw	s2,16(sp)
1c008f4e:	c64e                	sw	s3,12(sp)
1c008f50:	ce06                	sw	ra,28(sp)
1c008f52:	c452                	sw	s4,8(sp)
1c008f54:	892a                	mv	s2,a0
1c008f56:	89ae                	mv	s3,a1
1c008f58:	84b2                	mv	s1,a2
1c008f5a:	0017c70b          	p.lbu	a4,1(a5!)
1c008f5e:	c319                	beqz	a4,1c008f64 <putchw+0x22>
1c008f60:	08804863          	bgtz	s0,1c008ff0 <putchw+0xae>
1c008f64:	0084c783          	lbu	a5,8(s1)
1c008f68:	c391                	beqz	a5,1c008f6c <putchw+0x2a>
1c008f6a:	147d                	addi	s0,s0,-1
1c008f6c:	0004c783          	lbu	a5,0(s1)
1c008f70:	0027f713          	andi	a4,a5,2
1c008f74:	c711                	beqz	a4,1c008f80 <putchw+0x3e>
1c008f76:	44d8                	lw	a4,12(s1)
1c008f78:	46c1                	li	a3,16
1c008f7a:	06d71d63          	bne	a4,a3,1c008ff4 <putchw+0xb2>
1c008f7e:	1479                	addi	s0,s0,-2
1c008f80:	8ba5                	andi	a5,a5,9
1c008f82:	8a22                	mv	s4,s0
1c008f84:	c3c9                	beqz	a5,1c009006 <putchw+0xc4>
1c008f86:	0084c583          	lbu	a1,8(s1)
1c008f8a:	c199                	beqz	a1,1c008f90 <putchw+0x4e>
1c008f8c:	854a                	mv	a0,s2
1c008f8e:	9982                	jalr	s3
1c008f90:	0004c783          	lbu	a5,0(s1)
1c008f94:	8b89                	andi	a5,a5,2
1c008f96:	c39d                	beqz	a5,1c008fbc <putchw+0x7a>
1c008f98:	44dc                	lw	a5,12(s1)
1c008f9a:	4741                	li	a4,16
1c008f9c:	06e79e63          	bne	a5,a4,1c009018 <putchw+0xd6>
1c008fa0:	03000593          	li	a1,48
1c008fa4:	854a                	mv	a0,s2
1c008fa6:	9982                	jalr	s3
1c008fa8:	0004c783          	lbu	a5,0(s1)
1c008fac:	05800593          	li	a1,88
1c008fb0:	8b91                	andi	a5,a5,4
1c008fb2:	e399                	bnez	a5,1c008fb8 <putchw+0x76>
1c008fb4:	07800593          	li	a1,120
1c008fb8:	854a                	mv	a0,s2
1c008fba:	9982                	jalr	s3
1c008fbc:	0004c783          	lbu	a5,0(s1)
1c008fc0:	8a22                	mv	s4,s0
1c008fc2:	fc17b7b3          	p.bclr	a5,a5,30,1
1c008fc6:	e3bd                	bnez	a5,1c00902c <putchw+0xea>
1c008fc8:	0104aa03          	lw	s4,16(s1)
1c008fcc:	001a458b          	p.lbu	a1,1(s4!)
1c008fd0:	e5bd                	bnez	a1,1c00903e <putchw+0xfc>
1c008fd2:	0004c783          	lbu	a5,0(s1)
1c008fd6:	8ba5                	andi	a5,a5,9
1c008fd8:	0087b463          	p.bneimm	a5,8,1c008fe0 <putchw+0x9e>
1c008fdc:	06804463          	bgtz	s0,1c009044 <putchw+0x102>
1c008fe0:	40f2                	lw	ra,28(sp)
1c008fe2:	4462                	lw	s0,24(sp)
1c008fe4:	44d2                	lw	s1,20(sp)
1c008fe6:	4942                	lw	s2,16(sp)
1c008fe8:	49b2                	lw	s3,12(sp)
1c008fea:	4a22                	lw	s4,8(sp)
1c008fec:	6105                	addi	sp,sp,32
1c008fee:	8082                	ret
1c008ff0:	147d                	addi	s0,s0,-1
1c008ff2:	b7a5                	j	1c008f5a <putchw+0x18>
1c008ff4:	f88736e3          	p.bneimm	a4,8,1c008f80 <putchw+0x3e>
1c008ff8:	147d                	addi	s0,s0,-1
1c008ffa:	b759                	j	1c008f80 <putchw+0x3e>
1c008ffc:	02000593          	li	a1,32
1c009000:	854a                	mv	a0,s2
1c009002:	9982                	jalr	s3
1c009004:	1a7d                	addi	s4,s4,-1
1c009006:	ff404be3          	bgtz	s4,1c008ffc <putchw+0xba>
1c00900a:	fff40793          	addi	a5,s0,-1
1c00900e:	04046433          	p.max	s0,s0,zero
1c009012:	40878433          	sub	s0,a5,s0
1c009016:	bf85                	j	1c008f86 <putchw+0x44>
1c009018:	fa87b2e3          	p.bneimm	a5,8,1c008fbc <putchw+0x7a>
1c00901c:	03000593          	li	a1,48
1c009020:	bf61                	j	1c008fb8 <putchw+0x76>
1c009022:	03000593          	li	a1,48
1c009026:	854a                	mv	a0,s2
1c009028:	9982                	jalr	s3
1c00902a:	1a7d                	addi	s4,s4,-1
1c00902c:	ff404be3          	bgtz	s4,1c009022 <putchw+0xe0>
1c009030:	fff40793          	addi	a5,s0,-1
1c009034:	04046433          	p.max	s0,s0,zero
1c009038:	40878433          	sub	s0,a5,s0
1c00903c:	b771                	j	1c008fc8 <putchw+0x86>
1c00903e:	854a                	mv	a0,s2
1c009040:	9982                	jalr	s3
1c009042:	b769                	j	1c008fcc <putchw+0x8a>
1c009044:	02000593          	li	a1,32
1c009048:	854a                	mv	a0,s2
1c00904a:	9982                	jalr	s3
1c00904c:	147d                	addi	s0,s0,-1
1c00904e:	b779                	j	1c008fdc <putchw+0x9a>

1c009050 <tfp_format>:
1c009050:	711d                	addi	sp,sp,-96
1c009052:	083c                	addi	a5,sp,24
1c009054:	cca2                	sw	s0,88(sp)
1c009056:	c8ca                	sw	s2,80(sp)
1c009058:	c6ce                	sw	s3,76(sp)
1c00905a:	c4d2                	sw	s4,72(sp)
1c00905c:	c2d6                	sw	s5,68(sp)
1c00905e:	c0da                	sw	s6,64(sp)
1c009060:	de5e                	sw	s7,60(sp)
1c009062:	ce86                	sw	ra,92(sp)
1c009064:	caa6                	sw	s1,84(sp)
1c009066:	dc62                	sw	s8,56(sp)
1c009068:	da66                	sw	s9,52(sp)
1c00906a:	892a                	mv	s2,a0
1c00906c:	89ae                	mv	s3,a1
1c00906e:	8436                	mv	s0,a3
1c009070:	ca3e                	sw	a5,20(sp)
1c009072:	02500a13          	li	s4,37
1c009076:	02d00b93          	li	s7,45
1c00907a:	4a85                	li	s5,1
1c00907c:	4b15                	li	s6,5
1c00907e:	00064583          	lbu	a1,0(a2)
1c009082:	00160493          	addi	s1,a2,1
1c009086:	ed91                	bnez	a1,1c0090a2 <tfp_format+0x52>
1c009088:	40f6                	lw	ra,92(sp)
1c00908a:	4466                	lw	s0,88(sp)
1c00908c:	44d6                	lw	s1,84(sp)
1c00908e:	4946                	lw	s2,80(sp)
1c009090:	49b6                	lw	s3,76(sp)
1c009092:	4a26                	lw	s4,72(sp)
1c009094:	4a96                	lw	s5,68(sp)
1c009096:	4b06                	lw	s6,64(sp)
1c009098:	5bf2                	lw	s7,60(sp)
1c00909a:	5c62                	lw	s8,56(sp)
1c00909c:	5cd2                	lw	s9,52(sp)
1c00909e:	6125                	addi	sp,sp,96
1c0090a0:	8082                	ret
1c0090a2:	01458563          	beq	a1,s4,1c0090ac <tfp_format+0x5c>
1c0090a6:	854a                	mv	a0,s2
1c0090a8:	9982                	jalr	s3
1c0090aa:	a2ad                	j	1c009214 <tfp_format+0x1c4>
1c0090ac:	00414783          	lbu	a5,4(sp)
1c0090b0:	c402                	sw	zero,8(sp)
1c0090b2:	00010623          	sb	zero,12(sp)
1c0090b6:	c00027b3          	p.insert	a5,zero,0,0
1c0090ba:	c01027b3          	p.insert	a5,zero,0,1
1c0090be:	c03027b3          	p.insert	a5,zero,0,3
1c0090c2:	00f10223          	sb	a5,4(sp)
1c0090c6:	4701                	li	a4,0
1c0090c8:	4601                	li	a2,0
1c0090ca:	4681                	li	a3,0
1c0090cc:	4501                	li	a0,0
1c0090ce:	4581                	li	a1,0
1c0090d0:	03000813          	li	a6,48
1c0090d4:	02300893          	li	a7,35
1c0090d8:	0004c783          	lbu	a5,0(s1)
1c0090dc:	00148c13          	addi	s8,s1,1
1c0090e0:	e3a9                	bnez	a5,1c009122 <tfp_format+0xd2>
1c0090e2:	c519                	beqz	a0,1c0090f0 <tfp_format+0xa0>
1c0090e4:	00414503          	lbu	a0,4(sp)
1c0090e8:	c035a533          	p.insert	a0,a1,0,3
1c0090ec:	00a10223          	sb	a0,4(sp)
1c0090f0:	c619                	beqz	a2,1c0090fe <tfp_format+0xae>
1c0090f2:	00414603          	lbu	a2,4(sp)
1c0090f6:	c006a633          	p.insert	a2,a3,0,0
1c0090fa:	00c10223          	sb	a2,4(sp)
1c0090fe:	c719                	beqz	a4,1c00910c <tfp_format+0xbc>
1c009100:	00414703          	lbu	a4,4(sp)
1c009104:	c01aa733          	p.insert	a4,s5,0,1
1c009108:	00e10223          	sb	a4,4(sp)
1c00910c:	fd078713          	addi	a4,a5,-48
1c009110:	0ff77713          	andi	a4,a4,255
1c009114:	46a5                	li	a3,9
1c009116:	04e6eb63          	bltu	a3,a4,1c00916c <tfp_format+0x11c>
1c00911a:	4681                	li	a3,0
1c00911c:	45a5                	li	a1,9
1c00911e:	4629                	li	a2,10
1c009120:	a02d                	j	1c00914a <tfp_format+0xfa>
1c009122:	01778c63          	beq	a5,s7,1c00913a <tfp_format+0xea>
1c009126:	01078663          	beq	a5,a6,1c009132 <tfp_format+0xe2>
1c00912a:	fb179ce3          	bne	a5,a7,1c0090e2 <tfp_format+0x92>
1c00912e:	4705                	li	a4,1
1c009130:	a019                	j	1c009136 <tfp_format+0xe6>
1c009132:	4605                	li	a2,1
1c009134:	4685                	li	a3,1
1c009136:	84e2                	mv	s1,s8
1c009138:	b745                	j	1c0090d8 <tfp_format+0x88>
1c00913a:	4505                	li	a0,1
1c00913c:	4585                	li	a1,1
1c00913e:	bfe5                	j	1c009136 <tfp_format+0xe6>
1c009140:	42c68733          	p.mac	a4,a3,a2
1c009144:	001c478b          	p.lbu	a5,1(s8!)
1c009148:	86ba                	mv	a3,a4
1c00914a:	fd078713          	addi	a4,a5,-48
1c00914e:	0ff77513          	andi	a0,a4,255
1c009152:	fea5f7e3          	bleu	a0,a1,1c009140 <tfp_format+0xf0>
1c009156:	f9f78713          	addi	a4,a5,-97
1c00915a:	0ff77713          	andi	a4,a4,255
1c00915e:	06eb6563          	bltu	s6,a4,1c0091c8 <tfp_format+0x178>
1c009162:	fa978713          	addi	a4,a5,-87
1c009166:	fce65de3          	ble	a4,a2,1c009140 <tfp_format+0xf0>
1c00916a:	c436                	sw	a3,8(sp)
1c00916c:	02e00713          	li	a4,46
1c009170:	02e79163          	bne	a5,a4,1c009192 <tfp_format+0x142>
1c009174:	00414783          	lbu	a5,4(sp)
1c009178:	46a5                	li	a3,9
1c00917a:	c00aa7b3          	p.insert	a5,s5,0,0
1c00917e:	00f10223          	sb	a5,4(sp)
1c009182:	001c478b          	p.lbu	a5,1(s8!)
1c009186:	fd078713          	addi	a4,a5,-48
1c00918a:	0ff77713          	andi	a4,a4,255
1c00918e:	fee6fae3          	bleu	a4,a3,1c009182 <tfp_format+0x132>
1c009192:	07a00713          	li	a4,122
1c009196:	04e79263          	bne	a5,a4,1c0091da <tfp_format+0x18a>
1c00919a:	000c4703          	lbu	a4,0(s8)
1c00919e:	001c0493          	addi	s1,s8,1
1c0091a2:	06900793          	li	a5,105
1c0091a6:	1ef70563          	beq	a4,a5,1c009390 <tfp_format+0x340>
1c0091aa:	1ee7e563          	bltu	a5,a4,1c009394 <tfp_format+0x344>
1c0091ae:	05800793          	li	a5,88
1c0091b2:	20f70763          	beq	a4,a5,1c0093c0 <tfp_format+0x370>
1c0091b6:	1ce7e563          	bltu	a5,a4,1c009380 <tfp_format+0x330>
1c0091ba:	ec0707e3          	beqz	a4,1c009088 <tfp_format+0x38>
1c0091be:	05471b63          	bne	a4,s4,1c009214 <tfp_format+0x1c4>
1c0091c2:	02500593          	li	a1,37
1c0091c6:	b5c5                	j	1c0090a6 <tfp_format+0x56>
1c0091c8:	fbf78713          	addi	a4,a5,-65
1c0091cc:	0ff77713          	andi	a4,a4,255
1c0091d0:	f8eb6de3          	bltu	s6,a4,1c00916a <tfp_format+0x11a>
1c0091d4:	fc978713          	addi	a4,a5,-55
1c0091d8:	b779                	j	1c009166 <tfp_format+0x116>
1c0091da:	06c00713          	li	a4,108
1c0091de:	20e79463          	bne	a5,a4,1c0093e6 <tfp_format+0x396>
1c0091e2:	84e2                	mv	s1,s8
1c0091e4:	0014c70b          	p.lbu	a4,1(s1!)
1c0091e8:	faf71de3          	bne	a4,a5,1c0091a2 <tfp_format+0x152>
1c0091ec:	001c4783          	lbu	a5,1(s8)
1c0091f0:	06900713          	li	a4,105
1c0091f4:	002c0493          	addi	s1,s8,2
1c0091f8:	02e78863          	beq	a5,a4,1c009228 <tfp_format+0x1d8>
1c0091fc:	06f76763          	bltu	a4,a5,1c00926a <tfp_format+0x21a>
1c009200:	05800713          	li	a4,88
1c009204:	0ae78d63          	beq	a5,a4,1c0092be <tfp_format+0x26e>
1c009208:	00f76863          	bltu	a4,a5,1c009218 <tfp_format+0x1c8>
1c00920c:	e6078ee3          	beqz	a5,1c009088 <tfp_format+0x38>
1c009210:	fb4789e3          	beq	a5,s4,1c0091c2 <tfp_format+0x172>
1c009214:	8626                	mv	a2,s1
1c009216:	b5a5                	j	1c00907e <tfp_format+0x2e>
1c009218:	06300713          	li	a4,99
1c00921c:	12e78f63          	beq	a5,a4,1c00935a <tfp_format+0x30a>
1c009220:	06400713          	li	a4,100
1c009224:	fee798e3          	bne	a5,a4,1c009214 <tfp_format+0x1c4>
1c009228:	4789                	li	a5,2
1c00922a:	4729                	li	a4,10
1c00922c:	c83a                	sw	a4,16(sp)
1c00922e:	0e27b363          	p.bneimm	a5,2,1c009314 <tfp_format+0x2c4>
1c009232:	041d                	addi	s0,s0,7
1c009234:	c4043433          	p.bclr	s0,s0,2,0
1c009238:	404c                	lw	a1,4(s0)
1c00923a:	00840c13          	addi	s8,s0,8
1c00923e:	4008                	lw	a0,0(s0)
1c009240:	0005dd63          	bgez	a1,1c00925a <tfp_format+0x20a>
1c009244:	40a00533          	neg	a0,a0
1c009248:	00a037b3          	snez	a5,a0
1c00924c:	40b005b3          	neg	a1,a1
1c009250:	8d9d                	sub	a1,a1,a5
1c009252:	02d00793          	li	a5,45
1c009256:	00f10623          	sb	a5,12(sp)
1c00925a:	0050                	addi	a2,sp,4
1c00925c:	3e35                	jal	1c008d98 <ulli2a>
1c00925e:	0050                	addi	a2,sp,4
1c009260:	85ce                	mv	a1,s3
1c009262:	854a                	mv	a0,s2
1c009264:	39f9                	jal	1c008f42 <putchw>
1c009266:	8462                	mv	s0,s8
1c009268:	b775                	j	1c009214 <tfp_format+0x1c4>
1c00926a:	07300713          	li	a4,115
1c00926e:	0ee78e63          	beq	a5,a4,1c00936a <tfp_format+0x31a>
1c009272:	02f76d63          	bltu	a4,a5,1c0092ac <tfp_format+0x25c>
1c009276:	06f00713          	li	a4,111
1c00927a:	0ce78963          	beq	a5,a4,1c00934c <tfp_format+0x2fc>
1c00927e:	07000713          	li	a4,112
1c009282:	f8f719e3          	bne	a4,a5,1c009214 <tfp_format+0x1c4>
1c009286:	00414783          	lbu	a5,4(sp)
1c00928a:	4741                	li	a4,16
1c00928c:	c83a                	sw	a4,16(sp)
1c00928e:	c01aa7b3          	p.insert	a5,s5,0,1
1c009292:	c02027b3          	p.insert	a5,zero,0,2
1c009296:	00f10223          	sb	a5,4(sp)
1c00929a:	8c26                	mv	s8,s1
1c00929c:	4008                	lw	a0,0(s0)
1c00929e:	00440c93          	addi	s9,s0,4
1c0092a2:	004c                	addi	a1,sp,4
1c0092a4:	392d                	jal	1c008ede <ui2a>
1c0092a6:	84e2                	mv	s1,s8
1c0092a8:	8466                	mv	s0,s9
1c0092aa:	a8b1                	j	1c009306 <tfp_format+0x2b6>
1c0092ac:	07500713          	li	a4,117
1c0092b0:	4689                	li	a3,2
1c0092b2:	02e78563          	beq	a5,a4,1c0092dc <tfp_format+0x28c>
1c0092b6:	07800713          	li	a4,120
1c0092ba:	f4e79de3          	bne	a5,a4,1c009214 <tfp_format+0x1c4>
1c0092be:	4741                	li	a4,16
1c0092c0:	c83a                	sw	a4,16(sp)
1c0092c2:	00414703          	lbu	a4,4(sp)
1c0092c6:	fa878793          	addi	a5,a5,-88
1c0092ca:	0017b793          	seqz	a5,a5
1c0092ce:	c027a733          	p.insert	a4,a5,0,2
1c0092d2:	00e10223          	sb	a4,4(sp)
1c0092d6:	a039                	j	1c0092e4 <tfp_format+0x294>
1c0092d8:	84e2                	mv	s1,s8
1c0092da:	4681                	li	a3,0
1c0092dc:	47a9                	li	a5,10
1c0092de:	c83e                	sw	a5,16(sp)
1c0092e0:	0026bd63          	p.bneimm	a3,2,1c0092fa <tfp_format+0x2aa>
1c0092e4:	00740693          	addi	a3,s0,7
1c0092e8:	c406b6b3          	p.bclr	a3,a3,2,0
1c0092ec:	4288                	lw	a0,0(a3)
1c0092ee:	42cc                	lw	a1,4(a3)
1c0092f0:	0050                	addi	a2,sp,4
1c0092f2:	00868413          	addi	s0,a3,8
1c0092f6:	344d                	jal	1c008d98 <ulli2a>
1c0092f8:	a039                	j	1c009306 <tfp_format+0x2b6>
1c0092fa:	0044250b          	p.lw	a0,4(s0!)
1c0092fe:	004c                	addi	a1,sp,4
1c009300:	0016b863          	p.bneimm	a3,1,1c009310 <tfp_format+0x2c0>
1c009304:	3e9d                	jal	1c008e7a <uli2a>
1c009306:	0050                	addi	a2,sp,4
1c009308:	85ce                	mv	a1,s3
1c00930a:	854a                	mv	a0,s2
1c00930c:	391d                	jal	1c008f42 <putchw>
1c00930e:	b719                	j	1c009214 <tfp_format+0x1c4>
1c009310:	36f9                	jal	1c008ede <ui2a>
1c009312:	bfd5                	j	1c009306 <tfp_format+0x2b6>
1c009314:	00440c13          	addi	s8,s0,4
1c009318:	4008                	lw	a0,0(s0)
1c00931a:	0017bd63          	p.bneimm	a5,1,1c009334 <tfp_format+0x2e4>
1c00931e:	00055863          	bgez	a0,1c00932e <tfp_format+0x2de>
1c009322:	02d00793          	li	a5,45
1c009326:	40a00533          	neg	a0,a0
1c00932a:	00f10623          	sb	a5,12(sp)
1c00932e:	004c                	addi	a1,sp,4
1c009330:	36a9                	jal	1c008e7a <uli2a>
1c009332:	b735                	j	1c00925e <tfp_format+0x20e>
1c009334:	00055863          	bgez	a0,1c009344 <tfp_format+0x2f4>
1c009338:	02d00793          	li	a5,45
1c00933c:	40a00533          	neg	a0,a0
1c009340:	00f10623          	sb	a5,12(sp)
1c009344:	004c                	addi	a1,sp,4
1c009346:	3e61                	jal	1c008ede <ui2a>
1c009348:	bf19                	j	1c00925e <tfp_format+0x20e>
1c00934a:	84e2                	mv	s1,s8
1c00934c:	47a1                	li	a5,8
1c00934e:	c83e                	sw	a5,16(sp)
1c009350:	00440c13          	addi	s8,s0,4
1c009354:	004c                	addi	a1,sp,4
1c009356:	4008                	lw	a0,0(s0)
1c009358:	b7fd                	j	1c009346 <tfp_format+0x2f6>
1c00935a:	00044583          	lbu	a1,0(s0)
1c00935e:	854a                	mv	a0,s2
1c009360:	00440c13          	addi	s8,s0,4
1c009364:	9982                	jalr	s3
1c009366:	b701                	j	1c009266 <tfp_format+0x216>
1c009368:	84e2                	mv	s1,s8
1c00936a:	401c                	lw	a5,0(s0)
1c00936c:	0050                	addi	a2,sp,4
1c00936e:	85ce                	mv	a1,s3
1c009370:	854a                	mv	a0,s2
1c009372:	ca3e                	sw	a5,20(sp)
1c009374:	36f9                	jal	1c008f42 <putchw>
1c009376:	083c                	addi	a5,sp,24
1c009378:	00440c13          	addi	s8,s0,4
1c00937c:	ca3e                	sw	a5,20(sp)
1c00937e:	b5e5                	j	1c009266 <tfp_format+0x216>
1c009380:	06300793          	li	a5,99
1c009384:	fcf70be3          	beq	a4,a5,1c00935a <tfp_format+0x30a>
1c009388:	06400793          	li	a5,100
1c00938c:	e8f714e3          	bne	a4,a5,1c009214 <tfp_format+0x1c4>
1c009390:	4785                	li	a5,1
1c009392:	bd61                	j	1c00922a <tfp_format+0x1da>
1c009394:	07300793          	li	a5,115
1c009398:	fcf709e3          	beq	a4,a5,1c00936a <tfp_format+0x31a>
1c00939c:	00e7e963          	bltu	a5,a4,1c0093ae <tfp_format+0x35e>
1c0093a0:	06f00793          	li	a5,111
1c0093a4:	faf704e3          	beq	a4,a5,1c00934c <tfp_format+0x2fc>
1c0093a8:	07000793          	li	a5,112
1c0093ac:	bdd9                	j	1c009282 <tfp_format+0x232>
1c0093ae:	07500793          	li	a5,117
1c0093b2:	4685                	li	a3,1
1c0093b4:	f2f704e3          	beq	a4,a5,1c0092dc <tfp_format+0x28c>
1c0093b8:	07800793          	li	a5,120
1c0093bc:	e4f71ce3          	bne	a4,a5,1c009214 <tfp_format+0x1c4>
1c0093c0:	47c1                	li	a5,16
1c0093c2:	c83e                	sw	a5,16(sp)
1c0093c4:	00414783          	lbu	a5,4(sp)
1c0093c8:	4008                	lw	a0,0(s0)
1c0093ca:	fa870713          	addi	a4,a4,-88 # 1a10efa8 <__rt_iodev_uart_baudrate+0x1a076640>
1c0093ce:	00173713          	seqz	a4,a4
1c0093d2:	c02727b3          	p.insert	a5,a4,0,2
1c0093d6:	00440c13          	addi	s8,s0,4
1c0093da:	004c                	addi	a1,sp,4
1c0093dc:	00f10223          	sb	a5,4(sp)
1c0093e0:	8462                	mv	s0,s8
1c0093e2:	3c61                	jal	1c008e7a <uli2a>
1c0093e4:	b70d                	j	1c009306 <tfp_format+0x2b6>
1c0093e6:	06900713          	li	a4,105
1c0093ea:	02e78a63          	beq	a5,a4,1c00941e <tfp_format+0x3ce>
1c0093ee:	02f76b63          	bltu	a4,a5,1c009424 <tfp_format+0x3d4>
1c0093f2:	05800713          	li	a4,88
1c0093f6:	04e78f63          	beq	a5,a4,1c009454 <tfp_format+0x404>
1c0093fa:	00f76963          	bltu	a4,a5,1c00940c <tfp_format+0x3bc>
1c0093fe:	c80785e3          	beqz	a5,1c009088 <tfp_format+0x38>
1c009402:	84e2                	mv	s1,s8
1c009404:	db478fe3          	beq	a5,s4,1c0091c2 <tfp_format+0x172>
1c009408:	84e2                	mv	s1,s8
1c00940a:	b529                	j	1c009214 <tfp_format+0x1c4>
1c00940c:	06300713          	li	a4,99
1c009410:	84e2                	mv	s1,s8
1c009412:	f4e784e3          	beq	a5,a4,1c00935a <tfp_format+0x30a>
1c009416:	06400713          	li	a4,100
1c00941a:	fee797e3          	bne	a5,a4,1c009408 <tfp_format+0x3b8>
1c00941e:	84e2                	mv	s1,s8
1c009420:	4781                	li	a5,0
1c009422:	b521                	j	1c00922a <tfp_format+0x1da>
1c009424:	07300713          	li	a4,115
1c009428:	f4e780e3          	beq	a5,a4,1c009368 <tfp_format+0x318>
1c00942c:	00f76c63          	bltu	a4,a5,1c009444 <tfp_format+0x3f4>
1c009430:	06f00713          	li	a4,111
1c009434:	f0e78be3          	beq	a5,a4,1c00934a <tfp_format+0x2fa>
1c009438:	07000713          	li	a4,112
1c00943c:	84e2                	mv	s1,s8
1c00943e:	e4e784e3          	beq	a5,a4,1c009286 <tfp_format+0x236>
1c009442:	b7d9                	j	1c009408 <tfp_format+0x3b8>
1c009444:	07500713          	li	a4,117
1c009448:	e8e788e3          	beq	a5,a4,1c0092d8 <tfp_format+0x288>
1c00944c:	07800713          	li	a4,120
1c009450:	fae79ce3          	bne	a5,a4,1c009408 <tfp_format+0x3b8>
1c009454:	4741                	li	a4,16
1c009456:	c83a                	sw	a4,16(sp)
1c009458:	00414703          	lbu	a4,4(sp)
1c00945c:	fa878793          	addi	a5,a5,-88
1c009460:	0017b793          	seqz	a5,a5
1c009464:	c027a733          	p.insert	a4,a5,0,2
1c009468:	00e10223          	sb	a4,4(sp)
1c00946c:	bd05                	j	1c00929c <tfp_format+0x24c>

1c00946e <__rt_init>:
1c00946e:	1141                	addi	sp,sp,-16
1c009470:	1a1067b7          	lui	a5,0x1a106
1c009474:	00478693          	addi	a3,a5,4 # 1a106004 <__rt_iodev_uart_baudrate+0x1a06d69c>
1c009478:	c606                	sw	ra,12(sp)
1c00947a:	577d                	li	a4,-1
1c00947c:	c422                	sw	s0,8(sp)
1c00947e:	c298                	sw	a4,0(a3)
1c009480:	07a1                	addi	a5,a5,8
1c009482:	c398                	sw	a4,0(a5)
1c009484:	1c000437          	lui	s0,0x1c000
1c009488:	2a29                	jal	1c0095a2 <__rt_irq_init>
1c00948a:	29840413          	addi	s0,s0,664 # 1c000298 <ctor_list+0x4>
1c00948e:	226d                	jal	1c009638 <__rt_utils_init>
1c009490:	2b8d                	jal	1c009a02 <__rt_allocs_init>
1c009492:	0044278b          	p.lw	a5,4(s0!)
1c009496:	e3b1                	bnez	a5,1c0094da <__rt_init+0x6c>
1c009498:	1c0085b7          	lui	a1,0x1c008
1c00949c:	2c658593          	addi	a1,a1,710 # 1c0082c6 <__rt_fc_socevents_handler>
1c0094a0:	4569                	li	a0,26
1c0094a2:	20a5                	jal	1c00950a <rt_irq_set_handler>
1c0094a4:	1a10a7b7          	lui	a5,0x1a10a
1c0094a8:	04000737          	lui	a4,0x4000
1c0094ac:	80e7a223          	sw	a4,-2044(a5) # 1a109804 <__rt_iodev_uart_baudrate+0x1a070e9c>
1c0094b0:	30045073          	csrwi	mstatus,8
1c0094b4:	4501                	li	a0,0
1c0094b6:	2a89                	jal	1c009608 <__rt_cbsys_exec>
1c0094b8:	c11d                	beqz	a0,1c0094de <__rt_init+0x70>
1c0094ba:	f1402673          	csrr	a2,mhartid
1c0094be:	1c000537          	lui	a0,0x1c000
1c0094c2:	40565593          	srai	a1,a2,0x5
1c0094c6:	f265b5b3          	p.bclr	a1,a1,25,6
1c0094ca:	f4563633          	p.bclr	a2,a2,26,5
1c0094ce:	3e850513          	addi	a0,a0,1000 # 1c0003e8 <__DTOR_END__+0x124>
1c0094d2:	80bff0ef          	jal	ra,1c008cdc <printf>
1c0094d6:	865ff0ef          	jal	ra,1c008d3a <abort>
1c0094da:	9782                	jalr	a5
1c0094dc:	bf5d                	j	1c009492 <__rt_init+0x24>
1c0094de:	40b2                	lw	ra,12(sp)
1c0094e0:	4422                	lw	s0,8(sp)
1c0094e2:	0141                	addi	sp,sp,16
1c0094e4:	8082                	ret

1c0094e6 <__rt_deinit>:
1c0094e6:	1141                	addi	sp,sp,-16
1c0094e8:	c422                	sw	s0,8(sp)
1c0094ea:	4505                	li	a0,1
1c0094ec:	1c000437          	lui	s0,0x1c000
1c0094f0:	c606                	sw	ra,12(sp)
1c0094f2:	2c040413          	addi	s0,s0,704 # 1c0002c0 <dtor_list+0x4>
1c0094f6:	2a09                	jal	1c009608 <__rt_cbsys_exec>
1c0094f8:	0044278b          	p.lw	a5,4(s0!)
1c0094fc:	e789                	bnez	a5,1c009506 <__rt_deinit+0x20>
1c0094fe:	40b2                	lw	ra,12(sp)
1c009500:	4422                	lw	s0,8(sp)
1c009502:	0141                	addi	sp,sp,16
1c009504:	8082                	ret
1c009506:	9782                	jalr	a5
1c009508:	bfc5                	j	1c0094f8 <__rt_deinit+0x12>

1c00950a <rt_irq_set_handler>:
1c00950a:	f14027f3          	csrr	a5,mhartid
1c00950e:	46fd                	li	a3,31
1c009510:	ca5797b3          	p.extractu	a5,a5,5,5
1c009514:	4701                	li	a4,0
1c009516:	00d79563          	bne	a5,a3,1c009520 <rt_irq_set_handler+0x16>
1c00951a:	1a1047b7          	lui	a5,0x1a104
1c00951e:	43d8                	lw	a4,4(a5)
1c009520:	050a                	slli	a0,a0,0x2
1c009522:	8d89                	sub	a1,a1,a0
1c009524:	8d99                	sub	a1,a1,a4
1c009526:	c14586b3          	p.extract	a3,a1,0,20
1c00952a:	06f00793          	li	a5,111
1c00952e:	c1f6a7b3          	p.insert	a5,a3,0,31
1c009532:	d21586b3          	p.extract	a3,a1,9,1
1c009536:	d356a7b3          	p.insert	a5,a3,9,21
1c00953a:	c0b586b3          	p.extract	a3,a1,0,11
1c00953e:	c146a7b3          	p.insert	a5,a3,0,20
1c009542:	cec585b3          	p.extract	a1,a1,7,12
1c009546:	cec5a7b3          	p.insert	a5,a1,7,12
1c00954a:	00f56723          	p.sw	a5,a4(a0)
1c00954e:	8082                	ret

1c009550 <illegal_insn_handler_c>:
1c009550:	8082                	ret

1c009552 <__rt_handle_illegal_instr>:
1c009552:	1c0017b7          	lui	a5,0x1c001
1c009556:	d947a703          	lw	a4,-620(a5) # 1c000d94 <__rt_debug_config>
1c00955a:	1141                	addi	sp,sp,-16
1c00955c:	c422                	sw	s0,8(sp)
1c00955e:	c606                	sw	ra,12(sp)
1c009560:	fc173733          	p.bclr	a4,a4,30,1
1c009564:	843e                	mv	s0,a5
1c009566:	c315                	beqz	a4,1c00958a <__rt_handle_illegal_instr+0x38>
1c009568:	341026f3          	csrr	a3,mepc
1c00956c:	f1402673          	csrr	a2,mhartid
1c009570:	1c000537          	lui	a0,0x1c000
1c009574:	4298                	lw	a4,0(a3)
1c009576:	40565593          	srai	a1,a2,0x5
1c00957a:	f265b5b3          	p.bclr	a1,a1,25,6
1c00957e:	f4563633          	p.bclr	a2,a2,26,5
1c009582:	44050513          	addi	a0,a0,1088 # 1c000440 <__DTOR_END__+0x17c>
1c009586:	f56ff0ef          	jal	ra,1c008cdc <printf>
1c00958a:	d9442783          	lw	a5,-620(s0)
1c00958e:	c01797b3          	p.extractu	a5,a5,0,1
1c009592:	c399                	beqz	a5,1c009598 <__rt_handle_illegal_instr+0x46>
1c009594:	fa6ff0ef          	jal	ra,1c008d3a <abort>
1c009598:	4422                	lw	s0,8(sp)
1c00959a:	40b2                	lw	ra,12(sp)
1c00959c:	0141                	addi	sp,sp,16
1c00959e:	fb3ff06f          	j	1c009550 <illegal_insn_handler_c>

1c0095a2 <__rt_irq_init>:
1c0095a2:	1a10a7b7          	lui	a5,0x1a10a
1c0095a6:	577d                	li	a4,-1
1c0095a8:	80e7a423          	sw	a4,-2040(a5) # 1a109808 <__rt_iodev_uart_baudrate+0x1a070ea0>
1c0095ac:	f14027f3          	csrr	a5,mhartid
1c0095b0:	477d                	li	a4,31
1c0095b2:	ca5797b3          	p.extractu	a5,a5,5,5
1c0095b6:	00e79963          	bne	a5,a4,1c0095c8 <__rt_irq_init+0x26>
1c0095ba:	1c0087b7          	lui	a5,0x1c008
1c0095be:	1a104737          	lui	a4,0x1a104
1c0095c2:	00078793          	mv	a5,a5
1c0095c6:	c35c                	sw	a5,4(a4)
1c0095c8:	8082                	ret

1c0095ca <__rt_cbsys_add>:
1c0095ca:	1101                	addi	sp,sp,-32
1c0095cc:	cc22                	sw	s0,24(sp)
1c0095ce:	ca26                	sw	s1,20(sp)
1c0095d0:	842a                	mv	s0,a0
1c0095d2:	84ae                	mv	s1,a1
1c0095d4:	4501                	li	a0,0
1c0095d6:	45b1                	li	a1,12
1c0095d8:	c632                	sw	a2,12(sp)
1c0095da:	ce06                	sw	ra,28(sp)
1c0095dc:	26dd                	jal	1c0099c2 <rt_alloc>
1c0095de:	4632                	lw	a2,12(sp)
1c0095e0:	c115                	beqz	a0,1c009604 <__rt_cbsys_add+0x3a>
1c0095e2:	1c0017b7          	lui	a5,0x1c001
1c0095e6:	040a                	slli	s0,s0,0x2
1c0095e8:	d9878793          	addi	a5,a5,-616 # 1c000d98 <cbsys_first>
1c0095ec:	97a2                	add	a5,a5,s0
1c0095ee:	4398                	lw	a4,0(a5)
1c0095f0:	c104                	sw	s1,0(a0)
1c0095f2:	c150                	sw	a2,4(a0)
1c0095f4:	c518                	sw	a4,8(a0)
1c0095f6:	c388                	sw	a0,0(a5)
1c0095f8:	4501                	li	a0,0
1c0095fa:	40f2                	lw	ra,28(sp)
1c0095fc:	4462                	lw	s0,24(sp)
1c0095fe:	44d2                	lw	s1,20(sp)
1c009600:	6105                	addi	sp,sp,32
1c009602:	8082                	ret
1c009604:	557d                	li	a0,-1
1c009606:	bfd5                	j	1c0095fa <__rt_cbsys_add+0x30>

1c009608 <__rt_cbsys_exec>:
1c009608:	1141                	addi	sp,sp,-16
1c00960a:	c422                	sw	s0,8(sp)
1c00960c:	1c001437          	lui	s0,0x1c001
1c009610:	050a                	slli	a0,a0,0x2
1c009612:	d9840413          	addi	s0,s0,-616 # 1c000d98 <cbsys_first>
1c009616:	20a47403          	p.lw	s0,a0(s0)
1c00961a:	c606                	sw	ra,12(sp)
1c00961c:	e411                	bnez	s0,1c009628 <__rt_cbsys_exec+0x20>
1c00961e:	4501                	li	a0,0
1c009620:	40b2                	lw	ra,12(sp)
1c009622:	4422                	lw	s0,8(sp)
1c009624:	0141                	addi	sp,sp,16
1c009626:	8082                	ret
1c009628:	401c                	lw	a5,0(s0)
1c00962a:	4048                	lw	a0,4(s0)
1c00962c:	9782                	jalr	a5
1c00962e:	e119                	bnez	a0,1c009634 <__rt_cbsys_exec+0x2c>
1c009630:	4400                	lw	s0,8(s0)
1c009632:	b7ed                	j	1c00961c <__rt_cbsys_exec+0x14>
1c009634:	557d                	li	a0,-1
1c009636:	b7ed                	j	1c009620 <__rt_cbsys_exec+0x18>

1c009638 <__rt_utils_init>:
1c009638:	1c0017b7          	lui	a5,0x1c001
1c00963c:	d9878793          	addi	a5,a5,-616 # 1c000d98 <cbsys_first>
1c009640:	0007a023          	sw	zero,0(a5)
1c009644:	0007a223          	sw	zero,4(a5)
1c009648:	0007a423          	sw	zero,8(a5)
1c00964c:	0007a623          	sw	zero,12(a5)
1c009650:	0007a823          	sw	zero,16(a5)
1c009654:	0007aa23          	sw	zero,20(a5)
1c009658:	8082                	ret

1c00965a <__rt_fc_lock>:
1c00965a:	1141                	addi	sp,sp,-16
1c00965c:	c422                	sw	s0,8(sp)
1c00965e:	842a                	mv	s0,a0
1c009660:	c606                	sw	ra,12(sp)
1c009662:	c226                	sw	s1,4(sp)
1c009664:	c04a                	sw	s2,0(sp)
1c009666:	300474f3          	csrrci	s1,mstatus,8
1c00966a:	401c                	lw	a5,0(s0)
1c00966c:	eb99                	bnez	a5,1c009682 <__rt_fc_lock+0x28>
1c00966e:	4785                	li	a5,1
1c009670:	c01c                	sw	a5,0(s0)
1c009672:	30049073          	csrw	mstatus,s1
1c009676:	40b2                	lw	ra,12(sp)
1c009678:	4422                	lw	s0,8(sp)
1c00967a:	4492                	lw	s1,4(sp)
1c00967c:	4902                	lw	s2,0(sp)
1c00967e:	0141                	addi	sp,sp,16
1c009680:	8082                	ret
1c009682:	00c02783          	lw	a5,12(zero) # c <__rt_thread_current>
1c009686:	4585                	li	a1,1
1c009688:	0c87a503          	lw	a0,200(a5)
1c00968c:	c45c                	sw	a5,12(s0)
1c00968e:	2419                	jal	1c009894 <__rt_event_execute>
1c009690:	bfe9                	j	1c00966a <__rt_fc_lock+0x10>

1c009692 <__rt_fc_unlock>:
1c009692:	300477f3          	csrrci	a5,mstatus,8
1c009696:	00052023          	sw	zero,0(a0)
1c00969a:	30079073          	csrw	mstatus,a5
1c00969e:	8082                	ret

1c0096a0 <__rt_thread_enqueue_ready>:
1c0096a0:	00402703          	lw	a4,4(zero) # 4 <_l1FcShared_end>
1c0096a4:	02052c23          	sw	zero,56(a0)
1c0096a8:	00400793          	li	a5,4
1c0096ac:	e711                	bnez	a4,1c0096b8 <__rt_thread_enqueue_ready+0x18>
1c0096ae:	c388                	sw	a0,0(a5)
1c0096b0:	c3c8                	sw	a0,4(a5)
1c0096b2:	0c052623          	sw	zero,204(a0)
1c0096b6:	8082                	ret
1c0096b8:	43d8                	lw	a4,4(a5)
1c0096ba:	df08                	sw	a0,56(a4)
1c0096bc:	bfd5                	j	1c0096b0 <__rt_thread_enqueue_ready+0x10>

1c0096be <__rt_thread_sleep>:
1c0096be:	00400713          	li	a4,4
1c0096c2:	4708                	lw	a0,8(a4)
1c0096c4:	00400793          	li	a5,4
1c0096c8:	438c                	lw	a1,0(a5)
1c0096ca:	c999                	beqz	a1,1c0096e0 <__rt_thread_sleep+0x22>
1c0096cc:	5d98                	lw	a4,56(a1)
1c0096ce:	c398                	sw	a4,0(a5)
1c0096d0:	4705                	li	a4,1
1c0096d2:	0ce5a623          	sw	a4,204(a1)
1c0096d6:	00b50c63          	beq	a0,a1,1c0096ee <__rt_thread_sleep+0x30>
1c0096da:	c78c                	sw	a1,8(a5)
1c0096dc:	a0bfe06f          	j	1c0080e6 <__rt_thread_switch>
1c0096e0:	10500073          	wfi
1c0096e4:	30045073          	csrwi	mstatus,8
1c0096e8:	30047773          	csrrci	a4,mstatus,8
1c0096ec:	bff1                	j	1c0096c8 <__rt_thread_sleep+0xa>
1c0096ee:	8082                	ret

1c0096f0 <rt_thread_exit>:
1c0096f0:	300477f3          	csrrci	a5,mstatus,8
1c0096f4:	00c02783          	lw	a5,12(zero) # c <__rt_thread_current>
1c0096f8:	4705                	li	a4,1
1c0096fa:	c3e8                	sw	a0,68(a5)
1c0096fc:	5fc8                	lw	a0,60(a5)
1c0096fe:	c3b8                	sw	a4,64(a5)
1c009700:	c909                	beqz	a0,1c009712 <rt_thread_exit+0x22>
1c009702:	0cc52783          	lw	a5,204(a0)
1c009706:	c791                	beqz	a5,1c009712 <rt_thread_exit+0x22>
1c009708:	1141                	addi	sp,sp,-16
1c00970a:	c606                	sw	ra,12(sp)
1c00970c:	3f51                	jal	1c0096a0 <__rt_thread_enqueue_ready>
1c00970e:	40b2                	lw	ra,12(sp)
1c009710:	0141                	addi	sp,sp,16
1c009712:	b775                	j	1c0096be <__rt_thread_sleep>

1c009714 <__rt_thread_sched_init>:
1c009714:	1141                	addi	sp,sp,-16
1c009716:	c422                	sw	s0,8(sp)
1c009718:	1c0087b7          	lui	a5,0x1c008
1c00971c:	1c001437          	lui	s0,0x1c001
1c009720:	c226                	sw	s1,4(sp)
1c009722:	c04a                	sw	s2,0(sp)
1c009724:	c606                	sw	ra,12(sp)
1c009726:	db040413          	addi	s0,s0,-592 # 1c000db0 <__rt_thread_main>
1c00972a:	0e078793          	addi	a5,a5,224 # 1c0080e0 <__rt_thread_start>
1c00972e:	c01c                	sw	a5,0(s0)
1c009730:	1c0097b7          	lui	a5,0x1c009
1c009734:	6f078793          	addi	a5,a5,1776 # 1c0096f0 <rt_thread_exit>
1c009738:	04840913          	addi	s2,s0,72
1c00973c:	c45c                	sw	a5,12(s0)
1c00973e:	e3ff7797          	auipc	a5,0xe3ff7
1c009742:	8d678793          	addi	a5,a5,-1834 # 14 <__rt_sched>
1c009746:	00400493          	li	s1,4
1c00974a:	0cf42423          	sw	a5,200(s0)
1c00974e:	854a                	mv	a0,s2
1c009750:	4785                	li	a5,1
1c009752:	e3ff7597          	auipc	a1,0xe3ff7
1c009756:	8c258593          	addi	a1,a1,-1854 # 14 <__rt_sched>
1c00975a:	0cf42623          	sw	a5,204(s0)
1c00975e:	0004a023          	sw	zero,0(s1)
1c009762:	02042a23          	sw	zero,52(s0)
1c009766:	00042223          	sw	zero,4(s0)
1c00976a:	00042423          	sw	zero,8(s0)
1c00976e:	283d                	jal	1c0097ac <__rt_event_init>
1c009770:	01002783          	lw	a5,16(zero) # 10 <__rt_first_free>
1c009774:	c480                	sw	s0,8(s1)
1c009776:	40b2                	lw	ra,12(sp)
1c009778:	c83c                	sw	a5,80(s0)
1c00977a:	4422                	lw	s0,8(sp)
1c00977c:	01202823          	sw	s2,16(zero) # 10 <__rt_first_free>
1c009780:	4492                	lw	s1,4(sp)
1c009782:	4902                	lw	s2,0(sp)
1c009784:	0141                	addi	sp,sp,16
1c009786:	8082                	ret

1c009788 <__rt_thread_enqueue_ready_check>:
1c009788:	0cc52783          	lw	a5,204(a0)
1c00978c:	cf81                	beqz	a5,1c0097a4 <__rt_thread_enqueue_ready_check+0x1c>
1c00978e:	00402703          	lw	a4,4(zero) # 4 <_l1FcShared_end>
1c009792:	02052c23          	sw	zero,56(a0)
1c009796:	00400793          	li	a5,4
1c00979a:	e711                	bnez	a4,1c0097a6 <__rt_thread_enqueue_ready_check+0x1e>
1c00979c:	c388                	sw	a0,0(a5)
1c00979e:	c3c8                	sw	a0,4(a5)
1c0097a0:	0c052623          	sw	zero,204(a0)
1c0097a4:	8082                	ret
1c0097a6:	43d8                	lw	a4,4(a5)
1c0097a8:	df08                	sw	a0,56(a4)
1c0097aa:	bfd5                	j	1c00979e <__rt_thread_enqueue_ready_check+0x16>

1c0097ac <__rt_event_init>:
1c0097ac:	00052823          	sw	zero,16(a0)
1c0097b0:	00052a23          	sw	zero,20(a0)
1c0097b4:	c54c                	sw	a1,12(a0)
1c0097b6:	00052023          	sw	zero,0(a0)
1c0097ba:	8082                	ret

1c0097bc <__rt_wait_event_prepare_blocking>:
1c0097bc:	01000793          	li	a5,16
1c0097c0:	4388                	lw	a0,0(a5)
1c0097c2:	4518                	lw	a4,8(a0)
1c0097c4:	00052823          	sw	zero,16(a0)
1c0097c8:	00e7a22b          	p.sw	a4,4(a5!)
1c0097cc:	4705                	li	a4,1
1c0097ce:	c958                	sw	a4,20(a0)
1c0097d0:	c55c                	sw	a5,12(a0)
1c0097d2:	00052023          	sw	zero,0(a0)
1c0097d6:	8082                	ret

1c0097d8 <rt_event_alloc>:
1c0097d8:	1141                	addi	sp,sp,-16
1c0097da:	c226                	sw	s1,4(sp)
1c0097dc:	84ae                	mv	s1,a1
1c0097de:	c606                	sw	ra,12(sp)
1c0097e0:	c422                	sw	s0,8(sp)
1c0097e2:	c04a                	sw	s2,0(sp)
1c0097e4:	30047973          	csrrci	s2,mstatus,8
1c0097e8:	842a                	mv	s0,a0
1c0097ea:	e509                	bnez	a0,1c0097f4 <rt_event_alloc+0x1c>
1c0097ec:	00c02783          	lw	a5,12(zero) # c <__rt_thread_current>
1c0097f0:	0c87a403          	lw	s0,200(a5)
1c0097f4:	f14027f3          	csrr	a5,mhartid
1c0097f8:	8795                	srai	a5,a5,0x5
1c0097fa:	f267b7b3          	p.bclr	a5,a5,25,6
1c0097fe:	477d                	li	a4,31
1c009800:	4501                	li	a0,0
1c009802:	00e78463          	beq	a5,a4,1c00980a <rt_event_alloc+0x32>
1c009806:	00378513          	addi	a0,a5,3
1c00980a:	00749593          	slli	a1,s1,0x7
1c00980e:	2a55                	jal	1c0099c2 <rt_alloc>
1c009810:	87aa                	mv	a5,a0
1c009812:	557d                	li	a0,-1
1c009814:	cf91                	beqz	a5,1c009830 <rt_event_alloc+0x58>
1c009816:	01002683          	lw	a3,16(zero) # 10 <__rt_first_free>
1c00981a:	4581                	li	a1,0
1c00981c:	4601                	li	a2,0
1c00981e:	01000713          	li	a4,16
1c009822:	00964d63          	blt	a2,s1,1c00983c <rt_event_alloc+0x64>
1c009826:	c191                	beqz	a1,1c00982a <rt_event_alloc+0x52>
1c009828:	c314                	sw	a3,0(a4)
1c00982a:	30091073          	csrw	mstatus,s2
1c00982e:	4501                	li	a0,0
1c009830:	40b2                	lw	ra,12(sp)
1c009832:	4422                	lw	s0,8(sp)
1c009834:	4492                	lw	s1,4(sp)
1c009836:	4902                	lw	s2,0(sp)
1c009838:	0141                	addi	sp,sp,16
1c00983a:	8082                	ret
1c00983c:	c794                	sw	a3,8(a5)
1c00983e:	0007a823          	sw	zero,16(a5)
1c009842:	0007aa23          	sw	zero,20(a5)
1c009846:	c7c0                	sw	s0,12(a5)
1c009848:	0007a023          	sw	zero,0(a5)
1c00984c:	86be                	mv	a3,a5
1c00984e:	0605                	addi	a2,a2,1
1c009850:	4585                	li	a1,1
1c009852:	08078793          	addi	a5,a5,128
1c009856:	b7f1                	j	1c009822 <rt_event_alloc+0x4a>

1c009858 <rt_event_get_blocking>:
1c009858:	300476f3          	csrrci	a3,mstatus,8
1c00985c:	e509                	bnez	a0,1c009866 <rt_event_get_blocking+0xe>
1c00985e:	00c02783          	lw	a5,12(zero) # c <__rt_thread_current>
1c009862:	0c87a503          	lw	a0,200(a5)
1c009866:	01000713          	li	a4,16
1c00986a:	431c                	lw	a5,0(a4)
1c00986c:	cb91                	beqz	a5,1c009880 <rt_event_get_blocking+0x28>
1c00986e:	4790                	lw	a2,8(a5)
1c009870:	0007a223          	sw	zero,4(a5)
1c009874:	c7c8                	sw	a0,12(a5)
1c009876:	c310                	sw	a2,0(a4)
1c009878:	4705                	li	a4,1
1c00987a:	0007a023          	sw	zero,0(a5)
1c00987e:	cbd8                	sw	a4,20(a5)
1c009880:	30069073          	csrw	mstatus,a3
1c009884:	853e                	mv	a0,a5
1c009886:	8082                	ret

1c009888 <__rt_event_unblock>:
1c009888:	00052a23          	sw	zero,20(a0)
1c00988c:	4908                	lw	a0,16(a0)
1c00988e:	c111                	beqz	a0,1c009892 <__rt_event_unblock+0xa>
1c009890:	bde5                	j	1c009788 <__rt_thread_enqueue_ready_check>
1c009892:	8082                	ret

1c009894 <__rt_event_execute>:
1c009894:	1101                	addi	sp,sp,-32
1c009896:	cc22                	sw	s0,24(sp)
1c009898:	ce06                	sw	ra,28(sp)
1c00989a:	ca26                	sw	s1,20(sp)
1c00989c:	c84a                	sw	s2,16(sp)
1c00989e:	c64e                	sw	s3,12(sp)
1c0098a0:	842a                	mv	s0,a0
1c0098a2:	e509                	bnez	a0,1c0098ac <__rt_event_execute+0x18>
1c0098a4:	00c02783          	lw	a5,12(zero) # c <__rt_thread_current>
1c0098a8:	0c87a403          	lw	s0,200(a5)
1c0098ac:	4008                	lw	a0,0(s0)
1c0098ae:	e919                	bnez	a0,1c0098c4 <__rt_event_execute+0x30>
1c0098b0:	c1a1                	beqz	a1,1c0098f0 <__rt_event_execute+0x5c>
1c0098b2:	00c02783          	lw	a5,12(zero) # c <__rt_thread_current>
1c0098b6:	c45c                	sw	a5,12(s0)
1c0098b8:	00402783          	lw	a5,4(zero) # 4 <_l1FcShared_end>
1c0098bc:	c3a9                	beqz	a5,1c0098fe <__rt_event_execute+0x6a>
1c0098be:	3501                	jal	1c0096be <__rt_thread_sleep>
1c0098c0:	4008                	lw	a0,0(s0)
1c0098c2:	c51d                	beqz	a0,1c0098f0 <__rt_event_execute+0x5c>
1c0098c4:	451c                	lw	a5,8(a0)
1c0098c6:	4104                	lw	s1,0(a0)
1c0098c8:	00452983          	lw	s3,4(a0)
1c0098cc:	c01c                	sw	a5,0(s0)
1c0098ce:	495c                	lw	a5,20(a0)
1c0098d0:	e791                	bnez	a5,1c0098dc <__rt_event_execute+0x48>
1c0098d2:	01000793          	li	a5,16
1c0098d6:	4398                	lw	a4,0(a5)
1c0098d8:	c388                	sw	a0,0(a5)
1c0098da:	c518                	sw	a4,8(a0)
1c0098dc:	3775                	jal	1c009888 <__rt_event_unblock>
1c0098de:	c499                	beqz	s1,1c0098ec <__rt_event_execute+0x58>
1c0098e0:	30045073          	csrwi	mstatus,8
1c0098e4:	854e                	mv	a0,s3
1c0098e6:	9482                	jalr	s1
1c0098e8:	300477f3          	csrrci	a5,mstatus,8
1c0098ec:	4008                	lw	a0,0(s0)
1c0098ee:	f979                	bnez	a0,1c0098c4 <__rt_event_execute+0x30>
1c0098f0:	40f2                	lw	ra,28(sp)
1c0098f2:	4462                	lw	s0,24(sp)
1c0098f4:	44d2                	lw	s1,20(sp)
1c0098f6:	4942                	lw	s2,16(sp)
1c0098f8:	49b2                	lw	s3,12(sp)
1c0098fa:	6105                	addi	sp,sp,32
1c0098fc:	8082                	ret
1c0098fe:	10500073          	wfi
1c009902:	30045073          	csrwi	mstatus,8
1c009906:	300477f3          	csrrci	a5,mstatus,8
1c00990a:	bf5d                	j	1c0098c0 <__rt_event_execute+0x2c>

1c00990c <__rt_wait_event>:
1c00990c:	1141                	addi	sp,sp,-16
1c00990e:	c422                	sw	s0,8(sp)
1c009910:	c226                	sw	s1,4(sp)
1c009912:	c606                	sw	ra,12(sp)
1c009914:	842a                	mv	s0,a0
1c009916:	485c                	lw	a5,20(s0)
1c009918:	ef89                	bnez	a5,1c009932 <__rt_wait_event+0x26>
1c00991a:	445c                	lw	a5,12(s0)
1c00991c:	c791                	beqz	a5,1c009928 <__rt_wait_event+0x1c>
1c00991e:	01000793          	li	a5,16
1c009922:	4398                	lw	a4,0(a5)
1c009924:	c380                	sw	s0,0(a5)
1c009926:	c418                	sw	a4,8(s0)
1c009928:	40b2                	lw	ra,12(sp)
1c00992a:	4422                	lw	s0,8(sp)
1c00992c:	4492                	lw	s1,4(sp)
1c00992e:	0141                	addi	sp,sp,16
1c009930:	8082                	ret
1c009932:	00c02783          	lw	a5,12(zero) # c <__rt_thread_current>
1c009936:	4585                	li	a1,1
1c009938:	0c87a503          	lw	a0,200(a5)
1c00993c:	c81c                	sw	a5,16(s0)
1c00993e:	3f99                	jal	1c009894 <__rt_event_execute>
1c009940:	bfd9                	j	1c009916 <__rt_wait_event+0xa>

1c009942 <rt_event_wait>:
1c009942:	1141                	addi	sp,sp,-16
1c009944:	c606                	sw	ra,12(sp)
1c009946:	c422                	sw	s0,8(sp)
1c009948:	30047473          	csrrci	s0,mstatus,8
1c00994c:	37c1                	jal	1c00990c <__rt_wait_event>
1c00994e:	30041073          	csrw	mstatus,s0
1c009952:	40b2                	lw	ra,12(sp)
1c009954:	4422                	lw	s0,8(sp)
1c009956:	0141                	addi	sp,sp,16
1c009958:	8082                	ret

1c00995a <__rt_event_sched_init>:
1c00995a:	01000513          	li	a0,16
1c00995e:	00052023          	sw	zero,0(a0)
1c009962:	00052223          	sw	zero,4(a0)
1c009966:	00052823          	sw	zero,16(a0)
1c00996a:	4585                	li	a1,1
1c00996c:	0511                	addi	a0,a0,4
1c00996e:	b5ad                	j	1c0097d8 <rt_event_alloc>

1c009970 <rt_user_alloc_init>:
1c009970:	00758793          	addi	a5,a1,7
1c009974:	c407b7b3          	p.bclr	a5,a5,2,0
1c009978:	40b785b3          	sub	a1,a5,a1
1c00997c:	c11c                	sw	a5,0(a0)
1c00997e:	8e0d                	sub	a2,a2,a1
1c009980:	00c05763          	blez	a2,1c00998e <rt_user_alloc_init+0x1e>
1c009984:	c4063633          	p.bclr	a2,a2,2,0
1c009988:	c390                	sw	a2,0(a5)
1c00998a:	0007a223          	sw	zero,4(a5)
1c00998e:	8082                	ret

1c009990 <rt_user_alloc>:
1c009990:	411c                	lw	a5,0(a0)
1c009992:	059d                	addi	a1,a1,7
1c009994:	c405b5b3          	p.bclr	a1,a1,2,0
1c009998:	4681                	li	a3,0
1c00999a:	cb89                	beqz	a5,1c0099ac <rt_user_alloc+0x1c>
1c00999c:	4398                	lw	a4,0(a5)
1c00999e:	00b74963          	blt	a4,a1,1c0099b0 <rt_user_alloc+0x20>
1c0099a2:	00b71c63          	bne	a4,a1,1c0099ba <rt_user_alloc+0x2a>
1c0099a6:	43d8                	lw	a4,4(a5)
1c0099a8:	c699                	beqz	a3,1c0099b6 <rt_user_alloc+0x26>
1c0099aa:	c2d8                	sw	a4,4(a3)
1c0099ac:	853e                	mv	a0,a5
1c0099ae:	8082                	ret
1c0099b0:	86be                	mv	a3,a5
1c0099b2:	43dc                	lw	a5,4(a5)
1c0099b4:	b7dd                	j	1c00999a <rt_user_alloc+0xa>
1c0099b6:	c118                	sw	a4,0(a0)
1c0099b8:	bfd5                	j	1c0099ac <rt_user_alloc+0x1c>
1c0099ba:	8f0d                	sub	a4,a4,a1
1c0099bc:	c398                	sw	a4,0(a5)
1c0099be:	97ba                	add	a5,a5,a4
1c0099c0:	b7f5                	j	1c0099ac <rt_user_alloc+0x1c>

1c0099c2 <rt_alloc>:
1c0099c2:	1101                	addi	sp,sp,-32
1c0099c4:	c84a                	sw	s2,16(sp)
1c0099c6:	1c001937          	lui	s2,0x1c001
1c0099ca:	cc22                	sw	s0,24(sp)
1c0099cc:	ca26                	sw	s1,20(sp)
1c0099ce:	c64e                	sw	s3,12(sp)
1c0099d0:	ce06                	sw	ra,28(sp)
1c0099d2:	842a                	mv	s0,a0
1c0099d4:	89ae                	mv	s3,a1
1c0099d6:	448d                	li	s1,3
1c0099d8:	fd890913          	addi	s2,s2,-40 # 1c000fd8 <__rt_alloc_l2>
1c0099dc:	00241513          	slli	a0,s0,0x2
1c0099e0:	85ce                	mv	a1,s3
1c0099e2:	954a                	add	a0,a0,s2
1c0099e4:	3775                	jal	1c009990 <rt_user_alloc>
1c0099e6:	e519                	bnez	a0,1c0099f4 <rt_alloc+0x32>
1c0099e8:	0405                	addi	s0,s0,1
1c0099ea:	00343363          	p.bneimm	s0,3,1c0099f0 <rt_alloc+0x2e>
1c0099ee:	4401                	li	s0,0
1c0099f0:	14fd                	addi	s1,s1,-1
1c0099f2:	f4ed                	bnez	s1,1c0099dc <rt_alloc+0x1a>
1c0099f4:	40f2                	lw	ra,28(sp)
1c0099f6:	4462                	lw	s0,24(sp)
1c0099f8:	44d2                	lw	s1,20(sp)
1c0099fa:	4942                	lw	s2,16(sp)
1c0099fc:	49b2                	lw	s3,12(sp)
1c0099fe:	6105                	addi	sp,sp,32
1c009a00:	8082                	ret

1c009a02 <__rt_allocs_init>:
1c009a02:	661d                	lui	a2,0x7
1c009a04:	1c0015b7          	lui	a1,0x1c001
1c009a08:	1c001537          	lui	a0,0x1c001
1c009a0c:	1141                	addi	sp,sp,-16
1c009a0e:	01860613          	addi	a2,a2,24 # 7018 <__l2_priv0_heap_size>
1c009a12:	fe858593          	addi	a1,a1,-24 # 1c000fe8 <__L2_priv0_end>
1c009a16:	fd850513          	addi	a0,a0,-40 # 1c000fd8 <__rt_alloc_l2>
1c009a1a:	c606                	sw	ra,12(sp)
1c009a1c:	3f91                	jal	1c009970 <rt_user_alloc_init>
1c009a1e:	6619                	lui	a2,0x6
1c009a20:	1c00a5b7          	lui	a1,0x1c00a
1c009a24:	1c001537          	lui	a0,0x1c001
1c009a28:	f8860613          	addi	a2,a2,-120 # 5f88 <__l2_priv1_heap_size>
1c009a2c:	07858593          	addi	a1,a1,120 # 1c00a078 <__cluster_text_end>
1c009a30:	fdc50513          	addi	a0,a0,-36 # 1c000fdc <__rt_alloc_l2+0x4>
1c009a34:	3f35                	jal	1c009970 <rt_user_alloc_init>
1c009a36:	40b2                	lw	ra,12(sp)
1c009a38:	00070637          	lui	a2,0x70
1c009a3c:	1c0105b7          	lui	a1,0x1c010
1c009a40:	1c001537          	lui	a0,0x1c001
1c009a44:	00060613          	mv	a2,a2
1c009a48:	00058593          	mv	a1,a1
1c009a4c:	fe050513          	addi	a0,a0,-32 # 1c000fe0 <__rt_alloc_l2+0x8>
1c009a50:	0141                	addi	sp,sp,16
1c009a52:	bf39                	j	1c009970 <rt_user_alloc_init>

1c009a54 <__rt_time_poweroff>:
1c009a54:	1a10b7b7          	lui	a5,0x1a10b
1c009a58:	47d8                	lw	a4,12(a5)
1c009a5a:	1c0017b7          	lui	a5,0x1c001
1c009a5e:	4501                	li	a0,0
1c009a60:	fce7a823          	sw	a4,-48(a5) # 1c000fd0 <timer_count>
1c009a64:	8082                	ret

1c009a66 <__rt_time_poweron>:
1c009a66:	1c0017b7          	lui	a5,0x1c001
1c009a6a:	fd07a703          	lw	a4,-48(a5) # 1c000fd0 <timer_count>
1c009a6e:	1a10b7b7          	lui	a5,0x1a10b
1c009a72:	4501                	li	a0,0
1c009a74:	c7d8                	sw	a4,12(a5)
1c009a76:	8082                	ret

1c009a78 <rt_time_get_us>:
1c009a78:	1a10b7b7          	lui	a5,0x1a10b
1c009a7c:	47c8                	lw	a0,12(a5)
1c009a7e:	000f47b7          	lui	a5,0xf4
1c009a82:	24078793          	addi	a5,a5,576 # f4240 <__rt_iodev_uart_baudrate+0x5b8d8>
1c009a86:	02f535b3          	mulhu	a1,a0,a5
1c009a8a:	000f4637          	lui	a2,0xf4
1c009a8e:	1141                	addi	sp,sp,-16
1c009a90:	24060613          	addi	a2,a2,576 # f4240 <__rt_iodev_uart_baudrate+0x5b8d8>
1c009a94:	4681                	li	a3,0
1c009a96:	c606                	sw	ra,12(sp)
1c009a98:	02f50533          	mul	a0,a0,a5
1c009a9c:	957fe0ef          	jal	ra,1c0083f2 <__udivdi3>
1c009aa0:	40b2                	lw	ra,12(sp)
1c009aa2:	0141                	addi	sp,sp,16
1c009aa4:	8082                	ret

1c009aa6 <rt_event_push_delayed>:
1c009aa6:	30047373          	csrrci	t1,mstatus,8
1c009aaa:	1a10b737          	lui	a4,0x1a10b
1c009aae:	4750                	lw	a2,12(a4)
1c009ab0:	1c0016b7          	lui	a3,0x1c001
1c009ab4:	0405e5b3          	p.max	a1,a1,zero
1c009ab8:	80000737          	lui	a4,0x80000
1c009abc:	0585                	addi	a1,a1,1
1c009abe:	fff74713          	not	a4,a4
1c009ac2:	fe46a783          	lw	a5,-28(a3) # 1c000fe4 <first_delayed>
1c009ac6:	00e67833          	and	a6,a2,a4
1c009aca:	962e                	add	a2,a2,a1
1c009acc:	d510                	sw	a2,40(a0)
1c009ace:	982e                	add	a6,a6,a1
1c009ad0:	4601                	li	a2,0
1c009ad2:	c799                	beqz	a5,1c009ae0 <rt_event_push_delayed+0x3a>
1c009ad4:	0287a883          	lw	a7,40(a5)
1c009ad8:	00e8f8b3          	and	a7,a7,a4
1c009adc:	0108e863          	bltu	a7,a6,1c009aec <rt_event_push_delayed+0x46>
1c009ae0:	ca09                	beqz	a2,1c009af2 <rt_event_push_delayed+0x4c>
1c009ae2:	c608                	sw	a0,8(a2)
1c009ae4:	c51c                	sw	a5,8(a0)
1c009ae6:	30031073          	csrw	mstatus,t1
1c009aea:	8082                	ret
1c009aec:	863e                	mv	a2,a5
1c009aee:	479c                	lw	a5,8(a5)
1c009af0:	b7cd                	j	1c009ad2 <rt_event_push_delayed+0x2c>
1c009af2:	c51c                	sw	a5,8(a0)
1c009af4:	1a10b7b7          	lui	a5,0x1a10b
1c009af8:	00c78713          	addi	a4,a5,12 # 1a10b00c <__rt_iodev_uart_baudrate+0x1a0726a4>
1c009afc:	4318                	lw	a4,0(a4)
1c009afe:	fea6a223          	sw	a0,-28(a3)
1c009b02:	95ba                	add	a1,a1,a4
1c009b04:	01478713          	addi	a4,a5,20
1c009b08:	c30c                	sw	a1,0(a4)
1c009b0a:	0791                	addi	a5,a5,4
1c009b0c:	08500713          	li	a4,133
1c009b10:	c398                	sw	a4,0(a5)
1c009b12:	bfd1                	j	1c009ae6 <rt_event_push_delayed+0x40>

1c009b14 <rt_time_wait_us>:
1c009b14:	1101                	addi	sp,sp,-32
1c009b16:	85aa                	mv	a1,a0
1c009b18:	4501                	li	a0,0
1c009b1a:	ce06                	sw	ra,28(sp)
1c009b1c:	cc22                	sw	s0,24(sp)
1c009b1e:	c62e                	sw	a1,12(sp)
1c009b20:	3b25                	jal	1c009858 <rt_event_get_blocking>
1c009b22:	45b2                	lw	a1,12(sp)
1c009b24:	842a                	mv	s0,a0
1c009b26:	3741                	jal	1c009aa6 <rt_event_push_delayed>
1c009b28:	8522                	mv	a0,s0
1c009b2a:	4462                	lw	s0,24(sp)
1c009b2c:	40f2                	lw	ra,28(sp)
1c009b2e:	6105                	addi	sp,sp,32
1c009b30:	bd09                	j	1c009942 <rt_event_wait>

1c009b32 <__rt_time_init>:
1c009b32:	1141                	addi	sp,sp,-16
1c009b34:	1c0017b7          	lui	a5,0x1c001
1c009b38:	c606                	sw	ra,12(sp)
1c009b3a:	c422                	sw	s0,8(sp)
1c009b3c:	fe07a223          	sw	zero,-28(a5) # 1c000fe4 <first_delayed>
1c009b40:	08300713          	li	a4,131
1c009b44:	1a10b7b7          	lui	a5,0x1a10b
1c009b48:	1c00a5b7          	lui	a1,0x1c00a
1c009b4c:	c3d8                	sw	a4,4(a5)
1c009b4e:	bb058593          	addi	a1,a1,-1104 # 1c009bb0 <__rt_timer_handler>
1c009b52:	452d                	li	a0,11
1c009b54:	9b7ff0ef          	jal	ra,1c00950a <rt_irq_set_handler>
1c009b58:	6785                	lui	a5,0x1
1c009b5a:	1a10a737          	lui	a4,0x1a10a
1c009b5e:	80078793          	addi	a5,a5,-2048 # 800 <__rt_stack_size>
1c009b62:	1c00a5b7          	lui	a1,0x1c00a
1c009b66:	80f72223          	sw	a5,-2044(a4) # 1a109804 <__rt_iodev_uart_baudrate+0x1a070e9c>
1c009b6a:	4601                	li	a2,0
1c009b6c:	a5458593          	addi	a1,a1,-1452 # 1c009a54 <__rt_time_poweroff>
1c009b70:	4509                	li	a0,2
1c009b72:	3ca1                	jal	1c0095ca <__rt_cbsys_add>
1c009b74:	1c00a5b7          	lui	a1,0x1c00a
1c009b78:	842a                	mv	s0,a0
1c009b7a:	4601                	li	a2,0
1c009b7c:	a6658593          	addi	a1,a1,-1434 # 1c009a66 <__rt_time_poweron>
1c009b80:	450d                	li	a0,3
1c009b82:	34a1                	jal	1c0095ca <__rt_cbsys_add>
1c009b84:	8d41                	or	a0,a0,s0
1c009b86:	c10d                	beqz	a0,1c009ba8 <__rt_time_init+0x76>
1c009b88:	f1402673          	csrr	a2,mhartid
1c009b8c:	1c000537          	lui	a0,0x1c000
1c009b90:	40565593          	srai	a1,a2,0x5
1c009b94:	f265b5b3          	p.bclr	a1,a1,25,6
1c009b98:	f4563633          	p.bclr	a2,a2,26,5
1c009b9c:	49c50513          	addi	a0,a0,1180 # 1c00049c <__DTOR_END__+0x1d8>
1c009ba0:	93cff0ef          	jal	ra,1c008cdc <printf>
1c009ba4:	996ff0ef          	jal	ra,1c008d3a <abort>
1c009ba8:	40b2                	lw	ra,12(sp)
1c009baa:	4422                	lw	s0,8(sp)
1c009bac:	0141                	addi	sp,sp,16
1c009bae:	8082                	ret

1c009bb0 <__rt_timer_handler>:
1c009bb0:	7179                	addi	sp,sp,-48
1c009bb2:	cc3a                	sw	a4,24(sp)
1c009bb4:	1a10b737          	lui	a4,0x1a10b
1c009bb8:	c472                	sw	t3,8(sp)
1c009bba:	00c72e03          	lw	t3,12(a4) # 1a10b00c <__rt_iodev_uart_baudrate+0x1a0726a4>
1c009bbe:	d032                	sw	a2,32(sp)
1c009bc0:	ce36                	sw	a3,28(sp)
1c009bc2:	1c001637          	lui	a2,0x1c001
1c009bc6:	00400693          	li	a3,4
1c009bca:	d42a                	sw	a0,40(sp)
1c009bcc:	d22e                	sw	a1,36(sp)
1c009bce:	ca3e                	sw	a5,20(sp)
1c009bd0:	4288                	lw	a0,0(a3)
1c009bd2:	fe462783          	lw	a5,-28(a2) # 1c000fe4 <first_delayed>
1c009bd6:	42cc                	lw	a1,4(a3)
1c009bd8:	d61a                	sw	t1,44(sp)
1c009bda:	80000337          	lui	t1,0x80000
1c009bde:	c842                	sw	a6,16(sp)
1c009be0:	c646                	sw	a7,12(sp)
1c009be2:	c276                	sw	t4,4(sp)
1c009be4:	c07a                	sw	t5,0(sp)
1c009be6:	4801                	li	a6,0
1c009be8:	4881                	li	a7,0
1c009bea:	00400713          	li	a4,4
1c009bee:	ffe34313          	xori	t1,t1,-2
1c009bf2:	ebc1                	bnez	a5,1c009c82 <__rt_timer_handler+0xd2>
1c009bf4:	00088363          	beqz	a7,1c009bfa <__rt_timer_handler+0x4a>
1c009bf8:	c308                	sw	a0,0(a4)
1c009bfa:	00080363          	beqz	a6,1c009c00 <__rt_timer_handler+0x50>
1c009bfe:	c34c                	sw	a1,4(a4)
1c009c00:	fe062223          	sw	zero,-28(a2)
1c009c04:	1a10b7b7          	lui	a5,0x1a10b
1c009c08:	08100713          	li	a4,129
1c009c0c:	c3d8                	sw	a4,4(a5)
1c009c0e:	6785                	lui	a5,0x1
1c009c10:	1a10a737          	lui	a4,0x1a10a
1c009c14:	80078793          	addi	a5,a5,-2048 # 800 <__rt_stack_size>
1c009c18:	80f72a23          	sw	a5,-2028(a4) # 1a109814 <__rt_iodev_uart_baudrate+0x1a070eac>
1c009c1c:	5332                	lw	t1,44(sp)
1c009c1e:	5522                	lw	a0,40(sp)
1c009c20:	5592                	lw	a1,36(sp)
1c009c22:	5602                	lw	a2,32(sp)
1c009c24:	46f2                	lw	a3,28(sp)
1c009c26:	4762                	lw	a4,24(sp)
1c009c28:	47d2                	lw	a5,20(sp)
1c009c2a:	4842                	lw	a6,16(sp)
1c009c2c:	48b2                	lw	a7,12(sp)
1c009c2e:	4e22                	lw	t3,8(sp)
1c009c30:	4e92                	lw	t4,4(sp)
1c009c32:	4f02                	lw	t5,0(sp)
1c009c34:	6145                	addi	sp,sp,48
1c009c36:	30200073          	mret
1c009c3a:	47d4                	lw	a3,12(a5)
1c009c3c:	0087ae83          	lw	t4,8(a5)
1c009c40:	0007a423          	sw	zero,8(a5)
1c009c44:	0006af03          	lw	t5,0(a3)
1c009c48:	020f1563          	bnez	t5,1c009c72 <__rt_timer_handler+0xc2>
1c009c4c:	c29c                	sw	a5,0(a3)
1c009c4e:	c2dc                	sw	a5,4(a3)
1c009c50:	46dc                	lw	a5,12(a3)
1c009c52:	cf91                	beqz	a5,1c009c6e <__rt_timer_handler+0xbe>
1c009c54:	0006a623          	sw	zero,12(a3)
1c009c58:	0cc7a683          	lw	a3,204(a5)
1c009c5c:	ca89                	beqz	a3,1c009c6e <__rt_timer_handler+0xbe>
1c009c5e:	0207ac23          	sw	zero,56(a5)
1c009c62:	cd09                	beqz	a0,1c009c7c <__rt_timer_handler+0xcc>
1c009c64:	dd9c                	sw	a5,56(a1)
1c009c66:	0c07a623          	sw	zero,204(a5)
1c009c6a:	85be                	mv	a1,a5
1c009c6c:	4805                	li	a6,1
1c009c6e:	87f6                	mv	a5,t4
1c009c70:	b749                	j	1c009bf2 <__rt_timer_handler+0x42>
1c009c72:	0046af03          	lw	t5,4(a3)
1c009c76:	00ff2423          	sw	a5,8(t5)
1c009c7a:	bfd1                	j	1c009c4e <__rt_timer_handler+0x9e>
1c009c7c:	853e                	mv	a0,a5
1c009c7e:	4885                	li	a7,1
1c009c80:	b7dd                	j	1c009c66 <__rt_timer_handler+0xb6>
1c009c82:	5794                	lw	a3,40(a5)
1c009c84:	40de0eb3          	sub	t4,t3,a3
1c009c88:	fbd379e3          	bleu	t4,t1,1c009c3a <__rt_timer_handler+0x8a>
1c009c8c:	00088363          	beqz	a7,1c009c92 <__rt_timer_handler+0xe2>
1c009c90:	c308                	sw	a0,0(a4)
1c009c92:	00080363          	beqz	a6,1c009c98 <__rt_timer_handler+0xe8>
1c009c96:	c34c                	sw	a1,4(a4)
1c009c98:	fef62223          	sw	a5,-28(a2)
1c009c9c:	1a10b7b7          	lui	a5,0x1a10b
1c009ca0:	00c78713          	addi	a4,a5,12 # 1a10b00c <__rt_iodev_uart_baudrate+0x1a0726a4>
1c009ca4:	4318                	lw	a4,0(a4)
1c009ca6:	41c70733          	sub	a4,a4,t3
1c009caa:	9736                	add	a4,a4,a3
1c009cac:	01478693          	addi	a3,a5,20
1c009cb0:	c298                	sw	a4,0(a3)
1c009cb2:	0791                	addi	a5,a5,4
1c009cb4:	08500713          	li	a4,133
1c009cb8:	c398                	sw	a4,0(a5)
1c009cba:	b78d                	j	1c009c1c <__rt_timer_handler+0x6c>

1c009cbc <rt_periph_copy>:
1c009cbc:	1101                	addi	sp,sp,-32
1c009cbe:	cc22                	sw	s0,24(sp)
1c009cc0:	ca26                	sw	s1,20(sp)
1c009cc2:	842a                	mv	s0,a0
1c009cc4:	84ae                	mv	s1,a1
1c009cc6:	ce06                	sw	ra,28(sp)
1c009cc8:	c84a                	sw	s2,16(sp)
1c009cca:	30047973          	csrrci	s2,mstatus,8
1c009cce:	853e                	mv	a0,a5
1c009cd0:	eb91                	bnez	a5,1c009ce4 <rt_periph_copy+0x28>
1c009cd2:	c632                	sw	a2,12(sp)
1c009cd4:	c436                	sw	a3,8(sp)
1c009cd6:	c23a                	sw	a4,4(sp)
1c009cd8:	c03e                	sw	a5,0(sp)
1c009cda:	34cd                	jal	1c0097bc <__rt_wait_event_prepare_blocking>
1c009cdc:	4782                	lw	a5,0(sp)
1c009cde:	4712                	lw	a4,4(sp)
1c009ce0:	46a2                	lw	a3,8(sp)
1c009ce2:	4632                	lw	a2,12(sp)
1c009ce4:	e419                	bnez	s0,1c009cf2 <rt_periph_copy+0x36>
1c009ce6:	02850413          	addi	s0,a0,40
1c009cea:	02052a23          	sw	zero,52(a0)
1c009cee:	04052223          	sw	zero,68(a0)
1c009cf2:	444c                	lw	a1,12(s0)
1c009cf4:	c054                	sw	a3,4(s0)
1c009cf6:	cc08                	sw	a0,24(s0)
1c009cf8:	f645b5b3          	p.bclr	a1,a1,27,4
1c009cfc:	4811                	li	a6,4
1c009cfe:	06b86063          	bltu	a6,a1,1c009d5e <rt_periph_copy+0xa2>
1c009d02:	02c00593          	li	a1,44
1c009d06:	00549313          	slli	t1,s1,0x5
1c009d0a:	959a                	add	a1,a1,t1
1c009d0c:	0005a803          	lw	a6,0(a1)
1c009d10:	00042a23          	sw	zero,20(s0)
1c009d14:	02c00893          	li	a7,44
1c009d18:	04081d63          	bnez	a6,1c009d72 <rt_periph_copy+0xb6>
1c009d1c:	c180                	sw	s0,0(a1)
1c009d1e:	006885b3          	add	a1,a7,t1
1c009d22:	0085ae03          	lw	t3,8(a1)
1c009d26:	c1c0                	sw	s0,4(a1)
1c009d28:	c0474733          	p.bset	a4,a4,0,4
1c009d2c:	040e1663          	bnez	t3,1c009d78 <rt_periph_copy+0xbc>
1c009d30:	4014d813          	srai	a6,s1,0x1
1c009d34:	1a1025b7          	lui	a1,0x1a102
1c009d38:	081e                	slli	a6,a6,0x7
1c009d3a:	982e                	add	a6,a6,a1
1c009d3c:	00449593          	slli	a1,s1,0x4
1c009d40:	89c1                	andi	a1,a1,16
1c009d42:	95c2                	add	a1,a1,a6
1c009d44:	00858e93          	addi	t4,a1,8 # 1a102008 <__rt_iodev_uart_baudrate+0x1a0696a0>
1c009d48:	000ea803          	lw	a6,0(t4)
1c009d4c:	02087813          	andi	a6,a6,32
1c009d50:	02081463          	bnez	a6,1c009d78 <rt_periph_copy+0xbc>
1c009d54:	00c5a22b          	p.sw	a2,4(a1!)
1c009d58:	c194                	sw	a3,0(a1)
1c009d5a:	00eea023          	sw	a4,0(t4)
1c009d5e:	e391                	bnez	a5,1c009d62 <rt_periph_copy+0xa6>
1c009d60:	3675                	jal	1c00990c <__rt_wait_event>
1c009d62:	30091073          	csrw	mstatus,s2
1c009d66:	40f2                	lw	ra,28(sp)
1c009d68:	4462                	lw	s0,24(sp)
1c009d6a:	44d2                	lw	s1,20(sp)
1c009d6c:	4942                	lw	s2,16(sp)
1c009d6e:	6105                	addi	sp,sp,32
1c009d70:	8082                	ret
1c009d72:	41cc                	lw	a1,4(a1)
1c009d74:	c9c0                	sw	s0,20(a1)
1c009d76:	b765                	j	1c009d1e <rt_periph_copy+0x62>
1c009d78:	00042823          	sw	zero,16(s0)
1c009d7c:	c010                	sw	a2,0(s0)
1c009d7e:	c054                	sw	a3,4(s0)
1c009d80:	c418                	sw	a4,8(s0)
1c009d82:	fc0e1ee3          	bnez	t3,1c009d5e <rt_periph_copy+0xa2>
1c009d86:	989a                	add	a7,a7,t1
1c009d88:	0088a423          	sw	s0,8(a7)
1c009d8c:	bfc9                	j	1c009d5e <rt_periph_copy+0xa2>

1c009d8e <__rt_periph_init>:
1c009d8e:	1c008537          	lui	a0,0x1c008
1c009d92:	02c00713          	li	a4,44
1c009d96:	4601                	li	a2,0
1c009d98:	02c00693          	li	a3,44
1c009d9c:	1a1028b7          	lui	a7,0x1a102
1c009da0:	1be50513          	addi	a0,a0,446 # 1c0081be <udma_event_handler>
1c009da4:	012950fb          	lp.setupi	x1,18,1c009dc8 <__rt_periph_init+0x3a>
1c009da8:	40165793          	srai	a5,a2,0x1
1c009dac:	00461813          	slli	a6,a2,0x4
1c009db0:	079e                	slli	a5,a5,0x7
1c009db2:	97c6                	add	a5,a5,a7
1c009db4:	01087813          	andi	a6,a6,16
1c009db8:	97c2                	add	a5,a5,a6
1c009dba:	00072023          	sw	zero,0(a4)
1c009dbe:	00072423          	sw	zero,8(a4)
1c009dc2:	c75c                	sw	a5,12(a4)
1c009dc4:	cf48                	sw	a0,28(a4)
1c009dc6:	0605                	addi	a2,a2,1
1c009dc8:	02070713          	addi	a4,a4,32
1c009dcc:	2406a023          	sw	zero,576(a3)
1c009dd0:	2406a223          	sw	zero,580(a3)
1c009dd4:	8082                	ret

1c009dd6 <__rt_uart_wait_tx_done.isra.4>:
1c009dd6:	1a102737          	lui	a4,0x1a102
1c009dda:	0761                	addi	a4,a4,24
1c009ddc:	431c                	lw	a5,0(a4)
1c009dde:	8bc1                	andi	a5,a5,16
1c009de0:	eb91                	bnez	a5,1c009df4 <__rt_uart_wait_tx_done.isra.4+0x1e>
1c009de2:	1a102737          	lui	a4,0x1a102
1c009de6:	02070713          	addi	a4,a4,32 # 1a102020 <__rt_iodev_uart_baudrate+0x1a0696b8>
1c009dea:	431c                	lw	a5,0(a4)
1c009dec:	fc17b7b3          	p.bclr	a5,a5,30,1
1c009df0:	ffed                	bnez	a5,1c009dea <__rt_uart_wait_tx_done.isra.4+0x14>
1c009df2:	8082                	ret
1c009df4:	10500073          	wfi
1c009df8:	b7d5                	j	1c009ddc <__rt_uart_wait_tx_done.isra.4+0x6>

1c009dfa <__rt_uart_setfreq_before>:
1c009dfa:	1c0017b7          	lui	a5,0x1c001
1c009dfe:	fb87a783          	lw	a5,-72(a5) # 1c000fb8 <__rt_uart>
1c009e02:	cf91                	beqz	a5,1c009e1e <__rt_uart_setfreq_before+0x24>
1c009e04:	1141                	addi	sp,sp,-16
1c009e06:	c606                	sw	ra,12(sp)
1c009e08:	37f9                	jal	1c009dd6 <__rt_uart_wait_tx_done.isra.4>
1c009e0a:	40b2                	lw	ra,12(sp)
1c009e0c:	005007b7          	lui	a5,0x500
1c009e10:	1a102737          	lui	a4,0x1a102
1c009e14:	0799                	addi	a5,a5,6
1c009e16:	d35c                	sw	a5,36(a4)
1c009e18:	4501                	li	a0,0
1c009e1a:	0141                	addi	sp,sp,16
1c009e1c:	8082                	ret
1c009e1e:	4501                	li	a0,0
1c009e20:	8082                	ret

1c009e22 <soc_eu_fcEventMask_setEvent>:
1c009e22:	47fd                	li	a5,31
1c009e24:	4721                	li	a4,8
1c009e26:	00a7d463          	ble	a0,a5,1c009e2e <soc_eu_fcEventMask_setEvent+0xc>
1c009e2a:	1501                	addi	a0,a0,-32
1c009e2c:	4711                	li	a4,4
1c009e2e:	1a1067b7          	lui	a5,0x1a106
1c009e32:	973e                	add	a4,a4,a5
1c009e34:	4314                	lw	a3,0(a4)
1c009e36:	4785                	li	a5,1
1c009e38:	00a79533          	sll	a0,a5,a0
1c009e3c:	fff54513          	not	a0,a0
1c009e40:	8d75                	and	a0,a0,a3
1c009e42:	c308                	sw	a0,0(a4)
1c009e44:	8082                	ret

1c009e46 <__rt_uart_setfreq_after>:
1c009e46:	1c0017b7          	lui	a5,0x1c001
1c009e4a:	fb878793          	addi	a5,a5,-72 # 1c000fb8 <__rt_uart>
1c009e4e:	4398                	lw	a4,0(a5)
1c009e50:	cf19                	beqz	a4,1c009e6e <__rt_uart_setfreq_after+0x28>
1c009e52:	4798                	lw	a4,8(a5)
1c009e54:	02faf7b7          	lui	a5,0x2faf
1c009e58:	08078793          	addi	a5,a5,128 # 2faf080 <__rt_iodev_uart_baudrate+0x2f16718>
1c009e5c:	02e7d7b3          	divu	a5,a5,a4
1c009e60:	1a102737          	lui	a4,0x1a102
1c009e64:	17fd                	addi	a5,a5,-1
1c009e66:	07c2                	slli	a5,a5,0x10
1c009e68:	3067e793          	ori	a5,a5,774
1c009e6c:	d35c                	sw	a5,36(a4)
1c009e6e:	4501                	li	a0,0
1c009e70:	8082                	ret

1c009e72 <rt_uart_conf_init>:
1c009e72:	67f1                	lui	a5,0x1c
1c009e74:	20078793          	addi	a5,a5,512 # 1c200 <__L1Cl+0xc200>
1c009e78:	c11c                	sw	a5,0(a0)
1c009e7a:	57fd                	li	a5,-1
1c009e7c:	c15c                	sw	a5,4(a0)
1c009e7e:	8082                	ret

1c009e80 <__rt_uart_open>:
1c009e80:	7179                	addi	sp,sp,-48
1c009e82:	d226                	sw	s1,36(sp)
1c009e84:	84aa                	mv	s1,a0
1c009e86:	d606                	sw	ra,44(sp)
1c009e88:	d422                	sw	s0,40(sp)
1c009e8a:	d04a                	sw	s2,32(sp)
1c009e8c:	ce4e                	sw	s3,28(sp)
1c009e8e:	30047973          	csrrci	s2,mstatus,8
1c009e92:	c62e                	sw	a1,12(sp)
1c009e94:	2a05                	jal	1c009fc4 <__rt_padframe_init>
1c009e96:	45b2                	lw	a1,12(sp)
1c009e98:	cd8d                	beqz	a1,1c009ed2 <__rt_uart_open+0x52>
1c009e9a:	4198                	lw	a4,0(a1)
1c009e9c:	1c0017b7          	lui	a5,0x1c001
1c009ea0:	fb878413          	addi	s0,a5,-72 # 1c000fb8 <__rt_uart>
1c009ea4:	00449613          	slli	a2,s1,0x4
1c009ea8:	9432                	add	s0,s0,a2
1c009eaa:	4014                	lw	a3,0(s0)
1c009eac:	fb878793          	addi	a5,a5,-72
1c009eb0:	c68d                	beqz	a3,1c009eda <__rt_uart_open+0x5a>
1c009eb2:	c589                	beqz	a1,1c009ebc <__rt_uart_open+0x3c>
1c009eb4:	418c                	lw	a1,0(a1)
1c009eb6:	4418                	lw	a4,8(s0)
1c009eb8:	06e59663          	bne	a1,a4,1c009f24 <__rt_uart_open+0xa4>
1c009ebc:	0685                	addi	a3,a3,1
1c009ebe:	00d7e623          	p.sw	a3,a2(a5)
1c009ec2:	8522                	mv	a0,s0
1c009ec4:	50b2                	lw	ra,44(sp)
1c009ec6:	5422                	lw	s0,40(sp)
1c009ec8:	5492                	lw	s1,36(sp)
1c009eca:	5902                	lw	s2,32(sp)
1c009ecc:	49f2                	lw	s3,28(sp)
1c009ece:	6145                	addi	sp,sp,48
1c009ed0:	8082                	ret
1c009ed2:	6771                	lui	a4,0x1c
1c009ed4:	20070713          	addi	a4,a4,512 # 1c200 <__L1Cl+0xc200>
1c009ed8:	b7d1                	j	1c009e9c <__rt_uart_open+0x1c>
1c009eda:	1a1029b7          	lui	s3,0x1a102
1c009ede:	4785                	li	a5,1
1c009ee0:	c01c                	sw	a5,0(s0)
1c009ee2:	c418                	sw	a4,8(s0)
1c009ee4:	c044                	sw	s1,4(s0)
1c009ee6:	78098713          	addi	a4,s3,1920 # 1a102780 <__rt_iodev_uart_baudrate+0x1a069e18>
1c009eea:	4314                	lw	a3,0(a4)
1c009eec:	009797b3          	sll	a5,a5,s1
1c009ef0:	0486                	slli	s1,s1,0x1
1c009ef2:	8fd5                	or	a5,a5,a3
1c009ef4:	c31c                	sw	a5,0(a4)
1c009ef6:	8526                	mv	a0,s1
1c009ef8:	372d                	jal	1c009e22 <soc_eu_fcEventMask_setEvent>
1c009efa:	00148513          	addi	a0,s1,1
1c009efe:	3715                	jal	1c009e22 <soc_eu_fcEventMask_setEvent>
1c009f00:	4418                	lw	a4,8(s0)
1c009f02:	02faf7b7          	lui	a5,0x2faf
1c009f06:	08078793          	addi	a5,a5,128 # 2faf080 <__rt_iodev_uart_baudrate+0x2f16718>
1c009f0a:	02e7d7b3          	divu	a5,a5,a4
1c009f0e:	02498993          	addi	s3,s3,36
1c009f12:	17fd                	addi	a5,a5,-1
1c009f14:	07c2                	slli	a5,a5,0x10
1c009f16:	3067e793          	ori	a5,a5,774
1c009f1a:	00f9a023          	sw	a5,0(s3)
1c009f1e:	30091073          	csrw	mstatus,s2
1c009f22:	b745                	j	1c009ec2 <__rt_uart_open+0x42>
1c009f24:	4401                	li	s0,0
1c009f26:	bf71                	j	1c009ec2 <__rt_uart_open+0x42>

1c009f28 <rt_uart_close>:
1c009f28:	1141                	addi	sp,sp,-16
1c009f2a:	c606                	sw	ra,12(sp)
1c009f2c:	c422                	sw	s0,8(sp)
1c009f2e:	c226                	sw	s1,4(sp)
1c009f30:	300474f3          	csrrci	s1,mstatus,8
1c009f34:	411c                	lw	a5,0(a0)
1c009f36:	17fd                	addi	a5,a5,-1
1c009f38:	c11c                	sw	a5,0(a0)
1c009f3a:	e385                	bnez	a5,1c009f5a <rt_uart_close+0x32>
1c009f3c:	842a                	mv	s0,a0
1c009f3e:	3d61                	jal	1c009dd6 <__rt_uart_wait_tx_done.isra.4>
1c009f40:	1a102737          	lui	a4,0x1a102
1c009f44:	4050                	lw	a2,4(s0)
1c009f46:	78070713          	addi	a4,a4,1920 # 1a102780 <__rt_iodev_uart_baudrate+0x1a069e18>
1c009f4a:	4314                	lw	a3,0(a4)
1c009f4c:	4785                	li	a5,1
1c009f4e:	00c797b3          	sll	a5,a5,a2
1c009f52:	fff7c793          	not	a5,a5
1c009f56:	8ff5                	and	a5,a5,a3
1c009f58:	c31c                	sw	a5,0(a4)
1c009f5a:	30049073          	csrw	mstatus,s1
1c009f5e:	40b2                	lw	ra,12(sp)
1c009f60:	4422                	lw	s0,8(sp)
1c009f62:	4492                	lw	s1,4(sp)
1c009f64:	0141                	addi	sp,sp,16
1c009f66:	8082                	ret

1c009f68 <__rt_uart_init>:
1c009f68:	1c00a5b7          	lui	a1,0x1c00a
1c009f6c:	1141                	addi	sp,sp,-16
1c009f6e:	4601                	li	a2,0
1c009f70:	dfa58593          	addi	a1,a1,-518 # 1c009dfa <__rt_uart_setfreq_before>
1c009f74:	4511                	li	a0,4
1c009f76:	c606                	sw	ra,12(sp)
1c009f78:	c422                	sw	s0,8(sp)
1c009f7a:	e50ff0ef          	jal	ra,1c0095ca <__rt_cbsys_add>
1c009f7e:	1c00a5b7          	lui	a1,0x1c00a
1c009f82:	842a                	mv	s0,a0
1c009f84:	4601                	li	a2,0
1c009f86:	e4658593          	addi	a1,a1,-442 # 1c009e46 <__rt_uart_setfreq_after>
1c009f8a:	4515                	li	a0,5
1c009f8c:	e3eff0ef          	jal	ra,1c0095ca <__rt_cbsys_add>
1c009f90:	1c0017b7          	lui	a5,0x1c001
1c009f94:	fa07ac23          	sw	zero,-72(a5) # 1c000fb8 <__rt_uart>
1c009f98:	8d41                	or	a0,a0,s0
1c009f9a:	c10d                	beqz	a0,1c009fbc <__rt_uart_init+0x54>
1c009f9c:	f1402673          	csrr	a2,mhartid
1c009fa0:	1c000537          	lui	a0,0x1c000
1c009fa4:	40565593          	srai	a1,a2,0x5
1c009fa8:	f265b5b3          	p.bclr	a1,a1,25,6
1c009fac:	f4563633          	p.bclr	a2,a2,26,5
1c009fb0:	4e450513          	addi	a0,a0,1252 # 1c0004e4 <__DTOR_END__+0x220>
1c009fb4:	d29fe0ef          	jal	ra,1c008cdc <printf>
1c009fb8:	d83fe0ef          	jal	ra,1c008d3a <abort>
1c009fbc:	40b2                	lw	ra,12(sp)
1c009fbe:	4422                	lw	s0,8(sp)
1c009fc0:	0141                	addi	sp,sp,16
1c009fc2:	8082                	ret

1c009fc4 <__rt_padframe_init>:
1c009fc4:	1c001737          	lui	a4,0x1c001
1c009fc8:	fd470713          	addi	a4,a4,-44 # 1c000fd4 <__rt_padframe_is_init>
1c009fcc:	00074783          	lbu	a5,0(a4)
1c009fd0:	eb8d                	bnez	a5,1c00a002 <__rt_padframe_init+0x3e>
1c009fd2:	1c0017b7          	lui	a5,0x1c001
1c009fd6:	fcc7a683          	lw	a3,-52(a5) # 1c000fcc <_rt_io_uart>
1c009fda:	1a1047b7          	lui	a5,0x1a104
1c009fde:	01078613          	addi	a2,a5,16 # 1a104010 <__rt_iodev_uart_baudrate+0x1a06b6a8>
1c009fe2:	428c                	lw	a1,0(a3)
1c009fe4:	c20c                	sw	a1,0(a2)
1c009fe6:	42cc                	lw	a1,4(a3)
1c009fe8:	01478613          	addi	a2,a5,20
1c009fec:	c20c                	sw	a1,0(a2)
1c009fee:	468c                	lw	a1,8(a3)
1c009ff0:	01878613          	addi	a2,a5,24
1c009ff4:	07f1                	addi	a5,a5,28
1c009ff6:	c20c                	sw	a1,0(a2)
1c009ff8:	46d4                	lw	a3,12(a3)
1c009ffa:	c394                	sw	a3,0(a5)
1c009ffc:	4785                	li	a5,1
1c009ffe:	00f70023          	sb	a5,0(a4)
1c00a002:	8082                	ret

1c00a004 <__rt_padframe_constructor>:
1c00a004:	1c0017b7          	lui	a5,0x1c001
1c00a008:	fc078a23          	sb	zero,-44(a5) # 1c000fd4 <__rt_padframe_is_init>
1c00a00c:	8082                	ret

1c00a00e <__rt_bridge_check_bridge_req.part.2>:
1c00a00e:	1c001737          	lui	a4,0x1c001
1c00a012:	e8870793          	addi	a5,a4,-376 # 1c000e88 <__hal_debug_struct>
1c00a016:	0987a783          	lw	a5,152(a5)
1c00a01a:	e8870713          	addi	a4,a4,-376
1c00a01e:	c789                	beqz	a5,1c00a028 <__rt_bridge_check_bridge_req.part.2+0x1a>
1c00a020:	4b94                	lw	a3,16(a5)
1c00a022:	e681                	bnez	a3,1c00a02a <__rt_bridge_check_bridge_req.part.2+0x1c>
1c00a024:	0af72023          	sw	a5,160(a4)
1c00a028:	8082                	ret
1c00a02a:	439c                	lw	a5,0(a5)
1c00a02c:	bfcd                	j	1c00a01e <__rt_bridge_check_bridge_req.part.2+0x10>

1c00a02e <__rt_bridge_handle_notif>:
1c00a02e:	1c0017b7          	lui	a5,0x1c001
1c00a032:	e8878713          	addi	a4,a5,-376 # 1c000e88 <__hal_debug_struct>
1c00a036:	09872703          	lw	a4,152(a4)
1c00a03a:	e8878793          	addi	a5,a5,-376
1c00a03e:	c319                	beqz	a4,1c00a044 <__rt_bridge_handle_notif+0x16>
1c00a040:	4754                	lw	a3,12(a4)
1c00a042:	e689                	bnez	a3,1c00a04c <__rt_bridge_handle_notif+0x1e>
1c00a044:	0a07a783          	lw	a5,160(a5)
1c00a048:	e795                	bnez	a5,1c00a074 <__rt_bridge_handle_notif+0x46>
1c00a04a:	b7d1                	j	1c00a00e <__rt_bridge_check_bridge_req.part.2>
1c00a04c:	4310                	lw	a2,0(a4)
1c00a04e:	5f18                	lw	a4,56(a4)
1c00a050:	08c7ac23          	sw	a2,152(a5)
1c00a054:	300475f3          	csrrci	a1,mstatus,8
1c00a058:	4754                	lw	a3,12(a4)
1c00a05a:	00072423          	sw	zero,8(a4)
1c00a05e:	4288                	lw	a0,0(a3)
1c00a060:	c901                	beqz	a0,1c00a070 <__rt_bridge_handle_notif+0x42>
1c00a062:	42c8                	lw	a0,4(a3)
1c00a064:	c518                	sw	a4,8(a0)
1c00a066:	c2d8                	sw	a4,4(a3)
1c00a068:	30059073          	csrw	mstatus,a1
1c00a06c:	8732                	mv	a4,a2
1c00a06e:	bfc1                	j	1c00a03e <__rt_bridge_handle_notif+0x10>
1c00a070:	c298                	sw	a4,0(a3)
1c00a072:	bfd5                	j	1c00a066 <__rt_bridge_handle_notif+0x38>
1c00a074:	8082                	ret
	...
