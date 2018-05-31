/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��debug.h
 * ����    	��debug.c��ͷ�ļ�
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "includes.h"

#define FLASH_START_ADDR_X		((uint32_t)0x8010000)
#define FLASH_START_ADDR_Y		((uint32_t)0x8010014)

#define USART_TxBuffer_Size					80
#define USART_RxBuffer_Size					80

extern DMA_InitTypeDef USART_DMA_InitStructure;		//����DMA���ýṹ��
extern char USART_TxBuffer[USART_TxBuffer_Size];	//������������
extern char USART_RxBuffer[USART_RxBuffer_Size];	//������������

extern PID_PARM pid_parm;							//pid�����ṹ��

void Restart_USART_DMA(void);						//���¿���DMA�������ַ����
void Debug_Init(void);								//���ڡ�DMA��ʼ��

void set_pid(float arr[], char *p);					//����pid����
void analyze_data(char *buff);						//�������ݰ�

void save_pidparm(void);							//����pid�������ڲ�flash
void get_pidparm(void);								//���ڲ�flash��ȡpid����
void clr_pidparm(void);								//����ڲ�flash��pid����



#endif //__DEBUG_H__




/************************* (C) COPYRIGHT 2017 G627 Team **************************/



