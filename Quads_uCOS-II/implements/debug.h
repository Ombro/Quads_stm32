/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��
 * ����    	��        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "includes.h"

#define USART_TxBuffer_Size					80
#define USART_RxBuffer_Size					80

extern DMA_InitTypeDef USART_DMA_InitStructure;				//����DMA���ýṹ��
extern char USART_TxBuffer[USART_TxBuffer_Size];			//������������
extern char USART_RxBuffer[USART_RxBuffer_Size];			//������������

void Restart_USART_DMA(void);
void Debug_Init(void);



#endif //__DEBUG_H__




/************************* (C) COPYRIGHT 2017 G627 Team **************************/



