#include<stdint.h>
#include"stm32f10x.h"

void Dealy_us(uint16_t us);
void Dealy_ms(uint16_t ms);
void Dealy_s(uint16_t s);

int main(void)
{
	// 1.时钟配置
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPEEN;
	
	// 2.GPIO工作模式配置
	// LED0

	GPIOB->CRL &= ~GPIO_CRL_CNF5;
	GPIOB->CRL |= GPIO_CRL_MODE5;
	// LED1

	GPIOE->CRL &= ~GPIO_CRL_CNF5;
	GPIOE->CRL |= GPIO_CRL_MODE5;
	
	// 3.PB5 PE5 输出高电平，默认关灯
	// LED0
	GPIOB->ODR |= GPIO_ODR_ODR5;
	// LED1
	GPIOE->ODR |= GPIO_ODR_ODR5;

	// 4.在循环中执行流水灯
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

// 延时函数 微秒为单位，利用系统滴答定时器 72MHZ 一次嘀嗒1/72us
void Dealy_us(uint16_t us)
{
	// 装载计数值
	SysTick->LOAD = 72*us;

	// 配置 使用系统时钟（1） 计数不产生中断（0） 使能定时器（1）
	SysTick->CTRL |= 0x05;

	// 等待计数值变成0，判断CTRL标志位COUNTFLAG是否为1
	while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG)==0)
	{}

	// 关闭计时器
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