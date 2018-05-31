/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��ctrl.c
 * ����    	��
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/
#include "ctrl.h"

void shell_pid(float arr[], PID_VAL pid_val, float t)
{
	float Kp_out, Ki_out;
	
	//�������
	pid_val.error_cur = pid_val.target - pid_val.input;
	Kp_out = arr[0] * pid_val.error_cur;
	
	//���������
	pid_val.increment += pid_val.error_cur * t;
	
	//�����޷�����ֹ����Ư��
	pid_val.increment = math_limit(pid_val.increment, increment_max, increment_min);
	Ki_out = arr[1] * pid_val.increment;
	
	//PID�⻷���
	pid_val.output = Kp_out + Ki_out;
}

void core_pid(float arr[], PID_VAL pid_val, float t, float omega, float input)
{
	float Kp_out, Ki_out, Kd_out;
	
	//�������
	pid_val.error_cur = pid_val.target - input;
	Kp_out = arr[2] * pid_val.error_cur;
	
	//���������
	pid_val.increment += pid_val.error_cur * t;
	
	//�����޷�
	pid_val.increment = math_limit(pid_val.increment, increment_max, increment_min);
	Ki_out = arr[3] * pid_val.increment;
	
	//PID�ڻ����
	Kd_out = arr[4] * (omega - pid_val.omega_last);
	pid_val.output = Kp_out + Ki_out + Kd_out;
}

void control(void)
{
	
}

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
