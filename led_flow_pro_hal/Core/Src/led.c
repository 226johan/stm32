#include "led.h"

void LED_On(GPIO_TypeDef * led_gpio,uint16_t led)
{
    HAL_GPIO_WritePin(led_gpio,led,GPIO_PIN_RESET);
}

void LED_Off(GPIO_TypeDef * led_gpio,uint16_t led)
{
    HAL_GPIO_WritePin(led_gpio,led,GPIO_PIN_SET);
}

void LED_Toggle(GPIO_TypeDef * led_gpio,uint16_t led)
{
    HAL_GPIO_TogglePin(led_gpio,led);
}

void LED_OnAll(GPIO_TypeDef * led_gpios[],uint16_t leds[],uint16_t size)
{
    for(uint16_t i=0;i<size;i++)
    {
        LED_On(led_gpios[i],leds[i]);
    }
}

void LED_OffAll(GPIO_TypeDef * led_gpios[],uint16_t leds[],uint16_t size)
{
    for(uint16_t i=0;i<size;i++)
    {
        LED_Off(led_gpios[i],leds[i]);
    }
}

