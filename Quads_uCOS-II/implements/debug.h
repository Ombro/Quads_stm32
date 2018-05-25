/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：
 * 描述    	：        
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "includes.h"
#include <math.h>

#define FLASH_START_ADDR_X		((uint32_t)0x8000000)
#define FLASH_START_ADDR_Y		((uint32_t)0x8000014)

#define USART_TxBuffer_Size					80
#define USART_RxBuffer_Size					80

extern DMA_InitTypeDef USART_DMA_InitStructure;				//串口DMA配置结构体
extern char USART_TxBuffer[USART_TxBuffer_Size];			//发送数据数组
extern char USART_RxBuffer[USART_RxBuffer_Size];			//接收数据数组

extern PID pid;

void Restart_USART_DMA(void);
void Debug_Init(void);

void set_pid(float arr[], char *p);
void recieve_data(char *buff);

void save_pidparm(void);
void get_pidparm(void);
void clr_pidparm(void);



#endif //__DEBUG_H__




/************************* (C) COPYRIGHT 2017 G627 Team **************************/



