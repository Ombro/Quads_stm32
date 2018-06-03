/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：Global_Variable_Struct.h
 * 描述    	：全局变量结构体  
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/


//MPU9250数据
typedef struct
{
	short Raw_Value[9];			//原始值
	float Motion_9[9];			//九轴数据
}MPU9250_Data;


//电池电量
typedef struct
{
	unsigned int Battery_Value;
	
}Battery;


//标志位
typedef struct
{
	volatile unsigned char battery_alarm;	//电量报警标记位
}Flag;


//电机pwm
typedef struct
{
	unsigned short pwm1; 
	unsigned short pwm2;
	unsigned short pwm3;
	unsigned short pwm4;
}Motor_PWM;


//每个轴对应的卡尔曼变量
typedef struct
{
	float omega;				//角速度
	float omega_error;			//角速度误差
	float estimate_angle;		//预测值	
	float observation_angle;	//观察值
	float A[2][2];				//状态转移矩阵
	float P[2][2];				//滤波器误差传递的协方差矩阵
	float Q[2][2];				//状态转移误差协方差矩阵
	float H[2];					//观察值为标量，状态列向量为矢量，所以H为一个二维行向量，[1 0]
	float R;					//观察角度方差（原为观测噪声协方差矩阵，但由于观察值为标量，所以R为标量，即是观察值的方差）
	float k_gain[2];			//卡尔曼增益
	float optimum_angle;		//最优角度
	float optimum_omega;		//最优角速度
}Axis;


//卡尔曼滤波
typedef struct
{
	Axis x;
	Axis y;
	Axis z;
	float dt;					//采样周期
}Kalman;


typedef struct
{
	float x[5];
	float y[5];
}PID_PARM;

typedef struct
{
	float target;
	float input;
	float output;
	float error_last;
	float error_cur;
	float omega_last;
	float increment;
}PID_VAL;

typedef struct
{
	PID_VAL core;
	PID_VAL shell;
}PID_CASCADE;

typedef struct
{
	PID_CASCADE x;
	PID_CASCADE y;
	float shell_t;
	float core_t;
}PID;

typedef struct
{
	float forward;
	float backward;
	float left;
	float right;
}MOVE;

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
