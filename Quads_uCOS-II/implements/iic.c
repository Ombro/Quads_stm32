/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：
 * 描述    	：        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "stm32f10x_gpio.h"
#include "iic.h"

 /*
 * 函数名	：IIC_delay
 * 描述		：延时函数，12次自增时间为1us
 * 输入		：无
 * 输出		：无
 */
void IIC_delay(void)
{
	u8 j=0;
	while(j<36)//36 - 3us
	{
		j++;
	}
}

 /*
 * 函数名	：IIC_Init
 * 描述		：配置IIC引脚
 * 输入		：无
 * 输出		：无
 */
void IIC_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_GPIO_IIC, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin=SDA_PIN | SCL_PIN;
	GPIO_Init(GPIO_IIC, &GPIO_InitStructure);
	
	IIC_delay();
}

 /*
 * 函数名	：IIC_Start
 * 描述		：打开IIC总线
 * 输入		：无
 * 输出		：0-正常, 1-异常
 */ 
u8 IIC_Start(void)
{
	SDA_H();
    SCL_H();
    IIC_delay();
    if(!SDA_read())			//SDA线为低电平则总线忙,退出
	{
		printf("SDA线为低电平,总线忙!\n");
		return 1;
	}
    SDA_L();
    IIC_delay();
    if(SDA_read()) 			//SDA线为高电平则总线出错,退出
	{
		printf("SDA线为高电平,总线出错!\n");
		return 1;	
    }
	SDA_L();
    IIC_delay();
    return 0;
}

 /*
 * 函数名	：IIC_Free
 * 描述		：结束通讯，释放IIC总线
 * 输入		：无
 * 输出		：无
 */
void IIC_Free(void)
{
    SCL_L();
    IIC_delay();
    SDA_L();
    IIC_delay();
    SCL_H();
    IIC_delay();
    SDA_H();
    IIC_delay();
}

 /*
 * 函数名	：IIC_ACK
 * 描述		：允许从机应答
 * 输入		：无
 * 输出		：无
 */
void IIC_ACK(void)
{
    SCL_L();
    IIC_delay();
    SDA_L();
    IIC_delay();
    SCL_H();
    IIC_delay();
    SCL_L();
    IIC_delay();
}

 /*
 * 函数名	：IIC_NACK
 * 描述		：不允许从机应答，即释放IIC总线
 * 输入		：无
 * 输出		：无
 */
void IIC_NACK(void)
{
    SCL_L();
    IIC_delay();
    SDA_H();
    IIC_delay();
    SCL_H();
    IIC_delay();
    SCL_L();
    IIC_delay();
}

 /*
 * 函数名	：IIC_Wait_ACK
 * 描述		：判断从机是否返回ACK信号
 * 输入		：无
 * 输出		：0-有ACK， 1-无ACK
 */
u8 IIC_Wait_ACK(void)
{
	short time;
	SCL_L();
	IIC_delay();
	SDA_H();
	IIC_delay();
	SCL_H();
	IIC_delay();
	while(SDA_read())
	{
		time++;
		if(time>255)
		{
			IIC_Free();
			printf("从机无应答!\n");
			return 1;
		}
		IIC_delay();
	}
//	printf("主机收到应答!\n");
	SCL_L();
	IIC_delay();
	return 0;
}

 /*
 * 函数名	：IIC_Send_Byte
 * 描述		：发送一个字节（8Bit）的数据SendByte，从高位到低位
 * 输入		：无
 * 输出		：无
 */
void IIC_Send_Byte(unsigned char SendByte)
{
    u8 i = 8;
    while(i--)
    {
        SCL_L();
        IIC_delay();
        if(SendByte & 0x80)		//0x80 == 1000 0000
            SDA_H();
        else
            SDA_L();
		SendByte <<= 1;
		IIC_delay();
        SCL_H();
        IIC_delay();
    }
	SCL_L();
}

 /*
 * 函数名	：IIC_Recive_Byte
 * 描述		：返回从机传输的数据
 * 输入		：无
 * 输出		：ReceiveByte	：从机返回的数据
 */
unsigned char IIC_Recive_Byte(void)
{
    u8 i = 8;
    u8 ReceiveByte = 0;

	SDA_H();
    while(i--)
    {
        ReceiveByte <<= 1;
        SCL_L();
        IIC_delay();
        SCL_H();
        IIC_delay();
        if(SDA_read())
        {
            ReceiveByte |= 0x01;
        }
    }
    SCL_L();
    return ReceiveByte;
}

 /*
 * 函数名	：IIC_Single_Write
 * 描述		：发送设备地址+写信号
			  选中一个从机，并向指定的地址写入一个字节
 * 输入		：SlaveAddress	：从机地址
			  REG_Address	：从机寄存器地址
			  REG_data		：寄存器命令
 * 输出		：0-正常, 1-异常
 */
unsigned char IIC_Single_Write(unsigned char SlaveAddress, unsigned char REG_Address, unsigned char REG_data)
{
    if(IIC_Start())
		return 1;
    IIC_Send_Byte(SlaveAddress<<1); 	//发送设备地址（高位到低位）
    if(IIC_Wait_ACK())
    {
        IIC_Free();
        return 1;
    }
    IIC_Send_Byte(REG_Address );   		//设置低起始地址
    if(IIC_Wait_ACK())
	{
		printf("数据发送失败！\n");
		return 1;
	}
    IIC_Send_Byte(REG_data);
    if(IIC_Wait_ACK())
	{
		printf("数据发送失败！\n");
		return 1;
	}
	delay_us(10000);
    IIC_Free();
    return 0;
}

 /*
 * 函数名	：IIC_Single_Read
 * 描述		：发送设备地址+读信号
			  选中一个从机，并向指定的地址读出一个字节
 * 输入		：SlaveAddress	：从机地址
			  REG_Address	：从机寄存器地址
 * 输出		：REG_data		：从机寄存器地址储存的值
			  1				：异常
 */
unsigned char IIC_Single_Read(unsigned char SlaveAddress, unsigned char REG_Address)
{
    unsigned char REG_data;
    if(IIC_Start())
		return 1;
    IIC_Send_Byte(SlaveAddress<<1); 
    if(IIC_Wait_ACK())
    {
		IIC_Free();
        return 1;
    }
    IIC_Send_Byte((u8) REG_Address);   //设置低起始地址
    if(IIC_Wait_ACK())
		return 1;
    IIC_Start();
    IIC_Send_Byte((SlaveAddress<<1) + 1);
    if(IIC_Wait_ACK())
		return 1;

    REG_data = IIC_Recive_Byte();
    IIC_NACK();
    IIC_Free();
    return REG_data;
}

 /*
 * 函数名	：IIC_Write_2_Byte
 * 描述		：写两个字节的数据（需注意数据写入等待时间）
 * 输入		：SlaveAddress	：从机地址
			  REG_Address	：从机寄存器地址
			  DataToWrite	：写入的数据
 * 输出		：0-正常, 1-异常
 */
u8 IIC_Write_2_Byte(u8 SlaveAddress, u8 REG_Address, short DataToWrite)
{
	u8 data[2];
	data[0]=DataToWrite & 0x00FF;
	data[1]=DataToWrite >> 8;
    if(IIC_Start())
		return 1;
	IIC_Start();
    IIC_Send_Byte(SlaveAddress<<1);				//7位从机地址+一位（0-写, 1-读）
	if(IIC_Wait_ACK())
		return 1;
    IIC_Send_Byte(REG_Address);
    if(IIC_Wait_ACK())
		return 1;
    if(IIC_Start())
		return 1;
	IIC_Send_Byte(SlaveAddress<<1);				//7位从机地址+一位（0-写, 1-读）
	
    if(IIC_Wait_ACK())
		return 1;
	
	IIC_Send_Byte(data[0]);
    if(IIC_Wait_ACK())
		return 1;
	delay_us(1000000);							//这里需要注意，需要等待一定时间，保证数据写入寄存器
	IIC_Send_Byte(data[1]);
    IIC_NACK();
	printf("写入正常\n");
    IIC_Free();                      		    //释放总线
	delay_us(1000000);							//这里需要注意，需要等待一定时间，保证数据写入寄存器
	return 0;	
}

 /*
 * 函数名	：IIC_Read
 * 描述		：读取从机一块连续地址上的数据
 * 输入		：SlaveAddress	：从机地址
			  REG_Address	：从机寄存器地址
			  Length		：读取多个字节的总长度
			  buf			：缓冲数组
 * 输出		：0-正常, 1-异常
 */
unsigned char IIC_Read(u8 SlaveAddress, u8 REG_Address, u8 Length, u8 *buf)
{
    u8 i;
    // 起始信号
    if(IIC_Start())
		return 1;

    // 发送设备地址
    IIC_Send_Byte(SlaveAddress<<1);				//7位从机地址+一位（0-写, 1-读）

	if(IIC_Wait_ACK())
		return 1;
	
    //发送存储单元地址
    IIC_Send_Byte(REG_Address);
	
    if(IIC_Wait_ACK())
		return 1;

    // 起始信号
    if(IIC_Start())
		return 1;

    //发送设备地址+读信号
    IIC_Send_Byte((SlaveAddress<<1) + 1);		//7位从机地址+一位（0-写, 1-读）
	
    if(IIC_Wait_ACK())
		return 1;
	
    for (i = 0; i < Length; i++)				//连续读取Length个地址数据，存储中buf
    {
        *(buf + i) = IIC_Recive_Byte();			//buf[0]存储数据
        if (i == Length - 1)		
			IIC_NACK();							//最后一个数据需要回NACK
        else		
			IIC_ACK();							//回应ACK
		IIC_delay();
	}
//	printf("读取正常\n");
    IIC_Free();                      		    //停止信号
    IIC_delay();
	return 0;
}

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
