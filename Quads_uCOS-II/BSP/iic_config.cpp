#include "includes.h"
void I2C2_Init(u32 MASTER_ADDRESS = 0X0A)
{
	/*GPIO与IIC初始化结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;
	I2C_InitTypeDef I2C_InitStructure;
	
	/*GPIO与IIC时钟使能*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );		//GPIOB时钟使能
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_I2C2, ENABLE );		//IIC2时钟使能

	/*初始化GPIO*/
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11;	//初始化GPIO.B10(IIC2_SCL)，GPIO.B11(IIC2_SDA)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			//最高输出速度50Hz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;				//输入输出模式为复用功能开漏输出
	GPIO_Init( GPIOB, &GPIO_InitStructure );					//根据GPIO初始化结构体初始化GPIOB
	
	/*初始化IIC2*/
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;					//设置为IIC模式
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;			//设置IIC的占空比，低电平除以高电平值为2
	I2C_InitStructure.I2C_OwnAddress1 = MASTER_ADDRESS;					//设置STM32本身地址为7位地址（可任意设置）
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;					//使能ACK信号
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;	//指定7位地址
	I2C_InitStructure.I2C_ClockSpeed = 400000;					//时钟频率，必须小于等于400KHz
	
	I2C_Cmd( I2C2, ENABLE );   									//使能IIC2
	I2C_Init( I2C2, &I2C_InitStructure );						//根据IIC初始化结构体初始化IIC2
	
	/*允许一字节一应答模式*/
	I2C_AcknowledgeConfig( I2C2, ENABLE );  					//使能IIC2应答状态  
}