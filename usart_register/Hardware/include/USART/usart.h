#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"

void USART_Init(void);


void USART_SendChar(uint8_t ch);

uint8_t USART_ReceiverChar(void);

void USART_SendString(uint8_t *str,uint8_t size);

void USART_ReceiveString(uint8_t buffer[],uint8_t *size);


#endif
