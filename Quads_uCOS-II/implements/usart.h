/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��
 * ����    	��        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/


#ifndef __USART_H__
#define __USART_H__

#include "includes.h"

//��ֲ��ע���ַ
#define USART1_TDR_ADDRESS					0x40013808
#define USART1_RDR_ADDRESS					0x40013804


#define USART_TxBuffer_Size					80
#define USART_RxBuffer_Size					80

#define countof(a)   (sizeof(a) / sizeof(*(a)))						//���������С



int SendChar(int ch);
//int GetKey(void);
void usart_Init(u32 BaudRate);			//��ʼ������
void USART_DMA(void);


#endif //__USART_H__



/************************* (C) COPYRIGHT 2017 G627 Team **************************/
