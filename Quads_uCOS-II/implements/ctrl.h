/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：ctrl.h
 * 描述    	：
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/
#ifndef __CTRL_H__
#define __CTRL_H__

#include "includes.h"

#define math_limit(num,max,min)	((num)>max?max:(num)<min?min:(num))		//积分限幅
#define increment_max			 20
#define increment_min			-20

extern PID pid;


void calculate_target(void);
void shell_pid(float arr[], PID_VAL pid_val, float t);
void core_pid(float arr[], PID_VAL pid_val, float t, float omega, float input);
void control(void);

#endif //__CTRL_H__

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
