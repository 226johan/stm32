#include"usart.h"
#include"delay.h"

int main(void)
{
	USART_Init();

	USART_SendChar('a');
	USART_SendChar('t');
	USART_SendChar('\n');

	uint8_t * str = "Hello World!\n";
	USART_SendString(str, strlen((char*)str));


	while(1)
	{
		// USART_SendChar('x');
		// USART_SendChar('\n');
		// Dealy_ms(500);
		uint8_t ch = USART_ReceiverChar();
		USART_SendChar(ch);

	}
}

