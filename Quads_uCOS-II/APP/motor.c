/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��motor.c
 * ����    	���������        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/
#include "motor.h"
#include "includes.h"


TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStructure;


 /*
 * ������	��TIM3_GPIO_Config
 * ����		��TIM3�������ã�PA6,PA7,PB0,PB1������Ӧͨ��1-4
 * ����		����
 * ���		����
 */
void TIM3_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

 /*
 * ������	��TIM3_Mode_Config
 * ����		����ʱ�����PWM����
 * ����		����
 * ���		����
 */
void TIM3_Mode_Config(void)
{
    
    TIM_TimeBaseStructure.TIM_Period = 7199; 							//��������Ϊ7199+1
    TIM_TimeBaseStructure.TIM_Prescaler = 0; 							//��Ԥ��Ƶ��72Mhz
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;				//ʱ�ӷ�Ƶϵ��������Ƶ
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 		//���ϼ���
    //TIM_TimeBaseStructure.TIM_RepetitionCounter = 0; 					//�ظ����0�η�������ж�
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 					//PWM1Ϊ���ϼ���ʱ��TIMx_CNT<TIMx_CCRn,�����Ч��ƽ��
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 			//��������ֵС��CCR1_Val1������ߵ�ƽ
	
	
	//ͨ��1
    TIM_OC1Init(TIM3, &TIM_OCInitStructure);							//ʹ��ͨ��1����PA6
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);					//ʹ�ܱȽϼĴ�����Ԥװ��
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 		//ʹ�����
	TIM_OCInitStructure.TIM_Pulse = 0; 									//��������ֵ���������ﵽ��ֵʱ����ƽ��������

	//ͨ��2
    TIM_OC2Init(TIM3, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
	
	//ͨ��3
    TIM_OC3Init(TIM3, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	
	//ͨ��4
    TIM_OC4Init(TIM3, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	TIM_Cmd(TIM3, ENABLE);
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);

}

 /*
 * ������	��Motor_Init
 * ����		����ʼ���������
 * ����		����
 * ���		����
 */
void Motor_Init(void)//PWM��ʼ��
{
    TIM3_GPIO_Config();
    TIM3_Mode_Config();
}

 /*
 * ������	��Motor_Out
 * ����		�����pwm���
 * ����		��out1	�����1PWM(0-7199)
			  out2	�����2PWM
			  out3	�����3PWM
			  out4	�����4PWM
 * ���		����
 */
void Motor_Out(u8 out1, u8 out2, u8 out3, u8 out4)
{
	motor_pwm.pwm1=out1;
	motor_pwm.pwm2=out2;
	motor_pwm.pwm3=out3;
	motor_pwm.pwm4=out4;
	SET_PWM();
}

 /*
 * ������	��SET_PWM
 * ����		�����ö�ʱ��pwm����
 * ����		����
 * ���		����
 */
void SET_PWM(void)
{
    TIM_OC1Init(TIM3, &TIM_OCInitStructure);							//ʹ��ͨ��1����PA6
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);					//ʹ�ܱȽϼĴ�����Ԥװ��
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 		//ʹ�����
	TIM_OCInitStructure.TIM_Pulse = motor_pwm.pwm1;						//��������ֵ���������ﵽ��ֵʱ����ƽ��������

	//ͨ��2
    TIM_OC2Init(TIM3, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = motor_pwm.pwm2;
	
	//ͨ��3
    TIM_OC3Init(TIM3, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = motor_pwm.pwm3;
	
	//ͨ��4
    TIM_OC4Init(TIM3, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = motor_pwm.pwm4;
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	TIM_Cmd(TIM3, ENABLE);
	
}


/************************* (C) COPYRIGHT 2017 G627 Team **************************/
