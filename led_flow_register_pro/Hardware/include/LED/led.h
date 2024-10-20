#ifndef __LED_H
#define __LED_H

#include"stm32f10x.h"

#define LEDO GPIO_ODR_ODR5
#define LED1 GPIO_ODR_ODR5

// ��ʼ��
void LED_Init(void);

// ����ĳ��LED�Ŀ���
void LED_On(uint16_t led);
void LED_Off(uint16_t led);

// ��תled��״̬
void LED_Toggle(uint16_t led);

// ��һ��LED��ȫ��ȫ��
void LED_OnAll(uint16_t leds[],uint8_t size);
void LED_OnOff(uint16_t leds[],uint8_t size);

#endif