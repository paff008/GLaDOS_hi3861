#include "stm32f10x.h"                  // Device header
#include "usar.h"
#include "stdio.h"
void usart_init(void)
{
	GPIO_InitTypeDef  gpio_init;
	USART_InitTypeDef usartStruct;
	NVIC_InitTypeDef  nvic_initStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	
	//2.1 TX
	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_init.GPIO_Pin = GPIO_Pin_9;
	gpio_init.GPIO_Speed = GPIO_Speed_10MHz;
	
	GPIO_Init(GPIOA,&gpio_init);
	
	//2.2 RX
	gpio_init.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_init.GPIO_Pin = GPIO_Pin_10;
	
	GPIO_Init(GPIOA,&gpio_init);
	
	//3.
	usartStruct.USART_BaudRate = 115200;
	usartStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usartStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	usartStruct.USART_Parity = USART_Parity_No;
	usartStruct.USART_StopBits = USART_StopBits_1;
	usartStruct.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART1,&usartStruct);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1, ENABLE );
	
	nvic_initStruct.NVIC_IRQChannel = USART1_IRQn;
	nvic_initStruct.NVIC_IRQChannelPreemptionPriority = 1;
	nvic_initStruct.NVIC_IRQChannelSubPriority = 1;
	nvic_initStruct.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&nvic_initStruct);

	
}


void usartSendByte(USART_TypeDef* USARTx, uint16_t Data)
{
	USART_SendData(USARTx,Data);
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);

}


void usartSendStr(USART_TypeDef* USARTx,char *str)
{
	uint16_t i = 0;
	do{
		usartSendByte(USARTx,*(str+i));
		i++;
	}while(*(str+i) != '\0');

	
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
}

int fputc(int ch,FILE *f)
{
	USART_SendData(USART1,(uint8_t)ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	
	return (ch);
}

int fgetc(FILE *f)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
	
	return (int) USART_ReceiveData(USART1);
}
