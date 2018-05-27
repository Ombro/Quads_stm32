/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：motor.h
 * 描述    	：motor.c的头文件        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "includes.h"

extern Motor_PWM motor_pwm;

void TIM3_GPIO_Config(void);
void TIM3_Mode_Config(void);
void Motor_Init(void);//PWM初始化
void SET_PWM(void);
void Motor_Out(u8 out1, u8 out2, u8 out3, u8 out4);


#endif //__MOTOR_H__




/************************* (C) COPYRIGHT 2017 G627 Team **************************/
