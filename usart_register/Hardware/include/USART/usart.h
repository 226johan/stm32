#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"

void USART_Init(void);


void USART_SendChar(uint8_t ch);

uint8_t USART_ReceiverChar(void);

#endif
