/************************* (C) COPYRIGHT 2017 G627 Team **************************
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
float text_data = 1.23456;

extern char USART_TxBuffer[USART_TxBuffer_Size];			//发送数据数组
extern char USART_RxBuffer[USART_RxBuffer_Size];			//接收数据数组
extern int counter;

void Task_LED1(void *p_arg)
{
    (void)p_arg;
	strcpy(USART_RxBuffer, "@X5.55,4.44,3.33,2.22,1.11");
	strcpy(USART_TxBuffer, "@Y1.11,2.22,3.33,4.44,5.55");
//	USART_RxBuffer[0]='A';
    while(1)
    {
//falsh写测试		
//		analyze_data(USART_RxBuffer);
//		save_pidparm();
//		analyze_data(USART_TxBuffer);
//		save_pidparm();

//flash读测试
//		get_pidparm();
//		for(i = 0;i<5;i++)
//		{
//			printf("%lf\t",pid_parm.y[i]);
//			OSTimeDlyHMSM(0,0,0,10);
//			printf("%lf\n",pid_parm.x[i]);
//			OSTimeDlyHMSM(0,0,0,10);
//		}

		
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
		
		Timer_Start();
		OSTimeDlyHMSM(0,0,0,500);
//		for(i = 0; i<65500; i++ )
//			i++;
		Timer_End();
		printf("counter:%d\n",counter);
		counter = 0;
//		OSTimeDlyHMSM(0,0,1,500);
//		delay_us(100000);
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
