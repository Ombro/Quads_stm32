/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��debug.c
 * ����    	��pid����
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#include "debug.h"

volatile FLASH_Status FLASHStatus = FLASH_COMPLETE;


 /*
 * ������	��Restart_USART_DMA
 * ����		������ѡ��DMA����ģʽ��ÿ�δ�������Ҫ���¿�������DMA����
			  �����õ�ַ��ʹ���յ������ַ���������ﵽcircleģʽЧ��
 * ����		����
 * ���		����
 */
void Restart_USART_DMA(void)
{
	DMA_Cmd(DMA1_Channel5,DISABLE);
	
	while(DMA_GetFlagStatus(DMA1_FLAG_TC5))
		DMA_ClearFlag(DMA1_FLAG_TC5);
	
	memset(USART_RxBuffer,0,USART_RxBuffer_Size);
	
	DMA_Init(DMA1_Channel5, &USART_DMA_InitStructure); 
	DMA_Cmd(DMA1_Channel5,ENABLE); 
}

 /*
 * ������	��Debug_Init
 * ����		�����ڵ��Գ�ʼ����DMA�ʹ������ó�ʼ��
 * ����		����
 * ���		����
 */
void Debug_Init(void)
{
	usart_Init(115200);
	USART_DMA();
}

 /*
 * ������	��set_pid
 * ����		���������ڽ��յ��ַ���������pid����
 * ����		��arr[]	��pid��������
			  p		�����ڽ����ַ��������׵�ַ
 * ���		����
 */
void set_pid(float arr[], char *p)
{
	int i = 0, j = 0;
	float temp = 0;
	for (j = 0; j<5; j++)
	{
		i = 0;
		while ((*p>47) && (*p<58))
		{
			temp += (*p - 48) * (float)pow(10, i);
			p++;
			i++;
		}
		if (*p == '.')
		{
			i = 1;
			p++;
			while ((*p>47) && (*p<58))
			{
				temp += (*p - 48) * (float)pow(10, -i);
				p++;
				i++;
			}
		}
		if ((*p == ',') || (*p == '#'))
		{
			p++;
		}
		arr[j] = temp;
		temp = 0;
	}
}

 /*
 * ������	��save_pidparm
 * ����		������pid�������ڲ���flash����ʼ��ַΪ0x8010000��
			  float->int(x100)��ÿ������4���ֽ�
 * ����		����
 * ���		����
 */
void save_pidparm(void)
{
	int i = 0;
	int data_save[10];
	for(i = 0;i<5;i++)
		data_save[i] = (int)(pid_parm.x[i]*100);
	for(i = 5;i<10;i++)
		data_save[i] = (int)(pid_parm.y[i-5]*100);
	FLASH_Unlock();			//����������flash��д����
	FLASH_ReadOutProtection(DISABLE);		//Flash��������ֹ  
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);//�����־λ
	FLASHStatus = FLASH_ErasePage(FLASH_START_ADDR_X);//��������
	if(FLASHStatus == FLASH_COMPLETE)
	{
		for(i=0;i<10;i++)
			FLASH_ProgramWord(FLASH_START_ADDR_X+i*4, data_save[i]);
	}
	 FLASH_Lock();		//����������д�������
}

 /*
 * ������	��get_pidparm
 * ����		����falsh�ж���pid������ת����float
 * ����		����
 * ���		����
 */
void get_pidparm(void)
{
	int i=0;
	uint32_t *p = (uint32_t *)FLASH_START_ADDR_X;
	for(i=0;i<10;i++)
	{
		if(i<5)
		{
			pid_parm.x[i]=((float)(*p))/100;
				p++;
		}
		else
		{
			pid_parm.y[i-5]=((float)(*p))/100;
			if(i!=9)
				p++;
		}
	}
}

 /*
 * ������	��clr_pidparm
 * ����		����flash�ϵ�pid��������
 * ����		����
 * ���		����
 */
void clr_pidparm(void)
{
	int i=0;
	FLASH_Unlock();
	FLASH_ReadOutProtection(DISABLE);   
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	FLASHStatus = FLASH_ErasePage(FLASH_START_ADDR_X);
	if(FLASHStatus == FLASH_COMPLETE)
	{
		for(i=0;i<10;i++)
			FLASH_ProgramWord(FLASH_START_ADDR_X+i*4, 0);
	}
	FLASH_Lock(); 
}

 /*
 * ������	��recieve_data
 * ����		���������ݰ�����ִ����Ӧ����
 * ����		����
 * ���		����
 */
void analyze_data(char *buff)
{
	if(*buff == '@')
	{
		buff++;
		switch(*buff)
		{
			case 'X':
				buff++;
				set_pid(pid_parm.x, buff);
				break;
			case 'Y':
				buff++;
				set_pid(pid_parm.y, buff);
				break;
			case '*':
				save_pidparm();
				break;
			case '!':
				clr_pidparm();
				break;
		}
	}
}


/************************* (C) COPYRIGHT 2017 G627 Team **************************/



