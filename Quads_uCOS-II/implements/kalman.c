/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��kalman.c
 * ����    	���������˲�        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#include "kalman.h"

extern Kalman kalman;

 /*
 * ������	��set_param
 * ����		�����ÿ���������ֵ
 * ����		����
 * ���		����
 */
void set_param(void)
{
	kalman.dt = 0.001;				//��������

//	x�����
	kalman.x.H[0]=1;				//�۲ⷽ���е�H����
	kalman.x.H[1]=0;
	
	kalman.x.A[0][0]=1;				//״̬ת�ƾ���
	kalman.x.A[0][1]=-0.001;		//��������dt
	kalman.x.A[1][0]=0;
	kalman.x.A[1][1]=1;
	
	kalman.x.Q[0][0]=0.005;			//�˲������ת�Ƶ����Э�������
	kalman.x.Q[0][1]=0;		
	kalman.x.Q[1][0]=0;
	kalman.x.Q[1][1]=0.005;
	
	kalman.x.R=0.03;				//�۲�Ƕȷ���
	
	kalman.x.omega_error=0.003;		//���ٶ����
	
	
	
//	y�����
	kalman.y.H[0]=1;
	kalman.y.H[1]=0;
	
	kalman.y.A[0][0]=1;
	kalman.y.A[0][1]=-0.001;
	kalman.y.A[1][0]=0;
	kalman.y.A[1][1]=1;
	
	kalman.y.Q[0][0]=0.005;
	kalman.y.Q[0][1]=0;
	kalman.y.Q[1][0]=0;
	kalman.y.Q[1][1]=0.005;
	
	kalman.y.R=0.03;
	
	kalman.y.omega_error=0.003;	
	
	
//	z�����
	kalman.z.H[0]=1;
	kalman.z.H[1]=0;
	
	kalman.z.A[0][0]=1;
	kalman.z.A[0][1]=-0.001;	
	kalman.z.A[1][0]=0;
	kalman.z.A[1][1]=1;
	
	kalman.z.Q[0][0]=0.005;
	kalman.z.Q[0][1]=0;
	kalman.z.Q[1][0]=0;
	kalman.z.Q[1][1]=0.005;
	
	kalman.z.R=0.03;
	
	kalman.z.omega_error=0.003;
}

void kalman_filter(void)
{
	float temp1, temp2, temp3, temp4;
	
//	x��
//	��һ���������������
	kalman.x.estimate_angle += (kalman.x.omega - kalman.x.omega_error) * kalman.dt;
	
//	�ڶ���,�����˲������ݵ�Э�������
	temp1 = kalman.x.P[0][0];
	temp2 = kalman.x.P[0][1];
	temp3 = kalman.x.P[1][0];
	temp4 = kalman.x.P[1][1];
	
	kalman.x.P[0][0] = temp1 - temp3 * kalman.dt - kalman.dt * (temp2 - temp4 * kalman.dt) + kalman.x.Q[0][0];
	kalman.x.P[0][1] = temp2 - temp4 * kalman.dt + kalman.x.Q[0][1];
	kalman.x.P[1][0] = temp3 - temp4 * kalman.dt + temp3;
	kalman.x.P[1][1] = temp4 + kalman.x.Q[1][1];
	
//	�����������㿨��������
	kalman.x.k_gain[0] = kalman.x.P[0][0] / (kalman.x.P[0][0] + kalman.x.R);
	kalman.x.k_gain[1] = kalman.x.P[1][0] / (kalman.x.P[1][0] + kalman.x.R);

//	���Ĳ�����������
	kalman.x.optimum_angle = kalman.x.observation_angle + kalman.x.k_gain[0] * (kalman.x.observation_angle - kalman.x.estimate_angle);
	kalman.x.omega_error = kalman.x.omega_error + kalman.x.k_gain[1] * (kalman.x.observation_angle - kalman.x.estimate_angle);
	kalman.x.optimum_omega = kalman.x.omega - kalman.x.omega_error;
	
//	���岽���������Э����
	temp1 = kalman.x.P[0][0];
	temp2 = kalman.x.P[0][1];
	temp3 = kalman.x.P[1][0];
	temp4 = kalman.x.P[1][1];
	
	kalman.x.P[0][0] -= kalman.x.k_gain[0] * temp1;
	kalman.x.P[0][1] -= kalman.x.k_gain[0] * temp2;
	kalman.x.P[1][0] -= kalman.x.k_gain[1] * temp1;
	kalman.x.P[1][1] -= kalman.x.k_gain[1] * temp2;
	
	
//	y��
	kalman.y.estimate_angle += (kalman.y.omega - kalman.y.omega_error) * kalman.dt;
	
	temp1 = kalman.y.P[0][0];
	temp2 = kalman.y.P[0][1];
	temp3 = kalman.y.P[1][0];
	temp4 = kalman.y.P[1][1];
	
	kalman.y.P[0][0] = temp1 - temp3 * kalman.dt - kalman.dt * (temp2 - temp4 * kalman.dt) + kalman.y.Q[0][0];
	kalman.y.P[0][1] = temp2 - temp4 * kalman.dt + kalman.y.Q[0][1];
	kalman.y.P[1][0] = temp3 - temp4 * kalman.dt + temp3;
	kalman.y.P[1][1] = temp4 + kalman.y.Q[1][1];
	
	kalman.y.k_gain[0] = kalman.y.P[0][0] / (kalman.y.P[0][0] + kalman.y.R);
	kalman.y.k_gain[1] = kalman.y.P[1][0] / (kalman.y.P[1][0] + kalman.y.R);

	kalman.y.optimum_angle = kalman.y.observation_angle + kalman.y.k_gain[0] * (kalman.y.observation_angle - kalman.y.estimate_angle);
	kalman.y.omega_error = kalman.y.omega_error + kalman.y.k_gain[1] * (kalman.y.observation_angle - kalman.y.estimate_angle);
	kalman.y.optimum_omega = kalman.y.omega - kalman.y.omega_error;
	
	temp1 = kalman.y.P[0][0];
	temp2 = kalman.y.P[0][1];
	temp3 = kalman.y.P[1][0];
	temp4 = kalman.y.P[1][1];
	
	kalman.y.P[0][0] -= kalman.y.k_gain[0] * temp1;
	kalman.y.P[0][1] -= kalman.y.k_gain[0] * temp2;
	kalman.y.P[1][0] -= kalman.y.k_gain[1] * temp1;
	kalman.y.P[1][1] -= kalman.y.k_gain[1] * temp2;
	
	
//	z��
	kalman.z.estimate_angle += (kalman.z.omega - kalman.z.omega_error) * kalman.dt;
	
	temp1 = kalman.z.P[0][0];
	temp2 = kalman.z.P[0][1];
	temp3 = kalman.z.P[1][0];
	temp4 = kalman.z.P[1][1];
	
	kalman.z.P[0][0] = temp1 - temp3 * kalman.dt - kalman.dt * (temp2 - temp4 * kalman.dt) + kalman.z.Q[0][0];
	kalman.z.P[0][1] = temp2 - temp4 * kalman.dt + kalman.z.Q[0][1];
	kalman.z.P[1][0] = temp3 - temp4 * kalman.dt + temp3;
	kalman.z.P[1][1] = temp4 + kalman.z.Q[1][1];
	
	kalman.z.k_gain[0] = kalman.z.P[0][0] / (kalman.z.P[0][0] + kalman.z.R);
	kalman.z.k_gain[1] = kalman.z.P[1][0] / (kalman.z.P[1][0] + kalman.z.R);

	kalman.z.optimum_angle = kalman.z.observation_angle + kalman.z.k_gain[0] * (kalman.z.observation_angle - kalman.z.estimate_angle);
	kalman.z.omega_error = kalman.z.omega_error + kalman.z.k_gain[1] * (kalman.z.observation_angle - kalman.z.estimate_angle);
	kalman.z.optimum_omega = kalman.z.omega - kalman.z.omega_error;
	
	temp1 = kalman.z.P[0][0];
	temp2 = kalman.z.P[0][1];
	temp3 = kalman.z.P[1][0];
	temp4 = kalman.z.P[1][1];
	
	kalman.z.P[0][0] -= kalman.z.k_gain[0] * temp1;
	kalman.z.P[0][1] -= kalman.z.k_gain[0] * temp2;
	kalman.z.P[1][0] -= kalman.z.k_gain[1] * temp1;
	kalman.z.P[1][1] -= kalman.z.k_gain[1] * temp2;	
}

/************************* (C) COPYRIGHT 2017 G627 Team **************************/

