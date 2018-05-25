/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：
 * 描述    	：        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "mpu9250.h"

 /*
 * 函数名	：MPU9250_Get_Raw_Data
 * 描述		：获取9轴原始数据
 * 输入		：无
 * 输出		：无
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
 * 函数名	：MPU9250_Get_Offset9
 * 描述		：读取偏差值
 * 输入		：无
 * 输出		：无
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
 * 函数名	：MPU9250_Calibration
 * 描述		：校准
 * 输入		：无
 * 输出		：无
 */
void MPU9250_Calibration(void)
{
	//加速度计校准
	IIC_Write_2_Byte(0x50, CALSW, 0x0001);
	delay_us(1000000);
	IIC_Write_2_Byte(0x50, SAVE, 0x0000);
	IIC_Write_2_Byte(0x50, CALSW, 0x0000);
	
	//磁场校准
//	IIC_Write_2_Byte(0x50, SAVE, 0x0000);
//	IIC_Write_2_Byte(0x50, CALSW, 0x0002);
//	delay_us(1000000);
//	IIC_Write_2_Byte(0x50, CALSW, 0x0000);
//	IIC_Write_2_Byte(0x50, SAVE, 0x0000);
	
	//高度置零
//	IIC_Write_2_Byte(0x50, CALSW, 0x0003);
//	delay_us(1000000);
//	IIC_Write_2_Byte(0x50, SAVE, 0x0000);
//	IIC_Write_2_Byte(0x50, CALSW, 0x0000);
}

 /*
 * 函数名	：MPU9250_Get_Motion9
 * 描述		：
 * 输入		：无
 * 输出		：无
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
