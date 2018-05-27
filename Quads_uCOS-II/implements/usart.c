/************************* (C) COPYRIGHT 2017 G627 Team **************************
 * �ļ���	��
 * ����    	��        
 * ʵ��ƽ̨	��STM32F103C8T6
 * ��汾	��ST3.5.0
 * ����		������
 * QQ		��345792307
 * �Ŷ�		��G627
**********************************************************************************/

#include "usart.h"

DMA_InitTypeDef USART_DMA_InitStructure;			//����DMA���ýṹ��
char USART_TxBuffer[USART_TxBuffer_Size];			//������������
char USART_RxBuffer[USART_RxBuffer_Size];			//������������


struct __FILE
{
    int handle;
};
FILE __stdout;
FILE __stdin;


 /*
 * ������	��SendChar
 * ����		���ض���printfʹ�õ��������
 * ����		����
 * ���		����
 */
int SendChar(int ch)
{
    /* ����һ���ֽ����ݵ�USART */
    USART_SendData(USART1, (uint8_t) ch);
    /* �ȴ�������� */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

    return (ch);
}


 /*
 * ������	��GetKey
 * ����		�����񴮿����������
 * ����		����
 * ���		����
 */
int GetKey(void)
{
    /* �ȴ������������� */
    while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

    return (int)USART_ReceiveData(USART1);
}


 /*
 * ������	��usart_Init
 * ����		����ʼ������
 * ����		��BaudRate - ������
 * ���		����
 */
void usart_Init(u32 BaudRate)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    USART_DeInit(USART1);
	

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    USART_InitStructure.USART_BaudRate = BaudRate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    USART_Init(USART1, &USART_InitStructure);
    USART_Cmd(USART1, ENABLE);
}


 /*
 * ������	��USART_DMA
 * ����		������DMA���ã�RX��
 * ����		����
 * ���		����
 */
void USART_DMA(void)
{

//	USART1_DMA_RX
	DMA_DeInit(DMA1_Channel5);  
	USART_DMA_InitStructure.DMA_PeripheralBaseAddr = USART1_RDR_ADDRESS;
	USART_DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)USART_RxBuffer;
	USART_DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	USART_DMA_InitStructure.DMA_BufferSize = USART_RxBuffer_Size;
	USART_DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	USART_DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	USART_DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	USART_DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	USART_DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	USART_DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	USART_DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	
	DMA_Cmd(DMA1_Channel5, ENABLE);
	USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);
	DMA_Init(DMA1_Channel5, &USART_DMA_InitStructure);
}






int fputc(int ch, FILE *f)
{
    return (SendChar(ch));
}
int fgetc(FILE *f)
{
    return (SendChar(GetKey()));
}
void _ttywrch(int ch)
{
    SendChar (ch);
}
int ferror(FILE *f)
{
    return EOF;
}
void _sys_exit(int return_code)
{
label:
    goto label;
}

/************************* (C) COPYRIGHT 2017 G627 Team **************************/
