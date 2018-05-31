/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：ctrl.c
 * 描述    	：
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/
#include "ctrl.h"

void shell_pid(float arr[], PID_VAL pid_val, float t)
{
	float Kp_out, Ki_out;
	
	//计算误差
	pid_val.error_cur = pid_val.target - pid_val.input;
	Kp_out = arr[0] * pid_val.error_cur;
	
	//计算积分项
	pid_val.increment += pid_val.error_cur * t;
	
	//积分限幅，防止积分漂移
	pid_val.increment = math_limit(pid_val.increment, increment_max, increment_min);
	Ki_out = arr[1] * pid_val.increment;
	
	//PID外环输出
	pid_val.output = Kp_out + Ki_out;
}

void core_pid(float arr[], PID_VAL pid_val, float t, float omega, float input)
{
	float Kp_out, Ki_out, Kd_out;
	
	//计算误差
	pid_val.error_cur = pid_val.target - input;
	Kp_out = arr[2] * pid_val.error_cur;
	
	//计算积分项
	pid_val.increment += pid_val.error_cur * t;
	
	//积分限幅
	pid_val.increment = math_limit(pid_val.increment, increment_max, increment_min);
	Ki_out = arr[3] * pid_val.increment;
	
	//PID内环输出
	Kd_out = arr[4] * (omega - pid_val.omega_last);
	pid_val.output = Kp_out + Ki_out + Kd_out;
}

void control(void)
{
	
}

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
