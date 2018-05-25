/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：battery.c
 * 描述    	：电源电量检测    
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "battery.h"
#include "delay.h"

#define ADC1_DR_Address 	((u32)0x40012400+0x4c)

extern Battery battery;
extern Flag flag;


 /*
 * 函数名	：Battery_GPIO_Config
 * 描述		：配置电池功能的相应引脚
 * 输入		：无
 * 输出		：无
 */
static void ADC1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

 /*
 * 函数名	：Battery_Config
 * 描述		：配置DMA、ADC
 * 输入		：无
 * 输出		：无
 */
static void Battery_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
//	DMA配置
	
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_BufferSize = 1;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&(battery.Battery_Value);
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	
	DMA_Cmd(DMA1_Channel1, ENABLE);
	
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);
    
//	ADC配置

	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	
	ADC_Init(ADC1, &ADC_InitStructure);
	
//	配置ADC时钟
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_55Cycles5);
	
	ADC_DMACmd(ADC1, ENABLE);
	
	ADC_Cmd(ADC1, ENABLE);
	
//	校准
	
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

////////////////////////////////////////////////////////////////////////////////
void Battery_Init(void)
{
    ADC1_GPIO_Config();
    Battery_Config();
}

 /*
 * 函数名	：Battery_Read
 * 描述		：读取电池电量
 * 输入		：无
 * 输出		：无
 */
void Battery_Read(void)
{
	
	float voltage = battery.Battery_Value;
	
	//低于3.7V则启动低电量报警
	if(voltage < 3.0)											
		flag.battery_alarm = 0;												
	else 
		flag.battery_alarm = 1;
//	printf("battery:%f\n",battery.Battery_Value);
}

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
