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

    // AFIO�������Ÿ���ѡ��
    // PE4->EXTI4->EXTICR2  0100 PE[4]���� 
    AFIO->EXTICR[1] |= AFIO_EXTICR2_EXTI4_PE;

    // ����EXTI
    EXTI->RTSR |= EXTI_RTSR_TR4; // �����¼�ʹ��
    EXTI->IMR |= EXTI_IMR_MR4; // ʹ���ж�

    // ����NVIC
    NVIC_SetPriorityGrouping(3); //��ռ���ȼ�
    NVIC_SetPriority(EXTI4_IRQn, 3); // ���ȼ�3
    NVIC_EnableIRQ(EXTI4_IRQn); // ʹ���ж�

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
