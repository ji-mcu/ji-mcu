#include "soc_common.h"

#include "IC_lin.h"

// void LINHandler(void)
// {
//     int rdata;
//     // unsigned char send_buf[8]={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
//     rdata = Lin_ISR;
//     if (rdata & 0x7ff);
//         // printf("error is 0x%x\n", rdata);
//     else if (rdata & 0x1000)
//     {
//         // Lin_CR|=0x10;
//         // for(rdata=0;rdata<8;rdata++){
//         // Lin_DATA=send_buf[rdata];
//         //}
//         Lin_CR |= 0x20;
//         // printf("rec ID is 0x%x,Div is 0x%x\n", Lin_ID, Lin_DIV);
//     }
//     else
//     {
//         for (rdata = 0; rdata < 8; rdata++);
//             // printf("The %d num is 0x%x\n", rdata, Lin_DATA);
//     }
// }

void LIN_init(void)
{
    // Lin_IER = 0x1fff;//中断使能寄存器
   
    Lin_CR = 0x800; // 控制寄存器
    // Lin_CR = 0x43;
    Lin_ISR= 0;
    Lin_DIV = TIM_CLOCK_64M/16/ 115200 - 1; // 波特率分频寄存器
    // Lin_CR =0x643;
    // Lin_ID=0x30;
    // Lin_CR&=(~(0x1<<6));
    // Lin_CR|=0x5;//as slave
}

void LIN_send(unsigned char ID, unsigned char *buf)
{
    int i;
    Lin_CR = 0x43;
    Lin_ID = ID; // ID寄存器
    for (i = 0; i < 8; i++)
    {
        Lin_DATA = buf[i]; // 数据寄存器
    }
    Lin_CR |= 0x1a;
    Lin_CR |= 0x1;
    // Lin_CR |= 0x1B;
}
void LIN_send_head(unsigned char ID)
{
    Lin_ID = ID;
    Lin_CR |= 0xa;
    Lin_CR |= 0x1;
    // printf("now start to send head\n");
}
