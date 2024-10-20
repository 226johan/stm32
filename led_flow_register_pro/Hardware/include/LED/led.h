#ifndef __LED_H
#define __LED_H

#include"stm32f10x.h"

#define LEDO GPIO_ODR_ODR5
#define LED1 GPIO_ODR_ODR5

// 初始化
void LED_Init(void);

// 控制某个LED的开关
void LED_On(uint16_t led);
void LED_Off(uint16_t led);

// 翻转led灯状态
void LED_Toggle(uint16_t led);

// 对一组LED灯全开全关
void LED_OnAll(uint16_t leds[],uint8_t size);
void LED_OnOff(uint16_t leds[],uint8_t size);

#endif