/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：app.h
 * 描述    	：app.c的头文件        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#ifndef __APP_H__
#define __APP_H__

static OS_STK task_LED1_stk[LED_TASK_STK_SIZE];
static OS_STK task_LED2_stk[LED_TASK_STK_SIZE];
static OS_STK task_LED3_stk[LED_TASK_STK_SIZE];

void Task_LED1(void *p_arg);
void Task_LED2(void *p_arg);
//void Task_LED3(void *p_arg);


#endif



/************************* (C) COPYRIGHT 2017 G627 Team **************************/

