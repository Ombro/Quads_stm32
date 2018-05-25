/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：
 * 描述    	：        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#ifndef __IIC_H__
#define __IIC_H__

#include "includes.h"

#define 	SCL_PIN			GPIO_Pin_4									//定义SCL引脚
#define 	SDA_PIN 		GPIO_Pin_5									//定义SDA引脚				
#define 	GPIO_IIC		GPIOA										//定义IIC引脚组
#define 	RCC_GPIO_IIC	RCC_APB2Periph_GPIOA						//定义时钟


#define 	SCL_H()			GPIO_SetBits(GPIO_IIC , SCL_PIN)			//拉高SCL
#define 	SCL_L()			GPIO_ResetBits(GPIO_IIC , SCL_PIN)			//拉低SCL

#define 	SDA_H()			GPIO_SetBits(GPIO_IIC , SDA_PIN)			//拉高SDA
#define 	SDA_L()			GPIO_ResetBits(GPIO_IIC , SDA_PIN)			//拉低SDA

#define		SCL_read()		GPIO_ReadInputDataBit(GPIO_IIC , SCL_PIN)	//读取SCL引脚电平
#define 	SDA_read()		GPIO_ReadInputDataBit(GPIO_IIC , SDA_PIN)	//读取SDA引脚电平


//#define		IIC_delay() 	__NOP()										//IIC延迟



void IIC_delay(void);
void IIC_Init(void);													//配置IIC引脚
u8 IIC_Start(void);														//打开IIC总线
void IIC_Free(void);													//结束通讯，释放IIC总线
void IIC_ACK(void);														//允许从机应答
void IIC_NACK(void);													//不允许从机应答，即释放IIC总线
u8 IIC_Wait_ACK(void);													//判断从机是否返回ACK信号。返回为: 1-有ACK， 0-无ACK
void IIC_Send_Byte(unsigned char SendByte);								//发送一个字节（8Bit）的数据SendByte，从高位到低位
unsigned char IIC_Recive_Byte(void);									//返回从机传输的数据
unsigned char IIC_Single_Write(	unsigned char SlaveAddress,				//发送设备地址+写信号
								unsigned char REG_Address,
								unsigned char REG_data	);				
unsigned char IIC_Single_Read(	unsigned char SlaveAddress, 			//发送设备地址+读信号
								unsigned char REG_Address	);				
unsigned char IIC_Read(	u8 SlaveAddress, 								//读取从机一块连续地址上的数据
						u8 REG_Address, 
						u8 Length, u8 *buf);				
unsigned char IIC_Write_2_Byte(	u8 SlaveAddress, 						//向从机一个地址写入两个字节的数据
								u8 REG_Address, 
								short DataToWrite);
						  


#endif //__IIC_H__



/************************* (C) COPYRIGHT 2017 G627 Team **************************/
