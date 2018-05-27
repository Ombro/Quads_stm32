/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：battery.h
 * 描述    	：battery.c的头文件
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "stm32f10x_gpio.h"
#include "stm32f10x_adc.h"
#include "Global_Variable_Struct.h"
#include "stdio.h"


static void ADC1_GPIO_Config(void);
static void Battery_Config(void);
void Battery_Init(void);
void Battery_Read(void);		//读取电池电量

#endif //__BATTERY_H__



/************************* (C) COPYRIGHT 2017 G627 Team **************************/
