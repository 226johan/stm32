#include"delay.h"

// ��ʱ���� ΢��Ϊ��λ������ϵͳ�δ�ʱ�� 72MHZ һ�����1/72us
void Dealy_us(uint16_t us)
{
	// װ�ؼ���ֵ
	SysTick->LOAD = 72*us;

	// ���� ʹ��ϵͳʱ�ӣ�1�� �����������жϣ�0�� ʹ�ܶ�ʱ����1��
	SysTick->CTRL |= 0x05;

	// �ȴ�����ֵ���0���ж�CTRL��־λCOUNTFLAG�Ƿ�Ϊ1
	while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG)==0 && (SysTick->CTRL &SysTick_CTRL_ENABLE))
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
