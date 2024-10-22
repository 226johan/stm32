#include"delay.h"

// 延时函数 微秒为单位，利用系统滴答定时器 72MHZ 一次嘀嗒1/72us
void Dealy_us(uint16_t us)
{
	// 装载计数值
	SysTick->LOAD = 72*us;

	// 配置 使用系统时钟（1） 计数不产生中断（0） 使能定时器（1）
	SysTick->CTRL |= 0x05;

	// 等待计数值变成0，判断CTRL标志位COUNTFLAG是否为1
	while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG)==0 && (SysTick->CTRL &SysTick_CTRL_ENABLE))
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
