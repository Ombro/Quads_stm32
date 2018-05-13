/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：Global_Variable_Struct.c
 * 描述    	：全局变量结构体 
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/
#include "Global_Variable_Struct.h"

//MPU9250数据
MPU9250_Data mpu;

//电池
Battery battery;

//标志位
Flag flag;

//电机pwm
Motor_PWM motor_pwm;

//卡尔曼滤波变量
Kalman kalman;

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
