#include "usart.h"

void USART_Init(void)
{
    // ����ʱ��
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; //ʹ��GPIOAʱ��

    RCC->APB2ENR |=RCC_APB2ENR_USART1EN; //ʹ��USART1ʱ��

    // ����GPIO
    // PA9 : ����������� CNF-10 MODE-11
    // PA10: �������� CNF-01 MODE-00
    GPIOA->CRH |= GPIO_CRH_MODE9;
    GPIOA->CRH |= GPIO_CRH_CNF9_1;
    GPIOA->CRH &= ~GPIO_CRH_CNF9_0;

    GPIOA->CRH &= ~GPIO_CRH_MODE10;
    GPIOA->CRH &= ~GPIO_CRH_CNF10_1;
    GPIOA->CRH |= GPIO_CRH_CNF10_0;

    // ����USART
    USART1->BRR = 0x271; //����������
    USART1->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE; //ʹ�ܷ��ͽ���

    // ��������֡��ʽ
    USART1->CR1 &= ~USART_CR1_M; //8λ����λ
    USART1->CR1 &= ~USART_CR1_PCE; //��У��λ
    USART1->CR2 &= ~USART_CR2_STOP; //1λֹͣλ
    

}

void USART_SendChar(uint8_t ch)
{
    // �ж�SR��TXE�Ƿ�Ϊ1
    while((USART1->SR&USART_SR_TXE)==0)
    {
    }
    USART1->DR = ch; //��DRд��Ҫ���͵�����
}

uint8_t USART_ReceiverChar(void)
{
    while((USART1->SR & USART_SR_RXNE)==0)
    {
        if(USART1->SR & USART_SR_IDLE)
        {
            return 0;
        }

    }
    // ��ȡ���յ�������,�ȴ�������һ������
    return USART1->DR;

}

void USART_SendString(uint8_t *str,uint8_t size)
{
    for(uint8_t i=0;i<size;i++)
    {
        USART_SendChar(str[i]);
    }
}

void USART_ReceiveString(uint8_t buffer[],uint8_t *size)
{
    uint8_t i=0;
    while (1)
    {
        while((USART1->SR & USART_SR_IDLE)==0)
        {
            buffer[i] = USART_ReceiverChar();
            i++;
        }
        USART1->DR; //��ս��ջ���
        *size = --i;
    }
}

