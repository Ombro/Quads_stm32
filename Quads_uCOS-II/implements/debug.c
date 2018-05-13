/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��
 * ����    	��        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
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

/************************* (C) COPYRIGHT 2017 G627 Team **************************/



