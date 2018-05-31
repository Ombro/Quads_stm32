/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：debug.h
 * 描述    	：debug.c的头文件
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "includes.h"

#define FLASH_START_ADDR_X		((uint32_t)0x8010000)
#define FLASH_START_ADDR_Y		((uint32_t)0x8010014)

#define USART_TxBuffer_Size					80
#define USART_RxBuffer_Size					80

extern DMA_InitTypeDef USART_DMA_InitStructure;		//串口DMA配置结构体
extern char USART_TxBuffer[USART_TxBuffer_Size];	//发送数据数组
extern char USART_RxBuffer[USART_RxBuffer_Size];	//接收数据数组

extern PID_PARM pid_parm;							//pid参数结构体

void Restart_USART_DMA(void);						//重新开启DMA，解决地址自增
void Debug_Init(void);								//串口、DMA初始化

void set_pid(float arr[], char *p);					//设置pid参数
void analyze_data(char *buff);						//解析数据包

void save_pidparm(void);							//保存pid参数到内部flash
void get_pidparm(void);								//从内部flash获取pid参数
void clr_pidparm(void);								//清除内部flash的pid参数



#endif //__DEBUG_H__




/************************* (C) COPYRIGHT 2017 G627 Team **************************/



