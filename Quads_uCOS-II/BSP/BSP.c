/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：BSP.c
 * 描述    	：初始化并配置单片机
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "includes.h"

/*
* 函数名		：SysTick_init
* 描述		：初始化并使能SysTick定时器
* 输入		：无
* 输出		：无
*/
void SysTick_init(void)
{
    SysTick_Config(SystemCoreClock / OS_TICKS_PER_SEC);//初始化并使能SysTick定时器
}

/*
* 函数名		：BSP_Init
* 描述		：初始化并配置单片机
* 输入		：无
* 输出		：无
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
* 函数名		：LED_Init
* 描述		：初始化LED
* 输入		：无
* 输出		：无
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

