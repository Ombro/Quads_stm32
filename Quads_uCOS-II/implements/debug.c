/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：debug.c
 * 描述    	：pid调试
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "debug.h"

volatile FLASH_Status FLASHStatus = FLASH_COMPLETE;


 /*
 * 函数名	：Restart_USART_DMA
 * 描述		：由于选择DMA正常模式，每次传输完需要重新开启串口DMA，重
			  新设置地址，使接收的数组地址不自增，达到circle模式效果
 * 输入		：无
 * 输出		：无
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
 * 函数名	：Debug_Init
 * 描述		：串口调试初始化，DMA和串口配置初始化
 * 输入		：无
 * 输出		：无
 */
void Debug_Init(void)
{
	usart_Init(115200);
	USART_DMA();
}

 /*
 * 函数名	：set_pid
 * 描述		：解析串口接收的字符串，设置pid参数
 * 输入		：arr[]	：pid参数数组
			  p		：串口接收字符串数组首地址
 * 输出		：无
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
 * 函数名	：save_pidparm
 * 描述		：保存pid参数到内部上flash，起始地址为0x8010000，
			  float->int(x100)，每个参数4个字节
 * 输入		：无
 * 输出		：无
 */
void save_pidparm(void)
{
	int i = 0;
	int data_save[10];
	for(i = 0;i<5;i++)
		data_save[i] = (int)(pid_parm.x[i]*100);
	for(i = 5;i<10;i++)
		data_save[i] = (int)(pid_parm.y[i-5]*100);
	FLASH_Unlock();			//需解除锁定，flash读写保护
	FLASH_ReadOutProtection(DISABLE);		//Flash读保护禁止  
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);//清除标志位
	FLASHStatus = FLASH_ErasePage(FLASH_START_ADDR_X);//擦除数据
	if(FLASHStatus == FLASH_COMPLETE)
	{
		for(i=0;i<10;i++)
			FLASH_ProgramWord(FLASH_START_ADDR_X+i*4, data_save[i]);
	}
	 FLASH_Lock();		//锁定并保存写入的数据
}

 /*
 * 函数名	：get_pidparm
 * 描述		：从falsh中读出pid参数并转换成float
 * 输入		：无
 * 输出		：无
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
 * 函数名	：clr_pidparm
 * 描述		：将flash上的pid参数清零
 * 输入		：无
 * 输出		：无
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
 * 函数名	：recieve_data
 * 描述		：解析数据包，并执行相应操作
 * 输入		：无
 * 输出		：无
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



