#ifndef __USAR_H
#define __USAR_H
#include "stm32f10x.h" 
#include <stdio.h>

void usart_init(void);

void usartSendByte(USART_TypeDef* USARTx, uint16_t Data);

void usartSendStr(USART_TypeDef* USARTx,char *str);

#endif

