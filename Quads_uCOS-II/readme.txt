���ߣ�  
		stm32f10xc8t6	Description

USART1		 PA9		  TX
			 PA10		  RX	

IIC			 PA4		  SCL
			 PA5		  SDA
			 
battery		 PA3		  ADC1

motor		 PA6		  TIM3_CH1
			 PA7		  TIM3_CH2
			 PB0		  TIM3_CH3
			 PB1		  TIM3_CH4

		 
		 
		 
		 
		 
		 battery.c�޸�
		 
		 
		 
		 
#define USART1_TDR_ADDRESS                0x40013828
#define USART1_RDR_ADDRESS                0x40013824

#define USART2_TDR_ADDRESS                0x40004428
#define USART2_RDR_ADDRESS                0x40004424



����DMA��ַ����		https://blog.csdn.net/qlexcel/article/details/74052418
����ַ�������		memset(buf,0,200); 

DMA_InitStructure���Ϊȫ�ֱ���
ͨ����־λ�ж����ݵ���


ADC_DMA		ģʽӦ�ø�Ϊcircle






===============DEBUG===============

���ݰ���ʽ	��@Xshell_p,shell_i,core_p,core_i,core_d#
��ͷ		��@
��β		��#
������ʽ		��6����Ϣ�������У���X/Y������x/y�ᣬ
			  5��ΪPID������float�ͣ�������λС�����м���","����

===================================



