#include "key.h"

void Key_Init()
{
    // 配置时钟
    RCC->APB1ENR |= RCC_APB2ENR_IOPEEN;
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

    // 配置GPIO工作模式 PE4: CNF-10 MODE-00
    GPIOE->CRL &= ~GPIO_CRL_MODE4;
    GPIOE->CRL |= GPIO_CRL_CNF4_1;
    GPIOE->CRL &= ~GPIO_CRL_CNF4_0;

    GPIOE->ODR |= GPIO_ODR_ODR4;  // 输出高电平 上拉

    // AFIO配置引脚复用选择
    // PE4->EXTI4->EXTICR2  0100 PE[4]引脚 
    AFIO->EXTICR[1] |= AFIO_EXTICR2_EXTI4_PE;

    // 配置EXTI
    EXTI->RTSR |= EXTI_RTSR_TR4; // 触发事件使能
    EXTI->IMR |= EXTI_IMR_MR4; // 使能中断

    // 配置NVIC
    NVIC_SetPriorityGrouping(3); //抢占优先级
    NVIC_SetPriority(EXTI4_IRQn, 3); // 优先级3
    NVIC_EnableIRQ(EXTI4_IRQn); // 使能中断

}

// 按键中断服务函数
void EXTI4_IRQHandler(void)
{
    // 先清楚中断挂起标志位
    EXTI->PR |= EXTI_PR_PR4;

    // 防抖动
    Dealy_ms(1);

    // 判断如果依然保持高电平，则翻转
    if((GPIOE->IDR & GPIO_IDR_IDR4) != 0)
    {
        LED_Toggle(LED0_GPIO,LED0);
    }

}
