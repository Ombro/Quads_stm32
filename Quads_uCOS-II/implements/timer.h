/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：
 * 描述    	：
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
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
