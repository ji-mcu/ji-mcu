
#ifndef __REG_HGM_MAP__
#define __REG_HGM_MAP__

#define REG_HGM_STATUS      0x0
#define REG_HGM_BASE_ADDR   0x1
#define REG_HGM_CVCSEL_NUM  0x2
#define REG_HGM_FVCSEL_NUM  0x3
#define REG_HGM_GENERAL     0x4
#define REG_HGM_GENERAL2    0x5
#define REG_HGM_CNTR_CFG    0x6
#define REG_HGM_CNTR_CFG2   0x7
#define REG_HGM_UCBIN_L     0x8
#define REG_HGM_UCBIN_H     0x9
#define REG_HGM_WIN_CFG     0xa
#define REG_HGM_TEST_CFG    0xb
#define REG_HGM_CMAX_L      0xc
#define REG_HGM_CMAX_H      0xd
#define REG_HGM_CALIB_SUM   0xe
#define REG_HGM_CUR_ADDR    0xf


void TDC_setting(int hgm_mode, int test_mode, int shut_mode);
void wait_soc_event();
void set_soc_event_enable();

#endif