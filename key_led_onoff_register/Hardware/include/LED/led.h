#ifndef __LED_H
#define __LED_H

#include"stm32f10x.h"

#define LED0 GPIO_ODR_ODR5
#define LED1 GPIO_ODR_ODR5
#define LED0_GPIO GPIOB
#define LED1_GPIO GPIOE

// 初始化
void LED_Init(void);

// 控制某个LED的开关
void LED_On(GPIO_TypeDef * led_GPIO,uint16_t led);
void LED_Off(GPIO_TypeDef * led_GPIO,uint16_t led);

// 翻转led灯状态
void LED_Toggle(GPIO_TypeDef * led_GPIO,uint16_t led);

// 对一组LED灯全开全关
void LED_OnAll(GPIO_TypeDef * led_GPIO[],uint16_t leds[],uint8_t size);
void LED_OnOff(GPIO_TypeDef * led_GPIO[],uint16_t leds[],uint8_t size);

#endif
