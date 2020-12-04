#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


void UART_voidInit();
void UART_voidSendChar(char Copy_u8char);
void UART_voidSendStr(char *Copy_u8Str);
char UART_u8ReadChar(void);
void UART_voidEnableRxInterrupt(void);
void UART_voidDisableRxIntrrupt(void);
void UART_voidOnReceive(void (*Copy_PvoidOnReceiveFunction) (void));















#endif