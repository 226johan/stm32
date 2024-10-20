#include<stdint.h>
#include"stm32f10x.h"

// ????led0

int main(void)
{
	// 1.???????
//	*(uint32_t *)(0x40021000 + 0x18) = 1<<3;
//	*(uint32_t *)(0x40021000 + 0x18) = 1<<5;
//	*(uint32_t *)(0x40021000 + 0x18) = 0x0048;
//	RCC->APB2ENR |= 0x0048;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPEEN;
	
	// 2.GPIO?????????? 0011 ????????????
	// LED0
//	*(uint32_t *)(0x40010C00 + 0x00) = 3<<20;
//	GPIOB->CRL |= 3<<20;
	GPIOB->CRL &= ~GPIO_CRL_CNF5;
	GPIOB->CRL |= GPIO_CRL_MODE5;
	// LED1
//	*(uint32_t *)(0x40011800 + 0x00) = 3<<20;
//	GPIOE->CRL |= 3<<20;
	GPIOE->CRL &= ~GPIO_CRL_CNF5;
	GPIOE->CRL |= GPIO_CRL_MODE5;
	
	// 3.PB5 PE5???????
	// LED0
//	*(uint32_t *)(0x40010C00 + 0x0C) = ~(1<<5);
//	GPIOB->ODR &= ~(1<<5);
	GPIOB->ODR &= ~GPIO_ODR_ODR5;
	// LED1
//	*(uint32_t *)(0x40011800 + 0x0C) = ~(1<<5);
//	GPIOE->ODR &= ~(1<<5);
	GPIOE->ODR &= ~GPIO_ODR_ODR5;
	// 4.????????????????
	while(1)
	{
		
	}
}
