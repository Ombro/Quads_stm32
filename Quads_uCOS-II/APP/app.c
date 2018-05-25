﻿/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * 文件名	：app.c
 * 描述    	：用户相关程序，即任务   
 * 实验平台	：STM32F103C8T6
 * 库版本	：ST3.5.0
 * 作者		：河王
 * QQ		：345792307
 * 团队		：G627
**********************************************************************************/

#include "includes.h"


short data[18]={0};
float Motion_9[9]={0};
float pressure;
float temp;
int i=0;


extern char USART_TxBuffer[USART_TxBuffer_Size];			//接收数据数组
extern char USART_RxBuffer[USART_RxBuffer_Size];			//发送数据数组


void Task_LED1(void *p_arg)
{
    (void)p_arg;
//	USART_RxBuffer[0]='A';
    while(1)
    {
		
//		Battery_Read();
//		while(USART_RxBuffer[0]!='\0');
//		strcpy(USART_TxBuffer, USART_RxBuffer);
//		printf("%s\n",USART_RxBuffer);
//		Restart_USART_DMA();
//		memset(str,0,10); 
//		if(str[0]=='\0')
//			printf("hello\n");
		
//		MPU9250_Calibration();
//		delay_us(1000);
//		IIC_Write_2_Byte(0x50, AXOFFSET, data[0]+1);
//		MPU9250_Get_Offset9(data);
//		printf("%d  %d  %d\n",data[0],data[1],data[2]);
		
		
		OSTimeDlyHMSM(0,0,1,0);
		delay_us(100000);
    }
}

void Task_LED2(void *p_arg)
{
    (void)p_arg;
    while(1)
    {
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		printf("灯亮了\n");
        OSTimeDlyHMSM(0,0,0,500);
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
		printf("灯灭了\n");
        OSTimeDlyHMSM(0,0,0,500);
    }
}

void Task_LED3(void *p_arg)
{
    (void)p_arg;
    while(1)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_7);
        OSTimeDlyHMSM(0,0,3,0);
        GPIO_ResetBits(GPIOA, GPIO_Pin_7);
        OSTimeDlyHMSM(0,0,3,0);
    }
}





/************************* (C) COPYRIGHT 2017 G627 Team **************************/
