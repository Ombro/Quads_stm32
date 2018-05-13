/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��
 * ����    	��        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#ifndef __IIC_H__
#define __IIC_H__

#include "includes.h"

#define 	SCL_PIN			GPIO_Pin_4									//����SCL����
#define 	SDA_PIN 		GPIO_Pin_5									//����SDA����				
#define 	GPIO_IIC		GPIOA										//����IIC������
#define 	RCC_GPIO_IIC	RCC_APB2Periph_GPIOA						//����ʱ��


#define 	SCL_H()			GPIO_SetBits(GPIO_IIC , SCL_PIN)			//����SCL
#define 	SCL_L()			GPIO_ResetBits(GPIO_IIC , SCL_PIN)			//����SCL

#define 	SDA_H()			GPIO_SetBits(GPIO_IIC , SDA_PIN)			//����SDA
#define 	SDA_L()			GPIO_ResetBits(GPIO_IIC , SDA_PIN)			//����SDA

#define		SCL_read()		GPIO_ReadInputDataBit(GPIO_IIC , SCL_PIN)	//��ȡSCL���ŵ�ƽ
#define 	SDA_read()		GPIO_ReadInputDataBit(GPIO_IIC , SDA_PIN)	//��ȡSDA���ŵ�ƽ


//#define		IIC_delay() 	__NOP()										//IIC�ӳ�



void IIC_delay(void);
void IIC_Init(void);													//����IIC����
u8 IIC_Start(void);														//��IIC����
void IIC_Free(void);													//����ͨѶ���ͷ�IIC����
void IIC_ACK(void);														//����ӻ�Ӧ��
void IIC_NACK(void);													//������ӻ�Ӧ�𣬼��ͷ�IIC����
u8 IIC_Wait_ACK(void);													//�жϴӻ��Ƿ񷵻�ACK�źš�����Ϊ: 1-��ACK�� 0-��ACK
void IIC_Send_Byte(unsigned char SendByte);								//����һ���ֽڣ�8Bit��������SendByte���Ӹ�λ����λ
unsigned char IIC_Recive_Byte(void);									//���شӻ����������
unsigned char IIC_Single_Write(	unsigned char SlaveAddress,				//�����豸��ַ+д�ź�
								unsigned char REG_Address,
								unsigned char REG_data	);				
unsigned char IIC_Single_Read(	unsigned char SlaveAddress, 			//�����豸��ַ+���ź�
								unsigned char REG_Address	);				
unsigned char IIC_Read(	u8 SlaveAddress, 								//��ȡ�ӻ�һ��������ַ�ϵ�����
						u8 REG_Address, 
						u8 Length, u8 *buf);				
unsigned char IIC_Write_2_Byte(	u8 SlaveAddress, 						//��ӻ�һ����ַд�������ֽڵ�����
								u8 REG_Address, 
								short DataToWrite);
						  


#endif //__IIC_H__



/************************* (C) COPYRIGHT 2017 G627 Team **************************/
