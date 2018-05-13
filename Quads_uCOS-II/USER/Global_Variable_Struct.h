/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��Global_Variable_Struct.h
 * ����    	��ȫ�ֱ����ṹ��  
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/


//MPU9250����
typedef struct
{
	short Raw_Value[9];			//ԭʼֵ
	float Motion_9[9];			//��������
}MPU9250_Data;


//��ص���
typedef struct
{
	unsigned int Battery_Value;
	
}Battery;


//��־λ
typedef struct
{
	volatile unsigned char battery_alarm;	//�����������λ
}Flag;


//���pwm
typedef struct
{
	unsigned char pwm1; 
	unsigned char pwm2;
	unsigned char pwm3;
	unsigned char pwm4;
}Motor_PWM;


//ÿ�����Ӧ�Ŀ���������
typedef struct
{
	float omega;				//���ٶ�
	float omega_error;			//���ٶ����
	float estimate_angle;		//Ԥ��ֵ	
	float observation_angle;	//�۲�ֵ
	float A[2][2];				//״̬ת�ƾ���
	float P[2][2];				//�˲������ݵ�Э�������
	float Q[2][2];				//״̬ת�����Э�������
	float H[2];					//�۲�ֵΪ������״̬������Ϊʸ��������HΪһ����ά��������[1 0]
	float R;					//�۲�Ƕȷ��ԭΪ�۲�����Э������󣬵����ڹ۲�ֵΪ����������RΪ���������ǹ۲�ֵ�ķ��
	float k_gain[2];			//����������
	float optimum_angle;		//���ŽǶ�
	float optimum_omega;		//���Ž��ٶ�
}Axis;


//�������˲�
typedef struct
{
	Axis x;
	Axis y;
	Axis z;
	float dt;					//��������
}Kalman;


//PID���Ʋ���
typedef struct
{
	float Kp;
	float Ki;
	float Kd;
}PID;

/************************* (C) COPYRIGHT 2017 G627 Team **************************/