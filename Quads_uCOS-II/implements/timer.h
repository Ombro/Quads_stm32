/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��
 * ����    	��
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#ifndef __TIMER_H__
#define __TIMER_H__

#include "includes.h"

void NVIC_Configuration(void);  
void TIM2_Mode_Config(void);
void Timer_Init(void);
void Timer_Start(void);
void Timer_End(void);


#endif //__TIMER_H__


/************************* (C) COPYRIGHT 2017 G627 Team **************************/
