#include "key.h"

void Key_Init()
{
    // ����ʱ��
    RCC->APB1ENR |= RCC_APB2ENR_IOPEEN;
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

    // ����GPIO����ģʽ PE4: CNF-10 MODE-00
    GPIOE->CRL &= ~GPIO_CRL_MODE4;
    GPIOE->CRL |= GPIO_CRL_CNF4_1;
    GPIOE->CRL &= ~GPIO_CRL_CNF4_0;

    GPIOE->ODR |= GPIO_ODR_ODR4;  // ����ߵ�ƽ ����

    GPIOE->CRL &= ~GPIO_CRL_MODE3;
    GPIOE->CRL |= GPIO_CRL_CNF3_1;
    GPIOE->CRL &= ~GPIO_CRL_CNF3_0;

    GPIOE->ODR |= GPIO_ODR_ODR3;

    // AFIO�������Ÿ���ѡ��
    // PE4->EXTI4->EXTICR2  0100 PE[4]���� 
    AFIO->EXTICR[1] |= AFIO_EXTICR2_EXTI4_PE;
    AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI3_PE;

    // ����EXTI
    EXTI->RTSR |= EXTI_RTSR_TR4; // �����¼�ʹ��
    EXTI->IMR |= EXTI_IMR_MR4; // ʹ���ж�

    EXTI->RTSR |=EXTI_RTSR_TR3;
    EXTI->IMR |= EXTI_IMR_MR3;

    // ����NVIC
    NVIC_SetPriorityGrouping(3); //��ռ���ȼ�
    NVIC_SetPriority(EXTI4_IRQn, 3); // ���ȼ�3
    NVIC_EnableIRQ(EXTI4_IRQn); // ʹ���ж�
    NVIC_SetPriority(EXTI3_IRQn, 3); // ���ȼ�3
    NVIC_EnableIRQ(EXTI3_IRQn); // ʹ���ж�

}

// �����жϷ�����
void EXTI4_IRQHandler(void)
{
    // ������жϹ����־λ
    EXTI->PR |= EXTI_PR_PR4;

    // ������
    Dealy_ms(1);

    // �ж������Ȼ���ָߵ�ƽ����ת
    if((GPIOE->IDR & GPIO_IDR_IDR4) != 0)
    {
        LED_Toggle(LED0_GPIO,LED0);
    }

}

void EXTI3_IRQHandler(void)
{
    // ������жϹ����־λ
    EXTI->PR |= EXTI_PR_PR3;

    // ������
    Dealy_ms(1);

    // �ж������Ȼ���ָߵ�ƽ����ת
    if((GPIOE->IDR & GPIO_IDR_IDR3) != 0)
    {
        LED_Toggle(LED1_GPIO,LED1);
    }
}
