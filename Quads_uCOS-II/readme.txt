连线：  
		stm32f10xc8t6	function

USART1		 PA9		  TX
			 PA10		  RX	

IIC			 PA4		  SCL
			 PA5		  SDA
			 
battery		 PA3		  ADC1

motor		 PA6		  TIM3_CH1
			 PA7		  TIM3_CH2
			 PB0		  TIM3_CH3
			 PB1		  TIM3_CH4

		 
		 
		 
		 
		 
		 battery.c修改
		 
		 
		 
		 
#define USART1_TDR_ADDRESS                0x40013828
#define USART1_RDR_ADDRESS                0x40013824

#define USART2_TDR_ADDRESS                0x40004428
#define USART2_RDR_ADDRESS                0x40004424



串口DMA地址问题		https://blog.csdn.net/qlexcel/article/details/74052418
清空字符串数组		memset(buf,0,200); 

DMA_InitStructure最好为全局变量
通过标志位判断数据到达


ADC_DMA		模式应该改为circle






===============DEBUG===============

数据包形式	：@X_P,X_I,X_D,Y_P,Y_I,Y_D&
包头		：@
包尾		：#
数据形式		：两位整数两位小数，6个数据，中间用","隔开

===================================