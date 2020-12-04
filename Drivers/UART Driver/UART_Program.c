#include "avr/io.h"
//#include "UART_config.h"
//#include "UART_interface.h"
#include "UART_private.h"


void UART_voidInit(){
	int UBRR_Value = 25;
	UBRR0H = (unsigned char) (UBRR_Value >> 8);
	UBRR0L = (unsigned char) UBRR_Value;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << USBS0) | (3<< UCSZ00);
}
void UART_voidSendChar(char Copy_u8char){
	while(! (UCSR0A & ( 1 << UDRE0)) );
	UDR0 = Copy_u8char;
}
void UART_voidSendStr(char *Copy_u8Str){
	while (*Copy_u8Str != 0){
		UART_voidSendChar(*Copy_u8Str);
		Copy_u8Str++;
	}
}
char UART_u8ReadChar(){
	while (! (UCSR0A &(1 << RXC0)) );
	return UDR0;
}
void UART_voidEnableRxInterrupt(){
	UCSR0B = 1 << RXCIE0;
}
void UART_voidDisableRxIntrrupt(){
	UCSR0B &=~ (1<<RXCIE0);
	
}
void UART_voidOnReceive(void (*Copy_PvoidOnReceiveFunction) (void)){
	
}