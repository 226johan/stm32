#include<stdint.h>
#include"led.h"
#include"key.h"
#include"delay.h"

void Dealy_us(uint16_t us);
void Dealy_ms(uint16_t ms);
void Dealy_s(uint16_t s);

// 流水灯是否开启标志位
uint8_t isOn=0;

int main(void)
{
	LED_Init();
	Key_Init();
	uint8_t size=2;
	
	GPIO_TypeDef *led_gpios[]={LED0_GPIO,LED1_GPIO};
	uint16_t leds[]={LED0,LED1};

	// 4.在循环中执行流水灯
	while(1)
	{
		if(isOn)
		{
			for(uint8_t i = 0;i<size;i++)
			{
				LED_On(led_gpios[i],leds[i]);
				Dealy_ms(10);
				LED_Off(led_gpios[i],leds[i]);
				if(isOn==0)
				{
					break;
				}
			}
		}
		else
		{
			LED_OffAll(led_gpios,leds,size);
		}

	}
}

