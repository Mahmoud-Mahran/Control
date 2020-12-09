#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define  UART_F_CPU			1000000UL		//CPU frequency
#define	 UART_BaudRate		9600		
#define	 UART_Parity_1		0				//[0,0,1] >> [disabled, enabled even, enabled odd]
#define	 UART_Parity_2		0				//[0,1,1] >> [disabled, enabled even, enabled odd]
#define	 UART_BitSize1		0				//[0,0,0,0,1] >> [5, 6, 7, 8, 9]bits
#define	 UART_BitSize2		1				//[0,0,1,1,1] >> [5, 6, 7, 8, 9]bits
#define	 UART_BitSize3		1				//[0,1,0,1,1] >> [5, 6, 7, 8, 9]bits
#define  UART_StopBits		0				//[0,1] >> [1, 2]bits
#endif