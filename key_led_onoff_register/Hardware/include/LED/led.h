#ifndef __LED_H
#define __LED_H

#include"stm32f10x.h"

#define LED0 GPIO_ODR_ODR5
#define LED1 GPIO_ODR_ODR5
#define LED0_GPIO GPIOB
#define LED1_GPIO GPIOE

// ��ʼ��
void LED_Init(void);

// ����ĳ��LED�Ŀ���
void LED_On(GPIO_TypeDef * led_GPIO,uint16_t led);
void LED_Off(GPIO_TypeDef * led_GPIO,uint16_t led);

// ��תled��״̬
void LED_Toggle(GPIO_TypeDef * led_GPIO,uint16_t led);

// ��һ��LED��ȫ��ȫ��
void LED_OnAll(GPIO_TypeDef * led_GPIO[],uint16_t leds[],uint8_t size);
void LED_OnOff(GPIO_TypeDef * led_GPIO[],uint16_t leds[],uint8_t size);

#endif
