#ifndef __LED_H
#define __LED_H

#include"gpio.h"

void LED_On(GPIO_TypeDef * led_gpio,uint16_t led);
void LED_Off(GPIO_TypeDef * led_gpio,uint16_t led);
void LED_Toggle(GPIO_TypeDef * led_gpio,uint16_t led);

void LED_OnAll(GPIO_TypeDef * led_gpios[],uint16_t leds[],uint16_t size);
void LED_OffAll(GPIO_TypeDef * led_gpios[],uint16_t leds[],uint16_t size);

#endif
