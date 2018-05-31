/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��
 * ����    	��        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#include "mpu9250.h"

 /*
 * ������	��MPU9250_Get_Raw_Data
 * ����		����ȡ9��ԭʼ����
 * ����		��Raw_Buff	�����ԭʼ���ݵ�����
 * ���		����
 */
void MPU9250_Get_Raw_Data(short *Raw_Buff)
{
	u8 i=0;
	u8 temp[18]={0};
	IIC_Read(0x50, AX, 18, temp);
	for(i=0;i<18;i+=2)
	{
		Raw_Buff[i/2] = ((((short)temp[i+1]) << 8) | temp[i]);
	}
}
 /*
 * ������	��MPU9250_Get_Offset9
 * ����		����ȡƫ��ֵ
 * ����		��MPU9250_Offset	�����ƫ��ֵ���飬����У����ʼ��̬
 * ���		����
 */
void MPU9250_Get_Offset9(short *MPU9250_Offset)
{
	u8 i;
	u8 temp[18]={0};
	IIC_Read(0x50, AXOFFSET, 18, temp);
	for(i=0;i<18;i+=2)
	{
		MPU9250_Offset[i/2] = ((((short)temp[i+1]) << 8) | temp[i]);
	}
	printf("%d\n",MPU9250_Offset[0]);
}	

 /*
 * ������	��MPU9250_Calibration
 * ����		��У׼
 * ����		����
 * ���		����
 */
void MPU9250_Calibration(void)
{
	//���ٶȼ�У׼
	IIC_Write_2_Byte(0x50, CALSW, 0x0001);
	delay_us(1000000);
	IIC_Write_2_Byte(0x50, SAVE, 0x0000);
	IIC_Write_2_Byte(0x50, CALSW, 0x0000);
	
	//�ų�У׼
//	IIC_Write_2_Byte(0x50, SAVE, 0x0000);
//	IIC_Write_2_Byte(0x50, CALSW, 0x0002);
//	delay_us(1000000);
//	IIC_Write_2_Byte(0x50, CALSW, 0x0000);
//	IIC_Write_2_Byte(0x50, SAVE, 0x0000);
	
	//�߶�����
//	IIC_Write_2_Byte(0x50, CALSW, 0x0003);
//	delay_us(1000000);
//	IIC_Write_2_Byte(0x50, SAVE, 0x0000);
//	IIC_Write_2_Byte(0x50, CALSW, 0x0000);
}

 /*
 * ������	��MPU9250_Get_Motion9
 * ����		��
 * ����		����
 * ���		����
 */
void MPU9250_Get_Motion9(float *MPU9250_Buff)
{
	u8 i;
	short raw_data[9]={0};
	MPU9250_Get_Raw_Data(raw_data);
	for(i=0;i<3;i++)
	{
		MPU9250_Buff[i]=(float)raw_data[i] * 16.0 * 9.8 / 32768.0;
	}
	for(i=3;i<6;i++)
	{
		MPU9250_Buff[i]=(float)raw_data[i] * 2000.0 / 32768.0;
	}
	for(i=6;i<9;i++)
	{
		MPU9250_Buff[i]=(float)raw_data[i];
	}
}

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
