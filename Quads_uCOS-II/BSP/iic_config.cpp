#include "includes.h"
void I2C2_Init(u32 MASTER_ADDRESS = 0X0A)
{
	/*GPIO��IIC��ʼ���ṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	I2C_InitTypeDef I2C_InitStructure;
	
	/*GPIO��IICʱ��ʹ��*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );		//GPIOBʱ��ʹ��
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_I2C2, ENABLE );		//IIC2ʱ��ʹ��

	/*��ʼ��GPIO*/
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11;	//��ʼ��GPIO.B10(IIC2_SCL)��GPIO.B11(IIC2_SDA)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			//�������ٶ�50Hz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;				//�������ģʽΪ���ù��ܿ�©���
	GPIO_Init( GPIOB, &GPIO_InitStructure );					//����GPIO��ʼ���ṹ���ʼ��GPIOB
	
	/*��ʼ��IIC2*/
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;					//����ΪIICģʽ
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;			//����IIC��ռ�ձȣ��͵�ƽ���Ըߵ�ƽֵΪ2
	I2C_InitStructure.I2C_OwnAddress1 = MASTER_ADDRESS;					//����STM32�����ַΪ7λ��ַ�����������ã�
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;					//ʹ��ACK�ź�
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;	//ָ��7λ��ַ
	I2C_InitStructure.I2C_ClockSpeed = 400000;					//ʱ��Ƶ�ʣ�����С�ڵ���400KHz
	
	I2C_Cmd( I2C2, ENABLE );   									//ʹ��IIC2
	I2C_Init( I2C2, &I2C_InitStructure );						//����IIC��ʼ���ṹ���ʼ��IIC2
	
	/*����һ�ֽ�һӦ��ģʽ*/
	I2C_AcknowledgeConfig( I2C2, ENABLE );  					//ʹ��IIC2Ӧ��״̬  
}