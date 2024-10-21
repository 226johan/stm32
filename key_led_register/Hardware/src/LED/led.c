#include"led.h"

// ��ʼ��
void LED_Init(void)
{
    // 1.ʱ������
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPEEN;
	
	// 2.GPIO����ģʽ����
	// LED0

	GPIOB->CRL &= ~GPIO_CRL_CNF5;
	GPIOB->CRL |= GPIO_CRL_MODE5;
	// LED1

	GPIOE->CRL &= ~GPIO_CRL_CNF5;
	GPIOE->CRL |= GPIO_CRL_MODE5;
	
	// 3.PB5 PE5 ����ߵ�ƽ��Ĭ�Ϲص�
    LED_Off(LED0_GPIO, LED0);
    LED_Off(LED1_GPIO, LED1);
}

// ����ĳ��LED�Ŀ���
void LED_On(GPIO_TypeDef * led_GPIO,uint16_t led)
{
    led_GPIO->ODR &= ~led;
}
void LED_Off(GPIO_TypeDef * led_GPIO,uint16_t led)
{
    led_GPIO->ODR |= led;
}


// ��תled��״̬
void LED_Toggle(GPIO_TypeDef *led_GPIO,uint16_t led)
{
    // ���жϵ�ǰLED״̬����ȡIDR��Ӧλ
    if((led_GPIO->ODR & led)==0)
    {
        LED_Off(led_GPIO,led);
    }
    else
    {
        LED_On(led_GPIO,led);
    }
}

// ��һ��LED��ȫ��ȫ��
void LED_OnAll(GPIO_TypeDef * led_GPIO[],uint16_t leds[],uint8_t size)
{
    for(uint8_t i =0;i<size;i++)
    {
        LED_On(led_GPIO[i]->ODR,leds[i]);
    }
}
void LED_OnOff(GPIO_TypeDef * led_GPIO[],uint16_t leds[],uint8_t size)
{
        for(uint8_t i =0;i<size;i++)
    {
        LED_Off(led_GPIO[i]->ODR,leds[i]);
    }
}
