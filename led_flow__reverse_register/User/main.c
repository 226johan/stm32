#include<stdint.h>
#include"led.h"
#include"delay.h"

void Dealy_us(uint16_t us);
void Dealy_ms(uint16_t ms);
void Dealy_s(uint16_t s);

int main(void)
{
	LED_Init();

	uint8_t n=2;
	uint16_t leds[2]={LED0,LED1};
	GPIO_TypeDef *led_GPIOs[2]={LED0_GPIO,LED1_GPIO};


	// 4.在循环中执行流水灯
	while(1)
	{
		for(uint8_t i=0;i<n;i++)
		{
			LED_On(led_GPIOs[i],leds[i]);
			Dealy_ms(50);
			LED_Off(led_GPIOs[i],leds[i]);
		}

		for(uint8_t i=n-1;i>=1;i--)
		{
			LED_On(led_GPIOs[i],leds[i]);
			Dealy_ms(150);
			LED_Off(led_GPIOs[i],leds[i]);
		}
	}
}

