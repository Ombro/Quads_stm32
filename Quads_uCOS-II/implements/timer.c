/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��
 * ����    	��
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#include "timer.h"


void TIM2_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 	//ʱ��TIM2ʹ��  
	
	TIM_TimeBaseStructure.TIM_Period = 72 - 1;
	TIM_TimeBaseStructure.TIM_Prescaler = 2-1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);					//�������жϱ�־ 
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
}


void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);
}

void Timer_Init(void)
{
	NVIC_Configuration();
	TIM2_Mode_Config();
}

void Timer_Start(void)
{
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

void Timer_End(void)
{
	TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
}

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
