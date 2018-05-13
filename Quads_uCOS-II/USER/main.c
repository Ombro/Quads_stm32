/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：main.c
 * 描述    	：主函数
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "includes.h"

static OS_STK task_LED1_stk[LED_TASK_STK_SIZE];
static OS_STK task_LED2_stk[LED_TASK_STK_SIZE];
static OS_STK task_LED3_stk[LED_TASK_STK_SIZE];

extern u8 data[18];


/*
* 函数名	：main
* 描述		：主函数
* 输入		：无
* 输出		：无
*/
int main(void)
{
    BSP_Init();
    OSInit();
    OSTaskCreate(   Task_LED1,
                    (void *)0,
                    &task_LED1_stk[LED_TASK_STK_SIZE - 1],
                    LED1_FRIO
                );

//    OSTaskCreate(   Task_LED2,
//                    (void *)0,
//                    &task_LED2_stk[LED_TASK_STK_SIZE - 1],
//                    LED2_FRIO
//                );
//
//    OSTaskCreate(   Task_LED3,
//                    (void *)0,
//                    &task_LED3_stk[LED_TASK_STK_SIZE - 1],
//                    LED3_FRIO
//                );
    OSStart();

}






/************************* (C) COPYRIGHT 2017 G627 Team **************************/



