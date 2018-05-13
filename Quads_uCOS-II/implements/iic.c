/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��
 * ����    	��        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#include "stm32f10x_gpio.h"
#include "iic.h"

 /*
 * ������	��IIC_delay
 * ����		����ʱ������12������ʱ��Ϊ1us
 * ����		����
 * ���		����
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
 * ������	��IIC_Init
 * ����		������IIC����
 * ����		����
 * ���		����
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
 * ������	��IIC_Start
 * ����		����IIC����
 * ����		����
 * ���		��0-����, 1-�쳣
 */ 
u8 IIC_Start(void)
{
	SDA_H();
    SCL_H();
    IIC_delay();
    if(!SDA_read())			//SDA��Ϊ�͵�ƽ������æ,�˳�
	{
		printf("SDA��Ϊ�͵�ƽ,����æ!\n");
		return 1;
	}
    SDA_L();
    IIC_delay();
    if(SDA_read()) 			//SDA��Ϊ�ߵ�ƽ�����߳���,�˳�
	{
		printf("SDA��Ϊ�ߵ�ƽ,���߳���!\n");
		return 1;	
    }
	SDA_L();
    IIC_delay();
    return 0;
}

 /*
 * ������	��IIC_Free
 * ����		������ͨѶ���ͷ�IIC����
 * ����		����
 * ���		����
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
 * ������	��IIC_ACK
 * ����		������ӻ�Ӧ��
 * ����		����
 * ���		����
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
 * ������	��IIC_NACK
 * ����		��������ӻ�Ӧ�𣬼��ͷ�IIC����
 * ����		����
 * ���		����
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
 * ������	��IIC_Wait_ACK
 * ����		���жϴӻ��Ƿ񷵻�ACK�ź�
 * ����		����
 * ���		��0-��ACK�� 1-��ACK
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
			printf("�ӻ���Ӧ��!\n");
			return 1;
		}
		IIC_delay();
	}
//	printf("�����յ�Ӧ��!\n");
	SCL_L();
	IIC_delay();
	return 0;
}

 /*
 * ������	��IIC_Send_Byte
 * ����		������һ���ֽڣ�8Bit��������SendByte���Ӹ�λ����λ
 * ����		����
 * ���		����
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
 * ������	��IIC_Recive_Byte
 * ����		�����شӻ����������
 * ����		����
 * ���		��ReceiveByte	���ӻ����ص�����
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
 * ������	��IIC_Single_Write
 * ����		�������豸��ַ+д�ź�
			  ѡ��һ���ӻ�������ָ���ĵ�ַд��һ���ֽ�
 * ����		��SlaveAddress	���ӻ���ַ
			  REG_Address	���ӻ��Ĵ�����ַ
			  REG_data		���Ĵ�������
 * ���		��0-����, 1-�쳣
 */
unsigned char IIC_Single_Write(unsigned char SlaveAddress, unsigned char REG_Address, unsigned char REG_data)
{
    if(IIC_Start())
		return 1;
    IIC_Send_Byte(SlaveAddress<<1); 	//�����豸��ַ����λ����λ��
    if(IIC_Wait_ACK())
    {
        IIC_Free();
        return 1;
    }
    IIC_Send_Byte(REG_Address );   		//���õ���ʼ��ַ
    if(IIC_Wait_ACK())
	{
		printf("���ݷ���ʧ�ܣ�\n");
		return 1;
	}
    IIC_Send_Byte(REG_data);
    if(IIC_Wait_ACK())
	{
		printf("���ݷ���ʧ�ܣ�\n");
		return 1;
	}
	delay_us(10000);
    IIC_Free();
    return 0;
}

 /*
 * ������	��IIC_Single_Read
 * ����		�������豸��ַ+���ź�
			  ѡ��һ���ӻ�������ָ���ĵ�ַ����һ���ֽ�
 * ����		��SlaveAddress	���ӻ���ַ
			  REG_Address	���ӻ��Ĵ�����ַ
 * ���		��REG_data		���ӻ��Ĵ�����ַ�����ֵ
			  1				���쳣
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
    IIC_Send_Byte((u8) REG_Address);   //���õ���ʼ��ַ
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
 * ������	��IIC_Write_2_Byte
 * ����		��д�����ֽڵ����ݣ���ע������д��ȴ�ʱ�䣩
 * ����		��SlaveAddress	���ӻ���ַ
			  REG_Address	���ӻ��Ĵ�����ַ
			  DataToWrite	��д�������
 * ���		��0-����, 1-�쳣
 */
u8 IIC_Write_2_Byte(u8 SlaveAddress, u8 REG_Address, short DataToWrite)
{
	u8 data[2];
	data[0]=DataToWrite & 0x00FF;
	data[1]=DataToWrite >> 8;
    if(IIC_Start())
		return 1;
	IIC_Start();
    IIC_Send_Byte(SlaveAddress<<1);				//7λ�ӻ���ַ+һλ��0-д, 1-����
	if(IIC_Wait_ACK())
		return 1;
    IIC_Send_Byte(REG_Address);
    if(IIC_Wait_ACK())
		return 1;
    if(IIC_Start())
		return 1;
	IIC_Send_Byte(SlaveAddress<<1);				//7λ�ӻ���ַ+һλ��0-д, 1-����
	
    if(IIC_Wait_ACK())
		return 1;
	
	IIC_Send_Byte(data[0]);
    if(IIC_Wait_ACK())
		return 1;
	delay_us(1000000);							//������Ҫע�⣬��Ҫ�ȴ�һ��ʱ�䣬��֤����д��Ĵ���
	IIC_Send_Byte(data[1]);
    IIC_NACK();
	printf("д������\n");
    IIC_Free();                      		    //�ͷ�����
	delay_us(1000000);							//������Ҫע�⣬��Ҫ�ȴ�һ��ʱ�䣬��֤����д��Ĵ���
	return 0;	
}

 /*
 * ������	��IIC_Read
 * ����		����ȡ�ӻ�һ��������ַ�ϵ�����
 * ����		��SlaveAddress	���ӻ���ַ
			  REG_Address	���ӻ��Ĵ�����ַ
			  Length		����ȡ����ֽڵ��ܳ���
			  buf			����������
 * ���		��0-����, 1-�쳣
 */
unsigned char IIC_Read(u8 SlaveAddress, u8 REG_Address, u8 Length, u8 *buf)
{
    u8 i;
    // ��ʼ�ź�
    if(IIC_Start())
		return 1;

    // �����豸��ַ
    IIC_Send_Byte(SlaveAddress<<1);				//7λ�ӻ���ַ+һλ��0-д, 1-����

	if(IIC_Wait_ACK())
		return 1;
	
    //���ʹ洢��Ԫ��ַ
    IIC_Send_Byte(REG_Address);
	
    if(IIC_Wait_ACK())
		return 1;

    // ��ʼ�ź�
    if(IIC_Start())
		return 1;

    //�����豸��ַ+���ź�
    IIC_Send_Byte((SlaveAddress<<1) + 1);		//7λ�ӻ���ַ+һλ��0-д, 1-����
	
    if(IIC_Wait_ACK())
		return 1;
	
    for (i = 0; i < Length; i++)				//������ȡLength����ַ���ݣ��洢��buf
    {
        *(buf + i) = IIC_Recive_Byte();			//buf[0]�洢����
        if (i == Length - 1)		
			IIC_NACK();							//���һ��������Ҫ��NACK
        else		
			IIC_ACK();							//��ӦACK
		IIC_delay();
	}
//	printf("��ȡ����\n");
    IIC_Free();                      		    //ֹͣ�ź�
    IIC_delay();
	return 0;
}

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
