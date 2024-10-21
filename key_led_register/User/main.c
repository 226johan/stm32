#include<stdint.h>
#include"led.h"
#include"key.h"

void Dealy_us(uint16_t us);
void Dealy_ms(uint16_t ms);
void Dealy_s(uint16_t s);

int main(void)
{
	LED_Init();
	Key_Init();

	// 4.在循环中执行流水灯
	while(1)
	{
		// LED_Toggle(LED0_GPIO,LED0);
		// Dealy_ms(500);

	}
}

