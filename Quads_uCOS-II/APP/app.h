/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��app.h
 * ����    	��app.c��ͷ�ļ�        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
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

