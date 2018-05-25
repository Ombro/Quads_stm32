/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：kalman.c
 * 描述    	：卡尔曼滤波        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "kalman.h"

extern Kalman kalman;

 /*
 * 函数名	：set_param
 * 描述		：设置卡尔曼参数值
 * 输入		：无
 * 输出		：无
 */
void set_param(void)
{
	kalman.dt = 0.001;				//采样周期

//	x轴参数
	kalman.x.H[0]=1;				//观测方程中的H矩阵
	kalman.x.H[1]=0;
	
	kalman.x.A[0][0]=1;				//状态转移矩阵
	kalman.x.A[0][1]=-0.001;		//采样周期dt
	kalman.x.A[1][0]=0;
	kalman.x.A[1][1]=1;
	
	kalman.x.Q[0][0]=0.005;			//滤波器误差转移的误差协方差矩阵
	kalman.x.Q[0][1]=0;		
	kalman.x.Q[1][0]=0;
	kalman.x.Q[1][1]=0.005;
	
	kalman.x.R=0.03;				//观察角度方差
	
	kalman.x.omega_error=0.003;		//角速度误差
	
	
	
//	y轴参数
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
	
	
//	z轴参数
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
	
//	x轴
//	第一步，计算先验估计
	kalman.x.estimate_angle += (kalman.x.omega - kalman.x.omega_error) * kalman.dt;
	
//	第二步,计算滤波器误差传递的协方差矩阵
	temp1 = kalman.x.P[0][0];
	temp2 = kalman.x.P[0][1];
	temp3 = kalman.x.P[1][0];
	temp4 = kalman.x.P[1][1];
	
	kalman.x.P[0][0] = temp1 - temp3 * kalman.dt - kalman.dt * (temp2 - temp4 * kalman.dt) + kalman.x.Q[0][0];
	kalman.x.P[0][1] = temp2 - temp4 * kalman.dt + kalman.x.Q[0][1];
	kalman.x.P[1][0] = temp3 - temp4 * kalman.dt + temp3;
	kalman.x.P[1][1] = temp4 + kalman.x.Q[1][1];
	
//	第三步，计算卡尔曼增益
	kalman.x.k_gain[0] = kalman.x.P[0][0] / (kalman.x.P[0][0] + kalman.x.R);
	kalman.x.k_gain[1] = kalman.x.P[1][0] / (kalman.x.P[1][0] + kalman.x.R);

//	第四步，修正估计
	kalman.x.optimum_angle = kalman.x.observation_angle + kalman.x.k_gain[0] * (kalman.x.observation_angle - kalman.x.estimate_angle);
	kalman.x.omega_error = kalman.x.omega_error + kalman.x.k_gain[1] * (kalman.x.observation_angle - kalman.x.estimate_angle);
	kalman.x.optimum_omega = kalman.x.omega - kalman.x.omega_error;
	
//	第五步，更新误差协方差
	temp1 = kalman.x.P[0][0];
	temp2 = kalman.x.P[0][1];
	temp3 = kalman.x.P[1][0];
	temp4 = kalman.x.P[1][1];
	
	kalman.x.P[0][0] -= kalman.x.k_gain[0] * temp1;
	kalman.x.P[0][1] -= kalman.x.k_gain[0] * temp2;
	kalman.x.P[1][0] -= kalman.x.k_gain[1] * temp1;
	kalman.x.P[1][1] -= kalman.x.k_gain[1] * temp2;
	
	
//	y轴
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
	
	
//	z轴
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

