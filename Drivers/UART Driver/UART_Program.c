#include "avr/io.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "avr/interrupt.h"
#include "STD_TYPES.h"

void UART_voidInit(){
	int32_t UBRR_Value = UART_F_CPU/16*(int16_t)UART_BaudRate;
	UBRR0H = (unsigned char) (UBRR_Value >> 8);
	UBRR0L = (unsigned char) UBRR_Value;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (UART_BitSize1 << UCSZ02);
	UCSR0C = (UART_Parity_1 << UPM01) | (UART_Parity_2 << UPM00) | (UART_StopBits << USBS0) | (UART_BitSize2 << UCSZ01) | (UART_BitSize3 << UCSZ02);
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
	sei();
	UCSR0B = 1 << RXCIE0;
}
void UART_voidDisableRxIntrrupt(){
	UCSR0B &=~ (1<<RXCIE0);
	
}
void UART_voidOnReceive( void (*Copy_PvoidOnReceiveFunction) (void)){
	RX_Interrupt = Copy_PvoidOnReceiveFunction;
	
}
ISR(USART0_RX_vect){
	if(RX_Interrupt != 0){
		RX_Interrupt();
	}
}