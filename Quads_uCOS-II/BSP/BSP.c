/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��BSP.c
 * ����    	����ʼ�������õ�Ƭ��
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#include "includes.h"

/*
* ������		��SysTick_init
* ����		����ʼ����ʹ��SysTick��ʱ��
* ����		����
* ���		����
*/
void SysTick_init(void)
{
    SysTick_Config(SystemCoreClock / OS_TICKS_PER_SEC);//��ʼ����ʹ��SysTick��ʱ��
}

/*
* ������		��BSP_Init
* ����		����ʼ�������õ�Ƭ��
* ����		����
* ���		����
*/
void BSP_Init(void)
{
    SystemInit();
    SysTick_init();
	Battery_Init();
//	LED_Init();
//	IIC_Init();
	Debug_Init();
//	Motor_Init();
	Timer_Init();
}

/*
* ������		��LED_Init
* ����		����ʼ��LED
* ����		����
* ���		����
*/
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_SetBits(GPIOC, GPIO_Pin_13);
}




/************************* (C) COPYRIGHT 2017 G627 Team **************************/

