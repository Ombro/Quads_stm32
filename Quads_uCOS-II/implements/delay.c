/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：delay.c
 * 描述    	：存放延时函数        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "delay.h"

 /*
 * 函数名	：delay_us
 * 描述		：us延时函数
 * 输入		：count		：延时的us
 * 输出		：无
 */
void delay_us(u32 count)
{
	u32 Counter = 11.5 * count;
	while(Counter)
		Counter--;
}



/************************* (C) COPYRIGHT 2017 G627 Team **************************/

