/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：
 * 描述    	：        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/


#ifndef __USART_H__
#define __USART_H__

#include "includes.h"

//移植需注意地址
#define USART1_TDR_ADDRESS					0x40013808
#define USART1_RDR_ADDRESS					0x40013804


#define USART_TxBuffer_Size					80
#define USART_RxBuffer_Size					80

#define countof(a)   (sizeof(a) / sizeof(*(a)))						//计算数组大小



int SendChar(int ch);
//int GetKey(void);
void usart_Init(u32 BaudRate);			//初始化串口
void USART_DMA(void);


#endif //__USART_H__



/************************* (C) COPYRIGHT 2017 G627 Team **************************/
