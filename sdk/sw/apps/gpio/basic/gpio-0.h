/*memory map define for gpio-0 */


#ifndef __ARCHI_PULPISSIMO_MEMORY_MAP_H_GPIO0__
#define __ARCHI_PULPISSIMO_MEMORY_MAP_H_GPIO0__



/*SOC PERIPHERALS*/

#define PERI_GPIO0_ADDR                      0x1A101000


#define GPIO0_PADDIR_OFFSET                  0x00
#define GPIO0_PADIN_OFFSET                   0x04
#define GPIO0_PADOUT_OFFSET                  0x08
#define GPIO0_INTEN_OFFSET                   0x0c
#define GPIO0_INTTYPE0_OFFSET                0x10
#define GPIO0_INTTYPE1_OFFSET                0x14
#define GPIO0_INTSTATUS_OFFSET               0x18
#define GPIO0_EN_OFFSET                      0x1c
#define GPIO0_PADCFG0_OFFSET                 0x20
#define GPIO0_PADCFG1_OFFSET                 0x24
#define GPIO0_PADCFG2_OFFSET                 0x28
#define GPIO0_PADCFG3_OFFSET                 0x2c
#define GPIO0_PADCFG4_OFFSET                 0x30
#define GPIO0_PADCFG5_OFFSET                 0x34
#define GPIO0_PADCFG6_OFFSET                 0x38
#define GPIO0_PADCFG7_OFFSET                 0x3c

#define GPIO0_PADOUTSET_OFFSET               0x40
#define GPIO0_PADOUTCLR_OFFSET               0x44






#define PERI_GPIO0_PADDIR_ADDR               ( PERI_GPIO0_ADDR + GPIO0_PADDIR_OFFSET )
#define PERI_GPIO0_PADIN_ADDR                ( PERI_GPIO0_ADDR + GPIO0_PADIN_OFFSET )
#define PERI_GPIO0_PADOUT_ADDR               ( PERI_GPIO0_ADDR + GPIO0_PADOUT_OFFSET )
#define PERI_GPIO0_INTEN_ADDR                ( PERI_GPIO0_ADDR + GPIO0_INTEN_OFFSET )
#define PERI_GPIO0_INTTYPE0_ADDR             ( PERI_GPIO0_ADDR + GPIO0_INTTYPE0_OFFSET )
#define PERI_GPIO0_INTTYPE1_ADDR             ( PERI_GPIO0_ADDR + GPIO0_INTTYPE1_OFFSET )
#define PERI_GPIO0_INTSTATUS_ADDR            ( PERI_GPIO0_ADDR + GPIO0_INTSTATUS_OFFSET )
#define PERI_GPIO0_EN_ADDR                   ( PERI_GPIO0_ADDR + GPIO0_EN_OFFSET )
#define PERI_GPIO0_PADCFG0_ADDR              ( PERI_GPIO0_ADDR + GPIO0_PADCFG0_OFFSET )
#define PERI_GPIO0_PADCFG1_ADDR              ( PERI_GPIO0_ADDR + GPIO0_PADCFG1_OFFSET )
#define PERI_GPIO0_PADCFG2_ADDR              ( PERI_GPIO0_ADDR + GPIO0_PADCFG2_OFFSET )
#define PERI_GPIO0_PADCFG3_ADDR              ( PERI_GPIO0_ADDR + GPIO0_PADCFG3_OFFSET )
#define PERI_GPIO0_PADCFG4_ADDR              ( PERI_GPIO0_ADDR + GPIO0_PADCFG4_OFFSET )
#define PERI_GPIO0_PADCFG5_ADDR              ( PERI_GPIO0_ADDR + GPIO0_PADCFG5_OFFSET )
#define PERI_GPIO0_PADCFG6_ADDR              ( PERI_GPIO0_ADDR + GPIO0_PADCFG6_OFFSET )
#define PERI_GPIO0_PADCFG7_ADDR              ( PERI_GPIO0_ADDR + GPIO0_PADCFG7_OFFSET )
#define PERI_GPIO0_PADOUTSET_ADDR            ( PERI_GPIO0_ADDR + GPIO0_PADOUTSET_OFFSET )
#define PERI_GPIO0_PADOUTCLR_ADDR            ( PERI_GPIO0_ADDR + GPIO0_PADOUTCLR_OFFSET )







//void hal_soc_spis0_set(unsigned int value);
//void hal_soc_spis0_set(unsigned int addr,unsigned int value);
//void hal_soc_spis0_read_check(unsigned int addr, int exp_value);
//void hal_soc_spis0_read(unsigned int addr);
//void interrupt_handle();

void hal_soc_gpio_set(unsigned int addr,unsigned int value);
void hal_soc_gpio0_read(unsigned int addr);
void gpio_reg_test();
void gpio_input_test();
void gpio_output_test();
void gpio_interrupt_set();



#endif
