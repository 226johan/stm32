#include<stdint.h>
#include"stm32f10x.h"

void Dealy_us(uint16_t us);
void Dealy_ms(uint16_t ms);
void Dealy_s(uint16_t s);

int main(void)
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
	// LED0
	GPIOB->ODR |= GPIO_ODR_ODR5;
	// LED1
	GPIOE->ODR |= GPIO_ODR_ODR5;

	// 4.��ѭ����ִ����ˮ��
	while(1)
	{
		// LED0
		GPIOB->ODR &= ~GPIO_ODR_ODR5;
		Dealy_ms(500);
		GPIOB->ODR |= GPIO_ODR_ODR5;
		// LED1
		GPIOE->ODR &= ~GPIO_ODR_ODR5;
		Dealy_ms(500);
		GPIOE->ODR |= GPIO_ODR_ODR5;
	}
}

// ��ʱ���� ΢��Ϊ��λ������ϵͳ�δ�ʱ�� 72MHZ һ�����1/72us
void Dealy_us(uint16_t us)
{
	// װ�ؼ���ֵ
	SysTick->LOAD = 72*us;

	// ���� ʹ��ϵͳʱ�ӣ�1�� �����������жϣ�0�� ʹ�ܶ�ʱ����1��
	SysTick->CTRL |= 0x05;

	// �ȴ�����ֵ���0���ж�CTRL��־λCOUNTFLAG�Ƿ�Ϊ1
	while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG)==0)
	{}

	// �رռ�ʱ��
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE;
}

void Dealy_ms(uint16_t ms)
{
	while(ms--)
	{
		Dealy_us(1000);
	}
}

void Dealy_s(uint16_t s)
{
	while(s--)
	{
		Dealy_ms(1000);
	}
}