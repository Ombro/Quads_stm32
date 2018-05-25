/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：app_cfg.h
 * 描述    	：这个头文件主要用来规定任务优先级和栈的空间大小        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#ifndef __APP_CFG_H__
#define __APP_CFG_H__


 /*******************设置任务优先级*******************/
#define STARTUP_TASK_FRIO           4
#define LED1_FRIO                   5
#define LED2_FRIO                   6
#define LED3_FRIO                   7



/*************设置栈大小（单位 OS_STK）***************/
#define STARTUP_TASK_STK_SIZE       80
#define LED_TASK_STK_SIZE           80

#endif




/************************* (C) COPYRIGHT 2017 G627 Team **************************/


