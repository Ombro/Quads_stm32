/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：
 * 描述    	：        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "debug.h"


void Restart_USART_DMA(void)
{
	DMA_Cmd(DMA1_Channel5,DISABLE);
	
	while(DMA_GetFlagStatus(DMA1_FLAG_TC5))
		DMA_ClearFlag(DMA1_FLAG_TC5);
	
	memset(USART_RxBuffer,0,USART_RxBuffer_Size);
	
	DMA_Init(DMA1_Channel5, &USART_DMA_InitStructure); 
	DMA_Cmd(DMA1_Channel5,ENABLE); 
}


void Debug_Init(void)
{
	usart_Init(115200);
	USART_DMA();
}


void set_pid(float arr[], char *p)
{
	int i = 0, j=0;
	float temp;	
	for(j=0;j<5;j++)
	{
		while((*p>29)&&(*p<40))
		{
			temp += (*p - 30) * pow(10,i);
			p++;
			i++;
		}
		if(*p == '.')
		{
			p++;
			i=0;
			while((*p>29)&&(*p<40))
			{
				temp+=(*p - 30) * pow(10,-i);
				p++;
			}
		}
		if((*p == ',')||(*p == '#'))
		{
			p++;
		}
		arr[j]=temp;
		temp=0;
	}
}

void save_pidparm(void)
{
	char *temp;
	int i=0,j=0;
	char *x = (char *)FLASH_START_ADDR_X;
	char *y = (char *)FLASH_START_ADDR_Y;
	for(i=0;i<5;i++)
	{
		temp = (char *)(&pid.x[i]);
		for(j=0;j<4;j++)
		{
			*x = *temp;
			temp++;
			x++;
		}
	}
	for(i=0;i<5;i++)
	{
		temp = (char *)(&pid.y[i]);
		for(j=0;j<4;j++)
		{
			*y = *temp;
			temp++;
			y++;
		}
	}
}

void get_pidparm(void)
{
	int i=0,j=0;
	char temp[4];
	float *data;
	char *x = (char *)FLASH_START_ADDR_X;
	char *y = (char *)FLASH_START_ADDR_Y;
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			temp[j] = *x;
			x++;
		}
		data = (float*)(&temp);
		pid.x[i] = *data;
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			temp[j] = *y;
			y++;
		}
		data = (float*)(&temp);
		pid.y[i] = *data;
	}
}

void clr_pidparm(void)
{
	char *p = (char *)FLASH_START_ADDR_X;
	int size;
	for(size = 0;size<20;size++)
	{
		*p = 0;
		p++;
	}
}

void recieve_data(char *buff)
{
	if(*buff == '@')
	{
		buff++;
		switch(*buff)
		{
			case 'X':
				set_pid(pid.x, buff);
				break;
			case 'Y':
				set_pid(pid.y, buff);
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



