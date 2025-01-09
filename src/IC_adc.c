/********************************** (C) COPYRIGHT *******************************
 * File Name          : IC_adc.h
 * Author             : haungjin
 * Version            : V0.1
 * Date               : 2024/12/8
 * Description
 *******************************************************************************/

#include "IC_adc.h"


/*********************************************************************
 * @fn      ADC_ExtSingleChSampInit
 *
 * @brief   外部信号单通道采样初始化
 *
 * @param   sp  - refer to ADC_SampClkTypeDef
 * @param   ga  - refer to ADC_SignalPGATypeDef
 *
 * @return  none
 */
void ADC_ExtSingleChSampInit(uint8_t sp)
{

    ADC_SampClkCfg(1);
    ADC_SampClk_EN(0);
    ADC_Channel0(0);
}

/*********************************************************************
 * @fn      ADC_ExtDiffChSampInit
 *
 * @brief   外部信号差分通道采样初始化
 
 *
 * @return  none
 */
void ADC_ExtDiffChSampInit(uint8_t sp)
{
   

}


/*********************************************************************
 * @fn      ADC_ExcutSingleConver
 *
 * @brief   ADC执行单次转换
 *
 * @param   none
 *
 * @return  ADC转换后的数据
 */
uint16_t ADC_ExcutSingleConver(void)
{
    return (R8_CMD10_ADC);
}



/*********************************************************************
 * @fn      ADC_DMACfg
 *
 * @brief   配置DMA功能
 *
 * @param   s           - 是否打开DMA功能
 * @param   startAddr   - DMA 起始地址
 * @param   endAddr     - DMA 结束地址
 * @param   data_len      
 *
 * @return  none
 */
void ADC_DMACfg(uint8_t s, uint32_t startAddr, uint32_t data_len)
{
    uint32_t addr_count=0;
    
    for (addr_count = 0; addr_count < data_len; addr_count++)
    {
        if (s == DISABLE)
        {
            ADC_SampClk_EN(1);
            break;
        }
        else
        {
            *((volatile uint16_t *)(startAddr + addr_count)) |= ADC_ExcutSingleConver();
        }
    }

}

