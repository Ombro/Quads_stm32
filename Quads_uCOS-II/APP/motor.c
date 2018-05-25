/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：motor.c
 * 描述    	：电机控制        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/
#include "motor.h"
#include "includes.h"


TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStructure;


 /*
 * 函数名	：TIM3_GPIO_Config
 * 描述		：TIM3引脚配置（PA6,PA7,PB0,PB1），对应通道1-4
 * 输入		：无
 * 输出		：无
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
 * 函数名	：TIM3_Mode_Config
 * 描述		：定时器输出PWM配置
 * 输入		：无
 * 输出		：无
 */
void TIM3_Mode_Config(void)
{
    
    TIM_TimeBaseStructure.TIM_Period = 7199; 							//脉冲周期为7199+1
    TIM_TimeBaseStructure.TIM_Prescaler = 0; 							//不预分频，72Mhz
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;				//时钟分频系数，不分频
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 		//向上计数
    //TIM_TimeBaseStructure.TIM_RepetitionCounter = 0; 					//重复溢出0次发生溢出中断
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 					//PWM1为向上计数时，TIMx_CNT<TIMx_CCRn,输出有效电平。
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 			//计数器数值小于CCR1_Val1是输出高电平
	
	
	//通道1
    TIM_OC1Init(TIM3, &TIM_OCInitStructure);							//使能通道1，即PA6
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);					//使能比较寄存器的预装载
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 		//使能输出
	TIM_OCInitStructure.TIM_Pulse = 0; 									//设置跳变值，计数器达到此值时，电平发生跳变

	//通道2
    TIM_OC2Init(TIM3, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
	
	//通道3
    TIM_OC3Init(TIM3, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	
	//通道4
    TIM_OC4Init(TIM3, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	TIM_Cmd(TIM3, ENABLE);
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);

}

 /*
 * 函数名	：Motor_Init
 * 描述		：初始化电机配置
 * 输入		：无
 * 输出		：无
 */
void Motor_Init(void)//PWM初始化
{
    TIM3_GPIO_Config();
    TIM3_Mode_Config();
}

 /*
 * 函数名	：Motor_Out
 * 描述		：电机pwm输出
 * 输入		：out1	：电机1PWM(0-7199)
			  out2	：电机2PWM
			  out3	：电机3PWM
			  out4	：电机4PWM
 * 输出		：无
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
 * 函数名	：SET_PWM
 * 描述		：配置定时器pwm脉宽
 * 输入		：无
 * 输出		：无
 */
void SET_PWM(void)
{
    TIM_OC1Init(TIM3, &TIM_OCInitStructure);							//使能通道1，即PA6
    TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);					//使能比较寄存器的预装载
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 		//使能输出
	TIM_OCInitStructure.TIM_Pulse = motor_pwm.pwm1;						//设置跳变值，计数器达到此值时，电平发生跳变

	//通道2
    TIM_OC2Init(TIM3, &TIM_OCInitStructure);
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = motor_pwm.pwm2;
	
	//通道3
    TIM_OC3Init(TIM3, &TIM_OCInitStructure);
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = motor_pwm.pwm3;
	
	//通道4
    TIM_OC4Init(TIM3, &TIM_OCInitStructure);
    TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = motor_pwm.pwm4;
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	TIM_Cmd(TIM3, ENABLE);
	
}


/************************* (C) COPYRIGHT 2017 G627 Team **************************/
