/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��ctrl.h
 * ����    	��
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/
#ifndef __CTRL_H__
#define __CTRL_H__

#include "includes.h"

#define math_limit(num,max,min)	((num)>max?max:(num)<min?min:(num))		//�����޷�
#define increment_max			 20
#define increment_min			-20

extern PID pid;


void calculate_target(void);
void shell_pid(float arr[], PID_VAL pid_val, float t);
void core_pid(float arr[], PID_VAL pid_val, float t, float omega, float input);
void control(void);

#endif //__CTRL_H__

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
