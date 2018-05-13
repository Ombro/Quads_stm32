/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��battery.h
 * ����    	��battery.c��ͷ�ļ�
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
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
void Battery_Read(void);		//��ȡ��ص���

#endif //__BATTERY_H__



/************************* (C) COPYRIGHT 2017 G627 Team **************************/
