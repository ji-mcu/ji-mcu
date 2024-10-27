//////////////////////////////////////////////////////////////////////////////////
// 本程序只供学习使用，未经作者许可，不得用于其它任何用途
//   文 件 名   :
//   版 本 号   :
//   作    者   : huang jin
//   生成日期   : 2014/3/16
//   最近修改   : 2025/5/13
//   功能描述   : 0.96寸OLED 接口演示例程(技大一号系列硬件IIC)
//               说明:
//               ----------------------------------------------------------------
//               GND   电源地
//               VCC   接5V或3.3v电源
//               SCL   接PD1（SCL）
//               SDA   接PD0（SDA）
//               ----------------------------------------------------------------
// Copyright(C) 中景园电子2014/3/16
// All rights reserved
//////////////////////////////////////////////////////////////////////////////////
#include "oledfont.h"
#include "oled.h"
#include <stdio.h>
// #include <rt/rt_api.h>
#include "gpio-0.h"
#include <stdint.h>
#include "i2c-0.h"

/**
 * @defgroup I2C_Configuration
 * @{
 */
#define I2C_BAUDRATE (400000UL) // I2C波特率配置
#define I2C_TIMEOUT (0x64U)		//
#define OLED_ADD (0x78)			// 写入OLED初始地址
#define DATA_Len (0x0d)			// 写入数据长度
#define I2C_DIR_TX2 (0x00)		// 写入标志

void Delay(uint32_t count) //@64MHz
{
	unsigned long i;

	for (i = 0; i < count; i++)
		;
}

/**
 * @defgroup I2C_GPIO_Init  //设置IIC的初始化IO
 * @{
 */
void I2C_GPIO_Init()
{
	//   printf("Entering i2c0 test\n");
	//   pulp_write32(0x1A101010,1<<0|1<<2);
	//   pulp_write32(0x1A101014,0x0);

	// set i2c1 mux output
	//   pulp_write32(0x1A101010,0x5);
} // 这个寄存器究竟是做什么的？

/**
 * @defgroup I2C_init
 * @{
 * 初始化所要配置：
 * 配置TX ADDR 内存初始地址zhi
 * 配置TX 初始化内存地址数据长度
 * 配置TX CFG 开始传输或者停止传输：
 * 配置寄存器SETUP，设置分频系数/传输使能/设置bit-length
 */
void I2C_Init()
{
	// int tx_ram_addr = 0x40110;

	// int tx_size 	= 0x0D	;

	// I2C_GPIO_Init();
	// hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR, 0x23);
	// hal_soc_i2c0_set(PERI_I2C0_TX_SADDR_ADDR, tx_ram_addr);
	// hal_soc_i2c0_set(PERI_I2C0_TX_SIZE_ADDR, tx_size);
	// hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR, 0x32);
	// hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR, 1 << 4);
}

/**
 * @brief  OLED_WR_Byte 写入一字节/两字节
 * @param  *dat
 * @retval 无返回
 * 首先在sram存入buf数据，并保留其原地址
 * 其次在配置IIC读取sram的地址
 * 再配置IIC读取sram数据个数
 * 启动传输，传输后自动停止；
 *
 *用法举例：OLED_WR_Byte(buf),buf定义：可定义为数组，如 int8_t buf[2];
 */
void OLED_WR_Byte(uint8_t *dat)
{
	int32_t i32Ret;
	int32_t sram_addr = 0x40110;
	int32_t sram_addr_offset = 0x4;
	// int tx_size = 0x03;

	hal_soc_i2c0_set(0x1c040110, 0x0003C502);
	hal_soc_i2c0_set(0x1c040114, (0x00000080 | (OLED_ADD << 8) | (dat[0] << 16) | (dat[1] << 24)));
	hal_soc_i2c0_set(0x1c040118, 0x00000010);
	hal_soc_i2c0_set(0x1c040118, 0x00000020);

	// hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR, 0x01);
	// hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR, 0x00);
	// hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR, 0);
	hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR, 1 << 6 );
	// hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR, 0);
	hal_soc_i2c0_set(PERI_I2C0_TX_SADDR_ADDR, sram_addr);
	hal_soc_i2c0_set(PERI_I2C0_TX_SIZE_ADDR, DATA_Len);
	// hal_soc_i2c0_set(PERI_I2C0_SETUP_ADDR, (1 << 8 | 1 << 1 | 1 << 2)); // 8bits,no parity,1stopbit
	hal_soc_i2c0_set(PERI_I2C0_TX_CFG_ADDR, (1 << 4)|(1<<0));
	Delay(10000);
}
/**
 * @brief  oled_cmd 写入oled指令
 * @param  i2c_cmd,一个8位无符号整数
 * @retval void
 */
void oled_cmd(uint8_t i2c_cmd)
{

	uint8_t u8TXBuf[2];
	u8TXBuf[0] = 0x00;
	u8TXBuf[1] = i2c_cmd;
	OLED_WR_Byte(u8TXBuf);

	//	uint8_t *cmd;
	//	uint8_t adr1;
	//	uint8_t *adr;
	//	adr1=0x00;
	//	adr=&adr1;
	//	cmd=&i2c_cmd;
	//	 BSP_I2C_Write(BSP_TCA9539_I2C_UNIT, OLED_ADD, adr,1,cmd, 1);
}

/**
 * @brief  oled_data�
 * @param  i2c_data 传数据
 * @retval
 */
void oled_data(uint8_t i2c_data)
{
	uint8_t u8TXBuf[2];
	u8TXBuf[0] = 0x40;
	u8TXBuf[1] = i2c_data;
	OLED_WR_Byte(u8TXBuf);

	//		uint8_t *dat;
	//		uint8_t adr1;
	//		uint8_t *adr;
	//		adr1=0x40;
	//		adr=&adr1;
	//		dat=&i2c_data;
	//	 BSP_I2C_Write(BSP_TCA9539_I2C_UNIT, OLED_ADD,adr ,1,dat, 1);
}

/**
 * @brief  oled_setPos 坐标设置函数
 * @param  x，y，
 * @retval
 */
static void oled_setPos(uint8_t x, uint8_t y)
{
	oled_cmd(0xb0 + y);
	oled_cmd(((x & 0xf0) >> 4) | 0x10);
	oled_cmd((x & 0x0f) | 0x01);
}

/**
 * @brief  oled_full 满屏填充数据
 * @param  data:      Ҫ��������
 * @retval ��
 */
void oled_full(uint8_t data) // 0xff
{
	uint8_t m, n;
	for (m = 0; m < 8; m++)
	{
		oled_cmd(0xb0 + m); // page0-page1
		oled_cmd(0x00);		// low column start address
		oled_cmd(0x10);		// high column start address
		for (n = 0; n < 128; n++)
		{
			oled_data(data);
		}
	}
}

/**
 * @brief  oled_cls 清屏
 * @param
 * @retval
 */
void oled_cls(void)
{
	oled_full(0x00);
}

/**
 * @brief  OLED_ON 开启oled显示
 * @param
 * @retval
 */
void oled_on(void)
{
	oled_cmd(0X8D); // SET DCDC命令
	oled_cmd(0X14); // DCDC ON
	oled_cmd(0XAF); // OLED DISPLAY ON
}

/**
 * @brief  OLED_OFF 关闭oled
 * @param
 * @retval
 */
void oled_off(void)
{
	oled_cmd(0X8D); ////SET DCDC命令
	oled_cmd(0X10); // DCDC ON
	oled_cmd(0XAE); // OLED DISPLAY ON
}

/**
 * @brief  oled_init 初始化oled
 * @param
 * @retval
 */
void oled_init(void)
{
	// I2C_Init();
	// Delay(800);

	oled_cmd(0xAE); // display off

	oled_cmd(0x20); // Set Memory Addressing Mode
	oled_cmd(0x10); // 00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	oled_cmd(0xb0); // Set Page Start Address for Page Addressing Mode,0-7

	oled_cmd(0xc8); // Set COM Output Scan Direction
	oled_cmd(0x00); //---set low column address
	oled_cmd(0x10); //---set high column address

	oled_cmd(0x40); //--set start line address
	oled_cmd(0x81); //--set contrast control register
	oled_cmd(0xff); // 0x00~0xff
	oled_cmd(0xa1); //--set segment re-map 0 to 127

	oled_cmd(0xa6); //--set normal display
	oled_cmd(0xa8); //--set multiplex ratio(1 to 64)
	oled_cmd(0x3F); //
	oled_cmd(0xa4); // 0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	oled_cmd(0xd3); //-set display offset
	oled_cmd(0x00); //-not offset

	oled_cmd(0xd5); //--set display clock divide ratio/oscillator frequency
	oled_cmd(0xf0); //--set divide ratio
	oled_cmd(0xd9); //--set pre-charge period
	oled_cmd(0x22); //

	oled_cmd(0xda); //--set com pins hardware configuration
	oled_cmd(0x12);
	oled_cmd(0xdb); //--set vcomh
	oled_cmd(0x20); // 0x20,0.77xVcc
	oled_cmd(0x8d); //--set DC-DC enable

	oled_cmd(0x14); //
	oled_cmd(0xaf); //--turn on oled panel
}

/**
 * @brief  oled_display_char
 * @param  x,y : 坐标可填范围：x:0-127, y:0-7
 *					chr:- 显示字符
 *					Char_Size : 字符大小(填16/8)
 * @retval ��
 */
void oled_display_char(uint8_t x, uint8_t y, uint8_t chr, uint8_t Char_Size)
{
	unsigned char c = 0, i = 0;
	c = chr - ' '; // �õ�ƫ�ƺ��ֵ
	if (x > 128 - 1)
	{
		x = 0;
		y = y + 2;
	}
	if (Char_Size == 16)
	{
		oled_setPos(x, y);
		for (i = 0; i < 8; i++)
			oled_data(F8X16[c * 16 + i]);
		oled_setPos(x, y + 1);
		for (i = 0; i < 8; i++)
			oled_data(F8X16[c * 16 + i + 8]);
	}
	else
	{
		oled_setPos(x, y);
		for (i = 0; i < 6; i++)
			oled_data(F6x8[c][i]);
	}
}

/**
 * @brief  oled_show_string 显示一串string
 * @param  x,y : 坐标可填范围：x:0-127, y:0-7
 *	ch[] : 字符串
 *	TextSize : you can write 1 or 2 (1和2代表的尺寸：1:6*8 ; 2:8*16)
 * @retval ��
 */
void oled_show_string(uint8_t x, uint8_t y, char ch[], uint8_t TextSize)
{
	uint8_t c = 0, i = 0, j = 0;

	switch (TextSize)
	{
	case 1:
	{
		while (ch[j] != '\0')
		{
			c = ch[j] - 32;
			if (x > 126)
			{
				x = 0;
				y++;
			}

			oled_setPos(x, y);
			for (i = 0; i < 6; i++)
				oled_data(F6x8[c][i]);
			x += 6;
			j++;
		}
	}
	break;
	case 2:
	{
		while (ch[j] != '\0')
		{
			c = ch[j] - 32;
			if (x > 120)
			{
				x = 0;
				y++;
			}

			oled_setPos(x, y);
			for (i = 0; i < 8; i++)
				oled_data(F8X16[c * 16 + i]);
			oled_setPos(x, y + 1);
			for (i = 0; i < 8; i++)
				oled_data(F8X16[c * 16 + i + 8]);
			x += 8;
			j++;
		}
	}
	break;
	}
}

/**
 * @brief  oled_showCN  显示汉字
 * @param  x,y: (x:0~127, y:0~7);
 *					N:oledfont.h
 * @retval
 */
void oled_showCN(unsigned char x, unsigned char y, unsigned char CN[], unsigned char N)
{
	unsigned char wm = 0;
	unsigned int adder = 32 * N;
	oled_setPos(x, y);
	for (wm = 0; wm < 16; wm++)
	{
		oled_data(CN[adder]);
		adder += 1;
	}
	oled_setPos(x, y + 1);
	for (wm = 0; wm < 16; wm++)
	{
		oled_data(CN[adder]);
		adder += 1;
	}
}

/**
 * @brief  oled_drawBMP
 * @param  x0,y0 : 坐标上下限(x0:0~127, y0:0~7);
 *					x1,y1 : (x1:1~128,y1:1~8)
 * @retval
 */
void oled_drawBMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[])
{
	unsigned int j = 0;
	unsigned char x, y;

	if (y1 % 8 == 0)
		y = y1 / 8;
	else
		y = y1 / 8 + 1;
	for (y = y0; y < y1; y++)
	{
		oled_setPos(x0, y);
		for (x = x0; x < x1; x++)
		{
			oled_data(BMP[j++]);
		}
	}
}

// m^n
uint32_t oled_pow(uint8_t m, uint8_t n)
{
	uint32_t result = 1;
	while (n--)
	{
		result *= m;
	}
	return result;
}

/**
* @brief  oled_showNum 显示数字
 * @param  x,y: (x:0~127, y:0~7);
		   num
		   len 	数字长度
		   sizel 数字大小 12/16/24
 * @retval
 */
void oled_showNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size1)
{
	uint8_t t, temp;
	for (t = 0; t < len; t++)
	{
		//	BSP_LED_Toggle(LED_BLUE);
		temp = (num / oled_pow(10, len - t - 1)) % 10;
		if (temp == 0)
		{
			oled_display_char(x + (size1 / 2) * t, y, '0', size1);
		}
		else
		{
			oled_display_char(x + (size1 / 2) * t, y, temp + '0', size1);
		}
	}
}

/**
 * @brief  show_title 显示一个汉字标题，仅用以测试
 * @param
 * @retval
 */
void show_title(void)
{
	uint32_t i;

	oled_cls();
	for (i = 0; i <= 10; i++)
	{
		if (i <= 4)
			oled_showCN(20 + i * 16, 1, Title, i); //
		else
			oled_showCN(10 + (i - 5) * 16, 4, Title, i); //
	}
}