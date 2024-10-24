#include "usart.h"

void USART_Init(void)
{
    // 配置时钟
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; //使能GPIOA时钟

    RCC->APB2ENR |=RCC_APB2ENR_USART1EN; //使能USART1时钟

    // 配置GPIO
    // PA9 : 复用推挽输出 CNF-10 MODE-11
    // PA10: 浮空输入 CNF-01 MODE-00
    GPIOA->CRH |= GPIO_CRH_MODE9;
    GPIOA->CRH |= GPIO_CRH_CNF9_1;
    GPIOA->CRH &= ~GPIO_CRH_CNF9_0;

    GPIOA->CRH &= ~GPIO_CRH_MODE10;
    GPIOA->CRH &= ~GPIO_CRH_CNF10_1;
    GPIOA->CRH |= GPIO_CRH_CNF10_0;

    // 配置USART
    USART1->BRR = 0x271; //波特率设置
    USART1->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE; //使能发送接收

    // 设置数据帧格式
    USART1->CR1 &= ~USART_CR1_M; //8位数据位
    USART1->CR1 &= ~USART_CR1_PCE; //无校验位
    USART1->CR2 &= ~USART_CR2_STOP; //1位停止位
    

}

void USART_SendChar(uint8_t ch)
{
    // 判断SR里TXE是否为1
    while((USART1->SR&USART_SR_TXE)==0)
    {
    }
    USART1->DR = ch; //向DR写入要发送的数据
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
    // 读取接收到的数据,等待接收下一个数据
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
        USART1->DR; //清空接收缓存
        *size = --i;
    }
}

