//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//  文 件 名   : 
//  版 本 号   : 
//  作    者   : huang jin
//  生成日期   : 2014/3/16
//  最近修改   : 2023/8/25
//  功能描述   : 0.96寸OLED 接口演示例程(HC32F448系列硬件IIC)
//              说明:
//              ----------------------------------------------------------------
//              GND   电源地
//              VCC   接5V或3.3v电源
//              SCL   接PD1（SCL）
//              SDA   接PD0（SDA）
//              ----------------------------------------------------------------
//Copyright(C) 中景园电子2014/3/16
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////
#ifndef __OLED_H
#define __OLED_H

#include <stdio.h>
//#include <rt/rt_api.h>
#include <stdint.h>
#include "i2c-0.h"
#include "hal/pulp_io.h"

#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF
#define X_WIDTH 	128
#define Y_WIDTH 	64
//-----------------OLED IIC端口定义----------------

#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

/* Define port and pin for SDA and SCL */
#define I2C_SDA_PORT        (GPIO_PORT_D)//类似HAL库的配置
#define I2C_SDA_PIN         (GPIO_PIN_00)
#define I2C_SCL_PORT        (GPIO_PORT_D)
#define I2C_SCL_PIN         (GPIO_PIN_01)


#define I2C_SDA_FUNC        (GPIO_FUNC_50)	//pin脚功能配置号	
#define I2C_SCL_FUNC        (GPIO_FUNC_51)	//详情见数据手册引脚配置页

/* I2C unit define */
#define I2C_UNIT            (CM_I2C2)						//硬件I2C地址
#define I2C_FCG             (FCG1_PERIPH_I2C2)	//开启时钟

void Delay(uint32_t count);
void  I2C_GPIO_Init();
void I2C_Init();

//OLED控制用函数
void OLED_WR_Byte(uint8_t *dat);//I2C传输字节函数
void oled_init(void);//初始化
void oled_cmd(uint8_t i2c_cmd);
void oled_data(uint8_t i2c_data) ;
void oled_display_char(uint8_t x, uint8_t y, uint8_t chr, uint8_t Char_Size);
void oled_show_string(uint8_t x, uint8_t y, char ch[], uint8_t TextSize);//显示字符串，TextSize是尺寸大小
void oled_showCN(unsigned char x, unsigned char y, unsigned char CN[],unsigned char N); //显示汉字
void oled_drawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);	//画图
void oled_showNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size1); //显示数字
void oled_full(uint8_t data);
void oled_cls(void);  //清屏
void oled_on(void);   //开启
void oled_off(void);	//关闭
void show_title(void);//显示一个固定标题
#endif




